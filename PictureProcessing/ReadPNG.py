from PIL import Image
import numpy as np
from matplotlib import pyplot as plt

file_name = input()

image = Image.open(file_name).getdata()
lenght, hight = image.size
image = list(image)

matrix = []
black = (255, 255, 255)

for line in range(hight):
    matrix.append(image[line * lenght: (line + 1) * lenght])

new_data = np.array([[0 if pixel == black else 1 for pixel in line] for line in matrix])

with open('bit_version', 'w') as f:
    for i in new_data:
        for j in i:
            f.write(str(j))
        f.write('\n')

# plt.imshow(matrix)
# plt.show()
