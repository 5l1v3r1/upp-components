#include <Core/SSH/SSH.h>
#include <Terminal/Terminal.h>

// This example demonstrates a multithreaded ssh terminal splitter
// It is using the  Core/SSH package, therefore it can be compiled
// for, and run on, Windows and  POSIX-compliant operating systems.

using namespace Upp;

String url = "demo:password@test.rebex.net:22";	// A well-known public SSH test server.

const int MAXPANECOUNT = 4; // You can increase the number of panes if you like.

struct SshTerminalPane : Terminal, SshShell {
	Splitter& parent;
	SshTerminalPane(SshSession& session, Splitter& ctrl) : SshShell(session), parent(ctrl)
	{
		SshShell::Timeout(Null);
		SshShell::ChunkSize(65536);
		SshShell::WhenOutput = [=](const void *data, int size) { GuiLock __; Terminal::Write(data, size);     };
		SshShell::WhenWait   = [=]()                           { if(CoWork::IsCanceled()) SshShell::Abort();  };
		Terminal::WhenOutput = [=](String data)                { SshShell::Send(data);                        };
		Terminal::WhenResize = [=]()                           { SshShell::PageSize(Terminal::GetPageSize()); };
		Terminal::InlineImages();
		parent.Add(Terminal::SizePos());
	}
	
	void Run(const String& termtype)
	{
		SshShell::Run(termtype, Terminal::GetPageSize());
		GuiLock __;
		parent.Remove(*this);
		parent.Layout();
	}

	bool Key(dword key, int count) override
	{
		// Let the parent handle the SHIFT + CTRL + T key.
		return key != K_SHIFT_CTRL_T ? Terminal::Key(key, count) : false;
	}
};

struct SshTerminalSplitterExample : TopWindow {
	Splitter   splitter;
	SshSession session;
	CoWorkNX   workers; // Same as CoWork, but can be used as a member.

	bool Key(dword key, int count) override
	{
		if(key == K_SHIFT_CTRL_T) AddPane();
		return false;
	}

	void AddPane()
	{
		if(splitter.GetCount() < MAXPANECOUNT) {
			workers & [=] {
				EnterGuiMutex();                            // Note: Ctrl derived classes can only be
				SshTerminalPane shell(session, splitter);   // initialized in main thread OR vith gui
				LeaveGuiMutex();                            // mutex. (GuiLock)
				shell.Run("xterm");
			};
		}
	}

	void Run()
	{
		if(!EditTextNotNull(url, "SSH server", "Url"))
			Exit(1);

		session.WhenWait = [=] { if(IsMainThread()) ProcessEvents(); };

		if(!session.Timeout(10000).Connect(url)) {
			ErrorOK(DeQtf(session.GetErrorDesc()));
			Exit(1);
		}

		Title(t_("Ssh terminal splitter (Press CTRL + SHIFT + T to split the view)"));
		Sizeable().Zoomable().CenterScreen().SetRect(0, 0,  1024, 600);
		Add(splitter.Horz());
		AddPane();
		OpenMain();
		while(IsOpen() && !workers.IsFinished()) {
			ProcessEvents();
			Sleep(10);
		}
		GuiUnlock __;
		workers.Cancel();
	}
};

GUI_APP_MAIN
{
	SshTerminalSplitterExample().Run();
}