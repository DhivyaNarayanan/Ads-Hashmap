#include"Interfaces05.h"
#include"HashNode.h"

#define TableSize 23

class HashMap : public IHashMap
{
	
	HashNode * array_ptr[TableSize];
	int no_of_val;
	
public:
	HashMap() 
	{
		for (int i = 0; i < TableSize; i++)
		{
			array_ptr[i] = NULL;
		}
		no_of_val = 0;
	}
	~HashMap() { }
	int Hashfunc(CompositeKey key);
	void insert(CompositeKey key, int value);
	void remove(CompositeKey key);
	bool containsKey(CompositeKey key);
	int getValue(CompositeKey key);
	int kthMinValue(int k);
	int size();
	void heap_sort(std::vector<CompositeKey>& hash_key, std::vector<int>&hash_val);
	void BuildHeap(std::vector<CompositeKey>& hash_key, std::vector<int>&hash_val);
	void MaxHeapify(std::vector<CompositeKey>& hash_key, const std::vector<int>::size_type heapsize, const std::vector<int>::size_type snode, std::vector<int>&hash_val);
	void Swap(std::vector<CompositeKey>&hash_key, std::vector<int>::size_type i, std::vector<int>::size_type j, std::vector<int>&hash_val);


};