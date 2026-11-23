
#ifndef BUSCA_H
#define BUSCA_H

#include "grafo.h"

// Busca em profundidade
void executarDFS(Grafo *g, int origem, int destino, int procurarDestino);

// Busca em largura
void executarBFS(Grafo *g, int origem, int destino, int procurarDestino);

#endif
