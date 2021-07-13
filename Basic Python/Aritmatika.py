a = 5
b = 17
x = int(input('Banyak suku: '))
sum = 0
for n in range(1, x+1):
    u = a + (n-1) * b
    sum = sum + u
    print('suku ke-{}:'.format(n), u)
print('jumlah:', sum)