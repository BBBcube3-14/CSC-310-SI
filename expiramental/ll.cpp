#include <iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
};

void printList(Node* head){
    Node* trav = new Node();
    trav = head;
    while (trav != NULL) {
        cout << trav->value;
        cout << " ";
        trav = trav->next;
    }
}

int main() {
    int input = 1;

    Node* trav;
    Node* head = NULL;
    Node* newNode = NULL;

    do {
        cout << "1. Insert Node";
        cout << "2. Delete Node";
        cout << "3. Search Node";
        cout << "4. Seach List";
        cin >>  input;

        if(input == 1){
            trav = new Node();
            Node* newNode = new Node();
            cout << "Enter the node's value: ";
            cin >> newNode->value;
            newNode->next;

            if(head == NULL){
                head = newNode;
            } else {
                trav = head;
                while(trav->next != NULL){
                    trav = trav->next;
                }
                trav->next = newNode;
            }
            printList(head);
        }else if(input == 2){
            
        }else if(input == 3){
            int value;
            bool found = false;
            cout << "Enter the value you are looking for: ";
            cin >> value;
            trav = head;
            while(trav->next != NULL && (found == false)){
                if(trav->value == value){
                    found == true;
                    cout << "Found";
                }
                trav = trav->next;
            }
        }
    }while(input != 0);

    // print the linked list value
    
}