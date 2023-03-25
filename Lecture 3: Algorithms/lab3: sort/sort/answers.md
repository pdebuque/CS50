## sort1 uses: TODO

data:
- random5000 time: .093s
- random10000 time: .296s
- random50000 time: 8.596s

- reversed5000 time: .092s
- reversed10000 time: .289s
- reversed50000 time: 5.45s

- sorted5000 time: .044s
- sorted10000 time: .064s
- sorted50000 time: .382s

prelim: definitely not selection sort - you would expect all 5000 times to be the same, all 10000, etc.

you would expect bubble to be the fastest with pre-sorted, as a presorted list has O(n), while merge sort would be stuck on O(nlogn)

BUBBLE SORT

### How do you know?: TODO

## sort2 uses: TODO
data:
- random5000 time: .05s
- random10000 time: .083s
- random50000 time: 1.79s

- reversed5000 time: .062s
- reversed10000 time: .052s
- reversed50000 time: 1.697s

- sorted5000 time: .03s
- sorted10000 time: .064s
- sorted50000 time: 1.587s

prelim: again, definitely not selection sort - even though the corresponding times are the same across the files, the speed is much faster than the previous.

MERGE SORT

### How do you know?: TODO

## sort3 uses: TODO
data:
- random5000 time: .047s
- random10000 time: .166s
- random50000 time: 2.977s

- reversed5000 time:  .056s
- reversed10000 time: .166s
- reversed50000 time: 3.059s

- sorted5000 time: .047s
- sorted10000 time: .153s
- sorted50000 time: 3.132s

speed is basically the same across corresponding file sizes, and slower than sort 1.

SELECTION SORT

### How do you know?: TODO
