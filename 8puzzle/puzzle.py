import random

size = 5

matriz = [[0 for _ in range(size)] for _ in range(size)]

def print_board():
    for i in range(size):
        print('')
        for j in range(size):
            print(' ', matriz[i][j], end = '')

def reset_board():
    numbers = list(range(1, size*size))
    numbers.append('x')
    random.shuffle(numbers)
    
    for i in range(size):
        for j in range(size):
            matriz[i][j] = numbers.pop()

def test_order():
    expected_order = ['x'] + list(range(1, size*size-1))
    return matriz == expected_order

def main():
    while(test_order()==False):
        reset_board()
        print_board()
        print('')

if __name__ == "__main__":
    main()
