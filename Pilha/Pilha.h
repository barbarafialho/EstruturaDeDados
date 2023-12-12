#ifndef PILHA_H
#define PILHA_H

struct no
{
    int valor;
    struct no *ant;
};

class Pilha {
public:
    Pilha();
    Pilha(const Pilha& orig);
    virtual ~Pilha();
    no *topo, *aux;
    void menu();
    void inserir();
    void listar();
    void remover();
    bool pesquisar(int valorPesquisa);
    no* percorrerPilhaR(no* aux);
private:

};

#endif /* PILHA_H */

