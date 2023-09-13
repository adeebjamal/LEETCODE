import sys
sys.set_int_max_str_digits(10000*10000)

def solve(t1,t2,n):
    dp = []
    dp.extend([t1,t2])
    for itr in range(2,n):
        dp.append(dp[-1]**2 + dp[-2])
    return dp[-1]

t1, t2, n = map(int,input().split())
print(solve(t1,t2,n))