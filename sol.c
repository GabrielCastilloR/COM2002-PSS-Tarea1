#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int controlArgumentos(int argc, char* argv[]){
    if (argc == 2){
        return 2;
    }if (argc == 3){
        if (strlen(argv[1]) != 1 || strlen(argv[2]) != 1){
            printf("ERROR: Argumentos invalidos, esta ejecución solo acepta 2 argumentos, ambos deben ser carateres unicos.\n");
            return 1;
        }return 3;
    }else{
        printf("ERROR: Cantidad de argumentos invalida. Para traducir ingrese 2 argumentos, para contar ocurrencuas ingrese 1 argumento");
        return 1;
    }
}

int translate(char target, char new){
    int currentCH = getchar();
    while (currentCH != EOF){
        if (currentCH == target){
            fprintf(stdout, "%c", new);
        }else{
            fprintf(stdout, "%c", currentCH);
        }
        currentCH = getchar();
    }
    fflush(stdout);
    return 0;
}

int contarOcurrencias(char* target, int targetLen){
    int ocurrencias = 0;
    char line[1024];

    while (fgets(line, sizeof(line), stdin) != NULL){
        int lineLen = strlen(line);
        if (targetLen > lineLen) continue;
        
        int inLine = 0;
        for (int i = 0; i <= lineLen - targetLen; i++){
            int isMatch = 1;
            for (int j = 0; j < targetLen; j++){
                if (target[j] != line[i+j]){
                    isMatch = 0;
                    break;
                }
            }
            if (isMatch == 1){
                inLine = 1;
                break;
            }
        }
        if (inLine == 1) ocurrencias++;
    }
    fprintf(stdout, "%d\n", ocurrencias);
    fflush(stdout);
    return 0;
}

int main(int argc, char* argv[]){
    int run = controlArgumentos(argc, argv);
    if (run == 3){
        return translate(argv[1][0], argv[2][0]);
    }if (run == 2){
        return contarOcurrencias(argv[1], strlen(argv[1]));
    }
    return 1;
}