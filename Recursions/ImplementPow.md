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
