// example based on accessing pointer type data member
#include <iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
class books{

string *title,*author,*publisher,*price,*stock;
int size;
int cart_count[10];
static int count;
static int num;

public:
    books(int s){
        size=s;
    title=new string[s];
    author=new string[s];
    publisher=new string[s];
    price=new string[s];
    stock=new string[s];
    }
    // declaring  functions
    void add();
    void Search();
    int subsearch(string *k);
    void disp(int,int);
    void cart();
    void display_cart();
    int substring_find(string str,string sub_str);

};
void books::add(){
string *a=new string[5];
cout<<"Enter book details: \n<1> Title of book\n<2> Author Name\n<3> Publisher\n<4> Price\n<5> Stock"<<endl;
getline(cin,a[0]);getline(cin,a[1]);getline(cin,a[2]);getline(cin,a[3]);getline(cin,a[4]);
title[count]=a[0];
author[count]=a[1];
publisher[count]=a[2];
price[count]=a[3];
stock[count]=a[4];
count++;
delete []a;
}


void books::Search(){
string *p=new string;
int *s=new int[3]{0};
while(s[0]==0){
cout<<"press 1 : For search by Book's Title"<<endl;
cout<<"Press 2 : For search by author name"<<endl;
cout<<"Press 3 : For search by publisher"<<endl;
cout<<"Press 4 : For search Book's by price range"<<endl;
cout<<"Press 5 : For exit search"<<endl;

cin>>s[0];
cin.ignore();
switch(s[0]){
case 1: cout<<"Enter Book's Title :";
        s[2]=subsearch(title);
        if(s[2]==1){
            s[0]=0;
            continue;}
        break;
case 2: cout<<"Enter Author Name :";
        s[2]=subsearch(author);
        if(s[2]==1){
                s[0]=0;
            continue;}
        break;
case 3: cout<<"Enter Publisher :";
    s[2]=subsearch(publisher);
      if(s[2]==1){
            s[0]=0;
            continue;}
        break;
case 4:cout<<"Enter Price :";
        getline(cin,*p);
        for(int i=0;i<count;i++){

               if(stof(price[i])<=stof(*p))
                {
                  s[1]++;
                  disp(i,s[1]);
                  }}
        if(s[1]==0){
            cout<<"No match Found\nFor searching again press \'c\' otherwise exit search"<<endl;
            char *m=new char;
            cin>>*m;
            cin.ignore();
            if(*m=='c'||*m=='C'){
                    s[0]=0;
               delete m;
                continue;}
            else delete m;
            }
            delete p;
        break;
case 5: break;
default: cout<<"INCORRECT INPUT!, Enter Correct input"<<endl;
        s[0]=0;
        break;
}}}


int books:: subsearch(string *k){
string *p=new string;
int s=0;
getline(cin,*p);
        for(int i=0;i<count;i++){
               if(substring_find(k[i],*p)){
                  s++;
                  disp(i,s);
                }}
        if(s==0){
            cout<<"No match Found\nFor searching again press \'c\' otherwise press other key for back menu"<<endl;
            char *m=new char;
            cin>>*m;
            cin.ignore();
            if(*m=='c'||*m=='C'){
                    delete m;
                return 1;}
            else delete m;
            }

            delete p;
            return 0;
}


void books::disp(int j,int c){
//cout<<"Title             Author           Publication            Price           Stock"<<endl;
cout<<c<<".  "<<title[j]<<"           "<<author[j]<<"             "<<publisher[j]<<"             "<<price[j]<<"            "<<stock[j]<<endl;
}


int books::substring_find(string str,string sub_str){
transform(str.begin(),str.end(),str.begin(),::toupper);
transform(sub_str.begin(),sub_str.end(),sub_str.begin(),::toupper);
int i=str.find(sub_str);
if(i>=0)
    return 1;

else return 0;
}


void books::cart(){
string *h=new string[2];
cout<<"Enter Title and Author name"<<endl;
getline(cin,h[0]);
getline(cin,h[1]);
for(int i=0;i<count;i++){
   if(substring_find(title[i],h[0]) && substring_find(author[i],h[1])){
      cart_count[num]=i;
      num++;
      break;
   }}}


void books::display_cart(){
for(int j=0;j<num;j++){
 cout<<j+1<<".  "<<title[cart_count[j]]<<"           "<<author[cart_count[j]]<<"             "<<publisher[cart_count[j]]<<"             "<<price[cart_count[j]]<<"            "<<stock[cart_count[j]]<<endl;
}
}

int books::count=0;
int books::num=0;


int main(){
books a(5);
a.add();
a.add();
a.add();
a.Search();
//a.display_cart();
}

