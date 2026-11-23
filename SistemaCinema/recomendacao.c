
#include <stdio.h>
#include "recomendacao.h"

void recomendarFilmes(Grafo *g, int usuario)
{

    int i, j, k;

    // Guarda a similaridade entre o usuário escolhido
    // e os demais usuários.
    float similaridade[TOTAL_VERTICES] = {0};

    // Identifica os usuários que possuem avaliações em comum.
    for (i = 0; i < TOTAL_VERTICES; i++)
    {

        if (g->vertices[i].tipo != USUARIO || i == usuario)
        {
            continue;
        }

        int filmesEmComum = 0;
        float diferencaNotas = 0;

        for (j = 0; j < TOTAL_VERTICES; j++)
        {

            if (g->vertices[j].tipo != FILME)
            {
                continue;
            }

            // Verifica se os dois usuários avaliaram o mesmo filme.
            if (g->matriz[usuario][j] &&
                g->relacoes[usuario][j] == AVALIOU &&
                g->matriz[i][j] &&
                g->relacoes[i][j] == AVALIOU)
            {

                filmesEmComum++;

                float notaUsuario = g->pesos[usuario][j];
                float notaOutroUsuario = g->pesos[i][j];

                float diferenca = notaUsuario - notaOutroUsuario;

                if (diferenca < 0)
                {
                    diferenca = -diferenca;
                }

                diferencaNotas += diferenca;
            }
        }

        // Quanto menor a diferença entre as notas,
        // maior será a similaridade.
        if (filmesEmComum > 0)
        {
            float mediaDiferenca = diferencaNotas / filmesEmComum;

            similaridade[i] = 1.0f / (1.0f + mediaDiferenca);
        }
    }

    printf("\n========================================\n");
    printf("       RECOMENDACOES DE FILMES\n");
    printf("========================================\n");

    printf("Usuario: %s\n\n", g->vertices[usuario].nome);

    int encontrouRecomendacao = 0;

    // Analisa os filmes que o usuário ainda não avaliou.
    for (j = 0; j < TOTAL_VERTICES; j++)
    {

        if (g->vertices[j].tipo != FILME)
        {
            continue;
        }

        // Não recomenda filmes que o usuário já avaliou.
        if (g->matriz[usuario][j] &&
            g->relacoes[usuario][j] == AVALIOU)
        {
            continue;
        }

        float somaNotas = 0;
        float somaSimilaridades = 0;

        // Procura avaliações desse filme feitas por
        // usuários semelhantes.
        for (i = 0; i < TOTAL_VERTICES; i++)
        {

            if (similaridade[i] <= 0)
            {
                continue;
            }

            if (g->matriz[i][j] &&
                g->relacoes[i][j] == AVALIOU)
            {

                float nota = g->pesos[i][j];

                somaNotas += nota * similaridade[i];
                somaSimilaridades += similaridade[i];
            }
        }

        // Calcula a nota prevista para o filme.
        if (somaSimilaridades > 0)
        {

            float notaPrevista = somaNotas / somaSimilaridades;

            printf("Filme recomendado: %s\n",
                   g->vertices[j].nome);

            printf("Nota prevista: %.2f\n", notaPrevista);

            printf("----------------------------------------\n");

            encontrouRecomendacao = 1;
        }
    }

    if (!encontrouRecomendacao)
    {
        printf("Nenhuma recomendacao encontrada.\n");
        printf("Nao ha usuarios semelhantes com avaliacoes "
               "de filmes ainda nao vistos.\n");
    }
}
