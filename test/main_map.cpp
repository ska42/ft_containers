#include "Test.hpp"
#include <sstream>

template <typename Key, typename T>
static ft::IteratorMap<Key, T> get_n_fwd(ft::Map<Key, T>& map, size_t index)
{
	size_t i = 0;
	for (ft::IteratorMap<Key, T> ite = map.begin(); ite != map.end(); ++ite)
	{
		if (i++ == index)
			return ite;
	}
	std::stringstream ss;
	ss << "Index " << index << " is out of bound!";
	throw std::out_of_range(ss.str());
}
template <typename Key, typename T>
static typename ft::Map<Key, T>::reverse_iterator get_n_bwd(
	ft::Map<Key, T>& map, size_t index)
{
	size_t i = map.size() - 1;
	for (typename ft::Map<Key, T>::reverse_iterator ite = map.rbegin();
			ite != map.rend(); ++ite)
	{
		if (i-- == index)
			return ite;
	}
	exit(0);
	std::stringstream ss;
	ss << "Index " << index << " is out of bound!";
	throw std::out_of_range(ss.str());
}
static void test_insert()
{
	ft::Map<int, int>		map;
	std::pair<ft::Map<int, int>::iterator, bool> res;
	assert(map.empty());
	res = map.insert(std::pair<int, int>(13, 150));
	assert(res.second == true);
	assert(map.size() == 1);
	assert(!map.empty());
	assert((*map.begin()).first == 13);
	res = map.insert(std::pair<int, int>(13, 130));
	assert(res.second == false);
	assert(map.size() == 1);
	res = map.insert(std::pair<int, int>(62, 130));
	assert(map.size() == 2);
}
static void test_operator()
{
	ft::Map<int, int>			map;
	ft::Map<int, int>::iterator	it;
	map[2] = 12;
	assert(map.size() == 1);
	it = map.begin();
	assert(it->second == 12);
	map[3];
	++it;
	assert(map.size() == 2);
	assert(it->first == 3);
	map[2] = 14;
	--it;
	assert(map.size() == 2);
	assert(it->second == 14);
}
static void test_erase()
{
	std::pair<int, int> array[5] = { 
		std::pair<int, int>(3, 32),
		std::pair<int, int>(4, 0),
		std::pair<int, int>(314, 3),
		std::pair<int, int>(0, 6),
		std::pair<int, int>(1, 6),
	};
	ft::Map<int, int> map(array, array + 5);
	map.erase(map.begin());
	assert(map.size() == 4);
	ft::Map<int, int>::iterator	it = map.begin();
	assert(it->first == 1);
	assert(it->second == 6);
	it = map.begin();
	++it;
	++it;
	map.erase(it);
	assert(map.size() == 3);
	assert(map.find(4) == map.end());
	map.clear();
	assert(map.size() == 0);
	assert(map.empty());
}
static void test_swap()
{
	std::pair<int, int> array[5] = { 
		std::pair<int, int>(3, 32),
		std::pair<int, int>(4, 0),
		std::pair<int, int>(314, 3),
		std::pair<int, int>(0, 6),
		std::pair<int, int>(1, 6),
	};
	ft::Map<int, int> map(array, array + 5);
	std::pair<int, int> array2[3] = {
		std::pair<int, int>(10, 32),
		std::pair<int, int>(20, 32),
		std::pair<int, int>(30, 32),
	};
	ft::Map<int, int> map2(array2, array2 + 3);
	map.swap(map2);
	assert(map.size() == 3);
	assert(map2.size() == 5);
	assert(get_n_fwd(map, 0)->first == 10);
	assert(get_n_bwd(map2, 0)->first == 0);
	map2.swap(map);
	assert(map.size() == 5);
	assert(map2.size() == 3);
	assert(get_n_fwd(map, 0)->first == 0);
	assert(get_n_bwd(map2, 0)->first == 10);
}
void test_map()
{
	test_one("insert", test_insert);
	test_one("operator", test_operator);
	test_one("erase", test_erase);
	test_one("swap", test_swap);
}
