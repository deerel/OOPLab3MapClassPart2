#pragma once
/*
Map
Class imitates a C# Dictionary class.
Features:
- Store Unlimited number of keys and values
- An Add function that can be used to add a key and its value to the Map.
- A Remove function which given the key removes the key and its value
- A Count function that returns the number of elements in the Map.
- A Clear function the makes the Map empty.
- Two Boolean functions HasKey and HasValue which return true if the given key or value is present.
- A ToArray function that converts the contents of the Map values (only values) into an array.
- Overloaded [] operator (subscript operator) that allows us to access a value using the key as index.
Please note that the subscript operator should be overloaded in a way that allows statement like map Object[“key String”]=value; in such cases if the key does not exist an exception must be thrown.
- Overloaded << operator to print the whole map in the following form: 
{ [key1, 1233] , [key2, 32423], [key3, 2343] }
You will have to do this through a friend function. There is a special syntax for friends of templates.
You can read more about it here: http://www.cplusplus.com/forum/general/45776/
- An overloaded = operator (assignment operator) that performs a deep copy.
*/

#include <iostream>

#include "Dictionary.h"

using std::ostream;

template <class K, class V>
class Map;

template <class K, class V>
ostream& operator<< (ostream& os, const Map<K,V>& M);

template <class K, class V>
class Map
{
private:
	int numOfElements;
	Dictionary<K, V> * head;
public:
	void Add(K key, V value);
	void Remove(K key);
	int Count();
	void Clear();
	bool HasKey(K key);
	bool HasValue(V value);
	void ToArray(V** valueArr);
	V& operator[] (K key);
	friend ostream& operator<< <>(ostream& os, Map& M);
	void operator= (Map& M);
	Map();
	~Map();
};

template <class K, class V>
Map<K,V>::Map()
{
	numOfElements = 0;
}

template <class K, class V>
Map<K,V>::~Map()
{
	this->Clear();
}

template<class K, class V>
void Map<K, V>::Add(K key,  V value)
{
	Dictionary<K, V> * tmp = new Dictionary<K, V>;
	
	tmp->key = key;
	tmp->value = value;
	numOfElements++;

	if (numOfElements == 0)
		tmp->next = nullptr;
	else
		tmp->next = head;
	head = tmp;
}

template<class K, class V>
void Map<K, V>::Remove(K key)
{
	Dictionary<K, V> * tmp;
	Dictionary<K, V> * prev;
	tmp = head;
	prev = head;
	while (tmp != nullptr)
	{
		if (tmp->key == key)
		{
			if (prev == tmp && prev->next != nullptr) //First node
			{
				head = prev->next;
			}
			else if (tmp == prev) //Only one node
			{
				head = nullptr;
			}
			else if (tmp->next == nullptr) //Last node
			{
				prev->next = nullptr;
			}
			else //In the middle
			{
				prev->next = tmp->next;
			}

			delete tmp;
			numOfElements--;
			return;
		}
		else
		{
			prev = tmp;
		}

		tmp = tmp->next;
	}
}

template<class K, class V>
int Map<K, V>::Count()
{
	return numOfElements;
}

template<class K, class V>
void Map<K, V>::Clear()
{
	Dictionary<K, V> * tmp;
	tmp = head;
	while(head != nullptr)
	{
		Remove(tmp->key);
		tmp = head;
	}
}

template<class K, class V>
bool Map<K, V>::HasKey(K key)
{
	Dictionary<K, V> * tmp;
	tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->key == key)
		{
			return true;
		}
		tmp = tmp->next;
	}

	return false;
}

template<class K, class V>
bool Map<K, V>::HasValue(V value)
{
	Dictionary<K, V> * tmp;
	tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->value == value)
		{
			return true;
		}
		tmp = tmp->next;
	}

	return false;
}

template<class K, class V>
void Map<K, V>::ToArray(V** valueArr)
{
	Dictionary<K, V> * tmp;
	tmp = head;
	int i = 0;

	while (tmp != nullptr)
	{
		(*valueArr)[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
}

template <class K, class V>
V& Map<K,V>::operator[](K key)
{
	Dictionary<K, V> * tmp;
	tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->key == key)
		{
			return tmp->value;
		}
		tmp = tmp->next;
	}

	throw "Key not found!";
}

template <class K, class V>
void Map<K,V>::operator= (Map& M)
{
	Dictionary<K, V> * tmp;
	tmp = M.head;
	while (tmp != nullptr)
	{
		this->Add(tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

// NOT A MAP FUNCTION (...but a good friend)
template <class K, class V>
ostream& operator<< (ostream& os,Map<K, V>& M)
{

	os << "{ ";
	Dictionary<K, V> * tmp;
	tmp = M.head;
	while (tmp != nullptr)
	{
		os << "[";
		os << tmp->key;
		os << ", ";
		os << tmp->value;
		os << "]";
		
		tmp = tmp->next;

		if (tmp != nullptr)
		{
			os << " , ";
		}
	}
	os << " }";
	return os;
}