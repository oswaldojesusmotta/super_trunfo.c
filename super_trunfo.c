#include <stdio.h>

int main() {
    // Declaração das variáveis da Carta 1
    char estado1[3];
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    // Declaração das variáveis da Carta 2
    char estado2[3];
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    // Entrada dos dados da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf(" %s", estado1);
    printf("Código da Carta (ex: A01): ");
    scanf(" %s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculo dos indicadores da Carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Entrada dos dados da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf(" %s", estado2);
    printf("Código da Carta (ex: B02): ");
    scanf(" %s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo dos indicadores da Carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Exibição dos dados calculados
    printf("\nIndicadores calculados:\n");
    printf("Carta 1 - %s (%s): Densidade = %.2f hab/km², PIB per Capita = %.2f reais\n", nomeCidade1, estado1, densidade1, pibPerCapita1);
    printf("Carta 2 - %s (%s): Densidade = %.2f hab/km², PIB per Capita = %.2f reais\n", nomeCidade2, estado2, densidade2, pibPerCapita2);

    // Comparação baseada em População
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d habitantes\n", nomeCidade2, estado2, populacao2);

    // Estrutura de decisão para determinar a vencedora
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
