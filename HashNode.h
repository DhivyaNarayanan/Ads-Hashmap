#include"Interfaces05.h"

class HashNode
{
	CompositeKey keys;
	int value;
	HashNode* Next;

public:
	HashNode()
	{
		Next = NULL;
		value = -10;
		keys.key1 = -10;
		keys.key2 = -10.0;
		keys.key3 = -10;
	};
	~HashNode(){};
	void setKeys(CompositeKey ckeys);
	void setValue(int val);
	void setNext(HashNode*next);
	HashNode* getNext();
	int getValue();
	int getKey1();
	float getKey2();
	int getKey3();
	CompositeKey getCKey();
	
};