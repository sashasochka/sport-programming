#!/usr/bin/python3

def f(s, k, N):
  ''' s - string, k - substring length, N - number of substring '''
  if k == 1: return s[N]
  n = len(s)
  ind = N // (n ** (k-1))
  return s[ind] + f(s, k - 1, N - ind * n ** (k-1))


T = int(input())
for t in range(T):
  data = input().split()
  s = data[0]
  N = int(data[1]) - 1
  length = 1
  n = len(s)
  while n ** length <= N:
    N -= n ** length
    length += 1

  print('Case #' + str(t + 1) + ':', f(s, length, N))

