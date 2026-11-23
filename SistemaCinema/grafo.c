
#include <stdio.h>
#include <string.h>
#include "grafo.h"

// Inicializa os vertices e as arestas
void inicializarGrafo(Grafo *g) {

    Vertice lista[] = {
        {"V1", "Jose", USUARIO},
        {"V2", "Ana", USUARIO},
        {"F1", "Matrix", FILME},
        {"F2", "Interestelar", FILME},
        {"F3", "Duna", FILME},
        {"A1", "Keanu Reeves", ATOR},
        {"A2", "Matthew McConaughey", ATOR},
        {"A3", "Timothee Chalamet", ATOR},
        {"D1", "Lana Wachowski", DIRETOR},
        {"D2", "Christopher Nolan", DIRETOR},
        {"D3", "Denis Villeneuve", DIRETOR}
    };

    // Cadastra os vertices
    for (int i = 0; i < TOTAL_VERTICES; i++) {
        g->vertices[i] = lista[i];
    }

    // Inicializa as matrizes
    for (int i = 0; i < TOTAL_VERTICES; i++) {
        for (int j = 0; j < TOTAL_VERTICES; j++) {

            g->matriz[i][j] = 0;
            g->pesos[i][j] = 0;
            g->relacoes[i][j] = NENHUMA;

        }
    }

    // Relacoes de Jose
    g->matriz[0][2] = 1;
    g->pesos[0][2] = 5;
    g->relacoes[0][2] = AVALIOU;

    g->matriz[0][3] = 1;
    g->pesos[0][3] = 4;
    g->relacoes[0][3] = AVALIOU;

    // Relacoes de Ana
    g->matriz[1][3] = 1;
    g->pesos[1][3] = 5;
    g->relacoes[1][3] = AVALIOU;

    g->matriz[1][4] = 1;
    g->pesos[1][4] = 4;
    g->relacoes[1][4] = AVALIOU;

    // Matrix: ator e diretora
    g->matriz[2][5] = 1;
    g->pesos[2][5] = 1;
    g->relacoes[2][5] = ATUOU_EM;

    g->matriz[2][8] = 1;
    g->pesos[2][8] = 1;
    g->relacoes[2][8] = DIRIGIU;

    // Interestelar: ator e diretor
    g->matriz[3][6] = 1;
    g->pesos[3][6] = 1;
    g->relacoes[3][6] = ATUOU_EM;

    g->matriz[3][9] = 1;
    g->pesos[3][9] = 1;
    g->relacoes[3][9] = DIRIGIU;

    // Duna: ator e diretor
    g->matriz[4][7] = 1;
    g->pesos[4][7] = 1;
    g->relacoes[4][7] = ATUOU_EM;

    g->matriz[4][10] = 1;
    g->pesos[4][10] = 1;
    g->relacoes[4][10] = DIRIGIU;
}

// Retorna o nome do tipo de vertice
const char* nomeTipo(TipoVertice tipo) {

    switch (tipo) {
        case USUARIO: return "Usuario";
        case FILME: return "Filme";
        case ATOR: return "Ator";
        case DIRETOR: return "Diretor";
        default: return "Desconhecido";
    }
}

// Retorna o nome do relacionamento
const char* nomeRelacao(TipoRelacao relacao) {

    switch (relacao) {
        case AVALIOU: return "Avaliou";
        case ATUOU_EM: return "Atuou em";
        case DIRIGIU: return "Dirigiu";
        default: return "Nenhuma";
    }
}

// Exibe os vertices
void exibirVertices(Grafo *g) {

    printf("\n========== VERTICES DO GRAFO ==========\n");

    for (int i = 0; i < TOTAL_VERTICES; i++) {

        printf("%s - %-25s (%s)\n",
            g->vertices[i].id,
            g->vertices[i].nome,
            nomeTipo(g->vertices[i].tipo)
        );
    }
}

// Exibe as arestas
void exibirArestas(Grafo *g) {

    printf("\n========== ARESTAS DO GRAFO ==========\n");

    for (int i = 0; i < TOTAL_VERTICES; i++) {

        for (int j = 0; j < TOTAL_VERTICES; j++) {

            if (g->matriz[i][j] == 1) {

                printf("%s (%s) -> %s (%s)",
                    g->vertices[i].nome,
                    g->vertices[i].id,
                    g->vertices[j].nome,
                    g->vertices[j].id
                );

                printf(" | Relacao: %s",
                    nomeRelacao(g->relacoes[i][j])
                );

                printf(" | Peso: %d\n",
                    g->pesos[i][j]
                );
            }
        }
    }
}

// Busca um vertice pelo identificador
int buscarVertice(Grafo *g, char id[]) {

    for (int i = 0; i < TOTAL_VERTICES; i++) {

        if (strcmp(g->vertices[i].id, id) == 0) {
            return i;
        }
    }

    return -1;
}
