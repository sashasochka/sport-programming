#!/usr/bin/python3
from copy import deepcopy
from collections import deque

# for debugging
# def to_str(ln):
#  return '\n'.join(' '.join([str(e).rjust(2)  for e in l]) for l in ln])

def outline(mp, M):
  return [['#'] * (M + 2)] + \
         [['#'] + line + ['#'] for line in mp] + \
         [['#'] * (M + 2)]

def label(mp, sx, sy):
  result = deepcopy(mp)
  q = deque([])
  if result[sy][sx] == '.':
    q.append((sx, sy))
    result[sy][sx] = 1
  while q:
    x, y = q.popleft()
    for (nx, ny) in [(x+1, y), (x, y+1)]:
      if result[ny][nx] == '.':
        q.append((nx, ny))
        result[ny][nx] = result[y][x] + 1
  return result

def slice(mp, xs, ys):
  return [[mp[y][x] for x in range(xs, len(mp[0]) - 1)] for y in range(ys, len(mp) - 1)]

def maxval(ln):
  result = 0
  for row in ln:
    for val in row:
      if isinstance(val, int):
        result = max(result, val)
  return result

T = int(input())
for t in range(T):
  N, M = map(int, input().split())
  mp = outline([list(input()) for _ in range(N)], M)
  ln = label(mp, 1, 1)

  result = maxval(ln)
  for y in range(1, N + 1):
    for x in range(1, M + 1):
      val = ln[y][x]
      if isinstance(val, int) and isinstance(ln[y - 1][x], int):
        move = 1
        while mp[y][x - move] == '.':
          lbl = label(outline(slice(mp, x - move, y + 1), M), 1, 1)
          r = val + move + maxval(lbl)
          result = max(result, r)
          move += 1
      if isinstance(val, int) and isinstance(ln[y][x - 1], int):
        move = 1
        while mp[y - move][x] == '.':
          lbl = label(outline(slice(mp, x + 1, y - move), M), 1, 1)
          r = val + move + maxval(lbl)
          result = max(result, r)
          move += 1


  print('Case #' + str(t + 1) + ':', result)

