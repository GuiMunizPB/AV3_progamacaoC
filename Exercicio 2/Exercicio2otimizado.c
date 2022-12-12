#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Grupo : Guilherme Muniz, Luana de Mero, Camila Vasconcelos e Ravi de Almeida.
typedef struct {
  int linha;
  int coluna;
  int max;
  int **matriz;
} Imagem;
Imagem imagem;

// funcao que clareia a imagem
void clarearImagem(char *argv[]) {
  FILE *in;
  FILE *out1;
  out1 = fopen("out1.ascii.pgm", "wt");
  if (in == NULL || out1 == NULL) {
    printf("Erro ao abrir o arquivo de entrada");
  }

  char line[512];
  fscanf(in, "%[^\n]\n", line);
  fprintf(out1, "%s\n", line);
  fscanf(in, "%[^\n]\n", line);

  fprintf(out1, "%d %d\n", imagem.linha, imagem.coluna);
  fprintf(out1, "%d\n", imagem.max);

  fscanf(in, "%[^\n]\n", line);
  fscanf(in, "%[^\n]\n", line);

  int i, j;
  for (i = 0; i < imagem.linha; i++) {
    for (j = 0; j < imagem.coluna; j++) {
      int pixel;
      fscanf(in, "%d", &pixel);
      if (pixel < 255) {
        pixel = pixel + 50;
      }
      fprintf(out1, "%d ", pixel);
    }
  }

  fclose(in);
  fclose(out1);
}

// funcao que reduz o tamanho da imagem em blocos de 2x2 pixels e faz a media dos pixels para gerar um novo pixel na imagem de saida (zoom) ??
void zoomImagem(char *argv[]) {
  FILE *in;
  FILE *out2;
  out2 = fopen("out2.ascii.pgm", "wt");
  if (in == NULL || out2 == NULL) {
    printf("Erro ao abrir o arquivo de entrada");
  }

  char line[512];
  fscanf(in, "%[^\n]\n", line);
  fprintf(out2, "%s\n", line);
  fscanf(in, "%[^\n]\n", line);

  fprintf(out2, "%d %d \n", imagem.linha / 2, imagem.coluna / 2);
  fprintf(out2, "%d \n", imagem.max);

  fscanf(in, "%[^\n]\n", line);
  fscanf(in, "%[^\n]\n", line);

  int i, j;
  int matriz[imagem.linha][imagem.coluna];
  for (i = 0; i < imagem.linha; i++) {
    for (j = 0; j < imagem.coluna; j++) {
      int pixel;
      fscanf(in, "%d", &pixel);
      matriz[i][j] = pixel;
    }
  }

  for (i = 0; i < imagem.linha; i = i + 2) {
    for (j = 0; j < imagem.coluna; j = j + 2) {
      int pixel = (matriz[i][j] + matriz[i][j + 1] + matriz[i + 1][j] +
                   matriz[i + 1][j + 1]) /
                  4;
      fprintf(out2, "%d ", pixel);
    }
  }

  fclose(in);
  fclose(out2);
}

// funcao que binariza a imagem transforma em preto ou branco a partir de um limiar obtido pela media dos pixels da imagem
void binarizarImagem(char *argv[]) {
  FILE *in;
  FILE *out3;
  out3 = fopen("out3.ascii.pgm", "wt");
  if (in == NULL || out3 == NULL) {
    printf("Erro ao abrir o arquivo de entrada");
  }

  char line[512];
  fscanf(in, "%[^\n]\n", line);
  fprintf(out3, "%s\n", line);
  fscanf(in, "%[^\n]\n", line);

  fprintf(out3, "%d %d \n", imagem.linha, imagem.coluna);
  fprintf(out3, "%d \n", imagem.max);

  fscanf(in, "%[^\n]\n", line);
  fscanf(in, "%[^\n]\n", line);

  int i, j;
  int media = 0;

  for (i = 0; i < imagem.linha; i++) {
    for (j = 0; j < imagem.coluna; j++) {
      int pixel;
      fscanf(in, "%d", &pixel);
      media = media + pixel;
    }
  }

  media = media / (imagem.linha * imagem.coluna);

  // usando a media para binarizar a imagem
  fseek(in, 0, SEEK_SET);
  fscanf(in, "%[^\n]\n", line);
  fscanf(in, "%[^\n]\n", line);
  fscanf(in, "%[^\n]\n", line);
  fscanf(in, "%[^\n]\n", line);

  for (i = 0; i < imagem.linha; i++) {
    for (j = 0; j < imagem.coluna; j++) {
      int pixel;
      fscanf(in, "%d", &pixel);
      if (pixel < media) {
        pixel = 0;
      } else {
        pixel = 255;
      }
      fprintf(out3, "%d ", pixel);
    }
  }

  fclose(in);
  fclose(out3);
}

// funcao que faz uma rotacao simples trocando as linhas pelas colunas e vice-versa (rotacao de 90 graus)
void rotacionarImagem(char *argv[]) {
  FILE *in;
  FILE *out4;
  out4 = fopen("out4.ascii.pgm", "wt");
  if (in == NULL || out4 == NULL) {
    printf("Erro ao abrir o arquivo de entrada");
  }

  char line[512];
  fscanf(in, "%[^\n]\n", line);
  fprintf(out4, "%s\n", line);
  fscanf(in, "%[^\n]\n", line);

  fprintf(out4, "%d %d \n", imagem.coluna, imagem.linha);
  fprintf(out4, "%d \n", imagem.max);

  int i, j;
  int matriz[imagem.linha][imagem.coluna];

  for (i = 0; i < imagem.linha; i++) {
    for (j = 0; j < imagem.coluna; j++) {
      int pixel;
      fscanf(in, "%d", &pixel);
      matriz[i][j] = pixel;
    }
  }

  for (i = 0; i < imagem.coluna; i++) {
    for (j = 0; j < imagem.linha; j++) {
      fprintf(out4, "%d ", matriz[j][i]);
    }
  }

  fclose(in);
  fclose(out4);
}

// leitor e editor de imagens em PGM
int main(int argc, char *argv[]) {
  FILE *in;

  // lendo a imagem de entrada
  in = fopen(argv[1], "rt");
  if (in == NULL) {
    printf("Erro ao abrir o arquivo de entrada");
    return 1;
  }

  // preenchendo a struct

  char line[512];
  fscanf(in, "%[^\n]\n", line);
  fscanf(in, "%[^\n]\n", line);

  int linha, coluna, max;
  fscanf(in, "%d %d", &linha, &coluna);
  imagem.linha = linha;
  imagem.coluna = coluna;

  fscanf(in, "%d", &max);
  imagem.max = max;

  clarearImagem(char *argv[]);
  zoomImagem(char *argv[]);
  binarizarImagem(char *argv[]);
  rotacionarImagem(char *argv[]);

  printf("Imagens foram geradas!");

  return 0;
}
