#ifndef _Job_Job_h_
#define _Job_Job_h_

#include <Core/Core.h>

namespace Upp {

class JobWorker : NoCopy {
public:
    JobWorker();
    ~JobWorker();
    bool                Start(Event<>&& fn);
    void                Stop();
    void                Loop();
    void                Wait();
    void                Cancel()                    { cancel = true; Wait();  Rethrow(); }
    static bool         IsCanceled()                { return ptr && ptr->cancel; }
    void                Rethrow()                   { Mutex::Lock __(lock); if(exc) std::rethrow_exception(exc); }
    inline bool         Is(int stat) const          { return status == stat; }
    
    enum State : int { IDLE, WORKING, SHUTDOWN };
    
private:
    Thread              work;
    Event<>             cb;
    Mutex               lock;
    ConditionVariable   cv, wv;
    std::exception_ptr  exc;
    std::atomic<int>    status;
    std::atomic<bool>   cancel;
    static thread_local JobWorker *ptr;
};

template<class T>
class Job {
private:
    template<class R>
    struct Result {
        JobWorker v;
        R ret;
        template<class Function, class... Args>
        bool       Start(Function&& f, Args&&... args)  { return v.Start([=]{ ret = f(args...);}); }
        const R&   Get()                                { v.Wait(); v.Rethrow(); return ret; }
    };

    struct VoidResult {
        JobWorker v;
        template<class Function, class... Args>
        bool       Start(Function&& f, Args&&... args)  { return v.Start([=]{ f(args...); }); }
        void       Get()                                { v.Wait(); v.Rethrow(); }
    };

    using ResType = typename std::conditional<std::is_void<T>::value, VoidResult, Result<T>>::type;
    One<ResType> worker;
    
public:
    template<class Function, class... Args>
    bool    Do(Function&& f, Args&&... args)            { return worker && worker->Start(f, args...); }
    void    Finish()                                    { ASSERT(worker); worker->v.Wait(); }
    bool    IsFinished() const                          { return !worker || !worker->v.Is(JobWorker::WORKING);  }
    void    Cancel()                                    { ASSERT(worker); worker->v.Cancel(); }
    static bool IsCancelled()                           { return JobWorker::IsCanceled(); }
    T       Get()                                       { ASSERT(worker); return worker->Get(); }
    T       operator~()                                 { return Get(); }
    Job()                                               { worker.Create(); }
    ~Job()                                              { worker.Clear();  }
};
}
#endif
