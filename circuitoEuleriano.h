//
// Created by raito on 01/11/2022.
//

#ifndef TP_2_EDA_CIRCUITOEULERIANO_H
#define TP_2_EDA_CIRCUITOEULERIANO_H
#include "grafoA.h"
#include "grafoF.h"
#include "grafoE.h"
#include "grafoD.h"
#include "grafoB.h"
#include "grafoC.h"
typedef struct tipoCircuito{
    int chave,tamanho;
    struct tipoCircuito* proximo,*ultimo,*primeiro;
}tipoCircuito;

tipoCircuito* novoCircuito();
void adicionarCircuito( tipoCircuito* A, int chave);
void imprimirCircuito(tipoCircuito* A);
void anexarCircuito( tipoCircuito* A, tipoCircuito* B);

int geraCaminhoEulerianoF(GrafoF* grafo);
VerticeF* getVerticeF(GrafoF* grafo, int chave,int* numOps);
int geraCircuitoF(GrafoF* grafo,VerticeF* inicio);

int geraCaminhoEulerianoE(GrafoE* grafo);
VerticeE* getVerticeE(GrafoE* grafo, int chave,int* numOps);
int geraCircuitoE(GrafoE* grafo,VerticeE* inicio);

int geraCaminhoEulerianoD(GrafoD* grafo);
VerticeD* getVerticeD(GrafoD* grafo, int chave,int* numOps);
int geraCircuitoD(GrafoD* grafo,VerticeD* inicio);

int geraCaminhoEulerianoA(GrafoA* grafo);
int geraCircuitoA(GrafoA* grafo,Vertice* inicio);

int geraCaminhoEulerianoB(GrafoB* grafo);
int geraCircuitoB(GrafoB* grafo,VerticeB* inicio);

int geraCaminhoEulerianoC(GrafoC* grafo);
int geraCircuitoC(GrafoC* grafo,VerticeC* inicio);

#endif //TP_2_EDA_CIRCUITOEULERIANO_H
