def lastOccurrence(arr, tar):
    if len(arr) == 0:
        return -1

    l, r = 0, len(arr)-1
    while l < r - 1:  # exit with l+1=r or l==r
        mid = (l+r)//2
        if arr[mid] <= tar:
            l = mid
        else:
            r = mid

    if arr[r] == tar:
        return r
    elif arr[l] == tar:
        return l
    return -1

import numpy as np

def test(f, nb_tests=100, arr_size=10, max_ele=100):
    for _ in range(nb_tests):
        arr = list(sorted(np.random.randint(max_ele, size=(arr_size,))))
        tar = np.random.randint(max_ele) if np.random.rand() < 0.5 else np.random.choice(arr)
        try:
            answer = arr_size-arr[::-1].index(tar)-1
        except:
            answer = -1

        print(arr, tar, answer)
        assert f(arr, tar) == answer

if __name__ == '__main__':
    test(lastOccurrence)


