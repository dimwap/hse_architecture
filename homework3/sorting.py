# Python program for implementation of Shaker Sort

def shaker_sort(array, method):
    n = len(array)
    swapped = True
    start = 0
    end = n - 1
    while swapped:

        swapped = False

        for i in range(start, end):
            if method(array[i], array[i + 1]):
                array[i], array[i + 1] = array[i + 1], array[i]
                swapped = True

        if not swapped:
            break

        swapped = False

        end = end - 1

        for i in range(end - 1, start - 1, -1):
            if method(array[i], array[i + 1]):
                array[i], array[i + 1] = array[i + 1], array[i]
                swapped = True

        start = start + 1
