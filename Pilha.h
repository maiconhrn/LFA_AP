//
// Created by Maicon on 14/01/2020.
//

#ifndef AP_PILHA_H
#define AP_PILHA_H

#include <iostream>

using namespace std;

// pilha é uma lista ligada por nos, cada no tem uma referencia pra proximo da lista
template<typename T>
struct no {
    T valor;
    no *prox;
};

// pilha é uma lista ligada por nos
template<typename T>
class Pilha {
    no<T> *topo;

public:
    Pilha();

    void push(T data);

    void pop();

    bool is_vazia();

    T get_topo();

    ~Pilha();
};

template
class Pilha<string>;

template
class Pilha<char>;

#endif //AP_PILHA_H
