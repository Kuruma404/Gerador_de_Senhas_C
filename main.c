#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int main(){

    int comp;
    char continuar;

    //as variaveis que vao compor a senha
    char *digitos = "0123456789";
    char *lowers =  "abcdefghijklmnopqrstuwxyz";
    char *uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *simbolos = "!@#$%&*";

    int digitosComp = strlen(digitos);
    int lowersComp = strlen(lowers);
    int uppersComp = strlen(uppers);
    int simbolosComp = strlen(simbolos);

    // GERAR NUMEROS PSEUDOALEATORIOS
    srand(time(NULL) * getpid());


    // ---- INICIO ----

    printf("----  GERADOR DE SENHAS  ----\n\n");


    // Loop para refazer a função caso " continuar = 'Y' "
    do{
        do{
            
            printf("Qual o comprimento da senha? \nSua resposta: ");
            scanf("%d", &comp);
            
            //retorna o resultado de falha do programa
            if (comp < 5)
            { printf("\nERRO: A senha precisa ter o comprimento maior que 4!\n\n"); }

        } while (comp < 5);
            
        
        printf("\n-----------------------------\n");

        
        //aloca espaço para a senha
        char *senha = malloc(comp + 1);  

    
        //montando a senha
        for(int i = 0; i < comp; i++){

            int charTipo = rand() % 4;

                switch(charTipo){
                case 0:
                    senha[i] = digitos[rand() % digitosComp];
                    break;
                case 1:
                    senha[i] = lowers[rand() % lowersComp];
                    break;
                case 2:
                    senha[i] = uppers[rand() % uppersComp];
                    break;
                default:
                    senha[i] = simbolos[rand() % simbolosComp];
                }
        }

        senha[comp] = '\0';
        printf("Sua senha: %s\n\n", senha);

        
        printf("Refazer senha? [Y/N]: ");
        scanf("%s", &continuar);

        free(senha);

    }while(continuar == 'Y' || continuar == 'y');

    return 0;
}
