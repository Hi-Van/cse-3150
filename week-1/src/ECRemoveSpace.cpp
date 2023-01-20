#include <iostream>
#include "../headers/ECNumbers.h"
#include <assert.h>

using namespace ECNumbers;
using namespace std;

void unitTest(int val, int nums[], int len, int *counter)
{
    printf("(%d) TEST | input: val = %d nums = [", *counter, val);

    for (int idx = 0; idx < len; idx++)
    {

        if (idx != len - 1)
        {
            printf("%d,", nums[idx]);
        }

        else
        {
            printf("%d", nums[idx]);
        };
    }

    int k = ECRemoveSpace(nums, len, val);

    printf("] | result: k = %d nums = [", k);

    for (int idx = 0; idx < len; idx++)
    {

        if (idx <= k) {
            assert(nums[idx] != val);
        };

        if (idx != len - 1) {
            printf("%d, ", nums[idx]);
        }

        else{
            printf("%d] \n", nums[idx]);
        };
    }

    *counter += 1;
};

int main()
{
    int passed = 0;
    int nums[] = {3, 2, 2, 3};
    int val = 3;

    unitTest(val, nums, 4, &passed);

    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;

    unitTest(val2, nums2, 8, &passed);

    printf("\n (%d/2) test cases passed \n", passed);
    return 0;
};