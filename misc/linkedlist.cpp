#include <iostream>
using namespace std;
#include <thread>
#include <mutex>


struct Node{
    int val;
    Node* next;
};
class LinkedList{
    private:
        Node* head;
        Node* tail;
        std::mutex mtx;

    public:
        LinkedList(): head(NULL), tail(NULL){} \

        void addnode_tail(int val){
            Node* tmp = new Node();
            std::lock_guard<std::mutex> lck(mtx);
            tmp->val = val;
            tmp->next = NULL;
            if (head == NULL){
                head = tmp;
                tail = tmp;
                tmp = NULL;
            }
            else{
                tail->next = tmp;
                tail = tmp;
            }
        }

        void addnode_head(int val){
            Node* tmp = new Node;
            tmp->val = val;
            tmp->next = head;
            
            if (tail == NULL)
                tail = tmp;
            head = tmp;
            
        }

        void delnode_head(){
            if (head){
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }

        void delnode_tail(){
            Node* cur = head;
            Node* prev = new Node;
            while(cur->next != NULL){
                prev = cur;
                cur = cur->next;
            }
            tail = prev;
            prev->next = NULL;
            delete cur;
        }

        void delnode_idx(int pos){
            //int data = 0;
            if (pos == 0){
                delnode_head();
            }
            else{
                Node* curr = head;
                for (int idx=1;idx<pos-1; idx++){
                    curr = curr->next;
                }
                //data = curr->next->val;
                curr = curr->next->next;
            }
            //return data;
        }

        int getnode_idx(int pos){
            std::lock_guard<std::mutex> lck(mtx);
            int data = 0;
            if (pos==0){
                data = head->val;
            }
            else{
                Node* curr = head;
                for (int idx = 1; idx<pos; idx++){
                    curr = curr->next;
                } 
                data = curr->next->val;
            }
            return data;
        }
     
        void display(){
            Node* curr = head;
            while(curr){
                cout<<curr->val<<" ";
                curr = curr->next;
            }
            cout<<endl;
        }
};

void set_10(LinkedList& l){
    for (int i = 0; i<10; i++)
    l.addnode_tail(i);
}

void get_10(LinkedList& l){
    int a;
    for (int i = 0; i<10; i++){
        a = l.getnode_idx(i);
        cout<<a<<endl;
    }
}

int main(){
    LinkedList ll;  
    ll.addnode_tail(11);
    ll.addnode_tail(12);
    ll.addnode_head(13);
    ll.addnode_head(14);
    ll.addnode_tail(11);
    ll.delnode_tail();
    /*
    std::thread t1(set_10,ll);
    ll.display();
    std::thread t2(set_10,ll);
    ll.display();
    t1.join();
    t2.join();
    */
    
    auto set_10_1 = [&ll](){
        for (int i = 0; i<10; i++)
        ll.addnode_tail(i);
    };
    std::thread t1(set_10_1);
    t1.join();
    ll.display();
    return 0;
}