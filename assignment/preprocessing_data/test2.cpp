#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
 freopen("lyrl2004_tokens_test_pt0.dat", "r+", stdin);
 string item;
 int srno;
 while(feof(stdin))
 {
  cin>>item;
  cin>>srno;
  cout<<item<<" : "<<srno<<endl;
  cin>>item;
  cin>>srno;
  cout<<item<<" : "<<srno<<endl;
 }
 return 0;
}
