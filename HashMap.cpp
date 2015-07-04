#include"HashMap.h"
#include<iostream>
using namespace std;


int HashMap::Hashfunc(CompositeKey ckey)
{
	int ret = 1;
	ret = 31 * ret + ckey.key1;
	ret = 31 * ret + ckey.key2;
	ret = 31 * ret + ckey.key3;
	return ret;
}

void HashMap::insert(CompositeKey key, int value)
{
	int hashkey = Hashfunc(key);
	int index = hashkey%TableSize;
	HashNode * nn = new HashNode();
	nn->setKeys(key);
	nn->setValue(value);
	nn->setNext(NULL);
	no_of_val++;
	if (array_ptr[index] == NULL)
	{
		array_ptr[index] = nn;
	}
	else
	{
		HashNode* temp = array_ptr[index];
		if (value < temp->getValue())
		{
			nn->setNext(temp);
			array_ptr[index] = nn;
		}
		else
		{
			while (temp->getNext() != NULL)
			{
				if (value < temp->getNext()->getValue())
				{
					nn->setNext(temp->getNext());
					temp->setNext(nn);
					break;
				}
				else
					temp = temp->getNext();
			}
		
			temp->setNext(nn);
		}
		
	}
}
void HashMap::remove(CompositeKey key)
{
	int hashkey = Hashfunc(key);
	int index = hashkey%TableSize;
	HashNode* temp = array_ptr[index];
	if (temp != NULL)
	{
		if (temp->getKey1() == key.key1 && temp->getKey2() == key.key2 && temp->getKey3() == key.key3)
		{
			array_ptr[index] = temp->getNext();
		}
		else
		{
			while (temp->getNext() != NULL)
			{
				HashNode* nxt = temp->getNext();
				if (nxt->getKey1() == key.key1 && nxt->getKey2() == key.key2 && nxt->getKey3() == key.key3)
				{
					temp->setNext(nxt->getNext());
				}
				else
					temp = temp->getNext();
			}
		}
	}
	
	no_of_val--;
}
bool HashMap::containsKey(CompositeKey key)
{
	int hashkey = Hashfunc(key);
	int index = hashkey%TableSize;
	HashNode* temp = array_ptr[index];
	while (temp != NULL)
	{
		if (temp->getKey1() == key.key1 && temp->getKey2() == key.key2 && temp->getKey3() == key.key3)
		{
			return true;
		}
		else
			temp = temp->getNext();
	}
	return false;
		
}
int HashMap::getValue(CompositeKey key)
{
	int hashkey = Hashfunc(key);
	int index = hashkey%TableSize;
	HashNode* temp = array_ptr[index];
	while (temp != NULL)
	{
		if (temp->getKey1() == key.key1 && temp->getKey2() == key.key2 && temp->getKey3() == key.key3)
		{
			return temp->getValue();
		}
		else
			temp = temp->getNext();
	}
	return 0;
}
int HashMap::kthMinValue(int k)
{
	std::vector<CompositeKey> hash_key;
	std::vector<int> hash_val;
	for (int i = 0; i < TableSize; i++)
	{
		HashNode * tmp = array_ptr[i];
		while (tmp != NULL)
		{
			hash_key.push_back(tmp->getCKey());
			hash_val.push_back(tmp->getValue());
			tmp = tmp->getNext();
		}
	}
	std::cout << "\n\nKeys before sorting: \n";
	std::cout << "key1: \t";
	for (int i = 0; i < hash_key.size(); i++)
	{
		std::cout << hash_key[i].key1 << "\t";
	}
	std::cout << "\nkey2: \t";
	for (int i = 0; i < hash_key.size(); i++)
	{
		std::cout << hash_key[i].key2 << "\t";
	}
	std::cout << "\nkey3: \t";
	for (int i = 0; i < hash_key.size(); i++)
	{
		std::cout << hash_key[i].key3 << "\t";
	}

	heap_sort(hash_key, hash_val);

	std::cout << "\nKeys After sorting: \n";
	std::cout << "key1: \t";
	for (int i = 0; i < hash_key.size(); i++)
	{
		std::cout << hash_key[i].key1 << "\t";
	}
	std::cout << "\nkey2: \t";
	for (int i = 0; i < hash_key.size(); i++)
	{
		std::cout << hash_key[i].key2 << "\t";
	}
	std::cout << "\nkey3: \t";
	for (int i = 0; i < hash_key.size(); i++)
	{
		std::cout << hash_key[i].key3 << "\t";
	}
		
	return hash_val[k];
	
}
int HashMap::size()
{
	return no_of_val;
}

void HashMap::heap_sort(std::vector<CompositeKey>& hash_key, std::vector<int>&hash_val)
{
	BuildHeap(hash_key, hash_val);
	for (std::vector<int>::size_type i = hash_key.size() - 1; i > 0; --i)
	{
		Swap(hash_key, i, 0, hash_val);
		MaxHeapify(hash_key, i, 0, hash_val);
	}

}
void HashMap::BuildHeap(std::vector<CompositeKey>& hash_key, std::vector<int>&hash_val)
{
	for (int i = hash_key.size() - 1; i >= 0; --i)
	{
		MaxHeapify(hash_key, hash_key.size(), i, hash_val);
	}
}
void HashMap::MaxHeapify(std::vector<CompositeKey>& hash_key, const std::vector<int>::size_type heapsize, const std::vector<int>::size_type snode, std::vector<int>&hash_val)
{
	std::vector<int>::size_type i, j;

	j = snode;
	do
	{
		i = j;
		if (((2 * i + 1) < heapsize) && hash_key[j].operator<(hash_key[2 * i + 1]))
			j = 2 * i + 1;
		if (((2 * i + 2) < heapsize) && hash_key[j] .operator<(hash_key[2 * i + 2]))
			j = 2 * i + 2;
		Swap(hash_key, i, j, hash_val);
	} while (i != j);

}
void HashMap::Swap(std::vector<CompositeKey>&hash_key, std::vector<int>::size_type i, std::vector<int>::size_type j, std::vector<int>&hash_val)
{
	if (i == j)
		return;

	CompositeKey temp;
	temp = hash_key[i];
	hash_key[i] = hash_key[j];
	hash_key[j] = temp;
	int temp1;
	temp1 = hash_val[i];
	hash_val[i]= hash_val[j];
	hash_val[j] = temp1;
	

}