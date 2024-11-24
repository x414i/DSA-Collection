#include <iostream>
using namespace std;
void printArray(int a[6])
{

    for (int i = 0; i < 6; i++)

        cout << a[i] << " ";

    cout << endl;
}

// insertion Sorting
void insertionSort(int a[6])
{
    int key, j;
    for (int i = 1; i < 6; i++)
    {
        key = a[i];
        j = i - 1;
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int a[6] = {5, 4, 8, 1, 2, 6};
    insertionSort(a);
    printArray(a);
}