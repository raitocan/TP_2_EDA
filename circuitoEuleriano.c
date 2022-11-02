//
// Created by raito on 01/11/2022.
//

#include "circuitoEuleriano.h"

tipoCircuito* novoCircuito(){
    tipoCircuito* novoCircuito = malloc(sizeof(tipoCircuito));
    novoCircuito->chave = -1;
    novoCircuito->tamanho = 0;
    novoCircuito->proximo = NULL;
    novoCircuito->ultimo = NULL;
    novoCircuito->primeiro = NULL;
    return novoCircuito;
}

void adicionarCircuito( tipoCircuito* A, int chave){
    tipoCircuito *proximo = malloc(sizeof(tipoCircuito));
    proximo->chave = chave;
    if(A->primeiro == NULL){
        A->primeiro = proximo;
    }
    if(A->ultimo == NULL){
        A->ultimo = proximo;
    } else {
        A->ultimo->proximo = proximo;
        A->ultimo = A->ultimo->proximo;
    }
}

void imprimirCircuito(tipoCircuito* A){
    for(tipoCircuito* percorre = A->primeiro; percorre != NULL;percorre = percorre->proximo){
        printf("%d -> ", percorre->chave);
    }
    printf("\n");
}

void anexarCircuito( tipoCircuito* A, tipoCircuito* B){
    if(A->primeiro == NULL) { A->proximo = B->primeiro; A->primeiro = B->primeiro;}
    else { A->ultimo->proximo = B->primeiro; A->ultimo = B->ultimo;}
}


int geraCaminhoEulerianoF(GrafoF* grafo){
    int opBasica = 0;
    if(verificaEuleriano(grafo) != 1) { return 0;}
    printf("\n%d ->",grafo->inicio->arestaProxima->chave);
    for(VerticeF* atual = grafo->inicio; atual != NULL;atual = atual->proximo){
        while(atual->arestaProxima != NULL){
            opBasica += geraCircuitoF(grafo,atual);
        }
    }
    printf("\n");
    return opBasica;
}

VerticeF* getVerticeF(GrafoF* grafo, int chave,int* numOps){
    for(VerticeF* V = grafo->inicio; V != NULL;V = V->proximo){
        *numOps+=1;
        if(V->chave == chave) return V;
    }
    return NULL;
}


int geraCircuitoF(GrafoF* grafo,VerticeF* inicio){
    int numOp = 0;
    ArestaF* proximaAresta = inicio->arestaFim;
    VerticeF* atual,*prox;

    while (proximaAresta->chave != inicio->chave){
        numOp+=1;
        atual = getVerticeF(grafo,proximaAresta->chave,&numOp);
        proximaAresta = atual->arestaFim;
        prox = getVerticeF(grafo,proximaAresta->chave,&numOp);

        printf(" %d -> ",atual->chave);
        numOp+= removerArestaF(grafo,prox->chave,atual->chave);
    }
    printf("%d ->",prox->chave);
    return numOp;
}


int geraCaminhoEulerianoE(GrafoE* grafo){
    int numOps = 0;
    if(verificaEulerianoE(grafo) != 1) { return 0;}
    printf("\n%d ->",grafo->inicio->arestaProxima->chave);
    for(VerticeE* atual = grafo->inicio; atual != NULL;atual = atual->proximo){
        while(atual->arestaProxima != NULL){
            numOps+=geraCircuitoE(grafo,atual);
        }
    }
    printf("\n");
    return numOps;
}

VerticeE* getVerticeE(GrafoE* grafo, int chave,int* numOps){
    for(VerticeE* V = grafo->inicio; V != NULL;V = V->proximo){
        if(V->chave == chave) return V;
        *numOps++;
    }
    return NULL;
}


int geraCircuitoE(GrafoE* grafo,VerticeE* inicio){
    int numOps = 0;
    ArestaE* proximaAresta = inicio->arestaFim;
    VerticeE* atual,*prox;
    while (proximaAresta->chave != inicio->chave){
        atual = getVerticeE(grafo,proximaAresta->chave,&numOps);
        proximaAresta = atual->arestaFim;
        prox = getVerticeE(grafo,proximaAresta->chave,&numOps);
        printf(" %d -> ",atual->chave);
        numOps+= removerArestaE(grafo,prox->chave,atual->chave);
    }
    printf("%d ->",prox->chave);
    return numOps;
}


int geraCaminhoEulerianoD(GrafoD* grafo){
    int numOps = 0;
    if(verificaEulerianoD(grafo) != 1) { return 0;}
    for(VerticeD* atual = grafo->inicio; atual != NULL;atual = atual->proximo){
        while(atual->arestaProxima != NULL){
            numOps+=geraCircuitoD(grafo,atual);
        }
    }
    printf("\n");
    return numOps;
}

VerticeD* getVerticeD(GrafoD* grafo, int chave,int* numOps){
    for(VerticeD* V = grafo->inicio; V != NULL;V = V->proximo){
        if(V->chave == chave) return V;
        *numOps++;
    }
    return NULL;
}


int geraCircuitoD(GrafoD* grafo,VerticeD* inicio){
    int numOps = 0;
    ArestaD * proximaAresta = inicio->arestaInicio;
    VerticeD* atual,*prox;
    while (proximaAresta->chave != inicio->chave){
        atual = getVerticeD(grafo,proximaAresta->chave,&numOps);
        proximaAresta = atual->arestaInicio;
        prox = getVerticeD(grafo,proximaAresta->chave,&numOps);
        printf(" %d -> ",atual->chave);
        numOps+= removerArestaD(grafo,prox->chave,atual->chave);
    }
    printf("%d ->",prox->chave);
    return numOps;
}


int geraCircuitoA(GrafoA* grafo,Vertice* inicio){
    int numOps = 0;

    Vertice proximaAresta = grafo->listaVertices[inicio->chave]->listaAdjacencia[0];
    Vertice atual;

    while (proximaAresta.chave != inicio->chave){
        atual = proximaAresta;
        proximaAresta = atual.listaAdjacencia[0];
        printf(" %d -> ",atual.chave);
        numOps+= removerAresta(grafo,proximaAresta.chave,atual.chave);
    }
    printf("%d ->",proximaAresta.chave);
    return numOps;
}



int geraCaminhoEulerianoA(GrafoA* grafo){
    int numOps = 0, numRepeticoes;
    if(verificaEulerianoA(grafo) != 1) { return 0;}
    for(int i = 0; i<grafo->numVertices;i++){
        numRepeticoes = grafo->listaVertices[i]->tamanhoLista;
        for(int j = 0; j < numRepeticoes; j++){
            numOps+=geraCircuitoA(grafo,grafo->listaVertices[i]);
        }
    }
    printf("\n");
    return numOps;
}



int geraCircuitoB(GrafoB* grafo,VerticeB* inicio){
    int numOps = 0;

    VerticeB* proximaAresta = grafo->listaVertices[inicio->lista[inicio->primeiro]->chave];
    VerticeB* atual;

    while (proximaAresta->chave != inicio->chave){
        atual = proximaAresta;
        proximaAresta = grafo->listaVertices[proximaAresta->lista[proximaAresta->primeiro]->chave];
        printf(" %d -> ",atual->chave);
        numOps+= removerArestaGrafoB(grafo,proximaAresta->chave,atual->chave);
    }
    printf("%d ->",proximaAresta->chave);
    return numOps;
}



int geraCaminhoEulerianoB(GrafoB* grafo){
    int numOps = 0, numRepeticoes;
    if(verificaEulerianoB(grafo) != 1) { return 0;}

    for(int i = 0; i<grafo->tamanho;i++){
        numRepeticoes = grafo->listaVertices[i]->tamanho;
        for(int j = 0; j < numRepeticoes; j++){
            numOps+=geraCircuitoB(grafo,grafo->listaVertices[i]);
        }
    }
    printf("\n");
    return numOps;
}


int geraCircuitoC(GrafoC* grafo,VerticeC* inicio){
    int numOps = 0;

    VerticeC* proximaAresta = grafo->listaVertices[inicio->lista[inicio->primeiro]->chave];
    VerticeC* atual;

    while (proximaAresta->chave != inicio->chave){
        atual = proximaAresta;
        proximaAresta = grafo->listaVertices[proximaAresta->lista[proximaAresta->primeiro]->chave];
        printf(" %d -> ",atual->chave);
        numOps+= removerArestaGrafoC(grafo,proximaAresta->chave,atual->chave);
    }
    printf("%d ->",proximaAresta->chave);
    return numOps;
}



int geraCaminhoEulerianoC(GrafoC* grafo){
    int numOps = 0, numRepeticoes;
    if(verificaEulerianoC(grafo) != 1) { return 0;}

    for(int i = 0; i<grafo->tamanho;i++){
        numRepeticoes = grafo->listaVertices[i]->tamanho;
        for(int j = 0; j < numRepeticoes; j++){
            numOps+=geraCircuitoC(grafo,grafo->listaVertices[i]);
        }
    }
    printf("\n");
    return numOps;
}

