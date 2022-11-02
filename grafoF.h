//
// Created by raito on 29/10/2022.
//

#ifndef TP_2_EDA_GRAFOF_H
#define TP_2_EDA_GRAFOF_H
#define N 50
#include <stdio.h>
#include <stdlib.h>



typedef struct ArestaF{
    int chave;
    struct ArestaF *inicio,*proximo,*fim,*anterior; //Referentes aos vértices
}ArestaF;

typedef struct VerticeF{
    int chave;
    struct VerticeF *inicio,*proximo,*fim,*anterior; //Referentes ao grafo
    struct ArestaF *arestaInicio,*arestaProxima,*arestaFim,*arestaAnterior;
}VerticeF;

typedef struct GrafoF{
    VerticeF* inicio;
    VerticeF* fim;
    VerticeF* proximo;
    VerticeF* anterior;
}GrafoF;

VerticeF* inicializaVerticeF(int chave);
GrafoF* inicializaGrafoF();

void adicionaVerticeGrafoF(GrafoF* grafo, int chave);
void adicionarArestaGrafoF(GrafoF* grafo, int chaveA,int chaveB);

void imprimeGrafoF(GrafoF* grafo);
void imprimeVerticeF(VerticeF* vertice);

int removerArestaF(GrafoF* grafo,int chaveA,int chaveB);
void removerVerticeF(GrafoF* grafo,int chaveA);

int removerTodasArestasF(GrafoF* grafo);
GrafoF* inicializaGrafoFArquivo(char *filename,int num);

int verificaEuleriano(GrafoF* grafo);
int geraCaminhoEuleriano(GrafoF* grafo);
int verificaTodosVertices(int* vetor, int n);

#endif //TP_2_EDA_GRAFOF_H
