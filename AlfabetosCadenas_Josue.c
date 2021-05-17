/*
*Crear un programa que nos permita hacer lo siguiente:
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

void imprimir(char *string){ //manipulacion de string y vectores
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

// forma oprimizada de concatenacion de cadenas
char* concat(char* string, char* string2){
    int longitudString1 = len(string);
    int longitudString2 = len(string2);
    int k = 0;
    char* result = (char*)malloc(sizeof(char)*(longitudString1+longitudString2+1));

    for(int i=0; i<longitudString1; i++){
        result[k] = string[i];
        k++;
    }
    
    for(int i=0; i<longitudString2; i++){
        result[k] = string2[i];
        k++;
    }

    result[k] = '\0';
    return result; // En la llamada del print de esta funcion arroja un warnig, pero no es relevante, aun asi funciona 
}

/*
void concat(char* string, char* string2){ // forma normal con una funcion void, no es la mas optimizada
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
}*/

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

char* potencia(char* string, int n){
    int size = len(string) * n;
    
    char* result = (char*)malloc((size+1)*sizeof(char));
    for(int i=1; i<=n; i++){
        result = concat(result, string);
    }
    result[size] = '\0';
    return result;
}

/*
void potencia(char* string){ // forma normal y no optima de potencia de cadenas
    int i, potencia = 3;
    printf("potencia de cadena = {");
    for(i=0; i<potencia; i++){
        imprimir(string);
    }
    printf("}\n");
}*/

void ocurrences(char* string, char* simbolo){
    int i,x,cont=0;
    x = len(string);
    
    for(i=0;i<=x;i++){
        if (string[i]==simbolo[0]){
            cont++;
        }
    }
    printf("el simbolo %s se repite %i",simbolo, cont);
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
        printf("%s %s , son strings iguales",string, string2);
    }else{
        printf("%s %s , no son iguales",string, string2);
    }
}

int main(void){
    printf("El alfabeto de una cadena es el conjunto de símbolos que se usan para formar dicha cadena. \n'barbosa': ");
    alphabet("barbosa");
    
    printf("Orden inverso de una cadena.\n");
    inverse("barbosa");
    printf("\n");
    
    printf("La concatenación de cadenas se obtiene al adjuntar la cadena 1 con la cadena 2 al final.\n");
    printf(concat("josue","yoscer"));
    printf("\n");
    
    printf("La potencia de una cadena se obtiene concatenando n copias a la cadena original.\n");
    printf(potencia("josue", 9));
    // potencia("barbosa");
    printf("\n");
    
    printf("El numero de de veces que un simbolo/caracter a buscar aparece en la cadena es el numero de ocurrencias del mismo.\n");
    ocurrences("b#rb#s#","#");
    printf("\n");
    
    printf("Decimos que las cadenas 1 y la cadena 2 son iguales si los caracteres son inguaes en cada index/posicion dentro de la cadena y de longitud/tamano de caracteres es igual.\n");
    equal("josue", "josuebb");
    printf("\n");
    system("pause");
    
    // system("cls");
    return EXIT_SUCCESS;
}