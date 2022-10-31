//
// Created by raito on 29/10/2022.
//

#ifndef TP_2_EDA_GRAFOE_H
#define TP_2_EDA_GRAFOE_H
#define N 50
#include <stdio.h>
#include <stdlib.h>



typedef struct ArestaE{
    int chave;
    struct ArestaE *inicio,*proximo,*fim; //Referentes aos vértices
}ArestaE;

typedef struct VerticeE{
    int chave;
    struct VerticeE *inicio,*proximo,*fim; //Referentes ao grafo
    struct ArestaE *arestaInicio,*arestaProxima,*arestaFim;
}VerticeE;

typedef struct GrafoE{
    VerticeE* inicio;
    VerticeE* fim;
    VerticeE* proximo;
}GrafoE;

VerticeE* inicializaVerticeE(int chave);
GrafoE* inicializaGrafoE();

void adicionaVerticeGrafoE(GrafoE* grafo, int chave);
void adicionarArestaGrafoE(GrafoE* grafo, int chaveA,int chaveB);

void imprimeGrafoE(GrafoE* grafo);
void imprimeVerticeE(VerticeE* vertice);

int removerArestaE(GrafoE* grafo,int chaveA,int chaveB);
void removerVerticeE(GrafoE* grafo,int chaveA);

int removerTodasArestasE(GrafoE* grafo);

GrafoE* inicializaGrafoEArquivo(char *filename);

#endif //TP_2_EDA_GRAFOE_H
