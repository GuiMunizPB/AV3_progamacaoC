#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Grupo : Guilherme Muniz, Luana de Mero, Camila Vasconcelos e Ravi de Almeida.

// funcao que clareia uma imagem pgm


// leitor e editor de imagens em PGM
int main(int argc, char *argv[]) {
    FILE *in;
    FILE *out1 , *out2, *out3 , *out4;

    //lendo a imagem de entrada
    in = fopen("lena.ascii.pgm", "rt");
    if (in == NULL) {
        printf("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    //criando as imagens de saida
    out1 = fopen("out1.ascii.pgm", "wt");
    out2 = fopen("out2.ascii.pgm", "wt");
    out3 = fopen("out3.ascii.pgm", "wt");
    out4 = fopen("out4.ascii.pgm", "wt");
    if (out1 == NULL || out2 == NULL || out3 == NULL || out4 == NULL) {
        printf("Erro ao abrir o arquivo de saida");
        return 1;
    }

    char line[512];
    fscanf(in, "%[^\n]\n", line);
    fprintf(out1, "%s\n", line);
    fprintf(out2, "%s\n", line);
    fprintf(out3, "%s\n", line);
    fprintf(out4, "%s\n", line);
    fscanf(in, "%[^\n]\n", line);

    int linha, coluna, max;
    fscanf(in, "%d %d", &linha, &coluna);
    fprintf(out1, "%d %d\n", linha, coluna);
    fprintf(out2, "%d %d\n", linha, coluna);
    fprintf(out3, "%d %d\n", linha, coluna);
    fprintf(out4, "%d %d\n", linha, coluna);

    fscanf(in, "%d", &max);
    fprintf(out1, "%d\n", max);
    fprintf(out2, "%d\n", max);
    fprintf(out3, "%d\n", max);
    fprintf(out4, "%d\n", max);

    int i, j;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            int pixel;
            fscanf(in, "%d", &pixel);
            fprintf(out1, "%d ", pixel);
            fprintf(out2, "%d ", pixel);
            fprintf(out3, "%d ", pixel);
            fprintf(out4, "%d ", pixel);
        }
    }

    typedef struct {
        int linha;
        int coluna;
        int max;
        int **matriz;
    } Imagem;

    fclose(in);
    fclose(out1);
    fclose(out2);
    fclose(out3);
    fclose(out4);

    int menu;
    do {
    printf(
        "Escolha uma opção!\n0. Sair\n1. Clarear Imagem\n2. Efeito de Zoom\n3. Binazirizar Imagem\n4. Rotação Simples\n--> ");
    scanf("%d", &menu);
    switch (menu) {
    case 0:
      printf("Saindo...");
      break;
    case 1:
      
      break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
  } while (menu != 0);

  return 0;

}
