#include <stdio.h>

int main() {
    // Variáveis
    char cidade1[20], cidade2[20], estado1[20], estado2[20];
    char codigo1[4], codigo2[4];
    unsigned long populacao1, populacao2;
    int pontos_turisticos1, pontos_turisticos2;
    float area1, Pib1, densidade_populacional1, Pib_percapita1;
    float area2, Pib2, densidade_populacional2, Pib_percapita2;

    printf("-------- SUPER TRUNFO DE CIDADES --------\n\n");

    // Cadastro Carta 1
    printf("** CARTA 1 **\n");
    printf("Estado: ");
    scanf("%s", estado1);
    printf("Código (3 letras): ");
    scanf("%s", codigo1);
    printf("Cidade: ");
    scanf("%s", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &Pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cálculos Carta 1
    densidade_populacional1 = populacao1 / area1;
    Pib_percapita1 = (Pib1 * 1e9) / populacao1; // PIB per capita em reais

    // Cadastro Carta 2 (mesmo processo)
    printf("\n** CARTA 2 **\n");
    printf("Estado: ");
    scanf("%s", estado2);
    printf("Código (3 letras): ");
    scanf("%s", codigo2);
    printf("Cidade: ");
    scanf("%s", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &Pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos Carta 2
    densidade_populacional2 = populacao2 / area2;
    Pib_percapita2 = (Pib2 * 1e9) / populacao2;

    // Exibição dos dados
    printf("\n--- RESULTADOS ---\n");
    printf("CARTA 1: %s-%s | Pop: %lu | Área: %.2f km² | PIB: R$ %.2f per capita\n",
           cidade1, estado1, populacao1, area1, Pib_percapita1);
    printf("CARTA 2: %s-%s | Pop: %lu | Área: %.2f km² | PIB: R$ %.2f per capita\n",
           cidade2, estado2, populacao2, area2, Pib_percapita2);

    // Menu de comparação
    int opcao;
    printf("\nEscolha o critério de comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - Pontos Turísticos\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: // População
            if (populacao1 > populacao2)
                printf("%s vence em população (%lu > %lu)!\n", cidade1, populacao1, populacao2);
            else
                printf("%s vence em população (%lu > %lu)!\n", cidade2, populacao2, populacao1);
            break;

        case 2: // Área
            if (area1 > area2)
                printf("%s vence em área (%.2f km² > %.2f km²)!\n", cidade1, area1, area2);
            else
                printf("%s vence em área (%.2f km² > %.2f km²)!\n", cidade2, area2, area1);
            break;

        case 3: // PIB
            if (Pib1 > Pib2)
                printf("%s vence em PIB (R$ %.2f bi > R$ %.2f bi)!\n", cidade1, Pib1, Pib2);
            else
                printf("%s vence em PIB (R$ %.2f bi > R$ %.2f bi)!\n", cidade2, Pib2, Pib1);
            break;

        case 4: // Densidade Populacional (quanto menor, melhor)
            if (densidade_populacional1 < densidade_populacional2)
                printf("%s vence em densidade (%.2f hab/km² < %.2f hab/km²)!\n", 
                       cidade1, densidade_populacional1, densidade_populacional2);
            else
                printf("%s vence em densidade (%.2f hab/km² < %.2f hab/km²)!\n", 
                       cidade2, densidade_populacional2, densidade_populacional1);
            break;

        case 5: // Pontos Turísticos
            if (pontos_turisticos1 > pontos_turisticos2)
                printf("%s vence em pontos turísticos (%d > %d)!\n", cidade1, pontos_turisticos1, pontos_turisticos2);
            else
                printf("%s vence em pontos turísticos (%d > %d)!\n", cidade2, pontos_turisticos2, pontos_turisticos1);
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
