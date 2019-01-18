# author - newguo@sonaspy.cn
# coding - utf_8
import re
str = re.sub('[^a-zA-Z]', '', input()).upper()
n1, n2, sum = 0, 0, 0
for i in str:
    n = ord(i) - ord('A') + 1
    sum += n
str = bin(sum)
str = str[2:]
n1, n2 = str.count('0'), str.count('1')
if n2 == 0:
    print(0, 0)
else:
    print(n1, n2)