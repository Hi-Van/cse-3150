#include <iostream>
#include "../headers/ECNumbers.h"

using namespace ECNumbers;
using namespace std;

int main()
{
    int n;

    cout << "Please input integer value: ";
    cin >> n;
    cout << "\n";

    printf("ECdoubleN(N) = %d \n\n", ECDoubleN(n));
    printf("ECFourTimesN(N) = %d \n\n", ECFourTimesN(n));
    printf("ECSquareN(N) = %d \n\n", ECSquareN(n));

    return 0;
};