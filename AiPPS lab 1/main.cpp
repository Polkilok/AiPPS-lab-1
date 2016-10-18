#include <iostream>
#include <list>
#include <random>

#include "CycleList.h"

int main()
{
	CycleList<long long> list1;
	for (int i = 0; i < 10; i++)
	{

		list1.PushBack((double)std::rand() / RAND_MAX * 80 - 40);
	}
	list1.PushBack(100);
	auto iter = list1.GetIterator();
	while(iter->IsEnd() == false)
	{
		std::cout << iter->GetItem() << std::endl;
		iter->Next();
	}
	list1.FreeIterator(iter);
	return 0;
}

