#include <iostream>
using namespace std;
void printArray(int a[6])
{

    for (int i = 0; i < 6; i++)

        cout << a[i] << " ";

    cout << endl;
}

// Selection Sorting
void selectionSort(int a[6])
{
    int selection;
    for (int i = 0; i < 6; i++)
    {
        selection = a[i];
        for (int j = i + 1; j < 6; j++)
            if (a[j] < selection)
            {
                selection = a[j];
                a[j] = a[i];
                a[i] = selection;
                //  swap(a[j], a[i]);
            }
    }
}

int main()
{
    int a[6] = {5, 4, 8, 1, 2, 6};
    selectionSort(a);
    printArray(a);
}