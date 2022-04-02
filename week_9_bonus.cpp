// Поляков, К., "Программирование на языке Си" (2009)
#include <stdio.h>
#include <string.h>

struct node
{
    char data;
    node *left, *right;
};

typedef node *pnode;

#define NOT_AN_OPERATOR 100

int priority(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return NOT_AN_OPERATOR;
}

pnode make_tree(char expr[], int first, int last)
{
    int minptr, i, k, ptr;
    int nest = 0;
    pnode tree = new node;
    if (first == last)
    {
        tree->data = expr[first];
        tree->left = nullptr;
        tree->right = nullptr;
        return tree;
    }
    minptr = NOT_AN_OPERATOR;
    for (i = first; i <= last; i++)
    {
        if (expr[i] == '(')
        {
            nest++;
            continue;
        }
        if (expr[i] == ')')
        {
            nest--;
            continue;
        }
        if (nest > 0)
            continue;

        ptr = priority(expr[i]);
        if (ptr <= minptr)
        {
            minptr = ptr;
            k = i;
        }
    }
    if (minptr == NOT_AN_OPERATOR &&
        expr[first] == '(' &&
        expr[last] == ')')
    {
        delete tree;
        return make_tree(expr, first + 1, last - 1);
    }

    tree->data = expr[k];
    tree->left = make_tree(expr, first, k - 1);
    tree->right = make_tree(expr, k + 1, last);
    return tree;
}

void print_tree(pnode tree)
{
    if (!tree)
        return;
    print_tree(tree->left);
    printf("%c ", tree->data);
    print_tree(tree->right);
}

int main(int argc, char const *argv[])
{
    char s[] = "((1+((2+3)*(4+(5/6))))+((2*3)*(4-6)))";
    pnode tree = make_tree(s, 0, strlen(s) - 1);
    print_tree(tree);
}
