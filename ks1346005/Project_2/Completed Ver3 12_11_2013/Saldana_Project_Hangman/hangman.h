/* 
 * File:   hangman.h
 * Author: Kenny Saldana
 * Info: Project CIS17A - Project ver2
 * Date: 12/09/2013
 * Created on December 8, 2013, 1:27 PM
 */

#ifndef HANGMAN_H
#define	HANGMAN_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <time.h>

using namespace std;
 
class HANGMAN
{
    
        public:
                HANGMAN(); //Ctor and Dtor
                virtual ~HANGMAN();
 
                void Set_exitGame (bool b); //Flag for the main loop
                bool Get_exitGame();
                void Set_inGame (bool b);   //Flag for inside game loop
                bool Get_inGame();
                void ClearScreen();  //Clears the screen in radius {80,30}
                void CreditsIntro(); //Optional, not sure if going to use

                int CountLinesOfFile (const char* fname); //Count lines of .txt file
                void CreateWordsBuf (int len, const char* fname);  //Allocates _wordsBuf and store words.txt
  
                void Pull_randWord (int filelen); //Pulls a word from _wordsBuf
                void CreateLetterBuf(int len);    //Allocate _letterBuf and fills with whitespaces
                void CreateHiddenWord (int len);  //Allocate _hiddenWord buf and fills with underscores
                void OutputHiddenWord(); //Outputs _hiddenWord buf
                void OutputIngameUI();   //Requires _hiddenWord buf to be allocated and output simple UI
                void UpdateHiddenWord(); //Set cursor at proper pos and re-writes _hiddenWord buf
                void UpdateTriesLeft();  //Set cursor at proper pos and re-write triesLeft value
 
                void CreateNewGame();  //Pulls new randWord, alloc bufs, value for triesLeft/lenofLetterB
                void CheckForEndGame(); //Compares randWord letters with _hidenWord buf, checks triesLeft
 
                void Set_input (char v); //Used for reset
                char Get_input();
                void AskInputGetchar();  //Works with getchar ***see subsitute in code
                void AskLetterInput();  //Ask for single letter, can delete it before confirming with Enter
                void CheckInputLetter(); //Check if letter exist in randWord
  
        private:
        //Predef data types
                HANDLE hStdout; //Standard output handle
 
                //Game
                int triesLeft;
                bool exitGame; //Flag for the main loop
                bool inGame;   //Flag for inside game loop
 
                //Input
                char input;     //UI input
                char inpLetter; //Input only for letters
                char* _letterBuf;
                int lenofLetterB; //Lenth of _letterBuf
 
                //File
                int lenofFile; //Lenth of .txt file
                string* _wordsBuf;
 
                //Word
                char* _hiddenWord;
                string randWord; //Pull_randWord returns this variable
                int lenofRW;     //Lenth of randWord
};
#endif	/* HANGMAN_H */