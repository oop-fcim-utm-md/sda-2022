#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <array>
#include <vector>

struct d_t 
{

    int * a {nullptr};
    size_t size {0};

    d_t(const size_t len)
    {
        a = new int [len];
        size = len;
    }

    d_t(const d_t & other)
    {
        a = new int [other.size];
        size = other.size;

        std::copy(other.a, other.a + other.size, a);
    }

    ~d_t()
    {
        delete [] a;
    }

    int * begin()
    {
        return a;
    }

    int * end()
    {
        return a + size;
    }
};

int main(int argc, char const *argv[])
{
    
    d_t arr(5);

    for (size_t i = 0; i < arr.size; i++)
    {
        arr.a[i] = i + 1;
    }

    for (size_t i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.a[i]);
    }
    printf("\n");

    d_t brr(arr);

    for (auto it : brr)
    {
        printf("%d ", it);
    }
    printf("\n");
    
    std::vector<int> vec(brr.begin(), brr.end());
    for (
        std::vector<int>::reverse_iterator it = vec.rbegin();
        it < vec.rend();
        it++)
    {
        printf("%d ", *it);
    }

    std::vector<int> v;

    printf("\nsize: %d, capacity %d\n", v.size(), v.capacity());    
    v.resize(5);
    printf("\nsize: %d, capacity %d\n", v.size(), v.capacity());
    v.push_back(100);
    printf("\nsize: %d, capacity %d\n", v.size(), v.capacity());

    for (auto it : v)
    {
        printf("%d ", it);
    }

    std::array<int, 10> ar;
}
