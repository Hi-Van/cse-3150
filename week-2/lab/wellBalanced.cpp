#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

//#include "../doctest.h"
#include "fisherYates.h"
#include "../assignment/prefixsum.h"
#include <iostream>

using namespace std;


int nums_0[] = {};
int nums_1[] = {-5};
int nums_2[] = {35};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};
int nums_6[] = {1,1,1,-1,-1,-1};

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

bool wellBalanced(int array[], int length) {
    int stack = 0;

    for (int idx = 0; idx < length; idx++) {
        int val = array[idx];

        if (val == -1) {

            if (!stack) {
                return false;
            }

            stack--;
        }

        else {
            stack++;
        }
    }

    return !stack;
}

void fisherYates(int array[], int length) {
    //Durstenfield implementation of Fisher-Yates algorithm

    while (length) {
        int idx = rand() % length;
        swap(array[idx], array[length - 1]);

        length--;
    } 
}

void printArr(int array[], int length) {
    cout << "array: [";

    for (int idx = 0 ; idx < length - 1; idx++) {
        cout << array[idx] << ", ";
    }

    cout << array[length - 1] << ']';
}

double convergence(int array[], int length, int repeat = 10000) {
    int valid = 0, invalid = 0;

    for (int _ = 0; _ < repeat; _++) {
        fisherYates(array, length); //randomize array

        if (negativePrefixSum(array, length) or positivePrefixSum(array, length)) { //if array at least contains a negative or positive prefix          

            if (wellBalanced(array, length)) { // if array is well balanced
                valid++;
            }

            else {
                invalid++;
            }// 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 - idk what this is but imma keep it here
        }
    }

    cout << valid << invalid << endl;
    return (double)valid / (double)invalid; // return ratio convergence
}

int main() {
    int x;
    cout << "Input repetition count: ";
    cin >> x;
    cout << convergence(nums_6, 6, x) << endl;
}


// TEST_CASE("Test week1/2 functions") {
//   SUBCASE("non-negative prefix sums") {
//     CHECK(negativePrefixSum(nums_0, sizeof(nums_0) / sizeof(int) ) == false);
//     CHECK(negativePrefixSum(nums_2, sizeof(nums_2) / sizeof(int) ) == false);
//     CHECK(negativePrefixSum(nums_4, sizeof(nums_4) / sizeof(int) ) == false);
//   };
//   SUBCASE("non-positive prefix sums") {
//     CHECK(negativePrefixSum(nums_1, sizeof(nums_1) / sizeof(int) ) == true);
//     CHECK(negativePrefixSum(nums_3, sizeof(nums_3) / sizeof(int) ) == true);
//     CHECK(negativePrefixSum(nums_5, sizeof(nums_5) / sizeof(int) ) == true);
//   };
// }

