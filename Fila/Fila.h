#ifndef FILA_H
#define FILA_H
#include <cstdlib>
using namespace std;

struct no{
    int valor;
    struct no *prox;
};

class Fila {
public:
    Fila();
    Fila(const Fila& orig);
    virtual ~Fila();
    no *inicio, *fim, *aux;    
    void menu();
    void inserir();
    void remover();
    void listar(); 
    bool pesquisar(int valorPesquisa);
private:

};

#endif /* FILA_H */

