def LIS_l(s, arr):

    l = 1
    t = [0 for i in range(s + 1)]
    t[0] = arr[0]

    for i in range(1, s):

        if (arr[i] < t[0]): t[0] = arr[i]
        elif (t[l-1] < arr[i]):
            t[l] = arr[i]
            l = l + 1
        else: t[indextn(t, -1, l-1, arr[i])] = arr[i]

    return l

def indextn(arr, l, r, key):

    while (1 < r - l):
        mdm = l + (r - l)//2
        if (key <= arr[mdm]): r = mdm
        else: l = mdm
    return r

with open('input.txt') as f:
    w = [int(x) for x in next(f).split()]
    h = [int(x) for x in next(f).split()]
    answer = LIS_l(w[0], h)
    z = open("output.txt","w")
    z.write(str(answer))
    z.close()
    f.close()
