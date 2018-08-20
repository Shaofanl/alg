def selectionSort(arr):
    n = len(arr)
    if n == 0: return arr

    for i in range(n-1, 0, -1):  # the index in sorted part
        maxj = 0
        for j in range(i+1):
            if arr[j] > arr[maxj]:
                maxj = j
        arr[maxj], arr[i] = arr[i], arr[maxj]

    return arr


import numpy as np
def test():
    for _ in range(1000):
        arr = np.random.randint(100, size=(100,))
        arr = np.array(selectionSort(arr))
        print(arr)
        assert np.all(arr[:-1] <= arr[1:])

test()
