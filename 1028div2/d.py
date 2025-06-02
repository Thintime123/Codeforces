import sys
from collections import deque

def main():
    input = sys.stdin.readline
    t = int(input())
    for _ in range(t):
        n, q = map(int, input().split())
        b = [0] + list(map(int, input().split()))
        ops = []
        last = {}           
        for i in range(1, q+1):
            x, y, z = map(int, input().split())
            ops.append((x, y, z))
            last[z] = i

        
        adj = [[] for _ in range(n+1)]
        for idx, (x, y, z) in enumerate(ops, start=1):
            if last[z] == idx:
                adj[z].append(x)
                adj[z].append(y)

        
        lower = [0] * (n+1)
        vis   = [False] * (n+1)
        dq = deque()
        for z in last:
            vis[z] = True
            dq.append(z)

        while dq:
            u = dq.popleft()
            bu = b[u]
            for v in adj[u]:
                if lower[v] < bu:
                    lower[v] = bu
                if not vis[v]:
                    vis[v] = True
                    dq.append(v)

        
        a = [0] * (n+1)
        bad = False
        kept = set(last.keys())
        for i in range(1, n+1):
            if i not in kept:
                
                if lower[i] > b[i]:
                    bad = True
                    break
                a[i] = b[i]
            else:
                
                a[i] = lower[i]

        if bad:
            print(-1)
            continue

        
        c = a[:]   
        for x, y, z in ops:
            c[z] = min(c[x], c[y])
        for i in range(1, n+1):
            if c[i] != b[i]:
                bad = True
                break

        if bad:
            print(-1)
        else:
            print(" ".join(str(a[i]) for i in range(1, n+1)))

if __name__ == "__main__":
    main()