#include "metodos.h"
#include "stdio.h"
#include "stdlib.h"

struct lista{
    struct lista *ant;
    struct lista *prox;
    int info;
};

Lista* cria_lista() {
    return NULL;
}
Lista *inserir_inicio(Lista *l, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    novo->ant = NULL;

    if (l != NULL) {
        l->ant = novo;
    }
    return novo;
}

Lista *inserir_final(Lista *l, int valor){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    novo->ant = l;

    if (l != NULL) {
        l->prox = novo;
    }
    return novo;
}
void imprime(Lista *l) {
    Lista *aux;
    for(aux = l; aux != NULL; aux = aux->prox) {
        printf("Info = %d\n", aux->info);
    }

}

Lista *busca(Lista *l, int valor) {
    Lista *aux; // auxilia a percorrer a lista
    for(aux = l; aux != NULL; aux = aux->prox) {
        if (aux->info == valor) {
            return aux;
        }
    }
    return NULL; // Valor n~ao encontrado
}


Lista *remover(Lista *l, int valor) {
    Lista *p = busca(l, valor);
    if (p == NULL)
        return l;
    if (l == p)
        l = p->prox;
    else
        p->ant->prox = p->prox;
    if (p->prox != NULL)
        p->prox->ant = p->ant;
    free(p);
    return l;
}