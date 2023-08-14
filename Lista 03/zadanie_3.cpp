#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 3
// Zadanie 3

struct Link
{
    int value;
    Link *next = nullptr;
};

void add(Link **head, int n)
{
    Link *tmp = new Link;
    tmp->value = n;
    tmp->next = *head;
    *head = tmp;
}

void print(const Link *head)
{
    if (head == nullptr)
        return;

    cout << head->value << " ";
    print(head->next);
}

void reverse(Link *&lista)
{
    Link *current = lista;
    Link *prev = nullptr, *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    lista = prev;
}

int main()
{
    Link *lista = nullptr;

    add(&lista, 9);
    add(&lista, 5);
    add(&lista, 2);
    add(&lista, 1);

    cout << "Lista przed reverse: ";
    print(lista);

    reverse(lista);

    cout << "\nLista po reverse: ";
    print(lista);

    return 0;
}
