#pragma once

namespace search 
{
	template <typename T>
	inline T* linear_search(T* start, T* end, const T& target)
	{
		if (start == nullptr || end == nullptr)
		{
			throw std::invalid_argument("linear search failed.");
		}

		T *rst(nullptr);
		while (start <= end)
		{
			if (*start == target)
			{
				rst = start;
				break;
			}
			++start;
		}

		return rst;
	}
	
	template <typename T>
	inline T* binary_search(T* start, T* end, const T& target)
	{
		T *mid;
		do
		{
			mid = (start + size_t((end - start) / 2));

			if (*mid == target)
			{
				return mid;
			}
			else if (*mid < target)
			{
				start = mid;
			}
			else
			{
				end = mid;
			}

		} while (end - start > 1);

		// this is because the mid has incline to the left
		if (*end == target) return end;
		
		return nullptr;
	}
}