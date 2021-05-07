/*
*Crear un programa que nos permita hacer lo sig.
*alphabet(char* string)
concat(char* string1 char* string2)
pow(*char string)
len(*char string)
inverse(*char string)
ocurrences(char* string, char* symbol)
equal(char* string1 char* string2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char *inverse(char* string){
    int longitud = len(string);
    char temporal;
    for(int izquierda=0, derecha=longitud-1; izquierda<(longitud/2); izquierda++, derecha--){
        temporal = string[izquierda];
        string[izquierda] = string[derecha];
        string[derecha] = temporal;
    }
    return string;
}

void concat(char* string, char* string2){
    int i, j, k;
    k=0;
    j=len(string);
    for(i=0; i<=len(string2); i++){
        string[j] = string2[i];
        j++;
    }
}


int len(char* string){
    int n = 0;
    while(string[n]!='\0')n++;
    return n;
}

void alphabet(char* string){
    int* dict = (int*)malloc(255);
    printf("{ ");
    char c;
    int i = 0;
    while((c=string[i])!='\0'){
        if(dict[c] != 1){
            dict[c] = 1;
            if(string[i+1]=='\0'){
                printf("%c",c);
            }else{
                printf("%c, ",c);
            }
        }
        i++;
    }
    printf("}\n");
}

int main(void){
    alphabet("barbosa");
    printf("len %d\n", len("barbosa"));
    concat("josue", "yoscer");
    printf("\n");
    inverse("barbosa");
    system("pause");
    // system("cls");
    return EXIT_SUCCESS;
}