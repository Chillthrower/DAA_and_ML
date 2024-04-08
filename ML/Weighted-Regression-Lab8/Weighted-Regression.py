
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
