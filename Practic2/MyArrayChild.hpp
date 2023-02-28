#pragma once

#include "MyArrayParent.hpp"

class MyArrayChild : public MyArrayParent
{
public:
	MyArrayChild(int dimension = 100) : MyArrayParent(dimension) { }

	~MyArrayChild() { }

	//удаление элемента
	void RemoveAt(int index = -1)
	{
		if(index < 0)
			return;

		for(int i = index;i < _count;i++)
			_ptr[i] = _ptr[i + 1];

		_count--;
	};

	//вставка элемента
	void InsertAt(double value, int index = -1)
	{
		if(index < 0 || index > _count || _count >= _capacity)
			return;

		for(int i = _count;i > index;i--)
			_ptr[i] = _ptr[i - 1];

		_ptr[index] = value;

		_count++;
	};

	//Все повторяющиеся элементы (дубли) заменить средним арифме-тическим исходного массива
	MyArrayChild ReplaceRepeats()
	{
		double average = GetAverage();

		MyArrayChild array(*this);

		// Заменяю повторы
		for(int i = 0;i < _count;i++)
			for(int j = 0;j < _count;j++)
				if(i != j && _ptr[i] == _ptr[j])
				{
					array.SetComponent(i,average);
					break;
				}

		return array;
	};
};
