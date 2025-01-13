#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;    
};

class LinkedList{
    private:
        node* head;
        node* tail;
        int length;
    public:
        LinkedList():head(NULL), tail(NULL), length(0){}

        void addNodeTail(int val){
            node* tmp = new node();
            tmp->val = val;
            tmp->next = NULL;
            if (head == NULL){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tmp;
            }
            length += 1;
        }
        void addNodeHead(int val){
            node* tmp = new node;
            tmp->val = val;
            tmp->next = head;
            
            if (head == NULL){
                tail = tmp;
            }
            head = tmp;
            length += 1;
        }
        void addNodeIdx(int val, int idx){
            if (idx == 0){
                addNodeHead(val);
            }
            else if(idx - length == 0){
                addNodeTail(val);
            }
            else if(idx>length){
                cout<<"Inavlid index for insertion"<<"\n";
            }
            /*
            else{
                node* newnode = new node;
                newnode->val = val;
                newnode->next = NULL;
                node* curr = head;
                int curridx = 0;
                node* prev = new node;
                while(curridx<idx){
                    prev = curr;
                    curr = curr->next;
                    curridx += 1;
                }
                prev->next = newnode;
                newnode->next = curr;
                length += 1;
            }*/

            else{
                node* curr = head;
                node* tmp = new node;
                tmp->val = val;

                for (int i = 1;i<idx;++i){
                    curr = curr->next;
                }
                node* tmp2 = curr->next;
                curr->next = tmp;
                tmp->next = tmp2;
                length += 1;
            }
            
        }
        int delNodetail(){
            node* curr = head;
            node* prev = new node;
            while (curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            int popval = curr->val;
            tail = prev;
            prev->next= NULL;
            delete curr;
            length -= 1;
            return popval;
        }
        int delNodeHead(){
            int popval = head->val;
            if(head){
                node* tmp = head;
                head = head->next;
                delete tmp;
            }
            length -= 1;
            return popval;
        }
        int delNodeidx(int idx){
            if (idx == 0){
                delNodeHead();
            }
            else if(length - idx == 1){
                delNodetail();
            }
            else if(idx>length){
                cout<<"Invalid index for deletion"<<"\n";
            }
            else{
                node* curr = head;
                for (int i = 1; i < idx-1; ++i){
                    curr = curr->next;
                }
                int popval = curr->next->val;
                curr->next = curr->next->next;
                length -= 1;
                return popval;
            }
            return 0;
        }

        void display(){
            node* curr = head;
            while(curr!=NULL){
                cout<<curr->val<<"->";
                curr = curr->next;
            }
            cout<<"\n";
            cout<<"Length of the linked list is: "<<length<<"\n";
        }    
        //TODO move outside class
        void set_ll(int len){
            for (int i = 0; i<len; i++)
            this->addNodeTail(i);
        }
        int getNodeIdx(int idx){
            int data = 0;
            if (idx == 0){
                data = head->val;
            }
            else {
                node* curr = head;
                for (int i =1; i<idx; ++i){
                    curr = curr->next;
                }
                data =  curr->next->val;
            }
            return data;
        }

        void get_all(){
            for (int i = 0; i<length; ++i){
                auto vals = this->getNodeIdx(i);
                cout<<vals<<"\n";
            }
        }

        void reverseinplace(){
            if (head == NULL){
                cout<<"Linkedlist is empty"<<"\n";
            }
            node* prev = NULL;
            node* curr = head;
            while(curr!=NULL){
                node* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            } 
            head = prev;           
        }

        LinkedList reverse(){
            LinkedList l;
            if (length == 0){
                cout<<"Linked list is empty"<<"\n";
                return l;
            }
            node* curr = head;
            while(curr){
                l.addNodeHead(curr->val);
                curr = curr->next;
            }
            return l;
        }
            /*
            node* ntail = new node;
            ntail->val = head->val;
            ntail->next = NULL;
            node* curr = head->next;
            while(curr){
                node* newnode = new node;
                newnode->val = curr->val;
                newnode->next = ntail;
                curr = curr->next;
                ntail = newnode;
            }
            
        return l;
        }*/


        LinkedList<pair<T, T2>> zip(LinkedList<T2> l2);

        LinkedList<pair<T, int>> enumerate();

        LinkedList<T> operator+(const LinkedList<T>& l2)
};

    vector<vector<int>> <<<->>> LinkedList<LinkedList<int>>
ß
template <typename T1, typename T2>
LinkedList<pair<T1,T2>> zip(LinkedList<T1> l1, LinkedList<T2> l2);


LinkedList setll(int len){
    LinkedList ll;
    for (int i = 0; i<len ;i++){
        ll.addNodeHead(i);
    }
    return ll;
}

int main(){

    LinkedList ll;
    /*
    ll.addNodeTail(100);
    ll.display();
    ll.addNodeHead(1);
    ll.addNodeHead(10);
    ll.display();
    cout<<ll.delNodetail()<<"\n";
    ll.display();
    cout<<ll.delNodeHead()<<"\n";
    ll.display();*/
    ll.set_ll( 5); 
    ll.display();
    ll.addNodeIdx(100,5);
    ll.display();
    ll.delNodeidx(1);
    ll.display();
    //ll.get_all();
    //ll.reverseinplace();
  
    //auto zz = ll.reverse();
    //ll.display();
    LinkedList revll = ll.reverse();
    revll.display();
    revll.reverseinplace();
    revll.display();
    revll.addNodeIdx(8,0);
    revll.display();
    LinkedList test;
    test.reverseinplace();
    LinkedList l = setll(5);
    l.display();
    return 0;
}