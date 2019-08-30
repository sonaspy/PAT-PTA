# author -sonaspy@outlook.com
# coding - utf_8
num = input()
number = 0
for i in range(10):
    if num == num[::-1]:
        break
    number = int(num) + int(num[::-1])
    print("{} + {} = {}".format(num, num[::-1], number))
    num = str(number)
if num == num[::-1]:
    print("{} is a palindromic number.".format(num))
else:
    print("Not found in 10 iterations.")