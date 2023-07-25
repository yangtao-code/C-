#include <iostream>
#include <vector>
using namespace std;

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void print_arr(std::vector<int> &arr)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 快速排序1.0版本,P(基准数)在数组最右侧
// <= P 在左边,> P 在右边
class QuickSort1_0
{
public:
    void operator()(std::vector<int> &arr)
    {
        if (arr.size() <= 1)
            return;

        quickSort(arr, 0, arr.size() - 1);
    }
    void quickSort(std::vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;
        std::vector<int> p = partition(arr, l, r);

        quickSort(arr, l, p[0] - 1);
        quickSort(arr, p[1] + 1, r);
    }

    std::vector<int> partition(std::vector<int> &arr, int l, int r)
    {
        int less = l;
        int more = r;

        while (l < more)
        {
            if (arr[l] <= arr[r])
            {
                l++;
                less++
            }
            else if (arr[l] > arr[r])
            {
                Swap(arr[l], arr[--more]);
            }
        }

        Swap(arr[more], arr[r]);

        return std::vector<int>{less, more};
    }
};

// 快速排序2.0版本,P(基准数)在数组最右侧
// < P 在左边,> P 在右边, = P 在中间
class QuickSort2_0
{
public:
    void operator()(std::vector<int> &arr)
    {
        if (arr.size() <= 1)
            return;

        quickSort(arr, 0, arr.size() - 1);
    }
    void quickSort(std::vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;
        std::vector<int> p = partition(arr, l, r);

        quickSort(arr, l, p[0] - 1);
        quickSort(arr, p[1] + 1, r);
    }

    std::vector<int> partition(std::vector<int> &arr, int l, int r)
    {
        int less = l;
        int more = r;

        while (l < more)
        {
            if (arr[l] < arr[r])
            {
                Swap(arr[l++], arr[less++]);
            }
            else if (arr[l] > arr[r])
            {
                Swap(arr[l], arr[--more]);
            }
            else
            {
                l++;
            }
        }

        Swap(arr[more], arr[r]);

        return std::vector<int>{less, more};
    }
};

// 快速排序3.0版本,基准数随机
class QuickSort3_0
{
public:
    void operator()(std::vector<int> &arr)
    {
        srand((unsigned int)time(nullptr));
        if (arr.size() <= 1) // 如果数组的长度小于等于1,则不需要排序
            return;
        quickSort(arr, 0, arr.size() - 1);
    }

    void quickSort(std::vector<int> &arr, int L, int R)
    {
        if (L >= R)
            return;
        Swap(arr[L + rand() % (R - L + 1)], arr[R]);

        std::vector<int> res = partition(arr, L, R);
        quickSort(arr, L, res[0] - 1);
        quickSort(arr, res[1] + 1, R);
    }

    std::vector<int> partition(std::vector<int> &arr, int L, int R)
    {
        int less = L - 1;
        int more = R;
        while (L < more)
        {
            if (arr[L] < arr[R])
            {
                Swap(arr[++less], arr[L++]);
            }
            else if (arr[L] > arr[R])
            {
                Swap(arr[--more], arr[L]);
            }
            else
            {
                L++;
            }
        }
        Swap(arr[more], arr[R]);

        return std::vector<int>{less + 1, more};
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(nullptr));

    std::vector<int> arr;
    for (int i = 0; i < 20; i++)
    {
        arr.push_back(rand() % 999 + 1);
    }
    std::cout << "排序之前....." << std::endl;
    print_arr(arr);

    QuickSort1_0 b;
    b(arr);

    std::cout << "排序之后....." << std::endl;
    print_arr(arr);
    return 0;
}
