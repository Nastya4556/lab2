#pragma once

#include <stdexcept>
#include <iostream>

#include "Sequence.h"
#include "MutableSequence.h"
#include "LinkedList.h"
#include "DynamicArray.h"

template <class T> class MutableListSequence: public MutableSequence<T>
{
private:
	LinkedList<T>* list;
public:
	MutableListSequence(const T* items, int size) : list(new LinkedList<T>(items, size)) {}
	MutableListSequence() : list(new LinkedList<T>()) {}
	MutableListSequence(int size) : list(new LinkedList<T>(size)) {}
	MutableListSequence(const LinkedList<T>& other) : list(new LinkedList<T>(other)) {}
	MutableListSequence(const DynamicArray<T>& other) : list(new LinkedList<T>(other)) {}
	MutableListSequence(const Sequence<T>& other) : list(new LinkedList<T>(other)) {}
	MutableListSequence(const MutableListSequence<T>& other) : list(new LinkedList<T>(*other.list)) {}
	~MutableListSequence() override
	{
		delete list;
	}
	const T& operator [] (int index) const override
	{
		return (*list)[index];
	}
	T GetFirst() const override
	{
		return this->list->GetFirst();
	}
	T GetLast() const override
	{
		return this->list->GetLast();
	}
	T Get(int index) const override
	{
		return (*list)[index];
	}
	MutableListSequence<T>* GetSubsequence(int startIndex, int endIndex) const override
	{
		return new MutableListSequence<T>(*this->list->GetSubList(startIndex, endIndex));
	}
	int GetLength() const override
	{
		return this->list->GetLength();
	}
	void Append(const T& item) override
	{
		this->list->Append(item);
	}
	void Prepend(const T& item) override
	{
		this->list->Prepend(item);
	}
	void InsertAt(int index, const T& item) override
	{
		this->list->InsertAt(index, item);
	}
	MutableListSequence<T>* Concat(const Sequence<T>& other) const
	{
		MutableListSequence<T>* result = new MutableListSequence<T>(*this);
		for (int i = 0; i < other.GetLength(); i++)
		{
			result->list->Append(other.Get(i));
		}
		return result;
	}
	MutableListSequence<T>* GetSubsequence(int startIndex, int endIndex) 
	{
		MutableListSequence<T>* result = new MutableListSequence<T>;
		for (int i = startIndex; i <= endIndex; i++)
		{
			result->list->Append(this->Get(i));
		}
		return result;
	}
	void Set(int index, const T& item) override
	{
		return this->list->Set(index, item);
	}
};

