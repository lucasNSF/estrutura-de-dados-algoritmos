// Definindo a estrutura "Ponto"
typedef struct ponto Ponto;

// Cria um novo ponto
Ponto* pto_cria(float x, float y);
// Libera um ponto
void pto_libera(Ponto* p);
// Acessa os valores X e Y de um ponto
void pto_acessa(Ponto* p, float* x, float* y);
// Atribui os valores X e Y a um ponto
void pto_atribui(Ponto* p, float x, float y);
// Calcula a distância entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2);