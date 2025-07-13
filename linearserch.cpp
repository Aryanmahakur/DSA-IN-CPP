#include <iostream>
#include <vector>
using namespace std;

int linearsearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i; 
        }
        /* code */
    }

    return -1;
}

int linearsearch(vector<int> &arr, int target)
{int count=0;
    for (int i = 0; i < arr.size(); i++)

    {
        if (arr[i] == target)
        {
          count++;
        }
        /* code */
    }

    return count;
}

void linearsearch(vector<int> &arr, int target)
{
    vector<int> ind;  // Stores matching indices

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            ind.push_back(i);  // ✅ Correct way to add an index
        }
    }

    // Print result here OR return ind if you want to use it in main
    cout << "Target found at indices: ";
    for (int i : ind) {
        cout << i << " ";
    }
    cout << endl;
}


bool linearsearchs(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return true; 
        }
        /* code */
    }

    return false;
}

int main()
{
    vector<int> arr = {10, 30, 50, 20, 40};
    int target = 20;

    int index = linearsearch(arr, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in array.\n";
    }

    return 0;
}
