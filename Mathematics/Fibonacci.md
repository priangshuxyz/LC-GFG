<p>[Expected Approach-1] Memoization Approach

Time Complexity: O(n), each fibonacci number is calculated only one times from 1 to n
  
Auxiliary Space: O(n)

We can store the results of previously computed Fib number in a memo table to avoid redundant calculations.</p>

```cpp
private: 
    int fibHelper(int n, vector<int>& memo) {
        if (n <= 1) {
            return n;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = fibHelper(n-1, memo) + fibHelper(n-2, memo);
        return memo[n];
    }

public:
    int fib(int n) {
        vector<int> memo(n+1, -1);
        return fibHelper(n, memo);
    }
