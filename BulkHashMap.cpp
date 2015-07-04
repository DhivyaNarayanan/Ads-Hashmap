#include"BulkHashMap.h"

void BulkHashMap::insert(std::vector<std::pair<CompositeKey, int> >& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		tmp_vec.push_back(data[i]);
	}
}
int BulkHashMap::getValue(CompositeKey key)
{
	for (int i = 0; i < tmp_vec.size(); i++)
	{
		if (tmp_vec[i].first == key)
			return tmp_vec[i].second;
	}
}