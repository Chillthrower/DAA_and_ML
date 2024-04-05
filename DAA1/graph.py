import pandas as pd
import matplotlib.pyplot as plt

# Read the data from CSV file
df = pd.read_csv("time_vs_n_selection.csv")

# Plot the graph
plt.plot(df['n'], df['time_taken'], marker='o', linestyle='-')
plt.xlabel('Number of elements (n)')
plt.ylabel('Time taken (seconds)')
plt.title('Time taken to sort elements vs. Number of elements')
plt.grid(True)
plt.show()
