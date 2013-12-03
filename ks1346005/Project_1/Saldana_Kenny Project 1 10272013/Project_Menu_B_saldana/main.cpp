//Author: Kenny Saldana
//Info: Project CIS17A
//Date: 10/25/2013
//Ref:  Menu program taken from Midterm(Author: Dr. Mark Lehr)
//

//Library includes Here!!!
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!

void Menu();
int getN();
void def(int);
void problem1();//Beginner 
void problem2();//Moderate Game
void problem3();//Advance Game
void problem4();//Bonus Game

//Begin Execution Here!!!

int main(int argv,char *argc[]){
    int inN, count;
    string countries[25];
    ifstream inFile;
    inFile.open("countries.txt");
    
    if(!inFile.is_open())
    {
        cout << "File is not open!\n";
    }
    
    for(int i = 0; i < 25 && (!inFile.eof());i++, count++)
    {
        inFile >> countries[i];
    }
    inFile.clear();
    
    for(int i = 0; i < 25 && (!inFile.eof());i++)
    {
        cout << "Country " << i << ": " << countries[i] << endl;
    }
    
    string *temp_string;
    
    //sets the temp_string to a random country name and deletes it
    temp_string = new string(countries[39439493 % count]);
    cout << "Random String: " << *temp_string << endl;
    delete temp_string;
    
    //creates it again and reinitializes it
    temp_string = new string(countries[39439495 % count]);
    cout << "Random String: " << *temp_string << endl;
    
//access index at(index_number) and get length of string pointer
    cout << "Temp_string index: " << temp_string -> at(1)
         << " length: " << temp_string -> length() << endl;
    
    
    delete temp_string;
    
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    
    inFile.close();
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"\n\n\n\n\n********Hangman Game**********"<<endl;
    cout<<" Please choose level of game"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Type 1 for Special"<<endl;
    cout<<"Type 2 for Beginner"<<endl;
    cout<<"Type 3 for Moderate"<<endl;
    cout<<"Type 4 for Bonus Game! \n"<<endl;
    
    cout<<"Type anything else to exit game\n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

//Start special(problem 1)!!!
void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
//}

const int MAX_TRIES=3;

int letterFill (char, string, string&);

//int main ()
//{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
	/*	
                "lizzard",
		"leopard",
		"dolphin",
		"elephant",
		"golpher",
		"falcon",
		"donkey",
		"octopus",
		"monkey",
		"giraffe"
        */
	};

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];

	// Initialize the secret word with the * character.
	string unknown(word.length(),'*');

	// welcome the user
	cout << "\n\nWelcome to Special Hangman...Guess a random letter from a country's Name!";
	//cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the letter.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess another letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Sorry! That letter isn't in there. Please try again." << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Good job!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "\n You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}

	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was: " << word << endl;
	}
	cin.ignore();
	cin.get();
	//return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

/*
int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
*/
//End special(problem 1)!!!

//Start Brginner(problem 2)!!!
void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
//}
const int MAX_TRIES=7;

int letterFill (char, string, string&);

//int main ()
//{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"batman",
		"superman",
		"spiderman",
		"penguin",
		"twoface",
		"wonderwomen",
		"taskmaster",
		"silversurfer",
		"sandman",
		"wolverine"
	};

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];

	// Initialize the secret word with the * character.
	string unknown(word.length(),'*');

	// welcome the user
	cout << "\n\nWelcome to Beginner Hangman...Guess a Super Hero or Villian";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Sorry! That letter isn't in there. Please try again." << endl;
			num_of_wrong_guesses++;
                        //cout << "\n" <<endl;
		}
		else
		{
			cout << endl << "You found a letter! Good job!" << endl;
                        
		}
		// Tell user how many guesses has left.
		
                cout << "\n You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}

	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was: " << word << endl;
	}
	cin.ignore();
	cin.get();
	//return 0;
}
//End Beginner(problem 2)!!!

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */


//Start Moderate(problem 3)!!!
void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
//}
const int MAX_TRIES=7;

int letterFill (char, string, string&);

//int main ()
//{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"lizzard",
		"leopard",
		"dolphin",
		"elephant",
		"golpher",
		"falcon",
		"donkey",
		"octopus",
		"monkey",
		"giraffe"
	};

	//Choose and copy a word from array of words randomly
	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];

	//Initialize the secret word with the * character.
	string unknown(word.length(),'*');

	//Welcome the user
	cout << "\n\nWelcome to Moderate Hangman...Guess the name of an Animal!";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	//Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		//Fill secret word with letter if the guess is correct,
		//Otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Sorry! That letter isn't in there. Please try again." << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Good job!" << endl;
		}
		//Tell user how many guesses has left.
		cout << "\n You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		//Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}

	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was: " << word << endl;
	}
	cin.ignore();
	cin.get();
	//return 0;
}
//End Moderate(problem 3)!!!

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */        

//Bonus Game!!!
void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
//}

const int MAX_TRIES=4;

int letterFill (char, string, string&);

//int main ()
//{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"pontiac",
		"oldsmobile",
		"landrover",
		"packard",
		"porche",
		"edsel",
		"volkswagen",
		"mercedesbenz",
		"studebaker",
		"lincoln"
	};

	//Choose and copy a word from array of words randomly
	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];

	//Initialize the secret word with the * character.
	string unknown(word.length(),'*');

	//Welcome the user
	cout << "\n\nWelcome to Advance Hangman...Guess the name of an Automobile maker!";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	//Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		//Fill secret word with letter if the guess is correct,
		//Otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Sorry! That letter isn't in there. Please try again." << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Good job!" << endl;
		}
		//Tell user how many guesses has left.
		cout << "\n You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		//Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}

	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was: " << word << endl;
	}
	cin.ignore();
	cin.get();
	//return 0;
}        

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}


//End Bonus Game!!!

//Begin functions for class
int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}        