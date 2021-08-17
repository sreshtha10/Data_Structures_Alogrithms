# Rabin Karp Algorithm

In computer science, the Rabin–Karp algorithm or Karp–Rabin algorithm is a string-searching algorithm created by Richard M. Karp and Michael O. Rabin (1987) that uses hashing to find an exact match of a pattern string in a text. 

---
## Basic Idea of Rabin Karp

It uses a rolling hash to quickly filter out positions of the text that cannot match the pattern, and then checks for a match at the remaining positions.

---

## Time Complexity

Average case - O(n-m+1)
Worst case - O(m*n)

m - length of pattern,
n - length of string

---

## Algorithm
q - Any prime number
```
n = t.length
m = p.length
h = dm-1 mod q
p = 0
t0 = 0
for i = 1 to m
    p = (dp + p[i]) mod q
    t0 = (dt0 + t[i]) mod q
for s = 0 to n - m
    if p = ts
        if p[1.....m] = t[s + 1..... s + m]
            print s //found at s
    If s < n-m
        ts + 1 = (d (ts - t[s + 1]h) + t[s + m + 1]) mod q
```

## Alternative Links

* [Explaination 1](https://www.baeldung.com/cs/rabin-karp-algorithm)

* [Explaination 2](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)

* [Explaination 3](https://www.programiz.com/dsa/rabin-karp-algorithm)

* [Video Explaination](https://www.youtube.com/watch?v=qQ8vS2btsxI)

