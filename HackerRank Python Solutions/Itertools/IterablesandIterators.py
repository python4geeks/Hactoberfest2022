
from itertools import combinations
n = int(input())
ar = input().split()
k = int(input())
comb_list = list(combinations(ar,k))
a_list = [e for e in comb_list if 'a' in e]
print(len(a_list) / len(comb_list))
