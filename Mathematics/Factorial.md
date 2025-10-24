<p>[Approach - 1] - Iterative Solution O(n) Time and O(1) Space

The idea is simple, we initialize result as 1. Then, run a loop from 1 to n and multiply every number with result.</p>

```cpp
int factorial(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            // calculating the factorial
            ans = ans * i;
        }
        return ans;
}
