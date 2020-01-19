//
// Created by Maicon on 14/01/2020.
//

#ifndef AP_AP_H
#define AP_AP_H

#include <vector>

using namespace std;

typedef enum {
    NENHUM,
    INICIAL,
} Estado_Tipo;

class Alfabeto {
public:
    vector<char> simbolos;

    Alfabeto();
};

class Estado {
public:
    string nome;
    Estado_Tipo tipo;

    Estado();

    Estado(const string &nome);

    bool operator==(const Estado &rhs) const;

    bool operator!=(const Estado &rhs) const;
};

class Transicao {
public:
    Estado de;
    char com;
    char topo_pilha;
    Estado para;
    vector<char> inserir_pilha;

    Transicao();

    Transicao(const Estado &de, char com, char topoPilha, const vector<char> &inserirPilha, const Estado &para);

    bool operator==(const Transicao &rhs) const;

    bool operator!=(const Transicao &rhs) const;
};

class AP {
private:
    vector<Estado> estados;
    Alfabeto alfabeto;
    vector<Transicao> transicoes;
    Estado inicial;
    char base;
    vector<char> simbolos_auxiliares;

public:
    AP();

    bool existe_estado(string nome_estado);

    bool existe_simbolo_alfabeto(char simbolo);

    bool add_estado(Estado estado);

    bool existe_simbolo_auxiliar(char simbolo_auxiliar);

    bool add_simbolo_auxiliar(char simbolo_auxiliar);

    bool define_estado_inicial(string nome_estado);

    bool define_base(char simbolo);

    Estado &achar_estado(string nome_estado);

    bool add_transicao(Transicao transicao);

    Transicao get_transicao(const Estado& de, char com, char topo_pilha);

    bool validar_palavra(const string& palavra);

    bool add_simbolo_alfabeto(char simbolo);

};

#endif //AP_AP_H
