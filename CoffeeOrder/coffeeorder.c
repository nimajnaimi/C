#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int getCoffeeType() {
    printf("What type (1: Americano, 2: Latte, 3: Mocha): ");
    int coffeeType;
    scanf("%d", &coffeeType);
    return coffeeType;
}

int getCoffeeSize() {
    printf("What size (1: Tall, 2: Grande): ");
    int coffeeSize;
    scanf("%d", &coffeeSize);
    return coffeeSize;
}

double getPrice(int coffeeType, int coffeeSize) {
    if (coffeeType == 1) {
        if (coffeeSize == 1) {
            return 2.65;
        } else {
            return 2.95;
        }
    } else if (coffeeType == 2) {
        if (coffeeSize == 1){
            return 3.35;
        } else {
            return 3.95;
        }
    } else {
        if (coffeeSize == 1) {
            return 3.85;
        } else {
            return 4.45;
        }
    }
}

int main() {
    printf("Welcome to CoffeeOrder 3000\n");
    printf("How many espresso drinks would you like today (0-3): ");
    int coffees;
    scanf("%d", &coffees);
    assert(coffees < 4);
    if (coffees == 0) {
        printf("OK, so you do not want any espressos today!\n");
    } else {
        double total = 0;
        for (int i = 1; i <= coffees; i++) {
            printf("Getting order for espresso drink #%d\n", i);
            int coffeeType = getCoffeeType();
            int coffeeSize = getCoffeeSize();
            total += getPrice(coffeeType, coffeeSize);
        }
        printf("Your total is %.2f\n", total);
    }
    printf("Thank you for using CoffeeOrder 3000");
    return 0;
}
