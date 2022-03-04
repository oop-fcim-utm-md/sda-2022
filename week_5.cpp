#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

struct node
{
    // поле для хранения данных одного узла списка:
    int x{0};
    // ссылка на следующий узел списка:
    node * next{nullptr};
};

int main(int argc, char const *argv[])
{
    // само представление списка в программе тоже является ссылкой на узел для совместимости:
    node * head = new node {10};
    // инициализация следующего узла списка через первый узел head:
    head->next = new node {20};
    // итерирование по списку, используя связи между узлами:
    for( 
        node * current = head; // используя временную ссылку, инициализируя ее адресом начала списка
        current; // можно перебирать элементы списка до тех пор, пока не встретится последний элемент
        current = current->next) // поле next последнего элемента списка пусто, поэтому цикл завершится
    {
        printf("%d ", current->x);
    }
    // тот же принцип можно использовать для очищения списка:
    while(head)
    {
        node * cur = head;
        head = head->next;
        delete cur;
    }
}
