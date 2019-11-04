from collections import defaultdict
n, m, d = map(int, input().split())
cs = list(map(int, input().split()))
 
dist = 0
for c in cs:
    dist += (d + c - 1)
dist += d
if dist < n:
    print("NO")
else:
    answer = []
    jumps = n - sum(cs)
    for ind, c in enumerate(cs):
        count_zero = d - 1
        jump = min(jumps, d - 1)
        jumps -= jump
        answer.extend([0] * jump)
        answer.extend([ind + 1] * c)
    if jumps:
        answer.extend([0] * jump)
    print("YES")
    print(" ".join(map(str, answer)))