#include "grafoA.h"
#include "grafoB.h"
#include "grafoC.h"
#include "grafoD.h"
#include "grafoE.h"
#include "grafoF.h"



int main() {
    int qualTeste = 5;
    if(qualTeste == 0) {
        GrafoA* grafo = iniciaGrafo(50);
        adicionarVertice(grafo);
        adicionarVertice(grafo);
        adicionarVertice(grafo);
        adicionarVertice(grafo);
        inserirAresta(grafo,1,0);
        inserirAresta(grafo,1,3);
        inserirAresta(grafo,1,2);
        imprimirGrafo(grafo);
        //removerAresta(grafo,1,2);
        removerVertice(grafo,1);
        inserirAresta(grafo,1,2);
        imprimirGrafo(grafo);}
    if(qualTeste == 1){
        GrafoB* grafoB = inicializaGrafoB();
        adicionaVerticeGrafoB(grafoB,10);
        adicionaVerticeGrafoB(grafoB,117);
        adicionaVerticeGrafoB(grafoB,1);
        adicionaVerticeGrafoB(grafoB,7895);

        adicionarArestaGrafoB(grafoB,1,10);
        adicionarArestaGrafoB(grafoB,1,10);
        adicionarArestaGrafoB(grafoB,1,117);
        adicionarArestaGrafoB(grafoB,10,117);

        imprimeGrafoB(grafoB);

        //removerArestaGrafoB(grafoB,1,10);
        //removerArestaGrafoB(grafoB,1,10);
        removerVerticeGrafoB(grafoB,1);
        adicionaVerticeGrafoB(grafoB,2);

        imprimeGrafoB(grafoB);

    }
    if(qualTeste ==2){
        GrafoC* grafoC = inicializaGrafoC();
        adicionaVerticeGrafoC(grafoC,10);
        adicionaVerticeGrafoC(grafoC,117);
        adicionaVerticeGrafoC(grafoC,1);
        adicionaVerticeGrafoC(grafoC,7895);

        adicionarArestaGrafoC(grafoC,1,10);
        adicionarArestaGrafoC(grafoC,1,10);
        adicionarArestaGrafoC(grafoC,1,117);
        imprimeGrafoC(grafoC);

        //removerArestaGrafoC(grafoC,1,10);
        removerVerticeGrafoC(grafoC,1);
        imprimeGrafoC(grafoC);
    }
    if(qualTeste == 3){
        GrafoD*  grafoD = inicializaGrafoD();
        adicionaVerticeGrafoD(grafoD,18);
        adicionaVerticeGrafoD(grafoD,10);
        adicionaVerticeGrafoD(grafoD,1);

        adicionarArestaGrafoD(grafoD,1,10);
        adicionarArestaGrafoD(grafoD,1,18);
        adicionarArestaGrafoD(grafoD,10,18);
        adicionarArestaGrafoD(grafoD,1,10);

        imprimeGrafoD(grafoD);

        //removerArestaD(grafoD,1,10);
        removerVerticeD(grafoD,1);
        imprimeGrafoD(grafoD);

    }
    if(qualTeste == 4){
        GrafoE*  grafoE = inicializaGrafoE();
        adicionaVerticeGrafoE(grafoE,18);
        adicionaVerticeGrafoE(grafoE,10);
        adicionaVerticeGrafoE(grafoE,1);

        adicionarArestaGrafoE(grafoE,1,10);
        adicionarArestaGrafoE(grafoE,1,18);
        adicionarArestaGrafoE(grafoE,10,18);
        adicionarArestaGrafoE(grafoE,1,10);

        imprimeGrafoE(grafoE);

        //removerArestaE(grafoE,1,10);
        removerVerticeE(grafoE,1);
        imprimeGrafoE(grafoE);

    }
    if(qualTeste == 5){
        GrafoF* grafoF = inicializaGrafoF();
        adicionaVerticeGrafoF(grafoF,18);
        adicionaVerticeGrafoF(grafoF,10);
        adicionaVerticeGrafoF(grafoF,1);

        adicionarArestaGrafoF(grafoF,1,10);
        adicionarArestaGrafoF(grafoF,1,18);
        adicionarArestaGrafoF(grafoF,10,18);
        adicionarArestaGrafoF(grafoF,1,10);

        imprimeGrafoF(grafoF);

        //removerArestaF(grafoF,1,10);
        removerVerticeF(grafoF,1);
        //removerTodasArestasF(grafo)
        imprimeGrafoF(grafoF);

    }

    return 0;
}
