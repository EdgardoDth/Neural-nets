import matplotlib.pyplot as plt

file = open("perceptron/output.txt")

sizeW = (int)(file.readline())

w = []
print(sizeW)
for i in range(sizeW):
    w.append((float)(file.readline()))

bias = (float)(file.readline())

sizeTarget = (int)(file.readline())
target = []

for i in range(sizeTarget):
    target.append((float)(file.readline()))

sizeRowTs = (int)(file.readline())
sizeColTs = (int)(file.readline())

x = []
for j in range(sizeColTs):
    x.append(list())
    for i in range(sizeRowTs):
        x[j].append((float)(file.readline()))


file.close()

plt.plot(x[0], x[1] , 'bo')
plt.axline((0,-bias/w[1]), (-bias/w[0], 0))
plt.show()
