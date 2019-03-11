# author - newguo@sonaspy.cn 
# coding - utf_8 
num ,maxStep = eval(','.join(input().split()))
step = 0
s = str(num)
while step < maxStep and s != s[::-1]:
    step += 1
    num += int(s[::-1])
    s = str(num)
print("{}\n{}".format(num,step))