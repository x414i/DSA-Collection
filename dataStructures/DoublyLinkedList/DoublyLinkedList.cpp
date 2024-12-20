#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList 
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() 
    {
        head = NULL;
        tail = NULL;
    }

    void append(int data) 
    {
        Node* newNode = new Node(data);
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(int data) 
    {
        Node* newNode = new Node(data);
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(int data) 
    {
        Node* current = head;
        while (current != NULL) 
        {
            if (current->data == data) 
            {
                if (current->prev != NULL) 
                {
                    current->prev->next = current->next;
                } 
                else 
                {
                    head = current->next;
                }
                if (current->next != NULL) 
                {
                    current->next->prev = current->prev;
                }
                else 
                {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void displayForward() 
    {
        Node* current = head;
        while (current != NULL) 
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout<<" NULL" << endl;
    }

    void displayBackward() 
    {
        Node* current = tail;
        while (current != NULL) 
        {
            cout << current->data << " -> ";
            current = current->prev;
        }
        cout <<" NULL "<< endl;
    }
};

void display(DoublyLinkedList& dll) 
{
    int op = 0;
    do 
    {
        cout << "\n[-] Choose an operation: \n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> op;
        switch (op) 
        {
            case 1: 
            {
                int addOp;
                cout << "\n[-] Choose Add Operation: \n";
                cout << "1. Add First\n";
                cout << "2. Add Last\n";
                cout << "Enter your choice: ";
                cin >> addOp;

                int key;
                switch (addOp) 
                {
                    case 1:
                        cout << "\n[Add First] Enter key: ";
                        cin >> key;
                        dll.prepend(key);
                        break;
                    case 2:
                        cout << "\n[Add Last] Enter key: ";
                        cin >> key;
                        dll.append(key);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            }
            case 2: 
            {
                int key;
                cout << "\n[Delete] Enter key: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            }
            case 3:
                dll.displayForward();
                break;
            case 4:
                dll.displayBackward();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } 
    while (op != 0);
}

int main() 
{
    DoublyLinkedList dll;
    display(dll);
    return 0;
}