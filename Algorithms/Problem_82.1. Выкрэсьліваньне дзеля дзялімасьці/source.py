w = int(input())
h = [int(i) for i in input().split(' ')]
if w == 1: print(0)
else:
    v = [0] * w
    v[0] = 1
    for i in range(1, w):
        for j in range(i):
            # if h[i] / h[j] == int(h[i] / h[j]):
            if h[j] and h[i] % h[j] == 0:
                if v[i] < v[j]: v[i] = v[j]
        v[i] += 1
    print(w - max(v))
