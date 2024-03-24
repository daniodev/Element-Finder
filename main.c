#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void optionPrinter();
int main(int argc, char const *argv[]){
    
    FILE *file = fopen(argv[1], "r");

    if(argc == 1){
        printf("Sintassi non corretta.\n");
        printf("Sintassi corretta: ./elementFinder 'nomefile.estenzione' -optione\n");
        optionPrinter();
        exit(EXIT_FAILURE);
    }

    if(file == NULL){
        printf("Impossibile aprire il file.\n");
        exit(EXIT_FAILURE);
    }

    if(strcmp(argv[2], "-fe") == 0){
        if(argc > 3){
            printf("Sono in cerca dell'elemento: %s, se non viene trovata nessuna corrispondenza non verra' scritto niente.", argv[3]);

            char currchar;
            int filelen = 0;
            printf("\n");
            int riga = 1, linea = 1;

            while ((currchar = fgetc(file)) != EOF){
                if (!isspace(currchar)) {
                    filelen++;

                    if(argv[3][0] == currchar){
                        printf("Trovata corrispondenza in Riga: %d e Linea %d\n", riga, linea);
                    }
                }

                if(currchar == '\n'){
                    riga++;
                    linea = 1;
                }else{
                    linea++;
                }
            }
            printf("Elementi scansionati: %d", filelen);
        }else{
            optionPrinter();
            }
    }else{
        optionPrinter();
    }
}

void optionPrinter(){
    printf("Opzioni disponibili:\n");
    printf("-fe 'elemento', serve a cercare nel file una lettera o un numero\n");
}