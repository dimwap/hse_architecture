import copy
import enum
import json


def create_matrix(matrix_type, size, array):
    if matrix_type == MatrixType.DEFAULT.value:
        return dict(type=matrix_type, size=size, matrix=MatrixDefault(array, size))
    elif matrix_type == MatrixType.DIAGONAL.value:
        return dict(type=matrix_type, size=size, matrix=MatrixDiagonal(array, size))
    elif matrix_type == MatrixType.TRIANGLE.value:
        return dict(type=matrix_type, size=size, matrix=MatrixTriangle(array, size))


class MatrixType(enum.Enum):
    DEFAULT = 1
    DIAGONAL = 2
    TRIANGLE = 3


class Matrix:

    def __init__(self, array, size):
        self.matrix = copy.deepcopy(array)
        self.size = size

    def get_mean(self):
        ...

    def __str__(self):
        return json.dumps(self.matrix)


class MatrixDefault(Matrix):
    def __init__(self, array, size):
        super().__init__(array, size)

    def get_mean(self):
        return sum([sum(i) for i in self.matrix]) / self.size ** 2


class MatrixDiagonal(Matrix):
    def __init__(self, array, size):
        super().__init__(array, size)

    def get_mean(self):
        return sum(self.matrix) / self.size ** 2


class MatrixTriangle(Matrix):
    def __init__(self, array, size):
        super().__init__(array, size)

    def get_mean(self):
        return sum(self.matrix) / self.size ** 2
