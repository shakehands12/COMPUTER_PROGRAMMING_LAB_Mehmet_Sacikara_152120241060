#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;

};

Song* head = nullptr;
Song* current = nullptr;

void addSong(string title, string artist, int r1, int r2, int r3) {
    Song* newSong = new Song();

    newSong->title = title;

    newSong->artist = artist;

    newSong->ratings[0] = r1;
    newSong->ratings[1] = r2;

    newSong->ratings[2] = r3;

    newSong->next = nullptr;
    newSong->prev = nullptr;

    if (head == nullptr) {
        head = newSong;
        current = head;
        cout << "Song added: " << title << endl;
        return;
    }
    Song* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }




    temp->next = newSong;
    newSong->prev = temp;

    cout << "Song added: " << title << endl;
}

void goNext() {
    if (current == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    if (current->next == nullptr) {
        cout << "This is the last song." << endl;
        return;
    }
    current = current->next;
    cout << "Now playing: " << current->title << endl;
}

void goPrev() {
    if (current == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    if (current->prev == nullptr) {
        cout << "the first song." << endl;
        return;
    }
    current = current->prev;
    cout << "Now playing: " << current->title << endl;
}

void removeCurrent() {
    if (current == nullptr) {
        cout << "Nothing to remove!" << endl;
        return;
    }

    cout << "Removing: " << current->title << endl;

    Song* toDelete = current;

    if (toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    } else {
        head = toDelete->next;
    }

    if (toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
    }

    if (toDelete->next != nullptr) {
        current = toDelete->next;
    } else {
        current = toDelete->prev;
    }

    delete toDelete;
}

void display() {
    if (head == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    cout << "\n====== PLAYLIST ======" << endl;

    Song* temp = head;
    int i = 1;

    while (temp != nullptr) {
        if (temp == current) {
            cout << "-> ";
        } else {
            cout << " ";
        }

        cout << i << ". " << temp->title << "- " << temp->artist << endl;
        cout << " Ratings:";

        for (int j = 0; j < 3; j++) {
            cout << temp->ratings[j];
            if (j < 2) cout << ", ";
        }
        cout << endl;

        temp = temp->next;
        i++;
    }

    cout << "===================\n" << endl;
}

int main() {
    addSong("Blinding Lights", "The Weekend", 9, 8, 10);
    addSong("Levitating", "Dua Lipa", 7, 9, 8);
    addSong("Stay", "The Kid LAROI", 8, 7, 9);
    addSong("Peaches", "Justin Bieber", 6, 8, 7);

    display();

    int choice;

    do {
        cout << "1. Next" << endl;
        cout << "2. Previous" << endl;
        cout << "3. Remove current" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            goNext();
        } else if (choice == 2) {
            goPrev();
        } else if (choice == 3) {
            removeCurrent();
            display();
        } else if (choice == 4) {
            display();
        }

    } while (choice != 0);

    return 0;
}



