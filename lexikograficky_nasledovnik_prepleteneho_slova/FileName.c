#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)


void zadat_slovo(char** slovo) {
    char temp[100];
    scanf("%s", temp);
    int size = strlen(temp);
    *slovo = (char*)malloc((size + 1) * sizeof(char)); 
    strcpy(*slovo, temp); 
}

int main() {
    char** slova;
    int pocet_slov = 0;

    printf("Zadajte pocet slov");
    scanf("%d", &pocet_slov);

    slova = (char**)malloc((pocet_slov + 1) * sizeof(char*)); 

    for (int i = 0; i < pocet_slov; i++) {
        zadat_slovo(&slova[i]); 
    }

    slova[pocet_slov] = NULL;
}