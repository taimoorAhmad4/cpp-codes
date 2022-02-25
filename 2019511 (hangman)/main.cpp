#include <iostream>
#include <stdio.h>      // NULL
#include <stdlib.h>     // srand , rand , system("CLS") , system("PAUSE")
#include <time.h>       // time
#include <iomanip>      // setw
using namespace std;

//prototypes
string NameLibrary();
int namelengthcheck(string name , int lengthofname );
void displayletters(char displaychars[20] , char charinput ,string namegen , int lengthofname , int MistakesRemaining );
void updateDisplayLetters(int positionOfLetter , char displaychars[20] , char charinput );
void checkletter(char displaychars[20] , char charinput ,string namegen , int lengthofname , int &MistakesRemaining , int &LettersRemaining );
void displayHangman(int MistakesRemaining);
void head();
void throat();
void leftarm();
void rightarm();
void stomach();
void leftfoot();
void rightfoot();

void IntroScreen(){
    for(int j = 0 ; j < 10 ; j++){
       for(int n = 0 ; n < 8 ; n++){
         cout<< "!!!HANGMAN!!!  "  ;
       }
       cout << endl ;
    }

     cout <<"  -.-   "<< endl ;
     cout <<" -   -  "<< endl ;
     cout <<"  -.-                 ____    ____              ____         ___ ___   ____      "<< endl;
     cout <<"   |                 |       |    |   \\      / |            |   |   | |       | "<< endl ;
     cout <<"  /|\\                |____   |____|    \\    /  |___         |   |   | |___    |  "<< endl ;
     cout <<"_/ | \\_                   |  |    |     \\  /   |            |       | |       |  "<< endl ;
     cout <<"   |                  ____|  |    |      \\/    |____        |       | |____   o  "<< endl ;
     cout <<"  / \\                                                        "<< endl;
     cout <<"_/   \\_                                                      "<< endl;

}
char entercharacter(char ListOfEnteredCharacter[20], int &indexNextFree){
    bool charApproved = false;
    char charinput ;

    while(charApproved == false){
        cout << "guess a letter       \n" ;
        cin >> charinput;
        for( int i = 0 ; i < 18 ; i++){
          if (charinput == ListOfEnteredCharacter[i]){
              cout<< "Letter already entered \n" ;
              //entercharacter(ListOfEnteredCharacter, indexNextFree) ;  // RECURSIVE APPROACH
              charApproved = false;
              break;
          }else{
          charApproved = true;
        }
       }
    }
    if (charApproved == true){
       ListOfEnteredCharacter[indexNextFree]= charinput;
           indexNextFree++;
           return charinput ;
    }
}

int main(){
    char ListOfEnteredCharacter[20] ;      // stores characters already entered
    int indexNextFree = 0 ;                // holds next free location in ListOfEnteredCharacter
    string namegen ;
    int lengthofname = 0 ;
    char charinput= '.';
    char displaychars[20] ={'_'} ;
    int MistakesRemaining = 8 ;
    int LettersRemaining = 0 ;

    for(int j =0 ; j < 20 ; j++){
         ListOfEnteredCharacter[j] = '.';

    }

    namegen = NameLibrary() ;           // computer selects a country name from list
    lengthofname = namelengthcheck(namegen , lengthofname);
    LettersRemaining = lengthofname ;

    for(int m = 0 ; m < lengthofname ; m++){
       displaychars[m] = '_'  ;
    }

    system("Color B5");



    IntroScreen() ;     // the hangman intro screen



    system("PAUSE");
    system("CLS");

    displayletters( displaychars , charinput , namegen , lengthofname, MistakesRemaining  );

   while(MistakesRemaining>0 && LettersRemaining >0){

    charinput = entercharacter(ListOfEnteredCharacter , indexNextFree);
    system("CLS");
    checkletter(displaychars , charinput , namegen , lengthofname , MistakesRemaining , LettersRemaining ) ;
   }

    system("CLS");
    cout<< setw(20) << "HANGMAN  \n \n \n" ;

   if (LettersRemaining==0){
     system("Color E8");
    cout<< "contratulations \n the word was : " << namegen << endl;
   }
   if(MistakesRemaining==0){
       system("Color CF");
     cout<< "You Lost \n the word was : " << namegen << endl;
   }
    char choice ;
   cout << "do you want to play again: (y/n)  \n"  ;
    cin >> choice ;
   if (choice == 'y'){
        system("CLS");
    main();
   }else{
      cout << "thanks for playing \n" ;
   }
}



string NameLibrary(){
   int numgen;
   string name[20];
   name[0] = "argentina";
   name[1] = "samoa";
   name[2] = "nepal";
   name[3] = "pakistan";
   name[4] = "india";
   name[5] = "canada";
   name[6] = "russia";
   name[7] = "china";
   name[8] = "africa";
   name[9] = "portugal";
   name[10] = "leshoto";
   name[11] = "egypt";
   name[12] = "france";
   name[13] = "finland";
   name[14] = "germany";
   name[15] = "ghana";
   name[16] = "uruguay";
   name[17] = "ukraine";
   name[18] = "maldives";
   name[19] = "yemen";

    srand (time(NULL));
    numgen = rand() % 20 ;
    return name[numgen];
}



int namelengthcheck(string name , int lengthofname ){
    for(int i = 0; name[i] != '\0' ; i++){
        lengthofname++ ;
    }
    return lengthofname ;
}

void displayletters(char displaychars[20] , char charinput ,string namegen , int lengthofname , int MistakesRemaining ){
      //system("CLS");
      if(MistakesRemaining !=0){
            cout<< setw(20) << "HANGMAN  \n \n \n" ;
        for(int n = 0 ; n < lengthofname ; n++){
          cout << setw(2) <<displaychars[n]   ;
        }
        cout << "  Chances Remaining : " << MistakesRemaining  << endl;
        cout << endl ;
      }
}

void updateDisplayLetters(int positionOfLetter , char displaychars[20] , char charinput ){
   displaychars[positionOfLetter] =  charinput ;
}

void checkletter(char displaychars[20] , char charinput ,string namegen , int lengthofname , int &MistakesRemaining , int &LettersRemaining ){
   int positionOfLetter = 0 ;
   bool CorrectCharacter = false ;
  for(int i = 0 ; i < lengthofname ; i ++){
   if(charinput == namegen[i]){
      updateDisplayLetters( positionOfLetter , displaychars , charinput);
       system("CLS");
      displayletters( displaychars , charinput , namegen , lengthofname , MistakesRemaining );
      if(MistakesRemaining !=8){
        displayHangman(MistakesRemaining) ;
      }
      LettersRemaining-- ;
       positionOfLetter++ ;
       CorrectCharacter = true;
   }else{
   positionOfLetter++ ;
   }
  }
  if (CorrectCharacter == false){
     MistakesRemaining-- ;
     displayletters( displaychars , charinput , namegen , lengthofname , MistakesRemaining );
     displayHangman(MistakesRemaining) ;
  }
}

void displayHangman(int MistakesRemaining){
  switch (MistakesRemaining){
    case 7:
      head();
      break;
    case 6:
      throat();
      break;
    case 5:
      stomach();
      break;
    case 4:
     leftarm();
      break;
    case 3:
      rightarm();
      break;
    case 2:
      leftfoot();
      break;
    case 1:
     rightfoot();
      break;
  }
}

void head(){
cout << "  -.-   "<< endl ;
cout << " -   -  "<< endl ;
cout << "  -.-   "<< endl;
}
void throat(){
   head();
cout << "   |    "<< endl ;
cout << "   |    "<< endl ;

}
void stomach(){
  throat();
cout << "   |    "<< endl ;
cout << "   |    "<< endl ;
}
void leftarm(){
  head();
cout << "   |    "<< endl ;
cout << "  /|    "<< endl ;
cout << "_/ |    "<< endl ;

}
void rightarm(){
head();
cout << "   |    "<< endl ;
cout << "  /|\\  "<< endl ;
cout << "_/ | \\_"<< endl ;
cout << "   |    "<< endl ;

}
void leftfoot(){
 rightarm();
cout << "  /     "<< endl;
cout << "_/      "<< endl  ;
}

void rightfoot(){
rightarm();
cout << "  / \\  "<< endl;
cout << "_/   \\_ "<< endl;
}







