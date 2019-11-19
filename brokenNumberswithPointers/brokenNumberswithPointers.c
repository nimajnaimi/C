#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Write 3 functions
 * sum2, diff2 and product2
 * to make the following program work.
 *
 * You are not allowed to modify compareNumbers
 *
 */

void compareNumbers () {
    int firstNum = 5;
    int secondNum = 2;
    int * ff;
    ff = &firstNum;
    int dif;
    int sum = sum2(ff, secondNum);
    diff2(ff, &secondNum, &dif);
    int prod = product2(*ff, &secondNum);
    assert(sum == 7);
    assert(dif == 3);
    assert(prod == 10);
}

// returns the sum of an integer pointer and an integer
int sum2(int *ff2, int secondNum) {
    return *ff2 + secondNum;
}

// calculates the difference between two integer pointers and stores the
// solution in a third integer pointer
void diff2(int *ff3, int *secondNum, int *dif) {
    *dif = *ff3 - *secondNum;
}

// calculates and returns the product of an integer and an integer pointer
int product2(int firstNum, int *secondNum) {
   return firstNum * *secondNum;
}

int main() {
    compareNumbers();
    printf("If we got here, all is well!\n");
    return 0;
}
