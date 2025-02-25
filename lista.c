#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node* next;
} node;

typedef struct Lista {
    node* head;   // Ponteiro para o primeiro nó da lista
    int tam;  
} Lista;

// Criando a lista
Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista)); // Aloca memória para a lista
    if (lista == NULL) {
        printf("Erro ao alocar memória para a lista!\n");
        return NULL;
    }
    lista->head = NULL;
    lista->tam = 0;
    return lista;
}


int listaVazia(Lista* lista) {
    return lista->tam == 0;
}

int obterTamanho(Lista* lista) {
    return lista->tam;
}


int obterElemento(Lista* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tam) {
        printf("Posição inválida!\n");
        return -1; // Erro
    }

    node* atual = lista->head;
    for (int i = 1; i < posicao; i++) {  
        atual = atual->next;
    }

    return atual->dado;
}

void modificarElemento(Lista* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tam) {
        printf("Posição inválida!\n");
        return;
    }

    node* atual = lista->head;
    for (int i = 1; i < posicao; i++) {  
        atual = atual->next;
    }

    atual->dado = valor;
}

// Inserir um elemento em uma posição específica
void inserirElemento(Lista* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tam + 1) {  
        printf("Posição inválida!\n");
        return;
    }

    node* novoNode = (node*) malloc(sizeof(node));
    novoNode->dado = valor;

    if (posicao == 1) {
        novoNode->next = lista->head;
        lista->head = novoNode;
    } else {
        node* atual = lista->head;
        for (int i = 1; i < posicao - 1; i++) { 
            atual = atual->next;
        }
        novoNode->next = atual->next;
        atual->next = novoNode;
    }

    lista->tam++;
}

// Retirar um elemento de uma posição escolhida
void removerElemento(Lista* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tam) {
        printf("Posição inválida!\n");
        return;
    }

    node* temp;
    if (posicao == 1) {
        temp = lista->head;
        lista->head = lista->head->next;
    } else {
        node* atual = lista->head;
        for (int i = 1; i < posicao - 1; i++) { 
            atual = atual->next;
        }
        temp = atual->next;
        atual->next = atual->next->next;
    }

    free(temp);
    lista->tam--;
}


// print dos elementos da lista
void imprimirLista(Lista* lista) {
    node* atual = lista->head;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->next;
    }
    printf("NULL\n");
}

int main() {
    // Criação da lista
    Lista* minhaLista = criarLista();

    // Inserir elementos na lista
    printf("Inserindo elementos\n");
    inserirElemento(minhaLista, 1, 10);  // Insere na posição 1
    inserirElemento(minhaLista, 2, 20);  // Insere na posição 2
    inserirElemento(minhaLista, 2, 15);  // Insere na posição 2
    imprimirLista(minhaLista);  // resposta: 10 -> 15 -> 20 -> NULL

    //Modificar o elemento na posição 2
    printf("Modificando o elemento na posição 2 para 25\n");
    modificarElemento(minhaLista, 2, 25);
    imprimirLista(minhaLista);  // resposts: 10 -> 25 -> 20 -> NULL

    // Obter o valor de um elemento
    printf("Elemento na posição 2: %d\n", obterElemento(minhaLista, 2)); 

    // Remover o elemento da posição 2
    printf("Removendo o elemento da posição 2\n");
    removerElemento(minhaLista, 2);
    imprimirLista(minhaLista);  // resposta: 10 -> 20 -> NULL

    // Verificando se a lista está vazia
    printf("A lista está vazia? %s\n", listaVazia(minhaLista) ? "Sim" : "Não");

    // Obtendo o tamanho da lista
    printf("Tamanho da lista: %d\n", obterTamanho(minhaLista)); 

    return 0;
}





