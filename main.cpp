#include <iostream>
#include <fstream>
#include "ap.h"
#include "Pilha.h"

using namespace std;

int main() {
    try {
        string palavra_a_validar;
        bool continuar;
        AP ap = AP();
        ifstream apDescricao("ap.txt");


        //COLOCAR INTERPRETACAO DOS DADOS DO TXT AQUI


        if (!apDescricao.fail()) {
            do {
                cout << "Digite uma palavra para ser validada: ";
                getline(cin, palavra_a_validar);

                cout << "A Palavra \"" << palavra_a_validar << "\" eh "
                     << (ap.validar_palavra(palavra_a_validar) ? "VALIDA" : "INVALIDA") << endl << endl;

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