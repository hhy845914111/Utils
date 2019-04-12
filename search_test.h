#pragma once
#include "search.h"
#include "test_utils.h"
#include <iostream>

namespace search_test
{
	void run()
	{
		int *arr = test_utils::arange(0, 20, 1);
		test_utils::print_arr(arr, 20);

# if 0
		// linear search
		int *itm = search::linear_search(arr, arr + 20 - 1, 15);
		std::cout << *itm;
#endif

#if 1
		// binary search
		int *itm = search::binary_search(arr, arr + 20 - 1, 19);
		std::cout << *itm;

		delete[] arr;
#endif
	}
}