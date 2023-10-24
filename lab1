import math

x = 100
if (x>=3.6): #если радианы больше радиан 360 градусов, идет вычетание в обратную сторону
    while (x>=3.6):
        x = x-3.6

e = 0.1 ** 52
q=x
sin = 0.0
n = 1
def factor(k):
    if (k==0):
        return 1
    else:
        return(factor(k-1)*k)


while (abs(q)>e): #т.е больше бесконечно малого числа с заданной величиной
    q = (((-1) ** (n//2)) * (x**n))/factor(n)
    sin = sin+q
    n=n+2
    t = math.sin(x)
print("Ряд тейлора заданных градусов равен:", sin)
