#pragma once
#include <list>
namespace ListHelper
{
	template <typename T>
	T GetListElementAtIndex(std::list<T>& _list, int _index)
	{
		std::list<T>::iterator it = _list.begin();
		for (auto i = 0; i < _index; i++) {
			++it;
		}
		return *it;
	}
}