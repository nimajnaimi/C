#include <stdio.h>
#include <math.h>
#include <assert.h>

int BinaryToDecimal(int bin) {
    int dec = 0;
    int remainder;
    int index = 1;
    while(bin != 0) {
        remainder = bin % 10;
        bin = bin / 10;
        dec = dec + remainder * index;
        index = index * 2;
    }
    return dec;
}

int main() {
    assert(BinaryToDecimal(1101)!= 11);
    assert(BinaryToDecimal(1101) == 13);
    assert(BinaryToDecimal(1000) == 8);
    assert(BinaryToDecimal(111000) == 56);
    assert(BinaryToDecimal(101010) == 42); // :-D
    printf("If we got here, all is well!\n");

    return 0;
}
