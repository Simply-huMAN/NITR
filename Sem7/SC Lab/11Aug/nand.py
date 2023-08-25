#Make a perceptron model for NAND gate
from numpy import *

def nandTarget(x):
    a = x[0]
    b = x[1]
    
    if a==1:
        if b==1: return 0
        else: return 1
    else:
        return 1


def unitOperation(v):
    if v>=0 :
        return 1
    else:
        return 0

def nandGate(w,x,b):
    # w - weight, b - bias
    v=0
    for i in range(2):
        v+= w[i]*x[i]
    v+=b
    p = unitOperation(v)
    return p


def nandPerceptronModel(a,b):
    w = [0,1]
    x = [a,b]
    b = -4
    
    actualOutput = nandGate(w,x,b)
    targetOutput = nandTarget(x)
    e = targetOutput-actualOutput
    
    print(f"actual: {actualOutput} target: {targetOutput}")

    while(actualOutput!=targetOutput):
        for i in range(2):
            e = targetOutput-actualOutput
            if e>0 : w[i]=w[i]+x[i]
            elif e<0 : w[i]=w[i]-x[i]
            else: break

        b = b+e
        actualOutput = nandGate(w,x,b)
    
    print("Weights:")
    for i in range(2):
        print(f"{w[i]}")
    

    return actualOutput   

#main code
a = int(input("Enter a value: "))
b = int(input("Enter a value: "))

print(f"a: {a} b: {b} {nandPerceptronModel(a,b)}")





