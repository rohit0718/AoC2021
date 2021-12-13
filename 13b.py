from sys import stdin
from collections import defaultdict
lines = stdin.readlines()

max_x, max_y = 0, 0

def fold_x(points, fold_point):
    global max_x

    new_points = defaultdict(bool)
    for y in range(max_y + 1):
        for x in range(max_x + 1):
            if x == fold_point:
                continue
            if x < fold_point:
                new_points[(x,y)] = points[(x,y)]
                continue
            dis_centre = x - fold_point
            if new_points[(fold_point - dis_centre,y)]:
                continue
            new_points[(fold_point - dis_centre,y)] = points[(x,y)]
    max_x //= 2
    return new_points

def fold_y(points, fold_point):
    global max_y

    new_points = defaultdict(bool)
    for y in range(max_y + 1):
        for x in range(max_x + 1):
            if y == fold_point:
                continue
            if y < fold_point:
                new_points[(x,y)] = points[(x,y)]
                continue
            dis_centre = y - fold_point
            if new_points[(x,fold_point - dis_centre)]:
                continue
            new_points[(x,fold_point - dis_centre)] = points[(x,y)]
    max_y //= 2
    return new_points

points = defaultdict(bool)
for line in [x.strip() for x in lines if ',' in x]:
    x, y = line.split(',')
    max_x = max(max_x, int(x))
    max_y = max(max_y, int(y))
    points[(int(x), int(y))] = True

for line in [x.strip() for x in lines if '=' in x]:
    a, b, c = line.split()
    pos, val = c.split('=')
    if pos == 'x':
        points = fold_x(points, int(val))
    else:
        points = fold_y(points, int(val))

for y in range(max_y + 1):
    for x in range(max_x + 1):
        if points[(x,y)]:
            print("#", end="")
        else:
            print(".", end="")
    print()

