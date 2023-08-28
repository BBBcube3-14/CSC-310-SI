#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    
};

int main(){
    Node* head;
    head->next = NULL;
    Node* trav;
    Node* newNode = new Node();
    for(int i = 0; i < 10; i++){
        newNode->data = i + 1;
        newNode->next = NULL;
        trav = head;
        while(trav->next != NULL){
            trav = trav->next;
        }
        trav->next = newNode;
    } 

    cout << "Printing the tree: ";
    trav = head;
    while(trav != NULL){
        cout << trav->data << " -> ";
        trav = trav->next;
    }
    return 0;
}