#include <iostream> 
using namespace std; 
  


// task 1 and task 2 are implemented here.
//2019511 taimoor ahmad


class myBinarySearchTreeClass  
{ 
    int data; 
    myBinarySearchTreeClass *left, *right; 
  
public: 
  
    myBinarySearchTreeClass(){
        data = 0;
        left = NULL;
        right = NULL;
    
    }
  
    myBinarySearchTreeClass(int value){
        data = value;
        left = right = NULL;
    } 
  
    myBinarySearchTreeClass* Insert(myBinarySearchTreeClass* root, int value){
        if (!root)
        {
            return new myBinarySearchTreeClass(value);
        }

       
        if (value > root->data)
        {
            root->right = Insert(root->right, value);
        }
        else
        {
            root->left = Insert(root->left, value);
        }

        return root;
    }
  


    void DisplayInorder(myBinarySearchTreeClass* root)
    {
        if (!root) {
            return;
        }
        DisplayInorder(root->left);
        cout << root->data << endl;
        DisplayInorder(root->right);
    }

    void DisplayPostorder(myBinarySearchTreeClass* root)
    {
        if (!root) {
            return;
        }
        DisplayPostorder(root->left);
        DisplayPostorder(root->right);
        cout << root->data << endl;
    }
    void DisplayPreorder(myBinarySearchTreeClass* root)
    {
        if (!root) {
            return;
        }
        cout << root->data << endl;
        DisplayPreorder(root->left);
        DisplayPreorder(root->right);
        
    }

    void makeDeletion(myBinarySearchTreeClass*& nodePtr) {
        myBinarySearchTreeClass* tempNodePtr;
        if (nodePtr == NULL) {
            cout << "Cannot delete empty node.\n";
        }
        else if (nodePtr->right == NULL) {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left;
            delete tempNodePtr;
        }
        else if (nodePtr->left == NULL) {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }
        else {

            tempNodePtr = nodePtr ->right;
            while (tempNodePtr->left) {
                tempNodePtr = tempNodePtr->left;
            }
            tempNodePtr->left = nodePtr->left;
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }
    }

        
    

    void deleteNode(int num, myBinarySearchTreeClass *& nodePtr) {
        if (num < nodePtr->data) {
            deleteNode(num, nodePtr->left);
        }
        else if (num > nodePtr->data) {
            deleteNode(num, nodePtr->right);
        }
        else {
            makeDeletion(nodePtr);
        }
    }
    void searchNode(int num, myBinarySearchTreeClass*& nodePtr) {
        if (num < nodePtr->data) {
            searchNode(num, nodePtr->left);
        }
        else if (num > nodePtr->data) {
            searchNode(num, nodePtr->right);
        }
        else if(num == nodePtr->data) {
            cout << "data found" << endl;
        }
        else {
            cout << "data not found" << endl;
        }
    }

}; 
  

  
int main() 
{ 
    myBinarySearchTreeClass b, *root = NULL; 
    root = b.Insert(root, 50); 

    int choice = 2, choice2 = 2;;
    int dataEnter;

    while (choice >= 1 && choice <= 3) {
        cout << "Enter : " << endl;
        cout << "1 to insert : " << endl;
        cout << "2 to delete : " << endl;
        cout << "3 to search : " << endl;
        cout << "4 to display : " << endl;
        cin >> choice;

        if (choice==1) {
            cout << "enter data" << endl;
            cin >> dataEnter;
            b.Insert(root, dataEnter);
        }
        else if (choice==2) {
            cout << "enter data" << endl;
            cin >> dataEnter;
            b.deleteNode( dataEnter,root);
        }
        else if (choice == 3){
            cout << "enter data" << endl;
            cin >> dataEnter;
            b.searchNode(dataEnter,root);
        }
        else if (choice == 4) {
            cout << "enter : " << endl;
            cout << "1 to display inorder " << endl;
            cout << "2 to display preorder " << endl;
            cout << "3 to display postorder " << endl;
            cin >> choice2;


            if (choice2 == 1) {
                b.DisplayInorder(root);
            }
            else if (choice2==2) {
                b.DisplayPreorder(root);
            }
            else if (choice2==3) {
                b.DisplayPostorder(root);
            }


        }


      
    }
    return 0; 
} 
  