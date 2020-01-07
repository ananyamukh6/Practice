#include <iostream>
using namespace std;
template <typename T>
class doubleLinkedList{
    private:
        template <typename Tn>
        struct node{
            Tn val;
            node* next;
            node* prev;
        };
        int length;
        node<T>* head;
        node<T>* tail;        
    public:
        doubleLinkedList():head(NULL), tail(NULL), length(0){}

        void addNodeHead(T val){
            node<T>* tmp = new node<T>;
            tmp->val = val;
            if (head == NULL){
                tail = tmp;
            }
            tmp->next = head;
            tmp->prev = NULL;
            head = tmp;
            length += 1;
        }

        void addNodeTail(T val){
            node<T>* tmp = new node<T>;
            tmp->val = val;
            tmp->next = NULL;
            if (head == NULL){
                tmp->prev = NULL;
                head = tmp;
                tail = tmp;
            }
            else{
                tail ->next = tmp;
                tmp->prev = tail;
                tail = tmp;
            }
            length += 1;
        }

        private:
        T del(bool h){
            // assert n->prev == NULL or node->nect == NULL
            node* n = h ? head : tail;
            T popval = n->val;
            node<T>* tmp = n;
            //
            if (h){
                head = head->next;
                head->prev = NULL;
            }
            else{
                tail = tail->prev;
                tail->next = NULL;
            }
            delete tmp;
            length -= 1;
            return popval;
        }
        public:
        T delNodeHead(){
            return del(true);
            /*
            T popval = head->val;
            node<T>* tmp = head;
            head = head->next;
            head->prev = NULL;
            delete tmp;
            length -= 1;
            return popval;*/
        }

        T delNodeTail(){
            T popval = tail->val;
            node<T>* tmp = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            length -= 1;
            delete tmp;
            return popval;
        }
        void display(){
            node<T>* curr = head;
            while (curr){
                cout<<curr->val<<"->";
                curr = curr->next;
            }
            cout<<"\n";
            cout<<"Length of dll is: "<<length<<"\n";
        }

};

int main(){
    doubleLinkedList<int> dll;
    dll.addNodeHead(1);
    dll.addNodeHead(2);
    dll.addNodeTail(3);
    dll.display();
    int a = dll.delNodeHead();
    cout<<a<<"\n";
    dll.display();
    int c = dll.delNodeTail();
    dll.display();
    return 0;
}