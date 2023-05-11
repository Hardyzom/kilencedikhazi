#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char special_chars[] = {'.', ',', ';', '\''};
    const int num_special_chars = sizeof(special_chars) / sizeof(special_chars[0]);

    const int max_length = 12;
    const int min_length = 8;

    srand(time(NULL));

    int length = min_length + rand() % (max_length - min_length + 1);
    char password[max_length + 1];

    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < length; ++i) {
        int category = rand() % 4;

        if (category == 0) {
            password[i] = 'a' + rand() % 26;
            has_lower = 1;
        } else if (category == 1) {
            password[i] = 'A' + rand() % 26;
            has_upper = 1;
        } else if (category == 2) {
            password[i] = '0' + rand() % 10;
            has_digit = 1;
        } else {
            password[i] = special_chars[rand() % num_special_chars];
            has_special = 1;
        }
    }

    if (!has_lower) {
        password[rand() % length] = 'a' + rand() % 26;
    }
    if (!has_upper) {
        password[rand() % length] = 'A' + rand() % 26;
    }
    if (!has_digit) {
        password[rand() % length] = '0' + rand() % 10;
    }
    if (!has_special) {
        password[rand() % length] = special_chars[rand() % num_special_chars];
    }

    password[length] = '\0';

    printf("Erős jelszó: %s\n", password);

    return 0;
}
