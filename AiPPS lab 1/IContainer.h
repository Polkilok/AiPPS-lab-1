#pragma once
#include "IIterator.h"
template<typename _ItemType> class IContainer
{
public:
	IContainer()
	{
	}

	virtual ~IContainer()
	{
	}

	virtual void PushBack(const _ItemType &Item) = 0;
	virtual void PopBack() = 0;

	virtual IIterator<_ItemType>* GetIterator() = 0;
	virtual void FreeIterator(IIterator<_ItemType>*) = 0;
};
