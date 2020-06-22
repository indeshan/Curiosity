#Python program to generate the first N prime numbers

num = int((input("Enter the number of prime numbers required: ")))
count = 0
i = 2
while(count < num):
    isPrime = 1
    for j in range(2,i//2):
        if(i%j == 0):
            isPrime = 0
            break
    if(isPrime == 1):
        print(i)
        count = count + 1
    i = i + 1
