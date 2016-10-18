#include <iostream>
#include <list>
//#include <algorithm>
#include <random>
template <typename _elem_type>

class List
{
public:
	class Exception
	{
	public:
		class All {};
		class EmptyIterator :All {};
		class CopyNull :All {};
	};
private:
	class item
	{
	private:
		_elem_type _value;
		item *_next;
		item *_prew;
		friend List;
	public:
		item()
			:_value(), _next(nullptr), _prew(nullptr)
		{};
		item(const _elem_type& value)
			:_value(value), _next(nullptr), _prew(nullptr)
		{};
		//на всякий случай выкинем копирование
		item(const item& another) = delete;
		_elem_type& get_value()
		{
			return _value;
		}
		void set_value(const _elem_type &value)
		{
			_value = value;
		}
	};
public:
	class iterator
	{
	private:
		item *ptr;
	public:
		friend List;
		iterator(item* it)
			:ptr(it)
		{
		}
		iterator& operator++()
		{
			if (ptr != nullptr)
			{
				ptr = ptr->_next;
			}
			else
				throw Exception::EmptyIterator();
			return *this;
		};
		iterator& operator--()
		{
			if (ptr != nullptr)
			{
				ptr = ptr->_prew;
			}
			else
				throw Exception::EmptyIterator();
			return *this;
		};
		bool operator!=(const iterator& another) {
			return this->ptr != another.ptr;
		}
		_elem_type& operator*()
		{
			return ptr->get_value();
		}
	};
private:
	item *_head;
	void insert_first(const _elem_type &value)
	{
		_head = new item(value);
		_head->_next = _head;
		_head->_prew = _head;
	}
public:
	List()
		:_head(nullptr)
	{

	}
	~List()
	{
		clear();
	}
	inline iterator begin() const
	{
		return iterator(_head);
	}
	//эм, тут будет отличие от стандартных контейнеров...
	inline iterator end() const
	{
		return iterator(_head->_prew);
	}
	void erase(iterator& it) {
		if (it.ptr->_next == it.ptr->_prew)
		{
			delete it.ptr;//удаляем последний элемент
			it.ptr = nullptr;
			_head = nullptr;
		}
		else
		{
			if (_head == it.ptr)
				_head = it.ptr->_next;
			item* buf = it.ptr;
			buf->_prew->_next = it.ptr->_next;
			buf->_next->_prew = it.ptr->_prew;
			it.ptr = it.ptr->_next;
			delete buf;
		}

	}
	void insert_prew(iterator& it, const _elem_type &value) {
		item *new_item = new item(value);
		new_item->_prew = it.ptr->_prew;
		new_item->_next = it.ptr;
		it.ptr->_prew->_next = new_item;
		it.ptr->_prew = new_item;
	}
	void add(const List& another_list) {
		auto i = another_list.begin();
		auto beg = begin();
		do
		{
			insert_prew(beg, *i);
			++i;
		} while (i != another_list.begin());
	}
	void push_back(const _elem_type &value)
	{
		if (_head == nullptr)
			insert_first(value);
		else
			insert_prew(begin(), value);
	}
	void push_front(const _elem_type &value)
	{
		if (_head == nullptr)
			insert_first(value);
		else
			insert_prew(begin(), value);
		_head = _head->_prew;
	}
	void pop_front()
	{
		erase(begin());
	}
	void pop_back()
	{
		erase(end());
	}
	void show() const
	{
		auto i = begin();
		do
		{
			std::cout << *i << std::endl;
			++i;
		} while (i != begin());
	}

	void get_even_list(List &answer) {
		auto i = begin();
		int f = 0;
		do
		{
			++i;
			if (f != 0 && !(i != begin()))
				break;
			answer.push_back(*i);
			++i;
			f++;
		} while (i != begin());
	}
	void clear()
	{
		if (_head != nullptr)
		{
			_head->_prew->_next = nullptr;
			while (_head->_next != nullptr)
			{
				_head = _head->_next;
				delete _head->_prew;
			}
			delete _head;
		}
	}
};

int main()
{
	List<long long> list1;
	List<long long> list2;
	for (int i = 1; i <= 10; i++)
	{

		list1.push_back((double)std::rand() / RAND_MAX * 80 - 40);
	}
	list1.push_front(100);
	list1.get_even_list(list2);
	//list1.get_even_list(list2);
	list1.show();
	std::cout << std::endl;
	list2.show();
	std::cout << std::endl;
	auto a = list1.begin();
	do
	{
		if (*a > 0) {
			std::cout << (*a) << std::endl;
		}
		++a;
	} while (a != list1.begin());
	return 0;
}

