import pandas as pd
import matplotlib.pyplot as plt
data = {'day':[1,2,3,4,5],'time':['00:00:38', '00:01:18', '00:01:58', '00:03:06', '00:03:37'],'percent':[76,37,38,39,40]}
df = pd.DataFrame(data)
df.plot(kind='line', x='time',y='percent') # change line with hist for histogram.
plt.show()


