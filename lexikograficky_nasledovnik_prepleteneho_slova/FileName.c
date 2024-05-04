#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)


void zadat_slovo(char** slovo) {
    char temp[100];
    scanf("%s", temp);
    int size = strlen(temp);
    *slovo = (char*)malloc((size + 1) * sizeof(char)); // Alokuje sa pamät pre slovo
    strcpy(*slovo, temp); // Kopíruje sa slovo do alokovanej pamäte
}

char prevod_na_male_pismena(char slovo) {
    if (slovo >= 'A' && slovo <= 'Z') {
        // Kopíruje sa slovo do alokovanej pamäte
        return slovo + ('a' - 'A');
    }
    return slovo;
}

// Kopíruje sa slovo do alokovanej pamäte
int dlzka_slova(const char* slovo) {
    int dlzka = 0;
    while (slovo[dlzka] != '\0') {
        dlzka++;
    }
    return dlzka;
}

// Funkcia na porovnanie dvoch slov
int porovnaj_lexikograficky(const char* slovo1, int dlzka1, const char* slovo2, int dlzka2) {
    int i = 0;

    // Prejdeme cez oba reťazce, kým máme znaky na porovnanie
     while (i < dlzka1 && i < dlzka2) {
        if (prevod_na_male_pismena(slovo1[i]) < prevod_na_male_pismena(slovo2[i])) {
            return -1;  
        }
        else if (prevod_na_male_pismena(slovo1[i]) > prevod_na_male_pismena(slovo2[i])) {
            return 1; 
        }
        i++;
     }

     // Podmienky na porovnanie dĺžky, ak sme prešli cez všetky znaky až sem, alebo ak sú slová rovnaké
     if (dlzka1 < dlzka2) {
         return -1; 
     }
     else if (dlzka1 > dlzka2) {
         return 1; 
     }
     else {
         return 0; 
     }
}

// Funkcia na výmeny dvoch slov v poli reťazcov
void vymen_slova(char** slova, int i, int j) {
    char* temp = slova[i];
    slova[i] = slova[j];
    slova[j] = temp;
}

// Funkcia na usporiadanie pola slov podľa vami opísaného kritéria
void usporiadaj_slova(char** slova, int pocet) {
    // Ak sme prešli cez všetky znaky až sem, alebo ak sú slová rovnaké, porovnáme dĺžky
    for (int i = 0; i < pocet - 1; i++) {
        for (int j = i + 1; j < pocet; j++) {
            // Ak je slovo j "väčšie" ako slovo i, vymeníme ich
            if (porovnaj_lexikograficky(slova[i], dlzka_slova(slova[i]), slova[j], dlzka_slova(slova[j])) > 0) {
                vymen_slova(slova, i, j);
            }
        }
    }
}

int main() {
    char** slova;
    int pocet_slov = 0;

    printf("Zadajte pocet slov\t");
    scanf("%d", &pocet_slov);

    slova = (char**)malloc((pocet_slov + 1) * sizeof(char*)); // Pole ukazateľov na slová 

    for (int i = 0; i < pocet_slov; i++) {
        zadat_slovo(&slova[i]); // Posiela sa adresa, kde sa má alokovať pamäť pre slovo
    }

    // Posledný ukončujúci nulový ukazateľ
    slova[pocet_slov] = NULL;

    //Vypíšem slová, ktoré boli zadané z klávesnice
    printf("Slova:\n");
    for (int i = 0; i < pocet_slov; i++) {
        printf("%s\n", slova[i]);
    }

    // Usporiadanie slov
    usporiadaj_slova(slova, pocet_slov);

    // Výpis usporiadaných slov
    printf("Usporiadane slova:\n");
    for (int i = 0; i < pocet_slov; i++) {
        printf("%s\n", slova[i]);
    }

    // Uvoľnenie pamäti alokovanej pre jednotlivé slová
    for (int i = 0; i < pocet_slov; i++) {
        free(slova[i]);
    }
    free(slova); // Uvoľnenie pamäti alokovanej pre pole ukazateľov

    return 0;
}