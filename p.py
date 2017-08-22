from math import floor, sqrt
def fib(n):                                                     
        return int(floor(((1+sqrt(5))**n-(1-sqrt(5))**n)/(2**n*sqrt(5))+0.5))
print fib(4)
print fib(5)
print fib(6)
