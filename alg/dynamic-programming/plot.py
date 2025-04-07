import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # enables 3D plotting
import pandas as pd

# Load CSV data into a pandas DataFrame
df = pd.read_csv('out.csv')

# Example: your CSV might have columns: method, var1, var2, time
# Filter data by method
method1_data = df[df['Method'] == 'Bottom-up']
method2_data = df[df['Method'] == 'Memoization']

# Create a 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot method 1 data
ax.plot(method1_data['N'], method1_data['K'], method1_data['time(ns)'],
        label='Method1', color='blue', marker='o')

# Plot method 2 data
ax.plot(method2_data['N'], method2_data['K'], method2_data['time(ns)'],
        label='Method2', color='red', marker='^')

# align axes
ax.set_xlim(df['N'].min(), df['N'].max())
ax.set_ylim(df['K'].min(), df['K'].max())
ax.set_zlim(df['time(ns)'].min(), df['time(ns)'].max())

#check errors
df['var1'] = pd.to_numeric(df['N'], errors='coerce')
df['var2'] = pd.to_numeric(df['K'], errors='coerce')
df['time'] = pd.to_numeric(df['time(ns)'], errors='coerce')

# Label axes
ax.set_xlabel('N')
ax.set_ylabel('K')
ax.set_zlabel('Time')

# Add a legend
ax.legend()

# Display the plot
plt.show()

