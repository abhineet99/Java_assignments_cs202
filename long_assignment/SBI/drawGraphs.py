import matplotlib.pyplot as plt
import numpy as np
thread_4=np.array([104,94,93,104,87])
thread_3=np.array([112,103,96,104,103])
thread_2=np.array([99,104,108,115,118])
thread_1 =np.array([152,145,137,147,132])
x=[]
x.append(thread_1)
x.append(thread_2)
x.append(thread_3)
x.append(thread_4)
x=np.array(x)
print(x)
#x = np.random.randn(100, 8)
mins = x.min(1)
print(mins)
maxes = x.max(1)
means = x.mean(1)
std = x.std(1)
print(x.shape)
# create stacked errorbars:
# plt.errorbar(np.arange(4), means, std, fmt='ok', lw=3)
# plt.errorbar(np.arange(4), means, [means - mins, maxes - means],
#              fmt='.k', ecolor='gray', lw=1)
labels=["1","2","3","4"] 
# plt.xticks(range(len(labels)),labels)
#ax = plt.subplots(1,1)
#ax.set_xticks(labels)     
plt.xlabel('Number of threads', fontsize=18)
plt.ylabel('Parallel Efficiency', fontsize=16)
plt.xlim(-1, 4)
#plt.show()
print(means)
min_mean=means[0]
for i in range(len(means)):
    means[i]=min_mean/means[i]
print(means)
for i in range(len(means)):    
    means[i]=means[i]/(i+1)
plt.plot(labels,means,'ro')
print(means)
plt.show()
