from sys import stdin
from collections import defaultdict
lines = stdin.readlines()

def is_small(cave):
    return cave[0].islower()

def has_visited_twice(seen):
    seen_small_caves = { cave: seen[cave] for cave in seen if is_small(cave) }
    return any(seen[cave] > 1 for cave in seen_small_caves)

def count_paths(start, end, adj, seen):
    if start == end:
        return 1
    seen[start] += 1
    res = 0
    for neigh in [v for v in adj[start] if v != 'start']:
        if has_visited_twice(seen) and is_small(neigh) and seen[neigh] > 0:
            continue
        res += count_paths(neigh, end, adj, seen)
    seen[start] -= 1
    return res

adj = defaultdict(list)
seen = defaultdict(int)
for line in lines:
    u, v = line.strip().split('-')
    adj[u].append(v)
    adj[v].append(u)

print(count_paths('start', 'end', adj, seen))

