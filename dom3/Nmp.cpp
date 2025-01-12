//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Node
//{
//    int data;
//    Node* next;
//
//    Node(int data, Node* next = nullptr)
//        :data(data), next(next) {};
//};
//
//class SinglyLinkedList
//{
//private:
//    Node* head;
//    Node* tail;
//
//public:
//    SinglyLinkedList() : head(nullptr), tail(nullptr) {}
//
//    void push_back(int data)
//    {
//        Node* newNode = new Node(data);
//        if (!head) {
//            head = tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = tail->next;
//        }
//    }
//
//    void push_front(int data)
//    {
//        Node* newNode = new Node(data);
//        if (!head)
//            head = tail = newNode;
//
//        Node* curr = head;
//        newNode->next = curr;
//        head = newNode;
//    }
//
//    size_t contains(int data) const
//    {
//        if (!head)
//            return -1;
//
//        Node* curr = head;
//        int i = 0;
//        while (curr)
//        {
//            if (curr->data == data)
//                return i;
//            i++;
//            curr = curr->next;
//        }
//        return -1;
//    }
//
//    void remove(size_t index)
//    {
//
//        if (!head)return;
//
//        Node* curr = head;
//
//        if (index == 0)
//        {
//            head = head->next;
//            delete curr;
//            return;
//        }
//
//        Node* prev = nullptr;
//        int i = 0;
//        while (i < index)
//        {
//            i++;
//            prev = curr;
//            curr = curr->next;
//        }
//
//        if (curr == nullptr)
//        {
//            return;
//        }
//
//        prev->next = curr->next;
//        delete curr;
//
//    }
//
//    void pop_front()
//    {
//        if (!head)
//            return;
//
//        if (head == tail)
//        {
//            tail = nullptr;
//        }
//
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//};
//
//
//
//
//
//int main() {
//
//    SinglyLinkedList list;
//    int n, k;
//    cin >> n >> k;
//    int size = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        int el; cin >> el;
//        int ind = list.contains(el);
//
//        if (ind == -1 && size < k)
//        {
//            list.push_back(el);
//            cout << "false" << endl;
//            size++;
//        }
//
//        else if (ind == -1 && size == k)
//        {
//            list.pop_front();
//            list.push_back(el);
//            cout << "false" << endl;
//        }
//
//        else if (ind != -1 && size <= k)
//        {
//            list.remove(ind);
//            list.push_back(el);
//            cout << "true" << endl;
//        }
//    }
//
//};

//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Node
//{
//    int data;
//    Node* next;
//
//    Node(int data, Node* next = nullptr)
//        :data(data), next(next) {};
//};
//
//class SinglyLinkedList
//{
//private:
//    Node* head;
//    Node* tail;
//
//public:
//    SinglyLinkedList() : head(nullptr), tail(nullptr) {}
//
//    void push_back(int data)
//    {
//        Node* newNode = new Node(data);
//        if (!head) {
//            head = tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = tail->next;
//        }
//    }
//
//    void push_front(int data)
//    {
//        Node* newNode = new Node(data);
//        if (!head)
//            head = tail = newNode;
//
//        Node* curr = head;
//        newNode->next = curr;
//        head = newNode;
//    }
//
//    size_t contains(int data) const
//    {
//        if (!head)
//            return -1;
//
//        Node* curr = head;
//        int i = 0;
//        while (curr)
//        {
//            if (curr->data == data)
//                return i;
//            i++;
//            curr = curr->next;
//        }
//        return -1;
//    }
//
//    void remove(size_t index)
//    {
//
//        if (!head)return;
//
//        Node* curr = head;
//
//        if (index == 0)
//        {
//            head = head->next;
//            delete curr;
//            return;
//        }
//
//        Node* prev = nullptr;
//        int i = 0;
//        while (i < index)
//        {
//            i++;
//            prev = curr;
//            curr = curr->next;
//        }
//
//        if (curr == nullptr)
//        {
//            return;
//        }
//
//        prev->next = curr->next;
//        delete curr;
//
//    }
//
//    void pop_front()
//    {
//        if (!head)
//            return;
//
//        if (head == tail)
//        {
//            tail = nullptr;
//        }
//
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//};
//
//size_t contains(vector<Node> list, int data)
//{
//    if (list.empty())return -1;
//    int i = 0;
//    while (i < list.size())
//    {
//        if (list[i].data == data)
//            return i;
//        i++;
//    }
//    return -1;
//}
//
//
//
//int main() {
//
//    vector<Node> list;
//    //SinglyLinkedList list;
//    int n, k;
//    cin >> n >> k;
//    int size = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        int el; 
//        cin >> el;
//
//        int ind = contains(list, el);
//
//        if (ind == -1 && size < k)
//        {
//            list.push_back(el);
//            cout << "false" << endl;
//            size++;
//        }
//
//        else if (ind == -1 && size == k)
//        {
//            list.erase(list.begin());
//            //swap(list[0], list[ind]);
//             list.push_back(el);
//            cout << "false" << endl;
//        }
//
//        else if (ind != -1 && size <= k)
//        {
//           // swap(list[size-1], list[ind]);
//             list.erase(list.begin()+ind);
//             list.push_back(el);
//            cout << "true" << endl;
//        }
//    }
//
//};

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data, Node* next = nullptr)
        :data(data), next(next) {};
};

/*
class SinglyLinkedList
{
    private:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    public:
    SinglyLinkedList(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}

    void push_back(int data)
    {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void push_front(int data)
    {
        Node* newNode = new Node(data);
        if(!head)
            head=tail=newNode;

        Node* curr=head;
        newNode->next=curr;
        head=newNode;
    }

    size_t contains(int data) const
    {
        if(!head)
            return -1;

        Node* curr=head;
        int i=0;
        while(curr)
        {
            if(curr->data==data)
                return i;
            i++;
            curr=curr->next;
        }
        return -1;
    }

    void remove(int data)
    {

        if(!head)return;

         if(head->data==data)
         {
             Node* temp=head;
             head=head->next;
             delete temp;
             size--;
             if(!head)tail=nullptr;
             return;
         }

        Node* prev=head;
        Node* curr=head->next;
        while(curr && curr->data!=data)
        {
            prev=curr;
            curr=curr->next;
        }

        if(curr)
        {
            prev->next=curr->next;
            if(curr==tail)
            {
                tail=prev;
            }
            delete curr;
            size--;
        }


    }

    void pop_front()
    {
        if(!head)
            return;

        if(head==tail)
        {
           tail=nullptr;
            size--;
            return;
        }

        Node* temp=head;
        head=head->next;
        delete temp;
        size--;
        if(!head)temp=nullptr;
    }

    bool access(int data)
    {
        Node* curr=head;
        bool found=false;


        while(curr)
        {

        }
    }
};
*/


size_t contains(vector<Node> list, int data)
{
    if (list.empty())return -1;
    int i = 0;
    while (i < list.size())
    {
        if (list[i].data == data)
            return i;
        i++;
    }
    return -1;
}



int main() {

    vector<Node> list;

    int n, k;
    cin >> n >> k;
    int size = 0;
    int elements[100000]{ 0 };

    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;

        bool found = false;
        if (elements[el] != 0)found = true;


        if (!found && size < k)
        {
            list.push_back(el);
            size++;
            elements[el] = size;
            cout << "false" << endl;
        }

        else if (!found && size == k)
        {
            list.erase(list.begin());
            elements[el] = 0;

            list.push_back(el);
            elements[el] = size;

            cout << "false" << endl;
        }

        else if (found && size <= k)
        {

            list.erase(list.begin() + elements[el]-1);
            elements[el] = 0;

            list.push_back(el);
            elements[el] = size;

            cout << "true" << endl;
        }
    }



};

