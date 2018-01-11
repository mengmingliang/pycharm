import threading,multiprocessing,time,random

#loop function
def loop():
    x = 0
    while True:
        x = x^1


#the number of Cpu module,every module will run a loop thread
n = multiprocessing.cpu_count()
print('we have %s Cpu module,and we will start %s threads'%(n,n))
for i in range(n):
    t = threading.Thread(target=loop)
    t.start()

