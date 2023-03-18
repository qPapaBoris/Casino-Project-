#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"


int main() {
	Rules();

	char* list[] = { "Plums", "Oranges", "Cherries", "Ingot", "Bell", "Seven" };
	srand(time(NULL));
	float balance = 0;
	int bet;
	char play_again = 'y';

	printf("\n\nWelcome to the slot machine game!\n");

	do {
		printf("\nCurrent balance: %.2f$\n", balance);

		char add_money = 'n';
		printf("\nDo you want to add money to your balance? (y/n) ");
		scanf_s(" %c", &add_money);

		if (add_money == 'y') {
			PlayAgain(&balance, &add_money);
		}

		// Set the bet value
		printf("\nEnter your bet amount: ");
		scanf_s("%d", &bet);

		// Spin the reels
		if (add_money == 'y') {
			do {

				printf("\nDo you want to Spin the reels ? (y/n) ");
				scanf_s(" %c", &play_again);

				if (add_money == 'y')
					SpinReels(list, &balance, bet);

				// Check if player wants to play again
				if (balance < bet) {
					printf("\nYou do not have enough money to continue playing.\n");
					printf("\nDo you want to add money or exit the game? (a/e)");
					scanf_s(" %c", &play_again);

					if (play_again == 'a') {
						PlayAgain(&balance, &play_again);
					}
					else {
						play_again = 'n';
					}
				}


			} while (play_again == 'y' && balance >= bet);
		}


	} while (play_again == 'y');

	printf("\nThanks for playing! Your final balance is %.2f$.\n", balance);

	return 0;

}
