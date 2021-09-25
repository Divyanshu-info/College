# Torus defined by : x θ,φ = a(r + sinφ)cosθ, y θ,φ = b(r + sinφ)sinθ,
# and z θ,φ = ccosφ for 0 ≤ θ ≤ 2π and 0 ≤ φ ≤ π, and a, b, c, r =
# 1, 2, 3, 2 .

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

n = 100

phi = np.linspace(0, np.pi, n)
theta = np.linspace(0, 2.*np.pi, n)
theta, phi = np.meshgrid(theta, phi)
r, a, b, c = 2, 1 ,2 ,3

x =a * (r + np.sin(phi)) * np.cos(theta)
y =b * (r + np.sin(phi)) * np.sin(theta)
z =c * np.cos(phi)


fig = plt.figure()
ax1 = fig.add_subplot(121, projection='3d')
ax1.set_zlim(-3,3)
ax1.plot_surface(x, y, z, rstride=5, cstride=5, color='k', edgecolors='w')
ax1.view_init(36, 26)
ax2 = fig.add_subplot(122, projection='3d')
ax2.set_zlim(-3,3)
ax2.plot_surface(x, y, z, rstride=5, cstride=5, color='k', edgecolors='w')
ax2.view_init(0, 0)
ax2.set_xticks([])
plt.show()