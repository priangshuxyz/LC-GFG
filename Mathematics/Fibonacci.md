<p>[Expected Approach-1] Memoization top down Approach

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
```

<p>[Expected Approach-2] Bottom-Up Approach

Time Complexity: O(n), Auxiliary Space: O(n)</p>

```cpp
int nthFibonacci(int n){
    // Handle the edge cases
    if (n <= 1)
        return n;
    // Create a vector to store Fibonacci numbers
    vector<int> dp(n + 1);
    // Initialize the first two Fibonacci numbers
    dp[0] = 0;
    dp[1] = 1;
    // Fill the vector iteratively
    for (int i = 2; i <= n; ++i){
        // Calculate the next Fibonacci number
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // Return the nth Fibonacci number
    return dp[n];
}
