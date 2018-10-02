# Hanói Dinamico  
  
Abordagem do problema de Torres de Hanói com uso de Programação Dinâmica,
resultando em complexidade de tempo linear; na Linguagem C.
 
Exemplo de versão exponencial: https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/  
    
# Resumo  

Dadas (3) Torres de Hanói e "n" Discos  
O programa a seguir tem como saída a sequência dos movimentos necessários para levar "n" discos 
de uma torre "A"(inicial) para outra "C"(final), com uma auxiliar "B", no menor número de movimentos possível.    
  
Seguindo o código:  
(A: Inicial; B: Auxiliar; C: Final)    
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
(Concatenando sequências de movimentos)  
```   
  
Mover Pilha de X discos da torre Inicial para a Auxiliar:  
[Movimento de 2 de uma pilha de X-1 discos] + movimento 1 do disco X + [Movimento de 6 de uma pilha de X-1 discos]  
  
  
Mover Pilha de X discos da torre Auxiliar para a Final:  
[Movimento de 4 de uma pilha de X-1 discos] + movimento 3 do disco X + [Movimento de 2 de uma pilha de X-1 discos]  
  
  
Mover Pilha de X discos da torre Final para a Inicial:  
[Movimento de 6 de uma pilha de X-1 discos] + movimento 5 do disco X + [Movimento de 4 de uma pilha de X-1 discos]  
  
  
Mover Pilha de X discos da torre Inicial para a Final:  
[Movimento de 1 de uma pilha de X-1 discos] + movimento 2 do disco X + [Movimento de 3 de uma pilha de X-1 discos]  
  
  
Mover Pilha de X discos da torre Auxiliar para a Inicial:  
[Movimento de 3 de uma pilha de X-1 discos] + movimento 4 do disco X + [Movimento de 5 de uma pilha de X-1 discos]  
  
  
Mover Pilha de X discos da torre Final para a Auxiliar:  
[Movimento de 5 de uma pilha de X-1 discos] + movimento 6 do disco X + [Movimento de 1 de uma pilha de X-1 discos]  
```  
  
  
    Por meio da Programação Dinâmica, a complexidade de tempo exponencial pode ser reduzida para O(n).
  
# Exemplo de Saída  
```  
Numero de discos(Max: 27): 5  
31 movimentos:  
2162432165462162432465432162432  
  
  
Para 3 Torres:   A : Inicio     B : Auxiliar    C : Destino  
  
  
Movimentos:     A->B = 1         B->C = 3        C->A = 5  
                A->C = 2         B->A = 4        C->B = 6  
```  
  
