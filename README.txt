Author : Toshiki Arita in 5/2014
Written in Netbeans 7.4 and compiled with Cygwin GCC. Makefile included.


Program Usage: mm enable1.txt          

This game is based on a computer hacking mini game in Fallout 3 and Fallout: New Vegas. It resembles the classic game Mastermind.

The objective is to correctly guess the word from a list. Hints are given in how many characters you get correct in your guess. For example, you guess MEND and the correct answer is MIND then you would see 3/4 correct. 


Note - You can use any word bank assuming words have newlines. Simply replace enable1.txt with your own file.


Original post
/*************************************
Description:

The popular video games Fallout 3 and Fallout: New Vegas has a computer hacking mini game[1].

This game requires the player to correctly guess a password from a list of same length words. Your challenge is to implement this game yourself.

The game works like the classic game of Mastermind[2] The player has only 4 guesses and on each incorrect guess the computer will indicate how many letter positions are correct.

For example, if the password is MIND and the player guesses MEND, the game will indicate that 3 out of 4 positions are correct (M_ND). If the password is COMPUTE and the player guesses PLAYFUL, the game will report 0/7. While some of the letters match, they're in the wrong position.

Ask the player for a difficulty (very easy, easy, average, hard, very hard), then present the player with 5 to 15 words of the same length. The length can be 4 to 15 letters. More words and letters make for a harder puzzle. The player then has 4 guesses, and on each incorrect guess indicate the number of correct positions.

Here's an example game:

Difficulty (1-5)? 3
SCORPION
FLOGGING
CROPPERS
MIGRAINE
FOOTNOTE
REFINERY
VAULTING
VICARAGE
PROTRACT
DESCENTS
Guess (4 left)? migraine
0/8 correct
Guess (3 left)? protract
2/8 correct
Guess (2 left)? croppers
8/8 correct
You win!

You can draw words from our favorite dictionary file: enable1.txt[3] . Your program should completely ignore case when making the position checks.
Input/Output:

Using the above description, design the input/output as you desire. It should ask for a difficulty level and show a list of words and report back how many guess left and how many matches you had on your guess.

The logic and design of how many words you display and the length based on the difficulty is up to you to implement.
Easier Challenge:

The game will only give words of size 7 in the list of words.
Challenge Idea:

Credit to /u/skeeto [4] for the challenge idea[5] posted on /r/dailyprogrammer_ideas[6]

/*************************************
http://www.reddit.com/r/dailyprogrammer/comments/263dp1/5212014_challenge_163_intermediate_fallouts/
