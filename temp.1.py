from matplotlib import cm
import matplotlib.pyplot as plt
import numpy as np

theta, phi = np.mgrid[-np.pi:np.pi:50j, -np.pi/2:np.pi/2:50j]


def c(v, t):
    return np.sign(np.cos(v))*(np.abs(np.cos(v))**t)


def s(v, t):
    return np.sign(np.sin(v))*(np.abs(np.sin(v))**t)


def conv_for_para(s1, s2):
    r = 2/s2
    t = 2/s1
    return r, t


A, B, C = 1, 2, 3
s1, s2 = 1, 0.2
r, t = conv_for_para(s1, s2)

X = A*c(phi, 2/t)*c(theta, 2/r)
Y = B*c(phi, 2/t)*s(theta, 2/r)
Z = C*s(phi, 2/t)


fig = plt.figure(figsize=(6, 6), dpi=130)
ax = fig.add_subplot(111, projection='3d')
ax.set_xlim(-5, 5)
ax.set_ylim(-5, 5)
ax.set_zlim(-5, 5)
ax.set_box_aspect((1, 1, 1))

ax.plot_surface(X, Y, Z, cmap=cm.summer)
plt.show()
