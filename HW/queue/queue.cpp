#include <iostream>

using namespace std;
class MyQueue 
{
private:
    int capacity;
    int* item;
    int front, rear;
public:
    MyQueue(int _capacity)
    {
        front = rear = -1;
        capacity = _capacity;
        item = new int[capacity];
    }

    bool IsFull()  { return((rear == capacity - 1 && front == 0) || front == rear + 1);}

    bool IsEmpty() {return(front == -1 && rear == -1);}

    void Enqueue(int element)
    {
        if(IsFull())
        {
            cout<<"\n\t\t [-] is full "<<endl;
            return;
        }
        else if(IsEmpty())  
            front = rear = 0;
        else if(rear == capacity - 1) 
            rear = 0;
        else 
            rear++;

        item[rear] = element;
    }
    
    void Dequeue()
    {
        if(IsEmpty())
            cout<<"\t [-]  is empty "<<endl;
        else if(front == rear)  
            front = rear = -1;
        else if(front == capacity - 1 && rear >= 0) 
            front = 0;
        else 
            front++;  
    }
    
    int GetFront(){return item[front]; }


    void display()
    {
        MyQueue temp(capacity);
        cout<<"\n { ";
        while(!IsEmpty())
        {
            cout<<"\t"<<GetFront()<<"  ";
            temp.Enqueue(GetFront());
            Dequeue();
        }
        cout<<" } \n";
        while(!temp.IsEmpty())
        {
            Enqueue(temp.GetFront());
            temp.Dequeue();
        }
    }

//  [A] Find Max element in the queue
    int FindMax() 
    {
        if (IsEmpty()) 
        {
            cout << "\n\t\t[-] Queue is empty" << endl;
            return -1;
        }

        int max = GetFront();
        MyQueue temp(capacity);
        
        // temp.Enqueue(GetFront());
        //     Dequeue();

        while (!IsEmpty()) 
        {
            if (GetFront() > max) 
                max = GetFront();
            temp.Enqueue(GetFront());
            Dequeue();
        }

        while (!temp.IsEmpty()) 
        {
            Enqueue(temp.GetFront());
            temp.Dequeue();
        }
        return max;
    }

//  [B] Sort queue 
    void SortQueueUsingArray() 
    {
        if (IsEmpty()) 
        {
            cout << "\n\t\t [-] Queue is empty" << endl;
            return;
        }

        int n = (rear >= front) ? (rear - front + 1) : (capacity - front + rear + 1);
        int* arr = new int[n];
        int idx = 0;

//      Store Data in Array 
        while (!IsEmpty()) 
        {
            arr[idx++] = GetFront();
            Dequeue();
        }
//          using Bubble Sort 
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            }
        }         
        for (int i = 0; i < n; i++) 
        {
            Enqueue(arr[i]);
        }

        delete[] arr;
    }

//  [C] insert by position
    void InsertAt(int element, int position) 
    {
        if (position < 0 || position > capacity) 
        {
            cout << "\n\t\t[-] Invalid position" << endl;
            return;
        }
        
        if(IsFull())
        {
            cout<<"\n\t\t [-] is full "<<endl;
            return;
        }
        
        MyQueue temp(capacity);

        for (int i = 0; i < position && !IsEmpty(); i++) 
        {
            temp.Enqueue(GetFront());
            Dequeue();
        }
        temp.Enqueue(element);

        while (!IsEmpty()) 
        {
            temp.Enqueue(GetFront());
            Dequeue();
        }
        while (!temp.IsEmpty()) 
        {
            Enqueue(temp.GetFront());
            temp.Dequeue();
        }
    }

//  [D] Print Queue
    void PrintQueue()
    {
        cout<<endl;
        cout<<"\n { ";
        while(!IsEmpty())
        {
            cout<<"\t"<<GetFront()<<"  ";
            Dequeue();
        }
        cout<<"  } \n";
    }
    
    void menu() 
    {
        cout << "\n\t [1] Enqueue";
        cout << "\n\t [2] Dequeue";
        cout << "\n\t [3] Get front";
        cout << "\n\t [4] Print Queue";
        cout << "\n\t [5] Find Max";
        cout << "\n\t [6] Sort Queue";
        cout << "\n\t [7] Insert at position";
        cout << "\n\t [0] Exit" << endl;
    }

};
int main()
{
    int size;
    cout<<"\t [-] Enter queue size : ";
    cin>>size;

    MyQueue qu1(size);

    int element,position;
    int op;
    do
    {
        qu1.menu();
        cout<<"\t [-] Enter your option : ";
        cin>>op;
        switch(op)
        {
            case 1: cout<<"\t [-] Enter your element : ";
                    cin>>element;
                    qu1.Enqueue(element);
                    break;
            case 2: qu1.Dequeue();
                    break;
            case 3: if(qu1.IsEmpty())
                        cout<<"\t [-] Queue is empty !"<<endl;
                    else {
                    cout<<"\t [-] Front element is : ";
                    cout<<qu1.GetFront()<<endl;
                    }
                    break;
            case 4: qu1.PrintQueue();
                    break;
            case 5:
                cout << "\t [-] Max element: " << qu1.FindMax() << endl;
                break;
            case 6:
                qu1.SortQueueUsingArray();
                break;
            case 7:
                cout << "\t [-] Enter element to insert: ";
                cin >> element;
                cout << "\t [-] Enter position: ";
                cin >> position;
                qu1.InsertAt(element, position);
                break;
            case 0: break;
            default : cout<<"\t [-] Exiting .... "<<endl;
        }
    } 
    while(op != 0);
    return 0;
}

