import random

def isPrime(n):
    if n == 2 or n == 3: return True
    if n < 2 or n % 2 == 0: return False
    if n < 9: return True
    if n % 3 == 0: return False

    r = int(n ** 0.5)
    f = 5

    while f <= r:
        if n % f == 0: return False
        if n % (f + 2) == 0: return False
        f += 6

    return True    

def both(a, b):
    if b % a == 0: return True
    if a % 2 == 0 and b % 2 == 0: return True
    if a % 3 == 0 and b % 3 == 0: return True
    if a % 5 == 0 and b % 5 == 0: return True

    r = int(a ** 0.5)
    f = 5

    while f <= r:
        if a % f == 0 and b % f == 0: return True
        if a % (f + 2) == 0 and b % (f + 2) == 0: return True
        f += 6
    
    return False

def keys():
    primes = [i for i in range(10000, 100000) if isPrime(i)]

    p = random.choice(primes)
    q = random.choice(primes)
    while p == q:
        q = random.choice(primes)

    n = p * q

    func = (p - 1) * (q - 1)

    e = random.randint(9, int(func ** 0.5))
    while both(e, func):
        e = random.randint(9, int(func ** 0.5))

    d = 0
    k = 1
    while d == 0:
        if (func*k + 1) % e == 0: d = int((func*k + 1) / e)
        k += 1

    return (e, n, d)

def encryption(m, e, n):
    c = ((m % n) ** e) % n
    return c

def decryption(c, d, n):
    m = pow(c, d, n)
    return m

print('Введите шифруемое сообщение (число)')
m = int(input())

a = keys()
print('\nКлючи: e = ' + str(a[0]) + ' n = ' + str(a[1]) + ' d = ' + str (a[2]))

c = encryption(m, a[0], a[1])
print('Зашифрованное сообщение: ' + str(c))

m = decryption(c, a[2], a[1]) #долго
print('Расшифрованное сообщение: ' + str(m))
