from sys import stdin

def check_row(row):
    return sum([x[1] for x in row]) == len(row)

def check(board):
    for row in board:
        if (check_row(row)):
            return True
    for i in range(len(board[0])):
        col = [row[i] for row in board]
        if (check_row(col)):
            return True
    return False

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

nums = stdin.readline().strip().split(',')
boards, board = [], []
for line in stdin:
    cur_row = [(x,0) for x in line.strip().split(' ') if x]
    if cur_row:
        board.append(cur_row)
    if len(board) == 5:
        boards.append(board)
        board = []

seen = {}
res = None
for num in nums:
    for i in range(len(boards)):
        mark(boards[i], num)
        if check(boards[i]) and i not in seen:
            seen[i] = True
            res = solve(boards[i], num)

print(res)

