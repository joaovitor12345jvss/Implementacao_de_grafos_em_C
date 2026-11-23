# Sistema de Recomendação de Filmes

Projeto desenvolvido em linguagem C com o objetivo de aplicar conceitos de **Teoria dos Grafos**, utilizando uma estrutura de grafo direcionado e ponderado para representar relações entre usuários, filmes, atores e diretores.

O sistema implementa algoritmos de busca e um mecanismo básico de recomendação de filmes com base na similaridade entre usuários.

## Membros do Grupo
João Vitor Santiago
Gabriel Mohamad
Reinan Morais

## Objetivos do Projeto

- Representar relacionamentos entre usuários, filmes, atores e diretores por meio de um grafo.
- Aplicar estruturas de dados e conceitos de grafos na resolução de um problema prático.
- Implementar algoritmos de busca em profundidade (DFS) e busca em largura (BFS).
- Desenvolver um mecanismo de recomendação de filmes baseado nas avaliações dos usuários.
- Organizar o código utilizando modularização, separando responsabilidades em diferentes arquivos.

## Modelagem do Grafo

O projeto utiliza um **grafo direcionado e ponderado**, representado por uma matriz de adjacência.

Os vértices representam diferentes entidades:

| Tipo | Descrição | Exemplos |
|---|---|---|
| USUARIO | Pessoas que avaliam filmes | José, Ana |
| FILME | Filmes cadastrados | Matrix, Interestelar, Duna |
| ATOR | Atores relacionados aos filmes | Keanu Reeves, Matthew McConaughey |
| DIRETOR | Diretores relacionados aos filmes | Lana Wachowski, Christopher Nolan |

As arestas representam os relacionamentos entre essas entidades:

| Relação | Origem | Destino | Peso |
|---|---|---|---|
| AVALIOU | Usuário | Filme | Nota atribuída |
| ATUOU_EM | Filme | Ator | 1 |
| DIRIGIU | Filme | Diretor | 1 |

O peso das arestas de avaliação representa a nota atribuída pelo usuário ao filme.

## Funcionalidades

### 1. Exibição de vértices
Apresenta todos os vértices cadastrados no grafo, incluindo seus identificadores, nomes e respectivos tipos.

### 2. Exibição de arestas
Apresenta as conexões existentes entre os vértices, identificando a origem, o destino, o tipo de relacionamento e seu peso.

### 3. Busca em Profundidade (DFS)
Implementa o algoritmo Depth-First Search, que percorre o grafo explorando um caminho até seu limite antes de retornar e explorar outras possibilidades.

O algoritmo permite:
- Percorrer os vértices alcançáveis a partir de uma origem.
- Procurar um vértice de destino específico.
- Exibir o percurso realizado.
- Contabilizar vértices visitados e arestas examinadas.

### 4. Busca em Largura (BFS)
Implementa o algoritmo Breadth-First Search, que explora os vértices por níveis, utilizando uma fila para controlar a ordem de visitação.

O algoritmo permite:
- Percorrer os vértices alcançáveis a partir de uma origem.
- Procurar um destino específico.
- Reconstruir o caminho encontrado.
- Identificar caminhos com a menor quantidade de arestas em grafos não ponderados.
- Contabilizar vértices visitados e arestas examinadas.

### 5. Recomendação de filmes
Implementa um mecanismo de recomendação colaborativa baseado na similaridade entre usuários.

O funcionamento ocorre em três etapas:

1. Identifica usuários que avaliaram os mesmos filmes.
2. Calcula a similaridade considerando a diferença entre as notas atribuídas aos filmes em comum.
3. Utiliza as avaliações dos usuários semelhantes para estimar notas de filmes que o usuário ainda não avaliou.

A similaridade é calculada pela fórmula:

\[
S = \frac{1}{1 + D}
\]

Onde **D** representa a diferença média entre as avaliações dos usuários.

A nota prevista de um filme é calculada por uma média ponderada pelas similaridades dos usuários que avaliaram aquele filme.

**Exemplo:** se José e Ana possuem avaliações semelhantes para um filme em comum, o sistema pode utilizar a avaliação de Ana sobre outro filme para recomendar esse título a José.

## Estrutura do Projeto

O código foi organizado em módulos para facilitar a manutenção, a compreensão e a reutilização das funcionalidades.

```text
SistemaCinema/
│
├── main.c
│
├── grafo.h
├── grafo.c
│
├── busca.h
├── busca.c
│
├── recomendacao.h
└── recomendacao.c
```

| Arquivo | Responsabilidade |
|---|---|
| `main.c` | Menu principal e interação com o usuário. |
| `grafo.h` | Declaração das estruturas, tipos e funções do grafo. |
| `grafo.c` | Inicialização, manipulação e exibição do grafo. |
| `busca.h` | Declaração das funções de busca DFS e BFS. |
| `busca.c` | Implementação dos algoritmos DFS e BFS. |
| `recomendacao.h` | Declaração das funções de recomendação. |
| `recomendacao.c` | Implementação do algoritmo de recomendação de filmes. |

## Tecnologias Utilizadas

- **Linguagem:** C
- **Compilador:** GCC
- **Estrutura de dados:** Grafo direcionado e ponderado.
- **Representação do grafo:** Matriz de adjacência.
- **Algoritmos:** DFS, BFS e recomendação colaborativa.
- **Controle de versão:** Git e GitHub.

## Como Compilar e Executar

### Pré-requisitos

- GCC instalado e configurado no PATH.
- Terminal ou ambiente de desenvolvimento compatível com C.
- Arquivos do projeto disponíveis localmente.

### 1. Clonar o repositório

```bash
git clone URL_DO_REPOSITORIO
```

Entre na pasta do projeto:

```bash
cd SistemaCinema
```

### 2. Compilar o projeto

Execute o comando:

```bash
gcc main.c grafo.c busca.c recomendacao.c -o cinema
```

Esse comando compila todos os módulos e gera o executável do sistema.

### 3. Executar o programa

No Windows:

```powershell
.\cinema.exe
```

No Linux:

```bash
./cinema
```

## Menu do Sistema

Ao executar o programa, o usuário terá acesso às seguintes opções:

```text
========================================
       SISTEMA DE RECOMENDACAO
             DE FILMES
========================================
1 - Exibir vertices do grafo
2 - Exibir arestas do grafo
3 - Executar busca em profundidade (DFS)
4 - Executar busca em largura (BFS)
5 - Recomendar filmes
0 - Sair
========================================
Escolha uma opcao:
```

## Dados de Exemplo

O grafo inicial contém 11 vértices e 10 arestas:

**Usuários:**
- José (V1)
- Ana (V2)

**Filmes:**
- Matrix (F1)
- Interestelar (F2)
- Duna (F3)

**Atores:**
- Keanu Reeves (A1)
- Matthew McConaughey (A2)
- Timothée Chalamet (A3)

**Diretores:**
- Lana Wachowski (D1)
- Christopher Nolan (D2)
- Denis Villeneuve (D3)

As avaliações cadastradas permitem demonstrar o funcionamento do algoritmo de recomendação. Por exemplo, o sistema consegue recomendar Duna para José com base na avaliação de Ana.

## Conceitos Aplicados

Durante o desenvolvimento foram aplicados os seguintes conceitos:

- Grafos direcionados e ponderados.
- Vértices e arestas.
- Matriz de adjacência.
- Modularização de código em C.
- Estruturas e enumerações.
- Alocação e manipulação de estruturas.
- Recursividade.
- Busca em Profundidade (DFS).
- Busca em Largura (BFS).
- Filas.
- Similaridade entre usuários.
- Sistemas de recomendação colaborativa.

## Desenvolvimento

Projeto acadêmico desenvolvido como atividade prática de aplicação dos conceitos de grafos e algoritmos em linguagem C.
