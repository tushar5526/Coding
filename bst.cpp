//Practicing BST

#include<iostream>

using namespace std;

struct node
{
    int data;
    int pos;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node* tmp = new node();
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

class Node
{
    public:
    node* root;

    //add Node
    void addNode(int data)
    {
        node* current = newNode(data);
        node* parent = NULL;

        if(root == NULL)
        {
            current->pos = 1;
            root = current;
            return;
        }
        else
        {
            parent = root;
            while(1)
            {
                if(data < parent->data)
                {
                    if(parent->left == NULL)
                    {
                        current->pos = parent->pos * 2;
                        parent->left = current;
                        cout<<"added "<<current->data<<" before "<<parent->data<<" pos "<<current->pos<<endl;
                        break;
                    }
                    else
                    {
                        parent = parent->left;
                    }
                }
                else
                {
                    if(parent->right == NULL)
                    {
                        current->pos = parent->pos * 2 + 1;
                        parent->right = current;
                        cout<<"added "<<current->data<<" before "<<parent->data<<" pos "<<current->pos<<endl;
                        break;
                    }
                    else
                    {
                        parent = parent->right;
                    }
                }            
            }
        }
    }



    //del node
    void delNode(int data)
    {
        
    }



};

int main()
{
    Node* tree = new Node();
    
    tree->addNode(5);
    tree->addNode(10);
    tree->addNode(1);
    tree->addNode(4);
    tree->addNode(9);
    tree->addNode(6);
    tree->addNode(11);

    return 0;
}