line = input()
n, m = line.split(" ")
n = int(n)
m = int(m)
line = input()
edges = []
for _ in range(m):
    line = input()
    u, v, w = line.split(" ")[0:3]
    u = int(u)
    v = int(v)
    w = int(w)
    edges.append((u, v, w))
edges.sort(key=lambda x: x[2])

id = [x for x in range(n + 1)]
sz = [1 for _ in range(n + 1)]


def find(u):
    if u == id[u]:
        return u
    id[u] = find(id[u])
    return id[u]


def uni(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return
    if sz[u] > sz[v]:
        u, v = v, u
    sz[u] += sz[v]
    id[v] = u


ans = 0
for edg in edges:
    if find(edg[0]) == find(edg[1]):
        continue
    ans += edg[2]
    uni(edg[0], edg[1])

print(ans * 2)
