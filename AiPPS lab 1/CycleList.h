#pragma once

#include "IContainer.h"

template<typename _ElemType>
class CycleList : IContainer<_ElemType>
{
public:

	CycleList()
	{
	}

	~CycleList()
	{
	}

private:
	class Cell
	{
	private:
		_ElemType _value;
		Cell *_next;
		Cell *_prew;
		friend List;
	public:
		Cell()
			:_value(), _next(nullptr), _prew(nullptr)
		{};
		Cell(const _ElemType& value)
			:_value(value), _next(nullptr), _prew(nullptr)
		{};
		//на всякий случай выкинем копирование
		Cell(const item& another) = delete;
		_ElemType& get_value()
		{
			return _value;
		}
		void set_value(const _ElemType &value)
		{
			_value = value;
		}
	};

private:
	Cell *_head;
public:
	void PushBack(const _ItemType &Item) {
		if (_head == nullptr)
		{
			_head = new Cell(value);
			_head->_next = _head;
			_head->_prew = _head;
		}
		else
		{
			Cell *new_item = new Cell(value);
			_head->_prew->_next = new_item;
			new_item->_prew = _head->_prew;
			_head->_prew = new_item;
			new_item->_next = _head;
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
			Cell* buf = _head->_prew;
			buf->_prew->_next = _head;
			_head->_prew = buf->_prew;
			delete buf;
		}
	};

	IIterator<_ItemType> Begin() {
	};
	IIterator<_ItemType> End() {};
};

