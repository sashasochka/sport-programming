#!/usr/bin/python3
T = int(input())
for t in range(T):
  n = int(input())
  mp = [input() for _ in range(n)]
  st = None
  fi = None
  for i in range(n):
    for j in range(n):
      if st is None and mp[i][j] == '#':
        st = (i, j)
      if mp[i][j] == '#':
        fi = (i, j)
  ok = fi[0] - st[0] == fi[1] - st[1]
  for i in range(n):
    for j in range(n):
      if st[0] <= i <= fi[0] and st[1] <= j <= fi[1]:
        if mp[i][j] != '#':
          ok = False
      else:
        if mp[i][j] == '#':
          ok = False

  print('Case #' + str(t + 1) + ':', "YES" if ok else "NO")

