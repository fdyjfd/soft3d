#pragma once

#include "Utility.h"

namespace soft3d
{
	class RefCount
	{
		friend class Device;
		friend class DeviceContext;
	protected:
		RefCount();
		virtual ~RefCount();
	public:
		long addRef();
		long release();
	protected:
		long internalAddRef();
		long internalRelease();
		void safeInternalAddRef();
		void safeInternalRelease();
	protected:
		long m_refCount;
		long m_internalRefCount;
	};

	//----------------------------------------------------
	inline RefCount::RefCount() :
		m_refCount(1),
		m_internalRefCount(0)
	{}
	
	inline RefCount::~RefCount()
	{}

	inline long RefCount::addRef()
	{
		return ++m_refCount;
	}

	inline long RefCount::release()
	{
		--m_refCount;
		if (0 == m_refCount && 0 == m_internalRefCount)
		{
			delete this;
		}
	}

	inline long RefCount::internalAddRef()
	{
		return ++m_internalRefCount;
	}

	inline long RefCount::internalRelease()
	{
		long res = --m_internalRefCount;
		if (0 == m_refCount && 0 == m_internalRefCount)
		{
			delete this;
		}
		return res;
	}

	inline void RefCount::safeInternalAddRef()
	{
		if (this)
		{
			internalAddRef();
		}
	}

	inline void RefCount::safeInternalRelease()
	{
		if (this)
		{
			internalRelease();
		}
	}

}
