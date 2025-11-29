#include <stdio.h>

int main() {
    
    int numeroSecreto = 42;  
    int palpite;             
    int tentativas = 0;     

    printf("****************************************\n");
    printf("* JOGO DE ADIVINHACAO         *\n");
    printf("****************************************\n");
    printf("Tente adivinhar o numero entre 1 e 100.\n\n");

    
    do {
       
        printf("Digite seu palpite: ");
        scanf("%d", &palpite);
        
        tentativas++; 

        
        if (palpite == numeroSecreto) {
            // Se acertou:
            printf("\nPARABENS! Voce acertou o numero %d!\n", numeroSecreto);
            printf("Voce usou %d tentativas.\n", tentativas);
        } 
        else if (palpite > numeroSecreto) {
            // Se chutou alto:
            printf("--> Errado. O numero secreto eh MENOR que %d.\n\n", palpite);
        } 
        else {
            // Se chutou baixo (só sobra essa opção):
            printf("--> Errado. O numero secreto eh MAIOR que %d.\n\n", palpite);
        }

    } while (palpite != numeroSecreto); // A condição que mantém o loop vivo

   
    printf("Fim de jogo. Obrigado por jogar!\n");

    return 0;
}