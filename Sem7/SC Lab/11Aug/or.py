#Make a perceptron model for OR gate
from numpy import *

def orTarget(x):
    a = x[0]
    b = x[1]

    if a==1 and b==1: return 1
    if a==1 or b==1: return 1
    else: return 0


def unitOperation(v):
    if v>=0 :
        return 1
    else:
        return 0

def orGate(w,x,b):
    # w - weight, b - bias
    v=0
    v = dot(w,x)+b
    # for i in range(2):
    #     v += dot(w[i],x[i])
    # v+=b
    p = unitOperation(v)
    return p


def orPerceptronModel(a,b):
    w = [1,1]
    x = [a,b]
    b = -1
    
    actualOutput = orGate(w,x,b)
    targetOutput = orTarget(x)
    e = targetOutput-actualOutput
    
    print(f"actual: {actualOutput} target: {targetOutput}")

    while(actualOutput!=targetOutput):
        for i in range(2):
            e = targetOutput-actualOutput
            if e>0 : w[i]=w[i]+x[i]
            elif e<0 : w[i]=w[i]-x[i]
            else: break

        actualOutput = orGate(w,x,b)
    
    print("Weights:")
    for i in range(2):
        print(f"{w[i]}")
    

    return actualOutput
    

#main code
a = int(input("Enter a value: "))
b = int(input("Enter a value: "))

print(f"a: {a} b: {b} {orPerceptronModel(a,b)}")





