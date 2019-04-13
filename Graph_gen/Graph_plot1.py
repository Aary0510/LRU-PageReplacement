
# coding: utf-8

# In[63]:


import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')

frame = []
pageFault = []
# timer = []

with open('output1.txt','r') as f:
    for line in f:
        f, p = line.split()
        frame.append(int(str(f)))
        pageFault.append(int(str(p)))
#         timer.append(int(str(t)))


# frame , pageFault, timer

plt.title('Plot of Page Faults vs # of Frames') 
plt.ylabel('PageFaults') 
plt.xlabel('NoOfFrames')
plt.plot(frame , pageFault, '.-')
plt.show()

