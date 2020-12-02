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
static int n;
string word[50];
    
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
void divide(string inputString)
{ 
stringstream stringStream(inputString);
string line;
//static int i;
std::string delimiter1 = " OR ";
std::string delimiter2 = " AND ";
std::string delimiter3 = "NOT ";
string token;
std::getline(stringStream, line);
string s1,s2,s3,p1,p2,p3;
    std::size_t prev = 0, pos,pos1,pos2;
    if ((pos = line.find(delimiter1, prev)) != std::string::npos)
    {
           
           
            p1 = line.substr(pos+delimiter1.length(),line.length());
          //  divide(p1);
            s1 = line.substr(prev, pos-prev);       
            //divide(s1);
            if(s1.length() > p1.length())
                  {divide(s1);
                  divide(p1);
                  }
               else
                  {divide(p1);
                  divide(s1);
                  }

            // cout<<"OR"<<endl;
             word[n++]="OR";
    }
    else if((pos1 = line.find(delimiter2, prev)) != std::string::npos)
            {
                  
              p2 = line.substr(pos1+delimiter2.length(),line.length());
              s2 = line.substr(prev, pos1-prev);
              
               if(s2.length() > p2.length())
                  {divide(s2);
                  divide(p2);
                  }
               else
                  {divide(p2);
                  divide(s2);
                  }
              //cout<<"AND "<<endl;
              word[n++]="AND";
            }
    else if((pos2 = line.find(delimiter3, prev)) != std::string::npos)
            {
              p3 = line.substr(pos2+delimiter3.length(),line.length());
               //cout<<"s3="<<s3<<endl;
               divide(p3);
               word[n++]="NOT";
          //    cout<<"NOT "<<line<<endl;
            }           
               
     else
      { word[n++]=line;
      //cout<<line<<endl;     
      }  

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
long int * posting_ret(string search_word)
{      fstream file2;
        string filename2,word2,word3;
        filename2 = "vocab.dat";
        long int search_term_id=0;  //cin>>search_word; 
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
       if(search_term_id !=0)
       {
         Hashnode* item2=Search(search_term_id);//cout<<"posting list of "<<A[p]<<endl;
         return (item2->posting);
       }
       else
         {
           cout<<"word NOT found "<<search_word<<endl;
           return NULL;
         }
}

//------------------------------------------------------------------------------------------------

int main()
{
  fstream file1,file2;
    string word1_doc,word1_string,word1_freq,word2,word3, filename1,filename2; 
    filename1 = "dict0.dat"; 
    filename2 = "vocab.dat";
//-------------------------------------------------------------------------------------------------
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
  int case2;
  cout<<"Press 1 For Boolean Query\n"<<"Press 2 For Phrase Query"<<endl;    
  cin>>case2;
  if(case2==1)
   {  
    string inputString,s2 ;                //Boolean Query
    string A[100];
    char s1[100];
    fgets(s1,100,stdin);
    cout<<"Enter Query:";
    int and_query_type=0,or_query_type=0,not_query_type=0,and_operation=0,or_operation=0;
    fgets(s1,100,stdin);
    inputString=s1;
    n=0;
    divide(inputString);
    int p=0,q=0;
    long int* P[15];
    while(word[p]!="")
    {
        if(word[p]=="NOT")
        { 
         //P[q-1]=inverse(P[q-1];
         p++;
        }
        else if(word[p]=="AND")
        {
          P[q-2]= merge(P[q-1],P[q-2]);
           p++;
           q--;
        }
        else if(word[p]=="OR")
        {
          P[q-2]=add(P[q-1],P[q-2]);
          p++;
          q--;
        }
        else
        {
         if(posting_ret(word[p])!=NULL)
         {
          P[q]=posting_ret(word[p]);
          p++;
          q++;
         }
         else
         return 0;
        }
    
    }
    int t=0;
    cout<<"Documents retrieve after Query :"<<endl;
    while(*(P[0]+t)!=0)
    {
      cout<<*(P[0]+t)<<",";
      t++;
    }
    cout<<endl;

    }
    else
    {
           //Phrase Query
    
    }
 }
 else
 {
    //free(HashMap[TABLE_SIZE]);     
    return 0; 
 }
}
}
