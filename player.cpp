#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
//#include <Windows.h>
//#include "player.h"

using namespace std;
using hrc = std::chrono::high_resolution_clock;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


void gameover() {
	cout << "You were wrong to think you could ever succeed.\nWhy did you even try?\n";
	exit(0);
}
void exitgame() {
	cout << "Quitting game...\n";
	exit(0);
}


void CharStats(int choice) { //take in stats for classes, return
	vector<int> stats(3);
	if (choice == 1) {     //knight
		stats.at(0) = 50;  //attack
		stats.at(1) = 150; //health
		stats.at(2) = 5;   //agility
	} else if (choice == 2) { //wizard
		stats.at(0) = 150;  //atk
		stats.at(1) = 50;   //def
		stats.at(2) = 10;   //agi
	} else if (choice == 3) { //thief
		stats.at(0) = 75;   //atk
		stats.at(1) = 75;   //def
		stats.at(2) = 15;   //agi
	}
	cout << "Current Stats: \n";
	for (int i = 0; i < 3; i++) {
		if (i == 0) cout << "Strength: " << stats.at(i) << endl;
		if (i == 1) cout << "Health: " << stats.at(i) << endl;
		if (i == 2) cout << "Agility: " << stats.at(i) << endl;

	}
}

void MonsterStats(int x) {
	vector<int> monster;
	if (x == 1) {

	}
	if (x == 2) {
	}
	if (x == 3) {
	}

}

/*void Weaponfunc(int choice, int weapon, string &weaponname, int weaponatk) {
	if (weapon == 2) { // upgrade to weapon 2
		if (choice == 1) {
			weaponname = "Bronze Sword";
			weaponatk = stats.at(0) / 2; // placeholder, 50% of total atk?
		}
		if (choice == 2) {
			weaponname = "Bronze Staff";
			weaponatk = stats.at(0) / 2; //placeholder
		}
		if (choice == 3) {
			weaponname = "Bronze Knife";
			weaponatk = stats.at(0) / 2; //placeholder
		}
	}
}*
void inventory() { //prints out weapon name & atk, num pots, armor etc.

}
*/
void clrScr() {
	cout << "";
}

void reminder() {
	cout << "To make a move use: W, A, S, D" << endl;
}

void dungeonOne() {
	int tries = 3;
	cout << "Welcome to the first dungeon. Begin navigating your way out." << endl;
	cout << "Make your first move: ";
	while (true) {
		char move1;
		cin >> move1;
		if (move1 == 'w' or move1 == 'W') break;

		if (move1 != 'w' or move1 != 'W') {
			cout << "Ghost: You have moved incorrectly. You have " << tries-- << " tries left." << endl;
		}
		if (tries == -1) {
			cout << "Game over. You must be ashamed of yourself...or you really just didn't try." << endl;
			exit(1);
		}
	}
	cout << "";
	cout << "Ghost: You've made a wise move. Continue." << endl;
	cout << "Ghost: Make your second move." << endl;
	while (true) {
		char move2;
		cin >> move2;
		if (move2 == 'd' or move2 == 'D') break;

		if (move2 != 'd' or move2 != 'D') {
			cout << "Ghost: You have moved incorrectly. You have " << tries-- << " tries left." << endl;
		}
		if (tries == -1) {
			cout << "Game over. You must be ashamed of yourself...or you really just didn't try." << endl;
			exit(1);
		}
	}
	cout << "";
	cout << "Ghost: You've yet again made the correct move." << endl;
	cout << "Ghost: Make the final move." << endl;
	while (true) {
		char move3;
		cin >> move3;
		if (move3 == 's' or move3 == 'S') break;

		if (move3 != 's' or move3 != 'S') {
			cout << "Ghost: You have moved incorrectly. You have " << tries-- << " tries left." << endl;
		}
		if (tries == -1) {
			cout << "Game over. You must be ashamed of yourself...or you really just didn't try." << endl;
			exit(1);
		}
	}
}

int main() {

	/*
		clrScr();
		int monsterHealth = 100;
		int monsterAttack = 15;
		int characterHealth = 100;

		cout << "Make your first move against the Taloan Creature." << endl;

		int battleChoice = 0;

		while (true) {
			cout << "1) Hit 2) Defend" << endl;
			cin >> battleChoice;
			while (true) {
				if (battleChoice == 1) {
					cout << "You have hit the Taloan Creature. He now has " << monsterHealth - 20 << " health!" << endl;
					cout << "1) Hit 2) Defend" << endl;
					cin >> battleChoice;
				}
			}
			if (battleChoice == 2) {
				cout << "The Taloan Creature attempted to hit you, but missed." << endl;
			}

			if (monsterHealth == 0) break;

			if (battleChoice < 1 or battleChoice > 2)
				cout << "Not a valid battle choice.";
		}
		*/
	cout << "☂ ☂ Welcome to Rainy Meadows ☂ ☂" << endl;
	//Delay
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(2));

	cout << "Created by: " << endl;
	cout << "Ayesha Mirza and Aaron Benjamin" << endl;

	do {
		cout << "Press ENTER to continue..." << endl;
	} while (cin.get() != '\n');

	cout << "";


	int choice = 0;

	while (true) {
		cout << "►~~~~~~~~~~~~~~~~~~~~~~~◄" << endl;
		cout << "►~CHOOSE YOUR CHARACTER~◄" << endl;
		cout << "►~~~~~~~~~~~~~~~~~~~~~~~◄" << endl << endl;
		sleep_for(nanoseconds(15));
		sleep_until(system_clock::now() + seconds(1));

		//cout << "Press a number for which class you want" << endl;
		cout << "This young knight wishes to prove himself on the battlefield.\n1) ⚔️ Knight ⚔️\n\n";
		cout << "This wizard has travelled from faraway lands in search of knowledge.\n2) ⚡Wizard ⚡\n\n";
		cout << "This thief shouldn't be judged for his accupation or his foul mouth. He actually has a heart of gold. Really. He searches for the ultimate treasure.\n3) 💰 Thief 💰 \n\n";
		cout << "4) Character stats" << endl;

		cin >> choice;

		if (!cin or choice > 5 or choice < 1) {
			cout << "BAD INPUT! QUITTING GAME!" << endl;
			return 0;
		}
		if (choice <= 3 and choice >= 1) break;

//CHOICE 4 SOLUTION I THINK
		if (choice == 4) {
			//cout << "You've chosen more information. Here you will find information on the classes." << endl;
			//Delay
			sleep_for(nanoseconds(15));
			sleep_until(system_clock::now() + seconds(1));
			cout << "Which character do you want to hear more information on?" << endl;

			int info = 0;
			cout << " 1) Knight 2) Wizard 3) Thief ";
			cout << endl;
			cout << endl;

			cin >> info;
			if (!cin or info < 1 or info > 3) {
				cout << "BAD INPUT! QUITTING GAME..." << endl;
				return 0;
			}
			//Information on soldier's stats
			if (info == 1) {
				cout << "";
				cout << "⚔️ Knight Stats ⚔️" << endl;
				cout << "Strength: 50\nHealth: 150\nAgility: 5\n"; //str: 50 health: 150 agi: 5% cap 15% counter skill
				cout << "Starter weapon: Wooden Sword" << endl; //maybe only one weapon
				cout << "Description: Knight's strong determination shows in his unwillingless to fall.";
				cout << "While his attack may be low, he can take hit after hit without flinching\n" << endl;
			}
			//Information on wizard's stats
			if (info == 2) {
				cout << "";
				cout << "Wizard is a low health and armor class but you have the advantage due to the spells you can conduct while in battle." << endl;
				cout << "⚡Wizard's Stats⚡" << endl;
				cout << "Strength: 150\nHealth: 50\nAgility: 10\n"; //str:150, health 50 agi: 10% cap 20%
				cout << "Starter Weapon: Wooden Staff\n";
				cout << "Wizard may be physically weak, but his magic is nothing to scoff at.\n" << endl;
			}
			//Information on dwarf's stats
			if (info == 3) {
				cout << "";
				cout << "💰 Thief Stats 💰" << endl; // health 75 str: 75 chance of dodge agi: 15% cap 25%
				cout << "Strength: 75\nHealth: 75\nAgility: 25\n";
				cout << "Starter Weapon: Dull Knife\n";
				cout << "Thief may appear average, but he's sneaky and has many tricks hidden under his sleeve.\n" << endl;
			}
		}
	}

//ALL FOR SOLDIER CHOICE
	if (choice == 1) {
		cout << "You've chosen Knight!" << endl;
		cout << "Strength: 50\nHealth: 150\nAgility: 5\n";
		cout << "Starter weapon: Wooden Sword" << endl;
		cout << "Would you like more details? (Y/N) ";

		char yes;
		cin >> yes;

		if (yes == 'Y' or yes == 'y') cout << "That's... kind of an invasion of privacy, bro...\n";
		if (yes == 'N' or yes == 'n') {
			cout << "Alright then, onwards you foolish, brave, child!\n";
		}
	}


//ALL FOR WIZARD CHOICE

	if (choice == 2) {
		cout << "You've chosen Wizard!\n";
		cout << "Strength: 150\nHealth: 50\nAgility: 10\n";
		cout << "Starter Weapon: Wooden Staff" << endl;
		cout << "Would you like more details? (Y/N) ";

		char yes;
		cin >> yes;

		if (yes == 'Y' or yes == 'y') cout << "That's... kind of an invasion of privacy, bro...\n";

		if (yes == 'N' or yes == 'n') {
			cout << "Very well - Lead the path to probably useless knowledge!\n";
		}
	}
//ALL FOR DWARF CHOICE
	if (choice == 3) {
		cout << "You've chosen Thief! AKA\n";
		cout << "Strength: 75\nHealth: 75\nAgility: 15\n";
		cout << "Starter Weapon: Dull Knife\n";
		cout << "Would you like more description? (Y/N) ";

		char yes;
		cin >> yes;

		if (yes == 'Y' or yes == 'y') cout << "That's... kind of an invasion of privacy, bro...\n";

		if (yes == 'N' or yes == 'n') {
			cout << "Well, let's go raid that villa- dungeon!\n";
		}
	}


	cout << "Please enter your character's name: ";
	string name;
	cin >> name;
	cout << "Is " << name << " correct?\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(1));
	cout << "Too bad, you're stuck with it.\n";

	char ready;
	cout << "Ready to begin? (Y/N)\n ";
	cin >> ready;
//added in exit
	if (ready == 'Y' or ready == 'y') {
		clrScr();
	} else if (!cin or ready != 'Y' or ready != 'y') exitgame();

	CharStats(choice);
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	clrScr();

	//cout << "Elderly Woman: You're a new face around town. I don't believe we've met. What's your name?" << endl;
	cout << "Elderly Woman: Ahh " << name << ". Welcome to Rainy Meadows. My name is Johanne but the townspeople always call me Grandma." << endl;
//Delay
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(1));

//Delay
//sleep_for(nanoseconds(15));
//sleep_until(system_clock::now() + seconds(2));
	int reason = 0;
	while (true) {
		cout << "Grandma: So what brought you to Rainy Meadows, " << name << "?" << endl;

		cout << "1) I'm here for treasure 2) I'm here to make Rainy Meadows a safer place" << endl;
		cin >> reason;
		if (!cin or reason < 1 or reason > 2) {
			cout << "Grandma: I have bad hearing you'll have to speak up." << endl;
			return 1;
		}
		if (reason == 1 or reason == 2) break;
	}
	if (reason == 1) {
		cout << "Grandma: Ahh well many have tried and many have failed. Either way, I still wish you the best of luck in that." << endl;
	}
	if (reason == 2) {
		cout << "Grandma: Aww well you seem like you're well equipped for the job with your " << "filler" << " getup and all." << endl;
	}
//seperate arrows doesn't seem to change anything
//Delay
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	cout << "Grandma: Whatever the intentions of your journey, I intend to help you in whatever way I can." << endl;

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	cout << "Grandma: There's these dungeons around Rainy Meadows that are extremely tough to get through." << endl;

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	cout << "Grandma: Because I've lived here for so long, the explorers and treasure hunters that made it out alive have told the townspeople directions they took." << endl;

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	cout << "Grandma: Here's some directions explorer William McJeffries gave me when he passed through town." << endl;

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	cout << "Grandma: When you first enter, you'll need to go forward (w) and then I believe you make a right (d) and then you go down (s)." << endl;

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	cout << "Grandma: Hopefully you got all that." << endl;

	cout << "Setting: You dash out the door without thanking grandma for directions and trot the the first dungeon with this new knowledge you have gained." << endl;

	do {
		cout << "Press ENTER to continue..." << endl;
	} while (cin.get() != '\n');


	/*enter dungeon
		cout dungeon name
		if != w then monster
			if 3 wrong die


	if monster hits
		health - 10
			wizard uses skill
			health +5
			if health ==0; gameover
	*/

	clrScr();
	reminder();
	dungeonOne();
	cout << "Setting: After making your final move, you dash into a large room to spot a large creature with an enormous stinger on its head with red beating eyes staring down at you." << endl;
	cout << "You ready yourself to fight." << endl;
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(2));


}

