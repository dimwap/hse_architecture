import random
from matrix import MatrixType


def generate_random_matrix(min_value, max_value, size, matrix_type=0):
    matrix_type = random.randint(1, 3) if not matrix_type else matrix_type
    matrix = []
    if matrix_type == MatrixType.DEFAULT.value:
        for _ in range(size):
            matrix.append([random.randint(min_value, max_value) for _ in range(size)])
    elif matrix_type == MatrixType.DIAGONAL.value:
        matrix = [random.randint(min_value, max_value) for _ in range(size)]
    elif matrix_type == MatrixType.TRIANGLE.value:
        for i in range(1, size + 1):
            matrix.extend([random.randint(min_value, max_value) for _ in range(i)])

    return matrix_type, size, matrix
