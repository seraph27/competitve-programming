import random
import sys

n = int(sys.argv[1]) if len(sys.argv) > 1 else 8000

# Generate a random tree
parent = [0] * n
children = [[] for _ in range(n)]
for i in range(1, n):
    parent[i] = random.randint(0, i - 1)
    children[parent[i]].append(i)

# Compute reachability: node i can reach all nodes in its subtree
reach = [set() for _ in range(n)]

# BFS/DFS from each node to find subtree
# More efficient: compute subtrees bottom-up
order = []
visited = [False] * n
stack = [(0, False)]
# Topological order via DFS
def dfs_order(root):
    stack = [(root, False)]
    while stack:
        node, processed = stack.pop()
        if processed:
            order.append(node)
            continue
        stack.append((node, True))
        for c in children[node]:
            stack.append((c, False))

dfs_order(0)

# Bottom-up: each node's reachable set = {self} ∪ union of children's reachable sets
# Use bitsets (as Python ints)
reach_bits = [0] * n
for node in order:
    reach_bits[node] = 1 << node
    for c in children[node]:
        reach_bits[node] |= reach_bits[c]

# Output
print(1)
print(n)
for i in range(n):
    row = ''
    for j in range(n):
        row += '1' if (reach_bits[i] >> j) & 1 else '0'
    print(row)
