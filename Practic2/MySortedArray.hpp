#pragma once

#include "MyArrayChild.hpp"

class MySortedArray : public MyArrayChild
{
public:
	MySortedArray(int dimension = 100) : MyArrayChild(dimension) { }

	~MySortedArray() { }

	void Push(double value)
	{
		if(_count >= _capacity)
			return;

		if(_count <= 0)
		{
			MyArrayParent::Push(value);
			return;
		}

		if(value < _ptr[0])
		{
			InsertAt(value,0);
			return;
		}

		for(int i = 1;i < _count;i++)
			if(_ptr[i - 1] <= value && value <= _ptr[i])
			{
				InsertAt(value,i);
				return;
			}

		MyArrayParent::Push(value);
	}

	MySortedArray ReplaceRepeats()
	{
		double average = GetAverage();

		MySortedArray array(*this);

		// Заменяю повторы
		for(int i = 1;i < _count;i++)
			if(_ptr[i - 1] == _ptr[i])
			{
				array.SetComponent(i - 1,average);
				array.SetComponent(i,average);
			}

		return array;
	}

	int IndexOf(double value, bool bFindFromStart = true)
	{
		// Бинарный поиск (деление пополам)

		int left = 0,right = _count;

		while(true)
		{
			int midd = (left + right) / 2;

			if (value < _ptr[midd])
				right = midd - 1;
			else if (value > _ptr[midd])
				left = midd + 1;
			else
				return midd;

			if (left > right)
				return -1;
		}

		return -1;
	}
};