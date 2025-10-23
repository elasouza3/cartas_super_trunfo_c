
#include <stdio.h>
#include <string.h>

/* --- Definição de atributos possíveis para comparação --- */
typedef enum {
    ATTR_POPULACAO,
    ATTR_AREA,
    ATTR_PIB,
    ATTR_DENSIDADE,      /* densidade = populacao / area -> menor vence */
    ATTR_PIB_PER_CAPITA  /* pib per capita = pib / populacao */
} AtributoComparacao;

/* <<< ESCOLHA AQUI O ATRIBUTO QUE SERÁ USADO NA COMPARAÇÃO >>> */
#define COMPARE_ATTRIBUTE ATTR_POPULACAO
/* Troque por: ATTR_AREA, ATTR_PIB, ATTR_DENSIDADE ou ATTR_PIB_PER_CAPITA */

/* --- Estrutura que representa uma carta --- */
typedef struct {
    char estado[50];      /* ex: "São Paulo" ou "SP" - qualquer string */
    char codigo[10];      /* código da carta */
    char nomeCidade[60];  /* nome da cidade */
    int populacao;        /* população (inteiro) */
    double area;          /* área em km^2 (float) */
    double pib;           /* PIB (unidade qualquer, ex: milhões) */
    int pontosTuristicos; /* número de pontos turísticos */
    /* campos calculados - mantidos por clareza */
    double densidade;     /* populacao / area */
    double pibPerCapita;  /* pib / populacao */
} Carta;

/* --- Funções auxiliares --- */

/* Calcula densidade populacional e PIB per capita para uma carta */
void calcularDerivados(Carta *c) {
    if (c->area != 0.0)
        c->densidade = (double)c->populacao / c->area;
    else
        c->densidade = 0.0; /* evitar divisão por zero (caso hipotético) */

    if (c->populacao != 0)
        c->pibPerCapita = c->pib / (double)c->populacao;
    else
        c->pibPerCapita = 0.0; /* evitar divisão por zero */
}

/* Imprime uma carta (valores e campos calculados) */
void imprimirCarta(const Carta *c, int numero) {
    printf("Carta %d - %s (%s)\n", numero, c->nomeCidade, c->estado);
    printf("  Código: %s\n", c->codigo);
    printf("  População: %d\n", c->populacao);
    printf("  Área: %.2f km^2\n", c->area);
    printf("  PIB: %.2f\n", c->pib);
    printf("  Pontos turísticos: %d\n", c->pontosTuristicos);
    printf("  Densidade populacional: %.4f hab/km^2\n", c->densidade);
    printf("  PIB per capita: %.6f (mesma unidade do PIB / habitante)\n", c->pibPerCapita);
    printf("\n");
}

/* Obtém o valor numérico do atributo selecionado (para comparação) */
double obterValorAtributo(const Carta *c, AtributoComparacao attr) {
    switch (attr) {
        case ATTR_POPULACAO:     return (double)c->populacao;
        case ATTR_AREA:          return c->area;
        case ATTR_PIB:           return c->pib;
        case ATTR_DENSIDADE:     return c->densidade;
        case ATTR_PIB_PER_CAPITA: return c->pibPerCapita;
        default: return 0.0;
    }
}

/* Nome do atributo em texto para exibição */
const char* nomeAtributo(AtributoComparacao attr) {
    switch (attr) {
        case ATTR_POPULACAO:     return "População";
        case ATTR_AREA:          return "Área (km^2)";
        case ATTR_PIB:           return "PIB";
        case ATTR_DENSIDADE:     return "Densidade Populacional (hab/km^2)";
        case ATTR_PIB_PER_CAPITA: return "PIB per capita";
        default: return "Atributo Desconhecido";
    }
}

/* --- Função principal --- */
int main(void) {
    /* Defina aqui as duas cartas (pré-definidas para o nível novato) */
    Carta carta1 = {
        .estado = "SP",
        .codigo = "C01",
        .nomeCidade = "São Paulo",
        .populacao = 12300000,    /* exemplo */
        .area = 1521.11,          /* km^2 */
        .pib = 700000.0,          /* ex: milhões (apenas exemplo) */
        .pontosTuristicos = 25
    };

    Carta carta2 = {
        .estado = "RJ",
        .codigo = "C02",
        .nomeCidade = "Rio de Janeiro",
        .populacao = 6000000,     /* exemplo */
        .area = 1182.32,          /* km^2 */
        .pib = 300000.0,          /* ex: milhões (apenas exemplo) */
        .pontosTuristicos = 30
    };

    /* Cálculo de campos derivados */
    calcularDerivados(&carta1);
    calcularDerivados(&carta2);

    /* Impressão das cartas e seus valores calculados */
    printf("=== Cartas cadastradas ===\n\n");
    imprimirCarta(&carta1, 1);
    imprimirCarta(&carta2, 2);

    /* Determinar o atributo que vamos comparar (macro COMPARE_ATTRIBUTE) */
    AtributoComparacao atributo = COMPARE_ATTRIBUTE;
    const char *nomeAttr = nomeAtributo(atributo);

    /* Obter os valores do atributo para cada carta */
    double valor1 = obterValorAtributo(&carta1, atributo);
    double valor2 = obterValorAtributo(&carta2, atributo);

    /* Exibir o cabeçalho da comparação */
    printf("Comparação de cartas (Atributo: %s)\n\n", nomeAttr);
    /* Formatação especial para população (inteiro) por legibilidade */
    if (atributo == ATTR_POPULACAO) {
        printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
    } else {
        printf("Carta 1 - %s (%s): %.6f\n", carta1.nomeCidade, carta1.estado, valor1);
        printf("Carta 2 - %s (%s): %.6f\n\n", carta2.nomeCidade, carta2.estado, valor2);
    }

    /* Decidir o vencedor:
       - Para Densidade Populacional (ATTR_DENSIDADE): menor valor vence.
       - Para todos os demais atributos: maior valor vence.
       Usamos if / if-else conforme pedido. */
    if (atributo == ATTR_DENSIDADE) {
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu! (menor densidade: %.4f < %.4f)\n",
                   carta1.nomeCidade, valor1, valor2);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu! (menor densidade: %.4f < %.4f)\n",
                   carta2.nomeCidade, valor2, valor1);
        } else {
            /* empate exato */
            printf("Resultado: Empate! Ambas as cartas têm densidade igual (%.4f).\n", valor1);
        }
    } else {
        /* maior valor vence */
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu! (%.6f > %.6f)\n",
                   carta1.nomeCidade, valor1, valor2);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu! (%.6f > %.6f)\n",
                   carta2.nomeCidade, valor2, valor1);
        } else {
            /* empate exato */
            printf("Resultado: Empate! Ambas as cartas têm o mesmo valor (%.6f).\n", valor1);
        }
    }

    return 0;
}