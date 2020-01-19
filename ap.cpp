//
// Created by Maicon on 14/01/2020.
//

#include <iostream>
#include "ap.h"
#include "Pilha.h"

bool AP::validar_palavra(const string &palavra)
{
    Estado atual = inicial;
    Pilha<char> pilha = Pilha<char>();
    pilha.push(base);

    for (const char &i : palavra)
    {
        Transicao t = get_transicao(atual, i, pilha.get_topo());
        atual = t.para;
        pilha.pop();
        for (const char &s : t.inserir_pilha)
        {
            if (s != 'V')
            {
                pilha.push(s);
            }
        }
    }
    return pilha.is_vazia();
}

AP::AP()
{
    estados = vector<Estado>();
    alfabeto = Alfabeto();
    transicoes = vector<Transicao>();
    simbolos_auxiliares = vector<char>();
}

Transicao AP::get_transicao(const Estado &de, char com, char topo_pilha)
{
    for (const Transicao &t : transicoes)
    {
        if (t.de.nome.compare(de.nome) == 0 && t.com == com && t.topo_pilha == topo_pilha)
        {
            return t;
        }
    }
    throw "INVALIDA";
}

bool AP::define_estado_inicial(string nome_estado)
{

    if (existe_estado(nome_estado))
    {
        Estado &e = achar_estado(nome_estado);
        e.tipo = INICIAL;
        inicial = e;

        return true;
    }

    throw "Estado definido como inicial não esta na lista de estado";
}

Estado &AP::achar_estado(string nome_estado)
{
    for (Estado &e : estados)
    {
        if (e.nome == nome_estado)
        {
            return e;
        }
    }

    throw "Estado não encontrado";
}

bool AP::add_transicao(Transicao transicao)
{
    transicoes.push_back(transicao);
    return true;
}

bool AP::define_base(char simbolo)
{
    if (existe_simbolo_auxiliar(simbolo))
    {
        base = simbolo;
        return true;
    }
    throw "Simbolo base da pilha nao foi definido";
}

bool AP::existe_estado(string nome_estado)
{
    for (Estado e : estados)
    {
        if (e.nome == nome_estado)
        {
            return true;
        }
    }
    return false;
}

bool AP::add_estado(Estado estado)
{
    if (!existe_estado(estado.nome))
    {
        estados.push_back(estado);
        return true;
    }
    return false;
}

bool AP::existe_simbolo_alfabeto(char simbolo)
{
    for (int i = 0; i < alfabeto.simbolos.size(); i++)
    {
        if (alfabeto.simbolos[i] == simbolo)
            return true;
    }
    return false;
}

bool AP::add_simbolo_alfabeto(char simbolo)
{
    if (!existe_simbolo_alfabeto(simbolo))
    {
        alfabeto.simbolos.push_back(simbolo);
        return true;
    }
    return false;
}

bool AP::existe_simbolo_auxiliar(char simbolo)
{
    for (int i = 0; i < simbolos_auxiliares.size(); i++)
    {
        if (simbolos_auxiliares[i] == simbolo)
            return true;
    }
    return false;
}

bool AP::add_simbolo_auxiliar(char simbolo_auxiliar)
{
    if (!existe_simbolo_auxiliar(simbolo_auxiliar))
    {
        simbolos_auxiliares.push_back(simbolo_auxiliar);
        return true;
    }
    return false;
}

Alfabeto::Alfabeto()
{
    simbolos = vector<char>();
}

Estado::Estado()
{
    tipo = NENHUM;
}

Estado::Estado(const string &nome) : nome(nome)
{
    tipo = NENHUM;
}

bool Estado::operator==(const Estado &rhs) const
{
    return nome == rhs.nome &&
           tipo == rhs.tipo;
}

bool Estado::operator!=(const Estado &rhs) const
{
    return !(rhs == *this);
}

Transicao::Transicao() {}

Transicao::Transicao(const Estado &de, char com, char topoPilha, const vector<char> &inserirPilha, const Estado &para)
    : de(de), com(com), topo_pilha(topoPilha), inserir_pilha(inserirPilha), para(para) {}

bool Transicao::operator==(const Transicao &rhs) const
{
    return de == rhs.de &&
           com == rhs.com &&
           topo_pilha == rhs.topo_pilha &&
           inserir_pilha == rhs.inserir_pilha &&
           para == rhs.para;
}

bool Transicao::operator!=(const Transicao &rhs) const
{
    return !(rhs == *this);
}

void AP::imprimir_transicoes()
{
    for (int i = 0; i < transicoes.size(); i++)
    {
        cout << "De: " << transicoes[i].de.nome << "\n";
        cout << "Com: " << transicoes[i].com << "\n";
        cout << "Topo pilha: " << transicoes[i].topo_pilha << "\n";
        cout << "Para: " << transicoes[i].para.nome << "\n";
    }
}
