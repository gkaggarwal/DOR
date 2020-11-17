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
long int Array[TABLE_SIZE][3000]={0};

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
   { item->posting=Array[h_index];
     Array[h_index][0]=doc_id;
     HashMap[h_index]=item;
     counter_insert++;
   }
   }
   else if(check==1)
   {
   item1->frequency+=freq;
   long int i=0;
   while(*(item1->posting+i)!=0)
   {//cout<<*(item1->posting+i)<<",";
    i++;
   }
   
   (*(item1->posting+i))=doc_id;
   }
}
//----------------------------------------------------------------------------------------------
struct Hashnode* Delete(long int term_id)
{
   struct Hashnode* dummy_item=(struct Hashnode*)malloc(sizeof(struct Hashnode*));
   dummy_item->frequency=-1;
   dummy_item->term_id=-1;
   
   long int h_index=HashIndex(term_id);
   long int counter=0;
   while(HashMap[h_index]!=NULL)
   {
    if(HashMap[h_index]->term_id == term_id)
     {
      ++counter_delete;
      struct Hashnode* temp=HashMap[h_index];
      
      HashMap[h_index]=dummy_item;
      return temp;
     }
     ++h_index;
     counter++;
     ++counter_delete;
     if(counter==TABLE_SIZE)
     break;
     h_index%=TABLE_SIZE;
   }
   return NULL;
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
void display() 
{
   long int i = 0;
   for(i = 0; i<TABLE_SIZE; i++) {
      if(HashMap[i] != NULL)
         cout<<"("<<HashMap[i]->term_id<<","<<HashMap[i]->frequency<<","<<*(HashMap[i]->posting)<<")";
      else
         cout<<" ~~ ";
   }
	
   cout<<"\n";
}
//----------------------------------------------------------------------------------------------
void display_posting(Hashnode* item1)
{
 long int *p;
 p=item1->posting;
 int i=0;
 while(*(p+i)!=0)
 {
 cout<<*(p+i)<<",";
 i++;
 }
 cout<<"\nTotal documents="<<i<<endl;
}
//-------------------------------------------------------------------------------------------------

int main()
{
  fstream file1,file2;
    string word1_doc,word1_string,word1_freq,word2,word3, filename1,filename2; 
    filename1 = "dict0.dat"; 
    filename2 = "vocab.dat";
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
       freq>>frequency;
      //cout<<term_id<<" "<<doc_id<<" "<<frequency<<endl;
    
    if(Search(term_id) == NULL)
    {
     Insert(term_id, frequency,doc_id);
    }
    else
    {
     Hashnode* item1=Search(term_id);
   //  cout<<"Term id= "<<term_id<<endl;
     Insert(term_id, frequency,doc_id,1,item1);
     
 //  display_posting(item1);           
      
    }
    }
 while(1)
 {   int switch_case;
     cout<<"press 1 for search"<<endl;
     cout<<"press 2 to exit"<<endl;
     cin>>switch_case;
     if(switch_case==1)
     {
       
         cout<<"Enter word for search:";
         string search_word;
         long int search_term_id;
         cin>>search_word;
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
       Hashnode* item2=Search(search_term_id);
       display_posting(item2);
     }
    else
      return 0;
}
return 0;
}


