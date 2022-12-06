typedef struct lista Lista;

Lista* cria_lista();

Lista *inserir_inicio(Lista *l, int valor);
Lista *inserir_final(Lista *l, int valor);

void imprime(Lista *l);

Lista *busca(Lista *l, int valor);

Lista *remover(Lista *l, int valor);