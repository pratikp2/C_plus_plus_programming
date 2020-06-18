/*
Task Description
interval_map<K,V> is a data structure that efficiently associates intervals of keys of type K with values of type V. Your task is to implement the assign member function of this data structure, which is outlined below.
interval_map<K, V> is implemented on top of std::map. In case you are not entirely sure which functions std::map provides, what they do and which guarantees they provide, we provide an excerpt of the C++ standard here:
Each key-value-pair (k,v) in the std::map means that the value v is associated with the interval from k (including) to the next key (excluding) in the std::map.
Example: the std::map (0,'A'), (3,'B'), (5,'A') represents the mapping
0 -> 'A'
1 -> 'A'
2 -> 'A'
3 -> 'B'
4 -> 'B'
5 -> 'A'
6 -> 'A'
7 -> 'A'
... all the way to numeric_limits<int>::max()
The representation in the std::map must be canonical, that is, consecutive map entries must not have the same value: ..., (0,'A'), (3,'A'), ... is not allowed. Initially, the whole range of K is associated with a given initial value, passed to the constructor of the interval_map<K,V> data structure.
Key type K
besides being copyable and assignable, is less-than comparable via operator<
is bounded below, with the lowest value being std::numeric_limits<K>::lowest()
does not implement any other operations, in particular no equality comparison or arithmetic operators
Value type V
besides being copyable and assignable, is equality-comparable via operator==
does not implement any other operations
*/

#include <map>
#include <limits>
#include <ctime>

template<typename K, typename V>
class interval_map
{
	std::map<K, V> m_map;

public:
	// constructor associates whole range of K with val by inserting (K_min, val) into the map
	interval_map(V const& val)
	{
		m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
	}

	void assign(K const& keyBegin, K const& keyEnd, V const& val)
	{
		if (keyEnd < keyBegin)
			return;

		std::pair<K, V> beginPair, endPair;
		bool beginActive = false, endActive = false, midActive = true;
		typename std::map<K, V>::const_iterator itrBegin = m_map.lower_bound(keyBegin);

		if (itrBegin != m_map.end() && keyBegin < itrBegin->first)
			if (itrBegin != m_map.begin())
			{
				beginActive = true;
				--itrBegin;
				beginPair = std::make_pair(itrBegin->first, itrBegin->second);
			}

		typename std::map<K, V>::const_iterator itrEnd;
		itrEnd = m_map.lower_bound(keyEnd);

		if (itrEnd != m_map.end() && keyEnd < itrEnd->first)
		{
			endActive = true;
			typename std::map<K, V>::const_iterator extraIt = itrEnd;
			--extraIt;
			endPair = std::make_pair(keyEnd, extraIt->second);
		}

		if (beginActive)
			if (beginPair.second == val)
				midActive = false;
		else
			if (itrBegin != m_map.begin())
			{
				typename std::map<K, V>::const_iterator beforeMid = itrBegin;
				--beforeMid;
				if (beforeMid->second == val)
					midActive = false;
			}

		if (endActive)
			if ((midActive && endPair.second == val) || (!midActive && endPair.second == beginPair.second))
				endActive = false;
		else
			if ((midActive && itrEnd != m_map.end() && itrEnd->second == val) || (!midActive && itrEnd != m_map.end() && itrEnd->second == beginPair.second))
				itrEnd = m_map.erase(itrEnd);

		itrBegin = m_map.erase(itrBegin, itrEnd);
		if (beginActive)
			itrBegin = m_map.insert(itrBegin, beginPair);
		if (midActive)
			itrBegin = m_map.insert(itrBegin, std::make_pair(keyBegin, val));
		if (endActive)
			m_map.insert(itrBegin, endPair);
	}

	// look-up of the value associated with key
	V const& operator[](K const& key) const
	{
		return (--m_map.upper_bound(key))->second;
	}
};

int main()
{
	int value = 10;
	interval_map<unsigned int, int> obj(value);
	obj.assign(0, 10, value);
	obj.assign(2, 8, 6);
	obj.assign(4, 6, 2);
}