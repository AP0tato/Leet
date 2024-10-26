#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int primeCount = 0;
        for(uint i = left; i <= right; i++)
        {
            int onCount = popcount(i);
            primeCount += isPrime(onCount);
        }
        return primeCount;
    }

    bool isPrime(int n)
    {
        // 0 and 1 are not prime numbers
        if (n == 0 || n == 1) {
            return false;
        }

        // loop to check if n is prime
        for(int i = 2; i <= n/2; ++i) {
            if (n % i == 0) {
            return false;
            break;
            }
        }
        return true;
    }
};

int main()
{
    Solution *s;
    int l = 842;
    int r = 888;
    cout << s->countPrimeSetBits(l, r);
}