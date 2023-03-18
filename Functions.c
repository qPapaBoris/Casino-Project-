#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"

void Rules() {
	printf("The rules for the game are as follows:\n\n");
	printf("The player places a bet to start the game.\n\n");
	printf("The player spins the slot machine, which will randomly display a sequence of 3 objects on the screen.\n\n");
	printf("If the sequence of objects displayed on the screen matches any of the winning combinations listed below, the player wins the corresponding payout : \n\n");
	printf("3x Plums : bet * 1 \n3x Oranges : bet * 1.5 \n3x Cherries : bet * 2.5 \n3x Ingot : bet * 5 \n3x Bell : bet * 8 \n");
	printf("3x Seven : bet * 30\n\n");
	printf("To win a payout, the player must hit 3 objects in a row on the slot machine display.\n");
	printf("If the player doesn't hit any winning combination, the bet is lost.\nThe game ends when the player decides to cash out their winnings or runs out of money to bet.\n\n");
}

void AddMoney(float* balance, float amount) {
	*balance += amount;
	printf("\nYou added %.2f$ to your balance.\nCurrent balance: %.2f$\n", amount, *balance);
}

void SubtractMoney(float* balance, int bet) {
	*balance -= bet;
	printf("You lost %d$.\nCurrent balance : %.2f$\n", bet, *balance);
}

void VerifyWin(char* list[], int first, int second, int third, float* balance, int bet) {
	float amount = 0;
	if (first == second && second == third) {
		switch (list[second][0]) {
		case 'P':
			amount = bet * 1;
			break;
		case 'O':
			amount = bet * 1.5;
			break;
		case 'C':
			amount = bet * 2.5;
			break;
		case 'I':
			amount = bet * 5;
			break;
		case 'B':
			amount = bet * 8;
			break;
		case 'S':
			amount = bet * 30;
			break;
		}
	}
	else {
		SubtractMoney(balance, bet);
		return;
	}
	printf("You won %.2f$\n", amount);
	AddMoney(balance, amount);
}

int ChanceOfWinning(int num) {

	if (num >= 0 && num < 2)
		return 0;
	if (num >= 2 && num < 15)
		return 1;
	if (num >= 15 && num < 25)
		return 2;
	if (num >= 25 && num < 40)
		return 3;
	if (num >= 40 && num < 60)
		return 4;
	if (num >= 60 && num < 85)
		return 5;

}

void SpinReels(char* list[], float* balance, int bet) {

	int first, second, third;

	first = ChanceOfWinning(rand() % 85); second = ChanceOfWinning(rand() % 85); third = ChanceOfWinning(rand() % 85);

	printf("%s %s %s \n", list[first], list[second], list[third]);

	VerifyWin(list, first, second, third, balance, bet);
}

void PlayAgain(float* balance, char* play_again) {
	float amount = 0.0;
	printf("\nEnter the amount you want to add (minimum 10$): ");
	scanf_s("%f", &amount);
	while (amount < 10) {
		printf("\nInvalid amount. Enter the amount you want to add (minimum 10$): ");
		scanf_s("%f", &amount);
	}
	AddMoney(balance, amount);
	*play_again = 'y';
}