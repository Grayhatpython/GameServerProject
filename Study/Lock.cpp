//#include "pch.h"
//#include "Lock.h"
//
//Lock::Lock()
//{
//	::InitializeSRWLock(&_srwLock);
//}
//
//Lock::~Lock()
//{
//
//}
//
//void Lock::WriteLock()
//{
//	if (_lockFlag.load(std::memory_order_acquire) == LThreadId)
//	{
//		_recursive.store(true);
//		return;
//	}
//
//	::AcquireSRWLockExclusive(&_srwLock);
//	_lockFlag.store(LThreadId, std::memory_order_release);
//}
//
//void Lock::WriteUnlock()
//{
//	if (_recursive.load(std::memory_order_acquire) == true)
//	{
//		_recursive.store(false);
//		return;
//	}
//
//	_lockFlag.store(0);
//	::ReleaseSRWLockExclusive(&_srwLock);
//}

#include "pch.h"
#include "Lock.h"

Lock::Lock()
{
	static std::atomic<uint32> SGenerateLockId = 1;
	_lockId = SGenerateLockId.fetch_add(1);
}

Lock::~Lock()
{

}

void Lock::WriteLock()
{
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;

	if (LThreadId == lockThreadId)
	{
		_writeCount++;
		return;
	}

	const int64 raceConditionBeginTick = ::GetTickCount64();
	const uint32 desired = ((LThreadId << 16) & WRITE_THREAD_MASK);

	while (true)
	{
		uint32 expected = EMPTY_FLAG;

		if (_lockFlag.compare_exchange_weak(OUT expected, desired))
		{
			_writeCount++;
			return;
		}

		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
			::YieldProcessor();

		if (::GetTickCount64() - raceConditionBeginTick >= ACQUIRE_TIMEOUT_TICK)
			assert(1 == 2);	//	TEMP

		//this_thread::yield();
		/*::YieldProcessor();*/
	}
}

void Lock::WriteUnlock()
{
	if ((_lockFlag.load() & READ_COUNT_MASK) != 0)
		assert(1 == 2);	//	TEMP

	const uint16 lockCount = --_writeCount;
	if (lockCount == 0)
		_lockFlag.store(EMPTY_FLAG);
}

void Lock::ReadLock()
{
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;

	if (LThreadId == lockThreadId)
	{
		_writeCount++;
		return;
	}

	const int64 raceConditionBeginTick = ::GetTickCount64();

	while (true)
	{
		uint32 expected = (_lockFlag.load() & READ_COUNT_MASK);
		if (_lockFlag.compare_exchange_weak(OUT expected, expected + 1))
			return;

		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
			::YieldProcessor();

		if (::GetTickCount64() - raceConditionBeginTick >= ACQUIRE_TIMEOUT_TICK)
			assert(1 == 2);	//	TEMP

		//this_thread::yield();
		/*::YieldProcessor();*/
	}
}

void Lock::ReadUnlock()
{
	if ((_lockFlag.fetch_sub(1) & READ_COUNT_MASK) == 0)
		assert(1 == 2);	//	TEMP
}
