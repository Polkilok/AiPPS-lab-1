#pragma once

#include "IContainer.h"
#include "IIterator.h"

template<typename _ElemType> struct Cell
{
	_ElemType _value;
	Cell *_next;
	Cell *_prew;
	Cell()
		:_value(), _next(nullptr), _prew(nullptr)
	{};
	Cell(const _ElemType& value)
		:_value(value), _next(nullptr), _prew(nullptr)
	{};
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
	CycleListIterator()
		:_it(nullptr), _head(nullptr), _MoveFlag(false)
	{}
	CycleListIterator(Cell<_ElemType> *Head)
		:_it(Head), _head(Head), _MoveFlag(false)
	{}
	void Next()
	{
		if (_it != nullptr)
		{
			_it = _it->_next;
			_MoveFlag = true;
		}
	}
	_ElemType& GetItem() {
		if (_it != nullptr)
			return _it->_value;
	}
	bool IsEnd()
	{
		return _it == _head && _MoveFlag;
	}
};

template<typename _ElemType>
class CycleList : public IContainer<_ElemType>
{
public:

	CycleList()
		:_head(nullptr)
	{
	}

	~CycleList()
	{
	}

private:
	Cell<_ElemType> *_head;
public:
	void PushBack(const _ElemType &Value) {
		if (_head == nullptr)
		{
			_head = new Cell<_ElemType>(Value);
			_head->_next = _head;
			_head->_prew = _head;
		}
		else
		{
			Cell<_ElemType> *new_item = new Cell<_ElemType>(Value);
			new_item->_prew = _head->_prew;
			new_item->_next = _head;
			_head->_prew->_next = new_item;
			
			_head->_prew = new_item;
			
		}
	};
	void PopBack() {
		if (_head->_prew == _head)
		{
			delete _head;//удаляем последний элемент
			_head = nullptr;
		}
		else
		{
			Cell<_ElemType>* buf = _head->_prew;
			buf->_prew->_next = _head;
			_head->_prew = buf->_prew;
			delete buf;
		}
	};

	IIterator<_ElemType>* GetIterator() {
		return (IIterator<_ElemType>*)(new CycleListIterator<_ElemType>(_head));
	};
	void FreeIterator(IIterator<_ElemType>* iterator) {
		delete iterator;
	}
};
