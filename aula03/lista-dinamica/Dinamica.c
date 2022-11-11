#include <stdlib.h>
#include "Dinamica.h"

struct elemento {
  struct aluno dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista() {
  Lista* li = (Lista*) malloc(sizeof(Lista));
  if (li != NULL)
    *li = NULL;
  return li;
}

void libera_lista(Lista* li) {
  if (li != NULL) {
    Elem* no;
    while ((*li) != NULL) {
      no = *li;
      *li = (*li) -> prox;
      free(no);
    }
    free(li);
  }
}

int tamanho_lista(Lista* li) {
  if (li == NULL) return 0;
  int cont = 0;
  Elem* no = *li;
  while (no != NULL) {
    cont++;
    no = no -> prox;
  }
  return cont;
}

int lista_esta_vazia(Lista* li) {
  if (li == NULL || *li == NULL) return 1;
  return 0;
}

int inserir_inicio_lista(Lista* li, struct aluno al) {
  if (li == NULL) return 0;
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return 0;
  no -> dados = al;
  no -> prox = *li;
  *li = no;
  return 1;
}

int inserir_final_lista(Lista* li, struct aluno al) {
  if (li == NULL) return 0;
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return 0;
  no -> dados = al;
  // Define o próximo como NULL
  no -> prox = NULL;

  if ((*li) == NULL) { // Lista está vazia
    (*li) = no;
  } else {
    // Cria um nó auxiliar para iterar a lista
    Elem* aux = *li;
    while (aux -> prox != NULL) {
      aux = aux -> prox;
    }
    aux -> prox = no;
  }

  return 1;
}

int inserir_ordenado_lista(Lista* li, struct aluno al) {
  if (li == NULL) return 0;
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return 0;
  no -> dados = al;
  if ((*li) == NULL) { // Lista está vazia
    inserir_inicio_lista(*li, no -> dados);
  } else {
    // Cria um nó auxiliar para iterar a lista
    Elem* atual = *li, *anterior;
    while (atual -> prox != NULL && atual -> dados.matricula <= no -> dados.matricula) {
      anterior = atual;
      atual = atual -> prox;
    }
    if (atual == (*li)) { // Insere no início
      no -> prox = (*li);
      *li = no;
    } else { // insere no meio ou no final
      no -> prox = anterior -> prox;
      anterior -> prox = no;
    }
  }
  return 1;
}

int remover_inicio_lista(Lista* li) {
  if (li == NULL || (*li) == NULL) return 0;
  Elem* no = *li;
  *li = no -> prox;
  free(no);
  return 1;
}

int remover_final_lista(Lista* li) {
  if (li == NULL || (*li) == NULL) return 0;
  Elem* no = *li, *ant;
  while (no -> prox != NULL) {
    ant = no;
    no = no -> prox;
  }
  if (no == (*li)) // Remove o primeiro elemento
    *li = no -> prox;
  else // Remove o último
    ant -> prox = no -> prox;
  free(no);
  return 1;
}

int remover_elemento(Lista* li, int matricula) {
  if (li == NULL || (*li) == NULL) return 0;
  Elem *ant, *no = *li;
  while (no -> prox != NULL && no -> dados.matricula != matricula) {
    ant = no;
    no = no -> prox;
  }
  
  if (no == NULL) return 0; // Elemento não encontrado

  if (no == *li) // Remove o primeiro
    *li = no -> prox;
  else // Remove o último
    ant -> prox = no -> prox;
  free(no);
  return 1;
}

int buscar_elemento(Lista *li, int matricula, struct aluno* al) {
  if (li == NULL || (*li) == NULL) return 0;
  Elem* no = *li;
  while (no != NULL && no -> dados.matricula != matricula) {
    no = no -> prox;
  }

  // Elemento não encontrado
  if (no == NULL) return 0;
  else {
    *al = no -> dados;
    return 1;
  }
}