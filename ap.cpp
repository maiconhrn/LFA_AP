//
// Created by Maicon on 14/01/2020.
//

#include <iostream>
#include "ap.h"
#include "Pilha.h"

bool AP::validar_palavra(const string &palavra) {
    Estado atual = inicial;
    Pilha<char> pilha = Pilha<char>();
    pilha.push(base);

    for (const char &i : palavra) {
        if (existe_transicao(atual, i, pilha.get_topo())) {
            Transicao t = get_transicao(atual, i, pilha.get_topo());
            atual = t.para;
            pilha.pop();
            for (const char &s : t.inserir_pilha) {
                pilha.push(s);
            }
        } else {
            return false;
        }
    }

    return pilha.is_vazia();
}

AP::AP() {
    estados = vector<Estado>();
    alfabeto = Alfabeto();
    transicoes = vector<Transicao>();
    simbulos_auxiliares = vector<char>();
}

Transicao AP::get_transicao(const Estado &de, char com, char topo_pilha) {
    for (const Transicao &t : transicoes) {
        if (t.de == de && t.com == com && t.topo_pilha == topo_pilha) {
            return t;
        }
    }

    return Transicao();
}

bool AP::existe_transicao(const Estado &de, char com, char top_pilha) {
    return get_transicao(de, com, top_pilha) != Transicao();
}

Alfabeto::Alfabeto() {
    simbolos = vector<char>();
}

Estado::Estado() {
    tipo = NENHUM;
}

Estado::Estado(const string &nome) : nome(nome) {
    tipo = NENHUM;
}

bool Estado::operator==(const Estado &rhs) const {
    return nome == rhs.nome &&
           tipo == rhs.tipo;
}

bool Estado::operator!=(const Estado &rhs) const {
    return !(rhs == *this);
}

Transicao::Transicao() {}

Transicao::Transicao(const Estado &de, char com, char topoPilha, const vector<char> &inserirPilha, const Estado &para)
        : de(de), com(com), topo_pilha(topoPilha), inserir_pilha(inserirPilha), para(para) {}

bool Transicao::operator==(const Transicao &rhs) const {
    return de == rhs.de &&
           com == rhs.com &&
           topo_pilha == rhs.topo_pilha &&
           inserir_pilha == rhs.inserir_pilha &&
           para == rhs.para;
}

bool Transicao::operator!=(const Transicao &rhs) const {
    return !(rhs == *this);
}
