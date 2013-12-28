#!/usr/bin/python3

class Player:
  def __init__(self, name, value):
    self.name = name
    self.value = value
    self.played = 0

  def __str__(self):
    return self.name

  def __repr__(self):
    return self.name

T = int(input())
for t in range(T):
  N, M, P = map(int, input().split())
  players = []
  for p in range(N):
    read_data = input().split()
    name = read_data[0]
    shp = int(read_data[1])
    height = int(read_data[2])
    players.append(Player(name, shp * 100000 + height))

  players.sort(key=lambda player: player.value, reverse=True)
  team1 = players[::2]
  team2 = players[1::2]

  def compute(team):
    if P * 2 == N: return team
    a = team[:P]
    b = team[P:]
    for _ in range(M): # rotations
      for p in a: p.played += 1
      a.sort(key=lambda player: (+player.played, -player.value))
      b.sort(key=lambda player: (-player.played, player.value))
      to_a, to_b = b.pop(), a.pop()
      a.append(to_a), b.append(to_b)
    return a

  t1 = compute(team1)
  t2 = compute(team2)

  print('Case #' + str(t + 1) + ':', ' '.join(sorted(map(str, t1 + t2))))
