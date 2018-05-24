from math import sqrt, ceil

#  read the discription again if get stuck again

def get_range(piles, limit):
    min = piles
    max = piles * (piles+1) // 2
    if piles > limit:
        overflow = piles - limit
        if overflow % 2 == 1:
            max -= (overflow//2+1)**2
        else:
            max -= (overflow//2)*(overflow//2+1)
    return min, max


def main():
    n, h = map(int, input().strip().split())

    if n == 1:
        print(1)
        return

    l, r = 0, n
    while l != r:
        mid = int((l+r)//2)
        min, max = get_range(mid, h)
        # print(mid, ":", min, max)

        if min <= n <= max:
            r = mid
        else:
            l = mid+1
    print(r)

if __name__ == '__main__':
    main()
