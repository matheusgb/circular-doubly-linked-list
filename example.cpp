#include <iostream>
#include "CircularDoublyLinkedList.h"

int main() {
    CircularDoublyLinkedList<int> list;

    list.Enqueue(10);
    list.Enqueue(20);
    list.Enqueue(30);

    std::cout << "Valores ";
    list.Display();

    int removedValue = list.Dequeue();
    std::cout << "Removido: " << removedValue << std::endl;

    std::cout << "Valores após Dequeue: ";
    list.Display();

    return 0;
}
