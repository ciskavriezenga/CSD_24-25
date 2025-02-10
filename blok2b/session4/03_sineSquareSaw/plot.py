import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv

# create a list and import data from output.csv file
data = list()
with open('./output.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        data.append(float(row[0]))

# transform list to numpy array
np_data = np.array(data)

# create samples for x axis
t = np.arange(0, len(data), 1)

# create plot
fig, ax = plt.subplots()
ax.plot(t, np_data)
plt.yticks(np.arange(-1., 1., 1.0))
ax.set(xlabel='sample', ylabel='output',
       title='Output data')
ax.grid()

# To save the result, outcomment the line below:
# fig.savefig("data_plot.png")
plt.show()
