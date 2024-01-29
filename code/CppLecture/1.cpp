// https://marketplace.visualstudio.com/items?itemName=AdamWulkiewicz.ExcludeFromBuild


// 전처리 << 전에 미리 처리하겠다.
// 데이터 >> 가공
#include <iostream> 

int main(void)
{
    int** arr = new int* [5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = new int[10];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            *(*(arr + i) + j) = i * 10 + j; // 포인터를 사용하여 접근
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << *(*(arr + i) + j) << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

