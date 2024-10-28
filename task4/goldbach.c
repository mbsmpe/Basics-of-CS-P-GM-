/**
 * goldbach.c -- программа для ...
 *
 * Copyright (c) 2024, Marina Gruzdeva <mbsmpe@yandex.ru>
 *
 * This code is licensed under MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

void calculate_primes(int primes[], int n);

void goldbach(int n) {
    int *primes = (int *)malloc((n + 1) * sizeof(int));
    if (primes == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    calculate_primes(primes, n);
    int count = 0;
    int p1 = 0, p2 = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (primes[i] && primes[n - i]) {
            if (count == 0 || i < p1) {
                p1 = i;
                p2 = n - i;
            }
            count++;
        }
    }
    printf("%d %d %d %d\n", n, count, p1, p2);
    free(primes);
}
