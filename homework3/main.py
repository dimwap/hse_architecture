from matrix import create_matrix
from sorting import shaker_sort
import json
import argparse
import sys
from enum import Enum
from test_generation import generate
import time


class InputType(Enum):
    custom = 'custom'
    little_data_test = 'test_little_data'
    big_data_test = 'test_big_data'

    def __str__(self):
        return self.value


def read_matrices(filename, matrices):
    with open(filename, 'r') as file:
        for matrix in file.readlines():
            matrix_type, size, array = int(matrix[0]), int(matrix[2]), json.loads(matrix[4:])
            matrices.append(create_matrix(matrix_type, size, array))


def custom_data(input_file, output_file):
    matrices = []
    read_matrices(input_file, matrices)
    shaker_sort(matrices, lambda x, y: True if x['matrix'].get_mean() > y['matrix'].get_mean() else False)
    with open(output_file, 'w+') as file:
        matrices = [' '.join([str(j['type']), str(j['size']), str(j['matrix'])]) for j in matrices]
        file.writelines('\n'.join(matrices))


def test_little_data():
    for i in range(6):
        matrices = []
        input_file = 'tests/test{}.txt'.format(i)
        output_file = 'tests/answer_test{}.txt'.format(i)
        answer_file = 'tests/answer{}.txt'.format(i)
        read_matrices(input_file, matrices)
        shaker_sort(matrices, lambda x, y: True if x['matrix'].get_mean() > y['matrix'].get_mean() else False)
        with open(output_file, 'w') as file:
            matrices = [' '.join([str(j['type']), str(j['size']), str(j['matrix'])]) for j in matrices]
            file.writelines('\n'.join(matrices))
        with open(answer_file, 'r') as ans_file:
            with open(output_file, 'r') as ans_test_file:
                if ans_test_file.read() == ans_file.read():
                    print('-----------')
                    print("Test {} passed".format(i))
                else:
                    print('-----------')
                    print("Test {} failed".format(i))


def test_big_data():
    matrices = generate(0, 10000, 1000, 10000)
    start = time.perf_counter()
    shaker_sort(matrices, lambda x, y: True if x['matrix'].get_mean() > y['matrix'].get_mean() else False)
    end = time.perf_counter()
    print("Time passed: {} seconds".format(end - start))
    print("Elements sorted: {}".format(len(matrices)))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--type', type=InputType, required=True)
    parser.add_argument('--input', type=str, required=InputType.custom.value in sys.argv)
    parser.add_argument('--output', type=str, required=InputType.custom.value in sys.argv)
    args = parser.parse_args()
    if args.type == InputType.custom:
        custom_data(args.input, args.output)
    elif args.type == InputType.little_data_test:
        test_little_data()
    elif args.type == InputType.big_data_test:
        test_big_data()


if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        print(e)
