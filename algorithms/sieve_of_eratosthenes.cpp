#include <bits/stdc++.h>
using namespace std;

#define TARGET_PRIME 10'001
#define MAX_SIZE 200'000

/**
 * This also happens to be the solution to problem 7 from Project Euler.
 * Algorithm:
 * 1. initialize a boolean array, set all elements to true.
 * 2. iterate through, starting with 2, if the number is prime, iterate through all multiplicatives
 * of the number and mark them as non-primes.
 * 3. write the true values from the boolean array to a vector of primes.
 */
void sieveOfErastosthenes(vector<int>& primes) {
    bool is_prime[MAX_SIZE];
    memset(is_prime, true, sizeof(is_prime));

    for (int p = 2; p * p < MAX_SIZE; ++p) {
        if (is_prime[p] == true) {
            for (int i = p * p; i < MAX_SIZE; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int p = 2; p < MAX_SIZE; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

int main() {
    vector<int> primes;
    sieveOfErastosthenes(primes);
    if (primes.size() >= TARGET_PRIME) {
        cout << primes[TARGET_PRIME - 1];
    } else {
        cout << "Increase MAX_SIZE";
    }
    return 0;
}