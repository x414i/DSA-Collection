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

void addAtPos(int data , node* h,int postion)
{
    node* newNode = new node;
    newNode->data=data; newNode->next = NULL;
    if(isEmpty(h) || postion==0)
    {
        addBigen(data,h);
        return;
    }
    node*_curr= h;
    node*_prev = NULL;
    int i=0;
    while(_curr != NULL && i!=postion && _curr->next !=NULL)
    {
        _prev=_curr;
        _curr=_curr->next;
        i++;
    }
    _prev->next = newNode;
    newNode->next = _curr;
}

void addAtKey(int data , node* h,int key)
{
    node* newNode = new node;
    newNode->data=data; newNode->next = NULL;
    if(isEmpty(h) || key==h->data)
    {
        addBigen(data,h);
        return;
    }
    node*_curr= h;
    node*_prev = NULL;
    int i=_curr->data;
    while(_curr != NULL && i!=key && _curr->next !=NULL)
    {
        _prev=_curr;
        _curr=_curr->next;
        i=_curr->data;
    }
    _prev->next = newNode;
    newNode->next = _curr;
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
                print(h);
                break;
            }
            case 2: 
            {
                int v;
                cout << "\n[2] Enter key : ";
                cin >> v;
                addAfter(v, h);
                print(h);
                break;
            }
            case 3:
            {
                int d,pos;
                cout<<"[03] data  ";
                cin>>d;
                cout<<"[03] position :  ";
                cin>>pos;
                addAtPos(d,h,pos);
                print(h);
                break;
            }
            case 4:
            {
                int d,key;
                cout<<"[03] data  ";
                cin>>d;
                cout<<"[03] key :  ";
                cin>>key;
                addAtPos(d,h,key);
                print(h);
                break;
            }
            case 5:
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