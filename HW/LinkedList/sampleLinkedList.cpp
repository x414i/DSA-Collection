#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

bool isEmpty(node* h) { return h == NULL; }

// Add First , Last , Position , At Key , by Order 
void addBigen(int data, node*& h) 
{
    node* _curr_new = new node; 
    _curr_new->data = data;
    _curr_new->next = h;
    h = _curr_new;
}

void addAfter(int data, node* h) 
{
    node* _curr_new = new node; 
    _curr_new->data = data;
    _curr_new->next = NULL;

    if (isEmpty(h)) 
    {
        addBigen(data, h);
        return;
    }

    node* _temp = h;
    while (_temp->next != NULL) 
    {
        _temp = _temp->next; 
    }
    _temp->next = _curr_new;

}

void addAtPos(int data , node* h,int postion)
{
    node* newNode = new node;
    newNode->data=data; newNode->next = NULL;
    if(isEmpty(h) || postion==0)
    {
        addBigen(data,h);
        return;
    }
    node*_curr= h;
    node*_prev = NULL;
    int i=0;
    while(_curr != NULL && i!=postion && _curr->next !=NULL)
    {
        _prev=_curr;
        _curr=_curr->next;
        i++;
    }
    _prev->next = newNode;
    newNode->next = _curr;
}

void addAtKey( node* h,int key)
{
    node* newNode = new node;
    newNode->data=key; newNode->next = NULL;
    if(isEmpty(h) || key==h->data)
    {
        newNode->next = h;
        h = newNode;
        return;
    }
    node*_curr= h;
    node*_prev = NULL;
    int i=_curr->data;
    while(_curr != NULL && i!=key && _curr->next !=NULL)
    {
        _prev=_curr;
        _curr=_curr->next;
        i=_curr->data;
    }
    _prev->next = newNode;
    newNode->next = _curr;
}

void AddSorting(node*& h, int data) 
{
    node* newNode = new node; 
    newNode->data = data;
    newNode->next = NULL;

    if (h == NULL || h->data >= data) 
    {
        newNode->next = h;
        h = newNode;
        return;
    }

    node* _curr = h;
    while (_curr->next != NULL && _curr->next->data < data) 
    {
        _curr = _curr->next;
    }


    newNode->next = _curr->next;
    _curr->next = newNode;
}


// Print , Print Revers Nodes , Print Revers using Recursion
void print(node* h) 
{
    node* _temp = h;
    while (_temp != NULL) 
    {
        cout << _temp->data << " -> ";
        _temp = _temp->next;
    }
    cout << "NULL" << endl; 
}

void print_revers(node* h) 
{
    node* _temp = h;
    if (_temp != NULL) 
    {
        print_revers(_temp->next);
        cout << _temp->data << " -> ";
    }
}

void print_reversNode(node*& h) 
{
    node* _temp =h;
    node* _next = NULL;
    node* _prev = NULL;
    node* _curr = _temp;
    while (_curr != NULL)
    {
        _next = _curr->next;
        _curr->next = _prev;
        _prev = _curr;
        _curr = _next;
    }
    _temp = _prev;
    print(_temp);
}

void printReverseUsingArray(node* h) 
{
    if (h == NULL) return;

    int size = 0;
    node* _curr = h;
    while (_curr != NULL) 
    {
        size++;
        _curr = _curr->next;
    }

    int* arr = new int[size];
    _curr = h;
    for (int i = 0; i < size; i++) 
    {
        arr[i] = _curr->data;
        _curr = _curr->next;
    }

    for (int i = size - 1; i >= 0; i--) 
    {
        cout << arr[i] << " -> ";
    }
    cout << "NULL" << endl;

    delete[] arr;
}

// Delete First , Last , Position , At Key  
void deleteBegin(node*& h)
{
    if(h==NULL)
    {
        cout<<"Linked is Empty !!";
        return;
    }
    node* cn = h;
    h = h->next;
    free(cn);
}

void deleteLast(node*& h) 
{
    if (h == NULL) 
    {
        cout << "Linked list is empty!" << endl;
        return;
    }

    if (h->next == NULL)
    {
        h = NULL; 
        return;
    }

    node* _curr = h;
    node* _prev = NULL;

    while (_curr->next != NULL) {
        _prev = _curr;
        _curr = _curr->next;
    }

    delete _curr; 
    _prev->next = NULL; 
}

void deleteAtPos( node*& h,int postion)
{
    if (h == NULL) 
    {
        cout << "Linked list is empty!" << endl;
        return;
    }

    if (postion ==0)
    {
        node* temp = h;
        h = h->next;
        delete temp; 
        return;
    }
    
    node*_curr= h;
    node*_prev = NULL;
    int i=0;
    while(_curr != NULL && i<postion)
    {
        _prev=_curr;
        _curr=_curr->next;
        i++;
    }
    if (_curr == NULL) 
    {
        cout << "Position is out of bounds!" << endl;
        return;
    }
    _prev->next=_curr->next;
    delete _curr;
}

void deleteAtKey( node*& h,int key)
{
    if (h == NULL) 
    {
        cout << "Linked list is empty!" << endl;
        return;
    }

    if (key ==h->data)
    {
        node* temp = h;
        h = h->next;
        delete temp; 
        return;
    }
    
    node*_curr= h;
    node*_prev = NULL;
    int i=_curr->data;
    while(_curr != NULL && i!=key)
    {
        _prev=_curr;
        _curr=_curr->next;
        i=_curr->data;
    }
    if (_curr == NULL) 
    {
        cout << "Key is out of bounds!" << endl;
        return;
    }
    _prev->next=_curr->next;
    delete _curr;
}

//modfiy by(key,position)
void modifyAtKey(node*& h, int key, int data) 
{
    node*_curr = h;

    while (_curr != nullptr) 
    {
        if (_curr->data == key) 
        {
            _curr->data = data; 
            return;
        }
        _curr = _curr->next;
    }

    cout << "Key not found!!" << endl; 
} 

void modifyAtPosition(node*& h, int pos, int data) 
    {
    if (h == nullptr) 
    {
        cout << "The Linked list is empty!" << endl;
        return;
    }

    node* _curr = h;
    int i = 0;

    while (_curr != NULL) 
    {
        if (i == pos) 
        {
            _curr->data = data; 
            return;
        }
        _curr = _curr->next;
        i++;
    }

    cout << "Position out of bounds!!" << endl;
}

// Sorting List
void sortList(node*& h) 
{
    if (h == NULL || h->next == NULL) 
    {
        return; 
    }

    bool swapped;
    do 
    {
        swapped = false;
        node* _curr = h;

        while (_curr->next != NULL) 
        {
            if (_curr->data > _curr->next->data) 
            {
                int temp = _curr->data;
                _curr->data = _curr->next->data;
                _curr->next->data = temp;
                swapped = true; 
            }
            _curr = _curr->next;
        }
    } while (swapped); 
}

void bubbleSort(node*& h) 
{
    if (h == NULL || h->next == NULL) 
    {
        return; 
    }

    bool swapped;
    do 
    {
        swapped = false;
        node* _curr = h;

        while (_curr->next != NULL) 
        {
            if (_curr->data > _curr->next->data) 
            {
            
                int temp = _curr->data;
                _curr->data = _curr->next->data;
                _curr->next->data = temp;
                swapped = true; 
            }
            _curr = _curr->next;
        }
    } while (swapped); 
}

void insertionSort(node*& h) 
{
    if (h == NULL) return;

    node* _sorted = NULL; 
    node* _curr = h;
    while (_curr != NULL) 
    {
        node* next = _curr->next; 

        if (_sorted == NULL || _sorted->data >= _curr->data) 
        {
            _curr->next = _curr;
            _sorted = _curr;
        } 
        else 
        {
            node* temp = _sorted;
            while (temp->next != NULL && temp->next->data < _curr->data) 
                temp = temp->next;
            _curr->next = temp->next;
            temp->next = _curr;
        }
        _curr = next; 
    }
    h = _sorted; 
}

void selectionSort(node*& h) 
{
    if (h == NULL || h->next == NULL) 
    {
        return;
    }

    node* _curr = h;
    while (_curr != NULL) 
    {
        node* minNode = _curr;
        node* temp = _curr->next;

        while (temp != NULL) 
        {
            if (temp->data < minNode->data) 
            {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != _curr) 
        {
            int _temp = _curr->data;
            _curr->data = minNode->data;
            minNode->data = _temp;
        }
        _curr = _curr->next; 
    }
}

void extractOddElements(node*& h, node*& oddList) 
{
    node* current = h;
    node* previous = NULL;

    while (current != NULL) 
    {
        if (current->data % 2 != 0) 
        {
            if (previous == NULL) 
            {
                h = current->next;
            } 
            else 
            {
                previous->next = current->next;
            }

            node* temp = current;
            current = current->next;

            temp->next = oddList;
            oddList = temp;
        } 
        else 
        {
            previous = current;
            current = current->next;
        }
    }
}

void sortDescending(node*& h) 
{
    if (h == NULL || h->next == NULL) return;

    node* current = h;
    while (current != NULL) 
    {
        node* maxNode = current;
        node* temp = current->next;

        while (temp != NULL) 
        {
            if (temp->data > maxNode->data) 
            {
                maxNode = temp;
            }
            temp = temp->next;
        }

        if (maxNode != current) 
        {
            int tempValue = current->data;
            current->data = maxNode->data;
            maxNode->data = tempValue;
        }

        current = current->next;
    }
}

//Read Key and Show
/*
void display1(node* h) 
{ 
    int op = 0;
    do 
    {
        cout << "\n[-] Enter op : ";
        cin >> op;
        switch (op) 
        {
            case 1: 
            {
                int key;
                cout << "\n[1] Enter key : ";
                cin >> key;
                addBigen(key, h);
                print(h);
                break;
            }
            case 2: 
            {
                int v;
                cout << "\n[2] Enter key : ";
                cin >> v;
                addAfter(v, h);
                print(h);
                break;
            }
            case 3:
            {
                int d,pos;
                cout<<"[03] data  ";
                cin>>d;
                cout<<"[03] position :  ";
                cin>>pos;
                addAtPos(d,h,pos);
                print(h);
                break;
            }
            case 4:
            {
                int d,key;
                cout<<"[03] data  ";
                cin>>d;
                cout<<"[03] key :  ";
                cin>>key;
                addAtPos(d,h,key);
                print(h);
                break;
            }
            case 5:
            {
                int data; cout<<"enter data : ";cin>>data;
                AddOrder(h,data);
                print(h);
                break;
            }
            case 6:
            {
                deleteBegin(h);
                print(h);
                break;
            }
            case 7:
            {
                deleteLast(h);
                print(h);
                break;
            }
            case 8:
            {
                int pos;
                cout<<"Enter pos : ";cin>>pos;
                deleteAtPos(h,pos);
                print(h);
                break;
            }
            case 9:
            {
                int key;
                cout<<"Enter key : ";cin>>key;
                deleteAtKey(h,key);
                print(h);
                break;
            }
            case 10:
            {
                sortList(h);
                print(h);
                break;
            }
            default:
                break;
        }
    } 
    while (op != -1);
}

void display2(node*& h) {
    int op = 0;
    do {
        cout << "\n[-] Choose an operation: \n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Modify\n";
        cout << "4. Sort\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> op;

        switch (op) {
            case 1: { 
                int addOp;
                cout << "\n[-] Choose Add Operation: \n";
                cout << "1. Add First\n";
                cout << "2. Add Last\n";
                cout << "3. Add at Position\n";
                cout << "4. Add at Key\n";
                cout << "5. Add by Order\n";
                cout << "Enter your choice: ";
                cin >> addOp;

                int key;
                switch (addOp) {
                    case 1:
                        cout << "\n[Add First] Enter key: ";
                        cin >> key;
                        addBigen(key, h);
                        break;
                    case 2:
                        cout << "\n[Add Last] Enter key: ";
                        cin >> key;
                        addAfter(key, h); 
                        break;
                    case 3:
                        int pos;
                        cout << "\n[Add at Position] Enter key: ";
                        cin >> key;
                        cout << "Enter position: ";
                        cin >> pos;
                        addAtPos(key, h, pos);
                        break;
                    case 4:
                        cout << "\n[Add at Key] Enter key: ";
                        cin >> key;
                        addAtKey(h,key); 
                        break;
                    case 5:
                        cout << "\n[Add by Order] Enter key: ";
                        cin >> key;
                        AddOrder(h, key); 
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                print(h);
                break;
            }
            case 2: { 
                int deleteOp;
                cout << "\n[-] Choose Delete Operation: \n";
                cout << "1. Delete First\n";
                cout << "2. Delete Last\n";
                cout << "3. Delete at Position\n";
                cout << "4. Delete at Key\n";
                cout << "Enter your choice: ";
                cin >> deleteOp;

                switch (deleteOp) {
                    case 1:
                        deleteBegin(h);
                        break;
                    case 2:
                        deleteLast(h);
                        break;
                    case 3:
                        int pos;
                        cout << "Enter position: ";
                        cin >> pos;
                        deleteAtPos(h, pos);
                        break;
                    case 4:
                        int key;
                        cout << "Enter key: ";
                        cin >> key;
                        deleteAtKey(h, key); 
                            break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                print(h);
                break;
            }
            case 3: {
                int modfiyOp;
                cout << "\n[-] Choose Add Operation: \n";
                cout << "1. Add at Key\n";
                cout << "2. Add at position\n";
                cout << "Enter your choice: ";
                cin >> modfiyOp;

                int newkey,oldKey;
                switch (modfiyOp) {
                    case 1:
                        cout << "\n[old key] Enter old key: ";
                        cin >> oldKey;
                        cout << "\n[new key] Enter new key: ";
                        cin >> newkey;
                        modifyAtKey(h,oldKey,newkey);
                        break;
                    case 2:
                        cout << "\n[old key] Enter old pos: ";
                        cin >> oldKey;
                        cout << "\n[new key] Enter new pos: ";
                        cin >> newkey;
                        modifyAtPosition(h,oldKey,newkey);
                        break;
            }
            case 4: { 
                sortList(h);
                print(h);
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }}
    } while (op != 0);
}
*/
void display(node*& h) 
{
    int op = 0;
    do 
    {
        cout << "\n[-] Choose an operation: \n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Modify\n";
        cout << "4. Sort\n";
        cout<<"5.  Show\n";
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
                cout << "3. Add at Position\n";
                cout << "4. Add at Key\n";
                cout << "5. Add by Order\n";
                cout << "Enter your choice: ";
                cin >> addOp;

                int key;
                switch (addOp) 
                {
                    case 1:
                        cout << "\n[Add First] Enter key: ";
                        cin >> key;
                        addBigen(key, h);
                        break;
                    case 2:
                        cout << "\n[Add Last] Enter key: ";
                        cin >> key;
                        addAfter(key, h); 
                        break;
                    case 3:
                        int pos;
                        cout << "\n[Add at Position] Enter key: ";
                        cin >> key;
                        cout << "Enter position: ";
                        cin >> pos;
                        addAtPos(key, h, pos);
                        break;
                    case 4:
                        cout << "\n[Add at Key] Enter key: ";
                        cin >> key;
                        addAtKey(h, key); 
                        break;
                    case 5:
                        cout << "\n[Add by Order] Enter key: ";
                        cin >> key;
                        AddSorting(h, key); 
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            }
            case 2: 
            { 
                int deleteOp;
                cout << "\n[-] Choose Delete Operation: \n";
                cout << "1. Delete First\n";
                cout << "2. Delete Last\n";
                cout << "3. Delete at Position\n";
                cout << "4. Delete at Key\n";
                cout << "Enter your choice: ";
                cin >> deleteOp;

                switch (deleteOp) 
                {
                    case 1:
                        deleteBegin(h);
                        break;
                    case 2:
                        deleteLast(h);
                        break;
                    case 3:
                        int pos;
                        cout << "Enter position: ";
                        cin >> pos;
                        deleteAtPos(h, pos);
                        break;
                    case 4:
                        int key;
                        cout << "Enter key: ";
                        cin >> key;
                        deleteAtKey(h, key); 
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            }
            case 3: 
            {
                int modifyOp;
                cout << "\n[-] Choose Modify Operation: \n";
                cout << "1. Modify at Key\n";
                cout << "2. Modify at Position\n";
                cout << "Enter your choice: ";
                cin >> modifyOp;

                int newKey, oldKey;
                switch (modifyOp) 
                {
                    case 1:
                        cout << "\n[Old key] Enter old key: ";
                        cin >> oldKey;
                        cout << "\n[New key] Enter new key: ";
                        cin >> newKey;
                        modifyAtKey(h, oldKey, newKey);
                        break;
                    case 2:
                        cout << "\n[Position] Enter position: ";
                        cin >> oldKey; // استخدامه كموضع
                        cout << "\n[New key] Enter new key: ";
                        cin >> newKey;
                        modifyAtPosition(h, oldKey, newKey);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                print(h);
                break;
            }
            case 4: 
            { 
                int sortOp;
                cout << "\n[-] Choose Sort Method: \n";
                cout << "1. Bubble Sort\n";
                cout << "2. Insertion Sort\n";
                cout << "3. Selection Sort\n";
                cout << "Enter your choice: ";
                cin >> sortOp;

                switch (sortOp) 
                {
                    case 1:
                        cout << "Sorting using Bubble Sort..." << endl;
                        bubbleSort(h);
                        break;
                    case 2:
                        cout << "Sorting using Insertion Sort..." << endl;
                        insertionSort(h);
                        break;
                    case 3:
                        cout << "Sorting using Selection Sort..." << endl;
                        selectionSort(h);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            }

            case 5: 
            { 
                int printOp;
                cout << "\n[-] Choose Print Operation: \n";
                cout << "1. print sequnce\n";
                cout << "2. print revers using reusion \n";
                cout << "3. print revers using Threre Nodes\n";
                cout << "Enter your choice: ";
                cin >> printOp;

                switch (printOp) 
                {
                    case 1:
                        print(h);
                        break;
                    case 2:
                        print_revers(h);
                        break;
                    case 3:
                        print_reversNode(h);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
        }
    }
    while (op != 0);
}

int main() 
{
    node* head = NULL;
    display(head);
    return 0;
}

/*
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    void reversePrintHelper(Node* node) {
        if (node == nullptr) return;
        reversePrintHelper(node->next);
        cout << node->value << " ";
    }

public:
    LinkedList() {
        head = nullptr;
    }

    void addNode(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void sortDescending() {
        if (head == nullptr || head->next == nullptr) return;

        Node* current = head;
        while (current != nullptr) {
            Node* maxNode = current;
            Node* temp = current->next;

            while (temp != nullptr) {
                if (temp->value > maxNode->value) {
                    maxNode = temp;
                }
                temp = temp->next;
            }

            if (maxNode != current) {
                int tempValue = current->value;
                current->value = maxNode->value;
                maxNode->value = tempValue;
            }

            current = current->next;
        }
    }

    LinkedList extractOddElements() {
        LinkedList oddList;
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->value % 2 != 0) {
                oddList.addNode(current->value);

                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }

                Node* temp = current;
                current = current->next;
                delete temp;
            } else {
                previous = current;
                current = current->next;
            }
        }

        return oddList;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printReverse() {
        reversePrintHelper(head);
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "1. Add Element" << endl;
        cout << "2. Sort Descending" << endl;
        cout << "3. Extract Odd Elements" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Print Reverse" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.addNode(value);
                break;

            case 2:
                list.sortDescending();
                cout << "List sorted in descending order." << endl;
                break;

            case 3: {
                LinkedList oddList = list.extractOddElements();
                cout << "Odd elements extracted to a new list: ";
                oddList.printList();
                break;
            }

            case 4:
                cout << "Current List: ";
                list.printList();
                break;

            case 5:
                cout << "List in reverse: ";
                list.printReverse();
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
*/