import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, fftfreq

#Carrier wave c(t)=A_c*cos(2*pi*f_c*t)
#Modulating wave m(t)=A_m*cos(2*pi*f_m*t)
#Modulated wave s(t)=A_c[1+mu*cos(2*pi*f_m*t)]cos(2*pi*f_c*t)

# A_c = float(input('Enter carrier amplitude: '))
# f_c = float(input('Enter carrier frequency: '))
# A_m = float(input('Enter message amplitude: '))
# f_m = float(input('Enter message frequency: '))
#modulation_index = float(input('Enter modulation index: ') )

N = 1000

A_c = float(5)
f_c = float(100000000)
A_m = float(0.25)
f_m = float(50)
modulation_index = float(1.5)

t = np.linspace(0, 1, N)

carrier = A_c*np.cos(2*np.pi*f_c*t)
modulator = A_m*np.cos(2*np.pi*f_m*t)
product = A_c*(1+modulation_index*np.cos(2*np.pi*f_m*t))*np.cos(2*np.pi*f_c*t)

yf = fft(product)
xf = fftfreq(N, 1/1000)[:N//2]

plt.subplot(4, 1, 1)
plt.title('Amplitude Modulation')
plt.plot(modulator, 'g')
plt.ylabel('Amplitude')
plt.xlabel('Message signal')

plt.subplot(4, 1, 2)
plt.plot(carrier, 'r')
plt.ylabel('Amplitude')
plt.xlabel('Carrier signal')

plt.subplot(4, 1, 3)
plt.plot(product, color="purple")
plt.ylabel('Amplitude')
plt.xlabel('AM signal')

plt.subplot(4, 1, 4)
plt.plot(xf, 2.0/N * np.abs(yf[0:N//2]), color="purple")
plt.ylabel('Power')
plt.xlabel('Frequency')

plt.subplots_adjust(hspace=1)
plt.rc('font', size=15)
fig = plt.gcf()
fig.set_size_inches(16, 12)

fig.savefig('Amplitude Modulation.png', dpi=100)
