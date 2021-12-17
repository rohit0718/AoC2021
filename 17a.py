from sys import stdin
from collections import defaultdict
from operator import mul
from functools import reduce
lines = stdin.readlines()

x1, x2, y1, y2 = [int(x) for x in lines[0].strip().split()]

max_y = 0
for vel_x in range(1000):
    for vel_y in range(1000, -1000, -1):
        cur_vel_x, cur_vel_y = vel_x, vel_y
        cur_x, cur_y = 0, 0
        can = False
        y_vals = []
        while cur_x <= x2 and cur_y >= y1:
            y_vals.append(cur_y)
            if x1 <= cur_x <= x2 and y1 <= cur_y <= y2:
                can = True
                break
            cur_x, cur_y = cur_x + cur_vel_x, cur_y + cur_vel_y
            cur_vel_y -= 1
            if cur_vel_x > 0:
                cur_vel_x -= 1
            elif cur_vel_x < 0:
                cur_vel_x += 1
        if can:
            max_y = max(max_y, max(y_vals))

print(max_y)

