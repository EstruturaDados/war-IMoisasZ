#include <stdio.h>  // Biblioteca padrão para funções de entrada e saída (ex: printf, scanf)
#include <string.h> // Biblioteca para manipulação de cadeias de caracteres (strings)

// Definição da estrutura que agrupa os dados de um território
struct Territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para limpar o buffer do teclado e evitar erros em leituras consecutivas
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função principal: ponto de partida onde a execução do programa começa
int main()
{
    struct Territorio war[5]; // Declaração do vetor de estruturas
    int totalTerritorios = 0;               // Contador para controlar o preenchimento

    printf("=========================================================\n");
    printf("\nVamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");

    // Estrutura de repetição para entrada de dados dos territórios
    do
    {
        printf("--- Cadastrando Territorio %d ---\n", totalTerritorios + 1);

        printf("Nome do territorio: ");
        scanf(" %s", war[totalTerritorios].nome); // Lê a primeira palavra do nome
        limparBuffer(); // Remove o 'Enter' para que a próxima leitura de texto funcione corretamente

        printf("Cor do exercito (ex: Azul, Verde): ");
        fgets(war[totalTerritorios].cor, 10, stdin); // Lê a cor limitando o tamanho
        // Localiza o caractere de nova linha (\n) e o remove
        war[totalTerritorios].cor[strcspn(war[totalTerritorios].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &war[totalTerritorios].tropas); // Lê o valor inteiro de tropas
        limparBuffer(); // Limpa o buffer após ler o número, evitando erros no próximo ciclo do loop

        totalTerritorios++; // Incrementa para passar ao próximo índice
        printf("\n");
    } while (totalTerritorios < 5);

    // Cabeçalho da exibição dos dados cadastrados
    printf("=========================================================\n");
    printf("            MAPA DO MUNDO - ESTADO ATUAL                 \n");
    printf("=========================================================\n\n");

    // Laço para percorrer o vetor e imprimir as informações de cada território
    for (int i = 0; i < 5; i++)
    {
        printf("TERRITORIO %d\n", i + 1);
        printf(" - Nome: %s\n", war[i].nome);
        printf(" - Dominado por: Exercito %s\n", war[i].cor);
        printf(" - Tropas: %d\n\n", war[i].tropas);
    }

    getchar(); // Pausa a execução aguardando uma tecla do usuário

    return 0; // Retorna 0 informando ao sistema que o programa encerrou normalmente
}