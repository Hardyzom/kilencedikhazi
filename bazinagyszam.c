#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; ++i) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; ++i) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);

    free(left);
    free(right);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Hasznalat: %s <fajlnev>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Hiba: Nem sikerult megnyitni a fajlt.\n");
        return 1;
    }

    int* numbers = (int*)malloc(3000000 * sizeof(int));
    int count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        numbers[count] = atoi(line);
        ++count;
    }

    fclose(file);

    mergeSort(numbers, count);

    for (int i = 0; i < count; ++i) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);

    return 0;
}
