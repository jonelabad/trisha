#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct player {
    string nickname;
    int age;
    double score1;
    double score2;
    float ave;
};

void addRec(player newPlayer[], int i);
void viewRec(player newPlayer[]);
void computeAve(player &newPlayer);
void maxAve(const player newPlayer[]);
void minAve(const player newPlayer[]);
void openFile(player newPlayer[]);
void closeFile(player newPlayer[]);

void addRec(player newPlayer[], int i) {
    cout << "Enter nickname: ";
    cin >> newPlayer[i].nickname;
    cout << "Enter age: ";
    cin >> newPlayer[i].age;
    cout << "Enter first score: ";
    cin >> newPlayer[i].score1;
    cout << "Enter second score: ";
    cin >> newPlayer[i].score2;
    newPlayer[i].ave = (newPlayer[i].score1 + newPlayer[i].score2) / 2.0; // Compute average immediately
    cout << "Player added successfully!\n" << endl;
}

void viewRec(player newPlayer[]) {
    cout << "Player Records:\n";
 

   for (int i = 0; i < 5; i++) {
        cout << "Nickname: " << newPlayer[i].nickname
             << ", Age: " << newPlayer[i].age
             << ", First Score: " << newPlayer[i].score1
             << ", Second Score: " << newPlayer[i].score2
             << ", Average: " << newPlayer[i].ave << endl;
    }
}
void computeAve(player &newPlayer) {
    newPlayer.ave = (newPlayer.score1 + newPlayer.score2) / 2.0;
    cout << newPlayer.nickname << "'s average of two scores is: " << newPlayer.ave << endl;
}

void maxAve(const player newPlayer[]) {
    float maximumAve = newPlayer[0].ave;
    for (int i = 1; i < 5; i++) {
        if (newPlayer[i].ave > maximumAve) {
            maximumAve = newPlayer[i].ave;
        }
    }
    cout << "The player(s) with the maximum average of " << maximumAve << ":\n";
    for (int i = 0; i < 5; i++) {
        if (newPlayer[i].ave == maximumAve) {
            cout << newPlayer[i].nickname << endl;
        }
    }
}

void minAve(const player newPlayer[]) {
    float minimumAve = newPlayer[0].ave;
    for (int i = 1; i < 5; i++) {
        if (newPlayer[i].ave < minimumAve) {
            minimumAve = newPlayer[i].ave;
        }
    }
    cout << "The player(s) with the minimum average of " << minimumAve << ":\n";
    for (int i = 0; i < 5; i++) {
        if (newPlayer[i].ave == minimumAve) {
            cout << newPlayer[i].nickname << endl;
        }
    }
}

void openFile(player newPlayer[]) {
    fstream file("pla.txt", ios::in);
    if (file.is_open()) {
        int i = 0;
        while (file >> newPlayer[i].nickname >> newPlayer[i].age >> newPlayer[i].score1 >> newPlayer[i].score2) {
            newPlayer[i].ave = (newPlayer[i].score1 + newPlayer[i].score2) / 2.0;
            i++;
            if (i >= 5) break;
        }
        cout << "File opened and records loaded!" << endl;
        file.close();
    } else {
        cout << "Failed to open file, initializing empty records!" << endl;
    }
}

void closeFile(player newPlayer[]) {
    fstream file("pla.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << newPlayer[i].nickname << " "
                 << newPlayer[i].age << " "
                 << newPlayer[i].score1 << " "
                 << newPlayer[i].score2 << endl;
        }
        cout << "Player records have been written to the file successfully!" << endl;
        file.close();
    } else {
        cout << "Failed to open the file for writing." << endl;
    }
}

int main() {
    player newPlayer[5];
    int choice;

    // Optionally load file data first
    openFile(newPlayer);

    do {
        cout << "=====================\n";
        cout << "        MENU         \n";
        cout << "=====================\n";
        cout << "1. Add Record\n";
        cout << "2. View Players Record\n";
        cout << "3. Compute for Average\n";
        cout << "4. Show the Player(s) with Max Average\n";
        cout << "5. Show the Player(s) with Min Average\n";
        cout << "6. Open File\n";
        cout << "7. Close File\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    addRec(newPlayer, i);
                }
                break;

            case 2:
                viewRec(newPlayer);
                break;

            case 3:
                for (int i = 0; i < 5; i++) {
                    computeAve(newPlayer[i]);
                }
                break;

            case 4:
                maxAve(newPlayer);
                break;

            case 5:
                minAve(newPlayer);
                break;

            case 6:
                openFile(newPlayer);  // Optional: Load file records if needed
                break;

            case 7:
                closeFile(newPlayer);  // Save records to file
                break;

            case 8:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}

