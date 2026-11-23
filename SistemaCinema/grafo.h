
#ifndef GRAFO_H
#define GRAFO_H

#define TOTAL_VERTICES 11

// Tipos de vertices
typedef enum {
    USUARIO,
    FILME,
    ATOR,
    DIRETOR
} TipoVertice;

// Tipos de relacionamentos
typedef enum {
    NENHUMA,
    AVALIOU,
    ATUOU_EM,
    DIRIGIU
} TipoRelacao;

// Estrutura de um vertice
typedef struct {
    char id[5];
    char nome[100];
    TipoVertice tipo;
} Vertice;

// Estrutura principal do grafo
typedef struct {
    Vertice vertices[TOTAL_VERTICES];

    int matriz[TOTAL_VERTICES][TOTAL_VERTICES];
    int pesos[TOTAL_VERTICES][TOTAL_VERTICES];

    TipoRelacao relacoes[TOTAL_VERTICES][TOTAL_VERTICES];

} Grafo;

// Funcoes do modulo grafo
void inicializarGrafo(Grafo *g);

void exibirVertices(Grafo *g);

void exibirArestas(Grafo *g);

int buscarVertice(Grafo *g, char id[]);

const char* nomeTipo(TipoVertice tipo);

const char* nomeRelacao(TipoRelacao relacao);

#endif
