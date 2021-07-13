text = open('sekuensefile.txt')
inp = text.read()
a = 0
g = 0
t = 0
c = 0

for x in inp:
    if x == "A":
        a = a + 1
    elif x == "G":
        g = g + 1
    elif x == "T":
        t = t + 1
    elif x == "C":
        c = c + 1
print(a)
print(g)
print(t)
print(c)

