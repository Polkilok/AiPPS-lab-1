#pragma once

#include "IContainer.h"
#include "IIterator.h"

template<typename _ElemType> struct Cell
{
	_ElemType _value;
	Cell *_next;
	Cell *_prew;
	Cell();
	Cell(const _ElemType& value);
	//на всякий случай выкинем копирование
	Cell(const Cell& another) = delete;
};

template<typename _ElemType>
class CycleListIterator : public IIterator<_ElemType>
{
private:
	Cell<_ElemType> *_it;
	Cell<_ElemType> *_head;
	bool _MoveFlag;
public:
	CycleListIterator();
	CycleListIterator(Cell<_ElemType> *Head);
	void Next();
	_ElemType& GetItem();
	bool IsEnd();
};

template<typename _ElemType>
class CycleList : public IContainer<_ElemType>
{
public:

	CycleList();
	~CycleList();

private:
	Cell<_ElemType> *_head;
public:
	void PushBack(const _ElemType &Value);
	void PopBack();

	IIterator<_ElemType>* GetIterator();
	void FreeIterator(IIterator<_ElemType>* iterator);
};
