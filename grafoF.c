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

int removerArestaF(GrafoF* grafo,int chaveA,int chaveB){
    //printf("Removendo aresta %d %d\n",chaveA,chaveB);
    int numOP = 0;
    if(grafo->inicio == NULL) { return 0;}
    numOP++;
    VerticeF *ponteiroA = grafo->inicio,*ponteiroB = grafo->inicio;
    while (ponteiroA->chave != chaveA) {ponteiroA = ponteiroA->proximo; numOP++;}
    while (ponteiroB->chave != chaveB) {ponteiroB = ponteiroB->proximo; numOP++;}
    ArestaF *percorrer = ponteiroA->arestaInicio;

    while(percorrer->chave != chaveB) {percorrer = percorrer->proximo;}
    numOP++;
    if(percorrer->anterior == NULL){
        ponteiroA->arestaInicio = percorrer->proximo;
        ponteiroA->arestaProxima = percorrer->proximo;
        numOP++;
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
    numOP++; //Por conta do ELSE IF

    percorrer = ponteiroB->arestaInicio;
    while(percorrer->chave != chaveA) {percorrer = percorrer->proximo; numOP++;};
    numOP++;
    if(percorrer->anterior == NULL){
        ponteiroB->arestaInicio = percorrer->proximo;
        ponteiroB->arestaProxima = percorrer->proximo;
        numOP++;
        if (ponteiroB->arestaProxima == NULL) { ponteiroB->arestaFim = NULL;}
        else {percorrer->proximo->anterior =  NULL;}

    } else if(percorrer->proximo == NULL){
        ponteiroB->arestaFim = percorrer->anterior;
        percorrer->anterior->proximo = NULL;
    }else {
        percorrer->anterior->proximo = percorrer->proximo;
        percorrer->proximo->anterior = percorrer->anterior;
    }
    numOP++;
    //imprimeGrafoF(grafo);
    return numOP;

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

int removerTodasArestasF(GrafoF* grafo){
    int numOp = 0;
    VerticeF* percorrer = grafo->proximo;
    while(percorrer != NULL){
        numOp++;
        ArestaF* aresta = percorrer->arestaInicio;
        while (aresta != NULL){
            numOp++;
            printf("Removendo %d %d!\n",aresta->chave,percorrer->chave);
            numOp+= removerArestaF(grafo,aresta->chave,percorrer->chave);
            aresta = percorrer->arestaInicio;
        }
        percorrer = percorrer->proximo;
    }
    return numOp;
}

GrafoF* inicializaGrafoFArquivo(char *filename,int num){
    GrafoF* grafo = inicializaGrafoF();
    for(int i = 0;i<num;i++){
        adicionaVerticeGrafoF(grafo,i);
    }
    FILE *arquivo = fopen(filename,"r");
    if(arquivo ){
        int num,i = 0;
        char check;
        while (fscanf(arquivo, "%d%c", &num,&check)){
            //printf("LEU UM VALOR %d %d %c\n",i,num,check);
            if(num > i){ //Para evitar arestas duplicadas
                adicionarArestaGrafoF(grafo,i,num);
            }
            if (check == '\n') {i++;}
            if (feof(arquivo)) { break;}
        }

        //imprimeGrafoF(grafo);
        return grafo;
    } else {
        printf("Erro ao ler o arquivo! %s",filename);
        return NULL;
    }
}

int verificaEuleriano(GrafoF* grafo){
    int numVerticesImpar = 0;

    for (VerticeF* percorrer = grafo->inicio;percorrer != NULL;percorrer = percorrer->proximo){
        int numArestas = 0;
        for(ArestaF* aresta = percorrer->arestaInicio; aresta != NULL;aresta = aresta->proximo){
           numArestas++;
        }
        if(numArestas == 0){
            // Grafo desconexo;
            return 0;
        }
        else if(numArestas%2 != 0){
            numVerticesImpar+=1;
        }
    }

    if(numVerticesImpar == 0) return 1;
    else if (numVerticesImpar == 2) return 2; //Semi-euleriano
    else return 0;
}
