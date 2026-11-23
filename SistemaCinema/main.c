
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "busca.h"
#include "recomendacao.h"

// Exibe as opções disponíveis no sistema.
void exibirMenu()
{
    printf("\n========================================\n");
    printf("       SISTEMA DE RECOMENDACAO\n");
    printf("             DE FILMES\n");
    printf("========================================\n");

    printf("1 - Exibir vertices do grafo\n");
    printf("2 - Exibir arestas do grafo\n");
    printf("3 - Executar busca em profundidade (DFS)\n");
    printf("4 - Executar busca em largura (BFS)\n");
    printf("5 - Recomendar filmes\n");
    printf("0 - Sair\n");

    printf("========================================\n");
    printf("Escolha uma opcao: ");
}

// Solicita um ID e verifica se ele existe no grafo.
int solicitarVertice(Grafo *g, char id[])
{

    printf("Digite o ID do vertice (ex: V1, F1, A1): ");
    scanf("%4s", id);

    int indice = buscarVertice(g, id);

    if (indice == -1)
    {
        printf("\nErro: vertice nao encontrado!\n");
    }

    return indice;
}

// Executa DFS ou BFS conforme a opção escolhida.
void executarBuscaMenu(Grafo *g, int tipoBusca)
{

    char idOrigem[5];
    char idDestino[5];

    // Solicita o vértice de origem.
    int origem = solicitarVertice(g, idOrigem);

    if (origem == -1)
    {
        return;
    }

    // Pergunta se o usuário deseja procurar um destino específico.
    int procurarDestino;

    printf("\nDeseja procurar um destino especifico?\n");
    printf("1 - Sim\n");
    printf("0 - Nao (percorrer o grafo)\n");
    printf("Opcao: ");
    scanf("%d", &procurarDestino);

    int destino = -1;

    if (procurarDestino == 1)
    {

        destino = solicitarVertice(g, idDestino);

        if (destino == -1)
        {
            return;
        }

        if (destino == origem)
        {
            printf("\nOrigem e destino sao iguais.\n");
            return;
        }
    }
    else if (procurarDestino != 0)
    {
        printf("\nOpcao invalida!\n");
        return;
    }

    // Executa o algoritmo selecionado.
    if (tipoBusca == 3)
    {
        executarDFS(g, origem, destino, procurarDestino);
    }
    else if (tipoBusca == 4)
    {
        executarBFS(g, origem, destino, procurarDestino);
    }
}

// Solicita um usuário e apresenta recomendações de filmes.
void executarRecomendacaoMenu(Grafo *g)
{

    char idUsuario[5];

    printf("\n========================================\n");
    printf("       RECOMENDAR FILMES\n");
    printf("========================================\n");

    printf("Digite o ID do usuario (ex: V1): ");
    scanf("%4s", idUsuario);

    int usuario = buscarVertice(g, idUsuario);

    // Verifica se o ID informado existe.
    if (usuario == -1)
    {
        printf("\nErro: usuario nao encontrado!\n");
        return;
    }

    // Verifica se o vértice informado representa um usuário.
    if (g->vertices[usuario].tipo != USUARIO)
    {
        printf("\nErro: o vertice informado nao e um usuario!\n");
        return;
    }

    // Chama o módulo responsável pelas recomendações.
    recomendarFilmes(g, usuario);
}

int main()
{

    // Cria e inicializa a estrutura do grafo.
    Grafo g;
    inicializarGrafo(&g);

    int opcao;

    // Mantém o menu funcionando até o usuário escolher sair.
    do
    {

        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {

        // Exibe todos os vértices cadastrados.
        case 1:
            printf("\n--- VERTICES DO GRAFO ---\n");
            exibirVertices(&g);
            break;

        // Exibe todas as relações entre os vértices.
        case 2:
            printf("\n--- ARESTAS DO GRAFO ---\n");
            exibirArestas(&g);
            break;

        // Executa busca em profundidade.
        case 3:
            printf("\n--- BUSCA EM PROFUNDIDADE (DFS) ---\n");
            executarBuscaMenu(&g, 3);
            break;

        // Executa busca em largura.
        case 4:
            printf("\n--- BUSCA EM LARGURA (BFS) ---\n");
            executarBuscaMenu(&g, 4);
            break;

        // Executa o algoritmo de recomendação.
        case 5:
            executarRecomendacaoMenu(&g);
            break;

        // Encerra o programa.
        case 0:
            printf("\nEncerrando o sistema...\n");
            break;

        // Trata opções inexistentes.
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}
