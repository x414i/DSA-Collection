#include <iostream>
// Hash Fun : Division 
// Solving collision : open addressing : -> quadratic probing

using namespace std;

class HashTable 
{
private:
    int* table;
    int capacity;
    int size;

    int hashFunction(int key) 
    {
        return key % capacity;
    }

    int hashFunction2(int key) 
    {
        int square = key * key;
        return (square / 100) % capacity;
    }

    int hashFunction3(int key) 
    {
        float A = 0.6180339887;
        return int(capacity * ((key * A) - int(key * A)));
    }

    int hashFunction4(int key) 
    {
        int sum = 0;
        while (key > 0) {
            sum += key % 10;
            key /= 10;
        }
        return sum % capacity;
    }

public:
    HashTable(int size) : capacity(size), size(0) 
    {
        table = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = -1;
        }
    }

    ~HashTable() 
    {
        delete[] table;
    }

    void insert(int key) 
    {
        if (size == capacity) 
        {
            cout << "Hash Table is full!" << endl;
            return;
        }
        int index = hashFunction(key);
        for (int i = 0; i < capacity; i++)
        {
            int probeIndex = (index + i * i) % capacity;
            if (table[probeIndex] == -1) 
            {
                table[probeIndex] = key;
                size++;
                return;
            }
        }
    }

    bool search(int key) 
    {
        int index = hashFunction(key);
        for (int i = 0; i < capacity; i++) 
        {
            int probeIndex = (index + i * i) % capacity;
            if (table[probeIndex] == -1) 
            {
                return false;
            }
            if (table[probeIndex] == key) 
            {
                return true;
            }
        }
        return false;
    }

    void remove(int key) 
    {
        int index = hashFunction(key);
        for (int i = 0; i < capacity; i++) 
        {
            int probeIndex = (index + i * i) % capacity;
            if (table[probeIndex] == -1) {
                cout << "Key not found!" << endl;
                return;
            }
            if (table[probeIndex] == key) {
                table[probeIndex] = -1;
                size--;
                return;
            }
        }
        cout << "Key not found!" << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < capacity; i++) 
        {
            if (table[i] != -1) 
            {
                cout << "Index " << i << ": " << table[i] << endl;
            } 
            else 
            {
                cout << "Index " << i << ": EMPTY" << endl;
            }
        }
    }
};

void PrintMsg() 
{
    cout << "\nOptions:\n";
    cout << "1. Insert Key\n";
    cout << "2. Search Key\n";
    cout << "3. Remove Key\n";
    cout << "4. Display Hash Table\n";
    cout << "0. Exit\n";
}

void ReadKey(HashTable& h) 
{
    int op;
    do 
    {
        PrintMsg();
        cin >> op;
        switch (op) 
        {
            case 1: 
                int k;
                cout << "\n\t[-] Enter Key : "; 
                cin >> k;
                h.insert(k);
                cout << "\n\t [Done] \n";
                break;
            
            case 2: 
                int s;
                cout << "\n\t[-] Enter Key : "; cin >> s;
                cout << "\t" << (h.search(s) ? "Found" : "Not Found") << endl;
                cout << "\n\t [Done] \n";
                break;
            
            case 3: 
                int p;
                cout << "\n\t[-] Enter Key : "; cin >> p;
                h.remove(p);
                cout << "\n\t [Done] \n";
                break;
            
            case 4: 
                h.display();
                break;
            case 0:
                return;
            default:
                break;
        }
    } while (op != 0);
}

int main() {
    HashTable hashTable(10);
    ReadKey(hashTable);
    return 0;
}