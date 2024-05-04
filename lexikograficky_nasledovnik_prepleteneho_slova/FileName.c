#include <stdio.h>


int main() {
    char** slova;
    int pocet_slov = 0;

    printf("Zadajte pocet slov");
    scanf("%d", &pocet_slov);

    slova = (char**)malloc((pocet_slov + 1) * sizeof(char*)); 

}