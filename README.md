# Estrutura de Dados e Algoritmos 📚

O objetivo deste repositório é registrar meus estudos para a matéria de Estrutura de Dados e Algoritmos. Como base estou utilizando a playlist do canal [Programação Descomplicada](https://www.youtube.com/watch?v=bryesHll0vY&list=PL8iN9FQ7_jt6H5m4Gm0H89sybzR9yaaka&index=1) e utilizando a linguagem de programação C para facilitar o entendimento.

## Conteúdos das Aulas 🔎

1. [Aula 01 - TAD (Tipo Abstrato de Dado)](#tad-tipo-abstrato-de-dado)
2. [Aula 02 - Modularização e TAD](#modularização-e-tad)

## TAD (Tipo Abstrato de Dado)

Conceituando:

- **Tipo de dado**: define o conjunto de valores (domínio) que uma variável pode assumir.
- **Estrutura de dados**: trata-se de um relacionamento lógico entre os dados. Em C utiliza-se _struct_.

Em um TAD, devemos incluir as operações para manipulação dos dados tais como:

1. Criação da estrutura
2. Inclusão de um elemento
3. Remoção de um elemento
4. Acesso a um elemento
5. Outras opções

Utilizar TAD traz vantagens ao software como:

1. **Encapsulamento e Segurança**: usuário não tem acesso direto aos dados.
2. **Flexibilidade e Reutilização**: podemos alterar o TAD sem alterar as aplicações que o utilizam.

## Modularização e TAD

A convenção em linguagem C é preparar 2 arquivos para implementar um TAD:

- Arquivo **.H**: para protótipos das funções, tipos de ponteiros, e dados globalmente acessíveis.
- Arquivo **.C**: para declaração dos tipos de dados e implementação das suas funções.

Dessa forma é separado o conceito da implementação. [Veja o exemplo prático da aula!](./aula02/aula02.md)

## Listas

É uma estrutura que armazena uma sequência de elementos do mesmo tipo. Seus elementos possuem estrutura interna abstraída, ou seja, sua complexidade é arbitrária e não afeta o seu funcionamento.

Uma lista pode possuir N elementos e, se N = 0, consideramos que a lista está vazia.

Aplicações:

- Cadastro de funcionários
- Itens em estoque
- Cartas de baralho
- Outras opções

As operações na lista dependem do tipo de alocação de memória usada:

1. **Estática**:

- O espaço de memória é alocado no momento da compilação.
- Exige a definição do número máximo de elementos da lista.
- Acesso sequencial: elementos consecutivos na memória.

[Veja a implementação!](./aula03/lista-estatica/)

2. **Dinâmica**:

- O espaço de memória é alocado em tempo de execução.
- A lista cresce a medida que elementos são inseridos e vice-versa.
- Acesso encadeado: cada elemento pode estar em uma área distinta da memória. Para acessar um elemento, é preciso percorrer todos os antecessores na lista.

[Veja a implementação!](./aula03/lista-dinamica/)
