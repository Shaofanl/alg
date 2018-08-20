import numpy as np

def qs(arr):
    if len(arr) <= 1:
        return arr

    l, r = 0, len(arr)-1
    pivot = arr[(l+r)//2]

    while l <= r:
        while l < r and arr[l] <= pivot: l += 1
        while l < r and arr[r] >= pivot: r -= 1
        if l <= r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1
    return qs(arr[:r+1])+qs(arr[l:])

def test(a):
    a = np.array(a)
    return np.all(a[:-1]<=a[1:])

if __name__ == '__main__':
    for i in range(1000):
        arr = np.random.randint(100, size=(1000,))
        if not test(qs(arr)):
            print(arr)
            print(qs(arr))
            raise Exception
