/*
F3. (2.5 puncte) Scrieti un program care primeste ca argument in linia de
comanda un intreg si afisaza descompunerea sa in factori primi.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    if(argc != 2){
        fprintf(stderr, "Utilizare: %s <numar pozitiv>\n", argv[0]);
        return 1;
    }
    
    char *str = NULL;
    long nr = strtol(argv[1], &str, 10);
    
    if(*argv[1] == '\0' || *str != '\0'){
        fprintf(stderr, "%s nu este un numar, contine %s\n", argv[1], str);
        return 2;
    }

    if(nr < 0){
        fprintf(stderr, "%ld nu este un numar pozitiv, nu se poate calcula descompunerea in factori primi\n", nr);
        return 3;
    }

    long i = 1;
    long j;

    printf("descompunere in factori primi pentru %ld:\n", nr);

    if(nr < 2){
        printf("%ld = %ld", nr, nr);
    }
    else{
        printf("%ld = ", nr);

        while(nr != 1){
            ++i;
            j = 0;
            while(nr % i == 0){
                nr = nr / i;
                ++j;
            }
            if(j != 0){
                if(j > 1){
                    printf("(%ld ^ %ld) ", i, j);   
                }
                else{
                    printf("%ld ", i);
                }
                if(nr != 1){
                    printf("* ");
                }
            } 
        }
    }
    printf("\n");

    return 0;
}
