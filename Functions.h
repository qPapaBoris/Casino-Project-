#ifndef FUNCTIONS_FILE
#define FUNCTIONS_FILE

void Rules();
void AddMoney(float* balance, float amount);
void SubtractMoney(float* balance, int bet);
void VerifyWin(char* list[], int first, int second, int third, float* balance, int bet);
int ChanceOfWinning(int num);
void SpinReels(char* list[], float* balance, int bet);
void PlayAgain(float* balance, char* play_again);

#endif //FUNCTIONS_FILE