#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
  bool ativo;
} Funcionario;
Funcionario funcionario[40];

// struct para os departamentos
typedef struct Departamento {
  int codDepto;
  char nomeDepto[30];
  int inicio;
} Departamento;
Departamento departamento[5];

// funcao que admite novo funcionario no arquivo
void admitirFuncionario(int *j, int *numAtivos) {
  FILE *arq1;
  arq1 = fopen("funcionarios.dat", "r + w");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i;
  if (*numAtivos == 20) {
    printf("numero maximo!\n\n");
  } else {
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
    funcionario[*j].ativo = 1;
    
    
    
    // mudar o proximo do ultimo funcionario do departamento
    for (i = 0; i < *j; i++) {
      if (funcionario[*j].departamento == funcionario[i].departamento &&
          funcionario[i].proximo == -1 && funcionario[i].ativo == 1) {
        funcionario[i].proximo = *j;
      }
    }

    funcionario[*j].proximo = -1;
    FILE *arqtemp;
  arqtemp = fopen("funcionarios2.dat", "w");
  if (arqtemp == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  for (i = 0; i < *j+1; i++) {
    fprintf(arqtemp, "%s %d %d %d %d %d\n", funcionario[i].nome,
            funcionario[i].numRegistro, funcionario[i].nivelSalarial,
            funcionario[i].departamento, funcionario[i].proximo,
            funcionario[i].ativo);
  }

  fclose(arqtemp);
  remove("funcionarios.dat");
  rename("funcionarios2.dat", "funcionarios.dat");
  
  printf("Funcionario admitido com sucesso!\n");

  sleep(2);
  system("clear");

  fclose(arq1);
    }  
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
  arq1 = fopen("funcionarios.dat", "r + w");
  if (arq1 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int i, q = 0, numReg;

  printf("Digite o numero de registro do funcionario a ser demitido: ");
  scanf("%d", &numReg);
  // verificar se o numero do registro existe no arquivo
  do {
    for (i = 0; i < *j; i++) {
      if (numReg == funcionario[i].numRegistro) {
        funcionario[i].ativo = 0;
        q++;
      }
    }
    if (q == 0) {
      printf("Numero de registro nao encontrado, digite outro numero: ");
      scanf("%d", &numReg);
    }
  } while (q == 0);

  // criar um novo arquivo com os dados atualizados do funcionario demitido e o antigo arquivo sera apagado e o novo arquivo sera renomeado para o nome do antigo arquivo
  FILE *arqtemp;
  arqtemp = fopen("funcionarios2.dat", "w");
  if (arqtemp == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  for (i = 0; i < *j; i++) {
    fprintf(arqtemp, "%s %d %d %d %d %d\n", funcionario[i].nome,
            funcionario[i].numRegistro, funcionario[i].nivelSalarial,
            funcionario[i].departamento, funcionario[i].proximo,
            funcionario[i].ativo);
  }

  fclose(arqtemp);
  remove("funcionarios.dat");
  rename("funcionarios2.dat", "funcionarios.dat");
  
  printf("Funcionario demitido com sucesso!\n");



  sleep(2);
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
  arq2 = fopen("departamentos.dat", "a+");
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
  arq1 = fopen("funcionarios.dat", "a+");
  if (arq1 == NULL) {
    printf("Erro na abertura do arquivo");
    exit(1);
  }

  // passando os dados do arquivo para o vetor
  int i = 0;
  while (!feof(arq1)) {
    fscanf(arq1, "%s %d %d %d %d %d", funcionario[i].nome,
           &funcionario[i].numRegistro, &funcionario[i].nivelSalarial,
           &funcionario[i].departamento, &funcionario[i].proximo,
           &funcionario[i].ativo);
    i++;
  }

  fclose(arq1);

  arq2 = fopen("departamentos.dat", "a+");
  if (arq2 == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  // passando os dados do arquivo para o vetor
  int i1 = 0;
  while (!feof(arq2)) {
    fscanf(arq2, "%d %s %d", &departamento[i1].codDepto,
           departamento[i1].nomeDepto, &departamento[i1].inicio);
    i1++;
  }

  fclose(arq2);

  int menu;

  


  do {
    // printando a struct
    printf("Nome|Num|Nsal|Dep|Prox|Ativo\n");
    for (i = 0; i < 40; i++) {
      if (funcionario[i].nome[0] != '\0') {
      printf("%s %d %d %d %d %d\n", funcionario[i].nome,
             funcionario[i].numRegistro, funcionario[i].nivelSalarial,
             funcionario[i].departamento, funcionario[i].proximo,
             funcionario[i].ativo);
        }
    }
    //int max = 20;
    int j = 0;
    // conta a quantidade de casas preenchidas no vetor
    for (i = 0; i < 40; i++) {
      if (funcionario[i].nome[0] != '\0') {
        j++;
      }
    }
    int numAtivos = 0;
    for (i = 0; i < 40; i++) {
      if (funcionario[i].ativo == 1) {
        numAtivos++;
      }
    }
    printf("%d funcionários ativos!\n", numAtivos);

    printf(
        "\n\nEscolha uma opção!\n0. Sair\n1. Admissão de funcionário\n2. "
        "Demissão de funcionário\n3. Mudança de Departamento\n4. Consulta a "
        "todos funcionários de um departamento\n5. Consulta Individual\n--> ");
    scanf("%d", &menu);

    switch (menu) {
    case 0:
      printf("Saindo...");
      break;
    case 1:
      admitirFuncionario(&j, &numAtivos);
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