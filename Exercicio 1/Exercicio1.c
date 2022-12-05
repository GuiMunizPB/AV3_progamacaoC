#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

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

// funcao que admite novo funcionario no arquivo
void admitirFuncionario(int *j) {
  FILE *arq1;
  arq1 = fopen("funcionarios.dat", "a+");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i, a = *j;

  printf("Digite o nome do funcionario: ");
  scanf("%s", funcionario[*j].nome);
  printf("Digite o numero de registro do funcionario: ");
  scanf("%d", &funcionario[*j].numRegistro);
  // verificar se o numero do funcionario lena existe
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

// funcao que consulta individualmente um funcionario
void consultarFuncionario(int *j) {
  FILE *arq1;
  arq1 = fopen("funcionarios.dat", "r");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i, q = 0, numRegistro;

  printf("Digite o numero de registro do funcionario: ");
  scanf("%d", &numRegistro);
  // verificar se o numero do registro existe no arquivo
  do {
    for (i = 0; i < *j; i++) {
      if (numRegistro == funcionario[i].numRegistro) {
        printf("-=-=-=-=-=-=-=-\nNome: %s\nNumero de registro: %d\nNivel "
               "salarial: "
               "%d\nDepartamento: %d\nProximo: %d\n",
               funcionario[i].nome, funcionario[i].numRegistro,
               funcionario[i].nivelSalarial, funcionario[i].departamento,
               funcionario[i].proximo);
        q++;
      }
    }
    if (q == 0) {
      printf("Numero de registro nao encontrado, digite outro numero: ");
      scanf("%d", &numRegistro);
    }
  } while (q == 0);

  sleep(5);
  system("clear");

  fclose(arq1);
}

// funcao que consulta todos os funcionarios de um departamento
void consultarDepartamento(int *j) {
  FILE *arq1;
  arq1 = fopen("funcionarios.dat", "r");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i, q = 0, departamento;

  printf("Digite o departamento: ");
  scanf("%d", &departamento);
  // verificar se o departamento existe no arquivo
  do {
    for (i = 0; i < *j; i++) {
      if (departamento == funcionario[i].departamento) {
        printf("-=-=-=-=-=-=-=-\nNome: %s\nNumero de registro: %d\nNivel "
               "salarial: "
               "%d\nDepartamento: %d\nProximo: %d\n",
               funcionario[i].nome, funcionario[i].numRegistro,
               funcionario[i].nivelSalarial, funcionario[i].departamento,
               funcionario[i].proximo);
        q++;
      }
    }
    if (q == 0) {
      printf("Departamento nao encontrado, digite outro departamento: ");
      scanf("%d", &departamento);
    }
  } while (q == 0);

  sleep(20);
  system("clear");

  fclose(arq1);
}

// funcao que demite um funcionario
void demitirFuncionario(int *j) {
  FILE *arq1;
  arq1 = fopen("funcionarios.dat", "r");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i, q = 0, numRegistro, a = *j;

  printf("Digite o numero de registro do funcionario: ");
  scanf("%d", &numRegistro);
  // verificar se o numero do registro existe no arquivo
  do {
    for (i = 0; i < *j; i++) {
      if (numRegistro == funcionario[i].numRegistro) {
        strcpy(funcionario[i].nome, " ");
        funcionario[i].numRegistro = 0;
        funcionario[i].nivelSalarial = 0;
        funcionario[i].departamento = 0;
        funcionario[i].proximo = 0;
        q++;
      }
    }
    if (q == 0) {
      printf("Numero de registro nao encontrado, digite outro numero: ");
      scanf("%d", &numRegistro);
    }
  } while (q == 0);

  // mudar os proximos do funcionario apos a demissao

  // remover funcionario do arquivo
  fprintf(arq1, "%s %d %d %d %d\n", funcionario[i].nome,
          funcionario[i].numRegistro, funcionario[i].nivelSalarial,
          funcionario[i].departamento, funcionario[i].proximo);

  printf("Funcionario %d demitido com sucesso!\n", numRegistro);

  a--;
  *j = a;

  sleep(5);
  system("clear");

  fclose(arq1);
}

// funcao que faz mudanca de departamento de um funcionario
void mudarDepartamento(int *j) {
  FILE *arq1, *arq2;
  arq1 = fopen("funcionarios.dat", "r");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }
  arq2 = fopen("departamentos.dat", "w");
  if (arq2 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i, q = 0, numRegistro, dep;

  printf("Digite o numero de registro do funcionario: ");
  scanf("%d", &numRegistro);
  // verificar se o numero do registro existe no arquivo
  do {
    for (i = 0; i < *j; i++) {
      if (numRegistro == funcionario[i].numRegistro) {
        printf("Digite o novo departamento: ");
        scanf("%d", &dep);
        // verificar se o funcionario é o início de seu departamento
        if (departamento[i].inicio == i) {
          departamento[i].inicio = funcionario[i].proximo;
        }
        funcionario[i].departamento = dep;
        q++;
      }
    }
    if (q == 0) {
      printf("Numero de registro nao encontrado, digite outro numero: ");
      scanf("%d", &numRegistro);
    }
  } while (q == 0);

  // mudar os proximos do funcionario apos a mudanca de departamento ?????

  // adicionando no arquivo
  fprintf(arq1, "%d", funcionario[i].departamento);
  fprintf(arq2, "%d", departamento[i].inicio);

  printf("Funcionario %d mudou de departamento com sucesso!\n", numRegistro);
  sleep(5);
  system("clear");

  fclose(arq1);
  fclose(arq2);
}

int main() {
  FILE *arq1, *arq2;
  arq1 = fopen("funcionarios.dat", "w+");
  if (arq1 == NULL) {
    printf("Erro na abertura do arquivo");
    exit(1);
  }
  int menu, j = 13;

  // preenchendo os dados dos funcionarios
  strcpy(funcionario[0].nome, "Joao");
  funcionario[0].numRegistro = 123;
  funcionario[0].nivelSalarial = 7;
  funcionario[0].departamento = 1;
  funcionario[0].proximo = 5;

  strcpy(funcionario[1].nome, "Maria");
  funcionario[1].numRegistro = 8765;
  funcionario[1].nivelSalarial = 12;
  funcionario[1].departamento = 1;
  funcionario[1].proximo = -1;

  strcpy(funcionario[2].nome, "Jose");
  funcionario[2].numRegistro = 9210;
  funcionario[2].nivelSalarial = 4;
  funcionario[2].departamento = 2;
  funcionario[2].proximo = -1;

  strcpy(funcionario[3].nome, "Ana");
  funcionario[3].numRegistro = 2628;
  funcionario[3].nivelSalarial = 4;
  funcionario[3].departamento = 3;
  funcionario[3].proximo = 6;

  strcpy(funcionario[4].nome, "Pedro");
  funcionario[4].numRegistro = 5571;
  funcionario[4].nivelSalarial = 8;
  funcionario[4].departamento = 2;
  funcionario[4].proximo = -1;

  strcpy(funcionario[5].nome, "Paulo");
  funcionario[5].numRegistro = 652;
  funcionario[5].nivelSalarial = 1;
  funcionario[5].departamento = 1;
  funcionario[5].proximo = 9;

  strcpy(funcionario[6].nome, "Julia");
  funcionario[6].numRegistro = 7943;
  funcionario[6].nivelSalarial = 1;
  funcionario[6].departamento = 3;
  funcionario[6].proximo = -1;

  strcpy(funcionario[7].nome, "Marcos");
  funcionario[7].numRegistro = 671;
  funcionario[7].nivelSalarial = 5;
  funcionario[7].departamento = 3;
  funcionario[7].proximo = 12;

  strcpy(funcionario[8].nome, "Carla");
  funcionario[8].numRegistro = 1956;
  funcionario[8].nivelSalarial = 11;
  funcionario[8].departamento = 2;
  funcionario[8].proximo = 11;

  strcpy(funcionario[9].nome, "Ricardo");
  funcionario[9].numRegistro = 398;
  funcionario[9].nivelSalarial = 6;
  funcionario[9].departamento = 1;
  funcionario[9].proximo = 10;

  strcpy(funcionario[10].nome, "Juliana");
  funcionario[10].numRegistro = 3356;
  funcionario[10].nivelSalarial = 3;
  funcionario[10].departamento = 1;
  funcionario[10].proximo = 1;

  strcpy(funcionario[11].nome, "Leticia");
  funcionario[11].numRegistro = 4050;
  funcionario[11].nivelSalarial = 2;
  funcionario[11].departamento = 2;
  funcionario[11].proximo = 4;

  strcpy(funcionario[12].nome, "Rafael");
  funcionario[12].numRegistro = 2468;
  funcionario[12].nivelSalarial = 9;
  funcionario[12].departamento = 3;
  funcionario[12].proximo = 3;

  // escrevendo os dados no arquivo
  int i;
  for (i = 0; i < 13; i++) {
    fprintf(arq1, "%s %d %d %d %d\n", funcionario[i].nome,
            funcionario[i].numRegistro, funcionario[i].nivelSalarial,
            funcionario[i].departamento, funcionario[i].proximo);
  }

  fclose(arq1);

  arq2 = fopen("departamentos.dat", "w+");
  if (arq2 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  // preenchendo dados dos departamentos
  departamento[0].codDepto = 1;
  strcpy(departamento[0].nomeDepto, "Vendas");
  departamento[0].inicio = 0;

  departamento[1].codDepto = 2;
  strcpy(departamento[1].nomeDepto, "Contabilidade");
  departamento[1].inicio = 8;

  departamento[2].codDepto = 3;
  strcpy(departamento[2].nomeDepto, "Estoque");
  departamento[2].inicio = 7;

  departamento[3].codDepto = 4;
  strcpy(departamento[3].nomeDepto, "Entrega");
  departamento[3].inicio = 2;

  // escrevendo os dados no arquivo
  for (i = 0; i < 4; i++) {
    fprintf(arq2, "%d %s %d\n", departamento[i].codDepto,
            departamento[i].nomeDepto, departamento[i].inicio);
  }

  fclose(arq2);

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