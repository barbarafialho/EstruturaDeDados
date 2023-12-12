
#ifndef DUPLAMENTEENCADEADA_H
#define DUPLAMENTEENCADEADA_H

struct no {
    int valor;
    struct no *ant, *prox;
};

class DuplamenteEncadeada {
public:
    DuplamenteEncadeada();
    DuplamenteEncadeada(const DuplamenteEncadeada& orig);
    virtual ~DuplamenteEncadeada();
    no *inicio, *fim, *aux;
    void inserir();
    void listar();
    no* pesquisar(int valor);
    void menu();
    void remover(int valor);
private:

};

#endif 

