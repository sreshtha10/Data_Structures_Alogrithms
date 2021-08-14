# Knuth-Morris-Pratt Algorithm

Time complexity of brute force or naive algorithm = O(m*n) where,
m = Length of pattern and n = Length of string

Time complexity of KMP = O(m+n)
___

## Prerequisites

1. Prefix of a string/ pattern = A prefix of a string S is any leading contiguous part of S

2. Suffix of a string/pattern = A suffix of a string S is any trailing contiguous part of S

3. lps (longest prefix viz same as prefix) array also called Pi array- This will contain the length of the longest prefix which is also a suffix. In simple words, lps array observes if the beginning part of the pattern is also at the end or not.

Important Note - We dont backtrack the String in which we are searching the pattern unlike Naive approach.

___

## Steps for Creating LPS Table (Prefix Table)

* Step 1 - Define a one dimensional array with the size equal to the length of the Pattern. (LPS[size])

* Step 2 - Define variables i & j. Set i = 0, j = 1 and LPS[0] = 0.

* Step 3 - Compare the characters at Pattern[i] and Pattern[j].

* Step 4 - If both are matched then set LPS[j] = i+1 and increment both i & j * values by one. Goto to Step 3.

* Step 5 - If both are not matched then check the value of variable 'i'. If it is '0' then set LPS[j] = 0 and increment 'j' value by one, if it is not '0' then set i = LPS[i-1]. Goto Step 3.

* Step 6- Repeat above steps until all the values of LPS[] are filled.

## Algorithm

* Start looping through both string and pattern. Suppose String [1....N] length and Pattern is [1....M].

* Define i=1 and j=0. Start by comparing String[i] with Pattern[j+1]. If its a match increment i & j.

* If it's not a match set j = LPS[j].

* Repeat.

* If at any time j = M-1, therefore the pattern is found. If i = N and still we are looping then the pattern does not exists inside the string.

___

## Alternative Links

* [Explaination 1](http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html)

* [Explaination 2](https://www.educba.com/kmp-algorithm/)

* [Video Explaination](https://www.youtube.com/watch?v=V5-7GzOfADQ)


___