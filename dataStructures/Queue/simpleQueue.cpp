#include <iostream>
using namespace std;

int const MAX_size=10;

class simpleQueue
{
private:
    int *Queue,size;
    int rear,front;

public:
    simpleQueue(int _size)
    {
        rear = front =-1;
        this->size = _size;
        Queue= new int[size];
    }


bool isfull()
{
return rear == MAX_size-1;
}
bool isempty()
{
    return (front ==-1 && rear ==-1);
}
void enqueue(int data)
{
    if(isfull())
    cout<<"Queue Is Full ";
    else
    if(isempty())
    front=0;
    Queue[++rear]=data;

}


void dequeue()
{
    if(isempty()) cout<<"Queue Is Empty !!";

    else
    {
        if(rear==front)
        front=rear=-1;
        else
        front++;
    }
}

int getFront()
{
return Queue[front];
}

void display()
{
    while(!isempty())
    {
        cout<<endl<<getFront()<<"\t";
        dequeue();
    }
}
void readKey()
    {
        int op = 10;

        while (op != 0)
        {
            cout << "\n\t 1). add value \n\t 2). delete Front \n\t 3). dislpay Queue \n\t 4). get Front   \n\t 0). Exit\n\n";
            cin >> op;
            switch (op)
            {
            case 1:
                int v;
                cout << "Enter value : ";
                cin >> v;
                enqueue(v);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "\n"
                    << getFront() << endl;
                break;
            default:
                break;
            }
        }
    }
};



int main()
{
    simpleQueue simpaleQu(5);
    simpaleQu.readKey();
    return 0 ;
}