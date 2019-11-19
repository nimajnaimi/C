#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double squareRoot(double number)
{
    double currentX = 10.0;
    for (int i = 0; i < 10; i++)
    {
        currentX = currentX - ((currentX * currentX - number) / (2 * currentX));
    }
    return currentX;
}

void squareRootTester(int testTimes)
{
    printf("Testing squareRoot %d times\n", testTimes);
    int randNum;
    double mySquareRoot;
    double builtInSquareRoot;
    for (int i = 0; i < testTimes; i++)
    {
        randNum = rand() % 1001;
        mySquareRoot = squareRoot(randNum);
        builtInSquareRoot = sqrt(randNum);
        printf("For %d, my squareRoot gives %.12f, builtin sqrt gives\n%.12f, difference is %.12f\n",\
               randNum, mySquareRoot, builtInSquareRoot, mySquareRoot - builtInSquareRoot);
    }
}

double sumOfGeometricSeries(int sequenceLength)
{
    double sum = 0;
    for (int i = 1; i <= sequenceLength; i++)
    {
        sum += pow(-1, i - 1) * 1 / pow(2, i);
    }
    return sum;
}

void sumOfGeometricSeriesTester()
{
    printf("Testing sumOfGeometricSeries\n");
    double sum;
    double difference;
    const double expectedResult = 1.0/3.0;
    for (int i = 1; i <= 10; i++)
    {
        sum = sumOfGeometricSeries(i);
        difference = sum - expectedResult;
        printf("For sequence length of %d, sumOfGeometricSeries gives %.12f,\n"
               "expectedResult is %.12f, difference is %.12f\n", i, sum, expectedResult, difference);
    }
}

int calculateFactorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    int factorial = 1;
    for (int i = 2; i <= num; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

double calculateEulerNumber()
{
    double euler = 0.0;
    for (int i = 0; i < 34; i++)
    {
        euler = euler + (1.0 / calculateFactorial(i));
    }
    return euler;
}

int main()
{
    squareRootTester(10);
    sumOfGeometricSeriesTester();
    printf("An approximation of Euler's Number is: %.30f", calculateEulerNumber());
    return 0;
}
