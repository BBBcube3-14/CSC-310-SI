#include <stdio.h>
int main(){
    int length = 0;
    char sequence[50];
    int pair = 1;
    scanf("%100s", sequence);
    while(sequence[length] != '\0'){
        length++;
    }
    for(int i = 0; i < 20; i = i + 2){
        if(sequence[i] == 'A' && sequence[i + 1] != 'T'){
            pair = 0;
        }else if(sequence[i] == 'T' && sequence[i + 1] != 'A'){
            pair = 0;
        }else if(sequence[i] == 'G' && sequence[i + 1] != 'C'){
            pair = 0;
        }else if(sequence[i] == 'C' && sequence[i + 1] != 'G'){
            pair = 0;
        }
    }
    if(length == 20 && pair == 1){
        if(sequence[0] == 'A' && sequence[19] =='C'){
            printf("Coronavirus\n");
        }else if(sequence[0] == 'T' && sequence[19] == 'A'){
            printf("Influenza\n");
        }else{
            printf("Unknown\n");
        }
    }else{
        printf("Invalid sequence\n");
    }
    return 0;
}