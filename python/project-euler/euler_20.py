
def factorial(num):
	factorial = 1
	# check if the number is negative, positive or zero
	if num < 0:
		print("Sorry, factorial does not exist for negative numbers")
	elif num == 0:
		return 1
	else:
		for i in range(1,num + 1):
			factorial = factorial*i
	return factorial

ex = factorial(100)
s = 0
print(ex)
while ex > 0:
	rem = ex % 10
	ex = ex//10
	s += rem 
print(s)