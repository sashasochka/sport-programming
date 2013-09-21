from collections import deque
from sys import *
from itertools import *


def main():
    a = list(raw_input())
    b = raw_input()
    tested = set()
    ones = 0
    bones = [0]
    for i in range(len(b)):
        bones.append(bones[-1] + int(b[i] == '1'))

    if len(a) > len(b):
        a = a[-len(b):]
    aones = a.count('1')
    while True:
        ones = 0
        if tuple(a) in tested:
            print('NO')
            return

        for i in range(min(len(a), len(b)) - 1, -1, -1):
            if a[i] != b[i]:
                ones = a[:i + 1].count('1')
                a = a[i + 1:]
                aones -= ones
                break
        ones += aones % 2
        tested.add(tuple(a))
        if bones[-1] - bones[len(a)] <= ones:
            print('YES')
            return
        else:
            i = len(a)
            while True:
                if b[i] == '1':
                    if not ones:
                        break
                    else:
                        ones -= 1
                a.append(b[i])
                if a[-1] == '1':
                    aones += 1
                i += 1
        tested.add(tuple(a))


if __name__ == '__main__':
    main()
