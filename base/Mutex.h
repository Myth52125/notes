
#ifndef _MUTEXLOCK_H_M_
#define _MUTEXLOCK_H_M_


#include <pthread.h>


#include <codebase/base/ToolFunc.h>
#include <codebase/base/ToolThread.h>

namespace myth52125
{


class MutexLock
{
private:
	pthread_mutex_t _mutex;
	pid_t 			_tid;

public:
	MutexLock()
		:_tid(ToolThread::tid())
	{
		int result = pthread_mutex_init(&_mutex,NULL);
	}
	~MutexLock()
	{
		int result = pthread_mutex_destroy(&_mutex);
	}

	void lock()
	{
		int result = pthread_mutex_lock(&_mutex);
	}

	void unlock()
	{
		int result = pthread_mutex_unlock(&_mutex);
	}
	
	pthread_mutex_t *mutex()
	{
		return &_mutex;
	}
};



class MutexGuard
{
private:
	MutexLock &_mutex;
public:
	MutexGuard(MutexLock &mutex)
		:_mutex(mutex)
	{
		_mutex.lock();
	}
			
	~MutexGuard()
	{
		_mutex.unlock();
	}
};






}

	
#endif
