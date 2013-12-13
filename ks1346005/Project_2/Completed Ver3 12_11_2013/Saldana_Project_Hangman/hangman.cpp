/* 
 * File:   hangman.cpp
 * Author: Kenny Saldana
 * Info: Project CIS17A - Project ver2
 * Date: 12/09/2013
 *
 * Created on December 9, 2013, 1:12 PM
 */

#include <cstdlib>
#include <iostream>

#include "hangman.h"

//Ctor and Dtor
HANGMAN::HANGMAN(){
  
    SetConsoleTitle ("Hangman v3");
    hStdout = GetStdHandle (STD_OUTPUT_HANDLE);
  
    exitGame = false;
    inGame = false;
 
    lenofFile = CountLinesOfFile ("words.txt"); //Count lines
    CreateWordsBuf (lenofFile, "words.txt");    //Allocate and store them
  
    srand (time(NULL)); //Seed for picking element index from _wordsBuf
  
    CreditsIntro();
  
}
HANGMAN::~HANGMAN(){
    //Deallocate
    delete[] _wordsBuf;
    _wordsBuf = NULL;
  
    delete[] _hiddenWord;
    _hiddenWord = NULL;
  
    delete[] _letterBuf;
    _letterBuf = NULL;
}
 
void HANGMAN::Set_exitGame (bool b){ //Flag for the main loop    
    exitGame = b;
}
bool HANGMAN::Get_exitGame(){
    return exitGame;
}
void HANGMAN::Set_inGame(bool b){    //Flag for inside game loop
    inGame = b;
}
bool HANGMAN::Get_inGame (){
    return inGame;
}
 
void HANGMAN::ClearScreen(){  //Clears the screen in radius {80,30}
    COORD homeCoords = {0,0};
 
 
    //{80,30} is enough to clear the previous game
    SetConsoleCursorPosition (hStdout, homeCoords);
    for (int row = 0; row < 30; row++){
        for (int col = 0; col < 80; col++){
            cout << ' ';
        }
    }
    SetConsoleCursorPosition (hStdout, homeCoords);
}
void HANGMAN::CreditsIntro(){ //
    COORD dotsCoords = {0,2};
    int tip = rand() % 2;
 
    cout << "Hangman" << endl << endl;
 
    //
    cout << endl << endl << "Let's Play Hangman!!!!" << endl;
    switch (tip){
        case 0:
            cout << "Separate the word's in the text file with a whitespace.";
            break;
        case 1:
            cout << "Don't let your user see the word's from the text file.";
            break;
    }
  
    //Output 3 dots with short delay, clear and output again
    SetConsoleCursorPosition (hStdout, dotsCoords);
    for (int i = 0; i < 2; i++){
        cout << "."; Sleep (500);
        cout << "."; Sleep (500);
        cout << "."; Sleep (500);
        cout << '\r' << "   ";
        cout << '\r';  Sleep(500);
    }
  
    ClearScreen();
}
  
int HANGMAN::CountLinesOfFile (const char* fname){ //Counts number of words in .txt file
  
    int n = 0;
    string word;
 
    //Trouble shoot this loop --> having issues at this point; Currently resolved
    ifstream file (fname);
    
    file.clear();
        
    if(file.fail()){
        cout << "\nFail flag is true\n";
    }
    
    if(file.is_open()){
        cout << "\nFile is open\n";//If file is open
    }
    
    if(file.bad()){
        cout << "\nFile reading error\n";//If file has an error
    }
    
    //Read all lines form the file and count them
    if (file.is_open()){
  
        while (!file.eof()){
            getline (file, word, ' ');
            n++;
        }
        file.close();
    }
    else{
        cout << "Failed to open file for CountLinesOfFile (const char*)" << endl;
    }
 
    return n;
}
void HANGMAN::CreateWordsBuf (int len, const char* fname){ //Allocate _wordsBuf and store words .txt
    string line;
    int index = 0;
    _wordsBuf = new string[len];
  
    ifstream file (fname);
  
    //Read words and store them in own element
    if (file.is_open()){
  
        while (!file.eof()){
  
            getline (file, line, ' ');
            _wordsBuf[index++] = line;
        }
        file.close();
    }
    else{
        cout << "Failed to open words.txt for CreateWordBuf (int, const char*)" << endl;
    }
}
  
void HANGMAN::Pull_randWord (int filelen){ //Pulls a word from _wordsBuf
    int randVal;
    randVal = rand() % filelen;
  
    randWord = _wordsBuf[randVal];
}
void HANGMAN::CreateLetterBuf(int len){    //Allocate _letterBuf and fills with whitespaces
 
    //allocate array and fill it whitespaces (inputed letters will be pushed)
    _letterBuf = new char[len];
    for (int i = 0; i < len; i++){
        _letterBuf[i] = ' ';
    }
}
void HANGMAN::CreateHiddenWord(int len){   //Allocate _hiddenWord buf and fills with underscores
 
    //allocate array and fill it with underscores for hidden word UI
    _hiddenWord = new char[len];
    for (int i = 0; i < len; i++){
        _hiddenWord[i] = '_';
    }
}
void HANGMAN::OutputHiddenWord(){ //Outputs _hiddenWord buf
 
    //outputs the underscores and adds a whitespace between each for better reading
    for (int x = 0; x < lenofRW; x++){
        cout << _hiddenWord[x];
        if (x != lenofRW - 1){
            cout << " ";
        }
    }
}
void HANGMAN::OutputIngameUI(){   //Requires _hiddenWord buf to be allocated and output simple UI
 
    cout << "Tries left: " << triesLeft;
    cout << endl << endl;
 
    OutputHiddenWord();
    cout << endl << endl;
 
    cout << "Letter input: ";
}
void HANGMAN::UpdateHiddenWord(){ //Set cursor at proper pos and re-writes _hiddenWord buf
    COORD hiddenWordCoords = {0,2};
 
    SetConsoleCursorPosition (hStdout, hiddenWordCoords);
    OutputHiddenWord();
}
void HANGMAN::UpdateTriesLeft(){  //Set cursor at proper pos and re-write triesLeft value
    COORD triesLeftCoords = {0,0};
    COORD eraseDigit = {13,0};
  
    //Whitespace at the second digit when triesLeft goes under 9
    if (triesLeft < 5){
        SetConsoleCursorPosition (hStdout, eraseDigit);
        cout << ' ';
    }
    SetConsoleCursorPosition (hStdout, triesLeftCoords);
    cout << "Tries left: " << triesLeft;
    cout << endl << endl;
}
  
void HANGMAN::CreateNewGame(){   //Pulls new randWord, alloc bufs, value for triesLeft/lenofLetterB
 
    ClearScreen();
 
    //Pull new randWord and create _hiddenWord buf
    Pull_randWord (lenofFile);
    lenofRW = randWord.size();
    CreateHiddenWord (lenofRW);
 
    //Set value for triesLeft and create _letterBuf buf
    triesLeft = lenofRW;
    lenofLetterB = triesLeft * 2; //hold correct and incorect letters
    CreateLetterBuf (lenofLetterB);
 
    inGame = true;
}
void HANGMAN::CheckForEndGame(){ //Compares randWord letters with _hidenWord buf, checks triesLeft
 
    //Check if triesLeft are wasted, if so, end the current game
    if (triesLeft == 0){
        cout << endl << endl << endl << endl << "WRONG!";
        Sleep (2000);
        inGame = false;
    }
 
    //Compare _hiddenWord and randWord if all letters match
    int count = 0;
    for (int j = 0; j < lenofRW; j++){
        if (_hiddenWord[j] == randWord[j]){
            count++;
        }
    }
    //If _hiddenWord match randWord, end the current game
    if (count == lenofRW){
        cout << endl << endl << endl << endl << "CORRECT!";
        Sleep (2000);
        inGame = false;
    }
}
  
void HANGMAN::Set_input(char val){ //Used for reset
    input = val;
}
char HANGMAN::Get_input(){
    return input;
}
 void HANGMAN::AskInputGetchar (){ //Works with getch()
    input = getchar();
    //input = std::cin.get();
}
void HANGMAN::AskLetterInput(){ //Ask for single letter, can delete it before confirming with Enter
    COORD letterInpCoords; //X and Y values will be changed trough the function loops
    COORD letterInpOrigCoords = {14,4}; //permanent values for X and Y
    bool letterConfirmed = false;
  
    //SetConsoleCursorPosition (hStdout, letterInpOrigCoords); //set cursor at begining
  
    //Loop until a letter is pressed and then ENTER key
    while (!letterConfirmed){
  
        //If letter is deleted, reset coords so can re-write the buffer
        letterInpCoords.X = 14;
        letterInpCoords.Y = 4;
 
        //Search free element spot for input
        for (int i = 0; i < lenofLetterB; i++){
            if (_letterBuf[i] == ' '){  //if finds a whitespace element,
                letterInpCoords.X += i; //take value of i + 14 for X coordinates
                SetConsoleCursorPosition (hStdout, letterInpCoords); //set proper pos for input
 
                //Loop until a letter only is pressed
                do {
                    inpLetter = getchar(); 
                    //inpLetter = std::cin.get();
                } while ((inpLetter != 'A' && inpLetter != 'a') &&
                         (inpLetter != 'B' && inpLetter != 'b') &&
                         (inpLetter != 'C' && inpLetter != 'c') &&
                         (inpLetter != 'D' && inpLetter != 'd') &&
                         (inpLetter != 'E' && inpLetter != 'e') &&
                         (inpLetter != 'F' && inpLetter != 'f') &&
                         (inpLetter != 'G' && inpLetter != 'g') &&
                         (inpLetter != 'H' && inpLetter != 'h') &&
                         (inpLetter != 'I' && inpLetter != 'i') &&
                         (inpLetter != 'J' && inpLetter != 'j') &&
                         (inpLetter != 'K' && inpLetter != 'k') &&
                         (inpLetter != 'L' && inpLetter != 'l') &&
                         (inpLetter != 'M' && inpLetter != 'm') &&
                         (inpLetter != 'N' && inpLetter != 'n') &&
                         (inpLetter != 'O' && inpLetter != 'o') &&
                         (inpLetter != 'P' && inpLetter != 'p') &&
                         (inpLetter != 'Q' && inpLetter != 'q') &&
                         (inpLetter != 'R' && inpLetter != 'r') &&
                         (inpLetter != 'S' && inpLetter != 's') &&
                         (inpLetter != 'T' && inpLetter != 't') &&
                         (inpLetter != 'U' && inpLetter != 'u') &&
                         (inpLetter != 'V' && inpLetter != 'v') &&
                         (inpLetter != 'W' && inpLetter != 'w') &&
                         (inpLetter != 'X' && inpLetter != 'x') &&
                         (inpLetter != 'Y' && inpLetter != 'y') &&
                         (inpLetter != 'Z' && inpLetter != 'z'));
  
                break; //Break loop if letter is inputed
            }
            //If any time comma's are used or other letters, count them
            else
                letterInpCoords.X += 1;
        }
  
        //Output inputed letter on the same coords that was asked to
        cout << inpLetter;
  
        //Loop until ENTER or BACKSPACE key is pressed
        input = -1; //reset
        while (input != 10 && input != 8){
  
            input = getchar(); 
            //input = std::cin.get();
            switch (input){
                //ENTER KEY -- confirms the letter
                case 10:
                    /* save inputed letter in first whitespace element and add coma after it.
                    Confirm the letter flag to true and exit the function*/
                    for (int i = 0; i < lenofLetterB; i++){
                        if (_letterBuf[i] == ' '){
                            _letterBuf[i] = inpLetter;
                            cout << ",";
                            letterConfirmed = true;
                            break;
                        }
                    }
                    break; //case ENTER: ends
  
                //BACKSPACE KEY -- re-printing letters/visualy deleting
                case 8:
                    /* if still no letters in buffer, set cursor to begining and output whitespace,
                    then back one char so input can be be on the same spot */
                    if (_letterBuf[0] == ' '){
                        SetConsoleCursorPosition (hStdout, letterInpOrigCoords);
                        cout << ' ' << '\b';
                    }
                    /* if have inputed letter, set cursor to begining and re-write all letter's
                    and comma's */
                    else if (_letterBuf[0] != ' '){
                        SetConsoleCursorPosition (hStdout, letterInpOrigCoords);
                        for (int i = 0; i < lenofLetterB; i++){
                            if (_letterBuf[i] != ' '){        //if have letter in the element
                                cout << _letterBuf[i] << ","; //output it including comma after it
                            }
                            else {  //if no letter in the element
                                cout << ' ' << '\b'; //output whitespace to simulate deletion
                                break; //then back one char so input be on the same spot
                            }
                        }
                    }
  
                    break; //case BACKSPACE: ends
  
            } //switch (input) ends
         } //while (input != ENTER && != BACKSPACE) ends
     } //while (!letterConfirmed) ends
 
}
void HANGMAN::CheckInputLetter(){ //Check if letter exist in randWord
    bool matchLetter = false;
 
    //Compares inpLetter with randWord letters
    for (int x = 0; x < lenofLetterB; x++){
        if (inpLetter == randWord[x]){
            _hiddenWord[x] = inpLetter;
            matchLetter = true;
        }
    }
    //If inpLetter dont exist in randWord, decrease triesLeft
    if (!matchLetter){
        --triesLeft;
    }
}