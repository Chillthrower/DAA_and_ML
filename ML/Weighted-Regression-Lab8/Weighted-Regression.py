
################# MAM WONT LET YOU USE THIS CODE BECAUSE K VALUE IS NOT DEFINED
# AJAY BOYS CODE

import numpy as np
import statsmodels.api as sm
import matplotlib.pyplot as plt

n = 100
x = np.linspace(0, 2 * np.pi, n)
y = np.sin(x) + 0.3 * np.random.randn(n)

lowess = sm.nonparametric.lowess(y, x, frac=0.25, it=3)

plt.plot(x, y, "r.")
plt.plot(lowess[:, 0], lowess[:, 1], "b-")
plt.show()

#AMRITH BOYS CODE

import numpy as np
import matplotlib.pyplot as plt
from statsmodels.nonparametric.smoothers_lowess import lowess

n = 100
x = np.linspace(0, 2 * np.pi, n)
y = np.sin(x) + 0.3 * np.random.randn(n)

y_est = lowess(y, x,frac=0.2)

plt.plot(x, y, "r.", x, y_est[:,1], "b-")
plt.show()

#defined weights

import numpy as np
import statsmodels.api as sm
import matplotlib.pyplot as plt

n = 100
x = np.linspace(0, 2 * np.pi, n)
y = np.sin(x) + 0.3 * np.random.randn(n)

# Define weights (optional)
weights = np.ones_like(y)

# Apply weights to data
weighted_y = y * np.sqrt(weights)

lowess = sm.nonparametric.lowess(weighted_y, x, frac=0.25, it=3)

# Extract smoothed values
smoothed_y = lowess[:, 1] / np.sqrt(weights)

plt.plot(x, y, "r.")
plt.plot(x, smoothed_y, "b-")
plt.show()

