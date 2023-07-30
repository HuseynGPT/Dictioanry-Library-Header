#include <iostream>
#include <cassert>
using namespace std;



template<class TPairKey, class TPairValue>
class KeyValuePair {
	TPairKey key;
	TPairValue value;

	KeyValuePair() : key(), value() {}

	KeyValuePair(TPairKey key, TPairValue value)
	{
		this->key = key;
		this->value = value;
	}
};



template<class TKey, class TValue>
class Dictionary
{
	KeyValuePair<TKey, TValue>* _pairs = nullptr;
	size_t _count = 0;
	size_t _capacity = 5;

public:

	void add(KeyValuePair<TKey, TValue>& item)
	{
		if (containsKey(item))
			assert(!"Bele bir element  artiq var");

		auto temp = new KeyValuePair<TKey, TValue>[++_count];

		for (size_t i = 0; i < _count; i++)
			temp[i] = _pairs[i];

		temp[--_count] = item;
		delete[] _pairs;
		_pairs = temp;

	}
	void add(TKey key, TValue value)
	{
		if (containsKey(key))
			assert(!"Bele bir element  artiq var");

		auto temp = new KeyValuePair<TKey, TValue>[++_count];

		for (size_t i = 0; i < _count - 1; i++)
			temp[i] = _pairs[i];

		temp[_count - 1] = KeyValuePair<TKey, TValue>(key, value);

		delete[] _pairs;
		_pairs = temp;
	}
	TValue& operator[](TKey key)
	{
		for (size_t i = 0; i < _count; i++)
			if (_pairs[i].key == key)
				return _pairs[i].value;

		assert(!"Key Not found");
	}
	inline size_t count() const { return _count; };
	inline size_t capacity() const { return _capacity; };


	TKey* keys() {
		TKey* keyArray = new TKey[_count];
		for (size_t i = 0; i < _count; i++)
			keyArray[i] = _pairs[i].getKey();

		return keyArray;
	}

	TValue* values() {
		TValue* valueArray = new TValue[_count];
		for (size_t i = 0; i < _count; i++)
			valueArray[i] = _pairs[i].getValue();

		return valueArray;
	}
	KeyValuePair<TKey, TValue>* items()
	{
		KeyValuePair<TKey, TValue>* itemArray = new KeyValuePair<TKey, TValue>[_count];
		for (size_t i = 0; i < _count; i++)
			itemArray[i] = _pairs[i];

		return itemArray;
	}
	void clear()
	{
		delete[] _pairs;
		_pairs = nullptr;
		_count = 0;
	}
	bool containsKey(const TKey key) const
	{
		for (size_t i = 0; i < _count; i++)
		{
			if (_pairs[i].key == key)
				return true;
		}
		return false;
	}
	bool containsValue(const TValue value) const
	{
		for (size_t i = 0; i < _count; i++)
		{
			if (_pairs[i].value == value)
				return true;
		}
		return false;
	}


};
//#######################################################
// Example for Using
// ########################################################
//template<class TKey, class TValue>
//int main()
//{
//	Dictionary<int, string> map;
//
//	map.add(10, "Baku");
//	map.add(20, "Gence");
//	map.add(50, "Sumqayit");
//
//
//	// cout << map[20] << endl;
//	// cout << map[50] << endl;
//
//	// cout << map.count() << endl;
//
//	/*const TKey a = 10;
//	cout << map.containsKey(a);*/
//}