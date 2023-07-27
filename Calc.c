#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Protótipos das funções
int binToDec(char *bin);
char *decToBin(int dec);
char *decToHex(int dec);
int hexToDec(char *hex);
char *binOp(char *bin1, char *bin2, char op);

int main() {
    char num1[100], num2[100];
    char op;
    int dec1, dec2, result;
    char *resultBin, *resultHex;

    printf("Calculadora de Programador\n");
    printf("Digite o primeiro número: ");
    scanf("%s", num1);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Digite o segundo número: ");
    scanf("%s", num2);

    // Converter para letras maiúsculas para facilitar a validação
    op = toupper(op);

    // Verificar o sistema numérico e converter para decimal
    if (isdigit(num1[0]))
        dec1 = atoi(num1);
    else if (num1[0] == '0' && (num1[1] == 'x' || num1[1] == 'X'))
        dec1 = hexToDec(num1 + 2);
    else
        dec1 = binToDec(num1);

    if (isdigit(num2[0]))
        dec2 = atoi(num2);
    else if (num2[0] == '0' && (num2[1] == 'x' || num2[1] == 'X'))
        dec2 = hexToDec(num2 + 2);
    else
        dec2 = binToDec(num2);

    // Realizar a operação e obter o resultado em decimal
    switch (op) {
        case '+':
            result = dec1 + dec2;
            break;
        case '-':
            result = dec1 - dec2;
            break;
        case '*':
            result = dec1 * dec2;
            break;
        case '/':
            if (dec2 == 0) {
                printf("Erro: divisão por zero não é permitida.\n");
                return 1;
            }
            result = dec1 / dec2;
            break;
        default:
            printf("Operador inválido.\n");
            return 1;
    }

    // Converter o resultado de volta para os sistemas numéricos binário e hexadecimal
    resultBin = decToBin(result);
    resultHex = decToHex(result);

    // Exibir resultados
    printf("Resultado em decimal: %d\n", result);
    printf("Resultado em binário: %s\n", resultBin);
    printf("Resultado em hexadecimal: %s\n", resultHex);

    // Liberar a memória alocada dinamicamente
    free(resultBin);
    free(resultHex);

    return 0;
}

// Função para converter um número binário em decimal
int binToDec(char *bin) {
    return strtol(bin, NULL, 2);
}

// Função para converter um número decimal em binário
char *decToBin(int dec) {
    char *bin = (char *)malloc(33 * sizeof(char));
    itoa(dec, bin, 2);
    return bin;
}

// Função para converter um número decimal em hexadecimal
char *decToHex(int dec) {
    char *hex = (char *)malloc(9 * sizeof(char));
    sprintf(hex, "%X", dec);
    return hex;
}

// Função para converter um número hexadecimal em decimal
int hexToDec(char *hex) {
    return strtol(hex, NULL, 16);
}
