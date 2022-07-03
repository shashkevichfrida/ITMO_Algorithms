#include <fstream>


using namespace std;

struct element
{
    int value; 
    element* parent;
    element* left; 
    element* right; 
};

class search_tree
{
private:
    element* root = nullptr; 
public:

    element* search(int x)
    {
        element* current = root;
        while (current != nullptr && x != current->value) 
        {
            if (x < current->value)
                current = current->left;  
            else
                current = current->right;
        }
        return current;
    }

    void add(int x) 
    {
        if (check_el(x)) 
            return;
        element* new_el = new element; 
        new_el->value = x;
        new_el->parent = nullptr;        
        new_el->left = nullptr;
        new_el->right = nullptr;
        element* current = root; 
        while (current != nullptr) 
        {
            new_el->parent = current;
            if (new_el->value < current->value)
                current = current->left;
            else
                current = current->right;
        }
        if (new_el->parent == nullptr)
            root = new_el;
        else
        {
            if (new_el->value < new_el->parent->value)
                new_el->parent->left = new_el;
            else
                new_el->parent->right = new_el;
        }
    }

    void del(int x) 
    {
        element* el = search(x); 
        if (el == nullptr) 
        {
            return;
        }
        element* previous; //предыдущий элемент
        element* el2; /// вспомогательный элемент
        if (el->left == nullptr || el->right == nullptr)
            previous = el;
        else
            previous = next(x);
        if (previous->left != nullptr) 
            el2 = previous->left;
        else
            el2 = previous->right;
        if (el2 != nullptr)
            el2->parent = previous->parent;
        if (previous->parent == nullptr) 
            root = el2;
        else
        {
            if (previous == previous->parent->left)
                previous->parent->left = el2;
            else
                previous->parent->right = el2;
        }
        if (previous != el) 
            el->value = previous->value; 
        delete previous;
    }

    bool check_el(int x)
    {
        return search(x) != nullptr;
    }

    element* next(int x) 
    {
        element* current = root;   
        element* successor = nullptr; 
        while (current != nullptr)
        {
            if (current->value > x) 
            {
                successor = current;
                current = current->left;
            }
            else
                current = current->right;
        }
        return successor; 
    }

    element* Previous(int x) 
    {
        element* current = root; 
        element* previous = nullptr; 
        while (current != nullptr)
        {
            if (current->value < x) 
            {
                previous = current;
                current = current->right;
            }
            else
                current = current->left;
        }
        return previous;
    }
};

int main()
{
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    search_tree tree;
    string cmd;
    int key;
    while (fin >> cmd >> key)
    {
        if (cmd == "insert")
            tree.add(key);
        if (cmd == "delete")
            tree.del(key);
        if (cmd == "exists")
        {
            if (tree.search(key))
                fout << "true" << endl;
            else
                fout << "false" << endl;
        }
        if (cmd == "next")
        {
            element* res = tree.next(key);
            if (res == nullptr)
                fout << "none" << endl;
            else
                fout << res->value << "\n";
        }
        if (cmd == "prev")
        {
            element* res = tree.Previous(key);
            if (res == nullptr)
                fout << "none" << endl;
            else
                fout << res->value << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}