<p>[Naive Approach 1] Using Iteration - O(e) Time and O(1) Space
The idea is to simply multiply b exactly e times using a iterative loop.</p>

```cpp
    // Initialize result to 1
    double pow = 1;
    // Multiply x for n times
    for (int i = 0; i < abs(e); i++) 
        pow = pow * b;
  	if (e < 0)
      	return 1/pow;
    return pow;
```

<p>[Naive Approach 2] Using Recursion - O(e) Time and O(e) Space
The idea is to recursively multiply b exactly e times. To do so, define a recursive function that return b, if e > 0 else returns 1.</p>

```cpp
    // Base Case: pow(b, 0) = 1
    if (e == 0)
        return 1;
    if (e < 0)
        return 1 / power(b, -e);
    // For all other cases
    return b * power(b, e - 1);
