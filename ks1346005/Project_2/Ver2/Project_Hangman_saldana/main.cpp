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
void problem1();//Guess the letter
void problem2();//Beginner
void problem3();//Moderate Game
void problem4();//Advance Game
void problem5();//Bonus Game

//Bonus Game Functions

void game();
void header();
string stoupper(string s);
void create_hint(string s,string& ss);
void fill_hint(string l , string cw , string& wh,string& uc,int& gr);

bool started = false;
bool play = true;

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
        case 5:    problem5();break;
            
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    
    inFile.close();
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"\n\n\n\n\n********Hangman Game**********"<<endl;
    cout<<" Please choose level of game"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Type 1 for Special(guess the letter)"<<endl;
    cout<<"Type 2 for Beginner"<<endl;
    cout<<"Type 3 for Moderate"<<endl;
    cout<<"Type 4 for Advance"<<endl;
    cout<<"Type 5 for Bonus Game! \n"<<endl;
    
    cout<<"Type anything else to exit game\n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

//-------------------------------------------------------
//Start Game 1(problem 1)!!! Guess the letter
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
//End Game 1(problem 1)!!!

//Start Beginner Game(problem 2)!!!
void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
//}
const int MAX_TRIES=8;

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
//End Beginner Game 2(problem 2)!!!

/* Take a one character guess and the secret word, and fill in the
 unfinished guess word. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */


//Start Moderate Game 3(problem 3)!!!
void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
//}
const int MAX_TRIES=6;

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
//End Moderate Game 3(problem 3)!!!

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */        

//Start Advance Game 4(problem 4)!!!
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


//End Game 4(problem 4)!!!

//Start Bonus Game (problem 5)
void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
/*        
void game();
void header();
string stoupper(string s);
void create_hint(string s,string& ss);
void fill_hint(string l , string cw , string& wh,string& uc,int& gr);
bool started = false;
bool play = true;
*/
//int main()
//{

    string x;

    while(play){
        system("cls");
        header();
        cout << "\"n\" ->New Game"<<endl;
        cout << "\"x\" ->Leave Game"<<endl;
        cin >> x;
        if(x=="x"){
            play = false; //"x" End Game
        }
        if(x=="n"){
            started = true; //"n" To Start New Game 
        }

        if(started){
            game();
        }

    }
    //return 0;
}

void game(){
    char stop;

    //
    int wrong;
    string cword;
    string hword;
    string uchars;
    string letter;

    letter ="";
    wrong = 0;
    uchars = "";
    cword = "hangover";
    cword = stoupper("hangover");
    create_hint(cword , hword);


    //Begin the Game
    while(started){
        //Clear the Console and Place the Header
        system("cls");
        header();

        //Print Hint Word
        cout << "Hint:" << hword << endl;

        //Print Used Characters
        cout << "Used CHARS:"<< uchars << endl;
        cout << "Nope:" << wrong<<endl;

        //Print your Character

        cout << "________" << endl;
        cout << "|     |"<<endl;
        cout << "|     ";
        if(wrong>0){cout<<"O";}
        cout<<endl;
        cout << "|     ";
        if(wrong>1){cout<<"|";}
        cout<<endl;
        cout << "|    ";
        if(wrong>2){cout<<"/";}
        if(wrong>3){cout<<"|";}
        if(wrong>4){cout<<"\\";}
        cout<<endl;
        cout << "|     ";
        if(wrong>3){cout<<"|";}
        cout<<endl;
        cout << "|    ";
        if(wrong>5){cout<<"/";}
        if(wrong>6){cout<<" \\";}
        cout <<endl;
        cout << "|"<<endl;
        cout << "|"<<endl;
        cout << "======================"<<endl;
        if(wrong > 6){
            cout<<"You Lost! Press any key and then ENTER"<<endl;
            cin>>stop;
            started = false;
        }else{
            if(hword == cword){
                cout<<"You won! Press any key and then ENTER"<<endl;
                cin>>stop;
                started = false;
            }else{
            cout << "Enter the letter:";
            cin >> letter ;

            letter = toupper(letter[0]);

            fill_hint(letter , cword , hword , uchars , wrong);
            }
        }

    }
}

void fill_hint(string l , string cw , string& wh,string& uc,int& gr){
    int len;
    string temps;
    int i=0;
    bool e = false;
    len = uc.length();

    while(i < len){
        if(l[0] == uc[i]){
            e=true;
        }
        i++;
    }
    i=0;
    if(e == false){
    uc += l;
    len = cw.length();
    temps = wh;
    while(i < len){
        if(l[0] == cw[i]){
            wh[i] = l[0];
        }
        i++;
    }
    if(temps == wh){
        gr++;
    }
    }
}

void create_hint(string s , string& ss){
    int len;
    len = s.length();
    int i=0;
    string temps;
    temps ="";
    while(i < len){
        temps += "*";
        i++;
    }
	  ss = temps;
}

string stoupper(string s)
	{
	  int len;
	  len = s.length();
	  int i=0;
	  string temps;
	  temps ="";
	  while(i < len){
        temps += toupper(s[i]);
        i++;
	  }
	  return temps;
	}

void header(){
    cout << "===================="<< endl << "Hangman" << endl << "===================="<< endl;
}

//End Bonus Game (problem 5)!!!

//Begin Functions for Class
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