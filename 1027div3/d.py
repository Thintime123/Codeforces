def check(arr):
    mxx=mxy=0
    mnx=mny=int(1e9)
    for a,b in arr:
        mxx=max(mxx,a)
        mxy=max(mxy,b)
        mnx=min(mnx,a)
        mny=min(mny,b)
    x=(mxy-mny+1)
    y=(mxx-mnx+1)
    return x*y if x*y>len(arr) else x*y+min(x,y)

for _ in range(int(input())):
    n=int(input())
    arr=[[*map(int,input().split())] for i in range(n)]
    if n==1:
        print(1)
        continue
    ans=float("inf")
    arr.sort()
    ans=min(ans,check(arr[1:]),check(arr[:-1]))
    arr.sort(key=lambda x:(x[1],x[0]))
    ans=min(ans,check(arr[1:]),check(arr[:-1]))
    print(ans)