import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
import warnings

warnings.filterwarnings('ignore')

iris = load_iris()

print("Column names in the Iris dataset:", iris.feature_names)
print("Target names in the Iris dataset:", iris.target_names)

iris_df = pd.DataFrame(data=iris.data, columns=iris.feature_names)
iris_df['target'] = iris.target

X_train, X_test, y_train, y_test = train_test_split(iris_df.drop('target', axis=1), iris_df['target'], test_size=0.2, random_state=42)

k = 4
knn = KNeighborsClassifier(n_neighbors=k).fit(X_train, y_train)

accuracy = accuracy_score(y_test, knn.predict(X_test))
print(f"Accuracy of k-Nearest Neighbor (k={k}): {accuracy}")

print(pd.DataFrame({'Actual': y_test, 'Predicted': knn.predict(X_test)}))

sample = np.array([[5.1, 3.5, 1.4, 0.2]]) # Example sample
predicted_species = iris.target_names[knn.predict(sample)[0]]
print(f"Predicted class for the sample: {predicted_species}")
