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

---

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


