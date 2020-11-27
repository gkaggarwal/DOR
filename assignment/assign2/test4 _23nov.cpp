#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;
const long int TABLE_SIZE = 100000;
const long int Total_operation = 5000;
const long int Total_value=100000;

struct Hashnode
{ long int frequency;
  long int term_id;
  long int *posting;
};
struct Hashnode* HashMap[TABLE_SIZE];
static long int counter_insert; //counter for insertion
static long int counter_delete;
static long int counter_search;

long int HashIndex(long int term_id) {
   return term_id % TABLE_SIZE;
}
//--------------------------------------------------------------------------------------------
void Insert(long int term_id,long int freq, long int doc_id,int check=0,Hashnode* item1=NULL)
{  
   if(check==0)
   {
   long int counter=0;
   
   struct Hashnode* item=(struct Hashnode*)malloc(sizeof(struct Hashnode*));
   item->frequency=freq;
   item->term_id=term_id;
   
   (item->posting)=(long int*)calloc(8000,sizeof(int));
   long int h_index=HashIndex(term_id);
   
   while(HashMap[h_index]!=NULL && HashMap[h_index]->term_id!=-1)
   {
    ++h_index;
    h_index%=TABLE_SIZE;
    counter++;
    counter_insert++;
    if(counter==TABLE_SIZE)
    break;
   }
   if(counter==TABLE_SIZE)
   cout<<"No space available to insert\n";
   else
   { 
     *(item->posting)=doc_id;
     HashMap[h_index]=item;
     counter_insert++;
   }
   }
   else if(check==1)
   {
   item1->frequency+=freq;
   long int i=0;
   while(i<8000 && *(item1->posting+i)!=0)
   {
    i++;
   }
   if(i<8000)
   {
   (*(item1->posting+i))=doc_id;
   }
   }
}
//----------------------------------------------------------------------------------------------

struct Hashnode* Search(long int term_id)
{
    long int h_index = HashIndex(term_id);
    long int counter=0;
    while(HashMap[h_index]!=NULL)
    {
            if(HashMap[h_index]->term_id==term_id)
             { ++counter_search;
               return HashMap[h_index];
             }
             ++h_index;
             ++counter_search;
             h_index%=TABLE_SIZE;
             ++counter;
             if(counter==TABLE_SIZE)
             break;
    }
    return NULL;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}

//-----------------------------------------------------------------------------------------------

long int* merge(long int* A,long int* B)
{ int i=0,j=0,count=0;
  long int *c;
  c=(long int*)calloc(8000,sizeof(int));
  while(*(A+i) !=0 && *(B+j) !=0)
  {
     if(*(A+i)==*(B+j))
     {
     c[count]=(*(A+i));  //cout<<(*(A+i))<<",";
     count++;
     i++;
     j++;
     }
     else if(*(A+i)< *(B+j))
     i++;
     else
     j++;
  }
  return c;
}
//-------------------------------------------------------------------------------------------------
long int* add(long int* A,long int* B)
{ int i=0,j=0,count=0;
  long int *c;
  c=(long int*)calloc(16000,sizeof(int));
  while(*(A+i) !=0)
  {
       c[count]=(*(A+i));  //cout<<(*(A+i))<<",";
       count++;
       i++;
     
  }
  while(*(B+j) !=0)
  {
       c[count]=(*(B+j));  //cout<<(*(B+i))<<",";
       count++;
       j++;
     
  }
  return c;
}
//-------------------------------------------------------------------------------------------------

int main()
{
  fstream file1,file2;
    string word1_doc,word1_string,word1_freq,word2,word3, filename1,filename2; 
    filename1 = "dict0.dat"; 
    filename2 = "vocab.dat";
    //-----------------------------------------------------------------
    file1.open(filename1.c_str(),ios::in);  
    while( file1 >> word1_doc)
    {  long int term_id=0;
       long int doc_id=0;
       long int frequency=0;
       std::istringstream doc (word1_doc);
       doc >> doc_id;
       file1>>word1_string;
       file2.open(filename2.c_str(),ios::in);  
    
       while ( file2 >> word2)
       {
           file2 >> word3;
           if ( word1_string != word2)
           {
           }
           else
           { std::istringstream term (word3);
              term >> term_id;
              file2.close();
              break;  
           }   
       }
       
    file1>>word1_freq;
    std::istringstream freq (word1_freq);
    freq>>frequency;      //cout<<term_id<<" "<<doc_id<<" "<<frequency<<endl;    
    if(Search(term_id) == NULL)
    {
     Insert(term_id, frequency,doc_id);
    }
    else
    {
     Hashnode* item1=Search(term_id);//  cout<<"Term id= "<<term_id<<endl;
     Insert(term_id, frequency,doc_id,1,item1);//  display_posting(item1);            
    }
    }
//---------------------------------------------------------------------------------------------------
while(1)
{  
    int case1;
    cout<<"Press 1 For Search\n"<<"Press 2 For Exit"<<endl;    
    cin>>case1;
    
    
 if(case1==1)
 {   
    string s ,s2;
    string A[100];
    char s1[100];
    fgets(s1,100,stdin);
    cout<<"Enter Query:";
    int query_type=0;
    fgets(s1,100,stdin);
    s=s1;
    std::string delimiter = " AND ";
    std::string delimiter1 = " OR ";
    std::string delimiter2 = "NOT ";
    int k=1;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    query_type=1;
    A[k++]=token;
    
    s.erase(0, pos + delimiter.length());
   }
   s2=s;
   while ((pos = s2.find(delimiter1)) != std::string::npos) {
    token = s2.substr(0, pos);
    query_type=2;
    A[k++]=token;
    
    s2.erase(0, pos + delimiter1.length());
   }
   while ((pos = s2.find(delimiter2)) != std::string::npos) {
    if(pos ==0)
    { s2.erase(0, delimiter2.length());
      query_type=3;
    }
    }
   
   pos = s2.find("\n");  // Deleteing newline character at the end of input string
   s2.erase(pos,pos+1);
    A[k]=s2;
    cout<<"Query: "<<query_type<<endl;
    for(int i=1;i<=k;i++)
    {
    cout<<A[i]<<i<<endl;
    }
    cout<<"k="<<k<<endl;
//---------------------------------------------------------------------
  
    int p=1,g;
    long int* R[k];
    g=k;
 while(k)
 {    
         string search_word;       //  cout<<"Enter word for search:";
         long int search_term_id=0;  //cin>>search_word; 
         search_word= A[p];
         file2.open(filename2.c_str(),ios::in);
       while ( file2 >> word2)
       {
           file2 >> word3;
           if ( search_word != word2)
           {
           }
           else
           { std::istringstream term (word3);
              term >> search_term_id;
              file2.close();
              break;
              
           }
       
       }
       Hashnode* item2=Search(search_term_id);//cout<<"posting list of "<<A[p]<<endl;
       R[p]=item2->posting;
       p++;
       k--;
      }
if(query_type ==1)
{
    int m=0,n=1;
    while(n<g)
    {
      R[1]=merge(R[1],R[1+n]);   // To merge multiple posting list for AND operation
      n++;
    }
    cout<<"Both words present in:"<<endl;
    while(*(R[1]+m)!=0)
    {
      cout<<*(R[1]+m)<<",";
      m++;
    }
    cout<<endl;
}
else if(query_type ==2)
{
   int m=0,n=1;
    while(n<g)
    {
      R[1]=add(R[1],R[1+n]);   // To merge multiple posting list for OR operation
      n++;
    }
    cout<<"Documents which have either of both words :"<<endl;
    while(*(R[1]+m)!=0)
    {
      cout<<*(R[1]+m)<<",";
      m++;
    }
    cout<<endl;

}
}
else
{
  
free(HashMap[TABLE_SIZE]);     
return 0;
}

}
}


