#/usr/bin/python

import os
import random

os.system('touch testcases')
t = 1
os.system("echo '{}' > testcases".format(t))
os.system("echo '' > out1")
os.system("echo '' > out2")

while t:
    t -= 1
    n = random.randint(1, 50)
    min = random.randint(1, 1000-1)
    max = random.randint(min+1, 1000)
    os.system("echo '{} {} {}' >> testcases".format(n,min,max))

    while n:
        n -= 1
        w = random.randint(1,100)
        b = random.randint(1,100)
        os.system("echo '{} {}' >>  testcases".format(w,b))
