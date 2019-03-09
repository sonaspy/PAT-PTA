# author -  newguo@sonaspy.cn
# coding - utf_8
import re
hand = re.split('[ \[\]]', input())
eye = re.split('[ \[\]]', input())
mouth = re.split('[ \[\]]', input())
n = hand.count('')
for i in range(n):
    hand.remove('')
n = eye.count('')
for i in range(n):
    eye.remove('')
n = mouth.count('')
for i in range(n):
    mouth.remove('')
mouth.remove('...')
num = eval(input())
for i in range(num):
    a = [int(j) - 1 for j in input().split()]
    s = ''
    flag = True
    if a[0] > len(hand)-1:
        print('Are you kidding me? @\/@')
        flag = False
    elif a[1] > len(eye)-1:
        print('Are you kidding me? @\/@')
        flag = False
    elif a[2] > len(mouth)-1:
        print('Are you kidding me? @\/@')
        flag = False
    elif a[3] > len(eye)-1:
        flag = False
        print('Are you kidding me? @\/@')
    elif a[4] > len(hand)-1:
        flag = False
        print('Are you kidding me? @\/@')
    if flag == True:
        s = hand[a[0]] +'('
        s = s + eye[a[1]]
        s = s + mouth[a[2]]
        s = s + eye[a[3]] + ')'
        s = s + hand[a[4]]
        print(s)

    

