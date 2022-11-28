import numpy as np

def result_f(arr, n):

    tmp1 = 0
    tmp2 = 0

    arr = np.array(arr)
    arr_matrix = np.zeros(shape=(n, n, 3))

    for index in range(n):
        arr_matrix[index][index][0] = arr[index][0]
        arr_matrix[index][index][1] = arr[index][1]

    for i in range (1, n):
        for j in range (n - i):
            min_nz = float('inf')
            for k in range(i):
                cf = arr_matrix[j + k][j][0] * arr_matrix[j + k][j][1] * arr_matrix[i + j][j + k + 1][1]\
                     + arr_matrix[j + k][j][2] + arr_matrix[i + j][j + k + 1][2]

                if cf < min_nz:
                    min_nz = cf
                    tmp1 = arr_matrix[j + k][j][0]
                    tmp2 = arr_matrix[i + j][j + k + 1][1]

            arr_matrix[i + j][j][0] = tmp1
            arr_matrix[i + j][j][1] = tmp2
            arr_matrix[i + j][j][2] = min_nz

    return (arr_matrix[n - 1][0][2]).astype(int)

if __name__ == "__main__":

    f_out = open('output.txt', 'w')
    with open('input.txt') as f_in:
        n = [int(x) for x in next(f_in).split()]
        in_d = 0

        rows, cols = (int(n[0]), 2)
        arr = []

        for line in f_in:
            arr.append([])
            aaz, vvz = [int(x) for x in line.split()]
            arr[in_d].append(aaz), arr[in_d].append(vvz)
            in_d += 1

    f_out.write(str(result_f(arr, int(n[0]))))

    f_in.close()
    f_out.close()
