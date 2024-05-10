/*
ALUNO: Breno Martins Silva
DRE: 122031418
*/

#include <stdio.h>
#include <string.h>
#define MAX 15

//funcoes
int proxtoken(void);
void clearToken(char* completeToken);

//variaveis
int c;
char token[MAX];

int main(void){
    c = getchar();
    while (c != -1){
        c = proxtoken();
    }
    return 0;
}

int proxtoken(void) {
    //simbolos
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == ';' || c == '%' || c == '(' || c == ')' || c == '{' || c == '}') {
        printf("%c\n", c);
        c = getchar();
        return c;
    }

    //letras
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        int i;
        for(i = 0; (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); i++){
            token[i] = c;
            c = getchar();
        }
        token[i] = '\0';

        //palavras reservadas
        if (strcmp(token, "if") == 0 || strcmp(token, "while") == 0 || strcmp(token, "else") == 0) {
            printf("%s\n", token);
            clearToken(token);
            return c;
        }
        
        //outras palavras
        printf("NOME %s\n", token);
        clearToken(token);
        return c;
    }

    // numeros
    else if (c >= '0' && c <= '9') {
        int i;
        for (i = 0; c >= '0' && c <= '9'; i++){
            token[i] = c;
            c = getchar();
        }
        token[i] = '\0';
        printf("NUM %s\n", token);
        clearToken(token);
        return c;
    }

    //espacos
    else {
        c = getchar();
        return c;
    }
}

    
void clearToken(char* completeToken){
    for(int i = 0; i < MAX; i++){
        if(token[i] == ' '){
            break;
        }
        token[i] = ' ';
    }
}