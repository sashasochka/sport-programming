#!/usr/bin/env python3
p = 1000000007


def solve(N, K, s):
    s.sort()
    r = 1
    prev = 0
    for v in s:
        if v == 1:
            pairs = 1
        elif N >= v:
            pairs = (v - 2 * prev + 2) // 2
        else:
            if N >= v - prev:
                pairs = (v - 2 * prev) // 2
            else:
                pairs = min(v // 2, N) - prev

        r *= pow(2, pairs, p)
        r %= p
        prev = v
    r %= p
    r *= pow(2, N - prev, p)
    print(r % p)


def main():
    while True:
        l1 = input()
        if l1.rstrip() == '0 0':
            break
        N, K = map(int, l1.split())
        s = list(map(int, input().split()))
        solve(N, K, s)


if __name__ == '__main__':
    main()
