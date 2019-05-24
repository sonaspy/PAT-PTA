# author - newguo@sonaspy.cn
# coding - utf_8
s = input()
num = int(s)
set1 = {'.'}
set2 = {'.'}
for i in s:
    set1.add(i)
s = str(num*2)
for i in s:
    set2.add(i)
print("No" if set1 != set2 else "Yes")
print(s)