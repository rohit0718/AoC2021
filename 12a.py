from sys import stdin
from collections import defaultdict
lines = stdin.readlines()

def is_small(cave):
    return cave[0].islower()

def count_paths(start, end, adj, seen):
    if start == end:
        return 1
    seen[start] = True
    res = 0
    for neigh in adj[start]:
        if is_small(neigh) and seen[neigh]:
            continue
        res += count_paths(neigh, end, adj, seen)
    seen[start] = False
    return res

adj = defaultdict(list)
seen = defaultdict(bool)
for line in lines:
    u, v = line.strip().split('-')
    adj[u].append(v)
    adj[v].append(u)

print(count_paths('start', 'end', adj, seen))

