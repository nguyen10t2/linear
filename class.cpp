#include <iostream>
#include <algorithm>
#include <string>


class stack
{
    struct Node
    {
        int data;
        struct Node *next;
        struct Node *prev;
    };

private:
    struct Node *head = NULL;
    int leng = 0;
    struct Node *lastNode = head;

public:
    struct Node *createNode(int data)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void push(int data)
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
        struct Node *temp = lastNode->prev;
        lastNode->prev->next = NULL;
        free(lastNode);
        lastNode = temp;
        --leng;
    }
    int front()
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
class queue
{
    struct Node
    {
        std::string data;
        struct Node *next;
        struct Node *prev;
    };

    private:
        struct Node *head = NULL;
        int leng = 0;
        struct Node *lastNode = head;

    public:
        struct Node *createNode(std::string data)
        {
            struct Node *newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = NULL;
            return newNode;
        }
        void push(std::string data)
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
            struct Node *temp = head;
            head = head->next;
            if(head == NULL) lastNode = head;
            free(temp);
            --leng;
        }
        std::string front()
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
int main()
{
    queue p;
    int n;
    std::cin >> n;
    std::string bin[n + 1];
    bin[1] = "1";
    p.push("1");
    int count = 1;
    while (count < n)
    {
        std::string top = p.front();
        p.pop();
        ++count;
        bin[count] = top + "0";
        p.push(bin[count]);
        ++count;
        bin[count] = top + "1";
        p.push(bin[count]);
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cout << bin[i] << '\n';
    }
}