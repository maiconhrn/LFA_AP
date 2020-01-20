#include <iostream>
#include <fstream>
#include "ap.h"

using namespace std;

int main() {
    try {
        int i, n_estados, n_simbolos_alfabeto, n_simbolos_auxiliares, n_transicoes;
        string palavra_a_validar, nome_estado, estado_inicial;
        char simbolo_alfabeto, simbolo_auxiliar;
        bool continuar;
        AP ap = AP();
        ifstream apDescricao("ap.txt");

        if (!apDescricao.fail()) {
            apDescricao >> n_estados;
            for(i = 0; i < n_estados; i++) {
                apDescricao >> nome_estado;
                ap.add_estado(Estado(nome_estado));
            }

            apDescricao >> n_simbolos_alfabeto;
            for(i = 0; i < n_simbolos_alfabeto; i++) {
                apDescricao >> simbolo_alfabeto;
                ap.add_simbolo_alfabeto(simbolo_alfabeto);
            }

            apDescricao >> estado_inicial;
            ap.define_estado_inicial(estado_inicial);

            apDescricao >> n_simbolos_auxiliares;
            for(i = 0; i < n_simbolos_auxiliares; i++) {
                apDescricao >> simbolo_auxiliar;
                ap.add_simbolo_auxiliar(simbolo_auxiliar);
            }

            apDescricao >> simbolo_auxiliar;
            ap.define_base(simbolo_auxiliar);

            apDescricao >> n_transicoes;
            for(i=0; i<n_transicoes; i++) {
                string de, para, inserir_pilha_string;
                char com, topo_pilha;
                vector<char> inserir_pilha;

                apDescricao >> de;
                apDescricao >> com;
                apDescricao >> topo_pilha;
                apDescricao >> para;
                apDescricao >> inserir_pilha_string;
                copy(inserir_pilha_string.begin(), inserir_pilha_string.end(), back_inserter(inserir_pilha));
                ap.add_transicao(Transicao(Estado(de), com, topo_pilha, inserir_pilha, Estado(para)));
            }

            do {
                cout << "Digite uma palavra para ser validada: ";
                getline(cin, palavra_a_validar);

                try {

                    cout << "A Palavra \"" << palavra_a_validar << "\" eh "
                         << (ap.validar_palavra(palavra_a_validar.length() <= 0 ? "V" : palavra_a_validar)
                            ? "VALIDA" : "INVALIDA") << endl << endl;
                } catch (const char *e) {
                    cout << e << "\n";
                }

                cout << "Deseja testar outra palavra? (0 == NAO, 1 == SIM): ";
                cin >> continuar;

                cin.ignore();
            } while (continuar);
        } else {
            throw "Arquivo \"ap.txt\" no mesmo diretorio do executavel nao encontrado";
        }
    } catch (const char *e) {
        cout << e << endl;
    }

    return 0;
}