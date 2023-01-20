// Basic functions for numbers:
// (i) ECSquareN: take an integer and return its square
// (ii) ECDoubleN: take an integer and return two times of it

// Your code here...

namespace ECNumbers
{
    inline int ECSquareN(int n)
    {
        return n * n;
    };

    inline int ECDoubleN(int n)
    {
        return n + n;
    };

    inline int ECFourTimesN(int n)
    {
        return n * 4;
    };

    inline int ECRemoveSpace(int nums[], int len, int val)
    {
        int idx = 0;
        int n = len - 1;

        while (idx < n)
        {

            if (nums[idx] == val)
            {
                std::swap(nums[idx], nums[n]); // move-constructable, move-assignable in c++ 11 (source:https://cplusplus.com/reference/algorithm/swap/)
                n--;
            }

            else
            {
                idx++;
            };
        }

        return idx;
    }
};