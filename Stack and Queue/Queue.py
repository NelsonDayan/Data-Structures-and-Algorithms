#Implementation of a queue
stack=[]
tmp_stack=[]
top=0
while True:
    option=input("Choose your option:\n1.enqueue\n2.dequeue\n3.exit")
    if option=="enqueue" | "2":
        element=input("Enter element for insertion: ")
        stack.append(element)
        top+=1
        print(stack)
    elif option=="dequeue" | "2" :
        if top==0:
            print("Queue is empty")
        else:
            for i in range(0,top-1):
                stack[i]=stack[i+1]
            top-=1
            stack.pop()
            print(stack)

    elif option=="exit" | "3":
        exit(0)
    else:
        print("Enter a valid option: ")
