text = open('ftest.txt')
baris = 0
COUNT = 0
for x in text:
    baris = baris + 1
    if x.startswith('Received'):
        COUNT = COUNT + 1
        print('{}.'.format(COUNT), x)
print('Jumlah pengirim:', COUNT)
print('Jumlah baris:', baris)