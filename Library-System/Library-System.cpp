#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

//==================Variables============================
const int sizeOfLibrary = 10;

string Titles[sizeOfLibrary] = { "C++","Java","Python" };
string Author[sizeOfLibrary] = { "Ahmed","Ehab","Mohy" };
int IDs[sizeOfLibrary] = {1,2,3};
bool Status[sizeOfLibrary] = { true,false,true };

int numOfBooks = 3;

//==================Functions============================

//==================Main Menu============================
void mainMenu() {
	cout << "1- Display All Books" << endl;
	cout << "2- Add New Book" << endl;
	cout << "3- Borrow Book" << endl;
	cout << "4- Return Book" << endl;
	cout << "5- Update Book" << endl;
	cout << "6- Delete Book" << endl;
	cout << "7- Exit" << endl;
	cout << "Please enter your choice: ";
}


//==================Confirm Menu============================
void confirmMenu() {
	cout << "\nDo you wanna confirm? " << endl;
	cout << "1- yes" << endl;
	cout << "2- no" << endl;
	cout << "Enter your choice: ";
}
//==================Update Menu============================
void updateMenu() {
	cout << "\nWhat do you wanna update?" << endl;
	cout << "1- Book Title" << endl;
	cout << "2- Book Author" << endl;
	cout << "Enter your choice: ";
}

//==================Display One Book============================
void displayOneBooks(string t,string a,int i,bool s) {
		string bookStatus = s ? "Available" : "Not available";
		cout << "\nBook Info:\n\n";
		cout << "Title: " << t << endl;
		cout << "Author: " << a << endl;
		cout << "ID: " << i << endl;
		cout << "Status: " << bookStatus << endl;
		cout << "=====================================\n";
}

//==================Display All Books============================
void displayAllBooks() {
	for (int i = 0;i < numOfBooks;i++) {
		displayOneBooks(Titles[i], Author[i], IDs[i], Status[i]);
	}
}

//==================Add New Book============================
void addNewBook() {
	if (numOfBooks == sizeOfLibrary) {
		cout << "Sorry the library is full, you can't add a new book :(" << endl;
		return;
	}
	else {
		string title, author;
		cout << "Please enter book name: ";
		cin.ignore();
		getline(cin, title);
		Titles[numOfBooks] = title;
		cout << "Please enter book author: ";
		getline(cin, author);
		Author[numOfBooks] = author;
		Status[numOfBooks] = true;
		IDs[numOfBooks] = numOfBooks + 1;
		numOfBooks++;
		cout << "\nBook is added successfully!\n\n\n";
	}
}

//==================Search============================
int search(int id) {
	for (int i = 0;i < numOfBooks;i++) {
		if (IDs[i] == id) {
			return i;
		}
	}
	return -1;
}

//==================Borrow Book============================
void borrowBook() {
	int id=-1, index=-1,choice;
	cout << "\nPlease enter the ID of the book you want to borrow: ";
	cin >> id;
	index= search(id);
	if (index == -1) {
		cout << "\nThis book cannot be found\n\n\n";
	}
	else {
		if (Status[index]) {
		displayOneBooks(Titles[index], Author[index], IDs[index], Status[index]);
		confirmMenu();
		cin >> choice;
		if (choice == 1) {
			cout << "\nBook is borrowed successfully :)\n\n\n";
			Status[index] = false;
		}
	    }
		else {
			cout << "\nSorry but currently this book is not available :(\n\n\n";
		}
	}
}

//==================Return Book============================
void returnBook() {
	int id = -1, index = -1, choice;
	cout << "\nPlease enter the ID of the book you want to return: ";
	cin >> id;
	index = search(id);
	if (index == -1) {
		cout << "\nThis book cannot be found" << endl;
	}
	else {
		if (Status[index]==false) {
			displayOneBooks(Titles[index], Author[index], IDs[index], Status[index]);
			confirmMenu();
			cin >> choice;
			if (choice == 1) {
				cout << "\nBook is returned successfully :)\n\n\n" << endl;
				Status[index] = true;
			}
		}
		else {
			cout << "\nThis book is already returned\n\n\n";
		}
	}
}

//==================Update Book============================
void updateBook() {
	int id = -1, index = -1, choice1,choice2;
	string str;
	cout << "\nPlease enter the ID of the book you want to update: ";
	cin >> id;
	index = search(id);
	if (index == -1) {
		cout << "\nThis book cannot be found" << endl;
	}
	else {
			displayOneBooks(Titles[index], Author[index], IDs[index], Status[index]);
			confirmMenu();
			cin >> choice1;
			if (choice1 == 1) {
				updateMenu();
				cin >> choice2;
				cin.ignore();
				if (choice2 == 1) {
					cout << "Please enter the new title: ";
					getline(cin, str);
					Titles[index] = str;
				}
				else if (choice2 == 2) {
					cout << "Please enter the new author name: ";
					getline(cin, str);
					Author[index] = str;
				}
				cout << "\nBook updated successfully :)\n\n\n" << endl;
			}
	}
}

//==================Delete Book============================
void removeBook() {
	int id = -1, index = -1, choice;
	cout << "\nPlease enter the ID of the book you want to delete: ";
	cin >> id;
	index = search(id);
	if (index == -1) {
		cout << "\nThis book cannot be found" << endl;
	}
	else {
			displayOneBooks(Titles[index], Author[index], IDs[index], Status[index]);
			confirmMenu();
			cin >> choice;
			if (choice == 1) {
				if (numOfBooks == id) {
					numOfBooks--;
				}
				else {
					for (int i = index;i < numOfBooks;i++) {
						Titles[i] = Titles[i + 1];
						Author[i] = Author[i + 1];
						IDs[i] = IDs[i + 1];
						Status[i] = Status[i + 1];
					}
					numOfBooks--;
				}
			}
			cout << "\nBook is deleted successfully :)\n\n\n";
	}
}

int main() {
	int choice;
	bool flag = true;
	while (flag) {
		mainMenu();
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: displayAllBooks();break;
		case 2: addNewBook();break;
		case 3: borrowBook();break;
		case 4: returnBook();break;
		case 5: updateBook();break;
		case 6: removeBook();break;
		case 7: flag = false;break;
		default: cout << "Value not valid!" << endl;
		}
		system("pause");
		system("cls");
	}
    return 0;
}