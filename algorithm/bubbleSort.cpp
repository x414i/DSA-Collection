#include <iostream>
#include <algorithm>
using namespace std;

// - Bubble Sorting
void bubbleSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
}
void show(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {5, 4, 7, 2, 6, 1};
    cout << "Befor Sorting :\t";
    show(arr, 6);
    bubbleSort(arr, 6);
    cout << "After Sorting :\t";
    show(arr, 6);
    return 0;
}
