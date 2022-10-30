//
// Created by raito on 29/10/2022.
//

#include "grafoE.h"

ArestaE * inicializaArestaE(int chave){
    ArestaE* novaAresta = malloc(sizeof (ArestaE));
    novaAresta->chave = chave;
    novaAresta->proximo = NULL;
    novaAresta->fim = NULL;
    novaAresta->inicio = NULL;
    return novaAresta;
}

VerticeE* inicializaVerticeE(int chave){
    VerticeE* novoVertice = malloc(sizeof (VerticeE));
    novoVertice->chave = chave;
    novoVertice->inicio = NULL;
    novoVertice->fim = NULL;
    novoVertice->proximo = NULL;
    novoVertice->arestaInicio = NULL;
    novoVertice->arestaFim = NULL;
    novoVertice->arestaProxima = NULL;
    return novoVertice;
}

GrafoE* inicializaGrafoE(){
    GrafoE* novoGrafo = malloc(sizeof (GrafoE));
    novoGrafo->proximo = NULL;
    novoGrafo->inicio = NULL;
    novoGrafo->fim = NULL;
    return novoGrafo;
}

void adicionaVerticeGrafoE(GrafoE* grafo, int chave){
    VerticeE* novoVertice = inicializaVerticeE(chave);
    if(grafo->inicio == NULL){
        grafo->inicio = novoVertice;
        grafo->proximo = novoVertice;
    } else {
        grafo->fim->proximo = novoVertice;
    }
    grafo->fim = novoVertice;

}

void adicionarArestaGrafoE(GrafoE* grafo, int chaveA,int chaveB){
    if(grafo->inicio == NULL) { return;}
    VerticeE *ponteiroA = grafo->inicio,*ponteiroB = grafo->inicio;
    while (ponteiroA->chave != chaveA) ponteiroA = ponteiroA->proximo;
    while (ponteiroB->chave != chaveB) ponteiroB = ponteiroB->proximo;

    ArestaE* novaAresta = inicializaArestaE(chaveB);
    if(ponteiroA->arestaInicio != NULL){
        ponteiroA->arestaFim->proximo = novaAresta;
        ponteiroA->arestaFim->proximo->inicio = ponteiroA->arestaInicio;
    } else {
        ponteiroA->arestaInicio = novaAresta;
        ponteiroA->arestaProxima = novaAresta;
    }
    ponteiroA->arestaFim = novaAresta;


    ArestaE* novaArestaB = inicializaArestaE(chaveA);
    if(ponteiroB->arestaInicio != NULL){
        ponteiroB->arestaFim->proximo = novaArestaB;
        ponteiroB->arestaFim->proximo->inicio = ponteiroB->arestaInicio;
    } else {
        ponteiroB->arestaInicio = novaArestaB;
        ponteiroB->arestaProxima = novaArestaB;
    }
    ponteiroB->arestaFim = novaArestaB;
}


void imprimeGrafoE(GrafoE* grafo){
    VerticeE* percorrer = grafo->inicio;
    printf("Imprimindo grafo implementado com Lista encadeada dinamica com apontadores de inicio, proximo e fim.\n");
    while (percorrer != NULL){
        imprimeVerticeE(percorrer);
        percorrer = percorrer->proximo;
    }

}

void imprimeVerticeE(VerticeE* vertice){
    ArestaE *percorrer = vertice->arestaInicio;
    printf("Vertice %d : [ ",vertice->chave);
    while(percorrer != NULL){
        printf("%d ",percorrer->chave);
        percorrer = percorrer->proximo;
    }
    printf(" ]\n");
}

void removerArestaE(GrafoE* grafo,int chaveA,int chaveB){
    if(grafo->inicio == NULL) { return;}
    VerticeE *ponteiroA = grafo->inicio,*ponteiroB = grafo->inicio;
    while (ponteiroA->chave != chaveA) {ponteiroA = ponteiroA->proximo;}
    while (ponteiroB->chave != chaveB) {ponteiroB = ponteiroB->proximo;}

    ArestaE *antecessor = NULL,*percorrer = ponteiroA->arestaInicio;

    while(percorrer->chave != chaveB) {antecessor = percorrer; percorrer = percorrer->proximo;}
    if(antecessor == NULL){
        ponteiroA->arestaInicio = percorrer->proximo;
        ponteiroA->arestaProxima = percorrer->proximo;

        if(percorrer->proximo == NULL) { ponteiroA->arestaFim = NULL;}
    } else if(percorrer->proximo == NULL){
        ponteiroA->arestaFim = antecessor;
        antecessor->proximo = NULL;
    }
    else {
        antecessor->proximo = percorrer->proximo;
    }

    percorrer = ponteiroB->arestaInicio;
    antecessor = NULL;

    while(percorrer->chave != chaveA) {antecessor = percorrer; percorrer = percorrer->proximo;};

    if(antecessor == NULL){
        ponteiroB->arestaInicio = percorrer->proximo;
        ponteiroB->arestaProxima = percorrer->proximo;
        if (ponteiroB->proximo == NULL) { ponteiroB->arestaFim = NULL;}
    } else if(percorrer->proximo == NULL){
            ponteiroB->arestaFim = antecessor;
            antecessor->proximo = NULL;
    }else {
        antecessor->proximo = percorrer->proximo;
    }
}

void removerVerticeE(GrafoE* grafo,int chaveA){
    if(grafo->inicio == NULL) { return;}
    VerticeE *ponteiroA = grafo->inicio, *antecessor = NULL;
    while (ponteiroA->chave != chaveA) {antecessor = ponteiroA; ponteiroA = ponteiroA->proximo;}

    ArestaE* percorrer = ponteiroA->arestaInicio;
    while (percorrer != NULL){
        removerArestaE(grafo,ponteiroA->chave,percorrer->chave);
        percorrer = ponteiroA->arestaInicio;
    }
    if(antecessor == NULL){
        grafo->inicio = ponteiroA->proximo;
        grafo->proximo = ponteiroA->proximo;
        if(ponteiroA->proximo == NULL) {grafo->fim = NULL;}
    } else {
        antecessor->proximo = ponteiroA->proximo;
        if(ponteiroA->proximo == NULL) {grafo->fim = antecessor;}

    }

}


void removerTodasArestasE(GrafoE* grafo){
    VerticeE* percorrer = grafo->proximo;
    while(percorrer != NULL){
        ArestaE* aresta = percorrer->arestaInicio;
        while (aresta != NULL){
            printf("Removendo %d %d!\n",aresta->chave,percorrer->chave);
            removerArestaE(grafo,aresta->chave,percorrer->chave);
            aresta = percorrer->arestaInicio;
        }
        percorrer = percorrer->proximo;
    }
}