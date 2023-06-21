import numpy as np
import matplotlib.pyplot as plt

density = []
height = []
timestamps = []


"""
There are some errors in density_map, e.g. on line 92 the depth is += 10 w.r.t the thesis. 
density_map2 is copied straight from the thesis with no modification and is used to read the data.
"""
# Old way of reading data
"""
with open('density_map') as f:
    contents = f.readlines()
    

for line in contents:
    timestamps.append(float(line.split()[0]))
    height.append(float(line.split()[1]))
    density.append(float(line.split()[2]))
"""

# New way of reading data
with open('density_map2') as f:
    contents = f.readlines()

for line in contents: 
    line = line.split()
    height.append(float(line[3]))
    density.append(float(line[5]))

height = [ -x for x in height]

# Polyfitting
# pfit contains the polynomial coefficients in descending order
pfit = np.polyfit(density, height, 7)
# pol_our is the polyfit function that is used to predict single values
pol_our = np.poly1d(pfit)

# Polyfit coefficients from Intelligent Diving Control, in descending order
weights = [5.82791451e-13, 2.93618412e-10, 5.80359192e-08, 5.74515221e-06, 0.000301506402, 0.00794346722, 0.0338527732, 1003.71941686]
# pol_thesis is the same as pol_our, but for the thesis' coefficients
pol_thesis = np.poly1d(weights)


# Plotting
span = np.linspace(min(density), max(density), len(density))
plt.plot(span, pol_our(span), 'r-')
# plt.plot(span, pol_thesis(span), 'o--') # Not working atm, see comment below
plt.plot(density, height, 'bx')
plt.legend(['Our polyfit', 'Datapoints'])
plt.xlabel('Density (kg/m^3)')
plt.ylabel('Height (m)')
plt.show()

"""
There seems to be some problem related to the polyfit from the thesis. When you uncomment line 33, 
you can see in the plot that the function soares above the data points and our polyfit. I'm not 
sure why this is but may have someting to do with the format of the data we are using. 

Another thing is that the 7th-deg polynomial fit might be overfitting a bit. The python console 
gives the throws the RankWarning-error when you run it with a 7-degree polynomial, but stops when 
you decrease it to 3. This might be worth considering if we are planning on using our own polynomial. 
"""

