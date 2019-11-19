#include <stdio.h>
#include <assert.h>

//takes an integer s and prints that number of stars(*)
void printStar(int s){
    for(int i = 0; i < s; i++){
        printf("*");
    }
}

//takes an integer s and prints that number of dots(.)
void printDot(int s){
    for(int i = 0; i < s; i++){
        printf(".");
    }
}

//takes an integer "size" and prints an arrow head of stars with a total width
//of the given size, with an equal number of dots on each side
//of the stars to center it and create the triangle shape
void arrowHead(int size){
    for(int i = 0; i <= size / 2; i++){
        printDot(size / 2 - i);
        printStar(i * 2 + 1);
        printDot(size / 2 - i);
        printf("\n");
    }
}

//takes an integer "size" and prints an arrow trunk with size / 4 stars, and
//an equal number of dots on the sides of it to center the stars to the arrow
//head
void arrowTrunk(int size){
    for(int i = 0; i < size; i++){
        printDot((size - size / 4) / 2);
        printStar(size / 4);
        printDot((size - size / 4) / 2);
        printf("\n");
    }
}

//takes an integer "size" and prints an arrow of the given size
void arrow(int size){
   // we can only do odd size arrows
   assert(size % 2 == 1);
   arrowHead(size);
   arrowTrunk(size);
}

int main(){
   arrow(9);
   arrow(15);
   arrow(31);
   return 0;
}
