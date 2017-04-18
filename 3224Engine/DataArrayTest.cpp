#include "stdafx.h"
#include "DataArrayTest.h"

template<class T>
DataArrayTest<T>::DataArrayTest()
{
	//Set Next ID and data count to 0
	nextId = 0;
	count = 0;

	//Register all locations within the data array as free in the free list
	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		freeList.push_back(i);
	}

	////Create default DataElement objects in all locations of the data array with id = -1
	//for (int i = 0; i < MAX_OBJECTS; i++)
	//{
	//	data[i] = new DataElement;
	//}
}

template<class T>
DataArrayTest<T>::~DataArrayTest()
{

}

template<class T>
T * DataArrayTest<T>::Get(int id)
{
	for (int i = 0; i < count; i++)
	{
		if (data[i].id == id)
		{
			//return *data[i].object;
			return &data[i].object;
		}
	}
	return nullptr;
}

template<class T>
T* DataArrayTest<T>::CreateNew()
{
	if (!freeList.empty())
	{
		int newLocation = freeList.front();
		data[newLocation].id = nextId;

		freeList.pop_front();
		nextId++;
		count++;

		return &data[newLocation].object;
	}
	else
	{
		return nullptr;
	}
}

template<class T>
void DataArrayTest<T>::Free(int id)
{
	for (int i = 0; i < count; i++)
	{
		if (data[i].id == id)
		{
			freeList.push_front(i);
			data[i].id = -1;
		}
	}
}
