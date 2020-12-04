#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
#include<math.h>
using namespace std;
const long int TABLE_SIZE = 100000;
const long int Total_operation = 5000;
const long int Total_value=100000;
const long int P_size=10000;
const long int Total_doc=810257;
struct Hashnode
{ long int frequency;
  long int term_id;
  pair<long int,long int> *posting;
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
   
   (item->posting)=(pair<long int,long int>*)calloc(P_size,sizeof(pair<long int,long int>));
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
   { (*(item->posting)).first=1;//Document frequency
     (*(item->posting+1)).first=doc_id;
     (*(item->posting+1)).second=freq;
     HashMap[h_index]=item;
     counter_insert++;
   }
   }
   else if(check==1)
   {
   item1->frequency+=freq;
   long int i=0;
   while(i<P_size && (*(item1->posting+i)).first!=0)
   {
    i++;
   }
   if(i<P_size)
   {
    ((*(item1->posting)).first)+=1; 
   ((*(item1->posting+i)).first)=doc_id;
   ((*(item1->posting+i)).second)=freq;
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

pair<long int,long int>* merge(pair<long int,long int> *A,pair<long int,long int> *B)
{ int i=0,j=0,count=0;
  pair<long int,long int> *c;
  c=(pair<long int,long int> *)calloc(P_size,sizeof(pair<long int,long int>));
  while((*(A+i)).first !=0 && (*(B+j)).first !=0)
  {
     if((*(A+i)).first ==( *(B+j)).first)
     {
     c[count].first=(*(A+i)).first;  //cout<<(*(A+i))<<",";
      c[count].second=(*(A+i)).second;
     count++;
     i++;
     j++;
     }
     else if((*(A+i)).first< (*(B+j)).first)
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
pair<long int,long int>* add(pair<long int,long int>* A,pair<long int,long int>* B)
{ int i=0,j=0,count=0;
  pair<long int,long int> *c;
  c=(pair<long int,long int>*)calloc(2*P_size,sizeof(pair<long int,long int>*));
  while((*(A+i)).first !=0)
  {
       c[count].first=(*(A+i)).first;  //cout<<(*(A+i))<<",";
       c[count].second=(*(A+i)).second;
       count++;
       i++;
     
  }
  while((*(B+j)).first !=0)
  {
       c[count].first=(*(B+j)).first;  //cout<<(*(B+i))<<",";
       c[count].second=(*(B+j)).second;
       count++;
       j++;
     
  }
  return c;
}
//-------------------------------------------------------------------------------------------------
pair<long int,long int>* inverse(pair<long int,long int>* A)
{
       pair<long int,long int> *c;
       long int count=1;
       c=(pair<long int,long int>*)calloc(Total_doc,sizeof(pair<long int,long int>*));
  
       fstream file;
       string filename;
       long int word;
       filename ="Doc_list.dat";
       file.open("Doc_list.dat",ios::in);
       c[0].first=(*(A)).first;
       while(file >> word)
        {
           //cout<<"Doc"<<word<<endl;
          
           int i=1,match=0;
          while((*(A+i)).first!=0 && i<P_size)
          { 
           if(word != (*(A+i)).first)
           {
            i++;
           }
           else
           {
            match=1;
            break;
           }
        }
          
          if(match==0 && count<Total_doc)
          { 
           c[count].first=(*(A+i)).first;
           c[count].second=(*(A+i)).second;
           count++;
          }
        }
        return c;
}
//-------------------------------------------------------------------------------------------------
pair<long int,long int>* posting_ret(string search_word)
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
pair<long int,double>* retrieve_best(pair<long int,long int>*A[])
{
//A has the document name which has all the query terms
//word[] array has all the word
//retrieve posting list can be used for posting list retireval of each word
// for a single doc in A (tf(t,d).idf)

int n=0,i=1,j=1,m=1;
pair<long int,double> *c;
long int count=1;
c=(pair<long int,double>*)calloc(Total_doc,sizeof(pair<long int,double>*));
  
while((*(A[0]+i)).first!=0)
{  double score=0;
   long int term_freq=0,doc_freq=0;
   while((*(A[j]+m)).first!=0)
   {
      if((*(A[0]+i)).first != (*(A[j]+m)).first)
      {
        m++;
      }
      else
      {
       term_freq=(*(A[j]+m)).second;
       doc_freq=(*(A[j])).first;
       m=0;
       score+=(term_freq * log10(Total_doc/doc_freq)) ;
       j++;
      
      }
   }
  
  c[count].first=(*(A[0]+i)).first;
  c[count].second=score;
  i++;
  j=1;
  count++;
}

return c;

}
//------------------------------------------------------------------------------------------------
void parse(string inputString)
{
stringstream stringStream(inputString);
string line,wordp;
while(std::getline(stringStream, line)) 
{   int c=0;
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of(" ", prev)) != std::string::npos)
    {
        if (pos > prev)
            {
            wordp = line.substr(prev, pos-prev);
             if(wordp!= "at" && wordp!= "and"&& wordp!= "or" && wordp!= "not" && wordp!= "a" && wordp!= "an" && wordp!= "on" && wordp!= "by" && wordp!= "also" && wordp!= "also" && wordp!= "am" && wordp!= "any" && wordp!= "are"  && wordp!= "as" && wordp!= "be" && wordp!= "been" && wordp!= "but" && wordp!= "can" && wordp!= "cannot" && wordp!= "could" && wordp!= "did" && wordp!= "do" && wordp!= "does" && wordp!= "either" && wordp!= "else" && wordp!= "ever" && wordp!= "for" && wordp!= "from" && wordp!= "had" && wordp!= "has" && wordp!= "have" && wordp!= "her" && wordp!= "him" && wordp!= "how" && wordp!= "however" && wordp!= "i" && wordp!= "if" && wordp!= "in" && wordp!= "into" && wordp!= "is" && wordp!= "its" && wordp!= "it" && wordp!= "just" && wordp!= "least" && wordp!= "let" && wordp!= "may" && wordp!= "me" && wordp!= "might" && wordp!= "my" && wordp!= "no" && wordp!= "nor" && wordp!= "off" && wordp!= "of" && wordp!= "other" && wordp!= "our" && wordp!= "so" && wordp!= "than" && wordp!= "that" && wordp!= "there" && wordp!= "their" && wordp!= "them" && wordp!= "these" && wordp!= "they" && wordp!= "this" && wordp!= "to" && wordp!= "too" && wordp!= "us" && wordp!= "was" && wordp!= "we" && wordp!= "were" && wordp!= "what" && wordp!= "when" && wordp!= "when" && wordp!= "where" && wordp!= "which" && wordp!= "while" && wordp!= "who" && wordp!= "whom" && wordp!= "why" && wordp!= "yet" && wordp!= "you" && wordp!= "your")
         //   cout<<wordp<<endl;
            word[c++]=wordp;
            }
        prev = pos+1;
    }
    if (prev < line.length())
      {wordp = line.substr(prev, line.length()-prev);
            //cout<<wordp<<endl;
            word[c]=wordp;
            }  
}  
}

//-------------------------------------------------------------------------------------------------

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
{  Label:
    int case1;
    cout<<"Press 1 For Search\n"<<"Press 2 For Exit"<<endl;    
    cin>>case1;
    int p=0;
   while(word[p]!="")
   {
    word[p++]="";
   } 
    
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
    pair<long int,long int> *P[15];
    while(word[p]!="")
    {
        if(word[p]=="NOT")
        { 
         P[q-1]=inverse(P[q-1]);
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
         {
         goto Label;
         }
        }
    
    }
    int t=0;
    cout<<"Documents retrieve after Query :"<<endl;
    while((*(P[0]+t)).first!=0)
    {
      cout<<"("<<(*(P[0]+t)).first<<","<<(*(P[0]+t)).second<<")"<<" ";
      t++;
    }
    cout<<endl;

    }
    else
    {
         string inputString,s2 ;                //Phrase Query
         string A[100];
         char s1[100];
         fgets(s1,100,stdin);
         cout<<"Enter Query:";
         fgets(s1,100,stdin);
         inputString=s1;
         parse(inputString);
         int f=1;
         pair<long int,long int> *P[50];
         if(word[0]!="")
         P[0]=posting_ret(word[0]);
         P[1]=posting_ret(word[0]);
         
         while(word[f]!="")
         {
            P[f+1]=posting_ret(word[f]);
            P[0]=merge(P[0],P[f+1]);
            f++;
         }
         /*
         int t=0;
         cout<<"Documents retrieve after Query without rank:"<<endl;
         while((*(P[0]+t)).first!=0)
         {
            cout<<"("<<(*(P[0]+t)).first<<","<<(*(P[0]+t)).second<<")"<<" ";
             t++;
         }
         cout<<endl;*/
         pair<long int,double> *S;
         S=retrieve_best(P);                                                   
         long int x=1;
         cout<<"Documents retrieve after Query :"<<endl;
         while((*(S+x)).first!=0)
         {
            cout<<"("<<(*(S+x)).first<<","<<(*(S+x)).second<<")"<<" ";
             x++;
         }
         cout<<endl;
         
    }
 }
 else
 {
    //free(HashMap[TABLE_SIZE]);     
    return 0; 
 }
}
}
