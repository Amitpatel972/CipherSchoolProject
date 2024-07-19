#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

// Define classes for Message and Group (placeholders)
class Message {
    // Define Message class as needed
};

class Group {
    // Define Group class as needed
};

class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {}
    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};

// MAP user-name to USER
map<string, User> mapUserName;

// MAPPING ONE FRIEND TO ANOTHER FRIEND
map<string, set<string> Friends;

void addUser(string userName, User user) {
    if (mapUserName.find(userName) == mapUserName.end()) {
        mapUserName[userName] = user;
    } else {
        cout << "UserName Already Taken\n";
    }
}

void makeThemFriend(string userName1, string userName2) {
    Friends[userName1].insert(userName2);
    Friends[userName2].insert(userName1);
}

void displayAllUsers() {
    for (auto& entry : mapUserName) {
        cout << "UserName: " << entry.first << ", "
             << "Name: " << entry.second.firstName << " " << entry.second.lastName << "\n";
    }
}

void displayAllFriendships() {
    for (auto& entry : Friends) {
        cout << entry.first << " -> ";
        for (auto& friendName : entry.second) {
            cout << friendName << " ";
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

    displayAllUsers();
    displayAllFriendships();

    return 0;
}

