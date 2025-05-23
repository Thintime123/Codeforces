t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        curr_num = a[i]
        distinct_nums = set()
        distinct_nums.add(curr_num)
        count = 1
        for j in range(i + 1, n):
            if a[j] in distinct_nums or a[j] == curr_num + 1:
                if a[j] not in distinct_nums:
                    distinct_nums.add(a[j])
                curr_num = a[j]
                count += 1
                if len(distinct_nums) > k:
                    break
        ans = max(ans, count)
    print(ans)
