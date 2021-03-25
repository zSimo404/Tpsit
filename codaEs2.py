
def dequeue(queue):   #toglie la head della coda
    return queue.pop(0)

def enqueue(queue,element):  #aggiunge 
    queue.append(element)

def pop(stack):
    return stack.pop()

def push(stack,element):
    return stack.append(element)



def main():
    queue=[]  #crea una lista vuota
    while True:
        element=int(input())
        enqueue(queue,element)
        ans=input("metti s se vuoi continuare, n altrimenti")
        if ans=="n" or ans=="N":
            break

    for _ in range(len(queue)):
        push(stack,dequeue(queue))

    for _ in range(len(stack)):
        enqueue(queue,pop(stack))

    for _ in range(len(queue)):
        print(dequeue(queue))


if __name__=="__main__":
    main()