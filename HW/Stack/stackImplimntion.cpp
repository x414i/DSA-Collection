#include <iostream>
using namespace std;

class Stack 
{
private:
    int top;
    int maxSize;
    int* stackArray;

public:

    Stack(int size) 
    {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    bool isFull()  {return top == maxSize - 1;}

    bool isEmpty() {return top == -1;}

    void push(int value)
    {
        if (isFull()) 
        {
            cout << "\t [-] Stack overflow" << endl;
            return;
        }
        stackArray[++top] = value;
    }

//   return value of top
    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "\n\t [-] Stack is empty" << endl;
            return -1;
        }
        return stackArray[top];
    }

    int getTop() 
    {
        return top;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "\n\t [-] Stack underflow" << endl;
            return;
        }
        top--;
    }

//   display data stack only and do not remove elements
    void display() 
    {
        
        if (isEmpty()) 
        {
            cout << "\n\t [0] Stack is empty" << endl;
            return;
        }
        int temp = top;
        cout << "\n\t [-] Display Stack And Do not Reomving Elements \n\n";
        //for (int i = 0; i <= top; i++) 
            while(temp >= 0)
                cout <<"\t| "<< stackArray[temp--] << " |\n";
            //cout <<"\t| "<< stackArray[i] << " |\n";
        cout << endl;
    }

//  [A] insertion sort
    void sortStack(int s) 
    {
    Stack tempStack(s);

    while (!isEmpty()) 
    {
        // 8 5 7 1 3 2 4 6
        int key = peek(); 
        pop();               
        while (!tempStack.isEmpty() && tempStack.peek() > key) 
        {
            push(tempStack.peek()); 
            tempStack.pop();        
        }
        tempStack.push(key);
    }
    while (!tempStack.isEmpty()) 
    {
        push(tempStack.peek()); 
        tempStack.pop();       
    }
}

//  [B] Binary search 
    bool binarySearch(int value, int s) 
    {
        if (isEmpty()) 
        {
            cout << "\n [-] Stack is empty" << endl;
            return false;
        }
        //this->sortStack(s);
        Stack tempStack(s);
        int* tempArray = new int[getTop() + 1], i = 0;
        while (!isEmpty()) 
        {
            tempArray[i] = peek();
            tempStack.push(peek());
            pop();
            i++;
        }
        
        int left = 0;
        int right = i - 1;
        bool found = false;

        while (left <= right) 
        {
            int mid = (left + right) / 2;
            if (tempArray[mid] == value) 
            {
                found = true;
                break;
            }
            else if (tempArray[mid] < value)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        while (!tempStack.isEmpty()) 
        {
            push(tempStack.peek());
            tempStack.pop();
        }
        delete[] tempArray;
        return found;
    }

//  [C] Print data stack and remove elements
    void print() 
    {
        if (isEmpty()) 
        {
            cout << "[0] Stack is empty" << endl;
            return;
        }
        cout << "\n\t [-] Display Stack And Reomving Elements \n\n";
        while(!isEmpty()) 
        {
            cout <<"\t| "<< stackArray[getTop()] << " |\n";
            pop();
        }
        cout << endl;
    }

    void menu()
    {
        cout << "\n\t [1] push";
        cout << "\n\t [2] pop";
        cout << "\n\t [3] peek";
        cout << "\n\t [4] Print stack";
        cout << "\n\t [5] Sort stack" ;
        cout << "\n\t [6] Binary search";
        cout << "\n\t [0] Exit" << endl;
    }

    void readKey(int s)
    {
        int exp;
        do
        {
            menu();
        cout << "\n\t [-] Enter exp: ";
        cin >> exp;
            switch (exp)
            {
            case 1:
            {
                int value;
                cout << "\n\t [-] Enter value: ";
                cin >> value;
                push(value);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                cout << "\n\t [-] Top element: " << peek() << endl;
                break;
            }
            case 4:
            {
                cout << "\n\t [-] Stack: ";
                print();
              //  display();
                break;
            }
            case 5:
            {
                sortStack(s);
                cout << "\n\t [-] Sorted stack: ";
                display();
                break;
            }
            case 6:
            {
                int value;
                cout << "\n\t [-] Enter value to search: ";
                cin >> value;
                if (!binarySearch(value,s))
                    cout << "\n\t [0] Value not found" << endl;
                else
                    cout << "\n\t [-] Value found " <<value <<endl;
                break;
            }
            case 0:
            {
                cout << "Exit" << endl;
                break;
            }
            default:
                break;
            }
        } 
        while (exp != 0);
    }

};

int main() 
{
    int size; cout<<"\t [-] Enter Size Stack : "; cin>>size;

    Stack stack(size);
    stack.readKey(size);

    return 0;
}