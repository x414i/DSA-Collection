#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class HashTable 
{
private:
    int capacity;
    Node** table;

    //Division method
    int hashFunction(int key) 
    {
        return key % capacity;
    }
     int hashFunction2(int key) {
        int square = key * key;
        return (square / 100) % capacity;
    }

    int hashFunction3(int key) {
        float A = 0.6180339887;
        return int(capacity * ((key * A) - int(key * A)));
    }

    int hashFunction4(int key) {
        int sum = 0;
        while (key > 0) {
            sum += key % 10;
            key /= 10;
        }
        return sum % capacity;
    }

public:

    HashTable(int size) : capacity(size) 
    {
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) 
        {
            table[i] = nullptr;
        }
    }

    ~HashTable() 
    {
        for (int i = 0; i < capacity; i++) 
        {
            Node* current = table[i];
            while (current) 
            {
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] table;
    }

    void insert(int key) 
    {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

// ---------------------------
    bool search(int key) 
    {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current) 
        {
            if (current->data == key) 
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void update(int oldKey, int newKey) 
    {
        remove(oldKey); 
        insert(newKey); 
    }

    void remove(int key) 
    {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* previous = nullptr;

        while (current) 
        {
            if (current->data == key) 
            {
                if (previous) 
                    previous->next = current->next;
                
                else 
                    table[index] = current->next;
                
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void display() 
    {
        cout<<endl;
        for (int i = 0; i < capacity; i++) 
        {
            cout << "\tBucket " << i << ": ";
            Node* current = table[i];
            while (current) 
            {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

void PrintMsg()
{
    cout<<"\n\t____________________________\n\n";
    cout<<"\t[1] insert "<<"\n\t[2] update \n\t[3] Search \n\t[4] remove \n\t[5] Display All \n\t[0] Exit\n";
    cout<<"\n\t____________________________\n\n";
    cout<<"\t[-] Enter the option : ";
}

void ReadKey(HashTable h)
{
    int op;
do
{
        PrintMsg();
        cin>>op;
    switch (op)
    {
        case 1:
        int k;
        cout<<"\n\t[-] Enter Key : "; cin>>k;
        h.insert(k);
        cout<<"\n\t [Done] \n";
            break;

        case 2:
        int t,y;
        cout<<"Old key : ";cin>>y;
        cout<<"\n\t[-] Enter new Key : "; cin>>t;
        h.update(y,t);
        cout<<"\n\t [Done] \n";
            break;

        case 3:
        int s;
        cout<<"\n\t[-] Enter Key : "; cin>>s;
        cout<<"\t"<<h.search(s);
        cout<<"\n\t [Done] \n";
            break;

        case 4:
        int p;
        cout<<"\n\t[-] Enter Key : "; cin>>p;
        h.remove(p);
        cout<<"\n\t [Done] \n";
            break;

        case 5:
        
        h.display();
            break;
    case 0:
        return;

        default:
            break;
    }
    }
    while(op!=0);
}

int main() 
{
    HashTable hashTable(10);
    ReadKey(hashTable);
    return 0;
}