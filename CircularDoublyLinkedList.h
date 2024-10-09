#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
};

template <typename T>
class CircularDoublyLinkedList {
public:
    CircularDoublyLinkedList();
    void Enqueue(T value);
    T Dequeue();
    void Display();

private:
    Node<T>* head;
    Node<T>* tail; 
    int size;
};

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
void CircularDoublyLinkedList<T>::Enqueue(T value) {
    Node<T>* newNode = new Node<T>{ value, nullptr, nullptr };

    if (size == 0) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
T CircularDoublyLinkedList<T>::Dequeue() {
    if (size == 0) {
        std::cout << "A fila está vazia\n";
        return T();
    }

    T value = head->value;
    Node<T>* removedValue = head;

    if (size == 1) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    size--;

    delete removedValue;
    return value;
}

template <typename T>
void CircularDoublyLinkedList<T>::Display() {
    if (size == 0) {
        std::cout << "A fila está vazia\n";
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < size; i++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
