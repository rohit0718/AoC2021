from sys import stdin
from collections import defaultdict
hex_input = stdin.readlines()[0].strip()

idx = 0
res = 0
input_len = len(hex_input) * 4
bin_input = bin(int(hex_input,16))[2:].zfill(input_len)

def is_literal(bin_input):
    return int(bin_input, 2) == 4

def read_sub_packets(idx):
    while bin_input[idx] != '0':
        idx += 5
    return idx + 5

def parse_packet(idx):
    global res

    ver, typ = bin_input[idx:idx+3], bin_input[idx+3:idx+6]
    res += int(ver, 2)
    idx += 6

    if is_literal(typ):
        return read_sub_packets(idx)

    len_id = bin_input[idx]
    idx += 1
    if len_id == '0':
        tot_len = int(bin_input[idx:idx+15], 2)
        idx += 15
        new_idx = idx
        while new_idx - idx != tot_len:
            new_idx = parse_packet(new_idx)
        return new_idx
    # num sub packets
    num_pkts = int(bin_input[idx:idx+11], 2)
    idx += 11
    for i in range(num_pkts):
        idx = parse_packet(idx)
    return idx

parse_packet(0)
print(res)

