//Grupo: Guilherme Muniz, Luana de Mero, Camila Vasconcelos, Ravi de Almeida.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>



int main()
{
    FILE *arq1, *arq2;
    arq1 = fopen("funcionarios.dat", "w+");
    if(arq1 == NULL)
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
        int proximo;
    } Funcionario;
    
    Funcionario funcionario_0, funcionario_1, funcionario_2, funcionario_3, 
    funcionario_4, funcionario_5, funcionario_6, funcionario_7, funcionario_8, 
    funcionario_9, funcionario_10, funcionario_11, funcionario_12;

    // preenchendo os dados dos funcionarios
    strcpy(funcionario_0.nome, "Joao");
    funcionario_0.numRegistro = 123;
    funcionario_0.nivelSalarial = 7;
    funcionario_0.departamento = 1;
    funcionario_0.proximo = 5;

    strcpy(funcionario_1.nome, "Maria");
    funcionario_1.numRegistro = 8765;
    funcionario_1.nivelSalarial = 12;
    funcionario_1.departamento = 1;
    funcionario_1.proximo = -1;

    strcpy(funcionario_2.nome, "Jose");
    funcionario_2.numRegistro = 9210;
    funcionario_2.nivelSalarial = 4;
    funcionario_2.departamento = 2;
    funcionario_2.proximo = -1;

    strcpy(funcionario_3.nome, "Ana");
    funcionario_3.numRegistro = 2628;
    funcionario_3.nivelSalarial = 4;
    funcionario_3.departamento = 3;
    funcionario_3.proximo = 6;

    strcpy(funcionario_4.nome, "Pedro");
    funcionario_4.numRegistro = 5571;
    funcionario_4.nivelSalarial = 8;
    funcionario_4.departamento = 2;
    funcionario_4.proximo = -1;

    strcpy(funcionario_5.nome, "Paulo");
    funcionario_5.numRegistro = 652;
    funcionario_5.nivelSalarial = 1;
    funcionario_5.departamento = 1;
    funcionario_5.proximo = 9;

    strcpy(funcionario_6.nome, "Julia");
    funcionario_6.numRegistro = 7943;
    funcionario_6.nivelSalarial = 1;
    funcionario_6.departamento = 3;
    funcionario_6.proximo = -1;

    strcpy(funcionario_7.nome, "Marcos");
    funcionario_7.numRegistro = 671;
    funcionario_7.nivelSalarial = 5;
    funcionario_7.departamento = 3;
    funcionario_7.proximo = 12;

    strcpy(funcionario_8.nome, "Carla");
    funcionario_8.numRegistro = 1956;
    funcionario_8.nivelSalarial = 11;
    funcionario_8.departamento = 2;
    funcionario_8.proximo = 11;

    strcpy(funcionario_9.nome, "Ricardo");
    funcionario_9.numRegistro = 398;
    funcionario_9.nivelSalarial = 6;
    funcionario_9.departamento = 1;
    funcionario_9.proximo = 10;

    strcpy(funcionario_10.nome, "Juliana");
    funcionario_10.numRegistro = 3356;
    funcionario_10.nivelSalarial = 3;
    funcionario_10.departamento = 1;
    funcionario_10.proximo = 1;

    strcpy(funcionario_11.nome, "Leticia");
    funcionario_11.numRegistro = 4050;
    funcionario_11.nivelSalarial = 2;
    funcionario_11.departamento = 2;
    funcionario_11.proximo = 4;

    strcpy(funcionario_12.nome, "Rafael");
    funcionario_12.numRegistro = 2468;
    funcionario_12.nivelSalarial = 9;
    funcionario_12.departamento = 3;
    funcionario_12.proximo = 3;

    // escrevendo os dados no arquivo
    fprintf(arq1, "%s %d %d %d %d", funcionario_0.nome, funcionario_0.numRegistro, funcionario_0.nivelSalarial, funcionario_0.departamento, funcionario_0.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_1.nome, funcionario_1.numRegistro, funcionario_1.nivelSalarial, funcionario_1.departamento, funcionario_1.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_2.nome, funcionario_2.numRegistro, funcionario_2.nivelSalarial, funcionario_2.departamento, funcionario_2.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_3.nome, funcionario_3.numRegistro, funcionario_3.nivelSalarial, funcionario_3.departamento, funcionario_3.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_4.nome, funcionario_4.numRegistro, funcionario_4.nivelSalarial, funcionario_4.departamento, funcionario_4.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_5.nome, funcionario_5.numRegistro, funcionario_5.nivelSalarial, funcionario_5.departamento, funcionario_5.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_6.nome, funcionario_6.numRegistro, funcionario_6.nivelSalarial, funcionario_6.departamento, funcionario_6.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_7.nome, funcionario_7.numRegistro, funcionario_7.nivelSalarial, funcionario_7.departamento, funcionario_7.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_8.nome, funcionario_8.numRegistro, funcionario_8.nivelSalarial, funcionario_8.departamento, funcionario_8.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_9.nome, funcionario_9.numRegistro, funcionario_9.nivelSalarial, funcionario_9.departamento, funcionario_9.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_10.nome, funcionario_10.numRegistro, funcionario_10.nivelSalarial, funcionario_10.departamento, funcionario_10.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_11.nome, funcionario_11.numRegistro, funcionario_11.nivelSalarial, funcionario_11.departamento, funcionario_11.proximo);
    fprintf(arq1, "\n%s %d %d %d %d", funcionario_12.nome, funcionario_12.numRegistro, funcionario_12.nivelSalarial, funcionario_12.departamento, funcionario_12.proximo);

    fclose(arq1);

    arq2 = fopen("departamentos.dat", "w+");
    if (arq2 == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //struct para os departamentos

    typedef struct Departamento
    {;
        int codDepto;
        char nomeDepto[30];
        int inicio;
    } Departamento;

    Departamento departamento_0, departamento_1, departamento_2, departamento_3;

    //preenchendo dados dos departamentos
    departamento_0.codDepto = 1;
    strcpy(departamento_0.nomeDepto, "Vendas");
    departamento_0.inicio = 0;

    departamento_1.codDepto = 2;
    strcpy(departamento_1.nomeDepto, "Contabilidade");
    departamento_1.inicio = 8;

    departamento_2.codDepto = 3;
    strcpy(departamento_2.nomeDepto, "Estoque");
    departamento_2.inicio = 7;

    departamento_3.codDepto = 4;
    strcpy(departamento_3.nomeDepto, "Entrega");
    departamento_3.inicio = 2;

    //escrevendo os dados no arquivo
    fprintf(arq2, "%d %s %d", departamento_0.codDepto, departamento_0.nomeDepto, departamento_0.inicio);
    fprintf(arq2, "\n%d %s %d", departamento_1.codDepto, departamento_1.nomeDepto, departamento_1.inicio);
    fprintf(arq2, "\n%d %s %d", departamento_2.codDepto, departamento_2.nomeDepto, departamento_2.inicio);
    fprintf(arq2, "\n%d %s %d", departamento_3.codDepto, departamento_3.nomeDepto, departamento_3.inicio);

    fclose(arq2);

}