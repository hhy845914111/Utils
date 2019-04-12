#pragma once
#include "test_utils.h"
#include "sort.h"
#include <iostream>

namespace sort_test
{
	const size_t ARRAY_LEN = 100000;

	void run()
	{
		//insert_sort
		int* rand_arr = test_utils::generate_rand_int_arr(ARRAY_LEN);
#if 0
		sort::insert_sort(rand_arr, rand_arr + ARRAY_LEN - 1);
		//test_utils::print_arr(rand_arr, ARRAY_LEN);
		std::cout << test_utils::is_ascend(rand_arr, ARRAY_LEN) << std::endl;
#endif

		//merge_sort
#if 0
		test_utils::generate_rand_int_arr(ARRAY_LEN, rand_arr);
		int *tmp = new int[ARRAY_LEN];
		sort::merge_sort(rand_arr, 0, ARRAY_LEN - 1, tmp);
		//test_utils::print_arr(rand_arr, ARRAY_LEN);
		std::cout << test_utils::is_ascend(rand_arr, ARRAY_LEN);
		delete[]tmp;
#endif

#if 1
		test_utils::generate_rand_int_arr(ARRAY_LEN, rand_arr);
		int *tmp = new int[ARRAY_LEN];
		sort::merge_insert_sort(rand_arr, 0, ARRAY_LEN - 1, tmp);
		test_utils::print_arr(rand_arr, ARRAY_LEN);
		std::cout << test_utils::is_ascend(rand_arr, ARRAY_LEN);
		delete[]tmp;
#endif

		delete[]rand_arr;
	}

}