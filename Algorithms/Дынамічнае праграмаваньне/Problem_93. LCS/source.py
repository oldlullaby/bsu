import numpy as np
def lcs_problem(a, b):

    len_1 = b.shape[0]
    len_2 = a.shape[0]

    tmp = np.zeros(shape=(len_1 + 1, len_2 + 1), dtype=int)

    for i in range(len_1 + 1):
        for j in range(len_2 + 1):
            if i == 0 or j == 0: tmp[i][j] = 0
            elif a[i-1] == b[j-1]: tmp[i][j] = tmp[i-1][j-1] + 1
            else: tmp[i][j] = max(tmp[i][j-1], tmp[i-1][j])

    num = tmp[len_1][len_2]

    tmp_2 = np.zeros(shape=(num, ), dtype=int)
    tmp_3 = np.zeros(shape=(num, ), dtype=int)

    i, j = len_1, len_2
    while i > 0 and j > 0:

        if a[i-1] == b[j-1]:
            tmp_2[num-1] = i - 1
            tmp_3[num-1] = j - 1
            num -= 1
            i -= 1
            j -= 1

        elif tmp[i-1][j] > tmp[i][j-1]: i -= 1
        else: j -= 1

    print(len(tmp_2))
    print (' '.join(map(str, tmp_2)))
    print (' '.join(map(str, tmp_3)))

if __name__ == '__main__':

    n = int(input())
    
    arr_1 = np.array(input().split(), dtype='int')
    arr_2 = np.array(input().split(), dtype='int')
    
    lcs_problem(arr_1, arr_2)
