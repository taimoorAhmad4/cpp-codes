#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct book {

      int   ID = 0;
      string BookName  ;
      string author    ;
      string ISBN      ;
      int   price    =0  ;
      int   pages     = 0 ;
      int   IssuedBy  =0 ;

      string IssuedOn  ;
      string ReturnDate;

      void PrintAll(){
         cout << "ID : "          << ID     <<endl;
         cout << "Name :"         << BookName <<endl;
         cout << "Author : "      << author   <<endl;
         cout << "ISBN : "        << ISBN     <<endl;
         cout << "Price : "       << price  <<endl;
         cout << "Pages : "       << pages   <<endl;
         cout << "Issued By : "   << IssuedBy <<endl;
         cout << "Issued On : "   << IssuedOn  <<endl;
         cout << "Return Date : " << ReturnDate<<endl;
      }

};

struct Booklist{
    book books[10] ;

    void PrintPerticularBook (){
        int BookLocation = 0 , ThisID = 0 ;
        bool IdFound = false ;
        cout << "Enter the book ID to see its details" << endl ;
        cin >> ThisID ;
        while (IdFound == false && BookLocation <10 ){
            if(books[BookLocation].ID == ThisID){
               books[BookLocation].PrintAll();
               IdFound = true ;
            }else{
                BookLocation ++ ;
            }
        }
        if (BookLocation>=10){
            cout << "Book not in list" << endl ;
        }
    }

    void PrintAll(){
        cout << "Book list : " << endl ;
       for(int i = 0; i < 10 ; i++){
       books[i].PrintAll();
      }
    }

    void AddNewBook (){
        int x = 0 ;
        bool placefound = false ;
        while(placefound == false && x< 10 ){
            if( books[x].ID ==  0  ){
             cout<<"enter book id"<<endl ;
              cin>> books[x].ID    ;
              cin.ignore(0);

              cout<<"enter book name"<<endl ;
              //getline(cin,books[x].BookName) ;
              cin>>books[x].BookName ;
              cin.ignore(0);

              cout<<"enter book author"<<endl ;
              //getline(cin,books[x].author) ;
              cin>>books[x].author ;
               cin.ignore(0);

              cout<<"enter ISBN"<<endl ;
             // getline(cin,books[x].ISBN );
              cin>>books[x].ISBN ;


              //  cin.ignore(0);
              cout<<"enter book price"<<endl ;
              cin>> books[x].price  ;

              cout<<"enter book pages"<<endl ;
              cin>> books[x].pages     ;
              placefound = true;

            }else{
              x++ ;
            }
      }
    }

    void DeleteAll(){
      for(int i = 0; i < 10 ; i++){
       books[i].ID = 0 ;
       books[i].BookName = "" ;
       books[i].author = "" ;
       books[i].ISBN = "" ;
       books[i].price = 0 ;
       books[i].pages = 0 ;

       books[i].IssuedBy  = 0;
       books[i].IssuedOn  = "";
       books[i].ReturnDate = "" ;
      }
    }


    void ascendSorting (){
        book tempBook;
        for(int i = 0 ; i < 10 ; i++ ){
            for(int j = 0 ; j < 9 ; j++){
                if(books[j].ID>books[j+1].ID){
                     tempBook.ID = books[j].ID ;
                     tempBook.BookName=books[j].BookName ;
                     tempBook.author= books[j].author  ;
                     tempBook.ISBN =books[j].ISBN  ;
                     tempBook.price=books[j].price  ;
                     tempBook.pages  =books[j].pages  ;
                     tempBook.IssuedBy=books[j].IssuedBy ;
                     tempBook.IssuedOn=books[j].IssuedOn  ;
                     tempBook.ReturnDate=books[j].ReturnDate  ;

                     books[j].ID = books[j+1].ID ;
                     books[j].BookName=books[j+1].BookName ;
                     books[j].author= books[j+1].author  ;
                     books[j].ISBN =books[j+1].ISBN  ;
                     books[j].price=books[j+1].price  ;
                     books[j].pages  =books[j+1].pages  ;
                     books[j].IssuedBy=books[j+1].IssuedBy ;
                     books[j].IssuedOn=books[j+1].IssuedOn  ;
                     books[j].ReturnDate=books[j+1].ReturnDate  ;

                     books[j+1].ID = tempBook.ID ;
                     books[j+1].BookName=tempBook.BookName ;
                     books[j+1].author= tempBook.author  ;
                     books[j+1].ISBN =tempBook.ISBN  ;
                     books[j+1].price=tempBook.price  ;
                     books[j+1].pages  =tempBook.pages  ;
                     books[j+1].IssuedBy=tempBook.IssuedBy ;
                     books[j+1].IssuedOn=tempBook.IssuedOn  ;
                     books[j+1].ReturnDate=books[j+1].ReturnDate  ;
                }
            }
        }
    }

  void dscendSorting (){
        book tempBook;
        for(int i = 0 ; i < 10 ; i++ ){
            for(int j = 0 ; j < 9 ; j++){
                if(books[j].ID<books[j+1].ID){
                     tempBook.ID = books[j].ID ;
                     tempBook.BookName=books[j].BookName ;
                     tempBook.author= books[j].author  ;
                     tempBook.ISBN =books[j].ISBN  ;
                     tempBook.price=books[j].price  ;
                     tempBook.pages  =books[j].pages  ;
                     tempBook.IssuedBy=books[j].IssuedBy ;
                     tempBook.IssuedOn=books[j].IssuedOn  ;
                     tempBook.ReturnDate=books[j].ReturnDate  ;

                     books[j].ID = books[j+1].ID ;
                     books[j].BookName=books[j+1].BookName ;
                     books[j].author= books[j+1].author  ;
                     books[j].ISBN =books[j+1].ISBN  ;
                     books[j].price=books[j+1].price  ;
                     books[j].pages  =books[j+1].pages  ;
                     books[j].IssuedBy=books[j+1].IssuedBy ;
                     books[j].IssuedOn=books[j+1].IssuedOn  ;
                     books[j].ReturnDate=books[j+1].ReturnDate  ;

                     books[j+1].ID = tempBook.ID ;
                     books[j+1].BookName=tempBook.BookName ;
                     books[j+1].author= tempBook.author  ;
                     books[j+1].ISBN =tempBook.ISBN  ;
                     books[j+1].price=tempBook.price  ;
                     books[j+1].pages  =tempBook.pages  ;
                     books[j+1].IssuedBy=tempBook.IssuedBy ;
                     books[j+1].IssuedOn=tempBook.IssuedOn  ;
                     books[j+1].ReturnDate=books[j+1].ReturnDate  ;
                }
            }
        }
    }




};
struct student{
       int ID = 0  ;
       string StdName ;
       int RollNo = 0 ;
       int BooksIssued = 0 ;

       void Print(){
           cout << "Student : " << endl ;
           cout << "ID : " << ID << endl ;
           cout << "Name : " << StdName << endl ;
           cout << "Roll Number : " << RollNo << endl ;
           cout << "Books Issued : " << BooksIssued << endl ;
        }

};
struct StudentList{
       student stdlist[10] ;
       void PrintAll (){
          for(int i = 0 ; i <10 ; i++){
            stdlist[i].Print() ;
          }
       }

       void AddStudent(){
           int x = 0 ;
           bool placefound = false ;
           while(placefound == false && x< 10 ){
              if( stdlist[x].ID ==  0  ){
                cout << "enter students ID:" << endl ;
                cin>> stdlist[x].ID    ;
                cin.ignore(0);
                cout << "enter students Name:" << endl ;
                //getline(cin,stdlist[x].StdName  )    ;
                cin>>stdlist[x].StdName ;
                cout << "enter students Roll number:" << endl ;
                cin>> stdlist[x].RollNo     ;
              placefound = true ;
            }else{
              x++ ;
            }
          }
       }

       void DeleteStudent(){
         int thisID ;
         bool stdfound = false ;
         int x = 0;
         cout << "enter students' ID to delete student from list" << endl ;
         cin >> thisID ;
           while(stdfound == false && x < 10 ){
              if( stdlist[x].ID ==  thisID  ){
                 stdlist[x].ID  = 0   ;
                 stdlist[x].StdName =""    ;
                 stdlist[x].RollNo  = 0    ;
                 stdlist[x].BooksIssued = 0   ;
              stdfound = true ;
            }else{
              x++ ;
            }
          }
       }
};

struct Library{
       Booklist thisbooklist ;
       StudentList stud1 ;

       int IDofIssuedBooks[10] ;
       int  StudentID = 0 , BookID = 0 ;
       int StudentIndex = 0 , BookIndex = 0 ;
      bool bookfound = false , studentfound = false ;
       int x = 0 ;



       void issuebook (){
          cout << "enter id of book being issued" << endl ;
          cin>> BookID;
          while(bookfound == false && x <10){
            if(thisbooklist.books[x].ID == BookID){
                bookfound = true ;
            }else {
               x++ ;
            }
           }

           BookIndex = x ;
           x= 0 ;

           if (bookfound==false){
            cout << "book does not exist in booklist" << endl ;
           }else{
               cout << "enter id of student issuing the book" << endl ;
               cin>> StudentID;
               while(studentfound == false && x <10){
                  if(stud1.stdlist[x].ID == StudentID){
                      studentfound = true ;
                   }else {
                       x++ ;
                   }
                }
                StudentIndex = x ;
                x = 0 ;
           }


          if(studentfound == true &&  bookfound == true){
               stud1.stdlist[StudentIndex].BooksIssued ++ ;
               thisbooklist.books[BookIndex].IssuedBy = StudentID ;
               cout << "enter issuing date (DD-MM-YYYY)" << endl ;
               //getline(cin,thisbooklist.books[BookIndex].IssuedOn) ;
               cin>>thisbooklist.books[BookIndex].IssuedOn ;
               cout << "enter return date (DD-MM-YYYY)" << endl ;
               //getline(cin,thisbooklist.books[BookIndex].ReturnDate );
               cin>>thisbooklist.books[BookIndex].ReturnDate  ;
                for(int i = 0 ; i< 10 ; i++){
                    if (IDofIssuedBooks[i]== 0 ){
                        IDofIssuedBooks[i] = BookID ;
                        break ;
                    }
                }
          }

       }



       void returnbook (){
           BookIndex = 0 ;
           StudentIndex = 0 ;
           StudentID = 0 ;
            cout << "enter book ID to be returned" << endl ;
            cin>> BookID ;
            studentfound = false ;
            bookfound = false ;
            x= 0 ;
            for(int i = 0 ; i < 10 ; i ++){
                if(IDofIssuedBooks[i]==BookID ){
                    IDofIssuedBooks[i] = 0 ;


                    while(bookfound == false && BookIndex < 10){
                            if(thisbooklist.books[BookIndex].ID == BookID ){
                               thisbooklist.books[BookIndex].ReturnDate = "" ;
                                thisbooklist.books[BookIndex].IssuedOn ="";
                                StudentID = thisbooklist.books[BookIndex].IssuedBy ;

                               while(studentfound == false && StudentIndex <10){
                                  if(stud1.stdlist[StudentIndex].ID ==StudentID){
                                      stud1.stdlist[StudentIndex].BooksIssued--;
                                      studentfound= true;
                                  }else{
                                     StudentIndex++;
                                  }
                               }

                               bookfound = true ;
                            }else{
                                BookIndex ++ ;
                            }
                    }
                    break;
                }
            }
       }
       void showissuedbooks (){
                for(int i = 0 ; i < 10 ; i ++){
                     for(int j = 0 ; j < 10 ; j++ ){
                            if(IDofIssuedBooks[i]==thisbooklist.books[j].ID ){
                                   thisbooklist.books[j].PrintAll();
                              }
                     }
                }
       }
};

void MainMenu (int &x){
  cout << "Main Menu" << endl ;
  cout << "      1.Student." << endl ;
  cout << "      2.Book." << endl ;
  cout << "      3.Library." << endl ;
  cout << "      4.Exit." << endl ;

   bool choiceValid  = false ;
   while(choiceValid == false){
      cin >> x;
      if (x>=1 && x<= 5 ){
        choiceValid = true ;
      } else {
        cout << "invalid entry : enter again:<<" << endl ;
      }
   }
}

void StudentMenu (Library &L1){
  cout << "Student Sub-Menu" << endl ;
  cout << "    1.  Add New Student." << endl ;
  cout << "    2.  Delete Existing Student." << endl ;
  cout << "    3.  Show all Student." << endl ;
  bool choiceValid  = false ;
  int x = 0 ;
   while(choiceValid == false){
      cin >> x;
      if (x>=1 && x<= 3 ){
        choiceValid = true ;
      } else {
        cout << "invalid entry : enter again:<<" << endl ;
      }
   }

   switch (x){
 case 1:
    cout << "add student:::" << endl ;
    L1.stud1.AddStudent();
   break ;
 case 2:
    cout<< "delete student:::" << endl ;
    L1.stud1.DeleteStudent();
    break;
 case 3 :
    L1.stud1.PrintAll();
    break ;
   }

}

void BookMenu (Library &L1){
  cout << "Book Sub-Menu" << endl ;
  cout << "    1.  Add New Book." << endl ;
  cout << "    2.  Delete Existing Book." << endl ;
  cout << "    3.  Show Particular Book." << endl ;
  cout << "    4.  Show All Books." << endl ;
  cout << "    5.  Sort Books in Ascending order." << endl ;
  cout << "    6.  Sort Books in Descending order." << endl ;


  bool choiceValid  = false ;
  int x = 0 ;
   while(choiceValid == false){
      cin >> x;
      if (x>=1 && x<= 6 ){
        choiceValid = true ;
      } else {


        cout << "invalid entry : enter again:<<" << endl ;
      }
   }

  switch (x){
 case 1:
    cout<<"Add New book :::" << endl ;
    L1.thisbooklist.AddNewBook();
    break ;
 case 2:
    cout <<"Delete Existing Book :::" << endl ;
    L1.thisbooklist.DeleteAll();
    break ;
 case 3 :
    cout << "Show Particular Book :::" << endl ;
       L1.thisbooklist.PrintPerticularBook() ;
     break ;
 case 4:
    cout << "Show All Books :::" << endl ;
     L1.thisbooklist.PrintAll();
     break ;
 case 5 :
    cout << "Sort in ascending order :::" << endl ;
     L1.thisbooklist.ascendSorting();
     break ;
 case 6 :
     cout << "Sort in dscending order :::" << endl ;
     L1.thisbooklist.dscendSorting() ;
     break ;
  }


}


void LibraryMenu (Library &L1){
  cout << "Library Sub-Menu" << endl ;
  cout << "    1.  Issue a Book." << endl ;
  cout << "    2.  Return a Book." << endl ;
  cout << "    3.  Print Issued Books." << endl ;


  bool choiceValid  = false ;
  int x = 0 ;
   while(choiceValid == false){
      cin >> x;
      if (x>=1 && x<= 3 ){
        choiceValid = true ;
      } else {
        cout << "invalid entry : enter again:<<" << endl ;
      }
   }

   switch (x){
case 1:
     L1.issuebook() ;
    break ;
case 2 :
    L1.returnbook() ;
    break ;
case 3 :
     L1.showissuedbooks() ;
    break ;

   }

}


int main(){
   int x   = 0;
   Library L1 ;


   while(x!=4){
   MainMenu(x) ;
       system("CLS") ;
   switch (x){
   case 1:
       cout << "in case 1" << endl ;
        StudentMenu(L1) ;
        system("pause") ;
       break;
   case 2 :
       cout << "in case 2" << endl ;
       BookMenu(L1) ;
        system("pause") ;
       break ;
   case 3 :
      cout << "in case 4" << endl ;
      LibraryMenu(L1) ;
       system("pause") ;
      break ;
   case 4 :
       cout << "about to exit program " << endl ;
       break;
   }
   }

}
