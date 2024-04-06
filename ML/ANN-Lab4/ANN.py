import numpy as np

X = np.array(([2, 9], [1, 5], [3, 6]), dtype=float) / 9 # slept, study
y = np.array(([92], [86], [89]), dtype=float) / 100 # marks

class NN:
    def __init__(self):
        self.W1 = np.random.randn(2, 3)
        self.W2 = np.random.randn(3, 1)
    def forward(self, X):
        self.z2 = 1 / (1 + np.exp(-np.dot(X, self.W1)))
        return 1 / (1 + np.exp(-np.dot(self.z2, self.W2)))
    def backward(self, X, y, o):
        o_delta = (y - o) * o * (1 - o)
        self.W2 += np.dot(self.z2.T, o_delta)
        self.W1 += np.dot(X.T, np.dot(o_delta, self.W2.T) * self.z2 * (1 - self.z2))

NN = NN()
for _ in range(1000):
    o = NN.forward(X)
    NN.backward(X, y, o)
    print("\nInput:\n", X, "\nActual Output:\n", y, "\nPredicted Output:\n", o, "\nLoss:", np.mean(np.square(y - o)))
