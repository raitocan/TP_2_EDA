//
// Created by raito on 29/10/2022.
//

#ifndef TP_2_EDA_GRAFOD_H
#define TP_2_EDA_GRAFOD_H

#define N 50
#include <stdio.h>
#include <stdlib.h>



typedef struct ArestaD{
    int chave;
    struct ArestaD *inicio,*proximo; //Referentes aos vértices
}ArestaD;

typedef struct VerticeD{
    int chave;
    struct VerticeD *inicio,*proximo; //Referentes ao grafo
    struct ArestaD *arestaInicio,*arestaProxima;
}VerticeD;

typedef struct GrafoD{
    VerticeD* inicio;
    VerticeD* proximo;
}GrafoD;

VerticeD* inicializaVerticeD(int chave);
GrafoD* inicializaGrafoD();

void adicionaVerticeGrafoD(GrafoD* grafo, int chave);
void adicionarArestaGrafoD(GrafoD* grafo, int chaveA,int chaveB);

void imprimeGrafoD(GrafoD* grafo);
void imprimeVerticeD(VerticeD* vertice);

void removerArestaD(GrafoD* grafo,int chaveA,int chaveB);
void removerVerticeD(GrafoD* grafo,int chaveA);

void removerTodasArestasD(GrafoD* grafo);
GrafoD* inicializaGrafoDArquivo(char *filename);

#endif //TP_2_EDA_GRAFOD_H
