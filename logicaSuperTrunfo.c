#include <stdio.h>
#include <string.h>

   /*
    Super Trunfo - Comparação de Cartas
    
    Neste jogo, simulamos duas cartas de países e permitimos ao usuário
    escolher um atributo para comparar entre essas cartas por meio de um menu interativo (switch).
    A lógica de comparação é feita com if-else, incluindo casos de empate
    e a regra especial para densidade demográfica (menor valor vence).
*/

int main() {
    
    char pais1[50] = "Brasil";
    char pais2[50] = "Bolívia";

    unsigned long int populacao1 = 154000000; 
    unsigned long int populacao2 = 28000000;  
    float area1 = 8415000.0; 
    float area2 = 2520000.0;

    float pib1 = 1500.0; 
    float pib2 = 800.0;

    int pontos1 = 50;
    int pontos2 = 30;

    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;


    int opcao;
    printf("----- SUPER TRUNFO - MENU DE COMPARACAO -----\n");
    printf("1 - Nome do Pais\n");
    printf("2 - Populacao\n");
    printf("3 - Area\n");
    printf("4 - PIB\n");
    printf("5 - Numero de Pontos Turisticos\n");
    printf("6 - Densidade Demografica\n");
    printf("Escolha um atributo para comparar (1 a 6): ");
    scanf("%d", &opcao);

    printf("\n----- RESULTADO -----\n");
    switch(opcao) {
        case 1: 
            printf("Comparacao por Nome do Pais:\n");
            printf("Carta 1: %s\n", pais1);
            printf("Carta 2: %s\n", pais2);
            printf("O atributo Nome nao define vencedor.\n");
            break;

        case 2: 
            printf("Comparacao por Populacao:\n");
            printf("%s: %lu habitantes\n", pais1, populacao1);
            printf("%s: %lu habitantes\n", pais2, populacao2);

            if (populacao1 > populacao2) {
                printf("Vencedor: %s\n", pais1);
            } else if (populacao2 > populacao1) {
                printf("Vencedor: %s\n", pais2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: 
            printf("Comparacao por Area:\n");
            printf("%s: %.2f km²\n", pais1, area1);
            printf("%s: %.2f km²\n", pais2, area2);

            if (area1 > area2) {
                printf("Vencedor: %s\n", pais1);
            } else if (area2 > area1) {
                printf("Vencedor: %s\n", pais2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: 
            printf("Comparacao por PIB:\n");
            printf("%s: %.2f bilhoes de reais\n", pais1, pib1);
            printf("%s: %.2f bilhoes de reais\n", pais2, pib2);

            if (pib1 > pib2) {
                printf("Vencedor: %s\n", pais1);
            } else if (pib2 > pib1) {
                printf("Vencedor: %s\n", pais2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: 
            printf("Comparacao por Pontos Turisticos:\n");
            printf("%s: %d pontos\n", pais1, pontos1);
            printf("%s: %d pontos\n", pais2, pontos2);

            if (pontos1 > pontos2) {
                printf("Vencedor: %s\n", pais1);
            } else if (pontos2 > pontos1) {
                printf("Vencedor: %s\n", pais2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 6: 
            printf("Comparacao por Densidade Demografica:\n");
            printf("%s: %.2f hab/km²\n", pais1, densidade1);
            printf("%s: %.2f hab/km²\n", pais2, densidade2);

            if (densidade1 < densidade2) {
                printf("Vencedor: %s\n", pais1);
            } else if (densidade2 < densidade1) {
                printf("Vencedor: %s\n", pais2);
            } else {
                printf("Empate!\n");
            }
            break;

        default: 
            printf("Opcao invalida! \n");
            break;
    }

    return 0;
}