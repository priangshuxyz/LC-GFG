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
```

<p>[Expected Approach] Using Divide and Conquer - O(log e) Time and O(log e) Space
<br>The idea is to use Divide and Conquer and recursively bisect e in two equal parts. There are two possible cases:
<br>If e is even: power(b, e) = power(b, e / 2) * power(b, e / 2); 
<br>If e is odd: power(b, e) = b * power(b, e / 2) * power(b, e / 2); </p>

```cpp
    // Base Case: pow(b, 0) = 1
    if (e == 0)
        return 1;
    if (e < 0)
        return 1 / power(b, -e);
    double temp = power(b, e / 2);
    if (e % 2 == 0)
        return temp * temp;
    else
        return b * temp * temp;
```

<p>Using Inbuilt Functions - O(log e) Time and O(1) Space
The idea is to use inbuilt functions provided by various languages to calculate b^e.
Like in C++, pow(b, e) can be used to calculate b^e. Similarly, in Python, the exact same function can be used, or the **operator can be used to find the power.</p>

```cpp
return pow(b, e);
