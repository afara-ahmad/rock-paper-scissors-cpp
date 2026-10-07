#include <iostream>
using namespace std;
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };
struct stRoundInfo {
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	short RoundNumber;
	enWinner RoundWinner;
	string NameWinner;
};
struct stGameResult {
	short GameRound;
	short PlayerWonTimes;
	short ComputerWonTimes;
	short DrawTime;
	enWinner GameWinner;
	string Winner;
};
int RandomNumber(int From, int To) {
	int Rand;
	Rand = rand() % (To - From + 1) + From;
	return Rand;
}
int HowManyRound() {
	int HowManyRound=0;
	do {
		cout << "How Many Round 1 To 10 ? ";
		cin >> HowManyRound;
	} while (HowManyRound < 1 || HowManyRound>10);
	return HowManyRound;
}
enGameChoice GetComputerChoice() {
	return (enGameChoice)RandomNumber(1, 3);
}
enGameChoice ReadPlayerChoice() {
	short Choice;
	do {
		cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice>3);
	return (enGameChoice)Choice;
}
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice) {
		return enWinner::Draw;
	}
	switch (RoundInfo.PlayerChoice) {
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
			return enWinner::Computer;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
			return enWinner::Computer;


	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
			return enWinner::Computer;
	}
		return enWinner::Player1;
}
string WinnerNameInRound(enWinner Winner) {
	string arrWinnerRound[3] = { "Player1","Computer","No Winner" };
	return arrWinnerRound[Winner - 1];
}
string WinnerNAmeInGame(enWinner WinnerGame) {
	string arrGAmeWinner[3] = { "Player1","Computer","No Winner" };
	return arrGAmeWinner[WinnerGame - 1];
}
void SetColorScreen(stRoundInfo RoundInfo) {
	if (RoundInfo.RoundWinner == enWinner::Player1) {
		system("color 2F");

	}
	else if (RoundInfo.RoundWinner == enWinner::Computer) {
		cout << "\a";
		system("color 4F");
	}
	else
		system("color 6F");
}
string ChoiceName(enGameChoice Choice) {
	string arrChoiceName[3] = { "Stone","Paper","Scissors" };
	return arrChoiceName[Choice - 1];
}
void ShowRoundResult(stRoundInfo RoundInfo) {
	cout << "_________________Round [" << RoundInfo.RoundNumber << "]______________\n\n";
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer  Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner " <<"["<< WinnerNameInRound(RoundInfo.RoundWinner)<<"]" << endl;
	cout << "\n" << "________________________________________\n\n";

	SetColorScreen(RoundInfo);
}
enWinner WhoWonTheGame(stGameResult GameResult) {
	if (GameResult.PlayerWonTimes > GameResult.ComputerWonTimes)
		return enWinner::Player1;
	else if (GameResult.PlayerWonTimes < GameResult.ComputerWonTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}
string Tabs(int NumberOfTabs) {
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++) {
		t = t + "\t";
		cout << t;
	}
	return t;

}
void ShowGameOverScreen() {
	cout << Tabs(2) << "______________________________________________________________\n\n";
	cout << Tabs(3) << "+++ G A M E  O V E R +++"  << "\n";
	cout << Tabs(2) << "______________________________________________________________\n";

}
stGameResult FillGameResult(stRoundInfo RoundInfo, short PlayWin, short ComputerWin, short Draw) {
	stGameResult GameResult;
	GameResult.GameRound = RoundInfo.RoundNumber;
	GameResult.PlayerWonTimes = PlayWin;
	GameResult.ComputerWonTimes = ComputerWin;
	GameResult.DrawTime = Draw;
	GameResult.GameWinner = WhoWonTheGame(GameResult);
	GameResult.Winner = WinnerNAmeInGame(GameResult.GameWinner);
	return GameResult;
}
stGameResult PlayGame(short HowManyRound) {
	short PlayWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	stRoundInfo RoundInfo;
	for (short GameRound = 1; GameRound <= HowManyRound; GameRound++) {
		cout << "Round [" << GameRound << "] Begins:",
		cout << "\n\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
		RoundInfo.NameWinner = WinnerNameInRound(RoundInfo.RoundWinner);

		ShowRoundResult(RoundInfo);
		if (RoundInfo.RoundWinner == enWinner::Player1)
			PlayWinTimes++;
		else if (RoundInfo.RoundWinner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;
	}
	return FillGameResult(RoundInfo, PlayWinTimes, ComputerWinTimes, DrawTimes);
}
void ShowFinalGameResult(stGameResult GameResult) {
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________" << endl;
	cout << "Game Rounds   : " << GameResult.GameRound << endl;
	cout << "Player1 Won Times   : " << GameResult.PlayerWonTimes << endl;
	cout << "Computer Won Times   : " << GameResult.ComputerWonTimes << endl;
	cout << "Draw Times   : " << GameResult.DrawTime << endl;
	cout << "Final Winner   : " << GameResult.Winner << endl;
	cout << "\n________________________________________________";
}
void ResetScreen() {
	system("cls");
	system("color 07");
}
void StartGame() {
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		stGameResult GameResult = PlayGame(HowManyRound());
		ShowGameOverScreen();
		ShowFinalGameResult(GameResult);
		cout << "\n";
		cout << "Do You Want TO Play Again ? Y/N ? " << endl;
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
	srand((unsigned)time(NULL));
	
	StartGame();
}