//
// Created by raito on 29/10/2022.
//

#include "grafoC.h"
#include "grafoB.h"

VerticeC* inicializaVerticeC(int chave){
    VerticeC * novoVertice = malloc(sizeof(VerticeC));
    novoVertice->chave = chave;
    novoVertice->livre = 0;
    novoVertice->primeiro = -1;
    novoVertice->tamanho = 0;
    novoVertice->ultimo = novoVertice->primeiro;
    novoVertice->lista = malloc(sizeof(VerticeC)* N);
    novoVertice->listaIndicesAnterior = malloc(sizeof(int)* N);
    novoVertice->listaIndicesProx = malloc(sizeof(int)* N);

    for(int i = 0;i < N;i++){
        novoVertice->listaIndicesAnterior[i] = -1;
        novoVertice->listaIndicesProx[i] = -1;

    }
    return novoVertice;
}
GrafoC * inicializaGrafoC(){
    GrafoC* grafo = malloc(sizeof (GrafoC));
    grafo->primeiro = -1;
    grafo->ultimo = -1;
    grafo->livre = 0;
    grafo->listaIndicesAnterior = malloc(sizeof(int)* tamMax);
    grafo->listaIndicesProx = malloc(sizeof(int)* tamMax);
    grafo->listaVertices = malloc(sizeof(VerticeC)*tamMax);
    grafo->tamanho = 0;

    for(int i = 0; i < tamMax; i++){
        grafo->listaVertices[i] = inicializaVerticeC(-1);
        grafo->listaIndicesAnterior[i] = -1;
        grafo->listaIndicesProx[i] = -1;

    }
    return grafo;
}
void imprimeGrafoC(GrafoC* grafo){
    printf("Imprimindo Grafo feito com Lista estatica dinamica com indicador de proximo.\n");
    int chave = grafo->primeiro;
    if(chave != -1){
        while(grafo->listaIndicesProx[chave] != -1){
            imprimeVerticeC(grafo->listaVertices[chave]);
            chave = grafo->listaIndicesProx[chave];
        }
    }
}
void imprimeVerticeC(VerticeC* vertice){
    printf("Vertice %d : [",vertice->chave);
    int chave = vertice->primeiro;
    if(chave != -1){
        while(vertice->listaIndicesProx[chave] != -1){
            printf("%d ",vertice->lista[chave]->chave);
            chave = vertice->listaIndicesProx[chave];
        }
    }
    printf(" ]\n");
    chave = vertice->primeiro;
    printf("Primeiro %d  Ultimo %d\n",vertice->primeiro,vertice->ultimo);
    printf("Lista indices Proximos %d : [",vertice->chave);
    while(chave != -1){
        printf("%d ", vertice->listaIndicesProx[chave]);
        chave = vertice->listaIndicesProx[chave];
    }
    printf(" ]\n");
    chave = vertice->primeiro;
    printf("Lista indices Anteriores %d : [",vertice->chave);
    while(chave != -1){
        printf("%d ", vertice->listaIndicesAnterior[chave]);
        chave = vertice->listaIndicesProx[chave];
    }
    printf(" ]\n");
    printf(" \n");
}
void adicionaVerticeGrafoC(GrafoC* grafo, int chave){
    if(grafo->primeiro == -1){
        grafo->primeiro = grafo->livre;
    }
    grafo->listaVertices[grafo->livre]->chave = chave;
    grafo->listaIndicesProx[grafo->livre] = 0; //Temporiariamente preenche para achar o proximo livre
    grafo->listaIndicesProx[grafo->livre] = encontraProximoVazio(grafo->listaIndicesProx,tamMax);
    grafo->listaIndicesAnterior[grafo->livre] = grafo->ultimo;
    grafo->ultimo = grafo->livre;
    grafo->tamanho+=1;
    grafo->livre = grafo->listaIndicesProx[grafo->livre];
}

void adicionarVerticeVerticeC(VerticeC* vertice,VerticeC* chave){
    if(vertice->primeiro == -1){
        vertice->primeiro = vertice->livre;
    }
    vertice->lista[vertice->livre] = chave;
    vertice->listaIndicesProx[vertice->livre] = 0; //Temporiariamente preenche para achar o proximo livre
    vertice->listaIndicesProx[vertice->livre] = encontraProximoVazio(vertice->listaIndicesProx,N);
    vertice->listaIndicesAnterior[vertice->livre] = vertice->ultimo;
    vertice->ultimo = vertice->livre;
    vertice->tamanho+=1;
    vertice->livre = vertice->listaIndicesProx[vertice->livre];
}

int adicionarArestaGrafoC(GrafoC* grafo, int chaveA, int chaveB){
    int indiceA = -1,indiceB = -1;
    int chave = grafo->primeiro;
    while(chave != -1){
        if(grafo->listaVertices[chave]->chave == chaveA){ indiceA = chave;}
        if(grafo->listaVertices[chave]->chave == chaveB){ indiceB = chave;}
        chave = grafo->listaIndicesProx[chave];
    }
    if(indiceA == -1) { return -1;}
    if(indiceB == -1) { return -1;}

    adicionarVerticeVerticeC(grafo->listaVertices[indiceA],grafo->listaVertices[indiceB]);
    adicionarVerticeVerticeC(grafo->listaVertices[indiceB],grafo->listaVertices[indiceA]);
    return 1;

}

int removerArestaGrafoC(GrafoC* grafo, int chaveA, int chaveB){
    int indiceA = -1,indiceB = -1, numOp = 0;
    int chave = grafo->primeiro;
    while(chave != -1){
        numOp+= 2; // Pelo while e pelo if abaixo.
        if(grafo->listaVertices[chave]->chave == chaveA){ indiceA = chave;}
        numOp++;
        if(grafo->listaVertices[chave]->chave == chaveB){ indiceB = chave;}
        chave = grafo->listaIndicesProx[chave];
    }
    numOp++;
    if(indiceA == -1) { return -1;}
    numOp++;
    if(indiceB == -1) { return -1;}
    numOp+= removerArestaVerticeC(grafo->listaVertices[indiceB],chaveA);
    numOp+= removerArestaVerticeC(grafo->listaVertices[indiceA],chaveB);
    return numOp;
}
int removerArestaVerticeC(VerticeC* vertice, int aresta){
    int numOp = 0;
    int chave = vertice->primeiro;
    int antecessor = -1, indiceRemover = -1,sucessor = -1;
    //imprimeVerticeC(vertice);
    while(chave != -1){
        numOp+=2;
        if(vertice->lista[chave]->chave == aresta) {
            indiceRemover = chave;
            break;
        }
        chave = vertice->listaIndicesProx[chave];
        //printf("PAROU AQUI! %d\n",chave);

    }
    antecessor = vertice->listaIndicesAnterior[indiceRemover];
    sucessor = vertice->listaIndicesProx[indiceRemover];
    numOp++;
    if(antecessor == -1){
        vertice->primeiro = vertice->listaIndicesProx[indiceRemover];
    } else {
        vertice->listaIndicesProx[antecessor] = vertice->listaIndicesProx[indiceRemover];
    }
    numOp++;
    if(sucessor != -1){
        vertice->listaIndicesAnterior[sucessor] = vertice->listaIndicesAnterior[indiceRemover];
    } else {
        vertice->listaIndicesProx[antecessor] = -1;
    }
    numOp++;
    if(vertice->ultimo == indiceRemover) {
        vertice->ultimo = antecessor;
    }
    vertice->lista[indiceRemover] = NULL;
    vertice->tamanho--;
    vertice->livre = encontraProximoVazio(vertice->listaIndicesProx,N);
    return numOp;
}
int removerVerticeGrafoC(GrafoC* grafo, int chaveA){
    int chave = grafo->primeiro;
    int antecessor = -1, indiceRemover = -1,sucessor = -1;
    while(chave != -1){
        if(grafo->listaVertices[chave]->chave == chaveA) {
            indiceRemover = chave;
            break;
        }
        chave = grafo->listaIndicesProx[chave];
    }
    antecessor = grafo->listaIndicesAnterior[indiceRemover];
    sucessor = grafo->listaIndicesProx[indiceRemover];

    int primeiro = grafo->listaVertices[indiceRemover]->primeiro;
    while(grafo->listaVertices[indiceRemover]->ultimo != -1){

        removerArestaGrafoC(grafo,chaveA,grafo->listaVertices[indiceRemover]->lista[primeiro]->chave);
        primeiro = grafo->listaVertices[indiceRemover]->primeiro;
    }
    if(antecessor == -1){
        grafo->primeiro = grafo->listaIndicesProx[indiceRemover];
    } else {
        grafo->listaIndicesProx[antecessor] = grafo->listaIndicesProx[indiceRemover];
    }

    if(sucessor != -1){
        grafo->listaIndicesAnterior[sucessor] = grafo->listaIndicesAnterior[indiceRemover];
    }

    if(grafo->ultimo == indiceRemover) {
        grafo->ultimo = antecessor;
    }

    grafo->listaVertices[indiceRemover] = NULL;
    grafo->livre = encontraProximoVazio(grafo->listaIndicesProx,N);
    return 1;
}

int removerTodasArestasC(GrafoC* grafo){
    int chave = grafo->primeiro,numOp = 0;
    while(chave != -1 ){
        numOp++;
        int primeiro = grafo->listaVertices[chave]->primeiro;
        while(grafo->listaVertices[chave]->ultimo != -1){
            numOp++;
            printf("Removendo aresta %d %d\n",grafo->listaVertices[chave]->chave,grafo->listaVertices[chave]->lista[primeiro]->chave);
            numOp+= removerArestaGrafoC(grafo,grafo->listaVertices[chave]->chave,grafo->listaVertices[chave]->lista[primeiro]->chave);
            primeiro = grafo->listaVertices[chave]->primeiro;
        }
        chave = grafo->listaIndicesProx[chave];
    }
    return numOp;
}

GrafoC* inicializaGrafoCArquivo(char *filename){
    GrafoC* grafo = inicializaGrafoC();
    for(int i = 0;i<50;i++){
        adicionaVerticeGrafoC(grafo,i);
    }
    FILE *arquivo = fopen(filename,"r");
    if(arquivo ){
        int num,i = 0;
        char check;
        while (fscanf(arquivo, "%d%c", &num,&check)){
            //printf("LEU UM VALOR %d %d %c\n",i,num,check);
            adicionarArestaGrafoC(grafo,i,num);
            if (check == '\n') {i++;}
            if (feof(arquivo)) { break;}
        }

        //imprimeGrafoC(grafo);
        return grafo;
    } else {
        printf("Erro ao ler o arquivo! %s",filename);
        return NULL;
    }
}