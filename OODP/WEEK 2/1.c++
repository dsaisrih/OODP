#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;

class ArrayManager {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ArrayManager() : size(0) {}

    void insert(int element) {
        if (size < MAX_SIZE) {
            arr[size++] = element;
            cout << "Element inserted." << endl;
        } else {
            cout << "Array is full!" << endl;
        }
    }

    void deleteElement(int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                arr[i] = arr[size - 1]; // Replace with last element
                size--;
                cout << "Element deleted." << endl;
                return;
            }
        }
        cout << "Element not found!" << endl;
    }

    void search(int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                cout << "Element found at index " << i << "." << endl;
                return;
            }
        }
        cout << "Element not found!" << endl;
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void sortArray() {
        sort(arr, arr + size);
        cout << "Array sorted." << endl;
    }
};

int main() {
    ArrayManager manager;
    char choice;
    int element;

    do {
        cout << "\nMenu:\n";
        cout << "a. Insert an element\n";
        cout << "b. Delete an element\n";
        cout << "c. Search for an element\n";
        cout << "d. Display all elements\n";
        cout << "e. Sort the array\n";
        cout << "f. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Enter element to insert: ";
                cin >> element;
                manager.insert(element);
                break;
            case 'b':
                cout << "Enter element to delete: ";
                cin >> element;
                manager.deleteElement(element);
                break;
            case 'c':
                cout << "Enter element to search: ";
                cin >> element;
                manager.search(element);
                break;
            case 'd':
                manager.display();
                break;
            case 'e':
                manager.sortArray();
                break;
            case 'f':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 'f');

    return 0;
}