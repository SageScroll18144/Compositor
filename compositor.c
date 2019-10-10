#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char acordes[] = {'C','D','E','F','G','A','B'};

int main(void){

    int busca_bruta(char c);

    char tonica;
    
    char seq[] = {'1','4','5','x','1','4','6','5','x','1','6','2','5','m','x','1','5','6','m','4','1','5','x','1','5','6','m','3','m','4','4','m','1','x','2','m','7','5','m','7','1','x'};
    scanf("%c", &tonica);
    for(int i = 0; i < 50;i++){
        printf("=");
    }
    printf("\nthese->\n");
    for(int i = 0; i < sizeof(seq)/sizeof(char); i++)
    {
        if(seq[i] == 'x'){
            printf("\n");
        }else if(seq[i] == 'm' || seq[i] == '7'){
            printf("%c", seq[i]);
        }else{
            printf(" ");
            int pos = busca_bruta(toupper(tonica));
            if(pos+((int)seq[i]-(int)'0')>= sizeof(acordes)/sizeof(char)){
                printf("%c", acordes[((int)(seq[i])-(int)'0')+pos-(sizeof(acordes)/sizeof(char))-1]);
            }
            else{
                printf("%c", acordes[((int)(seq[i])-(int)'0')+pos-1]);
            }
        }
    }
    
    return 0;
}
int busca_bruta(char c){
    
    int pos;
    
    for(int i = 0; i < sizeof(acordes)/sizeof(char); i++)
    {
        if (acordes[i] == c) {
            pos = i;
        }
        
    }
    return pos;
}