//
// Created by raito on 27/10/2022.
//

#ifndef TP_2_EDA_GRAFOB_H
#define TP_2_EDA_GRAFOB_H
#define N 100
#define tamMax 100
#include <stdio.h>
#include <stdlib.h>

typedef struct VerticeB{
    int chave,primeiro,ultimo,tamanho,livre;
    int* listaIndices;
    struct VerticeB** lista;
}VerticeB;

typedef struct GrafoB{
    int primeiro,ultimo,tamanho,livre;
    int* listaIndices;
    VerticeB** listaVertices;
}GrafoB;

VerticeB* inicializaVerticeB(int chave);
GrafoB* inicializaGrafoB();
void imprimeGrafoB(GrafoB* grafo);
void imprimeVerticeB(VerticeB* vertice);
void adicionaVerticeGrafoB(GrafoB* grafo, int chave);
int adicionarArestaGrafoB(GrafoB* grafo, int chaveA, int chaveB);
void adicionarVerticeVerticeB(VerticeB* vertice,int chave);
int encontraProximoVazio(int* listaIndice, int tamanho);
int removerArestaGrafoB(GrafoB* grafo, int chaveA, int chaveB);
int removerArestaVerticeB(VerticeB* vertice, int aresta);
int removerVerticeGrafoB(GrafoB* grafo, int chaveA);
int removerTodasArestasB(GrafoB* grafo);
GrafoB* inicializaGrafoBArquivo(char *filename);



#endif //TP_2_EDA_GRAFOB_H
