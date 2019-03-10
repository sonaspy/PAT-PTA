# author - newguo@sonaspy.cn 
# coding - utf_8 
s = input()
num = int(s)
set1 = {'.'}
set2 = {'.'}
for i in s:
    set1.add(i)
for i in str(num*2):
    set2.add(i)
if set1 != set2:
    print("No")
else:
    print("Yes")
print(num*2)