#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void ask_number();
void end_game();

int number = 0;
int guesses = 0;

void init_game() {
    number = rand() % 100 + 1;
    printf("I'm thinking of a number between 1 and 100.\nCan you guess what it is?\n");
    guesses = 0;
    ask_number();
}

void ask_number() {
    int guess;
    printf("Make a guess: ");
    scanf("%d", &guess);
    guesses += 1;

    if(number == guess) {
        printf("\nYou got it! It took you %d guesses.\n", guesses);
        end_game();
        return;
    } 

    if(guess > number) {
        printf("Too high! Try again.\n\n");
    } else if(guess < number) {
        printf("Too low! Try again.\n\n");
    }

    ask_number();
}

void end_game() {
    printf("The game is over, would you like to play again? (y/n): ");
    char answer;
    scanf(" %c", &answer);
    answer = tolower(answer);

    if(answer == 'y') {
        printf("\n");
        init_game();
    } else {
        printf("Thanks for playing!\n");
    }
}

int main()
{
    printf("Welcome to the Guessing Game!\n");
    srand(time(NULL));
    init_game();
    
    return 0;
}