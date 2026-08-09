# 3.Merge K Sorted Arrays

### Algorithm: Sequential Merge(Method 1)

**Step 1:** Start.

**Step 2:** Read the number of sorted arrays `k` and the size `n` of each array.

**Step 3:** Input all `k` sorted arrays.

**Step 4:** Copy the first array into `result`.

**Step 5:** Set `currentSize = n`.

**Step 6:** For each remaining array from 2 to `k`:
  * Allocate a temporary array of size `currentSize + n`.
  * Merge `result` and the current sorted array using two pointers.
  * Store the merged elements in the temporary array.
  * Free the memory occupied by the old `result`.
  * Make the temporary array the new `result`.
  * Update `currentSize = currentSize + n`.
    
**Step 7:** Print the final merged sorted array.

**Step 8:** Free the memory allocated for `result`.

**Step 9:** Stop.

### Worst-Case Time Complexity Analysis

Consider $k$ sorted arrays, where each array contains $n$ elements. The program merges the arrays one by one. After every merge, the size of the `result` array increases by $n$.

**Step 1: Input**
The program takes $k$ arrays, each containing $n$ elements. Therefore, reading all elements takes:
$$T_{input} = O(kn)$$

**Step 2: Copy the First Array**
The first array containing $n$ elements is copied into `result`.
$$T_{copy} = O(n)$$

**Step 3: The Merging Process**
*   **1st Merge:** The 1st array ($n$ elements) and 2nd array ($n$ elements) are merged. The `merge()` function processes $2n$ elements.
    $$T_1 = O(2n)$$
*   **2nd Merge:** The `result` now contains $2n$ elements, and the 3rd array contains $n$ elements. The merge processes $3n$ elements.
    $$T_2 = O(3n)$$
*   **Subsequent Merges:** The same process continues iteratively:
    $$T_3 = O(4n)$$
    $$T_4 = O(5n)$$
    $$\dots$$
*   **Final Merge:** The last merge processes $kn$ elements.
    $$T_{k-1} = O(kn)$$

**Step 4: Total Merging Time**
The total time required for all merges is the sum of the times of each individual merge:
$$T_{merge} = O(2n + 3n + 4n + \dots + kn)$$

Taking $n$ as a common factor (and conceptualizing the sequence starting from $1$ for simplicity):
$$T_{merge} = O\left(n(1 + 2 + 3 + \dots + k)\right)$$

Using the arithmetic progression sum formula for the first $k$ natural numbers:
$$1 + 2 + 3 + \dots + k = \frac{k(k+1)}{2}$$

Substitute this back into the time equation:
$$T_{merge} = O\left(n \frac{k(k+1)}{2}\right)$$

Ignoring the constant factor ($\frac{1}{2}$) and lower-order terms, we get:
$$T_{merge} = O(nk^2)$$

**Step 5: Overall Time Complexity**
Including the time for input, copying, and merging:
$$T(n,k) = O(kn) + O(n) + O(nk^2)$$

The dominant term here is $O(nk^2)$. Hence, the overall worst-case time complexity of the given program is:
$$\mathbf{O(nk^2)}$$

---

### Final Conclusion

The program uses **sequential merging**, where each new array is merged with an increasingly larger `result` array. Because the amount of data processed increases linearly from $n$ to $2n, 3n, \dots, kn$, the total worst-case running time evaluates to:

$$\mathbf{O(nk^2)}$$

**Where:**
*   **$n$** = number of elements in each sorted array
*   **$k$** = number of sorted arrays

### Sample Output
Enter number of arrays: 3

Enter size of each array: 4

Enter sorted arrays:

Array 1:

1 4 7 10

Array 2:

2 5 8 11

Array 3:

3 6 9 12

Merged Array:

1 2 3 4 5 6 7 8 9 10 11 12

### Algorithm: Divide and Conquer(Method 2)

**Step 1:** Start.

**Step 2:** Read the number of sorted arrays `k` and the number of elements `n` in each array.

**Step 3:** Dynamically allocate memory for all `k` arrays and store their sizes.

**Step 4:** Input the elements of all `k` sorted arrays.

**Step 5:** Set `current = k`.

**Step 6:** While `current > 1`, perform the following:
  * Set `newCount = 0`.
  * Take the arrays in pairs: (Array 1, Array 2), (Array 3, Array 4), and so on.
  * For each pair:
    * Calculate the combined size of the two arrays.
    * Allocate memory for the merged array.
    * Merge the two sorted arrays using the `merge()` function.
    * Free the memory of the two original arrays.
    * Store the merged array in the next position.
    * Store its new size.
  * If one array is left without a pair, move it directly to the next round without merging.
  * Set `current = newCount`.
    
**Step 7:** Repeat Step 6 until only one array remains.

**Step 8:** Print the remaining array, which contains all elements in sorted order.

**Step 9:** Free all dynamically allocated memory.

**Step 10:** Stop.

### Worst-Case Time Complexity Analysis

Consider $k$ sorted arrays, where each array contains $n$ elements. The program uses a divide-and-conquer approach, merging pairs of arrays iteratively. In each iteration (or pass), the number of arrays is halved, and the size of each array is doubled.

**Step 1: Input and Memory Allocation**
The program takes $k$ arrays, each containing $n$ elements. Therefore, allocating memory and reading all elements takes:
$$T_{input} = O(kn)$$

**Step 2: The Merging Process (By Passes)**
Instead of merging arrays one by one, this algorithm merges them in parallel pairs during each "pass."
*   **Pass 1:** There are $k$ arrays of size $n$. The algorithm merges them into $k/2$ pairs. Each merge processes $2n$ elements. Total elements processed across all pairs in this pass: $\frac{k}{2} \times 2n = kn$.
    $$T_{pass\_1} = O(kn)$$
*   **Pass 2:** There are now $k/2$ arrays of size $2n$. The algorithm merges them into $k/4$ pairs. Each merge processes $4n$ elements. Total elements processed across all pairs in this pass: $\frac{k}{4} \times 4n = kn$.
    $$T_{pass\_2} = O(kn)$$
*   **Subsequent Passes:** In every single pass, the size of the arrays doubles, but the number of arrays halves. Therefore, the total number of elements processed in *any* given pass is always exactly $kn$.
    $$T_{pass\_i} = O(kn)$$

**Step 3: Total Merging Time**
Because the number of arrays is divided by 2 in each pass (going from $k$ arrays down to just $1$ array), the total number of passes required is exactly $\log_2 k$.

The total time for all merges is the sum of the work done in each pass:
$$T_{merge} = T_{pass\_1} + T_{pass\_2} + \dots + T_{pass\_{\log k}}$$

Substitute the work per pass into the equation:
$$T_{merge} = O(kn) + O(kn) + \dots (\text{repeated } \log_2 k \text{ times})$$

This simplifies directly to:
$$T_{merge} = O(kn \log k)$$

**Step 4: Overall Time Complexity**
Including the time for input, memory allocation, and the merging process:
$$T(n,k) = O(kn) + O(kn \log k)$$

As $k$ grows, the merging time dominates the input time. The dominant term is $O(kn \log k)$. Hence, the overall worst-case time complexity of the given program is:
$$\mathbf{O(kn \log k)}$$

---

### Final Conclusion

The program uses a **divide-and-conquer** approach, merging adjacent pairs of arrays in parallel passes. Because every element is processed exactly once per pass, and the number of arrays is halved during each pass (resulting in $\log_2 k$ passes), the total worst-case running time evaluates to:

$$\mathbf{O(kn \log k)}$$

**Where:**
*   **$n$** = number of elements in each sorted array
*   **$k$** = number of sorted arrays

### Sample Output

Enter number of arrays: 3

Enter number of elements in each array: 4

Enter 4 sorted elements of Array 1:

1 4 7 10

Enter 4 sorted elements of Array 2:

2 5 8 11

Enter 4 sorted elements of Array 3:

3 6 9 12

Merged Array:

1 2 3 4 5 6 7 8 9 10 11 12

### Conclusion: Sequential Merge vs. Divide and Conquer

When tasked with merging `k` sorted arrays of `n` elements each, the approach you choose drastically impacts the performance of your program. 

#### Method 1: The Sequential Approach
This method merges the arrays one by one (merging Array 1 and 2, then merging the result with Array 3, then with Array 4, and so on). While it is very intuitive and easy to code, it suffers from a major performance problem. Because the main result array grows by `n` with every single step, the elements from the earlier arrays are re-read and re-copied over and over again. This redundant copying leads to a worst-case time complexity of **O(n * k^2)**. This makes Method 1 highly inefficient when dealing with a large number of arrays.

#### Method 2: The Divide and Conquer Approach
This method solves the problem of Method 1 by merging the arrays in pairs (Array 1 with 2, Array 3 with 4, etc.). In the first pass, you create `k/2` arrays of size `2n`. In the next pass, you create `k/4` arrays of size `4n`. This halving continues until only one final sorted array remains. Because the number of arrays is cut in half at each step, the algorithm only needs to make `log(k)` passes. In every single pass, exactly `k * n` total elements are processed. This gives a drastically improved worst-case time complexity of **O(n * k * log k)**.

#### Final Verdict
For a very small number of arrays, Method 1 is perfectly acceptable due to its simplicity. However, for any substantial number of arrays, **Method 2 is strictly superior**. Method 2 scales significantly better and is the standard, most efficient approach for solving this problem.
