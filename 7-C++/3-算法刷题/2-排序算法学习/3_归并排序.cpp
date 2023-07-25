#include <iostream>
#include <vector>

void print_arr(std::vector<int> &arr)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 归并排序
class MergeSort
{
public:
    void operator()(std::vector<int> &arr)
    {
        if (arr.size() <= 1)
            return;
        process(arr, 0, arr.size() - 1);
    }

    void process(std::vector<int> &arr, int L, int R)
    {
        if (L == R)
            return;
        // L和R的中间值
        int mid = (L + R) >> 1;

        process(arr, L, mid);
        process(arr, mid + 1, R);
        merge(arr, L, mid, R);
    }

    void merge(std::vector<int> &arr, int L, int M, int R)
    {
        std::vector<int> help;

        int i = 0;
        int p1 = L;
        int p2 = M + 1;

        while (p1 <= M && p2 <= R)
        {
            if (arr[p1] <= arr[p2])
            {
                help.push_back(arr[p1++]);
            }
            else
            {
                help.push_back(arr[p2++]);
            }
        }

        while (p1 <= M)
        {
            help.push_back(arr[p1++]);
        }

        while (p2 <= R)
        {
            help.push_back(arr[p2++]);
        }

        for (int i = 0; i < help.size(); i++)
        {
            arr[L + i] = help[i];
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(nullptr));

    std::vector<int> arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 99 + 1);
    }
    std::cout << "排序之前....." << std::endl;
    print_arr(arr);

    MergeSort b;
    b(arr);

    std::cout << "排序之后....." << std::endl;
    print_arr(arr);

    return 0;
}
