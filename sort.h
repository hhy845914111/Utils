#pragma once

namespace sort
{
	template <typename T>
	inline void insert_sort(T* const start, T* const end)
	{
		if (start == nullptr || end == nullptr || start > end)
		{
			throw std::invalid_argument("start > end.");
		}
		if (start == end) return;


		T *m(nullptr);
		for (T *p(start + 1); p <= end; ++p)
		{
			T tmp(*p);
			m = p;
			for (; m > start && *(m - 1) > tmp; --m)
			{
				*m = *(m - 1);
			}
			*m = std::move(tmp);
		}
	}

	template <typename T>
	inline void merge_sort(T *const arr, size_t start, size_t end, T *const tmp)
	{	
		if (arr == nullptr || tmp == nullptr || start > end)
		{
			throw std::invalid_argument("merge sort failed.");
		}
		if (start == end)
		{
			return;
		}

		size_t mid(size_t((start + end) / 2));

		merge_sort(arr, start, mid, tmp);
		merge_sort(arr, mid + 1, end, tmp);

		// merge function
		size_t left(start), right(mid + 1);
		for (T *p(tmp + start), *q(tmp + end); p <= q; ++p)
		{
			if (left <= mid && right <= end)
			{
				if (arr[left] >= arr[right])
				{
					*p = std::move(arr[right++]);
				}
				else
				{
					*p = std::move(arr[left++]);
				}
			}
			else if (left > mid)
			{
				*p = std::move(arr[right++]);
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
	}

	template <typename T>
	inline void merge_insert_sort(T *const arr, size_t start, size_t end, T *const tmp, size_t k=5)
	{
		if (arr == nullptr || tmp == nullptr || start > end || k <= 0)
		{
			throw std::invalid_argument("merge insert sort failed.");
		}
		if (start == end)
		{
			return;
		}

		if (end - start < k)
		{
			insert_sort(arr + start, arr + end);
			return;
		}
		size_t mid(size_t((start + end) / 2));
		merge_sort(arr, start, mid, tmp);
		merge_sort(arr, mid + 1, end, tmp);

		size_t left(start), right(mid + 1);
		for (T *p(tmp + start), *q(tmp + end); p <= q; ++p)
		{
			if (left <= mid && right <= end)
			{
				if (arr[left] >= arr[right])
				{
					*p = std::move(arr[right++]);
				}
				else
				{
					*p = std::move(arr[left++]);
				}
			}
			else if (left > mid)
			{
				*p = std::move(arr[right++]);
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
	}
}
