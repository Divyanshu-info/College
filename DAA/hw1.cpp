// C++ program of above implementation
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Pair
{
public:
    int min;
    int max;
};

Pair get_Min_Max(int arr[], int low_index, int high_index)
{
    Pair minmax, Left_part, Right_part;
    int middle_index;

    if (low_index == high_index)
    {
        minmax.max = arr[low_index];
        minmax.min = arr[low_index];
        return minmax;
    }

    if (high_index == low_index + 1)
    {
        if (arr[low_index] > arr[high_index])
        {
            minmax.max = arr[low_index];
            minmax.min = arr[high_index];
        }
        else
        {
            minmax.max = arr[high_index];
            minmax.min = arr[low_index];
        }
        return minmax;
    }

    middle_index = (low_index + high_index) / 2;
    Left_part = get_Min_Max(arr, low_index, middle_index);
    Right_part = get_Min_Max(arr, middle_index + 1, high_index);

    if (Left_part.min < Right_part.min)
        minmax.min = Left_part.min;
    else
        minmax.min = Right_part.min;

    if (Left_part.max > Right_part.max)
        minmax.max = Left_part.max;
    else
        minmax.max = Right_part.max;

    return minmax;
}

int main()
{
    srand(time(0));
    int arr[16] = {};
    for (int i = 0; i < 16; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << ' ';
    }
    cout << endl;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();

    Pair minmax = get_Min_Max(arr, 0, arr_size - 1);

    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max << endl;
    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;
    return 0;
}