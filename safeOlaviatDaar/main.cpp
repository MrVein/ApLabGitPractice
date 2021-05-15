//implementation with struct (classic way)
#include <iostream>
#include <unistd.h>
using namespace std;

#define MAX 10
#define DELAY 3000000
typedef struct node {
    int value;
    int priority;
    struct node* next;
    struct node* prev;
}Node;

int length(Node*head);
void enQueue(Node* &head );
void push(Node* &head , int new_data , int priority);
void insertAfter(Node* &prev_node , int new_data , int priority);
void append(Node* &prev_node, int new_data , int priority);
//---------------------------------------------------------
void deQueue(Node* &head);
//---------------------------------------------------------
int menu();
int getOption();
void printQueue(Node* head);
bool isEmpty(Node* head);
bool isFull(Node* &head);
//----------------------------------
void removePriority(Node* &head);


int main(){
    Node* head = nullptr;

    while(int option = menu()){
        switch(option){
            case 1:{

                enQueue(head);
                break;

            } case 2:{

                deQueue(head);
                break;

            } case 3:{

                isEmpty(head);
                break;

            } case 4: {

                isFull(head);
                break;
            } case 5:{

                removePriority(head);
                break;

            } case 6:{

                printQueue(head);
                break;

            }
            default: break;
        }


    } system("clear");
}

int menu(){
    system("clear");
    cout << "Priority Queue :" << endl;
    cout << "\t\t1. enQueue" << endl;
    cout << "\t\t2. deQueue" << endl;
    cout << "\t\t3. isEmpty" << endl;
    cout << "\t\t4. isFull" << endl;
    cout << "\t\t5. removePriority" << endl;
    cout << "\t\t6. printQueue" << endl << endl;
    cout << "\t\t0. exit" << endl;

    return getOption();
}

void enQueue(Node* &head ){
    if(length(head) >= 10){
        system("clear");
        cout << "The Queue is Full .You shall not insert another node" << endl;
        usleep(DELAY);
        system("clear");
        return;
    }
    int new_data , priority;
    system("clear");
    cout << "Enter the value : " << endl;
    cin >> new_data;
    cout << "Enter priority : " << endl;
    cin >> priority;
    system("clear");

    if(head == nullptr || head->priority >= priority){
        push(head , new_data , priority);
        return;
    }
    Node* prev_node = head;
    while(prev_node->next != nullptr && prev_node->next->priority < priority)
        prev_node = prev_node->next;

    if(prev_node->next == nullptr) {
        append(prev_node , new_data , priority);
        return;
    }
    insertAfter(prev_node , new_data , priority);
}

int getOption(){
    int option;
    cin >> option;
    return option;
}

void printQueue(Node* head){
    system("clear");
    Node* temp = head;
    if(head == nullptr){
        cout << "Nothing to Show You !The Queue is Empty " << endl;
        usleep(DELAY);
        return;
    }
    while(temp != nullptr){
        cout<< "__" <<"\tNode value : " << temp->value << endl;
        cout<< "\tNode priority : " << temp->priority << endl << endl;
        temp = temp->next;

    }
    cout << "0. Back to menu" << endl;
    while(getOption());
}
//OK
void deQueue(Node* &head){
    if(head == nullptr){
        system("clear");
        cout << "Ops .The Queue is empty .You shall not \"Empty the Empty\" :)" << endl;
        usleep(DELAY);
        return;
    }
    Node* temp = head;
    if(temp->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    while(temp->next != nullptr)
        temp = temp->next;

    Node* temp2 = temp->prev;
    temp2->next = nullptr;
    delete temp;
    cout << "Front Node deleted successfully " << endl;
    usleep(DELAY);
}
//OK
bool isEmpty(Node* head){
    system("clear");
    if(head == nullptr){
        cout << "The Queue is Empty !" << endl;
        usleep(DELAY);
        return true;
    } else {
        cout << "The Queue is Not Empty !" << endl;
        usleep(DELAY);
        return false;

    }
}

bool isFull(Node* &head){
    system("clear");
    int count = length(head);
    if(!(count - MAX)){
        cout<< "The Queue is FULL !" << endl;
        usleep(DELAY);
        return true;
    } else {
        cout << "The Queue is NOT FULL !" << endl;
        usleep(DELAY);
        return false;
    }
}

void removePriority(Node* &head){
    if(head == nullptr){
        cout << "Queue is empty .Nothing to be deleted !" << endl;
        usleep(DELAY);
        system("clear");
        return;
    }
    int priority;
    system("clear");
    cout << "Enter priority : " << endl;
    cin >> priority;
    Node* temp = head;
    bool flag = false;
    while(temp != nullptr ) {
        if(temp->priority == priority){
            if(temp == head){
                head = temp->next;
                head->prev = nullptr;
                delete temp;
                temp = head;
                flag = true;

            }else if(temp->next == nullptr){
                temp = temp->prev;
                delete temp->next;
                temp->next = nullptr;
                return;

            } else {
                Node *temp2 = temp->prev;
                temp2->next = temp->next;
                temp2 = temp->next;
                temp2->prev = temp->prev;
                delete temp;
                temp = head;
                flag = true;

            }

        }
        temp = temp->next;

    }
    if(!flag){
        system("clear");
        cout << "No such priority found in the Queue " << endl;
        usleep(DELAY);
        return;
    }
}

void push(Node* &head_ref , int new_data , int priority){
    Node* new_node = new Node;

    new_node->value = new_data;
    new_node->priority = priority;

    new_node->next = (head_ref);
    new_node->prev = nullptr;

    if (head_ref != nullptr)
        head_ref->prev = new_node;

    head_ref = new_node;
}

void insertAfter(Node* &prev_node, int new_data , int priority){
    Node* new_node = new Node;

    new_node->value = new_data;
    new_node->priority = priority;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != nullptr)
        new_node->next->prev = new_node;
}

void append( Node* &prev_node, int new_data , int priority){
    Node* new_node = new Node;

    new_node->value = new_data;
    new_node->priority = priority;

    prev_node->next = new_node;
    new_node->prev = prev_node;

    new_node->next = nullptr;

}

int length(Node* head){
    int count = 0;
    while(head != nullptr){
        head = head->next;
        count++;
    }
    return count;
}










//#include <iostream>
//using namespace std;
//
//class queue {
//public:
//    queue()
//    {
//        nodeNumber = 0;
//        _rear = nullptr;
//        _front = nullptr;
//    }
//    void enQueue(int value , int priority);
//    void deQueue(int value , int priority);
//    void isEmpty();
//    void isFull();
//    void removePriority(int priority);
//
//private:
//    typedef struct node {
//        int _value;
//        int _priority;
//        struct node* _next;
//        struct node* _prev;
//    }Node;
//    int nodeNumber;
//    Node* _rear;
//    Node* _front;
//    Node* setMemory();
//};
//
//queue::Node* queue::setMemory()
//{
//    return new Node;
//}
//
//
//void queue::enQueue(int value , int priority)
//{
//    if(_rear == nullptr){
//        Node*setMemory(int value);
//
//    }
//
//
//}
//
//
//int main()
//{
//
//    return 0;
//}