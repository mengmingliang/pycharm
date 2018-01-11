from multiprocessing import Process,Queue
import os,time,random
#wirte message to the queue
def write(q):
    print('Process to Write:%s'%os.getpid())
    for value in ['A','B','C','D']:
        print('Put %s to queue...'%value)
    q.put(value)
    time.sleep(random.random())

#read message from the queue
def read(q):
    print('Process to read:%s'%os.getpid())
    while True:
        value = q.get(True)
        print('Get %s from queue.'%value)

if __name__ =='__main__':
    q = Queue()
    pw = Process(target=write,args=(q,))
    pr = Process(target=read,args=(q,))
    pw.start()
    pr.start()
    pw.join()
    pr.terminate()

