#include <iostream>
using namespace std;

template <class T>
T max(T *arr, int size)
{
    T max_ = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max_)
        {
            max_ = arr[i];
        }
    }
    return max_;
}

int main()
{
    int arr1[] = {5, 3, 9, 2, 4, 6, 11, 4};
    double arr2[] = {34.97, 34.22, 45.23, 34.65};

    cout << "Maximum element of {5,3,9,2,4,6,11,4} is : " << max(arr1, 8) << endl;
    cout << "Maximum element of {34.97,34.22,45.23,34.65} is : " << max(arr2, 4) << endl;

    return 0;
}