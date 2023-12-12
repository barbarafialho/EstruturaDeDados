#include "Pilha.h"
#include <iostream>
using namespace std;

Pilha::Pilha() {
    this->topo = NULL;
    this->aux = NULL;
}

Pilha::Pilha(const Pilha& orig) {
}

Pilha::~Pilha() {
}

void Pilha::menu() {
    int opc, valor;
    do {
        cout << "MENU" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Listar" << endl;
        cout << "4 - Pesquisar" << endl;
        cout << "5 - Listagem recursiva" << endl;
        cout << "0 - Sair" << endl;
        cin >> opc;

        switch (opc) {
            case 1:
                this->inserir();
                break;
            case 2:
                this->remover();
                break;
            case 3:
                this->listar();
                break;
            case 4:
                cout << "Digite um valor a ser pesquisado: ";
                cin >> valor;
                if(this->pesquisar(valor))
                    cout << "Valor já existe.\n";
                break;
            case 5:
                this->percorrerPilhaR(this->topo);
            default:
                break;
        }

    } while (opc != 0);
}

void Pilha::inserir() { //PUSH
    int valor;
    cout << "Digite um valor para inserir na pilha: ";
    cin >> valor;
    this->aux = (struct no*) malloc(sizeof (this->aux)); 
    this->aux->valor = valor; 
    this->aux->ant = NULL;
    this->aux->ant = this->topo;
    this->topo = this->aux;
}

void Pilha::listar() {
    this->aux = this->topo;
    cout << "Listagem" << endl;
    while (this->aux != NULL) {
        cout << this->aux->valor << "\t";
        this->aux = this->aux->ant;
    }
    cout << endl;
}

bool Pilha::pesquisar(int valorPesquisa) {
    for (this->aux = this->topo; this->aux != NULL; this->aux = this->aux->ant) {
        if (valorPesquisa == this->aux->valor)
            return true;
    }
    return false; //retorna true se o valor existe na pilha e false se não existe
}

void Pilha::remover() { //POP
    this->aux = this->topo;
    this->topo = this->aux->ant;
    free(aux);
}

no* Pilha::percorrerPilhaR(no* aux) {
    if (aux != NULL) {
        cout << aux->valor;
        
        this->percorrerPilhaR(aux->ant);
    }
    return aux;  //listar de forma recursiva
}
