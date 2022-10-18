/*
F10. (2 puncte) Scrieti un program care concateneaza mai multe fisiere sursa
 intr-unul destinatie. Se va lansa sub forma:
   concat   f1 + f2 + ... + fn   f
 unde f1, ..., fn sunt fisierele sursa iar f este fisierul destinatie.
 Daca n=1, va copia pe f1 in f.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
  if(argc < 3){
    fprintf(stderr, "Utilizare: %s <fisier1> + <fisier2> + ... + <fisiern> <fisier>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if(argc % 2 == 0){
    fprintf(stderr, "Utilizare: %s <fisier1> + <fisier2> + ... + <fisiern> <fisier>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  for(int i = 2; i < argc - 2; i += 2){
    if(strcmp(argv[i], "+") != 0){
      fprintf(stderr, "Utilizare: %s <fisier1> + <fisier2> + ... + <fisiern> <fisier>\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }
  for(int i = 1; i < argc - 1; i += 2){
    if(strcmp(argv[i], argv[argc - 1]) == 0){
      fprintf(stderr, "Se accepta doar fisiere distincte de fisierul destinatie!\n");
      exit(EXIT_FAILURE);
    }
  }

  FILE *fp1;
  fp1 = fopen(argv[argc - 1], "w");
  if(fp1 == NULL){
    perror(argv[argc - 1]);
    exit(EXIT_FAILURE);
  }

  for(int i = 1; i < argc - 1; i += 2){
    FILE *fp2;
    fp2 = fopen(argv[i], "r");

    if(fp2 == NULL){
      perror(argv[i]);
      exit(EXIT_FAILURE);
    }
    while(!feof(fp2)){
      char ch;
      if(fread(&ch, sizeof(char), 1, fp2) != 0)
        fwrite(&ch, sizeof(char), 1, fp1);
    }
    fclose(fp2);
  }

  fclose(fp1);

  return 0;
}
