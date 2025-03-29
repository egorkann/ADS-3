// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxValue = num;
    uint64_t t = num;
    while (t != 1) {
        if (t % 2 == 0) {
            t = t / 2;
        } else {
            t = 3 * t + 1;
        }
        if (t > maxValue) {
            maxValue = t;
        }
    }
    return maxValue;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int maxLength = 0;
    uint64_t numberWithMaxLength = lbound;

    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int currentLength = collatzLen(i);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            numberWithMaxLength = i;
        }
    }

    *maxlen = maxLength;
    return numberWithMaxLength;
}
