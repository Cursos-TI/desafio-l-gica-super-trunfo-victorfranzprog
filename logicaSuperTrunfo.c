#include <stdio.h>
#include <string.h>

/*
    Super Trunfo - Nivel mestre

    Como funciona:
    - Comparação entre 2 cartas (Brasil e Bolivia, fixas neste exemplo)
    - Jogador escolhe DOIS atributos diferentes (menus dinâmicos)
    - Para cada atributo, aplica-se a regra:
        * Maior valor vence (exceto densidade, menor vence)
    - Soma dos valores dos 2 atributos determina o vencedor final
    - Tratamento de empate
    - Uso de switch, if-else aninhado e operador ternário
*/

int main() {
    // --- Dados fixos das cartas ---
    char pais1[50] = "Brasil";
    char pais2[50] = "Bolivia";

    unsigned long int populacao1 = 214000000;
    unsigned long int populacao2 = 46000000;

    float area1 = 8516000.0;
    float area2 = 2780000.0;

    float pib1 = 1600.0;
    float pib2 = 600.0;

    int pontos1 = 50;
    int pontos2 = 30;

    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;

    // --- Variáveis de controle ---
    int atributo1, atributo2;
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    float soma_c1 = 0, soma_c2 = 0;

    // --- Menu 1 ---
    printf("===== SUPER TRUNFO - DESAFIO FINAL =====\n");
    printf("Escolha o primeiro atributo:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &atributo1);

    // Atribui valores do primeiro atributo
    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontos1; valor1_c2 = pontos2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    // --- Menu 2 (dinâmico: não mostra o atributo escolhido antes) ---
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    if (atributo1 != 1) printf("1 - Populacao\n");
    if (atributo1 != 2) printf("2 - Area\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turisticos\n");
    if (atributo1 != 5) printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &atributo2);

    if (atributo2 == atributo1) {
        printf("Erro: nao pode escolher o mesmo atributo duas vezes!\n");
        return 1;
    }

    // Atribui valores do segundo atributo
    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontos1; valor2_c2 = pontos2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    // --- Exibir resultado da comparação ---
    printf("\n===== RESULTADO =====\n");
    printf("%s vs %s\n", pais1, pais2);

    // Comparação do atributo 1
    printf("\nAtributo 1 escolhido: ");
    switch (atributo1) {
        case 1: printf("Populacao\n"); break;
        case 2: printf("Area\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turisticos\n"); break;
        case 5: printf("Densidade Demografica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", pais1, valor1_c1, pais2, valor1_c2);

    // Comparação do atributo 2
    printf("\nAtributo 2 escolhido: ");
    switch (atributo2) {
        case 1: printf("Populacao\n"); break;
        case 2: printf("Area\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turisticos\n"); break;
        case 5: printf("Densidade Demografica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", pais1, valor2_c1, pais2, valor2_c2);

    // --- Regra de comparação (uso do ternário e if-else aninhado) ---
    soma_c1 += (atributo1 == 5) ? (1 / valor1_c1) : valor1_c1;
    soma_c2 += (atributo1 == 5) ? (1 / valor1_c2) : valor1_c2;
    soma_c1 += (atributo2 == 5) ? (1 / valor2_c1) : valor2_c1;
    soma_c2 += (atributo2 == 5) ? (1 / valor2_c2) : valor2_c2;

    // --- Resultado Final ---
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", pais1, soma_c1);
    printf("%s: %.2f\n", pais2, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\nVencedor: %s\n", pais1);
    } else if (soma_c2 > soma_c1) {
        printf("\nVencedor: %s\n", pais2);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}