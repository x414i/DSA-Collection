#include <iostream>

using namespace std;

const int SIZE = 100;

bool isFound(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

void addNumber(int arr[], int &size, int newNum)
{
    if (isFound(arr, size, newNum))
    {
        cout << "Number " << newNum << "Is Done Add";
    }
    else
    {
        arr[size] = newNum;
        size++;
        cout << "Number [" << newNum << "] add array\n";
    }
}

void modifyNumber(int arr[], int size, int oldNum, int newNum)
{
    if (!isFound(arr, size, oldNum))
    {
        cout << "Number [" << oldNum << "] is Not Found\n";
        return;
    }

    if (isFound(arr, size, newNum))
    {
        cout << "New Number [" << newNum << "]\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == oldNum)
        {
            arr[i] = newNum;
            cout << "Number [" << oldNum << "] IsDone  to  Modify [" << newNum << "]\n";
            break;
        }
    }
}

void deleteNumber(int arr[], int &size, int num)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            found = true;
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            cout << "Number : " << num << " IsDone Deleted\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Number : " << num << " is not found\n";
    }
}

int main()
{
    int arr[SIZE] = {0, 0, 0, 0};
    int size = 0;

    addNumber(arr, size, 5);
    addNumber(arr, size, 10);

    modifyNumber(arr, size, 10, 20);
    deleteNumber(arr, size, 20);
    cout << endl;
    cout << "____________________________________________________\n\n";
    cout << " ________________ [ Print Array ] __________________\n\n";
    cout << "____________________________________________________\n\n";
    cout << "\t\t\t\t\t[" << " ";
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << arr[size - 1] << " ]" << " ";
    return 0;
}
