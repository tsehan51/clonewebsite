from words import words
import random

def game():
    w = random.choice(words)
    word = w.upper()
    set1 = set(word)
    set2 = set()
    lives = 10
    lst = list()
    while len(set1) > 0:
        
            
        wordlist = [letter if letter in set2 else '-' for letter in word]
        print('1. Current word:', ' '.join(wordlist))
        print('2. LIVES Left:', lives)
        ty_letter = input('Enter a letter:').upper()
        if ty_letter == 'B': 
            break
        set2.add(ty_letter)               
        if ty_letter in set1:
            set1.remove(ty_letter)            
        else:
            lives = lives - 1         
        print('3. Letter used:', ' '.join(set2))
        if lives == 0:
            break
            print('OUT OF LIVES!!!')
            print('CORRECT ANS:', word)
        if len(set1) == 0:
            print('Congrats!! You have guessed the word:', word)
game()
            
        
        