#include <iostream>

#include "Pilha.h"

template<typename T>
Pilha<T>::Pilha() {
    topo = NULL;
}

template<typename T>
void Pilha<T>::push(T data) {
    no<T> *temp;
    temp = new no<T>;
    temp->valor = data;
    temp->prox = topo;
    topo = temp;
}

template<typename T>
void Pilha<T>::pop() {
    if (!is_vazia()) {
        no<T> *temp = topo;
        topo = topo->prox;
        delete temp;
        return;
    }

    cout << "Pilha vazia";
}

template<typename T>
bool Pilha<T>::is_vazia() {
    return topo == NULL;
}

template<typename T>
Pilha<T>::~Pilha() {
    while (topo != NULL) {
        no<T> *temp = topo;
        topo = topo->prox;
        delete temp;
    }
}

template<typename T>
T Pilha<T>::get_topo() {
    if (!is_vazia()) {
        return topo->valor;
    }

    cout << "Pilha vazia" << endl;

    return NULL;
}
