from matrix import create_matrix
from sorting import shaker_sort
import random
from random_generation import generate_random_matrix


def generate_test_file():
    matrices = generate(1, 100, 1, 20)
    for i in range(6):
        with open('tests/test{}.txt'.format(i), 'w+') as file:
            temp = [' '.join([str(i['type']), str(i['size']), str(i['matrix'])]) for i in
                    matrices]
            file.writelines('\n'.join(temp))

        shaker_sort(matrices, lambda x, y: True if x['matrix'].get_mean() > y['matrix'].get_mean() else False)

        with open('tests/answer{}.txt'.format(i), 'w+') as file:
            temp = [' '.join([str(i['type']), str(i['size']), str(i['matrix'])]) for i in
                    matrices]
            file.writelines('\n'.join(temp))


def generate(min_value, max_value, min_count, max_count):
    matrices = []
    for i in range(random.randint(min_count, max_count)):
        matrix_type, size, array = generate_random_matrix(min_value, max_value, random.randint(1, 6))
        matrices.append(create_matrix(matrix_type, size, array))
    return matrices
