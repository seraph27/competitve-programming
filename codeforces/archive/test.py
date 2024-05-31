n, m = map(int, input().split())
g = []
for i in range(m): 
    g.append(tuple(map(int, input().split())))

# create adjacency list
adj_list = {}
for x, y, w in g: 
    # print(x, y, w)
    if x in adj_list: 
        adj_list[x].append((y,w))
    else: 
        adj_list[x] = [(y,w)]
    
    if y in adj_list: 
        adj_list[y].append((x,w))
    else: 
        adj_list[y] = [(x,w)]

d = [float('inf')] * (n+1) # distance list
p = [-1] * (n+1) # predecessor list
visited = [False] * (n+1) # marked/explored list
pq = [] # priority queue
pq.append((1, 0))
count = 0

d[1] = 0
while pq:
    count += 1
    if count > n: 
        break 
    #print(pq)
    # print(p)
    v, curr_d = pq.pop()
    if visited[v]:
        continue 

    # add appropriate neighbours to pq
    try:
        adj_list[v]
    except KeyError:
        print(-1)
        exit()

    for neigh, w in adj_list[v]:
        dist = curr_d + w
        # print(curr_d, adj_mat[v][j], v, j, dist)
        if (dist < d[neigh]): 
            # print(f"Curr = ({v},{curr_d}), Adding...({j},{dist})")
            p[neigh] = v
            d[neigh] = dist
            pq.append((neigh, dist))
            pq.sort(reverse=True, key=lambda x : x[1])
    
    visited[v] = True

# iterate backwards through predecessor list to recreate path
path = [n]
i = n 
while p[i] != -1: 
    path.append(p[i])
    i = p[i]

# print("Predecessors: ", p)
# print("Path: ", path)
if path[-1] != 1: 
    print(-1)
    exit()
else: 
    for vertex in reversed(path):
        print(vertex, end = " ")