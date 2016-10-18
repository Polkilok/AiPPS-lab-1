#pragma once

#include "IIterator.h"

template<typename _ItemType> class IContainer
{
public:

	Container()
	{
	}

	~Container()
	{
	}

	void PushBack(const _ItemType &Item) {};
	void PopBack(const _ItemType &Item) {};

	IIterator<_ItemType> Begin();
	IIterator<_ItemType> End();
};

