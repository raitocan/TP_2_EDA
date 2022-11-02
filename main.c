#include "grafoA.h"
#include "grafoB.h"
#include "grafoC.h"
#include "grafoD.h"
#include "grafoE.h"
#include "grafoF.h"
#include "circuitoEuleriano.h"


int main() {
    int qualTeste = 2,arquivo = 1,numOp = 0;
    if(qualTeste == 0){
        if(arquivo == 0 ){
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
            //removerVertice(grafo,1);
            //inserirAresta(grafo,1,2);
            removerTodasArestasA(grafo);
            imprimirGrafo(grafo);
        } else {
            GrafoA *grafoA = inicializaGrafoAArquivo("../graph100.txt",100);
            //numOp += removerTodasArestasA(grafoA);

            numOp+= geraCaminhoEulerianoA(grafoA);
            imprimirGrafo(grafoA);
        }
    }
    if(qualTeste == 1){
        if(arquivo == 0 ){
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
            //removerVerticeGrafoB(grafoB,1);
            //adicionaVerticeGrafoB(grafoB,2);
            removerTodasArestasB(grafoB);
            imprimeGrafoB(grafoB);
        } else {
            GrafoB *grafoB = inicializaGrafoBArquivo("../graph5.txt",5);// Mudar o TamMax TAMBÉM

            //numOp+= removerTodasArestasB(grafoB);
            //imprimeGrafoB(grafoB);
            //printf("Teste: %d\n",grafoB->primeiro);

            numOp+= geraCaminhoEulerianoB(grafoB);
            //imprimeVerticeB(grafoB->listaVertices[grafoB->listaIndices[grafoB->primeiro]]);


        }

    }
    if(qualTeste == 2){
        if(arquivo == 0 ){
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
            //removerVerticeGrafoC(grafoC,1);
            removerTodasArestasC(grafoC);
            imprimeGrafoC(grafoC);
        } else {
            GrafoC *grafoC = inicializaGrafoCArquivo("../graph100.txt",100);
            //removerArestaGrafoC(grafoC,41,43);
            //numOp+= removerTodasArestasC(grafoC);
            imprimeGrafoC(grafoC);
            numOp+= geraCaminhoEulerianoC(grafoC);

        }
    }
    if(qualTeste == 3){
        if(arquivo == 0){
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
            //removerVerticeD(grafoD,1);
            removerTodasArestasD(grafoD);
            imprimeGrafoD(grafoD);
        } else {
            GrafoD *grafoD = inicializaGrafoDArquivo("../graph100.txt",100);
            //numOp+= removerTodasArestasD(grafoD);
            //imprimeGrafoD(grafoD);

            numOp += geraCaminhoEulerianoD(grafoD);

        }

    }
    if(qualTeste == 4){
        if(arquivo == 0){
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
            //removerVerticeE(grafoE,1);
            removerTodasArestasE(grafoE);
            imprimeGrafoE(grafoE);
        } else {
            GrafoE *grafoE = inicializaGrafoEArquivo("../graph100.txt",100);
            //numOp += removerTodasArestasE(grafoE);
            //imprimeGrafoE(grafoE);

            numOp += geraCaminhoEulerianoE(grafoE);
            imprimeGrafoE(grafoE);

        }
    }
    if(qualTeste == 5){
        if(arquivo == 0) {
            GrafoF *grafoF = inicializaGrafoF();
            adicionaVerticeGrafoF(grafoF, 18);
            adicionaVerticeGrafoF(grafoF, 10);
            adicionaVerticeGrafoF(grafoF, 1);

            adicionarArestaGrafoF(grafoF, 1, 10);
            adicionarArestaGrafoF(grafoF, 1, 18);
            adicionarArestaGrafoF(grafoF, 10, 18);
            adicionarArestaGrafoF(grafoF, 1, 10);

            imprimeGrafoF(grafoF);

            //removerArestaF(grafoF,1,10);
            //removerVerticeF(grafoF,1);
            removerTodasArestasF(grafoF);
            imprimeGrafoF(grafoF);
        } else {
            GrafoF *grafoF = inicializaGrafoFArquivo("../graph5.txt",5);
            //numOp += removerTodasArestasF(grafoF);
            imprimeGrafoF(grafoF);
            //printf("%d\n", verificaEuleriano(grafoF));

            //eraCircuitoF(grafoF,grafoF->inicio);
            numOp += geraCaminhoEulerianoF(grafoF);
            //imprimeGrafoF(grafoF);

        }

    }
    printf("Numero de operacoes basicas: %d\n",numOp);
    return 0;
}
