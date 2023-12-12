#include <iostream>
using namespace std;
#include "DuplamenteEncadeada.h"

DuplamenteEncadeada::DuplamenteEncadeada() {
}

DuplamenteEncadeada::DuplamenteEncadeada(const DuplamenteEncadeada& orig) {
}

DuplamenteEncadeada::~DuplamenteEncadeada() {
}

void DuplamenteEncadeada::inserir() {
    int var;
    cout << "digite um valor para inserir: ";
    cin >> var;
    this->aux = (struct no*) malloc(sizeof (this->aux));
    this->aux->valor = var;
    this->aux->prox = NULL;
    this->aux->ant = NULL;

    if (this->inicio == NULL) {
        this->inicio = this->aux;
        this->fim = this->aux;
    } else {
        this->fim->prox = this->aux;
        this->aux->ant = this->fim;
        this->fim = this->aux;
    }
}

void DuplamenteEncadeada::listar() {
    cout << "Listagem" << endl;
    for (this->aux = this->inicio; this->aux != NULL; this->aux = this->aux->prox)
        cout << this->aux->valor << "\t";
    cout << endl;
}

no* DuplamenteEncadeada::pesquisar(int valor) {
    for (this->aux = this->inicio; this->aux != NULL; this->aux = this->aux->prox) {
        if (valor == this->aux->valor)
            return this->aux;
        return NULL;
    }
}

void DuplamenteEncadeada::remover(int valor) {
    no *aux = NULL;
    aux = this->pesquisar(valor);
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
}

void DuplamenteEncadeada::menu() {
    int opc,valor;
    do {
        cout << "MENU" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Listar" << endl;
        cout << "3 - Remover" << endl;
        cout << "4 - Pesquisar" << endl;
        cout << "0 - Sair" << endl;
        cin >> opc;

        switch (opc) {
            case 1:
                this->inserir();
                break;
            case 2:
                this->listar();
                break;
            case 3:
                cout << "digite o valor que deseja remover: ";
                cin >> valor;
                this->remover(valor);
                break;
            case 4: 
                cout << "digite o valor que deseja pesquisar: ";
                cin >> valor;
                cout << "valor encontrado na posição " << this->pesquisar(valor);
                break;
            default:
                break;
        }
    } while (opc != 0);
}
