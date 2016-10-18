#pragma once
template<typename _ItemType> class IIterator
{
public:

	IIterator(){}

	~IIterator(){}

	public virtual void Next() {};

	public virtual _ItemType& GetItem() {};
};

