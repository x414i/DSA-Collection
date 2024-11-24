#include <iostream>

using namespace std;

class HashTable 
{
private:
    int* table;
    int capacity;
    int size;

    /// 1-Division method 
    int hashFunction(int key) 
    {
        return key % capacity;
    }

    //-----------------------

    int MidSquare(int key) 
    {
        int square = key * key;
        return (square / 100) % capacity;
    }

    //------------------------

    int Multiplication(int key) 
    {
        float A = 0.6180339887;
        return int(capacity * ((key * A) - int(key * A)));
    }

    //-----------------------

    int Folding(int key) 
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
        for (int i = 0; i < capacity; ++i) 
        {
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
            cout << "\n [$] Hash Table is full!\n\n" << endl;
            return;
        }
        int index = hashFunction(key);
        while (table[index] != -1) 
        {
            index = (index + 1) % capacity;
        }
        table[index] = key;
        size++;
    }

    bool search(int key) 
    {
        int index = hashFunction(key);
        int originalIndex = index;
            
        while (table[index] != -1) 
        {
            if (table[index] == key) 
            {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) 
            {
                break;
            }
        }
        return false;
    }

    void remove(int key) 
    {
        int index = hashFunction(key);
        int originalIndex = index;
            
        while (table[index] != -1) 
        {
            if (table[index] == key) 
            {
                table[index] = -1;
                size--;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) 
            {
                break;
            }
        }
        cout << "Key not found!" << endl;
    }

    void update(int oldKey, int newKey) 
    {
        remove(oldKey);
        insert(newKey);
    }

    void display() 
    {
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
    cout << "2. Update Key\n";
    cout << "3. Search Key\n";
    cout << "4. Remove Key\n";
    cout << "5. Display Hash Table\n";
    cout << "0. Exit\n";
}

void ReadKey(HashTable& h) 
{
    int op;
    do {
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
                int t, y;
                cout << "Old key : "; cin >> y;
                cout << "\n\t[-] Enter new Key : "; cin >> t;
                h.update(y, t);
                cout << "\n\t [Done] \n";
                break;
            
            case 3: 
                int s;
                cout << "\n\t[-] Enter Key : "; cin >> s;
                cout << "\t" << (h.search(s) ? "Found" : "Not Found") << endl;
                cout << "\n\t [Done] \n";
                break;
            
            case 4: 
                int p;
                cout << "\n\t[-] Enter Key : "; cin >> p;
                h.remove(p);
                cout << "\n\t [Done] \n";
                break;
            
            case 5: 
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