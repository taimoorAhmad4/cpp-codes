// this program was written by Taimoor Ahmad 2019511 and Muteeb ur Rehman 2019419

#include<iostream>
#include <string>
using namespace std;

struct directoryData {
	string phoneNumber;
	string Name;
	string address;
	string email;
};

class node{
public:
	directoryData* data = new directoryData;
	node* left;
	node* right;
	int height;
};

//function definitions
int   max(int val1, int val2);
int   height(node* thisNode);
node* newNode(directoryData* data);
node* rotateRight(node* y);
node* rotateLeft(node* x);
int   getBalance(node* thisNode); 
node* getMinVal(node* thisNode);
node* insert(node* thisNode, directoryData* data);
void  preOrder(node* root);
void  inOrder(node* root);
void  postOrder(node* root);
void  displayMenu();
bool  searchByName(string searchThisName, node* root);
bool  searchByAddress(string searchThisAddress, node* root);
bool  searchByEmail(string searchThisEmail, node* root);
node* deleteNode();



int main()
{
	node* root = NULL;
	directoryData *dataEnter=new directoryData;
	int choice = -1;

	while (choice!=-7) {
		
		displayMenu();
		cin >> choice;
		cin.ignore();
		system("CLS");

		if (choice == 1) {
			cout << "enter number \n";
			getline(cin, dataEnter->phoneNumber);
			cout << "enter name \n";
			getline(cin, dataEnter->Name);
			cout << "enter address \n";
			getline(cin, dataEnter->address);
			cout << "enter email \n";
			getline(cin, dataEnter->email);

			root = insert(root, dataEnter);
			
		}
		else if (choice == 2) { 
			string findThisData;
			bool dataFound = false;
			if (root != NULL) {

				cout << "enter \n";
				cout << "1 to search by name \n";
				cout << "2 to search by address \n";
				cout << "3 to search by email \n";
				cout << "any other number to cancle search \n";
				cin >> choice;
				cin.ignore();
				system("CLS");
				if (choice == 1) {
					cout << "search by name selected : \n" << endl;
					cout << "enter name : \n ";
					getline(cin, findThisData);
					dataFound = searchByName(findThisData, root);
				}
				else if (choice == 2) {
					cout << "search by address selected : \n" << endl;
					cout << "enter address : \n ";
					getline(cin, findThisData);
					dataFound = searchByAddress(findThisData, root);

				}
				else if (choice == 3) {
					cout << "search by email selected : \n" << endl;
					cout << "enter email : \n ";
					getline(cin, findThisData);
					dataFound = searchByEmail(findThisData, root);
				}
				else {
					cout << "search cancled \n";
				}

				if (choice >= 1 && choice <= 3) {
					if (dataFound == true) {
						cout << "data found" << endl;
					}
					else {
						cout << "data not found" << endl;
					}
				}
			}
			else {
				cout << "there is nothing to search " << endl;
			}


		}
		else if (choice == 3) { // delete
			if (root != NULL) {
				string deleteThisNumber;
				cout << "enter number you want to delete \n";
				getline(cin, deleteThisNumber);

				//call related function
			}
			else {
				cout << "there is nothing to delete" << endl;
			}
			
		}
		else if (choice == 4) { // display in inOrder
			if (root != NULL) {


				system("CLS");
				cout << "enter : \n";
				cout << "1 for in-order \ n ";
				cout << "2 for pre-order \ n ";
				cout << "3 for post-order \ n ";
				cin >> choice;
				cin.ignore();
				if (choice == 1) {
					system("CLS");
					cout << "in-order : \n";
					inOrder(root);
				}
				else if (choice == 2) {
					system("CLS");
					cout << "pre-order : \n";
					preOrder(root);
				}
				else if (choice == 3) {
					system("CLS");
					cout << "post-order : \n";
					postOrder(root);
				}
			}
			else {
				cout << "there is nothing to display" << endl;
			}
			
		}
		else {
			cout << "program is about to exit" << endl;
			choice = -7;
		}
	}
	

	return 0;
}

int height(node* thisNode)
{
	if (thisNode == NULL)
		return 0;
	return thisNode->height;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}

node* rotateRight(node* y)
{
	node* x = y->left;
	node* T2 = x->right;

	
	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	return x;

}


node* rotateLeft(node* x)
{
	node* y = x->right;
	node* T2 = y->left;


	y->left = x;
	x->right = T2;


	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	return y;
}

int getBalance(node* thisNode)
{
	if (thisNode == NULL)
		return 0;
	return height(thisNode->left) - height(thisNode->right);
}

node* newNode(directoryData* data)
{
	node* thisNode = new node();


	thisNode->data->Name = data->Name;
	thisNode->data->phoneNumber = data->phoneNumber;
	thisNode->data->address = data->address;
	thisNode->data->email = data->email;
	thisNode->left = NULL;
	thisNode->right = NULL;
	thisNode->height = 1; 
					
	return(thisNode);
}

node* insert(node* thisNode, directoryData* data)
{
	
	if (thisNode == NULL) 
		return newNode(data);

	
	
		if (data->phoneNumber < thisNode->data->phoneNumber)	
			thisNode->left = insert(thisNode->left, data);
		else if (data->phoneNumber > thisNode->data->phoneNumber)
			thisNode->right = insert(thisNode->right, data);
		else 
			return thisNode;
		
	
		
	thisNode->height = 1 + max(height(thisNode->left),height(thisNode->right));

	int balance = getBalance(thisNode);

		//check and adjust balance
	if (balance > 1 && data->phoneNumber < thisNode->left->data->phoneNumber) {
		return rotateRight(thisNode);
	}
		
	if (balance < -1 && data->phoneNumber > thisNode->right->data->phoneNumber) {
		return rotateLeft(thisNode);
	}
		
	if (balance > 1 && data->phoneNumber > thisNode->left->data->phoneNumber)
	{
		thisNode->left = rotateLeft(thisNode->left);
		return rotateRight(thisNode);
	}

		
	if (balance < -1 && data->phoneNumber < thisNode->right->data->phoneNumber)
	{
		thisNode->right = rotateRight(thisNode->right);
		return rotateLeft(thisNode);
	}
	
	
	return thisNode;
}

node* getMinVal(node* thisNode) {
	node* tempNode = thisNode;

	while (tempNode->left != NULL) {
		tempNode = tempNode->left;
	}
	return tempNode;
}


node* deleteNode(node* thisNode,directoryData* data) {   // data variable to delete is of directoryData data type so that we can proceed using recursion
	
	if (thisNode == NULL)
		return thisNode;

	if (data->phoneNumber < thisNode->data->phoneNumber)
		thisNode->left = deleteNode(thisNode->left, data);
	else if (data->phoneNumber > thisNode->data->phoneNumber)
		thisNode->right = deleteNode(thisNode->right, data);
	else
	{
		if ((thisNode->left == NULL) ||(thisNode->right == NULL))  // node with one or no child  
		{
			node* tempNode = thisNode->left ?
				thisNode->left :
				thisNode->right;

			
			if (tempNode == NULL)
			{
				tempNode = thisNode;
				thisNode = NULL;
			}
			else {
				thisNode->data->Name = tempNode->data->Name;
				thisNode->data->email = tempNode->data->email;
				thisNode->data->address = tempNode->data->address;
				thisNode->data->phoneNumber = tempNode->data->phoneNumber;
				thisNode->height = tempNode->height;
				thisNode->left = tempNode->left;
				thisNode->right = tempNode->right;
			}
			   
			free(tempNode);
		}
		else
		{
			
			node* tempNode = getMinVal(thisNode->right);   // this tempNode is bounded by brackets
			thisNode->data->Name = tempNode->data->Name;
			thisNode->data->email = tempNode->data->email;
			thisNode->data->address = tempNode->data->address;
			thisNode->data->phoneNumber = tempNode->data->phoneNumber;
			

			thisNode->right = deleteNode(thisNode->right,tempNode->data);
		}
	}

	if (thisNode == NULL)
		return thisNode;

	thisNode->height = 1 + max(height(thisNode->left),height(thisNode->right));

	int balance = getBalance(thisNode);


	
	if (balance > 1 &&getBalance(thisNode->left) >= 0)
		return rotateRight(thisNode);

	 
	if (balance > 1 && getBalance(thisNode->left) < 0){
		thisNode->left = rotateLeft(thisNode->left);
		return rotateRight(thisNode);
	}

 
	if (balance < -1 && getBalance(thisNode->right) <= 0)
		return rotateLeft(thisNode);

	
	if (balance < -1 && getBalance(thisNode->right) > 0){
		thisNode->right = rotateRight(thisNode->right);
		return rotateLeft(thisNode);
	}
	return thisNode;
}


void preOrder(node* root)
{
	if (root != NULL)
	{
		cout << root->data->phoneNumber << "\n ";
		cout << root->data->Name << "\n ";
		cout << root->data->address << " \n";
		cout << root->data->email << "\n \n ";

		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->data->phoneNumber << "\n ";
		cout << root->data->Name << "\n ";
		cout << root->data->address << " \n";
		cout << root->data->email << "\n \n ";
		inOrder(root->right);
	}
}


void postOrder(node* root)
{
	if (root != NULL)
	{
		
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data->phoneNumber << "\n ";
		cout << root->data->Name << "\n ";
		cout << root->data->address << " \n";
		cout << root->data->email << "\n \n ";
	}
}


void displayMenu() {
	cout << "enter " << endl;
	cout << "1 to insert " << endl;
	cout << "2 to search " << endl;
	cout << "3 to delete " << endl;
	cout << "4 to display (in-order, pre-order, post-order) " << endl;
	cout << "any other value to exit" << endl;
}

bool searchByName(string searchThisName , node * root ) {
	if (root == NULL)
	{
		return false;
	}
	else if (searchThisName < root->data->Name)
	{
		return searchByName(searchThisName, root->left);
	}
	else if (searchThisName > root->data->Name)
	{
		return searchByName(searchThisName, root->right);
	}
	else {
		return true;
	}
	
}
bool searchByAddress(string searchThisAddress, node* root) {
	if (root == NULL)
	{
		return false;
	}
	else if (searchThisAddress < root->data->address)
	{
		return searchByAddress(searchThisAddress, root->left);
	}
	else if (searchThisAddress > root->data->address)
	{
		return searchByAddress(searchThisAddress, root->right);
	}
	else {
		return true;
	}

}
bool searchByEmail(string searchThisEmail, node* root) {
	if (root == NULL)
	{
		return false;
	}
	else if (searchThisEmail < root->data->email)
	{
		return searchByEmail(searchThisEmail, root->left);
	}
	else if (searchThisEmail > root->data->email)
	{
		return searchByEmail(searchThisEmail, root->right);
	}
	else {
		return true;
	}

}
