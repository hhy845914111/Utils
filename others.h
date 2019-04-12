#pragma once
#include "search.h"
#include "sort.h"
#include <utility>

namespace chapter2
{
	template <typename T>
	inline std::pair<T*, T*> find_pair (T *arr, size_t n, T x)
	{
		if (n < 0 || arr == nullptr)
		{
			throw std::invalid_argument("find pair failed");
		}

		T *tmp = new T[n];
		sort::merge_sort(arr, 0, n - 1, tmp);

		for (T *p(arr), *q(arr + n - 1); p < q; ++p)
		{
			if (*p > x)
			{
				delete[]tmp;
				return std::make_pair(nullptr, nullptr);
			}

			T* itm_ptr = search::binary_search(p + 1, q, x - *p);
			if (itm_ptr)
			{
				delete[]tmp;
				return std::make_pair(p, itm_ptr);
			}
		}

		delete[]tmp;
		return std::make_pair(nullptr, nullptr);
	}

	template <typename T>
	inline size_t inverse_count(T *const arr, size_t start, size_t end, T *const tmp)
	{
		if (arr == nullptr || tmp == nullptr || start > end)
		{
			throw std::invalid_argument("merge sort failed.");
		}
		if (start == end)
		{
			return 0;
		}

		size_t mid(size_t((start + end) / 2));

		size_t left_count = inverse_count(arr, start, mid, tmp);
		size_t right_count = inverse_count(arr, mid + 1, end, tmp);

		size_t between_count(0);
		size_t left(start), right(mid + 1);
		for (T *p(tmp + start), *q(tmp + end); p <= q; ++p)
		{
			if (left <= mid && right <= end)
			{
				if (arr[left] >= arr[right])
				{
					*p = std::move(arr[right++]);
					++between_count;
				}
				else
				{
					*p = std::move(arr[left++]);
				}
			}
			else if (left > mid)
			{
				*p = std::move(arr[right++]);
				++between_count;
			}
			else
			{
				*p = std::move(arr[left++]);
			}
		}

		for (T *p(tmp + start), *q(arr + start), *m(tmp + end); p <= m; ++p, ++q)
		{
			*q = std::move(*p);
		}

		return left_count + right_count + between_count;
	}

	template <typename T>
	inline T fib_number(T n)
	{
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}

		T current(1), last(0), tmp;
		for (T i(1); i < n; ++i)
		{
			tmp = current;
			current += last;
			last = tmp;
		}

		return current;
	}
}