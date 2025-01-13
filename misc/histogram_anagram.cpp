#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <map>
using namespace std;

template <typename T>
map<T, int> getHist(vector<T> v){
    map<T, int> histmap;
    for (auto &c:v){
        auto itr = histmap.find(c); 
        if (itr == histmap.end()){
            histmap[c] = 1;
        }
        else{
            itr->second += 1;
        }
        }
    return histmap;
}
template <>
map<bool,int> getHist(vector<bool> v){
    map<bool, int> histmap;
    int sum = 0;
    for (auto itr : v){
        sum += (itr ? 1 : 0);
    }

    histmap.insert(pair<bool,int>(false,v.size()-sum));
    histmap.insert(pair<bool,int>(true,sum));
    return histmap;
}

bool comparehist(map<char, int>hist1, map<char, int>hist2){
    if (hist1.size() != hist2.size()){
        return false;
    }
    for (auto itr1=hist1.begin(), itr2=hist2.begin();itr1 != hist1.end();itr1++,itr2++){
        if (itr1->first != itr2->first) return false;
        if (itr1->second != itr2->second)return false;
    }
    return true;
}
template<typename T>
string convVect(vector<T> v){
    string str(v.begin(), v.end());
    return str;
}

//template<typename T>
vector<char> convStr(string s){
    vector<char> v ;
    copy(s.begin(),s.end(),back_inserter(v));
    return v;
}

template<typename T>
void printVect(vector<T> v){
    for (auto itr:v){
        cout<<itr<<endl;
    }
}

bool isAnangram(string str1, string str2){
    vector<char> v1 = convStr(str1);
    vector<char> v2 = convStr(str2); 
    map<char, int>hist1 = getHist(v1);
    map<char, int> hist2 = getHist(v2);
    bool res = comparehist(hist1, hist2);
    if (res == 1) return true;
    return false;
}

template<typename T1, typename T2>
void printhist(map<T1, T2>hist){
    for (auto it:hist){
        cout<<"11111"<<it.first<<it.second<<endl;
    }
}



int main(){
    string str1 = "ananya";
    string str2= "ananya";
    string str3 = "12345";
    string str4 = "000011110101";
    vector<bool> v4 = {true, true, false,true, false,false,false};
    vector<char> v12 = convStr(str2);
    printVect(v12);
    vector< char> v1 = {'a','n','a','n','y','a'};
    vector<char> v2 = {'a','n','a','n','y','a','a'};
    string bb = convVect(v1);
    cout<<bb<<endl;
    map<char, int> hist1 = getHist(v1);
    map<char, int>hist2 = getHist(v2);
    map<bool,int> histbool = getHist(v4);
    //printhist(hist1);
    //printhist(hist2);
    printhist(histbool);
    auto aa = comparehist(hist1, hist2);
    cout <<aa<<endl;
    //auto isana = isAnangram(hist1, hist2);
    //cout<<hist1<<endl;
    //cout<<isana<<endl;

   bool finres = isAnangram(str1,str3);
   cout<<finres<<endl;
}