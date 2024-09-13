#author @PlatJack
def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n - 1)

n = int(input())
print (factorial(n))

k = 6
j = k + 6
print("aaj khane me kolhapuri paneer milega")
