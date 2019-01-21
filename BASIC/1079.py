# author - newguo@sonaspy.cn
# coding - utf_8
count = 0
x = input()
if x == x[::-1]:
    print("{} is a palindromic number.".format(x))
else:
    for i in range(10):
        a = int(x)
        b = int(x[::-1])
        c = a + b
        print("{} + {} = {}".format(x, x[::-1], str(c)))
        x = str(c)
        if x == x[::-1]:
            print("{} is a palindromic number.".format(x))
            break
        count += 1

if count == 10:
    print("Not found in 10 iterations.")
