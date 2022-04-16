#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef std::string data;

void push_back_st(data *obj, unsigned int &idx, const char *sval)
{
    obj[idx] = sval;
    idx++;
}

void set_st(data *obj, unsigned int i, unsigned int idx, const char *sval)
{
    assert(i < idx);
    obj[i] = sval;
}

void push_back_h(data *&obj, unsigned int &size, const char *sval)
{
    data *tmp = new data[size + 1];
    for (unsigned int i = 0; i < size; ++i)
    {
        tmp[i] = obj[i];
    }
    tmp[size] = sval;
    delete[] obj;
    obj = tmp;
    size++;
}

void set_h(data *obj, unsigned int i, unsigned int size, const char *sval)
{
    assert(i < size);
    obj[i] = sval;
}

int main()
{
    // 1. динамический массив на "стэке"
    data obj_st[1000] = {};
    unsigned int idx = 0;

    push_back_st(obj_st, idx, "Goodbye");
    push_back_st(obj_st, idx, "Hello");

    set_st(obj_st, 1, idx, "Hi");

    for (unsigned int i = 0; i < idx; ++i)
    {
        std::cout <<  obj_st[i] << "\n";
    }
    std::cout << "\n";

    // 2. динамический массив на "куче"
    data *obj_h = nullptr;
    unsigned int size = 0;

    push_back_h(obj_h, size, "Hello");
    push_back_h(obj_h, size, "Goodbye");

    set_h(obj_h, 1, size, "Hi");

    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << obj_h[i] << "\n";
    }
    std::cout << "\n";

    // встроенный динамический массив
    std::vector<data> obj_v;

    obj_v.push_back("My name is V");
    obj_v.push_back("What's yours?");

    obj_v[1] = "Timmy!";

    for (auto st : obj_v)
    {
        std::cout << st << "\n";
    }
}
