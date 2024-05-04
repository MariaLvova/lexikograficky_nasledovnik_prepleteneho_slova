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

char prevod_na_male_pismena(char slovo) {
    if (slovo >= 'A' && slovo <= 'Z') {
        return slovo + ('a' - 'A');
    }
    return slovo;
}

int dlzka_slova(const char* slovo) {
    int dlzka = 0;
    while (slovo[dlzka] != '\0') {
        dlzka++;
    }
    return dlzka;

int porovnaj_lexikograficky(const char* slovo1, int dlzka1, const char* slovo2, int dlzka2) {
    int i = 0;

     while (i < dlzka1 && i < dlzka2) {
        if (prevod_na_male_pismena(slovo1[i]) < prevod_na_male_pismena(slovo2[i])) {
            return -1;  
        }
        else if (prevod_na_male_pismena(slovo1[i]) > prevod_na_male_pismena(slovo2[i])) {
            return 1; 
        }
        i++;
    }
}

void usporiadaj_slova(char** slova, int pocet) {
    for (int i = 0; i < pocet - 1; i++) {
        for (int j = i + 1; j < pocet; j++) {
            
        }
    }
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