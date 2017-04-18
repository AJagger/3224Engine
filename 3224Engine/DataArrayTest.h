#pragma once
#include <deque>

template<class T>
class DataArrayTest
{
	struct DataElement
	{
		T object;
		int id;
	};

public:
	DataArrayTest();
	~DataArrayTest();

	static const int MAX_OBJECTS = 300;
	int count;
	int nextId;

	DataElement data[MAX_OBJECTS];
	std::deque<int> freeList;

	//bool Check(int id);
	T* Get(int id);

	T* CreateNew();
	void Free(int id);
};

