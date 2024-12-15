#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

bool isEmpty(node* h) { return h == NULL; }

void addBigen(int data, node*& h) 
{
    node* _curr_new = new node; 
    _curr_new->data = data;
    _curr_new->next = h;
    h = _curr_new;
}

void addAfter(int data, node* h) 
{
    node* _curr_new = new node; 
    _curr_new->data = data;
    _curr_new->next = NULL;

    if (isEmpty(h)) 
    {
        addBigen(data, h);
        return;
    }

    node* _temp = h;
    while (_temp->next != NULL) 
    {
        _temp = _temp->next; 
    }
    _temp->next = _curr_new;
}

void print(node* h) 
{
    node* _temp = h;
    while (_temp != NULL) 
    {
        cout << _temp->data << " -> ";
        _temp = _temp->next;
    }
    cout << "NULL" << endl; 
}

void display(node* h) 
{ 
    int op = 0;
    do 
    {
        cout << "\n[-] Enter op : ";
        cin >> op;
        switch (op) 
        {
            case 1: 
            {
                int key;
                cout << "\n[1] Enter key : ";
                cin >> key;
                addBigen(key, h);
                break;
            }
            case 2: 
            {
                int v;
                cout << "\n[2] Enter key : ";
                cin >> v;
                addAfter(v, h);
                break;
            }
            case 3:
                print(h);
                break;
            default:
                break;
        }
    } 
    while (op != -1);
}

int main() {
    node* head = NULL;
    display(head);
    return 0;
}