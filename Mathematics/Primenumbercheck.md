<p>Sieve of Eratosthenes

Time Complexity: O(n \log(\log n)) 
Space Complexity: O(n)

Create a List: Make a list of all numbers from 2 up to n-1.

Assume All are Prime: Start by assuming every number in this list is prime.

Start Sieving:

Begin with the first number, 2. It's prime.

Now, "cross off" all multiples of 2 (4, 6, 8, 10, ...) from your list.

Move to the next un-crossed-off number, which is 3. It must be prime.

Cross off all multiples of 3 (6, 9, 12, 15, ...). (It's okay if some, like 6, are crossed off multiple times).

Move to the next un-crossed-off number, 5 (since 4 was already crossed off). It must be prime.

Cross off all multiples of 5 (10, 15, 20, 25, ...).

Repeat: Continue this process. Any number you land on that isn't already crossed off is a prime.

Stop: You only need to do this "crossing off" step for numbers up to the square root of n.

Count: Finally, count how many numbers in your list were never crossed off.</p>

```cpp
int countPrimes(int n) {
        // We need an array up to n, but indices 0 to n-1 cover this.
        if (n <= 2) {
            return 0;
        }
        // 1. Create our list. 
        // Initialize all as 'true' (assumed prime).
        vector<bool> isPrime(n, true);
        // 2. 0 and 1 are not prime.
        isPrime[0] = false;
        isPrime[1] = false;
        // 3. Start sieving.
        // We only need to check up to sqrt(n).
        // (p * p < n) is a safer way to write (p <= sqrt(n)).
        for (int p = 2; p * p < n; p++) {
            // If isPrime[p] is still true, then p is a prime.
            if (isPrime[p]) {
                // 4. Cross off all multiples of p.
                // We can start from p*p. Why?
                // Because smaller multiples (like 2*p, 3*p)
                // would have already been crossed off by smaller primes (2, 3).
                for (int i = p * p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        // 5. Count the remaining primes.
        int primeCount = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                primeCount++;
            }
        }
        return primeCount;
    }
