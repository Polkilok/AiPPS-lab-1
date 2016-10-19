#pragma once
template<typename _ItemType> class IIterator
{
public:

	IIterator() {}

	virtual ~IIterator() {}

	virtual void Next() = 0;

	virtual _ItemType& GetItem() = 0;
	virtual bool IsEnd() = 0;
};