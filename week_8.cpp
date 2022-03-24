#include <iostream>
#include <string>
#include <vector>

struct list_node
{
    std::string name;
    list_node *next{nullptr};

    // основные конструкторы для облегчения создания списка, если количество узлов известно заранее
    // обратите внимание на использование списка инициализации
    list_node(const std::string val) : name(val) {}                        // создание узла без связей
    list_node(const std::string val, list_node *n) : name(val), next(n) {} // создание узла, связанного с уже существующим
    // здесь конструктор - наоборот отключается, чтобы его нельзя было вызывать:
    list_node(list_node &other) = delete; // конструктор копирования данных одного узла в другой (для односвязного списка такая операция бесполезна)
};

void print(const list_node *head)
{
    if (head)
    {
        std::cout << head->name << " ";
        print(head->next); // рекурсивный вызов только в том случае, если в head действительный адрес узла
    }
    // если узел не содержит действительный адрес, цепочка рекурсивных вызовов прервется 
}

void clear(list_node *head)
{
    if (head)
    {
        clear(head->next); // рекурсивный вызов, чтобы начать удалять узлы с конца
        delete head; // первый раз delete будет вызыван на том узле, у которого next == null
    }
}

int length(const list_node *head, const unsigned int acc)
{
    if (!head) // если это конец списка, значит счетчик можно больше не увеличивать
        return acc;
    return length(head->next, acc + 1); // рекурсивный вызов с инкрементированной переменной-счетчиком
}

// узел деререва с двумя дочерними узлами справа и слева
struct tree_node
{
    std::string name;
    tree_node *left{nullptr};
    tree_node *right{nullptr};
};

void insert(tree_node *&node, std::string s)
{
    if (nullptr == node) // если найден пустой узел, данные записываются на его позицицю
    {
        node = new tree_node;
        node->name = s;
        return;
    }
    // в противном случае нужно проверить, в какую сторону двигаться по дереву 
    if (s <= node->name)
    {
        insert(node->left, s); // для сортировки по возрастанию - влево
    }
    else
    {
        insert(node->right, s); // для сортировки по убыванию - вправо
    }
}

int main(int argc, char const *argv[])
{
    // создание списка через вызов конструкторов по цепочке
    list_node *head = new list_node("A", new list_node("B", new list_node("C", new list_node("D"))));

    print(head);
    std::cout << "\n"
              << length(head, 0)
              << "\n";

    clear(head);

    std::vector<std::string> v = {"N", "O", "J", "M", "L", "A", "D", "F", "G", "B"};

    tree_node *root = nullptr; // корень двоичного дерева
    for (size_t i = 0; i < v.size(); i++)
    {
        insert(root, v[i]);
    }
}
