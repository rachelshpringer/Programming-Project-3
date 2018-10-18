#include <iostream>
#include <cstdlib>
#include <fstream>


class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;
    
    LinkedList();
    ~LinkedList();
    Node *  add(int index, int data);
    int DeleteNode(int index);
    void print();
    void output(string filename);
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

Node* LinkedList::add(int index, int data){
    
    if (index < 0) return NULL;
    
    int currIndex    =    1;
    Node* currNode    =    head;
    while (currNode && index > currIndex) {
        currNode    =    currNode->next;
        currIndex++;
    }
    
    if (index > 0 && currNode == NULL) return NULL;
    
    Node* newNode    =    new    Node;
    newNode->data    =    data;
    if (index == 0) {
        newNode->next    =    head;
        head        =    newNode;
        this->length++;
    }
    else {
        newNode->next    =    currNode->next;
        currNode->next    =    newNode;
        this->length++;
    }
    return newNode;

    
}

//This is how you delete at a specific position:
int LinkedList::DeleteNode(int index) {
    Node* prevNode    =    NULL;
    Node* currNode    =    head;
    int currIndex    =    0;
    while (currNode && currIndex<index) {
        prevNode    =    currNode;
        currNode    =    currNode->next;
        currIndex++;
    }
    if (currNode) {
        if (prevNode) {
            prevNode->next    =    currNode->next;
            delete currNode;
        }
        else {
            head        =    currNode->next;
            delete currNode;
        }
        return currIndex;
    }
    return 0;
}


void LinkedList::print(){
    Node* head = this->head;
    int i = 0;
    while(head){
        std::cout << i << ": " << head->data<<endl;
        head = head->next;
        i++;
    }
}

//This is the function that outputs to a text file:
void LinkedList::output(string filename){
    ofstream outStream;
    outStream.open(filename);
    
    cout << "Output list to: '" << filename << "'" << endl;
    
    Node* head = this->head;
    int i = 0;
    while(head){
        outStream << i << ": " << head->data<<endl;
        head = head->next;
        i++;
    }
    outStream.close();
}





int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();

    
//QUESTION 1
    list->add(0,11);
    list->add(1,10);
    list->add(2,9);
    list->add(3,8);
    list->add(4,7);
    list->add(5,6);
    list->add(6,5);
    list->add(7,4);
    list->add(8,3);
    list->add(9,2);
    list->add(10,1);
    
    list->print();
    cout << endl << endl;

    
//QUESTION 2
    list->DeleteNode(5);
    
    list->print();
    cout << endl;
    
    
//QUESTION 3
    list->add(8,100);
   
    list->print();
    cout << endl;
    
    
//QUESTION 4
    list->output("Rachel.Shpringer.lList.txt");
    cout << endl;
    
    
    
    
    return 0;
}



