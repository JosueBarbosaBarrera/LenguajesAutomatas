/*
*Crear un programa que nos permita hacer lo sig.
alphabet(char string)
concat(char* string1 char* string2)
pow(*char string)
len(*char string)
inverse(*char string)
ocurrences(char* string, char* symbol)
equal(char* string1 char* string2)
*/

#include <stdio.h>
#include <stdlib.h>

int len(char* string){
    int n = 0;
    while(string[n]!='\0')n++;
    return n;
}

void imprimir(char *string){ // manipulacion de string y vectores
    char c;
    int i = 0;
    while((c=string[i])!='\0'){
        printf("%c",c);
        i++;
    }
}

void inverse(char* string){
    int x,i,y;
    i = 0;
    x = len(string);
    y = x;
    char vect[x];
    
    while(i<y){
        vect[i]=string[x-1];
        printf("%c",vect[i]);
        x--;
        i++;
    }
}

void concat(char* string, char* string2){
    int i,c,x,y,t,j;
    i=0;
    j=0;
    x = len(string);
    y = len(string2);
    t = x+y+1;
    int vect[t];
    
    while(i<=t){
        if(i<x){
            vect[i]=string[i];
        }
        if(i>x){
            vect[i]=string2[j];
            j++;
        }
        i++;
    }

    j=0;
    while(j<=t){
        printf("%c",vect[j]);
        j++;
    }
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

void potencia(char* string){
    int i, potencia = 3;
    printf("potencia de cadena = {");
    for(i=0; i<potencia; i++){
        imprimir(string);
    }
    printf("}\n");
}

void ocurrences(char* string, char* simbolo){
    int i,x,cont=0;
    x = len(string);
    
    for(i=0;i<=x;i++){
        if (string[i]==simbolo[0]){
            cont++;
        }
    }
    printf("el simbolo se repite %i",cont);
}

void equal(char* string, char* string2){
    int i=0, j=0;
    if(len(string) == len(string2)){
        for(i; i>len(string); i++){
            if(string[i] == string2[j]){
                j++;
            }else{
                break;
            }
        }
        printf("Los strings son iguales");
    }else{
        printf("Los strings son difernetes");
    }
}

int main(void){
    alphabet("barbosa");
    
    concat("josue","yoscer");
    printf("\n");
    
    inverse("barbosa");
    printf("\n");
    
    potencia("barbosa");
    printf("\n");
    ocurrences("b#rb#s#","#");
    printf("\n");
    
    equal("josue", "josuee");
    printf("\n");
    system("pause");
    
    // system("cls");
    return EXIT_SUCCESS;
}