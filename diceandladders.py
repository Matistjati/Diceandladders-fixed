from decimal import *
getcontext().prec = 100
r,c,k=[int(i) for i in input().split()]
ansp = Decimal(input())

n = r*c
p = [[Decimal(0) for i in range(n)] for j in range(n)]
ladder = [i for i in range(n)]
for i in range(k):
    a,b=[int(i) for i in input().split()]
    a-=1
    b-=1
    ladder[a]=b

for i in range(n):
    cnt = 0
    for j in range(i+1,i+7):
        if j>=n:
            break
        p[i][ladder[j]] += Decimal(1)/Decimal(6)

    for j in range(i+1, i+7):
        if j<n:
            cnt+=1

    p[i][-1] += (Decimal(6)-Decimal(cnt))/Decimal(6)
    


def multiply(a, b):
    res = [[Decimal(0) for i in range(len(b[0]))] for j in range(len(a))]
    for i in range(len(res)):
        for j in range(len(res[0])):
            for k in range(len(b)):
                res[i][j] += a[i][k]*b[k][j]
    return res

def prob(m, pos, mat):
    while m:
        if m%2==1:
            pos = multiply(pos,mat)
        m>>=1
        mat=multiply(mat,mat)
    return pos[0][-1]

lo = 0
hi = int(1e9)
pos = [[Decimal(0) for i in range(n)]]
pos[0][0] = Decimal(1)

while hi-lo>1:
    mid = (hi+lo)//2
    if prob(mid, pos, p) >= ansp:
        hi = mid
    else:
        lo = mid
print(hi)


