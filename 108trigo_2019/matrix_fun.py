from math import *

# MATRIX FUNCTION

def matrix_add(mat_1, mat_2):
    tmp = [0] * len(mat_1)
    for i in range(len(mat_1)):
        tmp[i] = mat_1[i] + mat_2[i]
    return (tmp)
    
def matrix_add_nbr(mat, nbr):
    tmp = [0] * len(mat)
    for i in range(0, len(mat)):
        tmp[i] = mat[i] + nbr
    return (tmp)

def matrix_sub(mat_1, mat_2):
    tmp = [0] * len(mat_1)
    for i in range(len(mat_1)):
        tmp[i] = mat_1[i] - mat_2[i]
    return (tmp)

def matrix_sub_nbr(mat, nbr):
    tmp = [0] * len(mat)
    for i in range(len(mat)):
        tmp[i] = mat[i] - nbr
    return (tmp)

def matrix_pow(mat, nbr):
    tmp = mat.copy()
    for i in range(nbr - 1):
        tmp = matrix_mult(tmp, mat)
    return (tmp)

def matrix_mult(mat_1, mat_2):
    n = int(sqrt(len(mat_1)))   
    tmp = [0] * len(mat_1)
    for i in range(0, n):
        for j in range(0, n):
            for k in range(0, n):
                tmp[i + j * n] += (mat_1[i + k * n] * mat_2[k + j * n])
    return (tmp)


def matrix_mult_nbr(mat, nbr):
    tmp = mat.copy
    for i in range(0, len(mat)):
        tmp = mat[i] * nbr
    return (tmp)

def matrix_div(mat_1, mat_2):
    tmp = [0] * len(mat_1)
    for i in range(len(mat_1)):
        try:
            tmp[i] = mat_1[i] / mat_2[i]
        except ZeroDivisionError:
            sys.exit(84)
    return (tmp)

def matrix_div_nbr(mat, nbr):
    tmp = [0] * len(mat)
    for i in range(len(mat)):
        try:
            tmp[i] = mat[i] / nbr
        except ZeroDivisionError:
            sys.exit(84)
    return (tmp)

def matrix_identity(mat):
    tmp = [0] * len(mat)
    n = int(sqrt(len(mat)))
    for i in range(n):
        tmp[i * n + i] = 1
    return (tmp)
