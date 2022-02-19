#include <stdio.h>
#include <vector>

int main(int argc, char const *argv[])
{
    // пустой вектор, память не выделена
    std::vector<int> brr;
    // выделение памяти под 5 элементов типа int
    brr.resize(5);
    printf("\nsize: %d, capacity %d\n", int(brr.size()), int(brr.capacity())); // size: 5, capacity: 5

    for (size_t i = 0; i < brr.size(); i++)
    {
        // вектор может быть использован как обычный массив
        brr[i] = i + 1;
    }

    // новый вектор как копия другого вектора, память выделяется в момент инициализации
    std::vector<int> vec(brr.begin(), brr.end());
    for (
        std::vector<int>::reverse_iterator current = vec.rbegin();
        current < vec.rend();
        current++)
    {
        // вектор так же может быть использован как список - через указатели на начало и конец
        printf("%d ", *current);
    }

    // вставка в вектор нового элемента с автоматическим выделением памяти при неоходимости
    // элемент вставляется в начало вектора, сдвигая другие элементы вправо
    vec.insert(vec.begin(), 0);

    // элементы можно вставлять в конец вектора, память также выделится, если необходимо
    vec.push_back(10);
    printf("\nsize: %d, capacity %d\n", int(vec.size()), int(vec.capacity())); // size: 7, capacity: 10

    for (auto it : vec)
    {
        // для векторов также есть особый способ итерирования, с помощью ссылок
        // ссылки - это указатели, которые не надо разыменовывать
        // также обратите внимание на ключевое слово auto - автоматическое определение типа данных
        printf("%d ", it);
    }

    // удаление элемента из вектора по указателю (итератору)
    vec.erase(vec.begin());
    // удаление элемента с конца вектора
    vec.pop_back();
    printf("\nsize: %d, capacity %d\n", int(vec.size()), int(vec.capacity())); // size: 5, capacity: 10
    for (auto it : vec)
    {
        printf("%d ", it);
    }
}
