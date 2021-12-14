from sys import stdin
from collections import defaultdict
lines = stdin.readlines()

rules = defaultdict(str)
for line in [x.strip() for x in lines if "->" in x]:
    u, v = line.split(" -> ")
    rules[u] = v

polymer = lines[0].strip()
STEPS = 40
for i in range(STEPS):
    print(i)
    new_polymer = ""
    for j in range(len(polymer) - 1):
        new_polymer += polymer[j] + rules[polymer[j:j+2]]
    polymer = new_polymer + polymer[-1]

max_char = max(set(polymer), key=polymer.count)
min_char = min(set(polymer),key=polymer.count)
print(polymer.count(max_char) - polymer.count(min_char))

