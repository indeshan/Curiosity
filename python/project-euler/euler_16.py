ex = 2**1000
s = 0
while ex > 0:
    rem = ex % 10
    ex = ex/10
    s += rem 

print(s)
