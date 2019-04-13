
# coding: utf-8

# In[16]:


import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')

avgTime = []
pageFault = []
frame = []
accesTime = []

with open('outputclock.txt','r') as f:
    for line in f:
        f, p, avgT, acT = line.split()
        frame.append(int(str(f)))
        pageFault.append(int(str(p)))
        avgTime.append(float(str(avgT)))
        accesTime.append(float(str(acT)))



plt.title('Plot of Execution vs # of Frames for LRU Clock') 
plt.ylabel('Average Time') 
plt.xlabel('No. of Frames')
plt.plot(frame, avgTime,  '.-')
plt.show()

plt.title('Plot of Cache Access Time vs # of Frames') 
plt.ylabel('Cache Access Time') 
plt.xlabel('No. of Frames')
plt.plot(frame, accesTime,  '.-')
plt.show()

