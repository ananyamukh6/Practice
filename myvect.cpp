#include <iostream>
using namespace std;

template <typename T>
class MyVect{
    public:
        //constructors: (numelem), (numelem, initval)
        MyVect(int numelem):len(numelem), cap(numelem), arr((T*)malloc(numelem * sizeof(T))), count(0){
            //arr = (T*)malloc(numelem * sizeof(T));
        }
        MyVect(int numelem, T initval): MyVect(numelem){
            //arr = (T*)malloc(numelem * sizeof(T));
            for (int i = 0; i<len; ++i){
                arr[i] = initval;
            }
        }
        MyVect(const MyVect& v):len(v.len), cap(v.cap), arr(v.arr), count(v.count+1) {
        }
        // deepcopy
        /*
        MyVect(const MyVect& v):len(v.len), cap(v.cap){
            arr = (T*) malloc(len*sizeof(T));
            memcpy(arr, v.arr, len * sizeof(T));
        }*/

        /*
        std::ostream& operator<<(std::ostream &out, const MyVect &vect){
            for (int i = 0; i<(sizeof(arr)/sizeof(T)); ++i){
            }
            //out<<"Myvect:"<< <<"\n";
            return out;
        }*/
        void printMe(){
            for (int i = 0; i<len; ++i){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        void push_back(T val){
            if (len == cap) {
                arr = (T*)realloc(arr, len==0 ? 1 : sizeof(T) * len * 2);
                cap = len * 2;
            }
            arr[len] = val;
            ++len;
        }

        int capacity() {return cap;};
        int size() {return len;};
        void clear() {
            if (count == 0){
                cout << "actual free\n";
                free(arr);
            }
            cap = 0;
            len = 0;
        }

        T at(int i){
            if (i >= len) {
                //throw error
            }
            return arr[i];
        }

        T& operator[](int i){
            return arr[i];
        }

        T front() {return arr[0];}
        T back() {return arr[len-1];}

        T pop_back() {
            --len;
            return arr[len];
        }


        ~MyVect() {
            cout << "DESTRUCTOR\n";
            clear();
        }
        /*
        T pop_back()

        at
        front
        back
        clear
        [] (2)

        move and copy const
        vector bool specialization

    

        //iterators


    */
    private:
        int len;
        int cap;
        T* arr;
        const int count; //counter for shallow copy
};



int main(){
    MyVect<int> v(3,2);
    v.printMe();
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.printMe();

    v[0] = 100;
    v.printMe();
    MyVect<int> v2(v);
    cout<<"helloo"<<"\n";
    v2.printMe();
    return 0;

}