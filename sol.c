#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcion auixiliar para el manejo de errores de argumentos y control de flujo del programa
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

// Inicio desarrollo de la funcion pedida en el ejercicio 1
int traducir(char target, char new){
    int currentCH = getchar();
    while (currentCH != EOF){ // Itera caracter a caracter hasta encontrar el delimitador EOF
        if (currentCH == target){
            fprintf(stdout, "%c", new);
        }else{
            fprintf(stdout, "%c", currentCH);
        }
        currentCH = getchar();// Actualiza currentCH
    }
    fflush(stdout);//Imprime toda la cola de fprintf retenidos a stdout
    return 0;
}
// Fin del desarrollo

// Inicio desarrollo de la funcion pedida en el ejercicio 2
int contarOcurrencias(char* target, int targetLen){
    int ocurrencias = 0;
    char line[1024]; // Se fijo un tamaño maximo por conveniencia de 1024

    while (fgets(line, sizeof(line), stdin) != NULL){// Itera linea a linea hasta llegar al delimitador EOF.
        int lineLen = strlen(line);
        if (targetLen > lineLen) continue; // Si la linea es mas corta que la palabra no puede haber una ocurrencia, la linea se salta.
        
        int inLine = 0; // bool para verificar que haya al menos una ocurrencia de la palabra en la linea, se asume inicialmente que no.
        for (int i = 0; i <= lineLen - targetLen; i++){//Itera sobre la linea, hasta el ultimo indice capaz de producir una ocurrencia.
            int isMatch = 1; // bool para verificar coincidencia de la palabra con el substring en la linea, se asume inicialmente verdadero
            for (int j = 0; j < targetLen; j++){// Itera sobre el substring
                if (target[j] != line[i+j]){ // Si no hay coincidencia, fija isMatch a 0 y termina la iteracion sobre el substring.
                    isMatch = 0;
                    break;
                }
            }
            if (isMatch == 1){ // Verificacion de ocurrencia, si hay una ocurrencia, no sigue buscando en la linea.
                inLine = 1;
                break;
            }
        }
        if (inLine == 1) ocurrencias++; // Cuenta la ocurrencia
    }
    fprintf(stdout, "%d\n", ocurrencias);
    fflush(stdout);
    return 0;
}
// Fin desarrollo

int main(int argc, char* argv[]){
    int run = controlArgumentos(argc, argv);
    if (run == 3){
        return traducir(argv[1][0], argv[2][0]);
    }if (run == 2){
        return contarOcurrencias(argv[1], strlen(argv[1]));
    }
    return 1;
}