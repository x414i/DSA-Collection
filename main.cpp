#include <iostream>
using namespace std;
class  queueCircler
{
private:
int Queue[4];
int front=-1,rear=-1;

public:
    int MAX_size =4;
bool isfull()
{
return ((rear == MAX_size-1 && front==0) || front == rear+1);
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
    if(rear == SIZE_MAX-1)
    rear=0;
    else
    if(isempty())
    front=0;
    else
    rear++;
    Queue[rear]=data;

}


void dequeue()
{
    if(isempty())

    cout<<"Queue Is Empty !!";
    
    else
    {
        if(rear==front)
        front=rear=-1;
        else 
        if(front == SIZE_MAX-1)
        front=0;
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
    queueCircler q ;
    q.readKey();

return 0;
}