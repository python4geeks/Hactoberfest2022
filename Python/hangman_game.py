import random
movies = ['hungama', 'dhamaal', 'genius']
chosen_word = random.choice(movies)
display = ['_' for i in range(len(chosen_word))]
print(display)
while('_' in display):
    guess = input('Enter a letter : ').lower()
    for i in range(len(chosen_word)):
        if chosen_word[i] == guess:
            display[i] = guess
    print(display)
print('\nYou WIN')
