#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// FRIENDSHIP
// 1.) TEST OUT DIFFERENT CASES OF THESE FRIENDSHIPS
// 2.) MAKE THE CODE BY TAKING USER INPUT
// 3.) CREATE CLASSES OF MESSAGES AND GROUP

// 1.) Message
// a.) SENDER
// b.) RECEIVER
// c.) CONTENT
// d.) TIMESTAMP

// Creating a Message Class
class Message {
public:
    string sender;
    string receiver;
    string content;

    Message() {}

    Message(string sender, string receiver, string content) {
        this->sender = sender;
        this->receiver = receiver;
        this->content = content;
    }

    void displayMessage() {
        // Displaying the individual messages
        cout << sender << " -> " << receiver << ": " << content << endl;
    }
};

// Creating a Social Media Group Class
class SocialGroup {
public:
    string GroupName;
    vector<pair<string, string>> messages;
    vector<string> Members;

    // Group Admin Functionality Add
    SocialGroup() {};

    // Defining the Social Media group Constructor
    SocialGroup(string groupName) {
        this->GroupName = groupName;
    }

    // Adding the member into the group
    void addMember(string userName) {
        Members.push_back(userName);
    }

    // Adding the messages into the group
    void addMessage(string userName, string content) {
        messages.push_back({userName, content});
    }
};

class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {};

    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};

// MAP username to USER
map<string, User> mapUserName;

// MAPPING ONE Friend TO ANOTHER FRIEND
map<string, set<string>> Friends;

void addUser(string userName, User user) {
    if (mapUserName.find(userName) == mapUserName.end()) {
        mapUserName[userName] = user;
    } else {
        cout << "UserName Already Taken" << endl;
    }
}

void makeThemFriend(string userName1, string userName2) {
    // Mapping first friend to another
    Friends[userName1].insert(userName2);
    Friends[userName2].insert(userName1);
}

void displayAllUser() {
    for (auto i : mapUserName) {
        cout << "UserName: " << i.first << " "
             << i.second.firstName << "\n";
    }
}

void displayAllFriendships() {
    // username1 -------> username2;
    for (auto i : Friends) {
        cout << i.first << ":" << "\n";
        set<string> friends = i.second;
        for (auto j : friends) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    User alice("Alice", "Mishra", 30, "Female");
    User bob("Bob", "Ali", 27, "Male");

    addUser("Alice", alice);
    addUser("Bob", bob);
    makeThemFriend("Alice", "Bob");

    // Chat Box Functionality
    Message message("Alice", "Bob", "Hey, Please Wake up early Tomorrow");
    message.displayMessage();

    // Social Groups Functionality
    // Creating an object of SocialGroup class
    SocialGroup group1("Goa trip");

    // Adding a member into the system
    group1.addMember("Alice");

    // Adding message to the group
    group1.addMessage("Alice", "Looking forward to the trip!");

    // Display all users
    displayAllUser();

    // Display all friendships
    displayAllFriendships();

    return 0;
}

