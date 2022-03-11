#include <iostream>
#include <forward_list>
#include <vector>

struct node
{
    // поле для хранения данных одного узла списка:
    int x{0};
    // ссылка на следующий узел списка:
    node *next{nullptr};
};

using std::cout;
using std::endl;

// слияние двух произвольных списков
node *merge(node *left, node *right)
{
    node *result = nullptr; // новый отсортированный список, результат слияния left и right 
    // выход из рекурсии, если хотя бы один из исходных списков пуст:
    if (left == nullptr)
        return (right);
    else if (right == nullptr)
        return (left);
    // условие сортировки
    // если начало left содержит меньшее значение, то оно добавляется в result:
    if (left->x <= right->x)
    {
        result = left;
        // после этого рекурсивно производится слияние оставшейся части left и целиком переданного right:
        result->next = merge(left->next, right);
    }
    else
    {
        // в противном случае производится слияние оставшейся части right и целиком переданного left:
        result = right;
        result->next = merge(left, right->next);
    }
    // когда рекурсивные вызовы прекращаются, result будет содержать окончательный список
    return (result);
}

void split(node *head, node *&left, node *&right)
{
    node *slow = head; // "медленный" указатель
    node *fast = head->next; // "быстрый" указатель, двигается в два раза дальше, чем "медленный"

    while (fast != nullptr) // условие выхода из цикла
    {
        // "быстрый" указатель двигается вперед на одну позицию
        fast = fast->next; 
        if (fast != nullptr) // условие выхода из цикла
        {
            // оба указателя двигаются вперед на одну позицию
            slow = slow->next;
            // т.о. "быстрый" указатель ушел на две позиции вперед за одну итерацию
            fast = fast->next;
        }
    }
    // если произошел выход из цикла, "быстрый" указатель вышел за пределы списка
    left = head; // left начинается там же, где начинался исходный список (head)
    // это значит, что "медленный" прошел в два раза меньшее расстояние и т.о. находится в середине списка 
    right = slow->next; // right начинается с элемента, расположенного сразу за серединой исходного списка
    // теперь связь между центральным и следующим элементами списка можно разорвать: 
    slow->next = nullptr;
    // в результате список head был поделен на два новых списка, left и right 
}

void msort(node *&head_ref)
{
    node *head = head_ref;
    node *left;
    node *right;
    // уловие выхода из рекурсии, если исходный список содержит меньше двух элементов:
    if (head == nullptr || head->next == nullptr)
        return;
    // разделение текущей версии списка напополам:
    split(head, left, right);
    // рекурсивная сортировка половин исходного списка:
    msort(left);
    msort(right);
    // если рекурсия завершена, исходный список был полностью обработан
    // слияние двух половин последнего разделенного отрезка исходного списка:
    head_ref = merge(left, right);
}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {14, 66, -1, 10, -45, 20, 1, 0};

    node *head = nullptr; // "голова" списка
    node *tail = nullptr; // "хвост" списка
    // инициализация списка с помощью вектора:
    for (unsigned int i = 0; i < array.size(); i++)
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
    // сортировка слиянием:
    msort(head);

    for (node *current = head; current; current = current->next)
    {
        cout << current->x << " ";
    }

    cout << endl;

    // аналогичный код, использующий встроенные алгоритмы С++ для работы со списками
    // инициализация списка с помощью массива:
    std::forward_list<int> l({14, 66, -1, 10, -45, 20, 1, 0});
    // сортировка слиянием:
    l.sort();

    for (auto it : l)
    {
        cout << it << " ";
    }
}
