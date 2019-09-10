# This is a guess the number game.
import random
secretNumber = random.randint(1, 10)
print('I am thinking of a number between 1 and 10.')

# Ask the player to guess 4 times.
for guessesTaken in range(1, 5):
	print('Take a guess.')
	guess = int(input())

	if guess < secretNumber:
		print(str(guess) + ' is too low.')
	elif guess > secretNumber:
		print(str(guess) + ' is too high.')
	else:
		break # This condition is the correct guess.

if guess == secretNumber:
	print('Good job! You guessed correct number in ' + str(guessesTaken) + 'guesses!')
else:
	print('Nope. The number i was thinking of was ' + str(secretNumber))