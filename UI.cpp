#include <iostream>
#include "UI.h"
#include "Sequence.h"
#include "MutableListSequence.h"
#include "MutableArraySequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"

template <typename T> struct MutableListSequence_func
{
private:
	MutableListSequence<T>* sequence = new MutableListSequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Mutable Linked List\n";
		std::cin >> length;
		std::cout << "Input elements of Mutable Linked List:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() == 0)
			{
				std::cout << "Mutable Linked List is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch(std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch(std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void appendValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Append(value);
	}
	void prependValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Prepend(value);
	}
	void insertAtValue()
	{
		int index;
		std::cout << "Enter the index of element: ";
		std::cin >> index;
		std::cout << "Enter the value of element number: ";
		try {
			T item{};
			std::cin >> item;
			sequence->InsertAt(index, item);
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void concatSequence()
	{
		int length;
		std::cout << "Input length of sequence which you want to concat:\n"; 
		std::cin >> length;
		T value{};
		std::cout << "Input elements of sequence which you want to concat:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
	}
};

template <typename T> struct ImmutableListSequence_func
{
private:
	ImmutableListSequence<T>* sequence = new ImmutableListSequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Immutable Linked List\n";
		std::cin >> length;
		std::cout << "Input elements of Immutable Linked List:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() <= 0)
			{
				std::cout << "Immutable Linked List is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
};

template <typename T> struct MutableArraySequence_func
{
private:
	MutableArraySequence<T>* sequence = new MutableArraySequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Mutable Dynamic Array\n";
		std::cin >> length;
		std::cout << "Input elements of Mutable Dynamic Array:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() <= 0)
			{
				std::cout << "Mutable Dynamic Array is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void appendValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Append(value);
	}
	void prependValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Prepend(value);
	}
	void insertAtValue()
	{
		int index;
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "Enter the index: ";
		std::cin >> index;
		std::cout << "\n";
		sequence->InsertAt(index, value);
	}
	void concatSequence()
	{
		int length;
		std::cout << "Input length of sequence which you want to concat:\n";
		std::cin >> length;
		T value{};
		std::cout << "Input elements of sequence which you want to concat:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
	}
};

template <typename T> struct ImmutableArraySequence_func
{
private:
	ImmutableListSequence<T>* sequence = new ImmutableListSequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Immutable Dynamic Array\n";
		std::cin >> length;
		std::cout << "Input elements of Immutable Dynamic Array:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() <= 0)
			{
				std::cout << "Immutable array is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i);
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
};


template <typename T> class MutableArraySequence_UI
{
private:
	void Choosing()
	{
		MutableArraySequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cout << "8: append value\n";
		std::cout << "9: prepend value\n";
		std::cout << "10: insert at value\n";
		std::cout << "11: concat sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 11)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			case 8:
				userSequence.appendValue();
				break;
			case 9:
				userSequence.prependValue();
				break;
			case 10:
				userSequence.insertAtValue();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 11)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};

template <typename T> class MutableListSequence_UI
{
private:
	void Choosing()
	{
		MutableListSequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cout << "8: append value\n";
		std::cout << "9: prepend value\n";
		std::cout << "10: insert at value\n";
		std::cout << "11: concat sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 11)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			case 8:
				userSequence.appendValue();
				break;
			case 9:
				userSequence.prependValue();
				break;
			case 10:
				userSequence.insertAtValue();
				break;
			case 11:
				userSequence.concatSequence();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 11)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};


template <typename T> class ImmutableArraySequence_UI
{
private:
	void Choosing()
	{
		ImmutableArraySequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 7)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 7)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};


template <typename T> class ImmutableListSequence_UI
{
private:
	void Choosing()
	{
		ImmutableListSequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 7)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 7)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};


int selectType1()
{
	int selectedType = 0;
	std::cout << "Choose type of elements in sequence:\n";
	std::cout << "int - enter 1\n";
	std::cout << "double - enter 2\n";
	std::cout << "char - enter 3\n";
	std::cin >> selectedType;
	while (selectedType < 1 || selectedType> 3)
	{
		std::cout << "The wrong number was entered. Try again\n";
		std::cin >> selectedType;
	}
	std::cout << "\n";
	return selectedType;
}
int selectType2()
{
	int selectedType = 0;
	std::cout << "Choose:\n";
	std::cout << "MutableSequence - enter 1\n";
	std::cout << "ImmutableSequence - enter 2\n";
	std::cin >> selectedType;
	while (selectedType < 1 || selectedType > 2)
	{
		std::cout << "The wrong number was entered. Try again\n";
		std::cin >> selectedType;
	}
	std::cout << "\n";
	return selectedType;
}
int selectType3()
{
	int selectedType = 0;
	std::cout << "Choose:\n";
	std::cout << "Array sequence - enter 1\n";
	std::cout << "List sequence - enter 2\n";
	std::cin >> selectedType;
	while (selectedType < 1 || selectedType > 2)
	{
		std::cout << "The wrong number was entered. Try again\n";
		std::cin >> selectedType;
	}
	std::cout << "\n";
	return selectedType;
}
void startUI()
{
	std::cout << "Let's start work with sequence\n";
	int selectedType1 = selectType1();
	int selectedType2 = selectType2();
	int selectedType3 = selectType3();
	if (selectedType1 == 1)
	{
		if (selectedType2 == 1)
		{
			if (selectedType3 == 1)
			{
				MutableArraySequence_UI<int> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				MutableListSequence_UI<int> sequence;
				sequence.start();
			}
		}
		if (selectedType2 == 2)
		{
			if (selectedType3 == 1)
			{
				ImmutableArraySequence_UI<int> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				ImmutableListSequence_UI<int> sequence;
				sequence.start();
			}
		}
	}
	if (selectedType1 == 2)
	{
		if (selectedType2 == 1)
		{
			if (selectedType3 == 1)
			{
				MutableArraySequence_UI<double> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				MutableListSequence_UI<double> sequence;
				sequence.start();
			}
		}
		if (selectedType2 == 2)
		{
			if (selectedType3 == 1)
			{
				ImmutableArraySequence_UI<double> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				ImmutableListSequence_UI<double> sequence;
				sequence.start();
			}
		}
	}
	if (selectedType1 == 3)
	{
		if (selectedType2 == 1)
		{
			if (selectedType3 == 1)
			{
				MutableArraySequence_UI<char> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				MutableListSequence_UI<char> sequence;
				sequence.start();
			}
		}
		if (selectedType2 == 2)
		{
			if (selectedType3 == 1)
			{
				ImmutableArraySequence_UI<char> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				ImmutableListSequence_UI<char> sequence;
				sequence.start();
			}
		}
	}
}
