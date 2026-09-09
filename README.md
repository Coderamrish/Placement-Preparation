<div align="center">

# 🎯 Placement Preparation

### A hands-on archive of DSA & coding-interview solutions in C++ — built while grinding for placements

[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Problems Solved](https://img.shields.io/badge/Problems%20Solved-268-brightgreen?style=for-the-badge)](#-problem-index)
[![LeetCode](https://img.shields.io/badge/LeetCode-107-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](#-leetcode-107)
[![GFG](https://img.shields.io/badge/GeeksforGeeks-94-2F8D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white)](#-geeksforgeeks-gfg-94)
[![TCS NQT](https://img.shields.io/badge/TCS%20%2F%20NQT-29-0033A0?style=for-the-badge)](#-tcs--tcs-nqt-29)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-ff69b4?style=for-the-badge)](#-contributing)

**New to DSA or placement prep? Start here 👉 [What even is this repo?](#-new-here-start-in-60-seconds)**

[📚 Problem Index](#-problem-index) • [🗂 Structure](#-how-a-solution-file-is-organized) • [🚀 Getting Started](#-getting-started) • [🧠 Topics](#-topics-covered) • [👤 Author](#-author)

</div>

---

## 🙋 New here? Start in 60 seconds

If you've never used a repo like this before, here's the short version:

> This is **one C++ file per problem**. Each file has the problem statement copied in as a comment at the top, followed by a working solution. That's it — no build system, no dependencies, nothing fancy.

**Why it's useful to you:**
- 🔍 **Browse by platform** — jump straight to the [LeetCode](#-leetcode-107) or [GeeksforGeeks](#-geeksforgeeks-gfg-94) table below. Every row has a one-line problem summary and a link to look the problem up on that platform.
- 🧪 **Copy, compile, run** — every `.cpp` file works standalone. Grab one, compile it, and test it against your own inputs.
- 🗓️ **See a real prep timeline** — filenames like `tcs28june.cpp` or `nqt8jul.cpp` are dated. They're not random; they map to actual practice sessions, so the repo doubles as a day-by-day prep log.
- 🏢 **Focus on your target company** — separate sections exist for **TCS / TCS NQT** and **Infosys** style questions if that's what you're prepping for.

> 💡 **Tip for absolute beginners:** if a term like "sliding window" or "DP" in the topics list below is unfamiliar, that's completely normal — pick any file in that category, read the problem comment, then read the code line-by-line. Understanding *one* solved example is the fastest way into a new pattern.

## 📊 Repository at a Glance

<div align="center">

| Platform / Source | Files | Share | Jump to |
|:---|:---:|:---:|:---:|
| 🟠 **LeetCode** | 107 | 40% | [→ Table](#-leetcode-107) |
| 🟢 **GeeksforGeeks (incl. POTD)** | 94 | 35% | [→ Table](#-geeksforgeeks-gfg-94) |
| 🔵 **TCS / TCS NQT** | 29 | 11% | [→ Table](#-tcs--tcs-nqt-29) |
| ⚪ **Miscellaneous DSA Drills** | 24 | 9% | [→ Table](#-miscellaneous-dsa-practice-24) |
| 🟣 **NQT (General)** | 11 | 4% | [→ Table](#-nqt-general-practice-11) |
| 🟡 **Infosys** | 3 | 1% | [→ Table](#-infosys-3) |
| **Total** | **268** | **100%** | |

</div>

## 📌 About This Repo

This is a **daily-practice log**, not a curated tutorial — every file is a real problem solved while preparing for coding interviews and placement drives. Problems come from:

- 🟠 **LeetCode** — classic interview questions across arrays, strings, DP, graphs, and heaps
- 🟢 **GeeksforGeeks** — practice sets and daily **Problem of the Day (POTD)** challenges
- 🔵 **TCS NQT** — questions and patterns from the TCS National Qualifier Test
- 🟡 **Infosys** — questions based on Infosys placement test patterns
- ⚪ **Miscellaneous** — general DSA drills (Kadane's Algorithm, Stock Buy/Sell, sorting algorithms, etc.)

## 🗂 How a Solution File Is Organized

Every file is self-contained and follows the same anatomy, so you always know what you're looking at:

```cpp
/*
   Problem statement, constraints, and example input/output
   copied in as a comment block for quick reference.
*/
#include <bits/stdc++.h>
using namespace std;

/* Core algorithm / solution function */
int solve(...) {
    // logic
}

/* Driver code - reads input from stdin, prints result to stdout */
int main() {
    // I/O handling
}
```

This means you can compile and run **any single file** in isolation to test it against sample input — no need to touch the rest of the repo.

## 🚀 Getting Started

### Prerequisites
- A C++ compiler — `g++` (GCC) recommended

### Clone & Run

```bash
# 1. Clone the repository
git clone https://github.com/Coderamrish/Placement-Preparation.git
cd Placement-Preparation

# 2. Compile any solution
g++ -O2 -o solution leetcode215.cpp

# 3. Run it and provide input as described in the file's comment header
./solution
```

## 📚 Problem Index

All **268** problems, grouped by source, each with a one-line summary and a link out to the platform so you can read the full statement, check constraints, or submit your own attempt.

> ℹ️ **About the links:** LeetCode problem numbers are global, so the **"Practice on LeetCode"** links search LeetCode directly for that exact problem number. GeeksforGeeks doesn't expose a stable per-problem numbering scheme, so the **"Search on GFG"** links run a GFG site search using keywords from the problem statement — click through and the problem will be at or near the top of the results. TCS / Infosys / NQT questions come from private assessment platforms, so those sections link only to the local file.

<details open>
<summary><strong>🟠 LeetCode (107)</strong></summary>

| # | Problem | File | Practice on LeetCode |
|---|---|---|---|
| 1 | Given a string s, find the length of the longest substring without duplicate characters. Example 1: Input: s... | [`leetcode3.cpp`](./leetcode3.cpp) | [🔗 Open #3](https://leetcode.com/problemset/?search=3) |
| 2 | Given an integer x, return true if x is a palindrome, and false otherwise. Example 1: Input: x = 121 Output:... | [`leetcode9.cpp`](./leetcode9.cpp) | [🔗 Open #9](https://leetcode.com/problemset/?search=9) |
| 3 | Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input... | [`leetcode20.cpp`](./leetcode20.cpp) | [🔗 Open #20](https://leetcode.com/problemset/?search=20) |
| 4 | Given an unsorted array of N integers, find the smallest missing positive integer. Your algorithm should run... | [`leetcode41.cpp`](./leetcode41.cpp) | [🔗 Open #41](https://leetcode.com/problemset/?search=41) |
| 5 | Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how... | [`leetcode42.cpp`](./leetcode42.cpp) | [🔗 Open #42](https://leetcode.com/problemset/?search=42) |
| 6 | You are given an integer array nums. You are initially positioned at the array's first index, and each... | [`leetcode55.cpp`](./leetcode55.cpp) | [🔗 Open #55](https://leetcode.com/problemset/?search=55) |
| 7 | Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.... | [`Leetcode136.cpp`](./Leetcode136.cpp) | [🔗 Open #136](https://leetcode.com/problemset/?search=136) |
| 8 | A peak element is an element that is strictly greater than its neighbors. Given a 0-indexed integer array... | [`leetcode162.cpp`](./leetcode162.cpp) | [🔗 Open #162](https://leetcode.com/problemset/?search=162) |
| 9 | Given an integer array nums and an integer k, return the kth largest element in the array. Note that it is... | [`leetcode215.cpp`](./leetcode215.cpp) | [🔗 Open #215](https://leetcode.com/problemset/?search=215) |
| 10 | Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of... | [`leetcode231.cpp`](./leetcode231.cpp) | [🔗 Open #231](https://leetcode.com/problemset/?search=231) |
| 11 | Given two strings s and t, return true if t is an anagram of s, and false otherwise. Example 1: Input: s =... | [`leetcode242.cpp`](./leetcode242.cpp) | [🔗 Open #242](https://leetcode.com/problemset/?search=242) |
| 12 | Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range... | [`leetcode268.cpp`](./leetcode268.cpp) | [🔗 Open #268](https://leetcode.com/problemset/?search=268) |
| 13 | You are given two jugs with capacities x liters and y liters. You have an infinite water supply. Return... | [`leetcode365.cpp`](./leetcode365.cpp) | [🔗 Open #365](https://leetcode.com/problemset/?search=365) |
| 14 | Given two integers a and b, return the sum of the two integers without using the operators + and -. Example... | [`leetcode371.cpp`](./leetcode371.cpp) | [🔗 Open #371](https://leetcode.com/problemset/?search=371) |
| 15 | Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the... | [`leetcode434.cpp`](./leetcode434.cpp) | [🔗 Open #434](https://leetcode.com/problemset/?search=434) |
| 16 | There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The... | [`leetcode435.cpp`](./leetcode435.cpp) | [🔗 Open #435](https://leetcode.com/problemset/?search=435) |
| 17 | You are given three integers n, l, and r. A ZigZag array of length n is defined as follows: Each element lies... | [`leetode439.cpp`](./leetode439.cpp) | [🔗 Open #439](https://leetcode.com/problemset/?search=439) |
| 18 | You are given three integers n, l, and r. A ZigZag array of length n is defined as follows: Each element lies... | [`leetcode440.cpp`](./leetcode440.cpp) | [🔗 Open #440](https://leetcode.com/problemset/?search=440) |
| 19 | You are given an integer array nums and an integer target. Return the number of subarrays of nums in which... | [`leetcode441.cpp`](./leetcode441.cpp) | [🔗 Open #441](https://leetcode.com/problemset/?search=441) |
| 20 | You are given an array of positive integers nums. You need to select a subset of nums which satisfies the... | [`leetcode443.cpp`](./leetcode443.cpp) | [🔗 Open #443](https://leetcode.com/problemset/?search=443) |
| 21 | You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it... | [`leetcode444.cpp`](./leetcode444.cpp) | [🔗 Open #444](https://leetcode.com/problemset/?search=444) |
| 22 | Given an array of strings patterns and a string word, return the number of strings in patterns that exist as... | [`leetcode445.cpp`](./leetcode445.cpp) | [🔗 Open #445](https://leetcode.com/problemset/?search=445) |
| 23 | Given a string s consisting only of characters a, b and c. Return the number of substrings containing at... | [`leetcode446.cpp`](./leetcode446.cpp) | [🔗 Open #446](https://leetcode.com/problemset/?search=446) |
| 24 | You are given an m x n binary matrix grid and an integer health. You start on the upper-left corner (0, 0)... | [`leetcode448.cpp`](./leetcode448.cpp) | [🔗 Open #448](https://leetcode.com/problemset/?search=448) |
| 25 | You are given a directed acyclic graph of n nodes numbered from 0 to n − 1. This is represented by a 2D array... | [`leetcode449.cpp`](./leetcode449.cpp) | [🔗 Open #449](https://leetcode.com/problemset/?search=449) |
| 26 | You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array... | [`leetcode450.cpp`](./leetcode450.cpp) | [🔗 Open #450](https://leetcode.com/problemset/?search=450) |
| 27 | You are given a square board of characters. You can move on the board starting at the bottom right square... | [`leetcode451.cpp`](./leetcode451.cpp) | [🔗 Open #451](https://leetcode.com/problemset/?search=451) |
| 28 | Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals... | [`leetcode452.cpp`](./leetcode452.cpp) | [🔗 Open #452](https://leetcode.com/problemset/?search=452) |
| 29 | You are given an integer n. Form a new integer x by concatenating all the non-zero digits of n in their... | [`leetcode453.cpp`](./leetcode453.cpp) | [🔗 Open #453](https://leetcode.com/problemset/?search=453) |
| 30 | You are given a string s of length m consisting of digits. You are also given a 2D integer array queries,... | [`leetcode454.cpp`](./leetcode454.cpp) | [🔗 Open #454](https://leetcode.com/problemset/?search=454) |
| 31 | You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1. You are also... | [`leetcode455.cpp`](./leetcode455.cpp) | [🔗 Open #455](https://leetcode.com/problemset/?search=455) |
| 32 | You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1. You are also... | [`leetcode456.cpp`](./leetcode456.cpp) | [🔗 Open #456](https://leetcode.com/problemset/?search=456) |
| 33 | You are given an undirected graph with N vertices numbered from 0 to N-1 and M edges. A connected component... | [`leetcode457.cpp`](./leetcode457.cpp) | [🔗 Open #457](https://leetcode.com/problemset/?search=457) |
| 34 | Given an array of integers arr, replace each element with its rank. The rank represents how large the element... | [`leetcode458.cpp`](./leetcode458.cpp) | [🔗 Open #458](https://leetcode.com/problemset/?search=458) |
| 35 | A sequential digit number is a number in which every digit is exactly one greater than its previous digit.... | [`leetcode459.cpp`](./leetcode459.cpp) | [🔗 Open #459](https://leetcode.com/problemset/?search=459) |
| 36 | You are given an integer array nums. Your task is to find the number of pairs of non-empty subsequences... | [`leetcode460.cpp`](./leetcode460.cpp) | [🔗 Open #460](https://leetcode.com/problemset/?search=460) |
| 37 | You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values: sumOdd:... | [`leetcode461.cpp`](./leetcode461.cpp) | [🔗 Open #461](https://leetcode.com/problemset/?search=461) |
| 38 | You are given an integer array nums of length n. Construct an array prefixGcd where for each index i: Let mxi... | [`leetcode462.cpp`](./leetcode462.cpp) | [🔗 Open #462](https://leetcode.com/problemset/?search=462) |
| 39 | Given an integer array nums, return the greatest common divisor of the smallest number and largest number in... | [`leetocde464.cpp`](./leetocde464.cpp) | [🔗 Open #464](https://leetcode.com/problemset/?search=464) |
| 40 | Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct... | [`leetcode465.cpp`](./leetcode465.cpp) | [🔗 Open #465](https://leetcode.com/problemset/?search=465) |
| 41 | Given a 2D grid of size m x n and an integer k. You need to shift the grid k times. In one shift operation:... | [`leetcode466.cpp`](./leetcode466.cpp) | [🔗 Open #466](https://leetcode.com/problemset/?search=466) |
| 42 | You are given a binary string s of length n, where: '1' represents an active section. '0' represents an... | [`leetcode467.cpp`](./leetcode467.cpp) | [🔗 Open #467](https://leetcode.com/problemset/?search=467) |
| 43 | You are given a binary string s of length n, where: '1' represents an active section. '0' represents an... | [`leetcode468.cpp`](./leetcode468.cpp) | [🔗 Open #468](https://leetcode.com/problemset/?search=468) |
| 44 | You are given an integer array nums. A XOR triplet is defined as the XOR of three elements nums[i] XOR... | [`leetcode470.cpp`](./leetcode470.cpp) | [🔗 Open #470](https://leetcode.com/problemset/?search=470) |
| 45 | You are given a positive integer n. Return the maximum product of any two digits in n. Note: You may use the... | [`leetcode471.cpp`](./leetcode471.cpp) | [🔗 Open #471](https://leetcode.com/problemset/?search=471) |
| 46 | Given the array of integers nums, you will choose two different indices i and j of that array. Return the... | [`leetcode473.cpp`](./leetcode473.cpp) | [🔗 Open #473](https://leetcode.com/problemset/?search=473) |
| 47 | You are given a palindromic string s. Return the lexicographically smallest palindromic permutation of s.... | [`leetcode474.cpp`](./leetcode474.cpp) | [🔗 Open #474](https://leetcode.com/problemset/?search=474) |
| 48 | You are given a palindromic string s and an integer k. Return the k-th lexicographically smallest palindromic... | [`leetcode475.cpp`](./leetcode475.cpp) | [🔗 Open #475](https://leetcode.com/problemset/?search=475) |
| 49 | You are given a string word containing distinct lowercase English letters. Telephone keypads have keys mapped... | [`leetcode476.cpp`](./leetcode476.cpp) | [🔗 Open #476](https://leetcode.com/problemset/?search=476) |
| 50 | You are given a string word containing lowercase English letters. Telephone keypads have keys mapped with... | [`leetcode477.cpp`](./leetcode477.cpp) | [🔗 Open #477](https://leetcode.com/problemset/?search=477) |
| 51 | You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.... | [`leetcode478.cpp`](./leetcode478.cpp) | [🔗 Open #478](https://leetcode.com/problemset/?search=478) |
| 52 | Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each... | [`leetcode479.cpp`](./leetcode479.cpp) | [🔗 Open #479](https://leetcode.com/problemset/?search=479) |
| 53 | Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each... | [`leetcode480.cpp`](./leetcode480.cpp) | [🔗 Open #480](https://leetcode.com/problemset/?search=480) |
| 54 | You are maintaining a project that has n methods numbered from 0 to n - 1. You are given two integers n and... | [`leetcode482.cpp`](./leetcode482.cpp) | [🔗 Open #482](https://leetcode.com/problemset/?search=482) |
| 55 | You are given two integers n and t. Return the smallest number greater than or equal to n such that the... | [`leetcode483.cpp`](./leetcode483.cpp) | [🔗 Open #483](https://leetcode.com/problemset/?search=483) |
| 56 | You are given two strings word1 and word2. A string x is called almost equal to y if you can change at most... | [`leetcode485.cpp`](./leetcode485.cpp) | [🔗 Open #485](https://leetcode.com/problemset/?search=485) |
| 57 | Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and... | [`leetcode486.cpp`](./leetcode486.cpp) | [🔗 Open #486](https://leetcode.com/problemset/?search=486) |
| 58 | Alice and Bob take turns playing a game, with Alice starting first. Initially, there are n stones in a pile.... | [`leetcode487.cpp`](./leetcode487.cpp) | [🔗 Open #487](https://leetcode.com/problemset/?search=487) |
| 59 | You are given a 0-indexed array of integers nums. A prefix nums[0..i] is sequential if, for all 1 <= j <= i,... | [`leetcode488.cpp`](./leetcode488.cpp) | [🔗 Open #488](https://leetcode.com/problemset/?search=488) |
| 60 | You are given an integer array nums and an integer k. The frequency of an element x is the number of times it... | [`leetcode489.cpp`](./leetcode489.cpp) | [🔗 Open #489](https://leetcode.com/problemset/?search=489) |
| 61 | You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a... | [`leetcode490.cpp`](./leetcode490.cpp) | [🔗 Open #490](https://leetcode.com/problemset/?search=490) |
| 62 | Given a string s, return the maximum length of a substring such that it contains at most two occurrences of... | [`leetcode491.cpp`](./leetcode491.cpp) | [🔗 Open #491](https://leetcode.com/problemset/?search=491) |
| 63 | You are given an integer array nums. Return the length of the longest subsequence in nums whose bitwise XOR... | [`leetcode492.cpp`](./leetcode492.cpp) | [🔗 Open #492](https://leetcode.com/problemset/?search=492) |
| 64 | Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated... | [`leetcode493.cpp`](./leetcode493.cpp) | [🔗 Open #493](https://leetcode.com/problemset/?search=493) |
| 65 | There are several stones arranged in a row, and each stone has an associated value which is an integer given... | [`leetcode494.cpp`](./leetcode494.cpp) | [🔗 Open #494](https://leetcode.com/problemset/?search=494) |
| 66 | You are given an integer array nums and an integer k. An integer x is almost missing from nums if x appears... | [`leetcode495.cpp`](./leetcode495.cpp) | [🔗 Open #495](https://leetcode.com/problemset/?search=495) |
| 67 | A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10. You are... | [`leetcode496.cpp`](./leetcode496.cpp) | [🔗 Open #496](https://leetcode.com/problemset/?search=496) |
| 68 | You are given a 1-indexed array of distinct integers nums of length n. You need to distribute all the... | [`leetcode497.cpp`](./leetcode497.cpp) | [🔗 Open #497](https://leetcode.com/problemset/?search=497) |
| 69 | You are given an integer array coins representing coins of different denominations and an integer k. You have... | [`leetcode498.cpp`](./leetcode498.cpp) | [🔗 Open #498](https://leetcode.com/problemset/?search=498) |
| 70 | You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:... | [`leetcode499.cpp`](./leetcode499.cpp) | [🔗 Open #499](https://leetcode.com/problemset/?search=499) |
| 71 | Alice and Bob take turns playing a game, with Alice starting first. You are given a string num of even length... | [`leetcode500.cpp`](./leetcode500.cpp) | [🔗 Open #500](https://leetcode.com/problemset/?search=500) |
| 72 | Alice and Bob take turns playing a game, with Alice starting first. There are n stones arranged in a row. On... | [`leetcode501.cpp`](./leetcode501.cpp) | [🔗 Open #501](https://leetcode.com/problemset/?search=501) |
| 73 | Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital,... | [`leetcode502.cpp`](./leetcode502.cpp) | [🔗 Open #502](https://leetcode.com/problemset/?search=502) |
| 74 | See file for full problem statement | [`leetcode505.cpp`](./leetcode505.cpp) | [🔗 Open #505](https://leetcode.com/problemset/?search=505) |
| 75 | You are given a 0-indexed array of positive integers nums and a positive integer limit. In one operation, you... | [`leetcode506.cpp`](./leetcode506.cpp) | [🔗 Open #506](https://leetcode.com/problemset/?search=506) |
| 76 | You are given a 0-indexed array of distinct integers nums. There is an element in nums that has the lowest... | [`leetcode507.cpp`](./leetcode507.cpp) | [🔗 Open #507](https://leetcode.com/problemset/?search=507) |
| 77 | A critical point in a linked list is defined as either a local maxima or a local minima. A node is a local... | [`leetcode508.cpp`](./leetcode508.cpp) | [🔗 Open #508](https://leetcode.com/problemset/?search=508) |
| 78 | You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered... | [`leetcode509.cpp`](./leetcode509.cpp) | [🔗 Open #509](https://leetcode.com/problemset/?search=509) |
| 79 | You are given an array nums1 of n distinct integers. You want to construct another array nums2 of length n... | [`leetcode510.cpp`](./leetcode510.cpp) | [🔗 Open #510](https://leetcode.com/problemset/?search=510) |
| 80 | You are given an array nums1 of n distinct integers. You want to construct another array nums2 of length n... | [`leetcode511.cpp`](./leetcode511.cpp) | [🔗 Open #511](https://leetcode.com/problemset/?search=511) |
| 81 | You are given an integer array nums of length n and an integer k. For each index i, define its instability... | [`leetcode512.cpp`](./leetcode512.cpp) | [🔗 Open #512](https://leetcode.com/problemset/?search=512) |
| 82 | You are given an integer array nums of length n and an integer k. For each index i, define its instability... | [`leetcode513.cpp`](./leetcode513.cpp) | [🔗 Open #513](https://leetcode.com/problemset/?search=513) |
| 83 | Given two strings s and t, return the number of distinct subsequences of s which equals t. The test cases are... | [`leetcode514.cpp`](./leetcode514.cpp) | [🔗 Open #514](https://leetcode.com/problemset/?search=514) |
| 84 | Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very... | [`leetode515.cpp`](./leetode515.cpp) | [🔗 Open #515](https://leetcode.com/problemset/?search=515) |
| 85 | You are given an integer n. Return the total number of commas used when writing all integers from [1, n]... | [`leetcode516.cpp`](./leetcode516.cpp) | [🔗 Open #516](https://leetcode.com/problemset/?search=516) |
| 86 | You are given an integer n. Return the total number of commas used when writing all integers from [1, n]... | [`leetcode517.cpp`](./leetcode517.cpp) | [🔗 Open #517](https://leetcode.com/problemset/?search=517) |
| 87 | Given an integer array nums, find three numbers whose product is maximum and return the maximum product.... | [`leetcode628.cpp`](./leetcode628.cpp) | [🔗 Open #628](https://leetcode.com/problemset/?search=628) |
| 88 | There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] =... | [`leetcode630.cpp`](./leetcode630.cpp) | [🔗 Open #630](https://leetcode.com/problemset/?search=630) |
| 89 | Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,... | [`leetocde973.cpp`](./leetocde973.cpp) | [🔗 Open #973](https://leetcode.com/problemset/?search=973) |
| 90 | Given a string text, you want to use the characters of text to form as many instances of the word "balloon"... | [`leetcode1189.cpp`](./leetcode1189.cpp) | [🔗 Open #1189](https://leetcode.com/problemset/?search=1189) |
| 91 | You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n... | [`leetcode1383.cpp`](./leetcode1383.cpp) | [🔗 Open #1383](https://leetcode.com/problemset/?search=1383) |
| 92 | Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its... | [`leetcode1394.cpp`](./leetcode1394.cpp) | [🔗 Open #1394](https://leetcode.com/problemset/?search=1394) |
| 93 | It is a sweltering summer day, and a boy wants to buy some ice cream bars. At the store, there are n ice... | [`letcode1833.cpp`](./letcode1833.cpp) | [🔗 Open #1833](https://leetcode.com/problemset/?search=1833) |
| 94 | You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1... | [`leetcode1840.cpp`](./leetcode1840.cpp) | [🔗 Open #1840](https://leetcode.com/problemset/?search=1840) |
| 95 | You are given the head of a linked list. Delete the middle node, and return the head of the modified linked... | [`leetcode2095.cpp`](./leetcode2095.cpp) | [🔗 Open #2095](https://leetcode.com/problemset/?search=2095) |
| 96 | See file for full problem statement | [`leetocde 2130.cpp`](./leetocde%202130.cpp) | [🔗 Open #2130](https://leetcode.com/problemset/?search=2130) |
| 97 | You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following... | [`leetcode2161.cpp`](./leetcode2161.cpp) | [🔗 Open #2161](https://leetcode.com/problemset/?search=2161) |
| 98 | You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates... | [`leetcode2196.cpp`](./leetcode2196.cpp) | [🔗 Open #2196](https://leetcode.com/problemset/?search=2196) |
| 99 | You are given a 0-indexed integer array nums of size n. Define two arrays leftSum and rightSum where:... | [`leetcode2754.cpp`](./leetcode2754.cpp) | [🔗 Open #2754](https://leetcode.com/problemset/?search=2754) |
| 100 | You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents: A cell containing a thief if... | [`leetcode2812.cpp`](./leetcode2812.cpp) | [🔗 Open #2812](https://leetcode.com/problemset/?search=2812) |
| 101 | You are given an integer array nums of length n and an integer array queries. Let gcdPairs denote an array... | [`leetcode3312.cpp`](./leetcode3312.cpp) | [🔗 Open #3312](https://leetcode.com/problemset/?search=3312) |
| 102 | You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and... | [`leetcode3614.cpp`](./leetcode3614.cpp) | [🔗 Open #3614](https://leetcode.com/problemset/?search=3614) |
| 103 | You are given an integer array nums of length n and an integer k. You need to choose exactly k non-empty... | [`leetcode3689.cpp`](./leetcode3689.cpp) | [🔗 Open #3689](https://leetcode.com/problemset/?search=3689) |
| 104 | You are given an integer array nums of length n and an integer k. You must select exactly k distinct... | [`leetcode3691.cpp`](./leetcode3691.cpp) | [🔗 Open #3691](https://leetcode.com/problemset/?search=3691) |
| 105 | You are given an integer array nums and an integer target. Return the number of subarrays of nums in which... | [`leetcode3739.cpp`](./leetcode3739.cpp) | [🔗 Open #3739](https://leetcode.com/problemset/?search=3739) |
| 106 | You are given two integers num1 and num2 representing an inclusive range [num1, num2]. The waviness of a... | [`Leetcode3753.cpp`](./Leetcode3753.cpp) | [🔗 Open #3753](https://leetcode.com/problemset/?search=3753) |
| 107 | You are given an array of strings words, where each string represents a word containing lowercase English... | [`Leetocde3838.cpp`](./Leetocde3838.cpp) | [🔗 Open #3838](https://leetcode.com/problemset/?search=3838) |

</details>

<details>
<summary><strong>🟢 GeeksforGeeks / GFG (94)</strong></summary>

| # | Problem | File | Search on GFG |
|---|---|---|---|
| 1 | Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication... | [`gfg353.cpp`](./gfg353.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20matrix%20mat%20size%20where%20mat%20represents) |
| 2 | Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in... | [`gfg423.cpp`](./gfg423.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20singly%20linked%20list%20remove%20all%20nodes) |
| 3 | Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an... | [`gfg424.cpp`](./gfg424.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20representing%20the%20number%20people%20seated) |
| 4 | Given an array arr[] consisting of n distinct integers, find the maximum count of integers that are binary... | [`gfg425.cpp`](./gfg425.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20consisting%20distinct%20integers%20find) |
| 5 | Given a string s of opening and closing brackets '(' and ')' only, find an equal point in the string. An... | [`gfg426.cpp`](./gfg426.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20string%20opening%20and%20closing%20brackets%20and) |
| 6 | Given a string s and an integer k, check if it is possible to convert s to a string that is repetition of a... | [`gfg427.cpp`](./gfg427.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20string%20and%20integer%20check%20possible%20convert) |
| 7 | Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as... | [`gfg428.cpp`](./gfg428.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20number%20find%20count%20all%20binary%20sequences) |
| 8 | Given a matrix mat[][] of size n × m consisting of 0s and 1s. You start at the top-left cell (0, 0) and... | [`gfg429.cpp`](./gfg429.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20matrix%20mat%20size%20consisting%20and%20You) |
| 9 | There is an array that initially contains only a single value, 0. Given a list of queries queries[][] of size... | [`gfg431.cpp`](./gfg431.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=There%20array%20that%20initially%20contains%20only%20single) |
| 10 | Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is... | [`gfg432.cpp`](./gfg432.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20rope%20length%20meters%20cut%20into%20multiple) |
| 11 | Given a binary matrix mat[][] containing only 0s and 1s, find the total coverage of all 0's. The coverage of... | [`gfg433.cpp`](./gfg433.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20binary%20matrix%20mat%20containing%20only%20and) |
| 12 | Given a sorted array arr[]. For each i(0 ≤ i ≤ n-1), make all the elements of the array from index 0 to i... | [`gfg434.cpp`](./gfg434.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20sorted%20array%20arr%20For%20each%20make) |
| 13 | Given two integers a and b in the form of strings. Return the last digit of ab. Examples: Input: a = "3", b =... | [`gfg435.cpp`](./gfg435.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integers%20and%20the%20form%20strings) |
| 14 | Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at... | [`gfg436.cpp`](./gfg436.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20string%20lowercase%20English%20letters%20you%20can) |
| 15 | Given an integer array height[], where height[i] represents the height of the ith bar arranged in a row, find... | [`gfg437.cpp`](./gfg437.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20array%20height%20where%20height%20represents) |
| 16 | There are infinitely many people standing in a row, indexed from 1. The strength of the person at index i is... | [`gfg438.cpp`](./gfg438.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=There%20are%20infinitely%20many%20people%20standing%20row) |
| 17 | Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump... | [`gfg439.cpp`](./gfg439.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20matrix%20mat%20size%20where%20mat%20represents) |
| 18 | Given an integer n, return all the n digit numbers in increasing order, such that their digits are in... | [`gfg440.cpp`](./gfg440.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20return%20all%20the%20digit%20numbers) |
| 19 | Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2. Return the... | [`gfg441.cpp`](./gfg441.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20strings%20and%20count%20the%20number) |
| 20 | Given a floor of dimensions n × m and an unlimited supply of tiles of size 1 × m, find the total number of... | [`gfg442.cpp`](./gfg442.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20floor%20dimensions%20and%20unlimited%20supply%20tiles) |
| 21 | Given two integers n and k, count the number of binary strings of length n where adjacent 1 appear k times.... | [`gfg443.cpp`](./gfg443.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integers%20and%20count%20the%20number) |
| 22 | Given two arrays a[] and b[] of positive integers of size n and m respectively, where m ≤ n. You are allowed... | [`gfg444.cpp`](./gfg444.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20arrays%20and%20positive%20integers%20size) |
| 23 | Given two arrays a[] and b[] of size n and m respectively, find the minimum number of insertions and... | [`gfg445.cpp`](./gfg445.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20arrays%20and%20size%20and%20respectively) |
| 24 | Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one... | [`gfg446.cpp`](./gfg446.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20find%20the%20maximum%20sum) |
| 25 | Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of... | [`gfg447.cpp`](./gfg447.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20positive%20integers%20and%20value) |
| 26 | Given two strings s1 and s2 consisting of lowercase English letters of length n1 and n2 respectively, find... | [`gfg448.cpp`](./gfg448.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20strings%20and%20consisting%20lowercase%20English) |
| 27 | Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than... | [`gfg449.cpp`](./gfg449.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20binary%20string%20consists%20only%20and%20Calculate) |
| 28 | Given a string s consisting of lowercase English letters, find the maximum number of characters between any... | [`gfg450.cpp`](./gfg450.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20string%20consisting%20lowercase%20English%20letters%20find) |
| 29 | Given two sorted arrays of distinct integers in increasing order a[] and b[], which may have some common... | [`gfg451.cpp`](./gfg451.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20sorted%20arrays%20distinct%20integers%20increasing) |
| 30 | Given two integers n and m, and an array arr[][] of size k, where arr[i] = [r, c] represents a blocked cell... | [`gfg452.cpp`](./gfg452.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integers%20and%20and%20array%20arr) |
| 31 | Given an array arr[] and positive integer k, count total number of pairs in the array whose sum is divisible... | [`gfg454.cpp`](./gfg454.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20and%20positive%20integer%20count) |
| 32 | Given a number n, find the number of ways to represent this number as a sum of 2 or more consecutive natural... | [`gfg455.cpp`](./gfg455.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20number%20find%20the%20number%20ways%20represent) |
| 33 | Given a binary matrix of size M × N consisting of 0s and 1s, where 1 represents a valid cell and 0 represents... | [`gfg456.cpp`](./gfg456.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20binary%20matrix%20size%20consisting%20and%20where) |
| 34 | Given an integer array arr[], where arr[i] denotes the number of tickets available with the i-th ticket... | [`gfg457.cpp`](./gfg457.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20array%20arr%20where%20arr%20denotes) |
| 35 | Consider an array a[] = [1, 2, 3, ..., n] and a permutation b[] of size n containing all integers from 1 to n... | [`gfg458.cpp`](./gfg458.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Consider%20array%20and%20permutation%20size%20containing%20all) |
| 36 | Problem Statement A number X is processed with each element of an array from left to right. For every array... | [`gfg459.cpp`](./gfg459.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Problem%20Statement%20number%20processed%20with%20each%20element) |
| 37 | Given an array arr[] of size n containing positive integers, return the maximum length of the bitonic... | [`gfg460.cpp`](./gfg460.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20size%20containing%20positive%20integers) |
| 38 | Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.... | [`gfg461.cpp`](./gfg461.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integers%20and%20sum%20determine%20the) |
| 39 | Given an array of integers arr[], find two non-overlapping contiguous sub-arrays such that the absolute... | [`gfg462.cpp`](./gfg462.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20integers%20arr%20find%20two%20non) |
| 40 | Given a matrix of 0s and 1s and an integer k, divide the matrix into k pieces such that each piece has at... | [`gfg463.cpp`](./gfg463.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20matrix%20and%20and%20integer%20divide%20the) |
| 41 | Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a... | [`gfg464.cpp`](./gfg464.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20and%20list%20queries%20For) |
| 42 | Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among... | [`gfg465.cpp`](./gfg465.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20strings%20arr%20find%20the%20shortest) |
| 43 | Given a string s containing lowercase English alphabets. Start from any index containing the character 'a'... | [`gfg466.cpp`](./gfg466.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20string%20containing%20lowercase%20English%20alphabets%20Start) |
| 44 | Given an array arr[], find the minimum number of elements to delete so that the remaining elements form a... | [`gfg467.cpp`](./gfg467.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20find%20the%20minimum%20number) |
| 45 | Given an array arr[ ] consisting of distinct integers, check if the given array can represent preorder... | [`gfg468.cpp`](./gfg468.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20consisting%20distinct%20integers%20check) |
| 46 | Given the root of a Binary Tree, find the length of the longest path consisting of connected nodes such that... | [`gfg469.cpp`](./gfg469.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20the%20root%20Binary%20Tree%20find%20the) |
| 47 | Given a n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible... | [`gfg470.cpp`](./gfg470.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20grid%20mat%20integers%20where%20values%20can) |
| 48 | Given two arrays pre[] and preMirror[] of size n containing unique elements, where pre[] represents the... | [`gfg472.cpp`](./gfg472.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20arrays%20pre%20and%20preMirror%20size) |
| 49 | Given a weighted undirected graph with V vertices numbered from 0 to V - 1, represented by an array edges,... | [`gfg473.cpp`](./gfg473.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20weighted%20undirected%20graph%20with%20vertices%20numbered) |
| 50 | Given an array arr[] of distinct positive numbers. Split the array into the minimum number of subsets (or... | [`gfg474.cpp`](./gfg474.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20distinct%20positive%20numbers%20Split) |
| 51 | Given an array arr[], choose any subset of elements (possibly all elements) such that the XOR of the chosen... | [`gfg475.cpp`](./gfg475.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20choose%20any%20subset%20elements) |
| 52 | Given an integer array arr[], count the number of different subsets whose product can be represented as a... | [`gfg476.cpp`](./gfg476.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20array%20arr%20count%20the%20number) |
| 53 | Given three arrays a[], b[], and k[], representing m range increment operations on an array arr[] of size n,... | [`gfg477.cpp`](./gfg477.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20three%20arrays%20and%20representing%20range%20increment) |
| 54 | Given two positive integer n and m. Find the number of arrays of size n that can be formed such that: Each... | [`gfg478.cpp`](./gfg478.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20positive%20integer%20and%20Find%20the) |
| 55 | Given an array arr[] and an integer k, find the maximum sum among all contiguous subarrays having a length... | [`gfg479.cpp`](./gfg479.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20and%20integer%20find%20the) |
| 56 | Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the... | [`gfg481.cpp`](./gfg481.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20array%20arr%20and%20two%20integers) |
| 57 | Given an array arr[]. Initially, you have another array containing only 0s. In one operation, you may either:... | [`gfg482.cpp`](./gfg482.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20Initially%20you%20have%20another) |
| 58 | Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be... | [`gfg483.cpp`](./gfg483.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20friends%20each%20one%20can%20remain%20single) |
| 59 | Given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge... | [`gfg484.cpp`](./gfg484.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20graph%20with%20vertices%20and%20edges%20You) |
| 60 | Given a square matrix mat[][] of size n × n. A zigzag sequence starts from the top and ends at the bottom.... | [`gfg485.cpp`](./gfg485.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20square%20matrix%20mat%20size%20zigzag%20sequence) |
| 61 | Given two integer arrays h[] and l[], where h[i] and l[i] denote the number of tasks that can be completed on... | [`gfg486.cpp`](./gfg486.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integer%20arrays%20and%20where%20and) |
| 62 | Given a binary matrix mat[][] of size n*m and an integer k, process a list of queries queries[][]. Each query... | [`gfg487.cpp`](./gfg487.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20binary%20matrix%20mat%20size%20and%20integer) |
| 63 | Given a maze represented as an n x n grid, grid[][], using 0-based indexing. Each cell contains one of the... | [`gfg488.cpp`](./gfg488.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20maze%20represented%20grid%20grid%20using%20based) |
| 64 | Given a weighted Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1, represented by... | [`gfg489.cpp`](./gfg489.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20weighted%20Directed%20Acyclic%20Graph%20DAG%20with) |
| 65 | There are n children standing in a queue, each assigned a number arr[i]. The teacher writes s on a paper and... | [`gfg490.cpp`](./gfg490.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=There%20are%20children%20standing%20queue%20each%20assigned) |
| 66 | Given a number n, count the numbers from 1 to n that don’t contain digit d in their decimal representation.... | [`gfg491.cpp`](./gfg491.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20number%20count%20the%20numbers%20from%20that) |
| 67 | Given an integer array arr[], find the minimum possible product that can be obtained by multiplying the... | [`gfg492.cpp`](./gfg492.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20array%20arr%20find%20the%20minimum) |
| 68 | Given an integer n such that there is n × n Snakes and Ladders board with cells numbered from 1 to n*n, find... | [`gfg493.cpp`](./gfg493.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20such%20that%20there%20Snakes%20and) |
| 69 | Geek wants to send a secret message to his friend Keeg. Instead of sending the original message directly, he... | [`gfg494.cpp`](./gfg494.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Geek%20wants%20send%20secret%20message%20his%20friend) |
| 70 | Given an array arr[] and a range from l to r, the task is to count the number of triplets having a sum in the... | [`gfg495.cpp`](./gfg495.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20and%20range%20from%20the) |
| 71 | Given the root of a binary tree, find the maximum difference between an ancestor node A and its descendant... | [`gfg496.cpp`](./gfg496.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20the%20root%20binary%20tree%20find%20the) |
| 72 | Given two strings s1 and s2. Find the minimum number of steps required to transform string s1 into string s2.... | [`gfg497.cpp`](./gfg497.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20strings%20and%20Find%20the%20minimum) |
| 73 | Given root of a binary tree and the values of its two nodes p and q, count turns required to travel from node... | [`gfg498.cpp`](./gfg498.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20root%20binary%20tree%20and%20the%20values) |
| 74 | Given a maze mat[][] of size n × m, where each cell is either: '.' representing an empty cell, or '#'... | [`gfg499.cpp`](./gfg499.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20maze%20mat%20size%20where%20each%20cell) |
| 75 | Given an integer n, count the number of binary strings of length 2 * n that contain exactly n ones and n... | [`gfg500.cpp`](./gfg500.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20count%20the%20number%20binary%20strings) |
| 76 | Given a numeric string s containing only digits and an integer n, count the number of non-empty subsequences... | [`gfg505.cpp`](./gfg505.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20numeric%20string%20containing%20only%20digits%20and) |
| 77 | Consider an input where all marks obtained are divided into intervals of consecutive numbers represented as... | [`gfg506.cpp`](./gfg506.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Consider%20input%20where%20all%20marks%20obtained%20are) |
| 78 | Given four integers n, i, d, and c, where: i is the cost of inserting a single character, d is the cost of... | [`gfg507.cpp`](./gfg507.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20four%20integers%20and%20where%20the%20cost) |
| 79 | Given two integers n and k, consider an alphabet consisting of the first k lowercase English letters. Find... | [`gfg508.cpp`](./gfg508.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integers%20and%20consider%20alphabet%20consisting) |
| 80 | A cafe has n computers. The customer events are represented by a string s of uppercase English letters, where... | [`gfg509.cpp`](./gfg509.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=cafe%20has%20computers%20The%20customer%20events%20are) |
| 81 | Given an integer array arr[], you are allowed to replace any elements with 1. Find the maximum sum of... | [`gfg510.cpp`](./gfg510.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20array%20arr%20you%20are%20allowed) |
| 82 | Given an array arr[] representing the fruit values of trees arranged in a circle and an integer m, find the... | [`gfg511.cpp`](./gfg511.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20representing%20the%20fruit%20values) |
| 83 | Given an array arr[] with n elements. find the longest subsequence such that the absolute difference between... | [`gfg512.cpp`](./gfg512.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20with%20elements%20find%20the) |
| 84 | Given an array arr[] of integers, calculate the sum of bitwise AND for all pairs of elements such that the... | [`gfg513.cpp`](./gfg513.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20integers%20calculate%20the%20sum) |
| 85 | Given an array arr[] of size n, partition its elements into a strictly increasing subsequence and a strictly... | [`gfg514.cpp`](./gfg514.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20size%20partition%20its%20elements) |
| 86 | Given a 2D grid mat[][] of size n × m consisting of characters and a string word, find all starting positions... | [`gfg515.cpp`](./gfg515.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20grid%20mat%20size%20consisting%20characters%20and) |
| 87 | Given a number n, find a number in the range from 1 to n such that its digit sum is maximum. If there are... | [`gfg516.cpp`](./gfg516.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20number%20find%20number%20the%20range%20from) |
| 88 | Given two integers x and y representing the GCD and LCM of two unknown positive integers a and b, count the... | [`gfg517.cpp`](./gfg517.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integers%20and%20representing%20the%20GCD) |
| 89 | Given an integer array arr[] representing the nodes of a Complete Binary Tree in level order traversal,... | [`gfg571.cpp`](./gfg571.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20integer%20array%20arr%20representing%20the%20nodes) |
| 90 | Given a string s consisting of n lowercase characters. Return the lexicographically smallest string after... | [`GfgPOTD420.cpp`](./GfgPOTD420.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20string%20consisting%20lowercase%20characters%20Return%20the) |
| 91 | Given two integers n and m representing the dimensions of a chessboard, find the number of ways to place one... | [`gfgpotd421.cpp`](./gfgpotd421.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20two%20integers%20and%20representing%20the%20dimensions) |
| 92 | Consider a special family of Engineers and Doctors with following rules : Everybody has two children. First... | [`gfgpotd422.cpp`](./gfgpotd422.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Consider%20special%20family%20Engineers%20and%20Doctors%20with) |
| 93 | Given a bag of size w kg and you are provided costs of packets different weights of oranges in array cost[],... | [`gfgpotd430.cpp`](./gfgpotd430.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20bag%20size%20and%20you%20are%20provided) |
| 94 | Given an array arr[] of positive integers and an integer k, find the total number of pairs of elements that... | [`gfgpotd480.cpp`](./gfgpotd480.cpp) | [🔍 Find it](https://www.geeksforgeeks.org/?s=Given%20array%20arr%20positive%20integers%20and%20integer) |

</details>

<details>
<summary><strong>🔵 TCS / TCS NQT (29)</strong></summary>

| # | Problem | File |
|---|---|---|
| 1 | An array of size N contains from 0 to N - 1. Exactly one number is repeated and exactly one number is missing... | [`tcs17june.cpp`](./tcs17june.cpp) |
| 2 | you are given the values of the nodes of a binary search tree and an integer K find the Kth smallest element... | [`tcs19.cpp`](./tcs19.cpp) |
| 3 | Given a square matrix of size N * N, calculate its trace. the trace of a matrix is the sum of its principal... | [`tcs21.cpp`](./tcs21.cpp) |
| 4 | Given an integer N, generate the first N terms of a series where: First term = 5 Second term = 6 Every... | [`tcs28.cpp`](./tcs28.cpp) |
| 5 | There are N passengers who need to travel. A car can carry 4 passengers and produce X units of pollution. A... | [`tcs28ju.cpp`](./tcs28ju.cpp) |
| 6 | Create a class that implements a Stack with following method push(value:string) pop() evaluate() the stack... | [`tcs28june.cpp`](./tcs28june.cpp) |
| 7 | K-th Best selling Product Problem Description Amazon is preparing for its annual shopping festival and wants... | [`tcs6jul.cpp`](./tcs6jul.cpp) |
| 8 | Given a Time in 12-hour AM/PM format, convert it to 24 hour military time Note : 12:00 AM on a 12 -hour clock... | [`tcs6july.cpp`](./tcs6july.cpp) |
| 9 | Given a positive integer N, print all of its prime factors in increasing order. if a prime factor occurs... | [`tcs8july.cpp`](./tcs8july.cpp) |
| 10 | Problem: Count Smaller Elements Before Each Target You are given an array a and a target value. For every... | [`tcs9augshift1.cpp`](./tcs9augshift1.cpp) |
| 11 | You are given a sequence of integers as a single line of space separated values. The number of elements is... | [`tcs9augshift1q2.cpp`](./tcs9augshift1q2.cpp) |
| 12 | Hospital system using priority queue Hospital system can do two operation on basis of 2 number 1 and 2, 1 for... | [`tcs9augshift2q2.cpp`](./tcs9augshift2q2.cpp) |
| 13 | Given a sorted array print all the indices of the given target element input: one sorted array and target... | [`tcs9jul.cpp`](./tcs9jul.cpp) |
| 14 | Problem Statement: Given an array prices where prices[i] is the price of a stock on day i, find the maximum... | [`tcsbuysell.cpp`](./tcsbuysell.cpp) |
| 15 | Problem Statement: Given an array of N integers (which may include negative numbers), find and print the... | [`tcskadane's.cpp`](./tcskadane%27s.cpp) |
| 16 | Problem Statement: Given an array of N integers (which may include negative numbers and zeros), find and... | [`tcsmaxproduct.cpp`](./tcsmaxproduct.cpp) |
| 17 | You are given a number N, and your task is to determine whether it is a "Good Number" or not. A Good Number... | [`tcsmockp1q1.cpp`](./tcsmockp1q1.cpp) |
| 18 | You are given two strings, str1 and str2. Your mission is to calculate the total number of occurrences of... | [`tcsmockp1q2.cpp`](./tcsmockp1q2.cpp) |
| 19 | You are given an array of integers of size $N$ and a target integer $T$. An "adjacent pair" is formed by any... | [`tcsnqt16july.cpp`](./tcsnqt16july.cpp) |
| 20 | Two integres N and S are given. starting from S, find prime numbers and count them until the Nth prime is... | [`tcsnqt17june.cpp`](./tcsnqt17june.cpp) |
| 21 | A historical department has developed a special roman numerical encoding system, in this system: Every 1000... | [`tcsnqt19jul.cpp`](./tcsnqt19jul.cpp) |
| 22 | Given two linked list, merge them by selecting elements alternatively from each list. Rules: Merge nodes... | [`tcsnqt21.cpp`](./tcsnqt21.cpp) |
| 23 | See file for full problem statement | [`tcsnqt21july.cpp`](./tcsnqt21july.cpp) |
| 24 | There are two items A and B with their respective prices. write a program to determine which is more... | [`tcsnqt28june.cpp`](./tcsnqt28june.cpp) |
| 25 | Given an integer N, print the first N fibonacci series. the fibonacci series starts with: 0 1 1 2 3 5 8... | [`tcsnqt6jul.cpp`](./tcsnqt6jul.cpp) |
| 26 | Given a sorted array of integers and a key, perform Binary Search. If the key is found, print the key.... | [`tcsnqt8jul.cpp`](./tcsnqt8jul.cpp) |
| 27 | A common coding interview problem is : Given two integers L and R, compute: where the integer binaary... | [`tcss.cpp`](./tcss.cpp) |
| 28 | given an array, sort it in ascending order. for each elelemnt, find the absolute difference between its... | [`tcsss.cpp`](./tcsss.cpp) |
| 29 | you are given two binary numbers as strings, your task is to compute their sum and print the resulting binary... | [`tcssss.cpp`](./tcssss.cpp) |

</details>

<details>
<summary><strong>🟣 NQT (General Practice) (11)</strong></summary>

| # | Problem | File |
|---|---|---|
| 1 | Given an array of integers, replace each element with its position (rank) in the sorted list of unique... | [`nqt19.cpp`](./nqt19.cpp) |
| 2 | Write a program to perform the following operations on a stack. 1. Read an integer n, representing the number... | [`nqt21.cpp`](./nqt21.cpp) |
| 3 | Given an array heights[] where each element represents the height of a histogram bar and the width of every... | [`nqt28ju.cpp`](./nqt28ju.cpp) |
| 4 | Given a string S, print the frequency of each distinct character in the order of its first occurrence. Input... | [`nqt28jun.cpp`](./nqt28jun.cpp) |
| 5 | Given the head of a singly linked list, sort the linked list using the Quick Sort algorithm. Input Format:... | [`nqt8jul.cpp`](./nqt8jul.cpp) |
| 6 | Given an array return the first unique element using Hashmap Input- Array with Exactly one element occuring... | [`nqt9jul.cpp`](./nqt9jul.cpp) |
| 7 | Find the smallest element in an array 9 Problem Statement: Given an array, we have to find the smallest... | [`nqtsheet1.cpp`](./nqtsheet1.cpp) |
| 8 | Find the Largest element in an array 95 Problem Statement: Given an array, we have to find the largest... | [`nqtsheet2.cpp`](./nqtsheet2.cpp) |
| 9 | Find Second Smallest and Second Largest Element in an array 43 Problem Statement: Given an array, find the... | [`nqtsheet3.cpp`](./nqtsheet3.cpp) |
| 10 | Reverse a given Array 14 Problem Statement: You are given an array. The task is to reverse the array and... | [`nqtsheet4.cpp`](./nqtsheet4.cpp) |
| 11 | Count frequency of each element in the array 24 Problem Statement: Given an array, we have found the number... | [`nqtsheet5.cpp`](./nqtsheet5.cpp) |

</details>

<details>
<summary><strong>🟡 Infosys (3)</strong></summary>

| # | Problem | File |
|---|---|---|
| 1 | You are given a string S. split the string into the minimum number of contigious substrings such that every... | [`infosys17july.cpp`](./infosys17july.cpp) |
| 2 | Andy wants to go on a vacation to de-stress himself. He can take only one continous vacation. during the next... | [`infosyspyq.cpp`](./infosyspyq.cpp) |
| 3 | There are N houses arranged in a straight line.Each house must be painted using one of C available colors The... | [`infosysq2.cpp`](./infosysq2.cpp) |

</details>

<details>
<summary><strong>⚪ Miscellaneous DSA Practice (24)</strong></summary>

| # | Problem | File |
|---|---|---|
| 1 | See file for full problem statement | [`bubblesortrecursive.cpp`](./bubblesortrecursive.cpp) |
| 2 | warehouse arrangement problem in a warehouse, boxes are palced in a row and each box has a number printed on... | [`campusmonkmock1.cpp`](./campusmonkmock1.cpp) |
| 3 | check if string is decomposable into value equal substring A value -equal string is a string where all... | [`campusmonkmockp1q2.cpp`](./campusmonkmockp1q2.cpp) |
| 4 | . Maximum consecutive one’s (or zeros) in a binary array Given a binary array arr[] consisting of only 0s and... | [`cnt0's_and1s.cpp`](./cnt0%27s_and1s.cpp) |
| 5 | Given a string str, Find the number of distinct subsequences that can be formed from it. A subsequence is a... | [`cnt_distinct_subsequence.cpp`](./cnt_distinct_subsequence.cpp) |
| 6 | Problem: Treasure Hunt in the Magical Kingdom A king has created a treasure map represented by an N × M grid.... | [`collegenqt1.cpp`](./collegenqt1.cpp) |
| 7 | Joseph is learning digital logic subject which will be for his next semester. He usually tries to solve unit... | [`DecimaltoBinary.cpp`](./DecimaltoBinary.cpp) |
| 8 | See file for full problem statement | [`heapsort.cpp`](./heapsort.cpp) |
| 9 | Given two integers N (number of cakes) and M (number of people), determine the minimum number of cuts... | [`idfc1.cpp`](./idfc1.cpp) |
| 10 | 2. Smallest Concatenated Adjacent Number Given an array of positive integers, concatenate every pair of... | [`idfc2.cpp`](./idfc2.cpp) |
| 11 | You are thr student ID and corresponding score of N students. you are also given: X-> score to check K ->... | [`last_student_score _freq.cpp`](./last_student_score%20_freq.cpp) |
| 12 | You are given an array of integers, arr, and an integer k. Your task is to find and print the maximum number... | [`maximum_element.cpp`](./maximum_element.cpp) |
| 13 | Given an array arr[] of non-negative integers, where each element represents the maximum number of steps you... | [`minimum_jump_to_reach_end.cpp`](./minimum_jump_to_reach_end.cpp) |
| 14 | A chocolate factory is packing chocolates into the packets. The chocolate packets here represent an array of... | [`move_zerostoEndTCS.cpp`](./move_zerostoEndTCS.cpp) |
| 15 | 1. Given an array Arr[] of N integers and a positive integer K, cyclically rotate the array clockwise by K.... | [`ques1.cpp`](./ques1.cpp) |
| 16 | 2. Given two non-negative integers n1 and n2, count how many numbers in the range [n1, n2] do not have... | [`ques2.cpp`](./ques2.cpp) |
| 17 | 3. Given a string, split it into exactly 3 palindromic substrings. If it's not possible, print "Impossible".... | [`ques3.cpp`](./ques3.cpp) |
| 18 | . Jack is always excited about sunday. It is favourite day, when he gets to play all day. And goes to cycling... | [`ques4.cpp`](./ques4.cpp) |
| 19 | See file for full problem statement | [`quicksort.cpp`](./quicksort.cpp) |
| 20 | Medium level question: Selection sort performing for p no of pass Input: n= 5(size of array) p = 3(no of... | [`selectionsort.cpp`](./selectionsort.cpp) |
| 21 | 6. Stickler Thief Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot... | [`sticklerTheif.cpp`](./sticklerTheif.cpp) |
| 22 | 1. Stock Buy and Sell - Max one Transaction Allowed Given an array prices[] of non-negative integers,... | [`stockbuy_and_sell.cpp`](./stockbuy_and_sell.cpp) |
| 23 | Given the following inputs for an arithemetic Progression (AP): a = First Term d = common difference n = term... | [`tcaap_gp.cpp`](./tcaap_gp.cpp) |
| 24 | Given an array of match scores and an integer K, find the scores with the highest frequencies. print the... | [`top_k_frequent.cpp`](./top_k_frequent.cpp) |

</details>

## 🧠 Topics Covered

<div align="center">

`Arrays` `Strings` `Two Pointers` `Sliding Window` `Hashing` `Sorting` `Binary Search`
`Heaps / Priority Queues` `Dynamic Programming` `Greedy` `Graphs` `Trees` `Linked Lists`
`Bit Manipulation` `Stacks & Queues` `Recursion & Backtracking` `Matrices`

</div>

## 🎯 Purpose

- ✅ Revise problem-solving patterns before interviews
- ✅ Track daily/weekly DSA practice (dated files act as a timeline)
- ✅ Build company-specific muscle memory for **TCS NQT** and **Infosys** test patterns
- ✅ Maintain a searchable, personal archive of solved LeetCode & GFG problems
- ✅ Give newcomers a clear, guided way to browse solved problems by platform and topic

## 🤝 Contributing

This is primarily a personal prep log, but if you spot a bug, a more optimal approach, or want to suggest an improvement — issues and pull requests are welcome!

1. Fork the repo
2. Create a branch (`git checkout -b improve/leetcode215`)
3. Commit your changes
4. Open a pull request

## 📄 License

No license has been specified yet for this repository. All rights reserved by default unless stated otherwise by the author.

## 👤 Author

<div align="center">

**Coderamrish**

[![GitHub](https://img.shields.io/badge/GitHub-Coderamrish-181717?style=for-the-badge&logo=github)](https://github.com/Coderamrish)

⭐ **If this helped your placement prep, consider starring the repo!** ⭐

</div>
