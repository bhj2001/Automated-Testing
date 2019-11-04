# cook your dish here
n,m,d=map(int,input().split(" "))
y=list(map(int,input().split()))
s=sum(y)
if s+(m+1)*(d-1)>=n:
    arr=[0]*(n+1)
    arr[0]=-1
    current=1
    k=1
    i=0
    while i<m:
        j=0
        while j<y[i]:
            arr[k]=current
            k+=1
            j+=1
        current+=1
        i+=1
 
    
    next1=n+1
    i=k-1
    while i>=0:
        if next1-i>d:
            previous=arr[i]
            arr[i]=0
            arr[next1-d]=previous
            next1=next1-d
          
            if arr[i-1]==previous:
                while arr[i-1]==previous:
                    previous=arr[i-1]
                    arr[i-1]=0
                    arr[next1-1]=previous
                    next1=next1-1
                    i-=1
             
                
            i-=1
        else:
            break
    
        
    
    print("YES")
    for i in range(1,n+1):
        print(arr[i],end=" ")
    
    
else:
    print("NO")
