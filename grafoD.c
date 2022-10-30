//
// Created by raito on 29/10/2022.
//

#include "grafoD.h"

ArestaD* inicializaArestaD(int chave){
    ArestaD* novaAresta = malloc(sizeof (ArestaD));
    novaAresta->chave = chave;
    novaAresta->proximo = NULL;
    novaAresta->inicio = NULL;
    return novaAresta;
}

VerticeD* inicializaVerticeD(int chave){
    VerticeD* novoVertice = malloc(sizeof (VerticeD));
    novoVertice->chave = chave;
    novoVertice->inicio = NULL;
    novoVertice->proximo = NULL;
    novoVertice->arestaInicio = NULL;
    novoVertice->arestaProxima = NULL;
    return novoVertice;
}

GrafoD* inicializaGrafoD(){
    GrafoD* novoGrafo = malloc(sizeof (GrafoD));
    novoGrafo->proximo = NULL;
    novoGrafo->inicio = NULL;
    return novoGrafo;
}

void adicionaVerticeGrafoD(GrafoD* grafo, int chave){
    VerticeD* novoVertice = inicializaVerticeD(chave);
    if(grafo->inicio == NULL){
        grafo->inicio = novoVertice;
        grafo->proximo = novoVertice;
    } else {
        VerticeD* percorrer = grafo->inicio;
        while (percorrer->proximo != NULL) percorrer = percorrer->proximo;
        percorrer->proximo = novoVertice;
    }
}

void adicionarArestaGrafoD(GrafoD* grafo, int chaveA,int chaveB){
    if(grafo->inicio == NULL) { return;}
    VerticeD *ponteiroA = grafo->inicio,*ponteiroB = grafo->inicio;
    while (ponteiroA->chave != chaveA) ponteiroA = ponteiroA->proximo;
    while (ponteiroB->chave != chaveB) ponteiroB = ponteiroB->proximo;

    ArestaD *arestaA = ponteiroA->arestaInicio;
    ArestaD* novaAresta = inicializaArestaD(chaveB);
    if(arestaA != NULL){
        while(arestaA->proximo != NULL){arestaA = arestaA->proximo;}
        arestaA->proximo = novaAresta;
        arestaA->inicio = ponteiroA->arestaInicio;
    } else {
        ponteiroA->arestaInicio = novaAresta;
        ponteiroA->arestaProxima = novaAresta;
    }

    ArestaD *arestaB = ponteiroB->arestaInicio;
    ArestaD* novaArestaB = inicializaArestaD(chaveA);
    if(arestaB != NULL){
        while(arestaB->proximo != NULL){arestaB = arestaB->proximo;}
        arestaB->proximo = novaArestaB;
        arestaB->inicio = ponteiroB->arestaInicio;
    } else {
        ponteiroB->arestaInicio = novaArestaB;
        ponteiroB->arestaProxima = novaArestaB;
    }
}


void imprimeGrafoD(GrafoD* grafo){
    VerticeD* percorrer = grafo->inicio;
    printf("Imprimindo grafo implementado com Lista encadeada dinamica com apontadores de inicio e proximo.\n");
    while (percorrer != NULL){
        imprimeVerticeD(percorrer);
        percorrer = percorrer->proximo;
    }

}

void imprimeVerticeD(VerticeD* vertice){
    ArestaD *percorrer = vertice->arestaInicio;
    printf("Vertice %d : [ ",vertice->chave);
    while(percorrer != NULL){
        printf("%d ",percorrer->chave);
        percorrer = percorrer->proximo;
    }
    printf(" ]\n");
}

void removerArestaD(GrafoD* grafo,int chaveA,int chaveB){
    if(grafo->inicio == NULL) { return;}
    VerticeD *ponteiroA = grafo->inicio,*ponteiroB = grafo->inicio;
    while (ponteiroA->chave != chaveA) ponteiroA = ponteiroA->proximo;
    while (ponteiroB->chave != chaveB) ponteiroB = ponteiroB->proximo;

    ArestaD *antecessor = NULL,*percorrer = ponteiroA->arestaInicio;

    while(percorrer->chave != chaveB) {antecessor = percorrer; percorrer = percorrer->proximo;}
    if(antecessor == NULL){
        ponteiroA->arestaInicio = percorrer->proximo;
        ponteiroA->arestaProxima = percorrer->proximo;
    } else {
        antecessor->proximo = percorrer->proximo;
    }

    percorrer = ponteiroB->arestaInicio;
    antecessor = NULL;

    while(percorrer->chave != chaveA) {antecessor = percorrer; percorrer = percorrer->proximo;};

    if(antecessor == NULL){
        ponteiroB->arestaInicio = percorrer->proximo;
        ponteiroB->arestaProxima = percorrer->proximo;
    } else {
        antecessor->proximo = percorrer->proximo;
    }
}

void removerVerticeD(GrafoD* grafo,int chaveA){
    if(grafo->inicio == NULL) { return;}
    VerticeD *ponteiroA = grafo->inicio, *antecessor = NULL;

    while (ponteiroA->chave != chaveA) {antecessor = ponteiroA; ponteiroA = ponteiroA->proximo;}

    ArestaD* percorrer = ponteiroA->arestaInicio;
    while (percorrer != NULL){
        removerArestaD(grafo,ponteiroA->chave,percorrer->chave);
        percorrer = ponteiroA->arestaInicio;
    }
    if(antecessor == NULL){
        grafo->inicio = ponteiroA->proximo;
        grafo->proximo = ponteiroA->proximo;
    } else {
        antecessor->proximo = ponteiroA->proximo;
    }

}



void removerTodasArestasD(GrafoD* grafo){
    VerticeD* percorrer = grafo->proximo;
    while(percorrer != NULL){
        ArestaD* aresta = percorrer->arestaInicio;
        while (aresta != NULL){
            printf("Removendo %d %d!\n",aresta->chave,percorrer->chave);
            removerArestaD(grafo,aresta->chave,percorrer->chave);
            aresta = percorrer->arestaInicio;
        }
        percorrer = percorrer->proximo;
    }
}