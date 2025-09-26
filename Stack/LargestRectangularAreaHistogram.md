<p>[Naive Approach] By Finding Max Area of Rectangles all Heights - O(n2) Time and O(1) Space </p>
<p>The idea is to fix each bar as the height of the rectangle and expand towards the left and right while the bars are at least as tall as the current bar. For every valid step, we keep adding the current bar’s height to the area. By doing this for all bars and keeping track of the maximum value. </p>

```cpp
    int res = 0, n = arr.size();
    // Consider every bar one by one
    for(int i = 0; i < n; i++){
        int curr = arr[i];
        // Traverse left while we have a greater height bar
        for(int j = i-1; j>=0 && arr[j] >= arr[i]; j--)
             curr += arr[i];
        // Traverse right while we have a greater height bar      
        for(int j = i+1; j<n && arr[j] >= arr[i]; j++)
            curr += arr[i];
        res = max(res, curr);
    }
    return res;
```

<p>[Expected Approach] Using Stack - O(n) Time and O(n) Space</p>
<p>The goal is to find the largest rectangle by treating each bar as the shortest bar in a potential rectangle. To do this efficiently, we find the boundaries for each bar by pre-computing its Previous Smaller Element (PSE) and Next Smaller Element (NSE), which are the first shorter bars to the left and right, respectively. <br>

The width of the rectangle for the current bar is calculated as:
<b>width = index_of_NSE - index_of_PSE - 1 </b><br>

The area is then height * width. The overall answer is the maximum area found across all bars.</p>

```cpp
// Function to find next smaller for every element
vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> nextS(n, n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {

            // Setting the index of the next smaller element
            // for the top of the stack
            nextS[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nextS;
}
// Function to find previous smaller for every element
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
  
    vector<int> prevS(n, -1);
  
    stack<int> st;
 
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {

            // Setting the index of the previous smaller element
            //  for the top of the stack
            st.pop();
        }
        if (!st.empty()) {
            prevS[i] = st.top();
        }
        st.push(i);
    }
    return prevS;
}
// Function to calculate the maximum rectangular
// area in the Histogram
int getMaxArea(vector<int>& arr) {
    vector<int> prevS = prevSmaller(arr);
    vector<int> nextS = nextSmaller(arr);
    int maxArea = 0;
    // Calculate the area for each Histogram bar
    for (int i = 0; i < arr.size(); ++i) {
        int width = nextS[i] - prevS[i] - 1; 
        int area = arr[i] * width;          
        maxArea = max(maxArea, area);        
    }
    return maxArea;
}
