import pandas as pd
from sklearn.cluster import KMeans
from sklearn.mixture import GaussianMixture
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

data = pd.read_csv("Mall_Customers.csv")

features = ['Annual Income (k$)', 'Spending Score (1-100)']
X = data[features]

scaled_data = StandardScaler().fit_transform(X)
em_cluster = GaussianMixture(n_components=5, random_state=42).fit_predict(scaled_data)
kmeans_cluster = KMeans(n_clusters=5, random_state=42).fit_predict(scaled_data)

plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.scatter(X.iloc[:, 0], X.iloc[:, 1], c=em_cluster, cmap='viridis')
plt.title("EM Clustering")
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')

plt.subplot(1, 2, 2)
plt.scatter(X.iloc[:, 0], X.iloc[:, 1], c=kmeans_cluster, cmap='viridis')
plt.title('K-Means Clustering')
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')

plt.tight_layout()
plt.show()

