#include <iostream>
using namespace std;
const int MAX_SIZE = 5;
class Stack
{
    int arr[MAX_SIZE];
    int top = -1;

public:
    void readKey()
    {
        int op = 10;

        while (op != 0)
        {
            cout << "\n\t 1). add value \n\t 2). delete top \n\t 3). dislpay stack \n\t 4). get Top \n\t 5). get value Top  \n\t 0). Exit\n\n";
            cin >> op;
            switch (op)
            {
            case 1:
                int v;
                cout << "Enter value : ";
                cin >> v;
                push(v);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "\n"
                     << getTop() << endl;
                break;
            case 5:
                cout << "\n"
                     << getTopValue() << endl;
                break;
            default:
                break;
            }
        }
    }

    bool isFull()
    {
        return top == (MAX_SIZE - 1);
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (!isFull())
            arr[++top] = value;
        else
            cout << "Satck is Full :( \n";
    }

    void pop()
    {
        if (!isEmpty())
            --top;
        else
            cout << "Satck is Empty :( \n";
    }

    int getTop() { return top; }

    int getTopValue() { return arr[top]; }

    void display()
    {
        int temp = top;
        cout << endl
             << "_\n";
        while (temp >= 0)

            cout << arr[temp--] << "\n";
        cout << "_\n"
             << endl;
    }
};

int main()
{
    Stack s;
    s.readKey();
    return 0;
}