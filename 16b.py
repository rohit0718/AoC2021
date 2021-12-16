from sys import stdin
from collections import defaultdict
from operator import mul
from functools import reduce

idx = 0
hex_input = stdin.readlines()[0].strip()
input_len = len(hex_input) * 4
bin_input = bin(int(hex_input,16))[2:].zfill(input_len)

def sum_pkts(*args):
    return sum(args)

def pdt_pkts(*args):
    return reduce(mul, args)

def min_pkts(*args):
    return min(args)

def max_pkts(*args):
    return max(args)

def idt_pkts(*args):
    return args[0]

def grt_pkts(*args):
    return int(args[0] > args[1])

def lst_pkts(*args):
    return int(args[0] < args[1])

def eql_pkts(*args):
    return int(args[0] == args[1])

commands = {
    0: sum_pkts,
    1: pdt_pkts,
    2: min_pkts,
    3: max_pkts,
    4: idt_pkts,
    5: grt_pkts,
    6: lst_pkts,
    7: eql_pkts
}

def is_literal(inp) -> bool:
    return inp == 4

# (idx, num)
def read_sub_packets(idx) -> (int, int):
    num = ""
    while bin_input[idx] != '0':
        num += bin_input[idx+1:idx+5]
        idx += 5
    return (idx + 5, int(num+bin_input[idx+1:idx+5],2))

# (idx, num)
def parse_packet(idx) -> (int, int):
    ver, typ = int(bin_input[idx:idx+3], 2), int(bin_input[idx+3:idx+6], 2)
    idx += 6

    if is_literal(typ):
        return read_sub_packets(idx)

    len_id = bin_input[idx]
    idx += 1
    if len_id == '0':
        tot_len = int(bin_input[idx:idx+15], 2)
        idx += 15
        new_idx = idx
        subpkt_nums = []
        while new_idx - idx != tot_len:
            new_idx, num = parse_packet(new_idx)
            subpkt_nums.append(num)
        return (new_idx, commands[typ](*subpkt_nums))
    # num sub packets
    num_pkts = int(bin_input[idx:idx+11], 2)
    idx += 11
    subpkt_nums = []
    for i in range(num_pkts):
        idx, num = parse_packet(idx)
        subpkt_nums.append(num)
    return (idx, commands[typ](*subpkt_nums))

print(parse_packet(0))

