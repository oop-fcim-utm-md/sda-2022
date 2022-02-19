#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

template <typename T>
struct d_t
{
    T x;
    d_t<T> * next{nullptr};
};

template <size_t M, size_t N, typename T>
void print_other(T (&matrix)[M][N]) 
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

template <size_t Num,typename Type>
void
print(
    d_t<Type> (&array)[Num])
{
    for (size_t i = 0; i < Num; i++)
    {
        std::cout << array[i].x << " ";
    }
}

int main(int argc, char const *argv[])
{
    d_t<std::string> arr [5] = {{"10"}, {"20"}, {"30"}, {"40"}, {"50"}};
    print(arr);

    assert();

    d_t<int> * head = new d_t<int> {10};

    head->next = new d_t<int> {20};

    for(
        d_t<int> * current = head; 
        current; 
        current = current->next)
    {
        printf("%d ", current->x);
    }

    while(head)
    {
        d_t<int> * cur = head;
        head = head->next;
        delete cur;
    }
}
