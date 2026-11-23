
#include <stdio.h>
#include "busca.h"

// ==========================================
// BUSCA EM PROFUNDIDADE (DFS)
// ==========================================

int dfsRecursivo(
    Grafo *g,
    int atual,
    int destino,
    int procurarDestino,
    int visitado[],
    int ordem[],
    int *qtdVisitados,
    int *arestasPercorridas,
    int caminho[],
    int *tamCaminho,
    int caminhoEncontrado[],
    int *tamCaminhoEncontrado)
{

    // Marca o vertice como visitado
    visitado[atual] = 1;

    // Registra a ordem de visita
    ordem[*qtdVisitados] = atual;
    (*qtdVisitados)++;

    // Adiciona ao caminho atual
    caminho[*tamCaminho] = atual;
    (*tamCaminho)++;

    // Verifica se encontrou o destino
    if (procurarDestino && atual == destino)
    {

        for (int i = 0; i < *tamCaminho; i++)
        {
            caminhoEncontrado[i] = caminho[i];
        }

        *tamCaminhoEncontrado = *tamCaminho;

        return 1;
    }

    // Percorre os vizinhos
    for (int i = 0; i < TOTAL_VERTICES; i++)
    {

        if (g->matriz[atual][i] == 1)
        {

            (*arestasPercorridas)++;

            if (!visitado[i])
            {

                if (dfsRecursivo(
                        g, i, destino, procurarDestino,
                        visitado, ordem, qtdVisitados,
                        arestasPercorridas, caminho,
                        tamCaminho, caminhoEncontrado,
                        tamCaminhoEncontrado))
                {

                    return 1;
                }
            }
        }
    }

    // BACKTRACKING
    (*tamCaminho)--;

    return 0;
}

// Executa o DFS e apresenta os resultados
void executarDFS(Grafo *g, int origem, int destino, int procurarDestino)
{

    int visitado[TOTAL_VERTICES] = {0};

    int ordem[TOTAL_VERTICES];
    int qtdVisitados = 0;

    int arestasPercorridas = 0;

    int caminho[TOTAL_VERTICES];
    int tamCaminho = 0;

    int caminhoEncontrado[TOTAL_VERTICES];
    int tamCaminhoEncontrado = 0;

    int encontrado = dfsRecursivo(
        g, origem, destino, procurarDestino,
        visitado, ordem, &qtdVisitados,
        &arestasPercorridas, caminho,
        &tamCaminho, caminhoEncontrado,
        &tamCaminhoEncontrado);

    printf("\n========== RESULTADO DO DFS ==========\n");

    printf("\nVertice de origem: %s (%s)\n",
           g->vertices[origem].nome,
           g->vertices[origem].id);

    printf("\nOrdem dos vertices visitados:\n");

    for (int i = 0; i < qtdVisitados; i++)
    {

        printf("%s (%s)",
               g->vertices[ordem[i]].nome,
               g->vertices[ordem[i]].id);

        if (i < qtdVisitados - 1)
        {
            printf(" -> ");
        }
    }

    printf("\n\nQuantidade de vertices visitados: %d\n", qtdVisitados);
    printf("Quantidade de arestas percorridas: %d\n", arestasPercorridas);

    if (procurarDestino)
    {

        if (encontrado)
        {

            printf("\nDestino encontrado!\n");
            printf("Caminho encontrado:\n");

            for (int i = 0; i < tamCaminhoEncontrado; i++)
            {

                printf("%s (%s)",
                       g->vertices[caminhoEncontrado[i]].nome,
                       g->vertices[caminhoEncontrado[i]].id);

                if (i < tamCaminhoEncontrado - 1)
                {
                    printf(" -> ");
                }
            }

            printf("\n");
        }
        else
        {

            printf("\nDestino nao encontrado!\n");
        }
    }
    else
    {

        printf("\nBusca concluida sem destino especifico.\n");
    }

    printf("\n======================================\n");
}

// ==========================================
// BUSCA EM LARGURA (BFS)
// ==========================================

void executarBFS(Grafo *g, int origem, int destino, int procurarDestino)
{

    int visitado[TOTAL_VERTICES] = {0};

    // Estrutura da fila
    int fila[TOTAL_VERTICES];
    int inicio = 0;
    int fim = 0;

    int ordem[TOTAL_VERTICES];
    int qtdVisitados = 0;

    // Armazena o predecessor de cada vertice
    int anterior[TOTAL_VERTICES];

    int arestasPercorridas = 0;

    for (int i = 0; i < TOTAL_VERTICES; i++)
    {
        anterior[i] = -1;
    }

    // Adiciona a origem na fila
    fila[fim++] = origem;
    visitado[origem] = 1;

    int encontrado = 0;

    // Enquanto houver elementos na fila
    while (inicio < fim)
    {

        // Retira o primeiro elemento
        int atual = fila[inicio++];

        // Registra a visita
        ordem[qtdVisitados++] = atual;

        // Verifica se chegou ao destino
        if (procurarDestino && atual == destino)
        {
            encontrado = 1;
            break;
        }

        // Percorre os vizinhos
        for (int i = 0; i < TOTAL_VERTICES; i++)
        {

            if (g->matriz[atual][i] == 1)
            {

                arestasPercorridas++;

                if (!visitado[i])
                {

                    visitado[i] = 1;

                    anterior[i] = atual;

                    // Adiciona o vizinho ao final da fila
                    fila[fim++] = i;
                }
            }
        }
    }

    // Apresenta os resultados
    printf("\n========== RESULTADO DO BFS ==========\n");

    printf("\nVertice de origem: %s (%s)\n",
           g->vertices[origem].nome,
           g->vertices[origem].id);

    printf("\nOrdem dos vertices visitados:\n");

    for (int i = 0; i < qtdVisitados; i++)
    {

        printf("%s (%s)",
               g->vertices[ordem[i]].nome,
               g->vertices[ordem[i]].id);

        if (i < qtdVisitados - 1)
        {
            printf(" -> ");
        }
    }

    printf("\n\nQuantidade de vertices visitados: %d\n", qtdVisitados);

    printf("Quantidade de arestas percorridas: %d\n",
           arestasPercorridas);

    // Apresenta o caminho caso exista destino
    if (procurarDestino)
    {

        if (encontrado)
        {

            int caminho[TOTAL_VERTICES];
            int tamanho = 0;

            int atual = destino;

            // Reconstrucao do caminho
            while (atual != -1)
            {

                caminho[tamanho++] = atual;
                atual = anterior[atual];
            }

            printf("\nDestino encontrado!\n");
            printf("Caminho encontrado:\n");

            // Exibe o caminho na ordem correta
            for (int i = tamanho - 1; i >= 0; i--)
            {

                printf("%s (%s)",
                       g->vertices[caminho[i]].nome,
                       g->vertices[caminho[i]].id);

                if (i > 0)
                {
                    printf(" -> ");
                }
            }

            printf("\n");
        }
        else
        {

            printf("\nDestino nao encontrado!\n");
        }
    }
    else
    {

        printf("\nBusca concluida sem destino especifico.\n");
    }

    printf("\n======================================\n");
}
