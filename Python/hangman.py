import random
import string
def hangman():
    print("H A N G M A N")
    word_list = ['python', 'java', 'kotlin', 'javascript']
    test = random.choice(word_list)
    test_l = list(test)
    guess = '-' * len(test)
    guess_l = list(guess)
    attempt = 8
    position = 0
    used_stuff = []  # anything that is inputted goes in this
    check = '-'
    print('\n')
    print(guess)
    while attempt >= 0:
            if attempt != 0:

                if check in guess_l:
                    letter = input('Input a letter: ')

            ### Correct input
                    if letter in (string.ascii_lowercase and test_l) and letter not in used_stuff:
                        for char in test_l:
                            position += 1
                            if letter == char:
                                guess_l.insert(position - 1, letter)
                                guess_l.pop(position)
                            else:
                                pass
                        print('\n')
                        new_s = ''.join(guess_l)
                        print(new_s)
                        position = 0
                        used_stuff.append(letter)

            ### Error 1
                    elif letter in used_stuff:
                        print("You already typed this letter\n")
                        new_s = ''.join(guess_l)
                        print(new_s)

            ### Error 2
                    elif letter not in string.ascii_lowercase and len(letter) == 1:
                        print("It is not an ASCII lowercase letter\n")
                        new_s = ''.join(guess_l)
                        print(new_s)
                        used_stuff.append(letter)

            ### Error 3
                    elif len(letter) != 1:
                        print("You should input a single letter\n")
                        new_s = ''.join(guess_l)
                        print(new_s)

            ### Valid input but not present in the chosen word
                    elif letter not in test_l and letter in string.ascii_lowercase and len(letter) == 1:
                        if attempt > 1:
                            print("No such letter in the word\n")
                            new_s = ''.join(guess_l)
                            print(new_s)
                            used_stuff.append(letter)
                            attempt -= 1
                        elif attempt == 1:  # to prevent guess from outputting on last try
                            print("No such letter in the word")
                            used_stuff.append(letter)
                            attempt -= 1

                elif check not in guess_l:
                    print(f"You guessed the word {test}!\nYou survived!")
                    break

            elif attempt == 0:
                print("You are hanged!")
                break

decission = ''
while decission != 'play' or decission != 'exit':
    decission = input('Type "play" to play the game, "exit" to quit: > ')
    if decission == 'play':
        print()
        hangman()
    if decission == 'exit':
        break