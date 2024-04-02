#include <iostream>
#include <algorithm>
using namespace std;


class stack{
    struct Node{
        int data;
        struct Node* next;
        struct Node* prev;
    };
    private:
        struct Node* head = NULL;
        int leng = 0;
        struct Node* lastNode = head;
    public:
        struct Node* createNode(int data){
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = NULL;
            return newNode;
        }
        void push(int data){
            if(head == NULL){
                head = createNode(data);
                ++leng;
                lastNode = head;
                return;
            }
            struct Node* newNode = createNode(data);
            lastNode->next = newNode;
            newNode->prev = lastNode;
            lastNode = newNode;
            ++leng;
        }
        void pop(){
            struct Node* temp = lastNode->prev;
            lastNode->prev->next = NULL;
            free(lastNode);
            lastNode = temp;
            --leng;
        }
        int front(){
            return lastNode->data;
        }
        void call(){
            struct Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<' ';
                temp = temp->next;
            }
            cout<<endl;
        }
        int size(){
            return leng;
        }
        bool empty(){
            if(leng == 0) return true;
            else return false;
        }
};
class queue{
    struct Node{
        int data;
        struct Node* next;
        struct Node* prev;
    };
    private:
        struct Node* head = NULL;
        int leng = 0;
        struct Node* lastNode = head;
    public:
        struct Node* createNode(int data){
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = NULL;
            return newNode;
        }
        void push(int data){
            if(head == NULL){
                head = createNode(data);
                ++leng;
                lastNode = head;
                return;
            }
            struct Node* newNode = createNode(data);
            lastNode->next = newNode;
            newNode->prev = lastNode;
            lastNode = newNode;
            ++leng;
        }
        void pop(){
            struct Node* temp = head;
            head = head->next;
            free(temp);
            --leng;
        }
        int front(){
            if(head == NULL) return -__INT_MAX__;
            return head->data;
        }
        int size(){
            return leng;
        }
        bool empty(){
            if(leng == 0) return true;
            return false;
        }
        void call(){
            struct Node* temp = head;
            while (temp != NULL)
            {
                cout<<temp->data<<' ';
                temp = temp->next;
            }
        }
};
int main(){
    queue p;
    p.push(1);
    p.push(2);
    p.push(3);
    cout<<p.front()<<endl;
    p.pop();
    cout<<p.front()<<endl;
    p.pop();
    p.pop();
}