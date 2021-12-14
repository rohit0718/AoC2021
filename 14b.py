from sys import stdin
from collections import defaultdict
import string
lines = stdin.readlines()

rules = defaultdict(str)
for line in [x.strip() for x in lines if "->" in x]:
    u, v = line.split(" -> ")
    rules[u] = v

polymer = lines[0].strip()
counts = defaultdict(int)
freq = defaultdict(int, { c: polymer.count(c) for c in polymer })
for j in range(len(polymer) - 1):
    counts[polymer[j:j+2]] += 1

STEPS = 40
for i in range(STEPS):
    new_counts = defaultdict(int)
    for pair, val in counts.items():
        if rules[pair]:
            freq[rules[pair]] += val
            new_counts[pair[0] + rules[pair]] += val
            new_counts[rules[pair] + pair[1]] += val
        else:
            new_counts[pair] = val
    counts = new_counts.copy()

max_count, min_count = 0, 10**30
for key, val in freq.items():
    max_count = max(max_count, val)
    min_count = min(min_count, val)
print(max_count - min_count)

