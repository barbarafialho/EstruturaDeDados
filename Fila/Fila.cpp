#include "Fila.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Fila::Fila() {
    this->inicio = NULL;
    this->fim = NULL;
    this->aux = NULL;
}

Fila::Fila(const Fila& orig) {

}

Fila::~Fila() {
}

void Fila::menu() {
    int opc, valor;
    do {
        cout << "MENU" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Listar" << endl;
        cout << "4 - Pesquisar" << endl;
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
            default:
                break;
        }

    } while (opc != 0);
}

void Fila::inserir() {
    int valorInserir;
    cout << "Digite um valor para inserir na fila: " << endl;
    cin >> valorInserir;
    
    if (this->pesquisar(valorInserir)==true) {      //se retornar verdadeiro é porque já existe o valor na fila 
        cout << "Valor já existe na lista. \n";     //e não insere o valor que já existe  
    } else {                                        
        this->aux = (struct no*) malloc(sizeof (this->aux));
        this->aux->prox = NULL;
        this->aux->valor = valorInserir;
        if (this->inicio == NULL) {                 //se o inicio for NULL, adiciona o primeiro nó como inicio
            this->inicio = this->aux;
        } else {
            this->fim->prox = this->aux;            //se o inicio já existir, adiciona o nó proxima posicao
        }
        this->fim = this->aux;                      //atualiza o fim com o elemento inserido por ultimo
    }                                                   //armazenado no nó aux

}

void Fila::listar() {
    cout << "Listagem" << endl;
    for (this->aux = this->inicio; this->aux != NULL; this->aux = this->aux->prox)
        cout << this->aux->valor << "\t";
    cout << endl;
}

void Fila::remover() {
    this->aux = this->inicio;
    this->inicio = this->aux->prox;
    free(aux);
}

bool Fila::pesquisar(int valorPesquisa) {
    for (this->aux = this->inicio; this->aux != NULL; this->aux = this->aux->prox) {
        if (valorPesquisa == this->aux->valor) 
            return true;
    }
    return false; //ESSE PESQUISAR VERIFICA SE EXISTE O VALOR NA FILA
                    // SE EXISTIR ELE RETORNA VERDADEIRO, SE NÃO EXISTIR ELE RETORNA FALSO
}
