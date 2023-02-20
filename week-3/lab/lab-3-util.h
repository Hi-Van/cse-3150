#ifndef LAB_3_UTIL
#define LAB_3_UTIL

void fisherYates(int array[], int length)
{
    // Durstenfield implementation of Fisher-Yates algorithm

    while (length)
    {
        int idx = std::rand() % length;
        std::swap(array[idx], array[length - 1]);

        length--;
    }
}

#endif