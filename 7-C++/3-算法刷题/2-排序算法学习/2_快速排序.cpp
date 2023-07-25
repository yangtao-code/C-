#include <iostream>
using namespace std;
#include <vector>
#include <ctime>

// 快速排序API
/**
 * @brief 
 * 
 * @param arr 
 * @param l 
 * @param r 
 */
void quickSort(vector<int>& arr, int l, int r);

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    vector<int> arr;
    for(int i = 0; i < 10; i++)
    {
        arr.push_back(rand()%100);
    }
    quickSort(arr,0,arr.size() - 1);

    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void quickSort(vector<int>& arr, int l, int r)
{
    // 子数组长度为1,返回
    if (l >= r)
    {
        return;
    }
    int i = l;
    int j = r;
    while (i < j)
    {
        while (i < j && arr[j] >= arr[l])
            j--;
        while (i < j && arr[i] <= arr[l])
            i++;

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    int tmp = arr[l];
    arr[l] = arr[i];
    arr[i] = tmp;

    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}