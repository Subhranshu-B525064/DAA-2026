# DAA-2026
# Design and Analysis of Algorithms (DAA) Lab Programs

## Student Information

- **Name:** Subhranshu Sekhar Dash
- **Roll Number:** B525064
- **Semester:** 3rd Semester
- **Section:** CE

---

# 1.Dictionary Operations:

## Problem Statement

Consider a Dictionary (D) Abstract Data Type that permits access to data items by their content (key).

The primary operations are:

- Search(D, k)
- Insert(D, x)
- Delete(D, x)
- Minimum(D)
- Maximum(D)
- Predecessor(D, x)
- Successor(D, x)

Implement the Dictionary ADT using the following six data structures:

1. Unsorted Array
2. Sorted Array
3. Singly Linked Unsorted List
4. Singly Linked Sorted List
5. Doubly Linked Unsorted List
6. Doubly Linked Sorted List

Determine the worst-case asymptotic running time of all seven operations and validate the order of growth using Gnuplot.

---

## Data Structures Used

### 1. Unsorted Array
Elements are stored without maintaining any particular order.

### 2. Sorted Array
Elements are maintained in increasing order.

### 3. Singly Linked Unsorted List
Elements are stored in nodes connected using a `next` pointer, without maintaining order.

### 4. Singly Linked Sorted List
Elements are stored in increasing order using a singly linked list.

### 5. Doubly Linked Unsorted List
Each node contains `prev` and `next` pointers, but elements are not sorted.

### 6. Doubly Linked Sorted List
Elements are maintained in sorted order using a doubly linked list.

## Worst Case Time Complexities

### 1. Unsorted Array

For an unsorted array implementation of the dictionary, let `n` be the number of elements in the dictionary. The asymptotic worst-case running times for all seven primary operations are as follows:

| Operation | Worst-Case Time | Reason |
| :--- | :---: | :--- |
| **Search(D, k)** | **$O(n)$** | In the worst case, we may need to scan the entire array linearly to find key `k`. |
| **Insert(D, x)** | **$O(1)$** | Since the array is unsorted, `x` can be inserted directly at the next available position (e.g., the end of the array). |
| **Delete(D, x)** | **$O(n)$** | Although `x` is given as a pointer or index, deleting it may require shifting the remaining elements left to maintain the contiguous array structure. |
| **Maximum(D)** | **$O(n)$** | Since the array is unsorted, every element must be checked to find the largest key. |
| **Minimum(D)** | **$O(n)$** | Since the array is unsorted, every element must be checked to find the smallest key. |
| **Predecessor(D, x)** | **$O(n)$** | We may need to examine all elements to find the largest key that is strictly smaller than `x`. |
| **Successor(D, x)** | **$O(n)$** | We may need to examine all elements to find the smallest key that is strictly larger than `x`. |

### 2. Sorted Array

For a sorted array implementation of the dictionary, let `n` be the number of elements in the dictionary. Since the array is maintained in sorted order, searching can be optimized, but modifying the array requires shifting elements. The asymptotic worst-case running times are as follows:

| Operation | Worst-Case Time | Reason |
| :--- | :---: | :--- |
| **Search(D, k)** | **$O(\log n)$** | Binary search can be used to locate the key efficiently in logarithmic time. |
| **Insert(D, x)** | **$O(n)$** | After finding the correct position for `x`, subsequent elements must be shifted to the right to make space for the new item. |
| **Delete(D, x)** | **$O(n)$** | Even though `x` is given as a pointer or index, removing the element requires shifting all subsequent elements left to close the gap and maintain the contiguous structure. |
| **Maximum(D)** | **$O(1)$** | The largest element is always predictably located at the last occupied position of the array. |
| **Minimum(D)** | **$O(1)$** | The smallest element is always located at the very first position (index 0) of the array. |
| **Predecessor(D, x)** | **$O(1)$** | Since the position of `x` is already known (given as a pointer/index) and the array is sorted, its predecessor is simply the element immediately before it `(index - 1)`. |
| **Successor(D, x)** | **$O(1)$** | Similarly, since the position of `x` is known, its successor is the element immediately after it `(index + 1)`. |

### 3. Singly Linked Unsorted List

For a singly linked unsorted list implementation of the dictionary, let `n` be the number of elements. Because the list is unsorted and nodes only have forward pointers, we generally have to traverse the list to find or manipulate elements based on their keys. The asymptotic worst-case running times are as follows:

| Operation | Worst-Case Time | Reason |
| :--- | :---: | :--- |
| **Search(D, k)** | **$O(n)$** | In the worst case, the key is at the last node or does not exist, so the entire list must be traversed. |
| **Insert(D, x)** | **$O(1)$** | If insertion is performed at the head of the list, the new node can be added directly in constant time without searching. |
| **Delete(D, x)** | **$O(n)$** | Although a pointer to `x` is given, deleting it requires updating the `next` pointer of the node immediately before it. Since a singly linked list does not provide a pointer to the previous node, we must traverse the list from the head to find the predecessor. |
| **Maximum(D)** | **$O(n)$** | Since the list is unsorted, every node must be examined to determine the largest key. |
| **Minimum(D)** | **$O(n)$** | Since the list is unsorted, every node must be examined to determine the smallest key. |
| **Predecessor(D, x)** | **$O(n)$** | We need to traverse the entire list to determine which element has the largest key that is strictly smaller than `x`. |
| **Successor(D, x)** | **$O(n)$** | We need to traverse the entire list to determine which element has the smallest key that is strictly larger than `x`. |

### 4. Singly Linked Sorted List

For a singly linked sorted list implementation of the dictionary, let `n` be the number of elements. Since the list is maintained in sorted order, some operations become easier than in an unsorted list, but we still lack backward pointers. The asymptotic worst-case running times are as follows:

| Operation | Worst-Case Time | Reason |
| :--- | :---: | :--- |
| **Search(D, k)** | **$O(n)$** | We must traverse the list until the key is found or we pass its potential position. In the worst case, the key may be at the very end or absent. |
| **Insert(D, x)** | **$O(n)$** | We must traverse the list from the beginning to find the correct sorted position before inserting the new node. |
| **Delete(D, x)** | **$O(n)$** | Since only a pointer to `x` is given and the list is singly linked, we must traverse the list from the head to find the node immediately preceding `x` to update its `next` pointer. |
| **Maximum(D)** | **$O(n)$** | The largest key is stored in the last node. Because it is a singly linked list (assuming no tail pointer), reaching the last node requires traversing the entire list. |
| **Minimum(D)** | **$O(1)$** | The smallest key is located at the first node (head) of the list, so it can be accessed immediately. |
| **Predecessor(D, x)** | **$O(n)$** | We must traverse the list from the head to reach `x` in order to identify the node immediately before it. |
| **Successor(D, x)** | **$O(1)$** | In a sorted linked list, the successor of `x` is simply the next node in the structure (`x->next`), which can be accessed directly in constant time. |

### 5. Doubly Linked Unsorted List

For a doubly linked unsorted list implementation of the dictionary, let `n` be the number of elements. Because the list is unsorted, searching for specific values or logical neighbors (minimum, maximum, predecessor, and successor) requires traversing the entire list. However, because it is doubly linked, deletion becomes highly efficient when a pointer to the node is already given. The asymptotic worst-case running times are as follows:

| Operation | Worst-Case Time | Reason |
| :--- | :---: | :--- |
| **Search(D, k)** | **$O(n)$** | The list is unsorted, so we may have to examine every node in the worst case to find the key `k`. |
| **Insert(D, x)** | **$O(1)$** | A new node can be inserted directly at the beginning (head) of the list in constant time. |
| **Delete(D, x)** | **$O(1)$** | Since a pointer to `x` is given and each node has a `prev` pointer, we can instantly access its neighboring nodes to update their pointers and remove `x` directly without traversing the list. |
| **Maximum(D)** | **$O(n)$** | The list is unsorted, so every single node must be examined to find the largest key. |
| **Minimum(D)** | **$O(n)$** | The list is unsorted, so every single node must be examined to find the smallest key. |
| **Predecessor(D, x)** | **$O(n)$** | Because the list is unsorted, the structural previous node (`x->prev`) is *not* necessarily the logical predecessor. We must search the entire list to find the element with the largest key strictly smaller than `x`. |
| **Successor(D, x)** | **$O(n)$** | Similarly, because the list is unsorted, we must search the entire list to find the element with the smallest key strictly greater than `x`. |

### 6. Doubly Linked Sorted List

For a doubly linked sorted list implementation of the dictionary, let `n` be the number of elements. Since the list is maintained in sorted order, operations like minimum, maximum, predecessor, and successor can take full advantage of the ordering. Furthermore, the doubly linked structure allows for highly efficient deletions when a pointer to the node is already given. The asymptotic worst-case running times are as follows:

| Operation | Worst-Case Time | Reason |
| :--- | :---: | :--- |
| **Search(D, k)** | **$O(n)$** | Although the list is sorted, linked lists do not support random access. Therefore, we cannot perform a binary search and must traverse the list sequentially. |
| **Insert(D, x)** | **$O(n)$** | We must traverse the list to find the correct sorted position before inserting the new node `x`. |
| **Delete(D, x)** | **$O(1)$** | Since a pointer to `x` is given and each node has `prev` and `next` pointers, we can update the neighboring nodes and remove `x` directly without any traversal. |
| **Maximum(D)** | **$O(1)$** | The largest key is stored at the last node. Assuming a standard doubly linked list implementation that maintains a tail pointer, it can be accessed directly in constant time. |
| **Minimum(D)** | **$O(1)$** | The smallest key is at the first node (head), which can be accessed immediately. |
| **Predecessor(D, x)** | **$O(1)$** | Since the list is sorted and doubly linked, the logical predecessor is exactly the structural previous node, accessible instantly via `x->prev`. |
| **Successor(D, x)** | **$O(1)$** | Since the list is sorted, the logical successor is exactly the structural next node, accessible instantly via `x->next`. |


# 2.Standard Merge Sort vs Modified 3-Way Merge Sort

### Algorithm: Comparing Merge Sort and Modified 3-Way Merge Sort

**Step 1:** Start.

**Step 2:** Initialize two comparison counters:
  * `c1` for standard Merge Sort.
  * `c2` for Modified 3-Way Merge Sort.
    
**Step 3:** Read the maximum value of `n`.

**Step 4:** For every `n` from 100 to `max` in increments of 100, perform the following:
  * Dynamically allocate two arrays of size `n`.
  * Fill both arrays with random values.
  * Reset `c1` and `c2` to 0.
    
**Step 5:** Apply Standard Merge Sort to the first array:
  * Divide the array into two halves.
  * Recursively sort both halves.
  * Merge the two sorted halves.
  * Increment `c1` for every comparison made during the merging phase.
  * Continue until the entire array is sorted.
    
**Step 6:** Apply Modified 3-Way Merge Sort to the second array:
  * Divide the array into three approximately equal parts.
  * Recursively sort all three parts.
  * Merge the three sorted parts using the `merge3()` function.
  * Increment `c2` for every comparison performed during the three-way merge phase.
  * Continue until the entire array is sorted.
    
**Step 7:** Display the value of `n`, the number of comparisons made by Standard Merge Sort (`c1`), and the number of comparisons made by Modified 3-Way Merge Sort (`c2`).

**Step 8:** Store these values (`n`, `c1`, `c2`) into a file named `data.txt` for plotting.

**Step 9:** Repeat Steps 4–8 for all values of `n` up to the maximum limit.

**Step 10:** Create a GNUPlot script that defines:
  * `n` (array size) on the x-axis.
  * Number of comparisons on the y-axis.
  * A plot line/curve for Standard Merge Sort.
  * A plot line/curve for Modified 3-Way Merge Sort.
    
**Step 11:** Open GNUPlot and display the comparison graph to visualize the performance difference.

**Step 12:** Free all dynamically allocated memory to prevent memory leaks.

**Step 13:** Stop.

### Worst-Case Time Complexity Analysis: Modified 3-Way Merge Sort

Consider an array of $n$ elements. In this modified version of Merge Sort, the array is divided into three equal parts (thirds) instead of two. Each third is sorted recursively, and then all three are combined using a 3-way merge subroutine. 

**Step 1: The Divide Step**
Finding the two splitting points to divide the array into three parts of size $n/3$ takes constant time.
$$T_{divide} = O(1)$$

**Step 2: The Conquer (Recursive) Step**
The algorithm recursively calls itself on 3 sub-arrays, each of size $n/3$. 
$$T_{conquer} = 3 \cdot T\left(\frac{n}{3}\right)$$

**Step 3: The Combine (Merge) Step**
To merge three sorted arrays of size $n/3$ into a single sorted array of size $n$, the algorithm compares the elements at the front of the three sub-arrays. Finding the minimum of 3 elements requires at most 2 comparisons. Since there are $n$ total elements to place in the final array, the merge step takes linear time.
$$T_{merge} = O(n)$$

**Step 4: The Recurrence Relation**
Combining the steps above, the overall running time $T(n)$ for an array of size $n$ can be expressed as a recurrence relation:
$$T(n) = 3T\left(\frac{n}{3}\right) + O(n)$$

**Step 5: Solving the Recurrence Relation**

We can solve this using the Recursion Tree method:
*   **Levels of the Tree:** The array size is divided by 3 at each level. The recursion stops when the array size becomes 1. Therefore, the depth (number of levels) of the recursion tree is $\log_3 n$.
*   **Work per Level:** 
    *   At Level 0: $1$ problem of size $n \rightarrow$ work is $cn$
    *   At Level 1: $3$ problems of size $n/3 \rightarrow$ work is $3 \times c(n/3) = cn$
    *   At Level 2: $9$ problems of size $n/9 \rightarrow$ work is $9 \times c(n/9) = cn$
*   At every level of the tree, the total work done is $O(n)$. 

Since there are $\log_3 n$ levels and each level takes $O(n)$ time, the total time is:
$$T(n) = O(n) \cdot \log_3 n = O(n \log_3 n)$$

**Step 6: Asymptotic Notation Conversion**
In Big-O notation, the base of the logarithm is a constant factor because $\log_3 n = \frac{\log_2 n}{\log_2 3}$. Since constants are ignored in asymptotic analysis, $O(n \log_3 n)$ simplifies to $O(n \log n)$.

---

### Final Conclusion

The **Modified 3-Way Merge Sort** divides the array into three parts recursively, resulting in a recursion tree with a shallower depth ($\log_3 n$) but slightly more work in the merge phase. Because the total work done at each level of division remains strictly linear ($O(n)$) and there are $\log_3 n$ levels, the total worst-case running time evaluates to:

$$\mathbf{O(n \log n)}$$

**Where:**
*   **$n$** = total number of elements in the array to be sorted.

### Sample Output (For n = 1000)

Enter maximum value of n: 1000

| n | Merge Sort | Modified Merge Sort |
| :---: | :---: | :---: |
| **100** | 541 | 846 |
| **200** | 1184 | 1923 |
| **300** | 1910 | 3141 |
| **400** | 2685 | 4365 |
| **500** | 3462 | 5589 |
| **600** | 4262 | 6869 |
| **700** | 5092 | 8189 |
| **800** | 5942 | 9539 |
| **900** | 6812 | 10939 |
| **1000** | 7702 | 12389 |

Opening GNUPlot...


<img width="1356" height="690" alt="image" src="https://github.com/user-attachments/assets/10421e75-d51f-4a80-849a-b25363967396" />

### Conclusion: Standard vs. 3-Way Merge Sort

Although both algorithms have a theoretical time complexity of **$O(n \log n)$**, empirical data proves that **Standard 2-Way Merge Sort is significantly more efficient in practice**.

*   **The Theory:** 3-Way Merge Sort creates a shallower recursion tree (a depth of $\log_3 n$ compared to $\log_2 n$), which might initially seem faster.
*   **The Reality:** The problem lies in the merge phase. To find the smallest element among three sub-arrays, you need **2 comparisons** (compare A vs B, then the winner vs C). A standard 2-way merge only needs **1 comparison**.

**Final Verdict:**
The heavy cost of doing double the comparisons during every merge step completely cancels out the benefit of having fewer recursion levels. Because of this, **Standard 2-Way Merge Sort** performs far fewer total operations and remains the superior approach.

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


