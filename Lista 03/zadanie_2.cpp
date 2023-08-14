#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 3
// Zadanie 2

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

void release(Link **phead)
{
    Link *head = *phead;
    if (head == nullptr)
        return;

    Link *tmp = head;
    head = head->next;
    delete tmp;

    *phead = nullptr;
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

    cout << "Rozmiar listy przed release: " << size(lista) << endl;

    release(&lista);

    cout << "Rozmiar listy po release: " << size(lista) << endl;

    return 0;
}
