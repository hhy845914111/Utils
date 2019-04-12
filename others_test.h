#pragma once
#include "others.h"
#include "test_utils.h"
#include <iostream>

namespace others_test
{
	using namespace test_utils;
	void run()
	{
#if 0
		// find pair
		int *arr = test_utils::arange(0, 20, 1);

		auto&& rst = chapter2::find_pair(arr, 20, 99);
		std::cout << rst << std::endl;

#endif

#if 0
		int arr[]{ 1, 5, 3, 4, 2 };
		int tmp[5];
		std::cout << chapter2::inverse_count(arr, 0, 5 - 1, tmp);

#endif

#if 1
		std::cout << chapter2::fib_number<long long>(50);

#endif

	}
}