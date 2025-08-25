#include <stdio.h>

// Função para exibir o menu de atributos
void exibirMenu(int excluido) {
    printf("\nEscolha um atributo para comparação:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
}

// Função para obter o valor de um atributo
float obterValor(int atributo, int populacao, float area, float pib, int pontos, float densidade) {
    switch (atributo) {
        case 1: return (float)populacao;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return densidade;
        default: return -1;
    }
}

// Função para exibir o nome do atributo
void nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
}

int main() {
    // Dados fixos das cartas
    char pais1[] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 2200.0;
    int pontos1 = 15;
    float densidade1 = populacao1 / area1;

    char pais2[] = "Argentina";
    int populacao2 = 45300000;
    float area2 = 2780400.0;
    float pib2 = 500.0;
    int pontos2 = 10;
    float densidade2 = populacao2 / area2;

    int atributo1, atributo2;

    // Escolha do primeiro atributo
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Validação do primeiro atributo
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida!\n");
        return 1;
    }

    // Escolha do segundo atributo (excluindo o primeiro)
    exibirMenu(atributo1);
    scanf("%d", &atributo2);

    // Validação do segundo atributo
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida!\n");
        return 1;
    }

    // Obtenção dos valores dos atributos
    float valor1A = obterValor(atributo1, populacao1, area1, pib1, pontos1, densidade1);
    float valor2A = obterValor(atributo1, populacao2, area2, pib2, pontos2, densidade2);

    float valor1B = obterValor(atributo2, populacao1, area1, pib1, pontos1, densidade1);
    float valor2B = obterValor(atributo2, populacao2, area2, pib2, pontos2, densidade2);

    // Exibição dos valores
    printf("\nComparando %s e %s com base em dois atributos:\n", pais1, pais2);

    printf("\nAtributo 1: ");
    nomeAtributo(atributo1);
    printf("\n%s: %.2f\n", pais1, valor1A);
    printf("%s: %.2f\n", pais2, valor2A);

    printf("\nAtributo 2: ");
    nomeAtributo(atributo2);
    printf("\n%s: %.2f\n", pais1, valor1B);
    printf("%s: %.2f\n", pais2, valor2B);

    // Comparação com regra especial para densidade
    float soma1 = 0, soma2 = 0;

    soma1 += (atributo1 == 5) ? -valor1A : valor1A;
    soma2 += (atributo1 == 5) ? -valor2A : valor2A;

    soma1 += (atributo2 == 5) ? -valor1B : valor1B;
    soma2 += (atributo2 == 5) ? -valor2B : valor2B;

    // Exibição da soma
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", pais1, soma1);
    printf("%s: %.2f\n", pais2, soma2);

    // Resultado final com operador ternário
    printf("\nResultado: ");
    (soma1 > soma2) ? printf("%s venceu!\n", pais1) :
    (soma2 > soma1) ? printf("%s venceu!\n", pais2) :
                      printf("Empate!\n");

    return 0;
}
