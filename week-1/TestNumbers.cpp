#include <iostream>
#include "ECNumbers.h"
#include <assert.h>

using namespace ECNumbers;
using namespace std;

void unitTest(int n, int desired, int(f)(int), int *counter)
{
    printf("(%d) TEST | input: %d | assert( %d == %d ) \n", *counter, n, desired, f(n));
    assert(f(n) == desired);
    *counter += 1;
}

int main()
{
    int passed = 0;
    int exampleInputs[] = {2, 3, 4, 5};

    int doubleOutputs[] = {4, 6, 8, 10};
    int fourTimeOutputs[] = {8, 12, 16, 20};
    int squareOutputs[] = {4, 9, 16, 25};

    for (int idx = 0; idx < sizeof(exampleInputs) / sizeof(int); idx++)
    {

        unitTest(exampleInputs[idx], doubleOutputs[idx], &ECDoubleN, &passed);
        unitTest(exampleInputs[idx], fourTimeOutputs[idx], &ECFourTimesN, &passed);
        unitTest(exampleInputs[idx], squareOutputs[idx], &ECSquareN, &passed);
    }

    printf("\n (%d/12) test cases passed \n", passed);
    return 0;
};