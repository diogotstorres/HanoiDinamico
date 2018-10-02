# Hanoi Dinamico  
  
Abordagem do problema de Torres de Hanói com uso de Programação Dinâmica,
resultando em complexidade de tempo linear; na Linguagem C.
 
Exemplo de versão exponencial: https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/  
    
# Resumo  

Dadas (3) Torres de Hanói e "n" Discos  
O programa a seguir tem como saída a sequência dos movimentos necessários para levar "n" discos 
de uma torre "A"(inicial) para outra "C"(final), com uma auxiliar "B", no menor número de movimentos possível.    
  
Seguindo o código:  
(A:INICIAL; B:AUXILIAR; C:FINAL )    
A->B = 1    
B->C = 3                        
C->A = 5  
A->C = 2         
B->A = 4          
C->B = 6    
  
Repetição de Subproblemas:  
Cada disco (e, portanto, cada pilha) de tamanho "X" realiza, no máximo, 3 movimentos diferentes, que se repetem  
  
Os movimentos de uma pilha de "X" discos podem ser definidos em função de uma de "x-1" discos   
Assim, a subestrutura ótima de dá conforme:  
  
 MOVER PILHA DE X DISCOS DA INICIAL PARA A FINAL:  
 [MOVIMENTO 1 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 2 DO DISCO X + [MOVIMENTO 3 DE UMA PILHA DE X-1 DISCOS]  
  
 MOVER PILHA DE X DISCOS DA AUXILIAR PARA A INICIAL:  
 [MOVIMENTO 3 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 4 DO DISCO X + [MOVIMENTO 5 DE UMA PILHA DE X-1 DISCOS]  
  
 MOVER PILHA DE X DISCOS DA FINAL PARA A AUXILIAR:  
 [MOVIMENTO 5 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 6 DO DISCO X + [MOVIMENTO 1 DE UMA PILHA DE X-1 DISCOS]  
  
 MOVER PILHA DE X DISCOS DA INICIAL PARA A AUXILIAR:  
 [MOVIMENTO 2 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 1 DO DISCO X + [MOVIMENTO 6 DE UMA PILHA DE X-1 DISCOS]  
  
 MOVER PILHA DE X DISCOS DA AUXILIAR PARA A FINAL:  
 [MOVIMENTO 4 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 3 DO DISCO X + [MOVIMENTO 2 DE UMA PILHA DE X-1 DISCOS]  
  
 MOVER PILHA DE X DISCOS DA FINAL PARA A INICIAL:  
 [MOVIMENTO 6 DE UMA PILHA DE X-1 DISCOS] + MOVIMENTO 5 DO DISCO X + [MOVIMENTO 4 DE UMA PILHA DE X-1 DISCOS]  
    
  
  
    POR MEIO DA PROGRAMAÇÃO DINÂMICA, A COMPLEXIDADE DE TEMPO EXPONENCIAL PODE SER REDUZIDA PARA O(n)  
  
# Exemplo de Saída  
```  
Numero de discos(Max: 27): 5  
31 movimentos:  
2162432165462162432465432162432  
  
  
Para 3 Torres:   A : Inicio     B : Auxiliar    C : Destino  
  
  
Movimentos:     A->B = 1         B->C = 3        C->A = 5  
                A->C = 2         B->A = 4        C->B = 6  
```  
  
