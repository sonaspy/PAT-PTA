# author - sonaspy@outlook.com 
# coding - utf_8 

l = list(map(int, input().split()))
s1 = str(l[0] * l[1])
num = int(s1[::-1])
print(num)