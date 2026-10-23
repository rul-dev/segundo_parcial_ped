#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void Insert(Node *&head, int data)
{
    Node *new_node = new Node{data, nullptr, nullptr};

    // Si esto ocurre es porque la lista esta vacia
    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    // Pero esto pasa si acaso no esta vacia
    Node *current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}

void ReverseList(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        // Intercambiar los punteros next y prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Mover al siguiente nodo (que ahora es el anterior)
        current = current->prev;
    }

    // Ajustar el puntero head al nuevo primer nodo
    if (temp != nullptr)
    {
        head = temp->prev;
    }
}

void Print(Node *head)
{
    Node *current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << '\n';
}

void SwapAdjacentPairs(Node *&head)
{

    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr && current->next != nullptr)
    {
        temp = current->next;
        current->next = temp->next;
        temp->prev = current->prev;

        if (current->prev != nullptr)
        {
            current->prev->next = temp;
        }
        else
        {
            head = temp; // Actualizar el head si estamos en el primer par
        }

        if (current->next != nullptr)
        {
            current->next->prev = current;
        }

        temp->next = current;
        current->prev = temp;

        // Mover al siguiente par
        current = current->next;
    }
}

int main()
{
    Node *lista1 = nullptr;

    Insert(lista1, 10);
    Insert(lista1, 20);
    Insert(lista1, 30);
    Insert(lista1, 40);

    std::cout << "Lista original: ";
    Print(lista1);

    std::cout << "Lista invertida: ";
    ReverseList(lista1);
    Print(lista1);

    //Revierto de nuevo la lista para que quede como estaba al principio
    ReverseList(lista1);

    std::cout << "Lista original: ";
    Print(lista1);
    
    std::cout << "Lista con pares intercambiados: ";
    SwapAdjacentPairs(lista1);
    Print(lista1);

    return 0;
}