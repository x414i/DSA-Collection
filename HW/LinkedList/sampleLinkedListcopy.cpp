#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class LinkedList 
{
private:
    Node* head;

    bool isEmpty() { return head == NULL; }

public:
    LinkedList() 
    {
        head = NULL;
    }

    void addBegin(int data) 
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void addAfter(int data) 
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (isEmpty()) 
        {
            addBegin(data);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() 
    {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void printReverse(Node* node) 
    {
        if (node == nullptr) return;
            printReverse(node->next);
        cout << node->data << " -> ";
    }

    void printReverse() 
    {
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        current = prev;
        while (current != NULL) 
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;

        current = prev;
        prev = NULL;
        next = NULL;
        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void deleteAtKey(int key) 
    {
        if (head == NULL) 
        {
            cout << "Linked list is empty!" << endl;
            return;
        }

        if (key == head->data) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;
        int i = curr->data;
        while (curr != NULL && i != key) 
        {
            prev = curr;
            curr = curr->next;
            i = curr->data;
        }
        if (curr == NULL) 
        {
            cout << "Key is out of bounds!" << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    void extractOddElements(LinkedList& oddList) 
    {
        Node* _curr = head;
        Node* _prev = NULL;

        while (_curr != NULL) 
        {
            if (_curr->data % 2 != 0) 
            {
                if (_prev == NULL) 
                    head = _curr->next;
                else 
                    _prev->next = _curr->next;
                
                Node* temp = _curr;
                _curr = _curr->next;

                temp->next = oddList.head;
                oddList.head = temp;
            }
            else 
            {
                _prev = _curr;
                _curr = _curr->next;
            }
        }
    }

    void sortList()
    {
        Node* _curr = head->next;
        Node* _prev = head;
        while (_curr != NULL) 
        {
            Node* _temp = head;
            while (_temp != _curr) 
            {
                if (_temp->data < _curr->data) 
                {
                    int temp = _curr->data;
                    _curr->data = _temp->data;
                    _temp->data = temp;
                }
                _temp = _temp->next;
            }
            _curr = _curr->next;
        }

    }
    
    void readKey()
    {
        int op = -1;
        while (op!=0)
        {
            cout<<"\n\t [1] Add after";
            cout<<"\n\t [2] Delete at key";
            cout<<"\n\t [3] Sort descending";
            cout<<"\n\t [4] Extract odd elements";
            cout<<"\n\t [5] Print reverse using nodes";
            cout<<"\n\t [6] Print reverse recursive";
            cout<<"\n\t [7] Print";
            cout<<"\n\t [0] Exit"<<endl;

            cout<<"\n\t [-] Enter op : "; cin>>op;
            switch (op)
            {
                case 1:
                {
                    int data;
                    cout<<"\n\t [-] Enter data : "; cin>>data;
                    addAfter(data);
                    break;
                }
                case 2:
                {
                    int key;
                    cout<<"\n\t [-] Enter key : "; cin>>key;
                    deleteAtKey(key);
                    break;
                }
                case 3:
                {
                    sortList();
                    break;
                }
                case 4:
                {
                    LinkedList oddList;
                    extractOddElements(oddList);
                    cout<<"\n\t [-] Odd elements : ";
                    oddList.print();
                    break;
                }

                case 5:
                {
                    cout<<"\n\t [-] Reverse : ";
                    printReverse();
                    break;
                }
                case 6:
                {
                    cout<<"\n\t [-] Reverse : ";
                    printReverse(head);
                    cout<<" NULL "<<endl;
                    break;
                }

                case 7:
                {
                    cout<<"\n\t [-] List : ";
                    print();
                    break;
                }
                case 0:
                    cout<<"Exiting..."<<endl;
                    break;
                default:
                    cout<<"\n\n\t\t  try agin :( \n"<<endl;
                    break;
            }
        }
        
    }
};

int main() 
{
    LinkedList list;
    list.readKey();
    return 0;
}