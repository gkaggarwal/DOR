#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;
const long int TABLE_SIZE = 8353;
const long int Total_operation = 5000;
const long int Total_value=100000;

struct Hashnode
{ long int frequency;
  long int term_id;
  int *posting;
};
struct Hashnode* HashMap[TABLE_SIZE];

static long int counter_insert; //counter for insertion
static long int counter_delete;
static long int counter_search;

long int HashIndex(long int term_id) {
   return term_id % TABLE_SIZE;
}
//--------------------------------------------------------------------------------------------
void Insert(long int term_id,long int freq, long int doc_id,int check)
{  
   if(check==0)
   {
   long int counter=0;
   struct Hashnode* item=(struct Hashnode*)malloc(sizeof(struct Hashnode*));
   int Post[1000];
   Post[0]=doc_id;
   item->frequency=freq;
   item->term_id=term_id;
   item->posting= Post;
   
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
   { HashMap[h_index]=item;
     counter_insert++;
   }
   }
   else
   {
   item->frequency+=freq;
   int *p;
   p=item->posting;
   p++;
   p=&doc_id;
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
         cout<<"("<<HashMap[i]->term_id<<","<<HashMap[i]->frequency<<")";
      else
         cout<<" ~~ ";
   }
	
   cout<<"\n";
}
//----------------------------------------------------------------------------------------------
int main()
{     
      srand((unsigned) time(0));
      long int term_id,value;
      long int choice=1;
      long int counter=1;
      while(1)
      {
          cout<<"\n----------------------"<<endl;
          cout<<"\nOperations on Hash Table"<<endl;
          cout<<"\n----------------------"<<endl;
          cout<<"1.Insert element long into the table"<<endl;
          cout<<"2.Search element from the term_id"<<endl;
          cout<<"3.Delete element at a term_id"<<endl;
          cout<<"4.Exit"<<endl;
          
          ++counter;
          if(counter>Total_operation)
          { choice++;
            counter=1;
          }
          //choice = (rand() % 1) + 1; //Random choice
          cout<<"Enter your choice: "<<choice<<endl;
          //cin>>choice;
          
        switch(choice)
        {
        case 1:
            value= (rand() % Total_value) + 1; // Random Value
            cout<<"Element to be inserted: "<<value<<endl;
            //cin>>value;
            term_id=(rand() % Total_value) + 1;   // Random term_id
            cout<<"term_id at which element to be inserted: "<<term_id<<endl;
            //cin>>term_id;
            Insert(term_id, value);
            //display();
            break;
       case 2:
            term_id=(rand() % Total_value) + 1;   // Random term_id
            cout<<"term_id of the element to be searched: "<<term_id<<endl;
            //cin>>term_id;
            if(Search(term_id) == NULL)
            {
                cout<<"No element found at term_id "<<term_id<<endl;
                //continue;
            }
            else
            {
                cout<<"Element at term_id "<<term_id<<" : ";
                cout<<Search(term_id)->frequency<<endl;
            }
            break;
        case 3:
            term_id=(rand() % Total_value) + 1;   // Random term_id
            cout<<"Enter term_id of the element to be deleted: "<<term_id<<endl;
            //cin>>term_id;
            Delete(term_id);
            //display();
            break;
        case 4:
            display();
            cout<<"NO of block access for insertion:"<<((float)counter_insert/Total_operation)<<"\n";
            cout<<"NO of block access for searching:"<<((float)counter_search/Total_operation)<<"\n";
            cout<<"NO of block access for deletion:"<<((float)counter_delete/Total_operation)<<"\n";
            return 0;
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
