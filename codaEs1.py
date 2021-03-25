
def dequeue(queue):   #toglie la head della coda
    return queue.pop(0)

def enqueue(queue,element):
    queue.append(element)



def main():
    queue=[]  #crea una lista vuota
    while True:
        element=int(input())
        enqueue(queue,element)
        ans=input("metti s se vuoi continuare, n altrimenti")
        if ans=="n" or ans=="N":
            break

    for _ in range(len(queue)):
        print(dequeue(queue))

        
if __name__=="__main__":
    main()
