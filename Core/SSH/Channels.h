class SshChannel : public Ssh {
public:
    SshChannel&         Timeout(int ms)                                             { ssh->timeout = ms; return *this; }
    SshChannel&         NonBlocking(bool b = true)                                  { ssh->async = b; return *this ;}
    SshChannel&         ChunkSize(int sz)                                           { if(sz >= 1024) ssh->chunk_size = sz; return *this; }

    LIBSSH2_CHANNEL*    GetHandle() const                                           { return chdata->channel; }
    String              GetResult()                                                 { return pick(chdata->data); }

    bool        Open();
    bool        Close();
    bool        CloseWait();
    bool        Request(const String& request, const String& params = Null);
    bool        Exec(const String& cmdline)                                         { return Request("exec", cmdline); }
    bool        Shell()                                                             { return Request("shell", Null); }
    bool        Subsystem(const String& subsystem)                                  { return Request("subsystem", subsystem); }
    bool        Terminal(const String& term, int width, int height);
    bool        SetEnv(const String& variable, const String& value);
    bool        Read(Stream& out, int64 size, Gate<int64, int64> progress = Null);
    bool        Write(Stream& in, int64 size = 0, Gate<int64, int64> progress = Null);
    bool        SendEof();
    bool        RecvEof();
    bool        SendRecvEof();
    bool        ReadStdErr(Stream& err);
    bool        WriteStdErr(Stream& err);
    bool        SetReadwindowSize(int64 size, bool force = false);
    int64       GetReadWindowSize();
    int64       GetWriteWindowSize();
    int         GetExitCode();
    String      GetExitSignal();


    SshChannel(SshSession& session);
    virtual ~SshChannel();

    SshChannel(SshChannel&&) = default;
    SshChannel& operator=(SshChannel&&) = default;

protected:
    virtual bool Init() override;
    virtual void Exit() override;
    virtual bool Cleanup(Error& e);

    bool _Read(int id, Stream& out, int64 size, Gate<int64, int64> progress = Null);
    bool _Write(int id, Stream& in, int64 size, Gate<int64, int64> progress = Null);
    bool _ReadChar(char& c);
    bool _WriteChar(const char& c);
    bool _IsEof();
    bool _SendEof();
    bool _RecvEof();
    bool _SetWndSz(int64 size, bool force = false);

    struct ChannelData {
        LIBSSH2_CHANNEL*    channel;
        libssh2_struct_stat fstat;
        int                 code;
        bool                open;
        String              signal;
        StringStream        data;
    };
    One<ChannelData> chdata;

    enum OpCodes {
        CHINIT,
        CHEXIT,
        CHOPEN,
        CHREQUEST,
        CHSETENV,
        CHREAD,
        CHWRITE,
        CHCLOSE,
        CHWAIT,
        CHEOF,
        CHSTDERR,
        CHRC,
        CHSIG,
        CHWNDSZ,
        CHEXEC,
        CHSHELL
    };
};

// Channels.
class Scp : public SshChannel {
public:
    bool    Get(Stream& out, const String& path, Gate<int64, int64> progress = Null);
    bool    operator()(Stream& out, const String& path, Gate<int64, int64> progress = Null)             { return Get(out, path, progress); }
    String  Get(const String& path, Gate<int64, int64> progress = Null);
    String  operator()(const String& path, Gate<int64, int64> progress = Null)                          { return Get(path, progress); }
    bool    Put(Stream& in, const String& path, long mode, Gate<int64, int64> progress = Null);
    bool    operator()(Stream& in, const String& path, long mode, Gate<int64, int64> progress = Null)   { return Put(in, path, mode, progress); }

    static  AsyncWork<String> AsyncGet(SshSession& session, const String& path, Gate<int64, int64> progress = Null);
    static  AsyncWork<void>   AsyncGet(SshSession& session, const char* source, const char* target, Gate<int64, int64> progress = Null);
    static  AsyncWork<void>   AsyncPut(SshSession& session, String&& data, const String& target, Gate<int64, int64> progress = Null);
    static  AsyncWork<void>   AsyncPut(SshSession& session, const char* source, const char* target, Gate<int64, int64> progress = Null);

    Scp(SshSession& session) : SshChannel(session)                                                      { ssh->otype = SCP; }

private:
    virtual bool            Init() override                                                             { return true; }
    enum OpCodes { FGET, FPUT };
};

class SshExec : public SshChannel {
public:
    int Execute(const String& cmd, Stream& out, Stream& err);
    int operator()(const String& cmd, Stream& out, Stream& err)                                         { return Execute(cmd, out, err); }

    static  AsyncWork<Tuple<int, String, String>> Async(SshSession& session, const String& cmd);

    SshExec(SshSession& session) : SshChannel(session)                                                  { ssh->otype = EXEC; };

private:
    bool Init() override { return true; }
};
