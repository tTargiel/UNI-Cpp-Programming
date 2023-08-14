#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 3
// Zadanie 1

struct Link
{
    int value;
    Link *next = nullptr;
};

size_t size(const Link *head)
{
    int size = 0;
    while (head != nullptr)
    {
        size += 1;
        head = head->next;
    }
    return size;
}

size_t sum(const Link *head)
{
    int sum = 0;
    while (head != nullptr)
    {
        sum += head->value;
        head = head->next;
    }
    return sum;
}

void add(Link **head, int n)
{
    Link *tmp = new Link;
    tmp->value = n;
    tmp->next = *head;
    *head = tmp;
}

int main()
{
    Link *lista = nullptr;

    add(&lista, 21);
    add(&lista, 37);
    add(&lista, 02);
    add(&lista, 04);

    cout << "1.a. " << size(lista) << endl;
    cout << "1.b. " << sum(lista) << endl;

    return 0;
}
