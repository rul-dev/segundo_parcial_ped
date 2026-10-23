#include <iostream>
#include <stack>
#include <queue>

void RemoveConsecutiveDuplicates(std::stack<int> &pila)
{
    std::stack<int> tempStack;

    // Transferir el primer elemento de la pila original a la pila temporal si no está vacía
    if (!pila.empty())
    {
        tempStack.push(pila.top());
        pila.pop();
    }

    // Procesar los elementos de la pila original
    while (!pila.empty())
    {
        int current = pila.top();
        pila.pop();

        if (tempStack.empty() || current != tempStack.top())
        {
            tempStack.push(current);
        }
    }

    // Transferir los elementos del stack temporal de vuelta
    while (!tempStack.empty())
    {
        pila.push(tempStack.top());
        tempStack.pop();
    }
}

void SeparateRequests(std::queue<int> &requests, std::queue<int> &priority)
{
    std::queue<int> tempQueue;

    // Procesar los elementos de la cola original
    while (!requests.empty())
    {
        int current = requests.front();
        requests.pop();

        if (current % 3 == 0)
        {
            priority.push(current);
        }
        else
        {
            tempQueue.push(current);
        }
    }

    // Transferir los elementos de vuelta a requests para mantener el orden original
    while (!tempQueue.empty())
    {
        requests.push(tempQueue.front());
        tempQueue.pop();
    }
}

int main()
{
    std::stack<int> pila;
    std::queue<int> requests;
    std::queue<int> priority;
    pila.push(2);
    pila.push(2);
    pila.push(7);
    pila.push(7);
    pila.push(3);
    pila.push(8);
    pila.push(8);
    pila.push(5);
    pila.push(5);
    pila.push(5);

    std::cout << "Pila inicial: ";
    std::stack<int> pilaCopia = pila;
    while (!pilaCopia.empty())
    {
        std::cout << pilaCopia.top() << " ";
        pilaCopia.pop();
    }
    std::cout << std::endl;

    RemoveConsecutiveDuplicates(pila);

    std::cout << "Pila después de eliminar duplicados consecutivos: ";
    while (!pila.empty())
    {
        std::cout << pila.top() << " ";
        pila.pop();
    }
    std::cout << std::endl;

    requests.push(4);
    requests.push(6);
    requests.push(9);
    requests.push(2);
    requests.push(12);
    requests.push(5);
    requests.push(7);
    requests.push(3);

    SeparateRequests(requests, priority);

    std::cout << "Cola de solicitudes: ";
    while (!requests.empty())
    {
        std::cout << requests.front() << " ";
        requests.pop();
    }

    std::cout << std::endl;

    std::cout << "Cola de prioridad (múltiplos de 3): ";
    while (!priority.empty())
    {
        std::cout << priority.front() << " ";
        priority.pop();
    }
    std::cout << std::endl;

    return 0;
}