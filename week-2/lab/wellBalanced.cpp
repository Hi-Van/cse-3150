#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "doctest.h"
#include "fisherYates.h"
#include "prefixsum.h"
#include <iostream>

using namespace std;


int nums_0[] = {};
int nums_1[] = {-5};
int nums_2[] = {35};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};

bool negativePrefixSum(int array[], int length) {
    int total = 0;

    for (int idx = 0; idx < length; idx++) {
        total += array[idx];

        if (total < 0) {
            return true;
        };

    };

    return false;
}

bool positivePrefixSum(int array[], int length) {
    int total = 0;

    for (int idx = 0; idx < length; idx++) {
        total += array[idx];

        if (total > 0) {
            return true;
        };

    };

    return false;
}

void fisherYates(int array[], int length) {
    //Durstenfield implementation of Fisher-Yates algorithm

    while (length) {
        int idx = rand() % length;
        swap(array[idx], array[length]);

        length--;
    } 
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

