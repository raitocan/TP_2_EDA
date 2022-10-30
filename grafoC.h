//
// Created by raito on 29/10/2022.
//

#ifndef TP_2_EDA_GRAFOC_H
#define TP_2_EDA_GRAFOC_H

#define N 50
#define tamMax 100
#include <stdio.h>
#include <stdlib.h>

typedef struct VerticeC{
    int chave,primeiro,ultimo,tamanho,livre;
    int* listaIndicesProx;
    int* listaIndicesAnterior;
    struct VerticeC** lista;
}VerticeC;

typedef struct GrafoC{
    int primeiro,ultimo,tamanho,livre;
    int* listaIndicesProx;
    int* listaIndicesAnterior;
    VerticeC** listaVertices;
}GrafoC;

VerticeC* inicializaVerticeC(int chave);
GrafoC * inicializaGrafoC();
void imprimeGrafoC(GrafoC* grafo);
void imprimeVerticeC(VerticeC* vertice);
void adicionaVerticeGrafoC(GrafoC* grafo, int chave);
int adicionarArestaGrafoC(GrafoC* grafo, int chaveA, int chaveB);
void adicionarVerticeVerticeC(VerticeC* vertice,VerticeC* chave);
int encontraProximoVazio(int* listaIndice, int tamanho);
int removerArestaGrafoC(GrafoC* grafo, int chaveA, int chaveB);
int removerArestaVerticeC(VerticeC* vertice, int aresta);
int removerVerticeGrafoC(GrafoC* grafo, int chaveA);
void removerTodasArestasC(GrafoC* grafo);

#endif //TP_2_EDA_GRAFOC_H
