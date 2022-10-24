/*
Carter Theesfeld
C++ Fall 2022
Due October 14, 2022
Lab 5 Random Number Guessing Game
Description: Write a number-guessing game in which the computer selects a random 
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At 
the end of each game, users should be told whether they won or lost, and then be asked 
whether they want to play again. When the user quits, the program should output the 
total number of wins and losses. To make the game more interesting, the program 
should vary the wording of the messages that it outputs for winning, for losing, and for 
asking for another game. Create 10 different messages for each of these cases, and use 
random numbers to choose among them. This application should use at least one Do-
While loop and at least one Switch statement. Write your C++ code using good style and 
documenting comments. You should use functions in your code as well. Your source 
code file should be called Lab5.cpp. 
*/
#include <iostream>
#include<string>
using namespace std;


//precondition: the randomNum varible exists. 
//postcondition:there is a value now assigned to the varible.
void RandomNumToGuess(int& randomNum);
//precondition: there is a terminal to output to.
//postcondition: there is now a heading describing the program.
void Heading();
//precondition: includes iostream. The user has a keyboard to type the number they want.
//postcondition: the number the user choses is saved and used in the program.
void UserInput(int& userGuess, int randomNum, int attempt, int& losses, int& wins, int correctStatment, int incorrectStatment, int finalStatment);
//precondition: The user typed in a number in UserInput. CorrectStatment,WrongGuess, and IncorrectLastStament exist and have switch statments.
//postcondition: The guess is checked if correct and the type of statment is figured out.
void CheckGuess(int& userGuess, int randomNum, int attempt, int& losses, int& wins, int correctStatment, int incorrectStatment, int finalStatment);
//precondition:the guess the user made matches the random number.
//postcondition:there is now a statment staying that you won.
void CorrectStatment(int& correctStatment);
//precondition: the user typed in the wrong number and the attemp number is not 20
//postcondition: a statment is outputed and the user gets to try again
void WrongGuess(int& incorrectStatment, int userGuess);
//precondition: the user typed in the wrong number and the attempt is 20
//postcondition: a statment is printed to tell them they lost
void IncorrectLasStatment(int& finalStatment);
//precondition: the rest of the program ran and the user has won or lost
//postcondition:the user can now type that they want to play again or not
void RunAgainQuestion(string& userAnswe, bool& runAgain);
//precondition:the user typed YES, NO, or something else
//postcondition:the user will be sent back to the runAgainQuestion, the program will close, or run again.
void RunAgainSolver(string& userAnswer, bool& runAgain);
//precondition:the user ran the program and won or lost
//postcondition:the score is outputed and the program ends
void Results(int wins, int losses);

int main()
{
	bool runAgain = true;
	int wins = 0;
	int losses = 0;
	int attempt = 1;
	int randomNum = 0;
	int userGuess = 0;
	int correctStatment = 0;
	int incorrectStatment = 0;
	int finalStatment = 0;
	string userAnswer;
	srand(time(0));
	do 
	{
		RandomNumToGuess(randomNum);
		//cout << randomNum << endl;
		Heading();
		UserInput(userGuess, randomNum, attempt, losses,wins,correctStatment, incorrectStatment, finalStatment);
		RunAgainQuestion(userAnswer, runAgain);
	} while (runAgain == true);

	Results(wins,losses);
	return 0;
}

void RandomNumToGuess(int& randomNum)
{
	randomNum = 1 + (rand() % 100);
}
void Heading()
{
	cout << "welcome to the Number guessing game!" << endl;
	cout << "The rules are simple. Type a number between 1 and 100. You have 20 guesses to get it right. Good Luck." << endl;

}
void UserInput(int& userGuess, int randomNum, int attempt, int& losses, int& wins, int correctStatment, int incorrectStatment, int finalStatment)
{
	cout << "Please type in a number from 1-100: ";
	cin >> userGuess;
	if (userGuess > 100 || userGuess < 1)
	{
		cout << "The number has to be from 1-100! Try again." << endl;
		UserInput(userGuess, randomNum, attempt, losses, wins, correctStatment, incorrectStatment, finalStatment);
	}
	CheckGuess(userGuess, randomNum, attempt, losses, wins, correctStatment, incorrectStatment, finalStatment);

}
void CheckGuess(int& userGuess, int randomNum,int attempt, int& losses, int& wins, int correctStatment, int incorrectStatment, int finalStatment)
{
	
	if (userGuess == randomNum)
	{
		CorrectStatment(correctStatment);
		wins++;
	}
	else if (userGuess != randomNum && attempt == 20)
	{
		IncorrectLasStatment(finalStatment);
		losses++;
	}
	else if (userGuess != randomNum)
	{
		WrongGuess(incorrectStatment, userGuess);
		attempt++;
		//cout << "This is attempt " << attempt << endl;
		UserInput(userGuess, randomNum, attempt, losses, wins, correctStatment, incorrectStatment, finalStatment);
	}
	
}
void CorrectStatment(int& correctStatment)
{
	correctStatment = 1 + (rand() % 10);
	//cout << correctStatment << endl;
	switch (correctStatment)
	{
		case 1:
			cout << "Nice job you guessed the correct number." << endl;
			break;
		case 2:
			cout << "I am suprised you got the answer. " << endl;
			break;
		case 3:
			cout << "Did you cheat?? There is no way you got the right answer." << endl;
			break;
		case 4:
			cout << "Man... I thought you wouldn't get the answer right... I'll make it harder next time." << endl;
			break;
		case 5:
			cout << "Dude how did you do that! There is no way you got it right!" << endl;
			break;
		case 6:
			cout << "Cool you guessed the right number." << endl;
			break;
		case 7:
			cout << "You must be a lucky person." << endl;
			break;
		case 8:
			cout << "Hmmmmmmmm looks like you guessed the right number." << endl;
			break;
		case 9:
			cout << "Cool Man Cool. You guessed the right number." << endl;
			break;
		default:
			cout << "The number you guessed is correct." << endl;
			break;

	}
}
void WrongGuess(int& incorrectStatment, int userGuess)
{
	incorrectStatment = 1 + (rand() % 10);
	//cout << incorrectStatment << endl;
	switch (incorrectStatment)
	{
	case 1:
		cout << "OOOO try again." << endl;
		break;
	case 2:
		cout << "How about you give it another try" << endl;
		break;
	case 3:
		cout << "That is not the right number." << endl;
		break;
	case 4:
		cout << "I hope you get it next time" << endl;
		break;
	case 5:
		cout << "Give it another shot." << endl;
		break;
	case 6:
		cout << "Choose a different number" << endl;
		break;
	case 7:
		cout << "Come'on you got it this time." << endl;
		break;
	case 8:
		cout << "You really thought it was " << userGuess << " hahaha no" << endl;
		break;
	case 9:
		cout << "I believe in you. You got it next time" << endl;
		break;
	default:
		cout << "Your guess was incorrect" << endl;
		break;

	}
}
void IncorrectLasStatment(int& finalStatment)
{
	finalStatment = 1 + (rand() % 10);
	//cout << finalStatment << endl;
	switch (finalStatment)
	{
	case 1:
		cout << "Looks like you didn't figure it out." << endl;
		break;
	case 2:
		cout << "Maybe next time... Oh wait there is no next time." << endl;
		break;
	case 3:
		cout << "Sorry, but you lost." << endl;
		break;
	case 4:
		cout << "And that was your last try. Way to go you got it wrong." << endl;
		break;
	case 5:
		cout << "Why did you think that was the right answer." << endl;
		break;
	case 6:
		cout << "Thats embarrassing. You lost." << endl;
		break;
	case 7:
		cout << "I can't believe you wasted your last guess on that." << endl;
		break;
	case 8:
		cout << "Man your last guess must have been a Hail Mary. To bad you still lost" << endl;
		break;
	case 9:
		cout << "Well... You lost" << endl;
		break;
	default:
		cout << "You lost, but I hope you still had fun." << endl;
		break;

	}
}
void RunAgainQuestion(string& userAnswer, bool& runAgain)
{
	cout << "Would you like to play again?" << endl;
	cout << "If you want to play again type YES or else Type NO to quit. Please type your answer in all caps." << endl;
	cin >> userAnswer;
	RunAgainSolver(userAnswer, runAgain);
}
void RunAgainSolver(string& userAnswer, bool& runAgain)
{
	if (userAnswer == "NO")
	{
		runAgain = false;
	}
	else if (userAnswer == "YES")
	{}
	else
	{
		cout << "Please type YES or NO and make sure it is in all caps.";
		RunAgainQuestion(userAnswer, runAgain);
	}
}
void Results(int wins, int losses)
{
	cout << "Your final score is " << wins << " wins and " << losses << " losses." << endl;
	cout << "Have a great day!";
}