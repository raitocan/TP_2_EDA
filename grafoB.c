//
// Created by raito on 27/10/2022.
//

#include "grafoB.h"

VerticeB* inicializaVerticeB(int chave){
    VerticeB* novoVertice = malloc(sizeof(VerticeB));
    novoVertice->chave = chave;
    novoVertice->livre = 0;
    novoVertice->primeiro = -1;
    novoVertice->tamanho = 0;
    novoVertice->ultimo = novoVertice->primeiro;
    novoVertice->lista = malloc(sizeof(VerticeB)* N);
    novoVertice->listaIndices = malloc(sizeof(int)* N);
    for(int i = 0;i < N;i++){
        novoVertice->listaIndices[i] = -1;
    }
    return novoVertice;
}

GrafoB* inicializaGrafoB(){
    GrafoB* grafo = malloc(sizeof (GrafoB));
    grafo->primeiro = -1;
    grafo->ultimo = -1;
    grafo->livre = 0;
    grafo->listaIndices = malloc(sizeof(int)* tamMax);
    grafo->listaVertices = malloc(sizeof(VerticeB)*tamMax);
    grafo->tamanho = 0;

    for(int i = 0; i < tamMax; i++){
        grafo->listaVertices[i] = inicializaVerticeB(-1);
        grafo->listaIndices[i] = -1;
    }
    return grafo;
}

void imprimeGrafoB(GrafoB* grafo){
    printf("Imprimindo Grafo feito com Lista estatica dinamica com indicador de proximo.\n");
    int chave = grafo->primeiro;
    if(chave != -1){
        while(grafo->listaIndices[chave] != -1){
            imprimeVerticeB(grafo->listaVertices[chave]);
            chave = grafo->listaIndices[chave];
        }
    }
}

void imprimeVerticeB(VerticeB* vertice){
    printf("Vertice %d : [",vertice->chave);
    int chave = vertice->primeiro;
    if(chave != -1){
        while(vertice->listaIndices[chave] != -1){
            printf("%d ",vertice->lista[chave]->chave);
            chave = vertice->listaIndices[chave];
        }
    }
    printf(" ]\n");
    chave = vertice->primeiro;
    printf("Primeiro %d  Ultimo %d\n ",vertice->primeiro,vertice->ultimo);
    printf("Lista indices %d : [",vertice->chave);
    while(chave != -1){
        printf("%d ", vertice->listaIndices[chave]);
        chave = vertice->listaIndices[chave];
    }
    printf(" ]\n");
    printf(" \n");

}

int encontraProximoVazio(int* listaIndice, int tamanho){
    for(int i = 0; i < tamanho;i++){
        if(listaIndice[i] == -1){
            return i;
        }
    } return -1;
}

void adicionaVerticeGrafoB(GrafoB* grafo, int chave){
    if(grafo->primeiro == -1){
        grafo->primeiro = grafo->livre;
    }
    grafo->listaVertices[grafo->livre]->chave = chave;
    grafo->listaIndices[grafo->livre] = 0; //Temporiariamente preenche para achar o proximo livre
    grafo->listaIndices[grafo->livre] = encontraProximoVazio(grafo->listaIndices,tamMax);
    grafo->ultimo = grafo->livre;
    grafo->tamanho+=1;
    grafo->livre = grafo->listaIndices[grafo->livre];
}

void adicionarVerticeVerticeB(VerticeB* vertice,VerticeB* chave){
    if(vertice->primeiro == -1){
        vertice->primeiro = vertice->livre;
    }
    vertice->lista[vertice->livre] = chave;
    vertice->listaIndices[vertice->livre] = 0; //Temporiariamente preenche para achar o proximo livre
    vertice->listaIndices[vertice->livre] = encontraProximoVazio(vertice->listaIndices,N);
    vertice->ultimo = vertice->livre;
    vertice->tamanho+=1;
    vertice->livre = vertice->listaIndices[vertice->livre];
}

int adicionarArestaGrafoB(GrafoB* grafo, int chaveA, int chaveB){
    int indiceA = -1,indiceB = -1;
    int chave = grafo->primeiro;
    while(chave != -1){
        if(grafo->listaVertices[chave]->chave == chaveA){ indiceA = chave;}
        if(grafo->listaVertices[chave]->chave == chaveB){ indiceB = chave;}
        chave = grafo->listaIndices[chave];
    }
    if(indiceA == -1) { return -1;}
    if(indiceB == -1) { return -1;}

    adicionarVerticeVerticeB(grafo->listaVertices[indiceA],grafo->listaVertices[indiceB]);
    adicionarVerticeVerticeB(grafo->listaVertices[indiceB],grafo->listaVertices[indiceA]);
    return 1;
}

int removerArestaGrafoB(GrafoB* grafo, int chaveA, int chaveB){
    int indiceA = -1,indiceB = -1;
    int chave = grafo->primeiro;
    while(chave != -1){
        if(grafo->listaVertices[chave]->chave == chaveA){ indiceA = chave;}
        if(grafo->listaVertices[chave]->chave == chaveB){ indiceB = chave;}
        chave = grafo->listaIndices[chave];
    }
    if(indiceA == -1) { return -1;}
    if(indiceB == -1) { return -1;}

    removerArestaVerticeB(grafo->listaVertices[indiceB],chaveA);
    removerArestaVerticeB(grafo->listaVertices[indiceA],chaveB);
    return 1;
}

int removerArestaVerticeB(VerticeB* vertice, int aresta){
    int chave = vertice->primeiro;
    int antecessor = -1, indiceRemover = -1;
    while(chave != -1){
        if(vertice->lista[chave]->chave == aresta) {
            indiceRemover = chave;
            break;
        }
        antecessor = chave;
        chave = vertice->listaIndices[chave];
    }
    if(antecessor == -1){
        vertice->primeiro = vertice->listaIndices[indiceRemover];
    } else {
        vertice->listaIndices[antecessor] = vertice->listaIndices[indiceRemover];
    }

    if(vertice->ultimo == indiceRemover) {
        vertice->ultimo = antecessor;
    }
    vertice->lista[indiceRemover] = NULL;
    vertice->tamanho--;
    vertice->livre = encontraProximoVazio(vertice->listaIndices,N);
    return 1;
}

int removerVerticeGrafoB(GrafoB* grafo, int chaveA){
    int chave = grafo->primeiro;
    int antecessor = -1, indiceRemover = -1;
    while(chave != -1){
        if(grafo->listaVertices[chave]->chave == chaveA) {
            indiceRemover = chave;
            break;
        }
        antecessor = chave;
        chave = grafo->listaIndices[chave];
    }
    int primeiro = grafo->listaVertices[indiceRemover]->primeiro;
    while(grafo->listaVertices[indiceRemover]->ultimo != -1){

        removerArestaGrafoB(grafo,chaveA,grafo->listaVertices[indiceRemover]->lista[primeiro]->chave);
        primeiro = grafo->listaVertices[indiceRemover]->primeiro;
    }
    if(antecessor == -1){
        grafo->primeiro = grafo->listaIndices[indiceRemover];
    } else {
        grafo->listaIndices[antecessor] = grafo->listaIndices[indiceRemover];
    }

    if(grafo->ultimo == indiceRemover) {
        grafo->ultimo = antecessor;
    }

    grafo->listaVertices[indiceRemover] = NULL;
    grafo->livre = encontraProximoVazio(grafo->listaIndices,N);
    return 1;
}


void removerTodasArestasB(GrafoB* grafo){
    int chave = grafo->primeiro;
    while(chave != -1 ){
        int primeiro = grafo->listaVertices[chave]->primeiro;
        while(grafo->listaVertices[chave]->ultimo != -1){

            removerArestaGrafoB(grafo,grafo->listaVertices[chave]->chave,grafo->listaVertices[chave]->lista[primeiro]->chave);
            primeiro = grafo->listaVertices[chave]->primeiro;
        }
        chave = grafo->listaIndices[chave];
    }
}