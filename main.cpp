#include <iostream>
#include <vector>

std::vector<std::vector<int>> data(3, std::vector<int>(3));

int P1choiceX;
int P1choiceY;
int P2choiceX;
int P2choiceY;

int winner;

void ShowGame(){

	std::cout << "Current game state: \n";


	for(int y = 0; y < 3; y++){
		for(int x = 0; x < 3; x++){
			if(y < data[x].size() && data[x][y] != 0) {
				std::cout << data[x][y];
			} else {
				std::cout << "*";
			}
			std::cout << "   ";
		}
		std::cout << "\n";
		std::cout << "\n";
	}
}

void P1addpiece() {
	std::cout << "Player 1\n";
	std::cin >> P1choiceX;
	std::cin >> P1choiceY;

	if(P1choiceX > 2 or P1choiceX < 0){
		std::cout << "You can not put a piece here\n";
		P1addpiece();
	}

	if(P1choiceY > 2 or P1choiceY < 0){
		std::cout << "You can not put a piece here\n";
		P1addpiece();
	}

	if(data[P1choiceX][P1choiceY] == 0){

		data[P1choiceX][P1choiceY] = 1;
	} else {
		std::cout << "You can not place a piece there, there is already one\n";
		P1addpiece();
	}
}

void P2addpiece(){
	std::cout << "Player 2\n";
	std::cin >> P2choiceX;
	std::cin >> P2choiceY;

	if(P2choiceX > 2 or P2choiceX < 0){
		std::cout << "You can not put a piece here\n";
		P2addpiece();
	}

	if(P2choiceY > 2 or P2choiceY < 0){
		std::cout << "You can not put a piece here\n";
		P2addpiece();
	}

	if(data[P2choiceX][P2choiceY] == 0){

		data[P2choiceX][P2choiceY] = 2;
	} else {
		std::cout << "You can not place a piece there, there is already one\n";
		P2addpiece();
	}
}

int CheckWinner() {
    if(data[0][0] == 1 && data[1][1] == 1 && data[2][2] == 1){
		return 1;
	}
	if(data[0][2] == 1 && data[1][1] == 1 && data[2][0] == 1){
		return 1;
	}

    for (int i = 0; i < 3; i++) {
        if ((data[i][0] == data[i][1] && data[i][1] == data[i][2] && data[i][0] != 0)) {
            return data[i][0];  // Return the winner (1 or 2)
        }
        if ((data[0][i] == data[1][i] && data[1][i] == data[2][i] && data[0][i] != 0)) {
            return data[0][i];  // Return the winner (1 or 2)
        }
    }

    return 0;
}

void GameUpdate() {
	ShowGame();

	for(int TIME = 0; TIME < 9; TIME++){
		P1addpiece();
		ShowGame();
		if(CheckWinner() == 1){
			std::cout << "Player 1 wined\n";
			break;
		}
		P2addpiece();
		ShowGame();
		if (CheckWinner() == 2)
		{
			std::cout << "Player 2 wined\n";
			break;
		}
	}
}

int main() {

	std::cout << "hello world\n";
	GameUpdate();

	return 0;
}
