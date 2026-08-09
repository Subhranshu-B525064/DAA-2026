# 2.Standard Merge Sort vs Modified 3-Way Merge Sort

## Problem Statement

Consider the following modification to merge sort: divide the input array into thirds (rather than halves), recursively sort each third, and finally combine the results using a three-way merge subroutine. What is the worst-case running time of this modified merge sort? Write a C program to validate your claim by plotting the order of growth for both the merge sort discussed in the class and the modified merge sort described above.

---

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

## 4. Experimental Validation

A C program is used to compare the order of growth of both algorithms.

The program counts the number of comparisons for different input sizes and stores the results in `data.txt`.

GNUplot is used to plot the results.

- X-axis: Input Size (n)
- Y-axis: Number of Comparisons

The graph compares the growth of 2-way and 3-way merge sort.

---

### Conclusion: Standard vs. 3-Way Merge Sort

Although both algorithms have a theoretical time complexity of **$O(n \log n)$**, empirical data proves that **Standard 2-Way Merge Sort is significantly more efficient in practice**.

*   **The Theory:** 3-Way Merge Sort creates a shallower recursion tree (a depth of $\log_3 n$ compared to $\log_2 n$), which might initially seem faster.
*   **The Reality:** The problem lies in the merge phase. To find the smallest element among three sub-arrays, you need **2 comparisons** (compare A vs B, then the winner vs C). A standard 2-way merge only needs **1 comparison**.

**Final Verdict:**
The heavy cost of doing double the comparisons during every merge step completely cancels out the benefit of having fewer recursion levels. Because of this, **Standard 2-Way Merge Sort** performs far fewer total operations and remains the superior approach.

