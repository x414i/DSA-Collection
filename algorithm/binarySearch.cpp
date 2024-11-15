#include <iostream>
using namespace std;

const int SIZE = 8;

int BinarySearch(const int arr[], int size, int value)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == value)

            return mid;

        else if (arr[mid] < value)
            start = mid + 1;

        else

            end = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    int valueToFind = 10;
    int position = BinarySearch(arr, SIZE, valueToFind);

    if (position == -1)
        cout << "Not Found" << endl;

    else
        cout << "Position is: " << position << endl;

    return 0;
}