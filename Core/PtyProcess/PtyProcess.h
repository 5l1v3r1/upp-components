#ifndef _PtyProcess_PtyProcess_h
#define _PtyProcess_PtyProcess_h

#include <Core/Core.h>

#ifdef PLATFORM_POSIX
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <termios.h>
#endif

namespace Upp {

#ifdef PLATFORM_POSIX
class PtyProcess : public AProcess {
public:
	PtyProcess()																		{ Init(); }
	PtyProcess(const char *cmdline, const char *env = nullptr)							{ Init(); Start(cmdline, nullptr, env, nullptr); }
	PtyProcess(const char *cmd, const Vector<String> *args, const char *env = nullptr)	{ Init(); Start(cmd, args, env, nullptr); }
	virtual ~PtyProcess()																{ Kill(); }

	PtyProcess&	ConvertCharset(bool b = true)		{ convertcharset = b; return *this; }
	PtyProcess& NoConvertCharset()					{ return ConvertCharset(false); }

	bool		SetSize(Size sz);
	Size		GetSize();
	bool		SetAtrributes(const termios& t);
	bool		GetAttributes(termios& t);
	bool		Start(const char *cmdline, const char *env = nullptr, const char *cd = nullptr)							{ return DoStart(cmdline, nullptr, env, cd); }
	bool		Start(const char *cmd, const Vector<String> *args, const char *env = nullptr, const char *cd = nullptr)	{ return DoStart(cmd, args, env, cd); }
	void		Kill() override;

	bool		IsRunning() override;
			
	bool		Read(String& s) override;
	void		Write(String s) override;

	int			GetPid() const						{ return pid; }
	int			GetExitCode() override;
	
private:
	void		Init();
	void		Free();
	bool		Open();
	bool		ResetSignals();
	bool		DecodeExitCode(int status);
	bool		DoStart(const char *cmd, const Vector<String> *args, const char *env, const char *cd);
	
	int			master, slave;
	int			exit_code;
	bool		convertcharset;
	String		exit_string;
	String		sname;
	String		wread;
	Size		ptysize;

	pid_t		pid;
	One<termios> attrs;
};
#endif
}

#endif
