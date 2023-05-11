#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kivalaszt(const int n, const int tomb[]){
    int index = rand() % n;
    return tomb[index];
}

int main(){

    int szamok[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int meret = sizeof(szamok) / sizeof(szamok[0]);

    srand(time(NULL));

    int randomszam = kivalaszt(meret, szamok);

    printf("Random szám: %d\n", randomszam);

    return 0;
}
