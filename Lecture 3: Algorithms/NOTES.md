# algorithms

## problem - search algorithm

how can a computer find pieces of data in its memory?
- imagine data inside closed doors

conceptually, this question is another function. given a collection of closed doors, is the piece of data inside one of them?

### linear search
- for each door, if the data is behind it, return true, else continue
```c
for (each door)
{
  if (that door contains data) return true
}
return false
```

### binary search
- start in the middle and branch out, given data has been stored sorted

```c
if (no doors left) return false
if (50 is behind middle door) return true
else if (50<doors[middle])
search right half
else if (50>doors[middle])
search left half
```
OR

```c
if no doors left return false
if doors[middle] = 50 return true
else if 50<doors[middle] 
{
  search doors[0]-doors[middle-1]
}
else if 50>doors[middle]
{
  search doors[middle+1]-doors[end]
}
```

## running time analysis

the latter algorithm scales better than the first: O(log2(n)) vs. O(n).
- big-O notation cares about the highest magnitude element

common Os:

| notation  | name        |
|-----------|-------------|
| O(n^2)    | exponential |
| O(nlogn)  |             | 
| O(n)      | linear      |
| O(logn)   | logarithmic |
| O(1)      | constant    |

Ω: lower bound on an algorithm
- e.g., Ω(n) says an algorithm takes minimum of n steps.
  - linear search has Ω(1)


θ: if upper and lower bounds are the same

## sorting

Having sorted things is nice. How do we get our things sorted?

input: unsorted thing --> ||--- function ---|| --> sorted thing

### **selection sort**
go through list, find the smallest and swap it with the first element each time

```
for i from 0 to n-1
  find the smallest number between numbers[i] and numbers [n-1]
  swap smallest number with numbers[i]
```

### **bubble sort**
go through the list looking at pairs and put the smaller number first

repeat until the whole list is sorted

(as the algorithm progresses, the largest elements "bubble" to the end of the list)

stop after an iteration has no swaps

```
repeat n times:
  for i from 0 to n-2
    if numbers[i] and numbers[i+1] out of order
      swap them
    if no swaps
      stop
```

### which is faster?
need to count the number of comparisons made in each case.

selection sort: 
- first pass: n-1 comparisons
- second pass: n-2 comparisons
- ...

so, for n elements, the number is

```
(n-1)+(n-2)+(n-3)+...+1
= n(n-1)/2
= n^2/2-n/2
~ n^2
therefore, O(n^2)
```

best case scenario (Ω) for selection sort is *the same* as the lower bound!

**selection sort: Θ(n^2)**

bubble sort:
n-1 happens twice => upper bound is O(n^2)

lower bound? bubble sort is not fixed like selection sort. If the elements are already sorted, Ω(n) (number of comparisons is linear with the number of elements)

## an additional tool for better sorting: recursion

recursion: the ability of a function to call itself

recall binary search: 
```c
if no doors left return false
  return false
if number behind middle door
  return true
else if number < middle door
  search left half // calling search here: recursion! 
else if number > middle door
  search right half // importantly, the function has an exit clause
```

### using recursion: **merge sort**

```c
function sort()
{
if only one number
  quit

sort left half of numbers
sort right half of numbers

// take the smallest left number and the smallest right number, put the smaller of the two in the new list
merge sorted halves 
}
```
note: merge sort uses more space, because it creates a new array of memory to hold data as it sorts

for 8 elements, merge will take 3 steps (2^3), each step taking n steps. Therefore, O(nlogn). Also, Ω(nlogn) => ϴ(nlogn)

the price for the faster sort is the extra space merge sort requires