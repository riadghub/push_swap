# push_swap - 42 School

Tri une pile (A) vers B puis A triée. Score 100/100. Complexité O(n log n) <500 elems. [web:54]

![GIF tri](screenshots/radix.gif) <!-- Enregistre un GIF de ./push_swap 5 2 4 1 3... -->

## Features
- Instructions : sa, sb, pa, pb, ra, rb, rra, rrb, rr, rrr.
- Small (<5) : 3-cycles.
- Medium (5-500) : tisd + radix sort.
- Big (>500) : radix full.
- No leaks, args safe (dups, int range). [web:47]

## Installation
```bash
make && ./push_swap 42 12 8 7 4 2 1
