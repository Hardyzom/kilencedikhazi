#include <stdio.h>
#include <stdlib.h>

int rendezes(const void* a, const void* b){
    return *(const int*)a - *(const int*)b;
}

int main(int argc, char* argv[]){
    if (argc < 2){
        printf("Hiba! Add meg a fájl nevét!\n");
        return 1;
    }

    const char* fajl = argv[1];
    FILE* f = fopen(fajl, "r");
    if (!f){
        printf("Hiba: a fajl nem nyithato meg.\n");
        return 1;
    }

    int szamok[1000];
    int n = 0;
    while (n < 1000 && fscanf(f, "%d", &szamok[n]) == 1){
        n++;
    }

    fclose(f);

    qsort(szamok, n, sizeof(int), rendezes);

    for (int i = 0; i < n; i++){
        printf("%d\n", szamok[i]);
    }

    return 0;
}
