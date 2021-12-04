
def check(board):
    for row in board:
        if sum([x[1] for x in row]) == len(row):
            return True
    for col in range(len(board[0])):
        cur = 0
        for row in board:
            if row[col][1] == 1:
                cur += 1
        if cur == len(board):
            return True

def mark(board, num):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j][0] == num:
                board[i][j] = (board[i][j][0], 1)

def solve(board, num):
    tmp = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j][1] == 0:
                tmp += int(board[i][j][0])
    return tmp * int(num)

boards = []
from sys import stdin
nums = stdin.readline()[:-1].split(',')

board = []
for line in stdin:
    cur_row = [(x,0) for x in line.strip().split(' ') if x]
    if cur_row:
        board.append(cur_row)
    if len(board) == 5:
        boards.append(board)
        board = []

seen = {}
for num in nums:
    for i in range(len(boards)):
        mark(boards[i], num)
        if check(boards[i]) and i not in seen:
            print(solve(boards[i], num))
            seen[i] = 1

