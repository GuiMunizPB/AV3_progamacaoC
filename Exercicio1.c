//Grupo: Guilherme Muniz, Luana de Mero, Camila Vasconcelos, Ravi de Almeida.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *arq;
    arq = fopen("funcionarios.dat", "w");
    if(arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    // struct de registro com funcionarios, numero de registro, nivel salarial e departamento
    typedef struct
    {
        char nome[30];
        int numRegistro;
        int nivelSalarial;
        int departamento;
    } Funcionario;
    // loop para preencher a struct com os dados dos funcionarios
    int i;
    for(int i = 0; i < 5; i++)
    {
        Funcionario funcionario;
        printf("Digite o nome do funcionario: ");
        scanf("%s", funcionario.nome);
        printf("Digite o numero de registro do funcionario: ");
        scanf("%d", &funcionario.numRegistro);
        printf("Digite o nivel salarial do funcionario: ");
        scanf("%d", &funcionario.nivelSalarial);
        printf("Digite o departamento do funcionario: ");
        scanf("%d", &funcionario.departamento);
        system("cls");
        // escreve os dados no arquivo
        fwrite(&funcionario, sizeof(Funcionario), 1, arq);
    }
    


    return 0;
}