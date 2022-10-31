//
// Created by raito on 26/10/2022.
//

#ifndef TP_2_EDA_GRAFOA_H
#define TP_2_EDA_GRAFOA_H
#define N 50
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int tamanhoLista,tamMax,chave;
    struct Vertice* listaAdjacencia;
}Vertice;

typedef struct GrafoA{
    int numVertices,tamMax;
    Vertice** listaVertices;
}GrafoA;

GrafoA* iniciaGrafo(int maxSize);
Vertice* iniciaVertice(int maxVizinhos, int chave);
int adicionarVertice(GrafoA* grafo);
int inserirAresta(GrafoA* grafo, int origem,int destino);
void imprimirGrafo(GrafoA* grafo);
int removerAresta(GrafoA* grafo,int origem,int destino);
void removerVertice(GrafoA* grafo, int vertice);
int removerTodasArestasA(GrafoA* grafo);
GrafoA* inicializaGrafoAArquivo(char *filename);



#endif //TP_2_EDA_GRAFOA_H
