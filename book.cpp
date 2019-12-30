#include <iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
class books{
string *title,*author,*publisher,*price,*stock;
int size;
static int count;
public:
    books(int s){
        size=s;
    title=new string[s];
    author=new string[s];
    publisher=new string[s];
    price=new string[s];
    stock=new string[s];
}
void add(){
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
void Search(){
string *p=new string;
int *s=new int[2]{0};
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
        getline(cin,*p);
        for(int i=0;i<count;i++){
               if(substring_find(title[i],*p)){
                  disp(i);
                  s[1]++;
                  }}
        if(s[1]==0){
            cout<<"No match Found\nFor searching again press \'c\' otherwise press other key for back menu"<<endl;
            char *m=new char;
            cin>>m;
            cin.ignore();

            if(*m=='c'||*m=='C'){
             s[0]=0; // for continue statement to be work ,loop condition should must be followed
            continue;  }
            delete m;
            }

        break;

case 2: cout<<"Enter Author Name :";
        getline(cin,*p);
        for(int i=0;i<count;i++){
               if(substring_find(author[i],*p)){
                  disp(i); s[1]++;
                  }}
                if(s[1]==0){
            cout<<"No match Found\nFor searching again press \'c\' otherwise press other key for back menu"<<endl;
            char *m=new char;
            cin>>m;
            cin.ignore();
            if(*m=='c'||*m=='C'){
                    s[0]=0;
                continue;}
            delete m;
            }

        break;
case 3: cout<<"Enter Publisher :";
        getline(cin,*p);
        for(int i=0;i<count;i++){
               if(substring_find(publisher[i],*p)){
                  disp(i); s[1]++;
                  }}
                if(s[1]==0){
            cout<<"No match Found\nFor searching again press \'c\' otherwise press other key for back menu"<<endl;
            char *m=new char;
            cin>>m;
            cin.ignore();
            if(*m=='c'||*m=='C'){
                    s[0]=0;
                continue;}
            delete m;
            }

        break;
case 4:cout<<"Enter Price :";
        getline(cin,*p);
        for(int i=0;i<count;i++){

               if(stof(price[i])<=stof(*p))
                {
                  disp(i); s[1]++;
                  }}
               if(s[1]==0){
            cout<<"No match Found\nFor searching again press \'c\' otherwise press other key for back menu"<<endl;
            char *m=new char;
            cin>>m;
            cin.ignore();
            if(*m=='c'||*m=='C'){
                    s[0]=0; 
                continue;}
            delete m;
            }

        break;
case 5: break;
default: cout<<"INCORRECT INPUT!, Enter Correct input"<<endl;
        s[0]=0;
        break;
}}
delete p;
delete []s;
}
void disp(int j){
//cout<<"Title             Author           Publication            Price           Stock"<<endl;
cout<<title[j]<<"           "<<author[j]<<"             "<<publisher[j]<<"             "<<price[j]<<"            "<<stock[j]<<endl;
}
int substring_find(string str,string sub_str){
transform(str.begin(),str.end(),str.begin(),::toupper);
transform(sub_str.begin(),sub_str.end(),sub_str.begin(),::toupper);
int i=str.find(sub_str);
if(i>=0)
    return 1;

else return 0;
}
};
int books::count=0;
int main(){
books a(5);
a.add();
a.Search();




}

