#include"HashNode.h"


void HashNode::setKeys(CompositeKey ckeys)
{
	this->keys.key1 = ckeys.key1;
	this->keys.key2 = ckeys.key2;
	this->keys.key3 = ckeys.key3;
}

void HashNode::setValue(int val)
{
	this->value = val;
}
void HashNode::setNext(HashNode*next)
{
	this->Next = next;
}
HashNode* HashNode::getNext()
{
	return this->Next;
}
int HashNode::getValue()
{
	return this->value;
}
int HashNode::getKey1()
{
	return this->keys.key1;
}
float HashNode::getKey2()
{
	return this->keys.key2;
}
int HashNode::getKey3()
{
	return this->keys.key3;
}
CompositeKey HashNode::getCKey()
{
	return this->keys;
}