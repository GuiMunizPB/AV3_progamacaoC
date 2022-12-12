#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

// Grupo : Guilherme Muniz, Luana de Mero, Camila Vasconcelos e Ravi de Almeida.

// struct de registro com funcionarios, numero de registro, nivel salarial e
// departamento
typedef struct {
  char nome[30];
  int numRegistro;
  int nivelSalarial;
  int departamento;
  int proximo;
} Funcionario;
Funcionario funcionario[20];

// struct para os departamentos
typedef struct Departamento {
  int codDepto;
  char nomeDepto[30];
  int inicio;
} Departamento;
Departamento departamento[4];


// funcao que admite um funcionario
void admitirFuncionario(int *j) {
  FILE *arq1;
  arq1 = fopen("funcionarios.dat", "a+");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i, a = *j;

  printf("Digite o nome do funcionario: ");
  gets(funcionario[*j].nome);
  printf("Digite o numero de registro do funcionario: ");
  scanf("%d", &funcionario[*j].numRegistro);
  getchar();
  // verificar se o numero do funcionario existe
  for (i = 0; i < *j; i++) {
    if (funcionario[*j].numRegistro == funcionario[i].numRegistro) {
      printf("Numero de registro ja existente, digite outro numero: ");
      scanf("%d", &funcionario[*j].numRegistro);
    }
  }
  printf("Digite o nivel salarial do funcionario: ");
  scanf("%d", &funcionario[*j].nivelSalarial);
  printf("Digite o departamento do funcionario: ");
  scanf("%d", &funcionario[*j].departamento);
  funcionario[*j].proximo = -1;
  // mudar o proximo do ultimo funcionario do departamento
  for (i = 0; i < *j; i++) {
    if (funcionario[i].departamento == funcionario[*j].departamento &&
        funcionario[i].proximo == -1) {
      funcionario[i].proximo = *j;
    }
  }

  fprintf(arq1, "%s %d %d %d %d\n", funcionario[*j].nome,
          funcionario[*j].numRegistro, funcionario[*j].nivelSalarial,
          funcionario[*j].departamento, funcionario[*j].proximo);

  a++;
  *j = a;

  system("clear");

  fclose(arq1);
}


int main() {
    FILE *arq1, *arq2;
    arq1 = fopen("funcionarios.dat", "a+");
    arq2 = fopen("departamentos.dat", "a+");
    if (arq1 == NULL || arq2 == NULL) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    fclose(arq1);
    fclose(arq2);
    
    int menu, j=0, i;
    // medir o tamanho de casa preenchidas no vetor funcionario e atribuir a j
    for(i=0; i<20; i++) {
        printf("%s\n", funcionario[i].nome);
    }
    printf("%d", j);

    do {
    printf(
        "Escolha uma opção!\n0. Sair\n1. Admissão de funcionário\n2. "
        "Demissão de funcionário\n3. Mudança de Departamento\n4. Consulta a "
        "todos funcionários de um departamento\n5. Consulta Individual\n--> ");
    scanf("%d", &menu);
    switch (menu) {
    case 0:
      printf("Saindo...");
      break;
    case 1:
      admitirFuncionario(&j);
      break;
    case 2:
      demitirFuncionario(&j);
      break;
    case 3:
      mudarDepartamento(&j);
      break;
    case 4:
      consultarDepartamento(&j);
      break;
    case 5:
      consultarFuncionario(&j);
      break;
    }
  } while (menu != 0);

  return 0;
}
