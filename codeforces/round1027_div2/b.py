import math

n, q = map(int, input().split(' '))
odd = n%2
half = math.ceil(n**2/2)

for _ in range(q):
    i, j = map(int, input().split(' '))

    count = 1
    if (i+j)%2 == 0:
        count += \
            (i-1)//2*(n//2*2+odd)+\
            ((n//2+odd) if i % 2 == 0 else 0)
        count += (j-1)//2;
    else:
        count += \
            (i-1)//2*(n//2*2+odd)+\
            (n//2 if i%2==0 else 0)
        count += (j-1)//2;
        count += half;
    print(count)

