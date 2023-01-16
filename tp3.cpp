#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Contact {
private:
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
public:
    Contact(string firstName, string lastName, string nickname, string phoneNumber) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->nickname = nickname;
        this->phoneNumber = phoneNumber;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getNickname() {
        return nickname;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }
};

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact* contacts[MAX_CONTACTS];
    int oldestContactIndex;
public:
    PhoneBook() {
        oldestContactIndex = 0;
        for (int i = 0; i < MAX_CONTACTS; i++) {
            contacts[i] = nullptr;
        }
    }

    void addContact(Contact* contact) {
        if (contacts[oldestContactIndex] != nullptr) {
            delete contacts[oldestContactIndex];
        }
        contacts[oldestContactIndex] = contact;
        oldestContactIndex = (oldestContactIndex + 1) % MAX_CONTACTS;
    }

    Contact* getContact(int index) {
        if (index < 0 || index >= MAX_CONTACTS) {
            return nullptr;
        }
        return contacts[index];
    }

    void displayContacts() {
        for (int i = 0; i < MAX_CONTACTS; i++) {
            if (contacts[i] == nullptr) {
                cout << "|   -   |   -   |   -   |   -   |" << endl;
            } else {
                string firstName = contacts[i]->getFirstName();
                if (firstName.length() > 10) {
                    firstName = firstName.substr(0, 9) + ".";
                }
                string lastName = contacts[i]->getLastName();
                if (lastName.length() > 10) {
                    lastName = lastName.substr(0, 9) + ".";
                }
                string nickname = contacts[i]->getNickname();
                if (nickname.length() > 10) {
                    nickname = nickname.substr(0, 9) + ".";
                }
                cout << "|" << setw(3) << i << " |" << setw(10) << firstName << " |" << setw(10) << lastName << " |" << setw(10) << nickname << " |" << endl;
            }
        }
    }
};

int main() {
    PhoneBook phoneBook;

    while (true) {
        string command;
        cout << "Enter a command (ADD, SEARCH, EXIT): ";
        cin >> command;

        if (command == "ADD") {
            string firstName, lastName, nickname, phoneNumber;
            cout << "Enter the first name: ";
            cin >> firstName;
            cout << "Enter the last name: ";
            cin >> lastName;
            cout << "Enter the nickname: ";
            cin >> nickname;
            cout << "Enter the phone number: ";
            cin >> phoneNumber;
            phoneBook.addContact(new Contact(firstName, lastName, nickname, phoneNumber));
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();
            int index;
            cout << "Enter the index of the entry to display: ";
            cin >> index;
            Contact* contact = phoneBook.getContact(index);
            if (contact == nullptr) {
                cout << "Invalid index." << endl;
            } else {
                cout << "First name: " << contact->getFirstName() << endl;
                cout << "Last name: " << contact->getLastName() << endl;
                cout << "Nickname: " << contact->getNickname() << endl;
                cout << "Phone number: " << contact->getPhoneNumber() << endl;
            }
        }
    }
}