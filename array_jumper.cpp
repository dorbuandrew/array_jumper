// array chaser 
// A simple game inspired by the book this is how you lose the time war by Max Gladstone and Amal El-Mohtar 
// player plays as either blue or red while the computer plays as the other 
//goal of game is to match the 1st 3 coordinates of the pc, while the 4th coordiante can either be +1 or -1 the
 //4th coordiante of the computer

// the libraries used 
#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using namespace std;


// the character class for both the player and computer

class Character {
public:
	string character_name = "green";
	int character_position[4] = { 0,0,0,0 };
	string set_character_name();
	vector<int> character_mover(int field_size);
	vector<int> character_initial_position(vector<int> computer_position, int field_size);
	vector<int> character_ai(vector<int>player_position, int field_size);
	vector<int> computer_initial_position(int field_size);
	void computer_name(string player_name);
};


// function to set player name 

string Character::set_character_name() {
	bool confirm_name = true;
	string player_name;
	string player_name_1;
	while (confirm_name == true) {
		cout << "\n Please enter either r for Red or b for Blue";
		cin >> player_name;
		if (player_name == "b") {
			character_name = "Blue";
			cout << "\n You are named " << character_name;
			player_name_1 = character_name;
			confirm_name = false;
		}
		else if (player_name == "r") {
			character_name = "Red";
			cout << "\n You are named " << character_name;
			player_name_1 = character_name;
			confirm_name = false;
		}
		else {
			"\n invalid Entry. Please Try Again";
		}
	}
	return player_name_1;
}






//function to set computers initial starting position 

vector<int> Character::computer_initial_position(int field_size) {
	int counter = 0;
	vector<int> initial_position(4, 0);
	srand(time(0));
	while (counter < 4) {
		character_position[counter] = (rand() % field_size) + 0;
		initial_position[counter] = character_position[counter];
		counter = counter + 1;
	}
	cout << "\n" << character_name << "s starting position is ";
	cout << character_position[0] << "-";
	cout << character_position[1] << "-";
	cout << character_position[2] << "-";
	cout << character_position[3];
	return initial_position;
}






// function for simple ai to govern the computer's moves 

vector<int> Character::character_ai(vector<int>player_position, int field_size) {
	int computer_position;
	int computer_direction;
	vector<int>computer_move(2, 0);
	if (character_name == "Blue") {
		computer_position = player_position[0] + 1;
		if (computer_position > 3) {
			computer_position = 0;
		}
		computer_direction = player_position[1] - 2;

		character_position[computer_position] = computer_direction + character_position[computer_position];
		if (character_position[computer_position] < 0) {
			character_position[computer_position] = 100;
		}
		cout << "\n Blue's new position is ";
		cout << character_position[0] << "-";
		cout << character_position[1] << "-";
		cout << character_position[2] << "-";
		cout << character_position[3];
	}
	else if (character_name == "Red") {
		computer_position = player_position[0] - 1;
		if (computer_position < 0) {
			computer_position = 3;
		}
		computer_direction = player_position[1] + 2;

		character_position[computer_position] = computer_direction + character_position[computer_position];
		if (character_position[computer_position] > field_size) {
			character_position[computer_position] = 0;
		}
		cout << "\n Reds new position is ";
		cout << character_position[0] << "-";
		cout << character_position[1] << "-";
		cout << character_position[2] << "-";
		cout << character_position[3];
	}
	computer_move[0] = computer_position;
	computer_move[1] = computer_direction;
	return computer_move;
}








//function to set the computers character.name based on the players name 

void Character::computer_name(string player_name) {
	if (player_name == "Blue") {
		character_name = "Red";
		cout << "\n I am " << character_name;
	}
	else {
		character_name = "Blue";
		cout << "\n I am " << character_name;
	}
}



// function for player to set their starting position based on the starting position of the computer 

vector<int>Character::character_initial_position(vector<int> computer_position, int field_size) {
	int player_position;
	int counter = 0;
	string player_position_text[4] = { "1st dimension ", "2nd dimension ", "3rd dimension ", "4th dimension " };
	vector<int> initial_player_move(2, 0);
	while (counter < 4) {
		cout << "\n Please enter your coordinate for the " << player_position_text[counter];
		cin >> player_position;
		if (player_position > computer_position[counter] + 4 and player_position < field_size + 1) {
			character_position[counter] = player_position;
			counter = counter + 1;
		}
		else if (player_position < computer_position[counter] - 4 and player_position>-1) {
			character_position[counter] = player_position;
			counter = counter + 1;
		}
		else {
			cout << "\n Invalid coordinate position. Coordinate must be at least either +5 or -5 of the computers";
			cout << "\n Please try again.";
		}
	}
	return initial_player_move;
}



//function to move player 

vector<int> Character::character_mover(int field_size) {
	bool confirm_position = true;
	bool confirm_direction = true;
	int confirm_direction_number;
	int direction;
	int position;
	vector<int>player_new_position(2, 0);
	while (confirm_position == true) {
		cout << "\n Please choose a dimension.";
		cout << "\n Enter either 0, 1, 2, or 3";
		cin >> position;
		if (position > -1 and position < 4) {
			confirm_position = false;
		}
		else {
			cout << "\n Invalid Position - Please try again.";
			cin >> position;
		}
	}
	while (confirm_direction == true) {
		cout << "\n Please enter a direction either -1, 0, or 1";
		cin >> direction;
		if (direction > 1 or direction < -1) {
			cout << "\n Invalid Direction - Please Try Again.";
			cin >> direction;
		}
		else if (direction == -1 or direction == 0 or direction == 1) {
			confirm_direction_number = character_position[position] + direction;
			if (confirm_direction_number > -1 and confirm_direction_number < field_size + 1) {
				character_position[position] = confirm_direction_number;
				player_new_position[0] = position;
				player_new_position[1] = direction;
				cout << "\n Your new position is ";
				cout << character_position[0] << "-";
				cout << character_position[1] << "-";
				cout << character_position[2] << "-";
				cout << character_position[3];
				confirm_direction = false;
			}
			else if (confirm_direction_number<0 or confirm_direction_number>field_size) {
				cout << "\n Invalid Direction Confirmation - Please Try Again.";
				cin >> direction;
			}
		}
	}
	return player_new_position;
}



// function for determining if player has won 

int win_condition(int p_position[], int c_position[], string p_name) {
	int counter = 0;
	int win_counter = 0;
	while (counter < 4) {
		if (p_position[counter]<c_position[counter] + 3 and p_position[counter]>c_position[counter] - 3) {
			counter = counter + 1;
			win_counter = win_counter + 1;
		}
		else {
			counter = counter + 1;
		}
	}
	if (win_counter >= 4) {
		cout << "\n" << p_name << " has won.";
		return 1;
	}
	else {
		return 0;
	}
}





int main() {
	int field_size = 100;
	int turn_counter = 0;
	string play_again = "n";
	cout << "Welcome to Array Jumper. You are a time-traveling operative on the hunt of a rogue operative across time and space.";
	cout << "\n This game was inspired by the book This is how you lose the timewar by Amal El-Mohtar and Max Gladstone.";
	cout << "\n You must catch the rogue agent before they escape at the end of the 100th turn.";
	cout << "\n In order to win you must get within 2 units of their coordinates before the 100th turn.";
	cout << "\n I.E. if the agents coordinates are 4-4-4-4 You may catch them with a 2-4-4-6 or 6-2-2-4";
	cout << "\n Pretty much any combination between 2-2-2-2 and 6-6-6-6 also including them, as an example.";
	cout << "\n Have fun and best of luck";

	// initializing the rest of the variables and such 
	Character player;
	Character computer;
	string player_name = player.set_character_name();
	computer.computer_name(player_name);
	vector<int> c_initial_position = computer.computer_initial_position(field_size);
	vector<int> p_initial_position = player.character_initial_position(c_initial_position, field_size);
	vector<int> c_ai = computer.character_ai(p_initial_position, field_size);
	vector<int>p_move = player.character_mover(field_size);
	int win = win_condition(player.character_position, computer.character_position, player.character_name);
	while (turn_counter < 101) {
		c_ai = computer.character_ai(p_move, field_size);
		p_move = player.character_mover(field_size);
		win;
		if (win == 1) {
			cout << "\n You have captured " << computer.character_name << " in" << turn_counter << "s";
			cout << "\n Good Job!";
			cout << "\n \n Would you like to play again?";
			cout << " y or n";
			cin >> play_again;
			if (play_again == "y") {
				player_name = player.set_character_name();
				computer.computer_name(player_name);
				c_initial_position = computer.computer_initial_position(field_size);
				p_initial_position = player.character_initial_position(c_initial_position, field_size);
				c_ai = computer.character_ai(p_initial_position, field_size);
				p_move = player.character_mover(field_size);
				win = win_condition(player.character_position, computer.character_position, player.character_name);
				turn_counter = 0;
			}
			else if (play_again != "y") {
				cout << "\n Thanks for playing.";
				cout << "\n This game was made by Andrew Dorbu";
				cout << "\n Email dorbuandrew@gmail.com if you'd like to get in contact.";
				cout << "\n Thanks again for playing.";
				turn_counter = 200;
			}
		}
		if (turn_counter > 100) {
			cout << "\n" << computer.character_name << " has gotten away.";
			cout << "\n Best of luck next time!";
			cout << "\n Would you like to play again?";
			cout << "\n y or n";
			cin >> play_again;
			if (play_again == "y") {
				player_name = player.set_character_name();
				computer.computer_name(player_name);
				c_initial_position = computer.computer_initial_position(field_size);
				p_initial_position = player.character_initial_position(c_initial_position, field_size);
				c_ai = computer.character_ai(p_initial_position, field_size);
				p_move = player.character_mover(field_size);
				win = win_condition(player.character_position, computer.character_position, player.character_name);
				turn_counter = 0;
			}
			else if (play_again != "y") {
				cout << "\n Thanks for playing.";
				cout << "\n This game was made by Andrew Dorbu";
				cout << "\n Email dorbuandrew@gmail.com if you'd like to get in contact.";
				cout << "\n Thanks again for playing.";
				turn_counter = 200;
			}
		}

		turn_counter = turn_counter + 1;
		cout << "\n You have " << 100 - turn_counter << " turns left to catch " << computer.character_name;
	}



	return 0;
}






