#include <initializer_list>
#include <iostream>
// логика списка включается в структуру для удобства (легче следить за началом списка, размером списка и т.д.) 
struct list
{
    struct node
    {
        // поле для хранения данных одного узла списка:
        int x{0};
        // ссылка на следующий узел списка:
        node * next{nullptr};
    };

    node *head = nullptr; // "голова" списка
    node *tail = nullptr; // "хвост" списка
    unsigned int len = 0; // длина списка
    // конструктор для инициализации списка массивом целых чисел
    list(const int *array, unsigned int count)
    {
        len = count;
        for (size_t i = 0; i < count; i++)
        {
            node *n = new node{array[i]};
            if (!head)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = tail->next;
            }
        }
    }
    // конструктор для инициализации списка любым массиво-образным объектом
    list(const std::initializer_list<int> &array)
    {
        len = array.size();
        for (size_t i = 0; i < array.size(); i++)
        {
            node *n = new node{*(array.begin() + i)};
            if (!head)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = tail->next;
            }
        }
    }
    // конструктор для инициализации списка другим списком
    list(const list &other)
    {
        len = list::size(other);

        node *n = head = new node;
        for (node *current = other.head; current; current = current->next)
        {
            n->x = current->x;
            if (current->next)
            {
                n->next = new node;
                tail = n;
                n = n->next;
            }
        }
    }
    // деструктор для автоматического очищения памяти, занятой списком
    ~list()
    {
        len = 0;
        while (head)
        {
            node *current = head;
            head = head->next;
            delete current;
        }
        head = tail = nullptr;
    }
    // статическая функция (не является частью объекта при инициализации)
    // возвращает размер списка, переданного в качестве аргумента
    static unsigned int
    size(const list &obj)
    {
        return obj.len;
    }
    // статическая функция (не является частью объекта при инициализации)
    // выводит данные списка, переданного в качестве аргумента
    static void
    print(const list &obj)
    {
        for (
            node *current = obj.head;
            current;
            current = current->next)
        {
            std::cout << current->x << " ";
        }
    }
};
// перегруженная функция-оператор вывода
// выводит данные списка, переданного в качестве аргумента (второй параметр)
// в поток данных, переданный в качестве аргумента (первый параметр)
std::ostream &operator<<(std::ostream &os, const list &obj)
{
    for (
        list::node *current = obj.head;
        current;
        current = current->next)
    {
        os << current->x << " ";
    }
    return os;
}

using std::cout;

int main(int argc, char const *argv[])
{
    int arr[3] = {1, 2, 3};
    // инициализация списка с помощью массива при создании объекта
    list a(arr, 3);
    cout << list::size(a) << "\n";
    list::print(a);
    // инициализация списка как копии другого списка при создании объекта
    list b(a);
    cout << list::size(b) << "\n";
    // использование перегруженного оператора вывода (<<)
    cout << b;
}
