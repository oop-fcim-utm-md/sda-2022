// еще немного о рекурсии и об эффективности
// https://godbolt.org/

#include <stdio.h>

// версия нахождения минимального элемента без использования ветвлений
// достигается засчет обнуления большего из двух чисел результатом сравнения (который вернет 1 или 0)
int min_branchless(int a, int b)
{
    return a * (a < b) + b * (b <= a);
}

// версия нахождения минимального элемента c ветвлениями
// результат компиляции сильно отличается с оптимизацией (флаг -O)
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

struct list_node
{
    const char name[10];
    list_node *next{nullptr};
};

unsigned int length(const list_node *head)
{
    if (nullptr == head)
        return 0; // если это конец списка, значит длина списка уже равна нулю

    return 1 + length(head->next); // иначе длина списка равна единице плюс длине оставшейся части списка
}

// пример tail recursive функции
// такая рекурсия отличается от примера выше порядком вызовов, если использовать флаг -O:
unsigned int aux(const list_node *head, const unsigned int acc)
{
    if (nullptr == head)
        return acc; // если это конец списка, счетчик содержит окончательное значение

    return aux(head->next, acc + 1); // иначе длина списка равна единице плюс текущее значение счетчика
}

unsigned int length_tail(const list_node *head)
{
    return aux(head, 0);
}

int main(int argc, char const *argv[])
{
    list_node *list = new list_node{"Alpha", new list_node{"Bravo", new list_node{"Charlie"}}};

    printf("%d %d", length(list), length_tail(list));
}
