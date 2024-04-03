#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
template <typename type>
class stack
{
    struct Node
    {
        type data;
        struct Node *next;
        struct Node *prev;
    };

private:
    struct Node *head = NULL;
    int leng = 0;
    struct Node *lastNode = head;

public:
    struct Node *createNode(type data)
    {
        struct Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void push(type data)
    {
        if (head == NULL)
        {
            head = createNode(data);
            ++leng;
            lastNode = head;
            return;
        }
        struct Node *newNode = createNode(data);
        lastNode->next = newNode;
        newNode->prev = lastNode;
        lastNode = newNode;
        ++leng;
    }
    void pop()
    {
        if(head == NULL) return;
        if(head->next == NULL)
        {
            struct Node* temp = head->next;
            head = NULL;
            free(temp);
            return;
        }
        struct Node *temp = lastNode->prev;
        lastNode->prev->next = NULL;
        free(lastNode);
        lastNode = temp;
        --leng;
    }
    type front()
    {
        return lastNode->data;
    }
    void call()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    int size()
    {
        return leng;
    }
    bool empty()
    {
        if (leng == 0)
            return true;
        else
            return false;
    }
};

template <typename type>
class queue
{
    struct Node
    {
        type data;
        struct Node *next;
        struct Node *prev;
    };

private:
    struct Node *head = NULL;
    int leng = 0;
    struct Node *lastNode = head;

public:
    struct Node *createNode(type data)
    {
        struct Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void push(type data)
    {
        if (head == NULL)
        {
            head = createNode(data);
            ++leng;
            lastNode = head;
            return;
        }
        struct Node *newNode = createNode(data);
        lastNode->next = newNode;
        newNode->prev = lastNode;
        lastNode = newNode;
        ++leng;
    }
    void pop()
    {
        if(head == NULL) return;
        struct Node *temp = head;
        head = head->next;
        if (head == NULL)
            lastNode = head;
        free(temp);
        --leng;
    }
    type front()
    {
        if (head == NULL)
            return "";
        return head->data;
    }
    int size()
    {
        return leng;
    }
    bool empty()
    {
        if (leng == 0)
            return true;
        return false;
    }
    void call()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
    }
};

template <typename type>
class deque
{
    struct Node
    {
        type data;
        struct Node* next;
        struct Node* prev;
    };
private:
    struct Node* head = NULL;
    struct Node* lastNode = head;
    int leng = 0;
public:
    struct Node* create(type data)
    {
        struct Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void push_back(type data){
        if(head == NULL){
            head = create(data);
            lastNode = head;
            ++leng;
            return;
        }
        struct Node* newNode = create(data);
        lastNode->next = newNode;
        newNode->prev = lastNode;
        lastNode = newNode;
        ++leng;
    }
    void push_front(type data){
        if(head == NULL){
            head = create(data);
            lastNode = head;
            ++leng;
            return;
        }
        struct Node* newNode = create(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        ++leng;
    }
    void pop_back(){
        if(head == NULL) return;
        if(head->next == NULL)
        {
            struct Node* temp = head;
            head = NULL;
            free(temp);
            return;
        }
        struct Node *temp = lastNode->prev;
        lastNode->prev->next = NULL;
        free(lastNode);
        lastNode = temp;
        --leng;
    }
    void pop_front(){
        if(head == NULL) return;
        struct Node* temp = head;
        head = head->next;
        if(head == NULL)
        {
            lastNode = head;
        }
        free(temp);
        --leng;
    }
    type front()
    {
        return head->data;
    }
    type back()
    {
        return lastNode->data;
    }
    int size()
    {
        return leng;
    }
    bool empty()
    {
        if(leng == 0) return true;
        return false;
    }
    void call()
    {
        struct Node* temp = head;
        while(temp != NULL)
        {
            std::cout<<temp->data<<' ';
            temp = temp->next;
        }
    }
};

int isValidHTMLTags(char* html, stack<char*> p) {
    // Duyệt qua từng ký tự trong chuỗi HTML
    char* token = strtok(html, ">"), * subToken;
    while (token != NULL) {
        subToken = strchr(token, '<');
        if (subToken == NULL) return 0;
        subToken++;
        // Nếu token là thẻ mở, thêm nó vào Stack
        if (subToken[0] != '/') {
            p.push(subToken);
            printf("push %s\n", subToken);
        }
        // Nếu token là thẻ đóng
        else if (subToken[0] == '/') {
            // Kiểm tra xem Stack có rỗng không
            if (p.empty()) {
                return 0;
            }
            // Lấy thẻ mở khỏi Stack và so sánh tên thẻ
            char* openTag = p.front();
            p.pop();
            printf("Pop %s\n", openTag);
            if (openTag == NULL || strcmp(openTag, subToken+1) != 0) {
                return 0;
            }
        }
        token = strtok(NULL, ">");
    }

    // Nếu Stack còn phần tử sau khi duyệt xong, thì các thẻ HTML không hợp lệ
    if (p.empty()) {
        return 0;
    }
    return 1;
}
int main()
{
    stack<char*> p;
    char s[] = "<div><p>Hello, world!</p></div>";
    std::cout<<isValidHTMLTags(s, p);
}