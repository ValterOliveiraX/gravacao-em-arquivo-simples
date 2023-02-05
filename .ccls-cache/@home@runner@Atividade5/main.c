#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int numPessoas, idade = 0, sexF = 0, sexM = 0, maiorIdade = 0;
  char sexo, nome;

  FILE *dat;
  FILE *res;

  dat = fopen("dados.dat", "r");
  fscanf(dat, "%d", &numPessoas);

  for (int i = 0; i <= numPessoas + 1; i++) {

    fscanf(dat, "%c", &nome);
    fscanf(dat, "%s", &sexo);
    fscanf(dat, "%d", &idade);

    if (sexo == 'F')
      sexF++;

    if (sexo == 'M')
      sexM++;

    if (maiorIdade < idade)
      maiorIdade = idade;
  }

  res = fopen("resultados.dat", "w+a");
  fprintf(res, "O numero de pessoas e %d", numPessoas);
  fprintf(res, "\nO numero de homens e %d", sexM);
  fprintf(res, "\nO numero de mulheres e %d", sexF);
  fprintf(res, "\nA idade da pessoa mais velha e %d", maiorIdade);


  return 0;
}