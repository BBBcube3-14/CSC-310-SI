#include <stdio.h>

#include <stdlib.h>
#include <time.h>

int main(){
    int number = 1;
    float decimal = 9.99;
    char letter = 'A';
    char sentence[] = "Closest thing to a string data type in C";

    printf("Hello World\n");

    for(int i = 0; i < 10; i++){
        printf("Times Run: %d\n", i + 1);
    }

    printf("%f\n", decimal);
    while(decimal > 1){
        decimal /= 2;
        printf("%2.2f\n", decimal);
    }

    //Single line comment
    /*
        Multi
        Line
        Comment
    */

   /*
    srand(time(NULL));

    int randNumber = rand() % 100 + 1;

    printf("Random Number: %d", randNumber);
    */
    return 0;
}