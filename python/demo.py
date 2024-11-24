# print("gello ,world")

import numpy as np

import matplotlib.pyplot as plt

x=np.arange(0,10,0.1)
y=np.sin(x)
# plt.grid()

# plt.plot(x,y)

plt.figure(figsize=(8,4.5))
ax1=plt.subplot(1,2,1)
ax1.plot(x,y)
ax1.minorticks_on()
ax2=plt.subplot(2,2,2)
ax2.plot(x,y)
ax3=plt.subplot(2,2,4)
ax3.plot(x,y)
plt.show()