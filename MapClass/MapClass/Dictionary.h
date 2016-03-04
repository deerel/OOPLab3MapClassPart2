#pragma once
/*
Datatype for Map class.
*/

template<class K, class V>
class Dictionary
{
public:
	K key;
	V value;
	Dictionary * next;
};
