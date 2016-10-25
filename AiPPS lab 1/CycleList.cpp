#include "CycleList.h"

template<typename _ElemType> Cell<_ElemType>::Cell()
		:_value(), _next(nullptr), _prew(nullptr)
	{};
template<typename _ElemType> Cell<_ElemType>::Cell(const _ElemType& value)
		:_value(value), _next(nullptr), _prew(nullptr)
	{};

template<typename _ElemType> CycleListIterator<_ElemType>::CycleListIterator()
		:_it(nullptr), _head(nullptr), _MoveFlag(false)
	{}
template<typename _ElemType> CycleListIterator<_ElemType>::CycleListIterator(Cell<_ElemType> *Head)
		:_it(Head), _head(Head), _MoveFlag(false)
	{}
template<typename _ElemType> void CycleListIterator<_ElemType>::Next()
	{
		if (_it != nullptr)
		{
			_it = _it->_next;
			_MoveFlag = true;
		}
	}
template<typename _ElemType> _ElemType& CycleListIterator<_ElemType>::GetItem() {
		if (_it != nullptr)
			return _it->_value;
	}
template<typename _ElemType> bool CycleListIterator<_ElemType>::IsEnd()
	{
		return _it == _head && _MoveFlag;
	}

template<typename _ElemType> CycleList<_ElemType>::CycleList()
		:_head(nullptr)
	{
	}

template<typename _ElemType> CycleList<_ElemType>::~CycleList()
	{
	}

template<typename _ElemType> void CycleList<_ElemType>::PushBack(const _ElemType &Value) {
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
template<typename _ElemType> void CycleList<_ElemType>::PopBack()
{
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

template<typename _ElemType> IIterator<_ElemType>* CycleList<_ElemType>::GetIterator() {
		return (IIterator<_ElemType>*)(new CycleListIterator<_ElemType>(_head));
	};
template<typename _ElemType> void CycleList<_ElemType>::FreeIterator(IIterator<_ElemType>* iterator) {
		delete iterator;
};