#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "doctest.h"
#include "prefixsum.h"

int nums_0[] = {};
int nums_1[] = {-5};
int nums_2[] = {35};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};

bool negativePrefixSum(int array[], int length) {
    int total = 0;

    // a prefix sum is just another representation of a running total
    for (int idx = 0; idx < length; idx++) {
        total += array[idx];

        // if running total is less than 0, qualifies negative prefix sum
        if (total < 0) {
            return true;
        };

    };

    // 0 will count as positive in this scenario
    return false;
}


TEST_CASE("Test week1/2 functions") {
  SUBCASE("non-negative prefix sums") {
    CHECK(negativePrefixSum(nums_0, sizeof(nums_0) / sizeof(int) ) == false);
    CHECK(negativePrefixSum(nums_2, sizeof(nums_2) / sizeof(int) ) == false);
    CHECK(negativePrefixSum(nums_4, sizeof(nums_4) / sizeof(int) ) == false);
  };
  SUBCASE("non-positive prefix sums") {
    CHECK(negativePrefixSum(nums_1, sizeof(nums_1) / sizeof(int) ) == true);
    CHECK(negativePrefixSum(nums_3, sizeof(nums_3) / sizeof(int) ) == true);
    CHECK(negativePrefixSum(nums_5, sizeof(nums_5) / sizeof(int) ) == true);
  };
}

