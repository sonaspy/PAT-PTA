n = int(input())

for i in range(n):
  l = list(map(int, input().split()))
  print("Case #{}: ".format(i+1), end='')
  if l[0]+l[1] > l[2]:
    print("true")
  else:
    print("false")
