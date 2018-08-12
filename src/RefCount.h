#pragma once

#include "Utility.h"

namespace soft3d
{
	class RefCount
	{
	protected:
		RefCount();
		virtual ~RefCount();
	public:
		long addRef();
		long release();
	protected:
		long internalAddRef();
		long internalRelease();
	protected:
		long m_refCount;
		long m_internalRefCount;
	};

	//----------------------------------------------------
	RefCount::RefCount() :
		m_refCount(1),
		m_internalRefCount(0)
	{}

	long RefCount::addRef()
	{
		return ++m_refCount;
	}

	long RefCount::release()
	{
		--m_refCount;
		if (0 == m_refCount && 0 == m_internalRefCount)
		{
			delete this;
		}
	}

	long RefCount::internalAddRef()
	{
		return ++m_internalRefCount;
	}

	long RefCount::internalRelease()
	{
		--m_internalRefCount;
		if (0 == m_refCount && 0 == m_internalRefCount)
		{
			delete this;
		}
	}
}
