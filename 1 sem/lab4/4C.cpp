#include <iostream>
#include <fstream>



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
        head = head->next;
        return temp;
    }

    char getPop()
    {
        return head->value;
    }
    bool Empty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
};





string answ(string str1)
{
    Stack stack;

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == '(' || str1[i] == '[')
        {
            stack.push(str1[i]);
        }
        else
        {
            if (stack.Empty() == false && ((stack.getPop() == '[' && str1[i] == ']') || (stack.getPop() == '(' && str1[i] == ')')))
            {
                stack.pop();
            }
            else
            {
                return "NO";
            }
        }
    }
    if (stack.Empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    Stack stack;
    string str;


    ifstream fin("brackets.in");
    ofstream fout("brackets.out");

    while (fin >> str)
    {
        fout << answ(str) << endl;
    }


    fin.close();
    fout.close();

    return 0;
}