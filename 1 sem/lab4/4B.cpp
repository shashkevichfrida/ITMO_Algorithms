#include <fstream>
using namespace std;



struct Element
{
	int d;
	Element* prev;
	Element* next;
};

class Queue
{
private:
	Element* head = NULL;
	Element* tail = NULL;
public:

	void push(int a)
	{
		Element* element = new Element();
		if (head != NULL)
			head->next = element;
		else
			tail = element;
		element->d = a;
		element->prev = head;
		element->next = NULL;
		head = element;
	}
	int pop()
	{
		int result = tail->d;
		Element* depart = tail;
		tail = tail->next;
		if (tail == NULL)
		{
			head = NULL;
		}
		delete depart;
		return result;
	}
};

int main()
{
	Queue q;
	ifstream fin("queue.in");
	ofstream fout("queue.out");
	int n, temp;
	fin >> n;
	char command;
	for (int i = 0; i < n; i++)
	{
		fin >> command;
		if (command == '+')
		{
			
			fin >> temp;
			q.push(temp);
		}
		else
			fout << q.pop() << endl;
	}
	return 0;
}