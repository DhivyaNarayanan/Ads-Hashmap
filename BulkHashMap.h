#include"Interfaces05.h"

class BulkHashMap : public IBulkHashMap
{
	std::vector<std::pair<CompositeKey, int> > tmp_vec;
public:
	BulkHashMap() { }
	~BulkHashMap() { }
	void insert(std::vector<std::pair<CompositeKey, int> >& data);
	int getValue(CompositeKey key);
};