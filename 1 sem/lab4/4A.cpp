#include <iostream>
#include <fstream>
#define NULL 0;

using namespace std;

struct stack_element // элемент стека
{
	int value;
	stack_element* next;
};

class StackClass
{
private:
	stack_element* head = NULL; 
public:
	void push(int value)
	{
		stack_element* element = new stack_element(); 
		element->next = head;
		element->value = value;
		head = element;
	}

	int pop() 
	{
		int temp = head->value;
		head = head->next;
		return temp; 
	}
};

int main()
{ 
	StackClass stack;
	int temp, n;
	char a;

	ifstream fin("stack.in");
	ofstream fout("stack.out");

	fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> a;
		if (a == '+')
		{
			fin >> temp;
			stack.push(temp);
		}
		else
			fout << stack.pop() << '\n';
	}

	fin.close();
	fout.close();

	return 0;
}