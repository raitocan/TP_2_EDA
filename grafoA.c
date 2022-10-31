//
// Created by raito on 26/10/2022.
//

#include "grafoA.h"

GrafoA* iniciaGrafo(int maxSize){
    GrafoA* novoGrafo = malloc(sizeof(GrafoA));
    novoGrafo->listaVertices = malloc(sizeof(Vertice)*maxSize);
    novoGrafo->numVertices = 0;
    novoGrafo->tamMax = maxSize;
    return novoGrafo;
}

Vertice* iniciaVertice(int maxVizinhos, int chave){
    Vertice* novoVertice = malloc(sizeof(Vertice)*maxVizinhos);
    novoVertice->chave = chave;
    novoVertice->tamanhoLista = 0;
    novoVertice->tamMax = maxVizinhos;
    novoVertice->listaAdjacencia = malloc(sizeof(Vertice)*maxVizinhos);
    return novoVertice;
}

int adicionarVertice(GrafoA* grafo){
    if(grafo->numVertices == grafo->tamMax) return -1;
    grafo->listaVertices[grafo->numVertices] = iniciaVertice(N,grafo->numVertices);
    //printf("Inserido um vertice de indice %d\n",grafo->numVertices);
    grafo->numVertices++;
    return grafo->numVertices-1;
}


int inserirAresta(GrafoA* grafo, int origem,int destino){
    if(grafo->numVertices-1 < origem || grafo->numVertices-1 < destino ) return -1;

    if(grafo->listaVertices[origem]->tamanhoLista == grafo->listaVertices[origem]->tamMax) return -1;
    if(grafo->listaVertices[destino]->tamanhoLista == grafo->listaVertices[destino]->tamMax) return -1;
    int tamOrigem, tamDestino;

    tamOrigem = grafo->listaVertices[origem]->tamanhoLista;
    tamDestino = grafo->listaVertices[destino]->tamanhoLista;

    grafo->listaVertices[origem]->listaAdjacencia[tamOrigem] = *grafo->listaVertices[destino];
    grafo->listaVertices[destino]->listaAdjacencia[tamDestino] = *grafo->listaVertices[origem];

    //printf("Inserido uma aresta entre %d e %d\n",origem,destino);
    grafo->listaVertices[origem]->tamanhoLista++;
    grafo->listaVertices[destino]->tamanhoLista++;

    return grafo->listaVertices[origem]->tamanhoLista-1;
}

int removerAresta(GrafoA* grafo,int origem,int destino){
    int numOp = 0;
    for(int i = 0; i < grafo->listaVertices[origem]->tamanhoLista;i++){
        numOp+=2;
        if(grafo->listaVertices[origem]->listaAdjacencia[i].chave == destino){
            for(int j = i;j < grafo->listaVertices[origem]->tamanhoLista-1;j++){
                numOp++;
                grafo->listaVertices[origem]->listaAdjacencia[j] = grafo->listaVertices[origem]->listaAdjacencia[j+1];
            }
            grafo->listaVertices[origem]->tamanhoLista--;
            break;
        }
    }
    for(int i = 0; i < grafo->listaVertices[destino]->tamanhoLista;i++){
        numOp+=2;
        if(grafo->listaVertices[destino]->listaAdjacencia[i].chave == origem){
            for(int j = i;j < grafo->listaVertices[destino]->tamanhoLista-1;j++){
                numOp++;
                grafo->listaVertices[destino]->listaAdjacencia[j] = grafo->listaVertices[destino]->listaAdjacencia[j+1];
            }
            grafo->listaVertices[destino]->tamanhoLista--;
            break;
        }
    }
    return numOp;
};

void removerVertice(GrafoA* grafo, int vertice){
    int numRepeticoes = grafo->listaVertices[vertice]->tamanhoLista;
    for(int i = 0; i < numRepeticoes; i++){
        removerAresta(grafo,vertice,grafo->listaVertices[vertice]->listaAdjacencia[0].chave);
    }
    for(int i = 0; i < grafo->numVertices;i++){
        if ( grafo->listaVertices[i]->chave == vertice){
            for(int j = i; j < grafo->numVertices-1;j++){
                grafo->listaVertices[j] = grafo->listaVertices[j+1];
                grafo->listaVertices[j]->chave--;
            }
            grafo->numVertices--;
            return;
        }
    }
}

void imprimirGrafo(GrafoA* grafo){
    printf("Grafo\n");
    printf("Numero de vertices %d\n",grafo->numVertices);
    for(int i = 0; i<grafo->numVertices;i++){
        printf("Vertice %d : ",grafo->listaVertices[i]->chave);
        if(grafo->listaVertices[i]->tamanhoLista == 0){
            printf("VAZIO \n");
        } else {
            for(int j = 0;j<grafo->listaVertices[i]->tamanhoLista;j++){
                printf("%d ",grafo->listaVertices[i]->listaAdjacencia[j].chave);
            }
            printf("\n");
        }
    }
    printf("\n");
}



int removerTodasArestasA(GrafoA* grafo){
    int numRepeticoes = 0,numOp = 0;
    for(int i = 0; i<grafo->numVertices;i++){
        numOp++;
        numRepeticoes = grafo->listaVertices[i]->tamanhoLista;
        for(int j = 0; j < numRepeticoes; j++){
            numOp++;
            printf("Removendo %d %d!\n",i,grafo->listaVertices[i]->listaAdjacencia[0].chave);
            numOp+= removerAresta(grafo,i,grafo->listaVertices[i]->listaAdjacencia[0].chave);
        }
        //printf("%d\n",numOp);
    }
    return numOp;
}

GrafoA* inicializaGrafoAArquivo(char *filename){
    GrafoA* grafo = iniciaGrafo(50);
    for(int i = 0;i<50;i++){
        adicionarVertice(grafo);
    }
    FILE *arquivo = fopen(filename,"r");
    if(arquivo ){
        int num,i = 0;
        char check;
        while (fscanf(arquivo, "%d%c", &num,&check)){
            //printf("LEU UM VALOR %d %d %c\n",i,num,check);
            inserirAresta(grafo,i,num);
            if (check == '\n') {i++;}
            if (feof(arquivo)) { break;}
        }

        imprimirGrafo(grafo);
        return grafo;
    } else {
        printf("Erro ao ler o arquivo! %s",filename);
        return NULL;
    }
}