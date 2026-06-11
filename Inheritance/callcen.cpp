#include <iostream>
using namespace std;

#define MAX 50  // maximum 50 callers

struct Caller {
    string name;
    string issue;
};
Caller queueArr[MAX];
int front = -1, rear = -1;

// Function to check empty
bool isEmpty() {
    return (front == -1 || front > rear);
}
// Function to check full
bool isFull() {
    return (rear == MAX - 1);
}
// Add caller (enqueue)
void addCaller() {
    if (isFull()) {
        cout << "Queue is FULL! No more callers can wait.\n";
        return;
    }
    string name, issue;
    cout << "Enter Caller Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter Issue: ";
    getline(cin, issue);

    if (front == -1) front = 0;  // first element
    queueArr[++rear] = {name, issue};

    cout << "Caller added to waiting line.\n";
}
// Serve caller (dequeue)
void serveCaller() {
    if (isEmpty()) {
        cout << "No callers waiting.\n";
        return;
    }
    cout << "Serving Caller: " << queueArr[front].name
         << " | Issue: " << queueArr[front].issue << endl;
    front++;
}
// Display queue
void displayQueue() {
    if (isEmpty()) {
        cout << "No callers in queue.\n";
        return;
    }
    cout << "\n--- Current Waiting Callers ---\n";
    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". " << queueArr[i].name
             << " - " << queueArr[i].issue << endl;
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\n===== CALL CENTER MENU =====\n";
        cout << "1. Add Caller to Queue\n";
        cout << "2. Serve Caller\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCaller(); 
            break;
            case 2: serveCaller(); 
            break;
            case 3: displayQueue();
            break;
            case 4: cout << "Thank you! Program closed.\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}