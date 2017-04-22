#include "stdafx.h"
#include "DataArray.h"

template<class T> DataArray<T>::DataArray()
{
	Initialise();
}

template<class T> DataArray<T>::~DataArray()
{
	delete data;
	freeList.clear();
}

template<class T> void DataArray<T>::Initialise()
{
	//Set Next ID and data count to 0.
	nextId = 0;
	count = 0;

	//Set lastLookup to -1 so that DataArray::Next() returns the first element.
	lastLookup = -1;

	//Register all locations within the data array as free in the free list
	for(int i = 0; i < MAX_OBJECTS; i++)
	{
		freeList.push_back(i);
	}
}

template<class T> T* DataArray<T>::CreateNew()
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

template<class T> void DataArray<T>::Free(int id)
{
	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		if (data[i].id == id)
		{
			freeList.push_front(i);
			data[i].id = -1;
			count--;
		}
	}
}

template<class T> bool DataArray<T>::Exists(int id)
{
	bool found = false;
	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		if (data[i].id == id)
		{
			found = true;
		}
	}

	return found;
}

//Returns a pointer to the object or, if the object does not exist, returns a nullptr.
template<class T> T * DataArray<T>::TryToGet(int id)
{
	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		if (data[i].id == id)
		{
			lastLookup = i;
			return &data[i].object;
		}
	}
	return nullptr;
}

//Looks up the ID for a returned object. If the object no longer exists then returns -1.
template<class T> int DataArray<T>::GetId(T & object)
{
	int id = -1;
	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		if (&data[i].object == &object)
		{
			id = i;
		}
	}

	return id;
}

template<class T> T * DataArray<T>::TryToGetFirst()
{
	for(int i = 0; i < MAX_OBJECTS; i++)
	{
		if(data[i].id !=-1)
		{
			lastLookup = i;
			return &data[i].object;
		}
	}

	return nullptr;
}

template<class T>
bool DataArray<T>::IsNext()
{
	bool found = false;
	for (int i = lastLookup + 1; i < MAX_OBJECTS; i++)
	{
		if (data[i].id != -1)
		{
			found = true;
		}
	}
	return found;
}

template<class T> T * DataArray<T>::Next()
{
	for (int i = lastLookup+1; i < MAX_OBJECTS; i++)
	{
		if (data[i].id != -1)
		{
			lastLookup = i;
			return &data[i].object;
		}
	}
	return nullptr;
}

//Returns the number of unexpired objects within the data structure
template<class T> int DataArray<T>::Count()
{
	return count;
}

template<class T> void DataArray<T>::FreeAll()
{
	for (int i = (MAX_OBJECTS - 1); i >= 0; i--)
	{
		if (data[i].id != -1)
		{
			data[i].id = -1;
			freeList.push_front(i);
		}
	}

	lastLookup = -1;
	nextId = 0;
	count = 0;
}
