#include <CtrlLib/CtrlLib.h>
#include <Message/Message.h>

using namespace Upp;

class Messages : public TopWindow {
	Message msg;
	DocEdit editor;
	Button  button;
	
public:
	Messages()
	{
		Title("U++ Message Boxes (Passive Notifications)");
		SetRect(0,0, 640, 480);
		Sizeable().Zoomable().CenterScreen();
		SetMinSize({100, 100});
		
		Add(editor.HSizePosZ().VSizePos(0, 24));
		Add(button.RightPos(4).BottomPos(4));
		button.SetLabel("Test");
		button <<  [=] {
			msg.Animation()
			  .Top()
			  .Information(*this, "This is an information message.")
			  .Success(*this, "This is a success message.")
			  .Warning(*this, "This is a warning message.")
			 .Bottom().Error(editor, "This is an error message.");
			
			auto action = [=](int id) {
				switch(id) {
				case IDYES: PromptOK("You've chosen 'yes'"); break;
				case IDNO:  PromptOK("You've chosen 'no'"); break;
				}
			};
			msg //Bottom()
			   .AskYesNo(editor, "This is a question message 'in' the text editor with "
			                   "[^https:www`.ultimatepp`.org^ l`i`n`k]"
			                   " support. Would you like to continue?",
			                   action,
			                   callback(LaunchWebBrowser)
			);
			
		};
	}
};

GUI_APP_MAIN
{
	Messages().Run();
}