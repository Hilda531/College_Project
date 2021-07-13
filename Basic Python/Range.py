import numpy as np

y = [0.25, 0.4]
y1 = y[0]
y2 = y[1]

for X in np.arange(y1, y2, 0.01):
    if X >= 0.9:
        if X <= 1.0:
            print('A')
        elif X > 1.0:
            print('Ga bisa yeuuu')
    elif X >= 0.8:
        if X < 0.9:
            print('B')
    elif X >= 0.7:
        if X < 0.8:
            print('C')
    elif X >= 0.6:
        if X < 0.7:
            print('D')
    elif X >= 0.0:
        if X < 0.6:
            print('F')


