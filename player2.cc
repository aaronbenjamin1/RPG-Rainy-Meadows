#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <ctime>
#include <cstdlib>
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
void CharStats(int choice, int &hp, int &atk) { //take in stats for classes, return. need to add/mess w agi later
	if (choice == 1) {     //knight
		atk = 50;  //attack
		hp = 150; //health
	} else if (choice == 2) { //wizard
		atk = 150;  //atk
		hp = 50;   //def
	} else if (choice == 3) { //thief
		atk = 75;   //atk
		hp = 75;   //def
	}
	cout << "Current Stats: \n";
	cout << "Strength: " << atk << endl;
	cout << "Health: " << hp << endl;
}
int MonsterStats(int x, int &strength, int &health) {
	if (x == 1) { //beast
		strength = 45;
		health = 15;
	}
	if (x == 2) {
		strength = 15;
		health = 45;
	}
	if (x == 3) {  //animated corpse
		strength = 30;
		health = 30;
	}
	return 0;
}
void clrScr() {
	cout << "";
}
void reminder() {
	cout << "To make a move use: W, A, S, D" << endl;
}
void dungeonOne() {
	int tries = 3;
	cout << "You enter the first floor of the dungeon. In front of you is a floating specter. It watches with empty, eerie eyes.\n";
	cout << "It begins to speak, slowly, and the words are raspy, as if it's throat was injured before its death.\n";
	cout << "Floating Specter: \"...I am the guide bound to this dungeon.\"\n";
	cout << "Specter: \"The dungeon will soon temporarily blind you. You may only go the wrong way three times, or the dungeon will consume you.\"\n";
	cout << "Which way will you go?\n";

	while (true) {
		char move1;
		cin >> move1;
		if (move1 == 'w' or move1 == 'W') break;

		if (move1 != 'w' or move1 != 'W') {
			cout << "Specter: \"...You've gone the wrong way.\"\nYou have " << tries-- << " tries left." << endl;
		}
		if (tries == -1) gameover();
	}
	cout << "";
	cout << "Specter: \"You've made a wise move. Continue.\"\n";
	cout << "Specter: \"Now, make your second decision.\"\n";
	while (true) {
		char move2;
		cin >> move2;
		if (move2 == 'd' or move2 == 'D') break;

		if (move2 != 'd' or move2 != 'D') {
			cout << "Specter: \"...You've gone the wrong way.\"\nYou have " << tries-- << " tries left." << endl;
		}
		if (tries == -1) gameover();
	}
	cout << "";
	cout << "Specter: \"You've yet to fail.\"\n";
	cout << "Specter: \"Now, your final decision.\"\n";

	while (true) {
		char move3;
		cin >> move3;
		if (move3 == 's' or move3 == 'S') break;

		if (move3 != 's' or move3 != 'S') {
			cout << "Specter: \"...You've gone the wrong way.\"\nYou have " << tries-- << " tries left." << endl;
		}
		if (tries == -1) gameover();
	}
}

void dungeonTwo() {
	int tries = 6;
	cout << "Your tries have been replenished!" << endl;

	cout << "Ghost: This game is similar to that kids game hangman. Think about it and guess a few words you have in mind." << endl;

	string hangman = "grandma";

	cout << "Guess the word by guessing some letters. You have 6 attempts." << endl;

	cout << "Ghost: Remember that hint grandma gave you." << endl;

	do {
		cout << "Press ENTER to continue..." << endl;
	} while (cin.get() != '\n');

	cout << "";

	string guess = "grandma";

	while (true) {
		cout << "Make a guess. It's a 7 letter word and it's a woman you always talk to." << endl;

		cin >> guess;

		if (guess == "grandma" or guess == "GRANDMA") {
			cout << "Correct!" << endl;
			break;
		} else cout << "Incorrect. You have " << tries-- << " tries left." << endl;

		if (tries == -1) gameover();
	}
}

void dungeonThree() {

	int tries = 15;
	srand(time(0));
	int target = rand() % 100 + 1;
	int guess = 0;

	while (guess != target) {
		cout << "Please guess a number:" << endl;
		cin >> guess;

		if (!cin) {
			cout << "Specter: It's numbers...not words or letters. It's over for you honestly." << endl;
			gameover();
		}
		if (guess == 0) {
			cout << "Input numbers 1-100" << endl;
		}

		if (guess > target) {
			cout << "Too high! " << "You have " << tries-- << " tries remaining!" << endl;
		}

		if (guess < target) {
			cout << "Too low! " << "You have " << tries-- << " tries remaining!" << endl;
		}

		if (guess == target) {
			cout << "Correct!" << endl;
			break; //was exit(1); testing this
		}

	}
}

void dungeonFour() {

	int tries_remaining = 5;
	string pass = "specter";

	while (true) {
		cout << "Guess this dungeon's password and you will be given its riches and pushed to a boss battle." << endl;
		string guess;
		cin >> guess;
		if (guess == pass) {
			cout << "ACCESS GRANTED TO DUNGEON FOUR!" << endl;
			break;
		}
		tries_remaining--;
		cout << "Tries remaining: " << tries_remaining << endl;
		if (!tries_remaining) {
			cout << "Specter: Sorry chief. It's over." << endl;
			gameover();
		}
		if (!cin) {
			cout << "Specter: That's not a word." << endl;
			cin.clear();
			string s;
			cin >> s;
			continue;
		}

	}

}

void dungeonFive() {

	cout << "What's 5 x 4?" << endl;
	int a = 0;
	cin >> a;
	if (a == 20) {
		cout << "That's right!" << endl;
	} else gameover();

}


void MonsterBattle(int x, int charatk, int &charhp) { //x is monster type from MonsterStats, which will be declared in main ea time both functions are used
	int monsterhp = 0;                              // charatk will remain same, but charhp should not
	int monsteratk = 0;
	MonsterStats(x, monsteratk, monsterhp);
	int battleChoice = 0;
	charatk /= 2;
	monsteratk /= 2;

	srand(time(0));
	monsteratk = rand() % monsteratk;

	while (true) {
		cout << "A boss has appeared!\n"; //i think i just accidentally pokemon'd oops -- lol who cares its dope
		cout << "1) Hit\n2) Defend\n";
		cin >> battleChoice;
		if (battleChoice == 1) {
			monsterhp -= charatk;
			cout << "You hit the boss. It now has " << monsterhp << " health!" << endl;
			if (monsterhp < 1) {
				charhp -= monsteratk;
				cout << "You were hit by the boss. Health is now " << charhp << endl;
			}
		}
		if (battleChoice == 2) {
			cout << "The boss attempted to hit “ << name << “ but missed." << endl;
		}
		if (monsterhp < 1) break;

		if (!cin or battleChoice < 1 or battleChoice > 2)
			cout << "Not a valid battle choice.";

	}
}

int main() {

	int charatk = 0;
	int charhp = 0;

	cout << "☂ ☂ Welcome to Rainy Meadows ☂ ☂" << endl;
	//Delay
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(2));

	cout << "Created by: " << endl;
	cout << "Ayesha Mirza and Aaron Benjamin" << endl;

	do {
		cout << "Press ENTER to continue..." << endl;
	} while (cin.get() != '\n');

	clrScr();


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
		cout << "This thief shouldn't be judged for his occupation or his foul mouth. He actually has a heart of gold. Really. He searches for the ultimate treasure.\n3) 💰 Thief 💰 \n\n";
		cout << "4) Character stats" << endl;

		cin >> choice;

		if (choice <= 3 and choice >= 1) break;
	}
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
			cout << "";
			cout << "⚔️ Knight Stats ⚔️" << endl;
			cout << "Strength: 50\nHealth: 150\nAgility: 5\n"; //str: 50 health: 150 agi: 5% cap 15% counter skill
			cout << "Starter weapon: Wooden Sword" << endl; //maybe only one weapon
			cout << "Description: Knight's strong determination shows in his unwillingless to fall.";
			cout << "While his attack may be low, he can take hit after hit without flinching\n" << endl;
		}
		//Information on wizard's stats
		if (info == 2) {
			cout << "";
			cout << "Wizard is a low health and armor class but you have the advantage due to the spells you can conduct while in battle." << endl;
			cout << "⚡Wizard's Stats⚡" << endl;
			cout << "Strength: 150\nHealth: 50\nAgility: 10\n"; //str:150, health 50 agi: 10% cap 20%
			cout << "Starter Weapon: Wooden Staff\n";
			cout << "Wizard may be physically weak, but his magic is nothing to scoff at.\n" << endl;
		}
		//Information on dwarf's stats
		if (info == 3) {
			cout << "";
			cout << "💰 Thief Stats 💰" << endl; // health 75 str: 75 chance of dodge agi: 15% cap 25%
			cout << "Strength: 75\nHealth: 75\nAgility: 25\n";
			cout << "Starter Weapon: Dull Knife\n";
			cout << "Thief may appear average, but he's sneaky and has many tricks hidden under his sleeve.\n" << endl;
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
		cout << "You've chosen Thief!\n";
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

	CharStats(choice, charhp, charatk);
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));

	clrScr();
	cout << "After days of searching, " << name << " has finally reached Rainy Meadows, a small town located near an infamous dungeon.\nThe town is small, almost identical buildings in neat rows. One house is a little different, a porch at the entrance where an old woman sits on a chair.";
	cout << " \nShe's slowly stroking a small fluffy cat as she fiddles with a small contraption of some sort with her other hand.\n\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(5));
	cout << "She looks up as " << name << " approaches, and smiles warmly.\nElderly Woman: \"Hello!\" She greets warmly \"Welcome to Rainy Meadows. My name is Johanne, but please, call me Grandma. And you are?\"\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(7));

	int reason = 0;
	while (true) {
		cout << "Grandma: \"" << name  << "? Well, what brings you to our peaceful town?\"\n\n";
		cout << "1) I've come to clear the dungeon and defeat the beast that has harmed so many.\n2) I'm here in search of knowledge\n";
		cout << "3) Heard there was a new dungeon 'round here, just lookin around, " << name << " says, quietly slipping a gleaming stone in one of many pockets.\n";
		cin >> reason;
		if (!cin or reason < 1 or reason > 3) {
			cout << "Grandma: \"Sorry, I need you to leave my home.\"\n";
			return 1;
		}
		if (reason == 1 or reason == 2 or reason == 3) break;
	}
	if (reason == 1) {
		cout << "Grandma:  \"I wish you well in your endeavor; this beast has plagued us for many months now.\"\n";
	}
	if (reason == 2) {
		cout << "Grandma: \"A worthy goal. I hope knowledge will never fail you.\"\n";

	}
	if (reason == 3) {
		cout << "Grandma: \"... I do hope you enjoy your stay.\"\n";

	}

	//Delay
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(5));


	cout << "Grandma: \"When you enter the first floor of the dungeon, you will be temporarily blinded.\"\n";
	cout << "Grandma: \"However, the previous explorers who sought to destroy this dungeon have left directions for any who will come after them.\"\n";

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(5));

	cout << "Grandma: \"I'm sure you'll be able to memorize it easily, so I won't write it down for you.\"\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(4));
	cout << "Grandma: \"First, you'll go straight, then take a right, then finally go back once.\nUnderstand?\"\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));
	cout << "Grandma: \"Alright, it's straight(w), right(d), and then back(s).\"\n";

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(4));


	cout << "After receiving the directions from Grandma, " << name << "heads to the dungeon's first floor.\n";

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(2));

	char go;
	while (true) {
		cout << "Are you ready to continue? Y/N" << endl;
		cin >> go;
		if (go == 'y' or go == 'Y') {
			cout << "Very well onwards!" << endl;
			break;
		} else gameover();
	}




	clrScr();
//	reminder();

	dungeonOne();

	cout << "As " << name << " readjusts to regaining his sight, a chill travels down his spine.\n";
	cout << "Light shines from above, illuminating the large room " << name << " has found himself in.\n";
	cout << "There are patches of grass spread across the dirt floor, and the beads of moisture on them shine in the light.\n";
	cout << "The blades of grass sway in a gentle breeze, and all of these combined give the room a peaceful air.\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(4));
	cout << "But " << name << " is in a dungeon, and this calm should not be here.\nAs soon as he thinks that, a loud rumble resounds\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(2));
	cout << "Through an opening that “ << name << “  did not see before, a creature emerges. It has large jaws, with jagged teeth, and somewhat resembles an angler fish.\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(2));
	cout << name << " does not think it would taste good.\n";

	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(2));

	cout << name << " raises his weapon, readying himself to fight.\n";
	sleep_for(nanoseconds(15));
	sleep_until(system_clock::now() + seconds(3));


	int x = 1;
	MonsterBattle(x, charatk, charhp);


	clrScr();

	cout << "You've successfully defeated the first boss and you run back to grandma's." << endl;

	cout << "Grandma tells you about how the second dungeon requires the name of a person you talk to frequently in the game in order to pass it." << endl;

	dungeonTwo();

	MonsterBattle(x, charatk, charhp);

	cout << "You defeat the second boss and run back to grandma's again." << endl;
	cout << "Grandma tells you that you've that it's known as the dungeon of random where you have to guess numbers to get passed it." << endl;

	dungeonThree();

	MonsterBattle(x, charatk, charhp);

	cout << "You defeat the third boss and run back to grandma's for the third time." << endl;
	cout << "Grandma tells you that the next dungeon is where you have to guess the password. The password has something to do with a thing that follows you around in dungeons." << endl;

	dungeonFour();

	MonsterBattle(x, charatk, charhp);

	cout << "You run back to grandma's and tell her you defeated the boss of the fourthe dungeon and are ready for the final dungeon." << endl;
	cout << "She tells you that you need to know your times tables." << endl;

	dungeonFive();

	MonsterBattle(x, charatk, charhp);

}

