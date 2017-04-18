#pragma once
#include <deque>

template<class T>
class DataArray
{
	struct DataElement
	{
		T object;
		int id = -1;
	};

public:
	DataArray();
	~DataArray();

	T* CreateNew();
	void Free(int id);

	bool Exists(int id);
	T* TryToGet(int id);
	int GetId(T &object);
	bool IsNext();
	T* Next();
	int Count();

private:
	static const int MAX_OBJECTS = 300;
	int count;
	int nextId;
	int lastLookup;

	DataElement data[MAX_OBJECTS];
	std::deque<int> freeList;

	void Initialise();


	//struct DataArrays<T>
	//{
	//	void Init(int count); // allocs items (max 64k), then Clear()
	//	void Dispose();       // frees items
	//	void Clear();         // resets data members, (runs destructors* on outstanding items, *optional)

	//	T &Alloc();           // alloc (memclear* and/or construct*, *optional) an item from freeList or items[maxUsed++], sets id to (nextKey++ << 16) | index
	//	void Free(T &);       // puts entry on free list (uses id to store next)

	//	int GetID(T &);       // accessor to the id part if Item

	//	T &Get(id)            // return item[id & 0xFFFF]; 
	//	T *TryToGet(id);      // validates id, then returns item, returns null if invalid.  for cases like AI references and others where 'the thing might have been deleted out from under me'

	//	bool Next(T *&);      // return next item where id & 0xFFFF0000 != 0 (ie items not on free list)

	//	struct Item {
	//		T item;
	//		int id;             // (key << 16 | index) for alloced entries, (0 | nextFreeIndex) for free list entries
	//	};

	//	Item *items;
	//	int maxSize;          // total size
	//	int maxUsed;          // highest index ever alloced
	//	int count;            // num alloced items
	//	int nextKey;          // [1..2^16] (don't let == 0)
	//	int freeHead;         // index of first free entry
	//};
};
