#include <iostream>
#include <string>

using namespace std;


struct Package {
    string id;
    string city;
    int dims[3]; 
    Package* next;
};

Package* head = nullptr; 


struct Courier {
    string name;
    string vehicle;
};

const int SIZE = 5;
Courier myQueue[SIZE];
int front = 0;
int rear = 0;
int counter = 0;


void addPackage() {
    Package* temp = new Package();

    cout << "Enter ID: ";
    cin >> temp->id;
    cout << "Enter City: ";
    cin >> temp->city;
    cout << "Enter Dimensions (L W H): ";
    cin >> temp->dims[0] >> temp->dims[1] >> temp->dims[2];

   
    temp->next = head;
    head = temp;
    cout << "Done! Package added." << endl;
}


void addCourier() {
    if (counter == SIZE) {
        cout << "Queue is full!" << endl;
        return;
    }

    cout << "Courier Name: ";
    cin >> myQueue[rear].name;
    cout << "Vehicle: ";
    cin >> myQueue[rear].vehicle;

 
    rear = (rear + 1) % SIZE;
    counter++;
    cout << "Courier registered." << endl;
}

void dispatch() {
    if (head == nullptr || counter == 0) {
        cout << "Missing package or courier!" << endl;
        return;
    }

    
    Package* toDelete = head;
    string pID = head->id;
    string pCity = head->city;
    head = head->next;

    
    string cName = myQueue[front].name;
    front = (front + 1) % SIZE;
    counter--;

    cout << "SUCCESS: " << cName << "is going to " << pCity << " with package " << pID << endl;

    delete toDelete; 
}

void showAll() {
    cout << "\n---PACKAGES IN STACK---" << endl;
    Package* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->id << " -City: " << current->city << endl;
        current = current->next;
    }

    cout << "\n---COURIERS IN QUEUE---" << endl;
    for (int i = 0; i < counter; i++) {
        int index = (front + i) % SIZE;
        cout << "Name: " << myQueue[index].name << " [" << myQueue[index].vehicle << "]" << endl;
    }
}

int main() {
    int choice = -1;

    while (choice != 0) {
        cout << "\n--- LOGISTICS MENU ---" << endl;
        cout << "1. Add Package" << endl;
        cout << "2. Add Courier" << endl;
        cout << "3. Dispatch (Send)" << endl;
        cout << "4. Show All" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) addPackage();
        else if (choice == 2) addCourier();
        else if (choice == 3) dispatch();
        else if (choice == 4) showAll();
    }

    return 0;
}