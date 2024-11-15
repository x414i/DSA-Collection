#include <iostream>
using namespace std;

template <class T>
struct Node
{
public:
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
};

template <class T>
class LinkedStack
{
private:
    Node<T> *top;

public:
    LinkedStack() : top(nullptr) {}

    void readKey()
    {
        int op = 10;
        while (op != 0)
        {
            cin >> op;
            cout << "\n\t 1). Add value \n\t 2). Delete top \n\t  3). Get value at Top \n\t 4). Display stack  \n\t0). Exit\n\n";
            switch (op)
            {
            case 1:
            {
                T v;
                cout << "Enter value: ";
                cin >> v;
                push(v);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
                // case 4: cout << "\n" << getTopIndex() << endl; break;
            case 5:
                cout << "\n"
                     << getTopValue() << endl;
                break;
            default:
                break;
            }
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        cout << "Value pushed: " << value << endl;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
            cout << "Top value popped." << endl;
        }
        else
        {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    T getTopValue()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            cout << "Stack is empty." << endl;
            return T();
        }
    }

    void display()
    {
        Node<T> *temp = top;
        cout << endl
             << "_\n";
        while (temp != nullptr)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
        cout << "_\n"
             << endl;
    }
};

int main()
{
    LinkedStack<int> s;
    s.readKey();
    return 0;
}