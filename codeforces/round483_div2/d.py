def f(arr):
    return [a ^ b for a, b in zip(arr[:-1], arr[1:])]

arr = [1, 2, 4, 8, 16, 32, 64]  # , 128]
while len(arr) > 0:
    print([bin(x) for x in arr])
    arr = f(arr)
