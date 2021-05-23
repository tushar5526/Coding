#include <iostream>

using namespace std;

class Node
{
public:
    Node *right;
    int value;
    Node()
    {
        right = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int size = 0;

    void push_front(int value)
    {
        ++size;
        Node *tmp = new Node();
        tmp->value = value;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
            return;
        }

        tmp->right = head;
        head = tmp;
    }

    void push_back(int value)
    {
        ++size;
        Node *tmp = new Node();
        tmp->value = value;
        if (tail == NULL)
        {
            head = tmp;
            tail = tmp;
            return;
        }
        tail->right = tmp;
        tail = tmp;
    }

    int search(int value)
    {
        Node *tmp = head;
        int i = 0;
        while (tmp != NULL)
        {
            // cout<<"at value "<<tmp->value<<endl;
            if (tmp->value == value)
            {
                return i;
            }
            tmp = tmp->right;
            ++i;
        }
        return -1;
    }

    void delNode(int value)
    {
        if (size == 0)
        {
            cout << "Underflow\n";
            return;
        }

        Node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->value == value)
            {
                cout << "deleting " << value << endl;
                --size;
                if (size == 0)
                {
                    head = NULL;
                    tail = NULL;
                    delete tmp;
                    return;
                }

                Node *t = tmp->right;
                if (t->right == NULL)
                    tail = tmp;
                tmp->right = t->right;
                tmp->value = t->value;
                delete t;
                return;
            }
            tmp = tmp->right;
        }
        cout << "Not found any node for the value " << value << endl;
    }

    void reverse(){
        Node *curr, *prev = NULL, *next = NULL;
    }
    void print()
    {
        if(size == 0){
            cout<<"empty list \n";
            return;
        }

        Node *tmp = head;
        cout << "head -> ";
        while (tmp != NULL)
        {
            cout << tmp->value << " -> ";
            tmp = tmp->right;
        }
        cout << "tail" << endl;
    }

};

int main()
{
    LinkedList l = LinkedList();
    l.push_front(15);
    l.print();
    l.push_front(0);
    l.print();
    l.push_front(20);
    l.print();
    l.push_back(58);
    l.print();
    l.push_back(100);
    l.print();
    l.delNode(20);
    l.delNode(0);
    l.delNode(58);
    l.delNode(15);
    l.delNode(100);
    l.delNode(100);
    l.push_front(100);
    l.push_front(151);
    l.push_front(121);
    l.push_back(1213);
    l.print();
    cout<<l.size<<endl;

    return 0;
}