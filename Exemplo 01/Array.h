#pragma once
#include <iostream>
using namespace std;


template<class A>
class Array
{

public:
	A* m_array;
	int m_size;
	Array(int p_size)
	{
		m_array = new A[p_size];
		m_size = p_size;
	}

	~Array()
	{
		if (m_array != 0)		
			delete[] m_array;		
		m_array = 0;
	}
	void Resize(int p_size)
	{
		A* m_novoarray = new A;
		if (m_novoarray == 0)
			return;
		int min;
		if (p_size < m_size)
			min = p_size;
		else
			min = m_size;
		for (int index = 0; index < min; index++)
			m_novoarray[index] = m_array[index];
		m_size = p_size;
		if (m_array != 0)
			delete[] m_array;
		m_array = m_novoarray;
	}
	A& operator[] (int p_index)
	{
		return m_array[p_index];
	}
	operator A* ()
	{
		return m_array;
	}
	void Insert(A p_item, int p_index)
	{
		int index;
		for (index = m_size - 1; index > p_index; index--)
		{
			m_array[index] = m_array[index - 1];
		}
		m_array[p_index] = p_item;
	}

	void Remove(int p_index)
	{
		int index;
		for (index = p_index + 1; index < m_size; index++)
		{
			m_array[index - 1] = m_array[index];
		}
	}

	int Size()
	{
		return m_size;
	}



};