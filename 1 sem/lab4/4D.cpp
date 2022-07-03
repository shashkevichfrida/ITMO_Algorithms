#include <iostream>
#include <fstream>
#include <string>



using namespace std;

struct stack_element // элемент стека
{
    int value;
    stack_element* next;
};

class Stack
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
        stack_element* depart = head;
        head = head->next;
        delete depart;
        return temp;
    }
};


int main()
{
    Stack stack;

    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    string str;
    getline(fin, str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
           stack.push((int)str[i] - '0');
        }
        else if (str[i] == '+')
        {
            stack.push(stack.pop() + stack.pop());
        }
        else if (str[i] == '-')
        {
            int a = stack.pop();
            int b = stack.pop();
            stack.push(b -a);
        }
        else if (str[i] == '*')
        {
            stack.push(stack.pop() * stack.pop());
        }
        
    }
    fout << stack.pop() << endl;
    fin.close();
    fout.close();

    return 0;
}