//
// Created by raito on 29/10/2022.
//

#include "grafoF.h"


ArestaF * inicializaArestaF(int chave){
    ArestaF* novaAresta = malloc(sizeof (ArestaF));
    novaAresta->chave = chave;
    novaAresta->proximo = NULL;
    novaAresta->fim = NULL;
    novaAresta->inicio = NULL;
    novaAresta->anterior = NULL;
    return novaAresta;
}

VerticeF* inicializaVerticeF(int chave){
    VerticeF* novoVertice = malloc(sizeof (VerticeF));
    novoVertice->chave = chave;
    novoVertice->inicio = NULL;
    novoVertice->fim = NULL;
    novoVertice->proximo = NULL;
    novoVertice->anterior = NULL;
    novoVertice->arestaInicio = NULL;
    novoVertice->arestaFim = NULL;
    novoVertice->arestaProxima = NULL;
    novoVertice->arestaAnterior = NULL;
    return novoVertice;
}

GrafoF* inicializaGrafoF(){
    GrafoF* novoGrafo = malloc(sizeof (GrafoF));
    novoGrafo->proximo = NULL;
    novoGrafo->inicio = NULL;
    novoGrafo->fim = NULL;
    novoGrafo->anterior = NULL;
    return novoGrafo;
}

void adicionaVerticeGrafoF(GrafoF* grafo, int chave){
    VerticeF* novoVertice = inicializaVerticeF(chave);
    if(grafo->inicio == NULL){
        grafo->inicio = novoVertice;
        grafo->proximo = novoVertice;
    } else {
        grafo->fim->proximo = novoVertice;
        novoVertice->anterior = grafo->fim;
    }
    grafo->fim = novoVertice;

}

void adicionarArestaGrafoF(GrafoF* grafo, int chaveA,int chaveB){
    if(grafo->inicio == NULL) { return;}
    VerticeF *ponteiroA = grafo->inicio,*ponteiroB = grafo->inicio;
    while (ponteiroA->chave != chaveA) ponteiroA = ponteiroA->proximo;
    while (ponteiroB->chave != chaveB) ponteiroB = ponteiroB->proximo;

    ArestaF* novaAresta = inicializaArestaF(chaveB);
    if(ponteiroA->arestaInicio != NULL){
        ponteiroA->arestaFim->proximo = novaAresta;
        novaAresta->anterior = ponteiroA->arestaFim;
        novaAresta->inicio = ponteiroA->arestaInicio;
    } else {
        ponteiroA->arestaInicio = novaAresta;
        ponteiroA->arestaProxima = novaAresta;
    }
    ponteiroA->arestaFim = novaAresta;


    ArestaF* novaArestaB = inicializaArestaF(chaveA);
    if(ponteiroB->arestaInicio != NULL){
        ponteiroB->arestaFim->proximo = novaArestaB;
        novaArestaB->anterior = ponteiroB->arestaFim;
        novaArestaB->inicio = ponteiroB->arestaInicio;
    } else {
        ponteiroB->arestaInicio = novaArestaB;
        ponteiroB->arestaProxima = novaArestaB;
    }
    ponteiroB->arestaFim = novaArestaB;
}


void imprimeGrafoF(GrafoF* grafo){
    VerticeF* percorrer = grafo->inicio;
    printf("Imprimindo grafo implementado com Lista encadeada dinamica com apontadores de inicio, proximo, anterior e fim.\n");
    while (percorrer != NULL){
        imprimeVerticeF(percorrer);
        percorrer = percorrer->proximo;
    }

}

void imprimeVerticeF(VerticeF* vertice){
    ArestaF *percorrer = vertice->arestaInicio;
    printf("Vertice %d : [ ",vertice->chave);
    while(percorrer != NULL){
        printf("%d ",percorrer->chave);
        percorrer = percorrer->proximo;
    }
    printf(" ]\n");
/*
    printf("Anterior %d : [ ",vertice->chave);

    percorrer = vertice->arestaInicio;
    while(percorrer != NULL){
        if(percorrer->anterior != NULL){
        printf("%d ",percorrer->anterior->chave);}
        percorrer = percorrer->proximo;
    }
    printf(" ]\n");*/
}

void removerArestaF(GrafoF* grafo,int chaveA,int chaveB){
    if(grafo->inicio == NULL) { return;}
    VerticeF *ponteiroA = grafo->inicio,*ponteiroB = grafo->inicio;
    while (ponteiroA->chave != chaveA) ponteiroA = ponteiroA->proximo;
    while (ponteiroB->chave != chaveB) ponteiroB = ponteiroB->proximo;
    ArestaF *percorrer = ponteiroA->arestaInicio;

    while(percorrer->chave != chaveB) {percorrer = percorrer->proximo;}
    if(percorrer->anterior == NULL){
        ponteiroA->arestaInicio = percorrer->proximo;
        ponteiroA->arestaProxima = percorrer->proximo;

        if(percorrer->proximo == NULL) { ponteiroA->arestaFim = NULL;}
        else {percorrer->proximo->anterior =  NULL;}
    } else if(percorrer->proximo == NULL){
        ponteiroA->arestaFim = percorrer->anterior;
        percorrer->anterior->proximo = NULL;
    }
    else {
        percorrer->anterior->proximo = percorrer->proximo;
        percorrer->proximo->anterior = percorrer->anterior;
    }

    percorrer = ponteiroB->arestaInicio;
    while(percorrer->chave != chaveA) {percorrer = percorrer->proximo;};

    if(percorrer->anterior == NULL){
        ponteiroB->arestaInicio = percorrer->proximo;
        ponteiroB->arestaProxima = percorrer->proximo;
        if (ponteiroB->arestaProxima == NULL) { ponteiroB->arestaFim = NULL;}
        else {percorrer->proximo->anterior =  NULL;}

    } else if(percorrer->proximo == NULL){
        ponteiroB->arestaFim = percorrer->anterior;
        percorrer->anterior->proximo = NULL;
    }else {
        percorrer->anterior->proximo = percorrer->proximo;
        percorrer->proximo->anterior = percorrer->anterior;
    }
    //imprimeGrafoF(grafo);

}

void removerVerticeF(GrafoF* grafo,int chaveA){
    if(grafo->inicio == NULL) { return;}
    VerticeF *ponteiroA = grafo->inicio;
    while (ponteiroA->chave != chaveA) {ponteiroA = ponteiroA->proximo;}

    ArestaF* percorrer = ponteiroA->arestaInicio;
    while (percorrer != NULL){
        removerArestaF(grafo,ponteiroA->chave,percorrer->chave);
        percorrer = ponteiroA->arestaInicio;
    }
    if(ponteiroA->anterior == NULL){
        grafo->inicio = ponteiroA->proximo;
        grafo->proximo = ponteiroA->proximo;
        if(ponteiroA->proximo == NULL) {grafo->fim = NULL;}
        else{ ponteiroA->proximo->anterior = NULL;}
    } else {
        ponteiroA->anterior->proximo = ponteiroA->proximo;
        if(ponteiroA->proximo == NULL) {grafo->fim = ponteiroA->anterior;}
        else{ ponteiroA->proximo->anterior = NULL;}
    }
}

void removerTodasArestasF(GrafoF* grafo){
    VerticeF* percorrer = grafo->proximo;
    while(percorrer != NULL){
        ArestaF* aresta = percorrer->arestaInicio;
        while (aresta != NULL){
            printf("Removendo %d %d!\n",aresta->chave,percorrer->chave);
            removerArestaF(grafo,aresta->chave,percorrer->chave);
            aresta = percorrer->arestaInicio;
        }
        percorrer = percorrer->proximo;
    }
}

GrafoF* inicializaGrafoFArquivo(char *filename){
    GrafoF* grafo = inicializaGrafoF();
    for(int i = 0;i<50;i++){
        adicionaVerticeGrafoF(grafo,i);
    }
    FILE *arquivo = fopen(filename,"r");
    if(arquivo ){
        int num,i = 0;
        char check;
        while (fscanf(arquivo, "%d%c", &num,&check)){
            //printf("LEU UM VALOR %d %d %c\n",i,num,check);
            adicionarArestaGrafoF(grafo,i,num);
            if (check == '\n') {i++;}
            if (feof(arquivo)) { break;}
        }

        imprimeGrafoF(grafo);
        return grafo;
    } else {
        printf("Erro ao ler o arquivo! %s",filename);
        return NULL;
    }
}