
#include <iostream>
#include <stdlib.h>
using namespace std;


//this grid , yellowKilled and red killed  this grid can be made static inside the piece class
//take move or validate piece can be made a static function inside piece class or outside class if that is possible in time



int thisGrid[8][8];
int gridWithNumbers[8][8];
int redKilled = 0;
int yellowkilled = 0;

class piece{
protected:
    int locationX;
    int locationY;
    bool IsKing;
    //bool IsDead;
public:

   

    piece() {
        locationX=-1;
        locationY=-1;
        IsKing=false;
      //  IsDead = false;
    }

    void setLocation(int x,int y) {
        locationX = x;
        locationY = y;
    }
    int getLocationX() {
        return  locationX;
    }
    int getLocationY() {
        return  locationY;
    }
    bool getIsKing() {
        return  IsKing;
    }

    void setIsKing(bool boolentery) {
        IsKing = boolentery;
    }

};

class redPieces {
public:
    piece R[12];

    redPieces() {
        int a = 0;
        int b = 1;
        int c = 0;
        int d = 1;
        for (int i = 0; i < 12; i++) {
            R[i].setLocation(a, b);

            c++;
            b += 2;
            if (c == 4) {
                //R[i].setLocation(a, b);
                if (d == 1) {
                    b = 0;
                    d = 0;
                }
                else {
                    b = 1;
                    d = 1;
                }
                a++;
                c = 0;
            }
        }
        for (int i = 0; i < 12; i++) {
            thisGrid[R[i].getLocationX()][R[i].getLocationY()] = 1;
        }

    }


    void TakeMove() {
        int xEnter = 0, yEnter = 0;
        bool movemade = false;            // becomes true if move was made successfully
        char choiceMade = ' ';
        bool killed = false;
        while (movemade == false) {
            ValidatePiece(xEnter, yEnter);
            validateMove(xEnter, yEnter, movemade, choiceMade, killed);

            if (killed == true) {
                cout << "player killed. choose next move" << endl;
                validateMove(xEnter, yEnter, movemade, choiceMade, killed);
            }


        }
    }

    void ValidatePiece(int& xEnter, int& yEnter) {
        bool outOfBounds = true;
        bool notYourPiece = true;


        while (notYourPiece == true) {
            outOfBounds = true;
            while (outOfBounds == true) {
                cout << "enter coordinates of piece you want to move \n";
                cout << "enter X : ";
                cin >> xEnter;
                cout << "enter Y : ";
                cin >> yEnter;
                if ((xEnter >= 0 && xEnter <= 7) && (yEnter >= 0 && yEnter <= 7)) {
                    outOfBounds = false;
                }
                else {
                    cout << "invalid coordinates, enter again:" << endl;
                }
            }

            if (thisGrid[xEnter][yEnter] == 1) {
                notYourPiece = false;
            }
            else {
                cout << "this is not your piece, enter coordinates again " << endl;
            }
        }
    }

    void validateMove(int& xEnter, int& yEnter, bool& movemade, char& choiceMade, bool& killed) {

        int r1, c1, r2, c2, r3, c3, r4, c4;
        int num1, num2, num3, num4;
        bool pieceFound = false;
        bool locApass = false, locBpass = false, locCpass = false, locDpass = false;
        bool potentialKill1 = false, potentialKill2 = false, potentialKill3 = false, potentialKill4 = false;
        int indexOfPiece = -1;
        //optA is downleft optB is downrigth, optC is upleft optD is upright



        for (int i = 0; i < 12; i++) {
            if ((R[i].getLocationX() == xEnter) && ((R[i]).getLocationY() == yEnter)) {
                indexOfPiece = i;
            }
        }


        r1 = xEnter + 1;
        c1 = yEnter - 1;
        r2 = xEnter + 1;
        c2 = yEnter + 1;
        r3 = xEnter - 1;
        c3 = yEnter - 1;
        r4 = xEnter - 1;
        c4 = yEnter + 1;


        //check every location if it is availaible


        if (killed == true) {
            ValidateMoveSubFunc1(xEnter, yEnter, movemade, choiceMade, killed, r1, c1, r2, c2, r3, c3, r4, c4, potentialKill1, potentialKill2, potentialKill3, potentialKill4, locApass, locBpass, locCpass, locDpass);
        }
        else {
            ValidateMoveSubFunc2(xEnter, yEnter, movemade, choiceMade, killed, r1, c1, r2, c2, r3, c3, r4, c4, potentialKill1, potentialKill2, potentialKill3, potentialKill4, locApass, locBpass, locCpass, locDpass);
        }


        if (R[indexOfPiece].getIsKing() == false) {
            locCpass = false;
            locDpass = false;
        }

        //validate all x and ys at the boarder    can be made a function
        if (r1 > 7 || c1 < 0) {
            locApass = false;
        }
        if (r2 > 7 || c2 > 7) {
            locBpass = false;
        }
        if (r3 < 0 || c3 < 0) {
            locCpass = false;
        }
        if (r4 < 0 || c4 > 7) {
            locDpass = false;
        }



        if (locApass == true || locBpass == true || locCpass == true || locDpass == true) {


            //this has to wait
            num1 = gridWithNumbers[r1][c1];
            num2 = gridWithNumbers[r2][c2];
            num3 = gridWithNumbers[r3][c3];
            num4 = gridWithNumbers[r4][c4];
            char choice = ' ';




                if (locApass == true) {
                    cout << "enter a to move to number " << num1 << endl;
                }
                else {
                    cout << "option a is not availaible \n";
                }
                if (locBpass == true) {
                    cout << "enter b to move to number " << num2 << endl;
                }
                else {
                    cout << "option b is not availaible \n";
                }


                if (R[indexOfPiece].getIsKing() == true) {
                    
                    if (locCpass == true) {
                        cout << "enter c to move to number " << num3 << endl;
                    }
                    else {
                        cout << "option c is not availaible \n";
                    }
                    if (locDpass == true) {
                        cout << "enter d to move to number " << num4 << endl;
                    }
                    else {
                        cout << "option d is not availaible \n";
                    }
                }

            if (R[indexOfPiece].getIsKing() == false) {
               
                while (choice != 'a' && choice != 'b') {
                    cin >> choice;
                    if (choice != 'a' && choice != 'b') {
                        cout << "incorrect choice enter again" << endl;
                    }
                    if ((choice == 'a' && locApass == false) || (choice == 'b' && locBpass == false)) {
                        cout << "choose from availaible options" << endl;
                        cin >> choice;
                    }
                }

            }
            else if (R[indexOfPiece].getIsKing() == true) {
               
                while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd') {
                    cin >> choice;
                    if (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd') {
                        cout << "incorrect choice enter again" << endl;
                    }
                    if ((choice == 'a' && locApass == false) || (choice == 'b' && locBpass == false) || (choice == 'c' && locCpass == false) || (choice == 'd' && locDpass == false)) {
                        cout << "choose from availaible options" << endl;
                        cin >> choice;
                    }
                }
            }





            if (choice == 'a') {
                killed = potentialKill1;
                EffectOFMove(indexOfPiece, r1, c1, xEnter, yEnter, potentialKill1, (r1 - 1), (c1 + 1));
            }
            else if (choice == 'b') {
                killed = potentialKill2;
                EffectOFMove(indexOfPiece, r2, c2, xEnter, yEnter, potentialKill2, (r2 - 1), (c2 - 1));
            }
            else if (choice == 'c') {
                killed = potentialKill3;
                EffectOFMove(indexOfPiece, r3, c3, xEnter, yEnter, potentialKill3, (r3 + 1), (c3 + 1));
            }
            else {
                killed = potentialKill4;
                EffectOFMove(indexOfPiece, r4, c4, xEnter, yEnter, potentialKill4, (r4 + 1), (c4 - 1));
            }
            movemade = true;
        }
        else {
            cout << "no moves possible on selected piece" << endl;    // makes the passed boolean variable false so that we can enter coordinates again;
            movemade = false;
            if (killed == true) {
                movemade = true;
                cout << "movemade is set to false" << endl;
            }
        }
    }

    void EffectOFMove(int indexOfPiece, int x, int y, int& xEnter, int& yEnter, bool potentialkill, int x2, int y2) {
        R[indexOfPiece].setLocation(x, y);
        thisGrid[xEnter][yEnter] = 0;
        thisGrid[x][y] = 1;
        xEnter = x;
        yEnter = y;

        if (xEnter == 7) {
            R[indexOfPiece].setIsKing(true);
            cout << "selected piece is made king" << endl;
            system("Pause");
        }
        if (potentialkill == true) {
            yellowkilled++;
            thisGrid[x2][y2] = 0;
        }
    }

    void ValidateMoveSubFunc1(int& xEnter, int& yEnter, bool& movemade, char& choiceMade, bool& killed, int& r1, int& c1, int& r2, int& c2, int& r3, int& c3, int& r4, int& c4, bool& potentialKill1, bool& potentialKill2, bool& potentialKill3, bool& potentialKill4, bool& locApass, bool& locBpass, bool& locCpass, bool& locDpass) {

        //pass all Rs and Cs   ,  all potential kills , all locationPasses , index of piece

        if (thisGrid[r1][c1] == 2) { //ooponent piece means check next availaible location
            if (thisGrid[r1 + 1][c1 - 1] == 0) {   // location empty and good to go
                locApass = true;
                r1++; c1--;
                potentialKill1 = true;
            }
            else {
                locApass = false;
            }
        }

        if (thisGrid[r2][c2] == 2) { //ooponent piece means check next availaible location
            if (thisGrid[r2 + 1][c2 + 1] == 0) {   // location empty and good to go
                locBpass = true;
                potentialKill2 = true;
                r2++; c2++;
            }
            else {
                locBpass = false;
            }
        }
        if (thisGrid[r3][c3] == 2) { //ooponent piece means check next availaible location

            if (thisGrid[r3 - 1][c3 - 1] == 0) {   // location empty and good to go
                locCpass = true;
                potentialKill3 = true;
                r3--; c3--;
            }
            else {
                locCpass = false;
            }
        }
        if (thisGrid[r4][c4] == 2) { //ooponent piece means check next availaible location
            if (thisGrid[r4 - 1][c4 + 1] == 0) {   // location empty and good to go
                locDpass = true;
                potentialKill4 = true;
                r4--; c4++;
            }
            else {
                locDpass = false;
            }
        }
    }

    void ValidateMoveSubFunc2(int& xEnter, int& yEnter, bool& movemade, char& choiceMade, bool& killed, int& r1, int& c1, int& r2, int& c2, int& r3, int& c3, int& r4, int& c4, bool& potentialKill1, bool& potentialKill2, bool& potentialKill3, bool& potentialKill4, bool& locApass, bool& locBpass, bool& locCpass, bool& locDpass) {

        if (thisGrid[r1][c1] == 0) {   // location empty and good to go
            locApass = true;
        }
        else if (thisGrid[r1][c1] == 1) {   //if my piece, location is not availaible
            locApass = false;
        }
        else if (thisGrid[r1][c1] == 2) { //ooponent piece means check next availaible location
            if (thisGrid[r1 + 1][c1 - 1] == 0) {   // location empty and good to go
                locApass = true;
                r1++; c1--;
                potentialKill1 = true;
            }
            else {
                locApass = false;
            }
        }


        if (thisGrid[r2][c2] == 0) {   // location empty and good to go
            locBpass = true;
        }
        else if (thisGrid[r2][c2] == 1) {   //if my piece, location is not availaible
            locBpass = false;
        }
        else if (thisGrid[r2][c2] == 2) { //ooponent piece means check next availaible location
            if (thisGrid[r2 + 1][c2 + 1] == 0) {   // location empty and good to go
                locBpass = true;
                potentialKill2 = true;
                r2++; c2++;
            }
            else {
                locBpass = false;
            }
        }

        if (thisGrid[r3][c3] == 0) {   // location empty and good to go
            locCpass = true;
        }
        else if (thisGrid[r3][c3] == 1) {   //if my piece, location is not availaible
            locCpass = false;

        }
        else if (thisGrid[r3][c3] == 2) { //ooponent piece means check next availaible location

            if (thisGrid[r3 - 1][c3 - 1] == 0) {   // location empty and good to go
                locCpass = true;
                potentialKill3 = true;
                r3--; c3--;
            }
            else {
                locCpass = false;
            }
        }


        if (thisGrid[r4][c4] == 0) {   // location empty and good to go
            locDpass = true;
        }
        else if (thisGrid[r4][c4] == 1) {   //if my piece, location is not availaible
            locDpass = false;
        }
        else if (thisGrid[r4][c4] == 2) { //ooponent piece means check next availaible location
            if (thisGrid[r4 - 1][c4 + 1] == 0) {   // location empty and good to go
                locDpass = true;
                potentialKill4 = true;
                r4--; c4++;
            }
            else {
                locDpass = false;
            }
        }
    }

};

class yellowPieces {
public:
    piece Y[12];

    yellowPieces() {
        int a = 7;
        int b = 6;  
        int c = 0;
        int d = 1;

        for (int i = 0; i < 12;i++) { 
            Y[i].setLocation(a,b);
            c++;
            b -= 2;
            if (c==4) {
                if (d==1) {
                    b = 7;
                    d = 0;
                }
                else {
                    b = 6;
                    d = 1;
                }
                a--;
                c = 0;
            }
        }
        for (int i = 0; i < 12;i++) {
            thisGrid[Y[i].getLocationX()][Y[i].getLocationY()] = 2;
        }
    
    }

    void TakeMove() {
        int xEnter = 0, yEnter = 0;
        bool movemade = false;            // becomes true if move was made successfully
        char choiceMade=' ';
        bool killed = false;
        while (movemade==false) {
            ValidatePiece(xEnter, yEnter);
            validateMove(xEnter, yEnter, movemade, choiceMade,killed);

            if (killed==true) {
                cout << "player killed.choose next move" << endl;
                validateMove(xEnter, yEnter, movemade, choiceMade, killed);
            }

        }
    }

    void ValidatePiece(int &xEnter, int &yEnter) {
        bool outOfBounds = true;
        bool notYourPiece = true;
       

        while (notYourPiece==true) {
            outOfBounds = true;
            while (outOfBounds == true) {
                cout << "enter coordinates of piece you want to move \n";
                cout << "enter X : ";
                cin >> xEnter;
                cout << "enter Y : ";
                cin >> yEnter;
                if ((xEnter >= 0 && xEnter <= 7) && (yEnter >= 0 && yEnter <= 7)) {
                    outOfBounds = false;
                }
                else {
                    cout << "invalid coordinates, enter again:" << endl;
                }
            }

            if (thisGrid[xEnter][yEnter]==2) {
                notYourPiece = false;
            }
            else {
                cout << "this is not your piece, enter coordinates again " << endl;
            }

        }
    }

    void validateMove(int &xEnter, int &yEnter, bool &movemade , char &choiceMade,bool &killed) {

        int r1, c1, r2, c2, r3, c3, r4, c4;
        int num1, num2, num3, num4;
        bool pieceFound = false;
        bool locApass = false, locBpass = false, locCpass = false , locDpass=false;
        bool potentialKill1=false, potentialKill2=false, potentialKill3=false, potentialKill4=false;
        int indexOfPiece = -1;
        //optA is upleft optB is uprigth, optC is downleft optD is down right


        //check if the piece at the entered location is king or not
        for (int i = 0; i < 12;i++) {
            if ((Y[i].getLocationX()==xEnter) && ((Y[i]).getLocationY()== yEnter)){
                indexOfPiece = i;
            }
        }

        r1 = xEnter - 1;
        c1 = yEnter - 1;
        r2 = xEnter - 1; 
        c2 = yEnter + 1;
        r3 = xEnter + 1; 
        c3 = yEnter - 1;
        r4 = xEnter + 1; 
        c4 = yEnter + 1;

     
        //check every location if it is availaible



        if (killed == true) {
            ValidateMoveSubFunc1(xEnter, yEnter, movemade, choiceMade, killed, r1, c1, r2, c2, r3, c3, r4, c4, potentialKill1, potentialKill2, potentialKill3, potentialKill4, locApass, locBpass, locCpass, locDpass);
        }
        else {
            ValidateMoveSubFunc2(xEnter, yEnter, movemade, choiceMade, killed, r1, c1, r2, c2, r3, c3, r4, c4, potentialKill1, potentialKill2, potentialKill3, potentialKill4, locApass, locBpass, locCpass, locDpass);


        }




        if (Y[indexOfPiece].getIsKing() == false) {
            locCpass = false;
            locDpass = false;
        }

             
       



        //validate all x and ys at the boarder    can be made a function
        if (r1 < 0||c1 < 0) {
            locApass = false;
        }
        if (r2 < 0||c2 > 7) {
            locBpass = false;
        }
        if (r3 > 7||c3 < 0) {
            locCpass = false;
        }
        if (r4 > 7||c4 > 7) {
            locDpass = false;
        }


        if (locApass == true || locBpass == true || locCpass == true || locDpass == true) {


            //this has to wait
            num1 = gridWithNumbers[r1][c1];
            num2 = gridWithNumbers[r2][c2];
            num3 = gridWithNumbers[r3][c3];
            num4 = gridWithNumbers[r4][c4];
            char choice = ' ';


            if (locApass == true) {
                cout << "enter a to move to number " << num1 << endl;
            }
            else {
                cout << "option a is not availaible \n";
            }
            if (locBpass == true) {
                cout << "enter b to move to number " << num2 << endl;
            }
            else {
                cout << "option b is not availaible \n";
            }


            if (Y[indexOfPiece].getIsKing() == true) {

                if (locCpass == true) {
                    cout << "enter c to move to number " << num3 << endl;
                }
                else {
                    cout << "option c is not availaible \n";
                }
                if (locDpass == true) {
                    cout << "enter d to move to number " << num4 << endl;
                }
                else {
                    cout << "option d is not availaible \n";
                }
            }

            if (Y[indexOfPiece].getIsKing() == false) {

                while (choice != 'a' && choice != 'b') {
                    cin >> choice;
                    if (choice != 'a' && choice != 'b') {
                        cout << "incorrect choice enter again" << endl;
                    }
                    if ((choice == 'a' && locApass == false) || (choice == 'b' && locBpass == false)) {
                        cout << "choose from availaible options" << endl;
                        cin >> choice;
                    }
                }

            }
            else if (Y[indexOfPiece].getIsKing() == true) {

                while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd') {
                    cin >> choice;
                    if (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd') {
                        cout << "incorrect choice enter again" << endl;
                    }
                    if ((choice == 'a' && locApass == false) || (choice == 'b' && locBpass == false) || (choice == 'c' && locCpass == false) || (choice == 'd' && locDpass == false)) {
                        cout << "choose from availaible options" << endl;
                        cin >> choice;
                    }
                }
            }




            if (choice=='a') {
               killed= potentialKill1;
               EffectOFMove(indexOfPiece,r1,c1, xEnter,  yEnter,potentialKill1,(r1+1),(c1+1));
            }   
            else if(choice == 'b') {
                killed = potentialKill2;
                EffectOFMove(indexOfPiece, r2, c2, xEnter, yEnter, potentialKill2, (r2 + 1), (c2 - 1));
            }else if (choice == 'c') {
                killed = potentialKill3;
                EffectOFMove(indexOfPiece, r3, c3, xEnter, yEnter, potentialKill3, (r3 - 1), (c3 + 1));
            }
            else {
                killed = potentialKill4;
                 EffectOFMove(indexOfPiece,r4,c4, xEnter,  yEnter,potentialKill4, (r4 - 1), (c4 - 1));
            }


            movemade = true;
        }
        else {
            cout << "no moves possible on selected piece" << endl;    // makes the passed boolean variable false so that we can enter coordinates again;
            movemade = false;
            if (killed == true) {
                movemade = true;
            }
        }
    }

    void EffectOFMove(int indexOfPiece,int x, int y  ,int &xEnter ,int &yEnter,bool potentialkill , int x2,int y2) {
        
        Y[indexOfPiece].setLocation(x, y);
        thisGrid[xEnter][yEnter] = 0;
        thisGrid[x][y] = 2;
        xEnter = x;
        yEnter = y;

        if (xEnter==0) {
            Y[indexOfPiece].setIsKing(true);
            cout << "selected piece is made king" << endl;
            system("Pause");
        }
        if (potentialkill==true) {
            redKilled++;
            thisGrid[x2][y2] = 0;
        }
    }

    void ValidateMoveSubFunc1(int& xEnter, int& yEnter, bool& movemade, char& choiceMade, bool& killed, int& r1, int& c1, int& r2, int& c2, int& r3, int& c3, int& r4, int& c4, bool& potentialKill1, bool& potentialKill2, bool& potentialKill3, bool& potentialKill4, bool& locApass, bool& locBpass, bool& locCpass, bool& locDpass) {

        if (thisGrid[r1][c1] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r1 - 1][c1 - 1] == 0) {   // location empty and good to go
                locApass = true;
                r1--; c1--;
                potentialKill1 = true;
            }
            else {
                locApass = false;
            }
        }
        if (thisGrid[r2][c2] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r2 - 1][c2 + 1] == 0) {   // location empty and good to go
                locBpass = true;
                potentialKill2 = true;
                r2--; c2++;
            }
            else {
                locBpass = false;
            }
        }
        if (thisGrid[r3][c3] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r3 + 1][c3 - 1] == 0) {   // location empty and good to go
                locCpass = true;
                potentialKill3 = true;
                r3++; c3--;
            }
            else {
                locCpass = false;
            }
        }
        if (thisGrid[r4][c4] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r4 + 1][c4 + 1] == 0) {   // location empty and good to go
                locDpass = true;
                potentialKill4 = true;
                r4++; c4++;
            }
            else {
                locDpass = false;
            }
        }


    }

    void ValidateMoveSubFunc2(int& xEnter, int& yEnter, bool& movemade, char& choiceMade, bool& killed, int& r1, int& c1, int& r2, int& c2, int& r3, int& c3, int& r4, int& c4, bool& potentialKill1, bool& potentialKill2, bool& potentialKill3, bool& potentialKill4, bool& locApass, bool& locBpass, bool& locCpass, bool& locDpass) {
        if (thisGrid[r1][c1] == 0) {   // location empty and good to go
            locApass = true;
        }
        else if (thisGrid[r1][c1] == 2) {   //if my piece, location is not availaible
            locApass = false;
        }
        else if (thisGrid[r1][c1] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r1 - 1][c1 - 1] == 0) {   // location empty and good to go
                locApass = true;
                r1--; c1--;
                potentialKill1 = true;
            }
            else {
                locApass = false;
            }
        }


        if (thisGrid[r2][c2] == 0) {   // location empty and good to go
            locBpass = true;
        }
        else if (thisGrid[r2][c2] == 2) {   //if my piece, location is not availaible
            locBpass = false;
        }
        else if (thisGrid[r2][c2] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r2 - 1][c2 + 1] == 0) {   // location empty and good to go
                locBpass = true;
                potentialKill2 = true;
                r2--; c2++;
            }
            else {
                locBpass = false;
            }
        }

        if (thisGrid[r3][c3] == 0) {   // location empty and good to go
            locCpass = true;
        }
        else if (thisGrid[r3][c3] == 2) {   //if my piece, location is not availaible
            locCpass = false;
        }
        else if (thisGrid[r3][c3] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r3 + 1][c3 - 1] == 0) {   // location empty and good to go
                locCpass = true;
                potentialKill3 = true;
                r3++; c3--;
            }
            else {
                locCpass = false;
            }
        }


        if (thisGrid[r4][c4] == 0) {   // location empty and good to go
            locDpass = true;
        }
        else if (thisGrid[r4][c4] == 2) {   //if my piece, location is not availaible
            locDpass = false;
        }
        else if (thisGrid[r4][c4] == 1) { //ooponent piece means check next availaible location
            if (thisGrid[r4 + 1][c4 + 1] == 0) {   // location empty and good to go
                locDpass = true;
                potentialKill4 = true;
                r4++; c4++;
            }
            else {
                locDpass = false;
            }
        }

    }



    

};


void displayBoardwithpieces() {
    int number = 32;
    cout << " ";
    for (int i = 0; i < 8; i++) {
        cout << "   " << i<< "  ";
    }
    cout << endl;
    cout << " ++-----+-----+-----+-----+-----+-----+-----+-----++" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i;
        cout << "|";
        for (int j = 0; j < 8; j++) {
            if (thisGrid[i][j] == -1) {
                cout << "| " << "." << "   ";
            }
            else {
                if (thisGrid[i][j] == 1) {
                    cout << "| " << "@" << "   ";
                }
                else {
                    if (thisGrid[i][j] == 2) {
                        cout << "| " << "O" << "   ";
                    }
                    else {
                        if (number > 9) {
                            cout << "| " << number << "  ";
                        }
                        else {
                            cout << "| " << number << "   ";
                        }
                    }
                }
                number--;
            }
        }
        cout << "||" << endl;
        cout << " ++-----+-----+-----+-----+-----+-----+-----+-----++" ;
        cout << endl;
    }
}


void actualgrid(){
      /* this grid will hold a value if a piece actually exists at a given location
          1 for red piece or @ 
          2 for white piece or O
          0 for empty place and 
          else -1 for the dark checker blockes 
      */
    //this funtion also initializes the array of grid numbers only




    bool alternate = false;
    int c = 0;
    int number = 32;
    for (int i = 0; i < 8;i++) {
        for (int j = 0; j < 8;j++) {
           
            if (alternate == false) {
                alternate = true;
                thisGrid[i][j] = -1;
                    /*................................................*/
                gridWithNumbers[i][j] = -1;
                    /*................................................*/
            }
            else {
                alternate = false;
                thisGrid[i][j] = 0;
                /*................................................*/
                gridWithNumbers[i][j] = number;
                number--;
                /*................................................*/   
            }
        }
        if (alternate == false) {
            alternate = true;
        }
        else {
            alternate = false;
        }
    }
}




int main(){
    system("Color F3");
    bool turnAlternator = false;
    bool gameEnd = false;
    bool RedWon = false;

    actualgrid();               //have to be placed before instantiation of both pieces
    yellowPieces yellow;
    redPieces red;

    while (gameEnd==false) {

        displayBoardwithpieces();
        cout << "                                        Red killed: " << redKilled << "   Yellow killed: " << yellowkilled << endl;
        if (turnAlternator == false) {
            cout << "player O turn" << endl;
            yellow.TakeMove(); 
            turnAlternator =true;
        }
        else {
            cout << "Player @ turn" << endl;
            red.TakeMove();
            turnAlternator = false;
        } 
        
        system("CLS");


        if (redKilled == 14 || yellowkilled == 14) {
            cout << "Game Over" << endl;
            gameEnd = true;
        }
      
    }




    if (redKilled == 14) {
        cout << "Yellow player ' O ' won " << endl;
    }
    else if (yellowkilled == 14) {
        cout << "Red player ' @ ' won " << endl;
    }



}


