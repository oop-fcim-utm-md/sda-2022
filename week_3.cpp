#include <algorithm>
#include <assert.h>
#include <stdio.h>
// простая реализация вектора
struct vector 
{
    // переменные, необходимые для работы вектора

    // указатель для массива:
    int * start {nullptr};
    // счетчик для текущего размера:
    size_t size {0};

    // конструкторы вызываются при создании переменной этого типа

    // конструктор с параметром,
    // инициализирует массив длины len:
    vector(const size_t len)
    {
        start = new int [len];
        size = len;
    }
    // конструктор копирования,
    // инициализирует массив как копию массива из другого вектора other:
    vector(const vector & other)
    {
        start = new int [other.size];
        size = other.size;
        // алгоритм копирования из библиотеки <algorithm>:
        std::copy(other.start, other.start + other.size, start);
    }
    // деструктор, вызывается при уничтожении переменной:
    ~vector()
    {
        delete [] start;
    }

    // методы вектора

    // специальный метод, возвращающий начало массива:
    int * begin()
    {
        return start;
    }
    // специальный метод, возвращающий конец массива:
    int * end()
    {
        return start + size;
    }
    // специальный метод, возвращающий ссылку на элемент массива, соотв. index:
    int & at(size_t index)
    {
        // если индекс недействительный, программа прекратит работу
        assert(index < size);
        return start[index];
    }
};

int main(int argc, char const *argv[])
{
    // вызов конструктора vector(const size_t len):
    vector arr(5);
    for (size_t i = 0; i < arr.size; i++)
    {
        arr.at(i) = i + 1; // присваивание по ссылке можно делать и на вызов метода
        printf("%d ", arr.at(i));
    }
    printf("\n");

    // вызов конструктора vector(const vector & other):
    vector brr(arr);

    // короткая форма записи цикла
    // использует методы вектора begin и end
    // для определения местоположения и длины массива
    // it является ссылкой на элемент массива start из вектора brr:
    for (auto it : brr)
    {
        printf("%d ", it);
    }
    printf("\n");

    // вызов всех деструкторов происходит здесь
}
