#!/usr/bin/env python3
import sys


def solve(N, a):
    a.sort()


def main():
    T = int(input())
    for t in range(T):
        N = int(input())
        a = list(map(int, input().split()))
        solve(N, a)


if __name__ == '__main__':
    main()
