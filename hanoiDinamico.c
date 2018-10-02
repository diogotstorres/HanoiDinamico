// TORRES DE HANÓI COM PROGRAMAÇÃO DINÂMICA ("BOTTOM UP")
//
// AUTOR: DIOGO TORRES DA SILVEIRA
//
// DADAS (3) TORRES DE HANÓI E "N" DISCOS
// O PROGRAMA A SEGUIR TEM COMO SAÍDA A ORDEM DO MENOR NÚMERO DE MOVIMENTOS NECESSÁRIOS
// PARA LEVAR "N" DISCOS DE UMA TORRE "A" PARA OUTRA "C", COM UMA AUXILIAR "B"
// SEGUINDO O CÓDIGO:    A:INICIAL      B:AUXILIAR      C:FINAL
//                       A->B = 1       B->C = 3        C->A = 5
//                       A->C = 2       B->A = 4        C->B = 6
//
// REPETIÇÃO DE SUBPROBLEMAS:
// CADA DISCO DE TAMANHO "X" REALIZA, NO MÁXIMO, 3 MOVIMENTOS DIFERENTES, QUE SE REPETEM.
//
// OS MOVIMENTOS DE UMA PILHA DE X DISCOS PODEM SER DEFINIDOS EM FUNÇÃO DOS DE UMA DE X-1
// ASSIM, A SUBESTRUTURA ÓTIMA SE DÁ CONFORME:
//
// MOVER PILHA DE X DISCOS DA INICIAL PARA A FINAL:
// [MOVIMENTO 1 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 2 DO DISCO X + [MOVIMENTO 3 DE UMA PILHA DE X-1 DISCOS]
//
// MOVER PILHA DE X DISCOS DA AUXILIAR PARA A INICIAL:
// [MOVIMENTO 3 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 4 DO DISCO X + [MOVIMENTO 5 DE UMA PILHA DE X-1 DISCOS]
//
// MOVER PILHA DE X DISCOS DA FINAL PARA A AUXILIAR:
// [MOVIMENTO 5 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 6 DO DISCO X + [MOVIMENTO 1 DE UMA PILHA DE X-1 DISCOS]
//
// MOVER PILHA DE X DISCOS DA INICIAL PARA A AUXILIAR:
// [MOVIMENTO 2 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 1 DO DISCO X + [MOVIMENTO 6 DE UMA PILHA DE X-1 DISCOS]
//
// MOVER PILHA DE X DISCOS DA AUXILIAR PARA A FINAL:
// [MOVIMENTO 4 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 3 DO DISCO X + [MOVIMENTO 2 DE UMA PILHA DE X-1 DISCOS]
//
// MOVER PILHA DE X DISCOS DA FINAL PARA A INICIAL:
// [MOVIMENTO 6 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 5 DO DISCO X + [MOVIMENTO 4 DE UMA PILHA DE X-1 DISCOS]
//
//
//
//    POR MEIO DA PROGRAMAÇÃO DINÂMICA, A COMPLEXIDADE DE TEMPO EXPONENCIAL PODE SER REDUZIDA PARA O(n)
//
//
//
#include <stdio.h>
#include <math.h>

int main(){

    int nDiscos, i;
    printf("Numero de discos(Max: 27): ");         // ATÉ 27, LIMITAÇÕES DE MEMÓRIA
    scanf("%d", &nDiscos);
    //nDiscos = 21;                                //PARA TESTES DE TEMPO
    unsigned long long int x = pow(2,nDiscos)-1;   //TOTAL DE MOVIMENTOS
    printf("%llu movimentos:\n", x);

    char **arr[7];
    for(int i=1; i<7; i++)           // 6 ARRAYS, CADA UM COM UMA "STRING"  (ARR[0] IGNORADO PARA FACILITAR COMPREENÇÃO)
        arr[i] = malloc(sizeof(char)* x*2) ;        //TAMANHO DA STRING ALOCADO DINAMICAMENTE PARA OTIMIZAR TEMPO/ESPAÇO


    // INICIALIZAÇÃO COM CÓDIGOS DOS CASOS BASE DA MOVIMENTAÇÃO DOS DISCOS
    // CODIFICAÇÃO POSSIBILITA UMA OCUPAÇÃO EFICIENTE DO ARRAY
    // 3 CASOS BASE SERÃO USADOS, PARES OU ÍMPARES

    strcpy(arr[1],"1"); // TORRE INICIAL PARA AUXILIAR
    strcpy(arr[2],"2"); // TORRE INICIAL PARA FINAL
    strcpy(arr[3],"3"); // TORRE AUXILIAR PARA FINAL
    strcpy(arr[4],"4"); // TORRE AUXILIAR PARA INICIAL
    strcpy(arr[5],"5"); // TORRE FINAL PARA INICIAL
    strcpy(arr[6],"6"); // TORRE FINAL PARA AUXILIAR

    int ehImpar = nDiscos%2;                       //NÚMERO DE DISCOS É   0:PAR;  OU  1:ÍMPAR

    //CONSTRUÇÃO DA SEQUÊNCIA DE MOVIMENTOS ÓTIMA POR CONCATENAÇÃO DE "STRINGS" (BOTTOM UP)

    for (i=2; i<=nDiscos; i++){                    // ########  TEMPO:  O(n)
        if( (i+ehImpar)%2==0 ){                    // ALTERNA ENTRE OS MOVIMENTOS PARES E ÍMPARES
            strcpy(arr[2],arr[1]);
            strcat(arr[2],"2"); // A->C
            strcat(arr[2],arr[3]);

            strcpy(arr[4],arr[3]);
            strcat(arr[4],"4"); // B->A
            strcat(arr[4],arr[5]);

            strcpy(arr[6],arr[5]);
            strcat(arr[6],"6"); // C->B
            strcat(arr[6],arr[1]);
        }                         // CADA DISCO MOVIMENTA-SE EM SOMENTE UM DESSES DOIS CICLOS
                                  // O DISCO ANTERIOR, NECESSARIAMENTE, EM UM CICLO DIFERENTE
                                  // PERMITINDO ASSIM, O USO DE UM ÚNICO ARRAY DE 6 "STRINGS"
        else{
            strcpy(arr[1],arr[2]);
            strcat(arr[1],"1"); // A->B
            strcat(arr[1],arr[6]);

            strcpy(arr[3],arr[4]);
            strcat(arr[3],"3"); // B->C
            strcat(arr[3],arr[2]);

            strcpy(arr[5],arr[6]);
            strcat(arr[5],"5"); // C->A
            strcat(arr[5],arr[4]);
        }
    }
    printf(arr[2]);                                //NO FINAL, POR DEFINIÇÃO, ARMAZENA A SEQUÊNCIA TOTAL   A->C

    for(int i=1; i<7; i++) free(arr[i]);           //LIBERAÇÃO DA MEMÓRIA DINAMICAMENTE ALOCADA

    printf("\n\n");
    printf("\nPara 3 Torres:");
    printf("\t A : Inicio\t B : Auxiliar\t C : Destino\n\n");
    printf("\nMovimentos:");
    printf("\tA->B = 1\t B->C = 3\t C->A = 5\n");
    printf("\t\tA->C = 2\t B->A = 4\t C->B = 6\n\n");

    return 0;
}

