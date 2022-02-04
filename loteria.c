#include<stdio.h>
#include<stdlib.h>
typedef struct {
 int numJogo;
 int numero[6];
}CARTELA;

typedef struct {
    int concurso;
    int numero[6];
}Resultado;

int acerto(int jogo[6], int resultado[6]){
    int qtd_acertos = 0;
    int i, z;
    for (i = 0; i < 6; i++){
        for ( z = 0; z < 6; z++){
            if (resultado[i] == jogo[z])
                qtd_acertos++;
        }
    }

    return qtd_acertos;

}

int existe(int num, int resultado[6]){

int i;

    for ( i = 0; i < 6; i++){
        if (num == resultado[i])
            return 1;
    }

    return 0;

}

int main(){

CARTELA *cartela;
Resultado resultado;
int N, i, qtw = 0, num_acertos, cont, acertos[6], nao_acertos;

    printf("Informe a quantidade de apostas: ");
    scanf("%d", &N);
    printf("----------------------\n");

    if (N >= 1 && N <= 1000)
    {
        cartela = (CARTELA*) malloc(N * sizeof(CARTELA));
        for (i = 0; i < N; i++){
            printf("Informe o número do jogo + sequência de números da cartela [%d de %d]:\n", i+1, N);
            scanf("%d %d %d %d %d %d %d", &cartela[i].numJogo, &cartela[i].numero[0], &cartela[i].numero[1], &cartela[i].numero[2], &cartela[i].numero[3], &cartela[i].numero[4], &cartela[i].numero[5]);
        }

        printf("----------------------\n");
        printf("Informe o núero do concurso + os 6 números correspondentes ao jogo realizado:\n");
        scanf("%d %d %d %d %d %d %d", &resultado.concurso, &resultado.numero[0], &resultado.numero[1], &resultado.numero[2], &resultado.numero[3], &resultado.numero[4], &resultado.numero[5]);
        printf("----------------------\n");

        for (i = 0; i < N; i++){
            num_acertos = acerto(cartela[i].numero, resultado.numero);
            if (num_acertos >= 4)
            {
                nao_acertos = 0;
                for (cont = 0; cont < 6; cont++)
                {   
                    if (existe(cartela[i].numero[cont], resultado.numero) == 1)
                        acertos[nao_acertos++] = cartela[i].numero[cont];
                }
                if (num_acertos == 4){
                    printf("QUADRA %d: %d %d %d %d\n", cartela[i].numJogo, acertos[0], acertos[1], acertos[2], acertos[3]);
                }
                if (num_acertos == 5)
                    printf("QUINA %d: %d %d %d %d %d\n", cartela[i].numJogo, acertos[0], acertos[1], acertos[2], acertos[3], acertos[4]);
                if (num_acertos == 6)
                    printf("SENA %d: %d %d %d %d %d %d\n", cartela[i].numJogo, resultado.numero[0], resultado.numero[1], resultado.numero[2], resultado.numero[3], resultado.numero[4], resultado.numero[5]);
                
                qtw++;
            }
            
        }
        if (qtw == 0)
            printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", resultado.concurso);
        
        free(cartela);
    }
    
}