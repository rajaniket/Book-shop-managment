#include <iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
class books{

string *title,*author,*publisher,*price,*stock;
int size;
int cart_count[2][10];   // this will store books i value which is store in cart;
static int count;       // how many books there have in library
static int num;        // it stores number of books in the cart
int store_search[10];  //this will store address of books which appears in search list (means i value of data members )

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
    void display_all();
    void edit_cart();

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
                    store_search[s[1]]=i; // store_search will store address of all book which will appear after search
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
                 store_search[s]=i;
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
int *h=new int[2];
cout<<"Enter Book serial number : ";
cin>>h[0];
cout<<"Title of book:- "<<title[store_search[h[0]-1]]<<endl<<"Author:- "<<author[store_search[h[0]-1]]<<endl<<"Publication:- "<<publisher[store_search[h[0]-1]]<<endl<<"Price:- "<<price[store_search[h[0]-1]]<<endl<<"Stock:- "<<stock[store_search[h[0]-1]]<<endl;
cout<<"Enter number of book required : ";
cin>>h[1];
cin.ignore();

       if(((stoi(stock[store_search[h[0]-1]])>=(h[1])))){
       cart_count[0][num]=store_search[h[0]-1];
       cart_count[1][num]=h[1];
       stock[store_search[h[0]-1]]=to_string(stoi(stock[store_search[h[0]-1]])-h[1]);
       cout<<"Book Successfully added to cart"<<endl;
       num++;}
       else cout<<"Not Available, Failed to add"<<endl;

   }

void books::display_cart(){
    float total=0;
if(num>=1){
for(int j=0;j<num;j++){
 cout<<j+1<<".  "<<title[cart_count[0][j]]<<"           "<<author[cart_count[0][j]]<<"             "<<publisher[cart_count[0][j]]<<"             "<<price[cart_count[0][j]]<<"            "<<cart_count[1][j]<<endl;
  total=total+stof(price[cart_count[0][j]])*cart_count[1][j];
}
cout<<"Total price :- "<<total<<" Rupees"<<endl;
edit_cart();
}
else cout<<"There is no any book in the cart"<<endl;
}
void books::edit_cart(){
cout<<"\n\nPress D for deleting books into cart :- ";
cout<<"Press T for transaction:- ";
cout<<"Press Any other key for Back Menu";
char *w=new char;
int *g=new int;
cin>>*w;
*w=toupper(*w);
switch(*w){
case 'D': cout<<"Enter serial number"<<endl;
     while(num>0){
        cin>>*g;
        if(*g<=num && *g>0)
            break;
        else cout<<"Wrong input, Enter Correct serial number :- "<<endl;
        }
     stock[cart_count[0][*g]]=to_string(stoi(stock[cart_count[0][*g]])+cart_count[1][*g]);
       for(int i=(*g-1);i<num;i++){
          cart_count[0][i]=cart_count[0][i+1];
          cart_count[1][i]=cart_count[1][i+1];
       }
       cout<<"Book successfully removed from cart"<<endl;


case 'T': num=0;

default: break;
}}



void books :: display_all(){
  if(count>=1){
    for(int i=0;i<count;i++){
        disp(i,i+1);
    }
  }
  else cout<<"There is no book added yet"<<endl;
}

int books::count=0;
int books::num=0;


int main(){
books a(5);

a.add();
//a.add();
//a.add();
a.Search();
cout<<"add to cart"<<endl;
a.cart();
a.display_cart();
cout<<"displaying all"<<endl;
a.display_all();
cout<<"displaying cart"<<endl;
a.display_cart();
cout<<"displaying all"<<endl;
a.display_all();

}

