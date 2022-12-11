#!/usr/bin/python3

def compute(p):
    if len(p)==0:
        print(0)
        return
    mx = p[0]
    dp = [p[0]]
    for i in range(1,len(p)):
        dp.append(dp[i-1]*p[i])
    for i in range(len(p)):
        for j in range(i):
            if dp[j]==0:
                continue
            x = dp[i]/dp[j]
            mx = max(mx,x)

    print(int(mx))

p = []
while True:
  try:
    text = input()
    nums = text.split(" ")
    for x in nums:
        x = int(x)
        if x==-999999:
            compute(p)
            p = []
            continue
        p.append(x)

  except EOFError:
    break
