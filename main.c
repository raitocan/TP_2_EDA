#include "grafoA.h"
#include "grafoB.h"
#include "grafoC.h"

int main() {
    int qualTeste = 2;
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

    return 0;
}
