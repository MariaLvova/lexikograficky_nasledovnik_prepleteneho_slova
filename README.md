## Lexikografické usporiadanie slov

Tento program usporiada zadané slová lexikograficky podľa abecedy. Program používa metódu porovnávania znakov, pričom berie do úvahy aj veľké a malé písmená. Ak je potrebné, mení veľké písmená na malé, aby porovnanie bolo korektné.

### Použitie

1. Spustite program.
2. Zadajte počet slov, ktoré chcete usporiadať.
3. Postupne zadajte jednotlivé slová.
4. Program ich usporiada a vypíše na obrazovku.

### Funkcie

- `prevod_na_male_pismena`: Funkcia prevádza veľké písmená na malé, ak sa vyskytnú.
- `porovnaj_lexikograficky`: Porovnáva dve slová na základe lexikografického poradia.
- `vymen_slova`: Vymieňa pozície dvoch slov v poli.
- `usporiadaj_slova`: Usporiadava slová v poli podľa lexikografického poradia.
- `dlzka_slova`: Vráti dĺžku zadaného slova.
- `zadat_slovo`: Načíta vstupné slovo a alokuje pamäť pre jeho uloženie.
- `main`: Hlavná funkcia programu.

### Vzorový vstup

```
5
jablko
auto
Jablko
autoMobil
Auto
```

### Vzorový výstup

```
Usporiadane slova:
auto
Auto
autoMobil
jablko
Jablko
```

### Poznámka

Program zanedbáva diakritiku a ďalšie špeciálne znaky pri porovnávaní slov.
