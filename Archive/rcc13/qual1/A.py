#!/usr/bin/env python3
import sys


def solve(h1, w1, h2, w2, h3, w3):
    result = sys.maxsize
    for i in range(2):
        h2, w2 = w2, h2
        for j in range(2):
            h3, w3 = w3, h3
            S = h1 * w1 + h2 * w2 + h3 * w3
            S -= min(h1, h2) * min(w1, w2)
            S -= min(h1, h3) * min(w1, w3)
            S -= min(h2, h3) * min(w2, w3)
            S += min(h1, h2, h3) * min(w1, w2, w3)
            result = min(result, S)
    print(result)


def main():
    for line in sys.stdin:
        if line.rstrip() == '0 0 0 0 0 0':
            break
        h1, w1, h2, w2, h3, w3 = map(int, line.split())
        solve(h1, w1, h2, w2, h3, w3)


if __name__ == '__main__':
    main()
