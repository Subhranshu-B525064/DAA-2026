# DAA-2026
DAA Assignment Submission of Subhranshu Sekhar Dash   B525064

Q1  Order of Growth
    Algorithm:
    1.Start.
    2.Set a sufficiently large value of n (e.g., 500).
    3.Define all mathematical functions to be evaluated.
    4.Compute the value of each function for the chosen value of n.
    5.Store each function's name and its computed value in a structure.
    6.Use the qsort() function with a comparison function to sort the structures in ascending order based on their computed values.
    7.Display the functions in increasing order of growth.
    8.Display the corresponding evaluated values of all functions.
    9.Stop.
    Output:
    Function Order (Lowest to Highest for n = 500):
    1. 1/n
    2. log2(n)
    3. n^0.51
    4. 12 * sqrt(n)
    5. 50 * n^0.5
    6. n * log2(n)
    7. n^2 - 324
    8. 100n^2 + 6n
    9. 2n^3
    10. 2^32 * n
    11. n^log2(n)
    12. 3^n
    Evaluated Data for n = 500:
    1/n             : 2.000000e-03
    log2(n)         : 8.965784e+00
    n^0.51          : 2.384883e+01
    12 * sqrt(n)    : 2.683282e+02
    50 * n^0.5      : 1.118034e+03
    n * log2(n)     : 4.482892e+03
    n^2 - 324       : 2.496760e+05
    100n^2 + 6n     : 2.500300e+07
    2n^3            : 2.500000e+08
    2^32 * n        : 2.147484e+12
    n^log2(n)       : 1.053158e+24
    3^n             : 3.636029e+238
    
  Time Complexity: O(1)
    
Q2  Fair vs Biased Coins
    Algorithm:
    1. Start.
    2. Read the number of trials (N) from the user.
    3. Set the biased coin's probability of getting Heads (e.g., 0.75).
    4. Initialize the random number generator using the current system time.
    5. Initialize two counters:
      fair heads = 0
      biased heads = 0
    6. Repeat the following steps N times:
      . Simulate a fair coin toss:
      . Generate a random value (0 or 1).
      . If the result is 1 (Heads), increment fair heads
      . Simulate a biased coin toss:
      . Generate a random decimal number between 0 and 1.
      . If the number is less than the bias probability, increment biased_heads
    7. Calculate the simulated probabilities:
        Fair Probability = fair_heads / N
        Biased Probability = biased_heads / N
    8. Display:
      . Total number of trials.
      . Number of Heads for the fair coin.
      . Simulated probability of Heads for the fair coin.
      . Number of Heads for the biased coin.
      . Simulated probability of Heads for the biased coin.
    9. Stop.
    Output:
    Enter the number of trials for the coin toss simulation: 1000
    Simulation Results for 1000 Trials
    Fair Coin
    Heads count: 503
    Simulated Probability of Heads: 0.5030 (Expected: 0.5000)
    Biased Coin
    Heads count: 754
    Simulated Probability of Heads: 0.7540 (Expected: 0.7500)
    
  Time Complexity: O(n)

Q3  Bubble Sort Comparison
    Algorithm: Normal Bubble Sort
    1. Start.
    2. Read the number of elements n.
    3. Read the array elements.
    4. Set i = 0
    5. Repeat while i < n - 1:
      . Set j = 0
      . Repeat while j < n - i - 1
        . Compare arr[j] and arr[j + 1]
        . If arr[j] > arr[j + 1] , swap them.
        . Increment j
     . Increment i
    6. Display the sorted array.
    7. Stop.
    Algorithm: Optimized Bubble Sort
    1. Start.
    2. Read the number of elements n.
    3. Read the array elements.
    4. Set i = 0
    5. Repeat while i < n - 1:
      . Set swapped = 0.
      . Set j = 0
      . Repeat while j < n - i - 1:
        . Compare arr[j] and arr[j + 1]
        . If arr[j] > arr[j + 1] :
          . Swap the two elements.
          . Set swapped = 1
        .Increment j.
      . If swapped == 0, terminate the loop (array is already sorted).
      . Increment i
    6. Display the sorted array.
    7. Stop.
    Output:
    Array Size(n) | Normal Comparisons | Optimized Comparisons
    10            | 45                 | 42
    20            | 190                | 181
    30            | 435                | 427
    40            | 780                | 768
    50            | 1225               | 1204

  Time Complexity:
  Normal Bubble Sort
  . Best Case: O(n^2)
  . Average Case: O(n^2)
  . Worst Case: O(n^2)
  
  Optimized Bubble Sort
  . Best Case: O(n) (when the array is already sorted)
  · Average Case: O(n^2)
  . Worst Case: O(n^2)

Q4  Tower of Hanoi
   Algorithm: Tower of Hanoi
    1. Start.
    2. Read the maximum number of discs, n.
    3. If n < 1, display "Invalid input" and Stop.
    4. Print the heading "N-Discs | Total Moves".
    5. For each number of discs i from 1 to n:
       a. Set total_moves = 0.
       b. Call towerOfHanoi(i, 'A', 'B', 'C').
    6. In the recursive function towerOfHanoi(n, Source, Auxiliary, Destination):
       a. If n == 1:
          i. Increment total_moves.
          ii. Return.
       b. Call towerOfHanoi(n - 1, Source, Destination, Auxiliary).
       c. Increment total_moves.
       d. Call towerOfHanoi(n - 1, Auxiliary, Source, Destination).
    7. Print the number of discs and the corresponding total moves.
    8. Stop.
  Output:
    Enter the maximum number of discs (n): 10
    N-Discs | Total Moves
    1   | 1
    2   | 3
    3   | 7
    4   | 15
    5   | 31
    6   | 63
    7   | 127
    8   | 255
    9   | 511
   10   | 1023

  Time Complexity: O(2^n)

  Conclusion from the Plot:
    1. The graph shows that the number of moves increases exponentially as the number of discs increases.
    2. Each additional disc approximately doubles the number of moves required.
    3. Therefore, the algorithm is not efficient for large values of n.
    4. The plot confirms the theoretical relation T(n) = 2^n − 1.
    5. Hence, the time complexity of the Tower of Hanoi algorithm is exponential, O(2^n).
  
Q5  Partition Point
    Algorithm:
    1: Start.
    2: Read the number of elements n.
    3: Input the array containing 0s followed by 1s.
    4: Initialize:
        low = 0
        high = n - 1
        Step 5: While (low <= high), repeat:
        a) Find mid = low + (high - low) / 2.
        b) If arr[mid] == 0,
              set low = mid + 1.
        c) Else,
              If (mid == 0) OR (arr[mid - 1] == 0),
                   return mid (transition point found).
              Else,
                   set high = mid - 1.
    6: If no transition point is found, return -1.
    7: If the returned value is not -1,
        display the transition index.
        Otherwise, display "No transition to 1 was found."
    8: Stop.
    Output:
    Enter the total number of elements in the array: 8
    Enter the elements (a run of 0s followed by a run of 1s), separated by space:
    0 0 0 0 1 1 1 1
    The exact point of transition to 1 is at index: 4
    
  Time Complexity:
    . Best Case: O(1)(When the transition point is found in the first comparison.)
    . Average Case: O(log n)
    . Worst Case: O(log n)

Q6  Duplicate Number Finding
    Algorithm: Find Duplicate Element in an Array
    1: Start.
    2: Read the number of elements (n).
    3: Input the array elements.
    4: Set duplicate = 0.
    5: Repeat for i = 0 to n-2:
            a) Repeat for j = i+1 to n-1:
               i) If arr[i] == arr[j]:
                  - Set duplicate = 1.
                  - Display the duplicate element.
                  - Display its positions (i and j).
                  - Exit the inner loop.
            b) If duplicate == 1, exit the outer loop.
    6: If duplicate == 0, display "All elements are unique."
    7: Stop.
    Output:
    Enter number of elements: 6
    Enter 6 elements:
    10
    20
    30
    40
    20
    50
    Duplicate Element Found : 20
    Position : 1 and 4

  Time complexity:
    . Best Case: O(n) (duplicate found very early, though due to nested loops it's often described as close to O(n) for the earliest match)
    . Worst Case: O(n^2) (no duplicates or duplicate found at the end)
    . Average Case: O(n^2)

  Conclusion:
  The method uses two nested loops to compare each element with every other element. As the number of elements (n) increases, the number of comparisons grows rapidly. For sufficiently large values of n, the execution time becomes high because the algorithm has a time complexity of O(n^2). Therefore, this method is not efficient for large datasets. A better approach is to use a hashing technique, which can detect duplicates in O(n) time using additional memory.
    

  
    
