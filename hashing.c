#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int hash_hundredths(float num) {
    return (int)floor(num * 100) % 10;
}

int hash_name(const char *name) {
    return (name && name[0] && isalpha(name[0])) ? toupper(name[0]) - 'A' : -1;
}

int hash_rgb_bitwise(int r, int g, int b) {
    return ((r >> 6) << 4) | (g >> 6) << 2 | (b >> 6);
}

int main() {
    float f1 = 12.345;
    printf("1. Hundredths of %.3f \t-> Hash: %d \t(Expected: 4)\n", f1, hash_hundredths(f1));
    
    const char *n1 = "Angeles";
    printf("2.  Name '%s' \t\t-> Hash: %d \t(Expected: 0)\n", n1, hash_name(n1));
    
    int r1 = 200, g1 = 100, b1 = 50;
    printf("3.  RGB(%d, %d, %d) \t-> Hash: %d \t(Expected: 52)\n", r1, g1, b1, hash_rgb_bitwise(r1, g1, b1));

    return 0;
}
