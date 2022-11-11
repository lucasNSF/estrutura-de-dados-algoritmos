struct aluno {
  int matricula;
  char nome[30];
  float n1, n2, n3;
};
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);

int tamanho_lista(Lista* li);
int lista_esta_vazia(Lista* li);

int inserir_inicio_lista(Lista* li, struct aluno al);
int inserir_final_lista(Lista* li, struct aluno al);
int inserir_ordenado_lista(Lista* li, struct aluno al);

int remover_inicio_lista(Lista* li);
int remover_final_lista(Lista* li);
int remover_elemento(Lista* li, int matricula);

int buscar_elemento(Lista *li, int matricula, struct aluno* al);
