#include <iostream>
#include <algorithm>
using namespace std;

class Queue
{
	string* data;
	int* priorities;
	unsigned int maxCount;
	unsigned int realCount = 0;

public:
	Queue(unsigned int maxCount)
	{
		this->maxCount = maxCount;
		data = new string[maxCount];
		priorities = new int[maxCount];
	}

	~Queue()
	{
		if (data != nullptr) delete[] data;
		if (priorities != nullptr) delete[] priorities;
	}

	void Clear()
	{
		realCount = 0;
	}

	bool IsEmpty() const
	{
		return realCount == 0;
	}

	bool IsFull() const
	{
		return realCount == maxCount;
	}

	inline int GetCount() const
	{
		return realCount;
	}

	void Enqueue(string value, int priority)
	{
		if (!IsFull())
		{
			int indexToInsert = realCount;
			for (int i = 0; i < realCount; i++)
			{
				if (priority > priorities[i])
				{
					indexToInsert = i;
					break;
				}
			}
			for (int i = realCount; i > indexToInsert; i--)
			{
				data[i] = data[i - 1];
				priorities[i] = priorities[i - 1];
			}
			data[indexToInsert] = value;
			priorities[indexToInsert] = priority;
			realCount++;
		}
		else
		{
			throw "Queue is full!";
		}
	}

	string Dequeue()
	{
		if (!IsEmpty())
		{
			string result = data[0];
			for (int i = 0; i < realCount - 1; i++)
			{
				data[i] = data[i + 1];
				priorities[i] = priorities[i + 1];
			}
			realCount--;
			return result;
		}
		else
		{
			throw "Queue is empty!";
		}
	}

	void Print() const
	{
		cout << "---------------------------------------\n";
		for (int i = 0; i < realCount; i++)
		{
			cout << i + 1 << ") " << data[i] << "\n";
		}
		cout << "\n---------------------------------------\n";
	}
};

int main()
{
	Queue q(25);

	q.Enqueue("teacher, Alexander", 199);
	q.Enqueue("branch manager, Diane", 4);
	q.Enqueue("training manager, Ekaterina", 2);
	q.Enqueue("department chair, Christina", 3);
	q.Enqueue("CEO, Dmitry", 5);
	q.Enqueue("God, Pavlo ", 200);

	q.Print();

	q.Dequeue();

	q.Print();

	q.Dequeue();

	q.Print();

	q.Dequeue();

	q.Print();

	q.Dequeue();

	q.Print();
}

