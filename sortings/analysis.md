In this article, we will discuss more about the time complexity and space complexity of each sorting algorithm.

## Bubble sort and Insertion sort
**Time complexity**
- The average case and the worst case : $O(n^2)$
    -> occurs when the array is reversely sorted.
- The best case : $O(n)$
    -> occurs when the array is already sorted.

**Space complexity :** $O(1)$




## Selection sort
**Time complexity :** The best, average, worst case are all $O(n^2)$

**Space complexity :** $O(1)$




## Merge sort
**Time complexity :** The best, average, worst case are all $O(n\log{n})$

**Space complexity :** $O(n)$




## Heap sort
**Time complexity :** The best, average, worst case are all $O(n\log{n})$

**Space complexity :** $O(1)$




## Quick sort
**Time complexity**
- The best and average case : $O(n\log{n})$
    -> occurs if partition algorithm divides the array in two subarrays with equal size
- The best case : $O(n^2)$
    -> occurs when the array is sorted or reverse sorted, the partition algorithm divides the array in two subarrays with $0$ and $n - 1$ elements.

**Space complexity :** $O(\log{n})$




## Radix sort
**Time complexity :** The best, average and worst case time complexity : $nk$ where $k$ is the maximum number of digits in elements of array. 

**Space complexity :** $O(n + k)$




## Counting sort
**Time complexity :** The best, average and worst case time complexity : $n + k$ where $k$ is the size of count array. 

**Space complexity :** $O(k)$