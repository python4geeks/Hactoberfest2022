#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;
//initializing
set<string> sentence1, sentence2;
string s1= "This is a is dog cat",s2="This is cat";

//(A n B)
int intersection1(set<string> A, set<string> B){
 vector<string>::iterator it;
 vector<string> v;
 int count=0;
 set_intersection(A.begin(),A.end(),B.begin(),B.end(),back_inserter(v));
 for(it = v.begin(); it != v.end(); ++it){
    //cout<<*it<<endl;
    count++;
 }
 return count;
}
//A u B)
 int union1(set<string> A, set<string> B){
 vector<string>::iterator it;
 vector<string> v;
 int count=0;
 set_union(A.begin(),A.end(),B.begin(),B.end(),back_inserter(v));
 for(it = v.begin(); it != v.end(); ++it){
    //cout<<*it<<endl;
    count++;
 }
 return count;
 }
 // (A n B)/(A u B)
 float Jaccard_Similarity(set<string> A, set<string> B){
 float result;
 result = float(intersection1(A,B)) / float(union1(A,B));
 return result;
 }
 //splitting and populating sets
void splitting(){

    stringstream x;
    string buffer;

    x.str(s1);
    while(x>>buffer)
        sentence1.insert(buffer);
    x.clear(); //clear stream to be used again

    x.str(s2);
    while(x>>buffer)
        sentence2.insert(buffer);
    x.clear();
}

//displays all elements in a set
void display(set<string> x){
    set<string>::iterator it;
for(it = x.begin(); it != x.end(); ++it)
  cout<<*it<<endl;
}
int main(){
splitting();
display(sentence2);
cout<<endl;
display(sentence1);
cout<<endl<<"Result:"<<Jaccard_Similarity(sentence1,sentence2);




    return 0;
}