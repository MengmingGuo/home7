/*
 * Author: Mengming Guo
 *
 * Date: July 5, 2016
 *
 *
 * Description: this is implementation file for class movies
 *
 */

#include "DVD.h"
#include "movies.h"



using namespace std;

const size_t movies::CAPACITY;

movies::movies()
{
	used = 0;
}

void movies::set_used(int num)
{
	used = num;
}

void movies::display_all()
{
	for(size_t i = 0; i < used; i++)
	{
	  cout << data[i];
	}
}

void movies::insert(DVD& t1)
{
	if(used < CAPACITY)
		{
			data[used] = t1;
	        used ++;
         }
     else
	{
		cout << " Cannot hold more information " << endl;
	}   
}

void movies::remove(string str)
{
	for(size_t i =0; i < used -1; i++)
	{  
		if(data[i].get_title() == str)
		{
			 data[i] = data[used -1];
			 used --;
		}
	}	
		if(data[used -1].get_title() == str)
		   used --;
}

void movies::display_certain_rating(string str)
{  
     int count = 0;	
    for(size_t i = 0; i < used; i++)
         {
         	if (data[i].get_rating() == str)
         	{
         		cout << data[i];
         		count ++;
         	}
        }
      if(count == 0)
      {
      	cout << " Entered rating is invalid" << endl;
      }   
}

void movies::search_title(string str)
{    
	int count = 0;
	 for(size_t i = 0; i < used; i++)
    {
    	if(data[i].get_title() == str)
    	{
    		  cout << " Your search in the file: " << endl;
    		  cout << data[i];
    		  count ++;
    	}
     }
    if(count == 0)
    {
    	cout << " Entered Title cannot be found in the file" << endl;
    }
}

void movies::sort_by_title()
{
	bool done = false;
	int j;
	DVD Temp;
    while(!done)
    {
    	done = true;
       for(j= used-1; j > 0; --j)
       {    
       	   if(data[j].get_title() < data[j-1].get_title() )  // sorted by title
       	   {
       	   	done = false;
       	   	Temp = data[j -1];
       	   	data[j -1] = data[j];
       	   	data[j] = Temp;
           }
        }
     } 
}

void movies::sort_by_year()
{
    bool done = false;
	int j;
	DVD temp;
    while(!done)
    {
    	done = true;
       for(j=used-1; j > 0; --j)
       {
       	   if(data[j].get_year() < data[j-1].get_year())  // sorted by year
       	   {             
       	   	   done = false;
       	   	   temp = data[j];
       	   	   data[j] = data[j-1];
       	   	   data[j -1] = temp;
       	   	}
       	  }
       	}  
}


void movies::save() 
{       
           ofstream outstream;
           outstream.open("moviesdata.txt");
          if(!outstream.fail())
           {
	       for(int i = 0; i < used; i++)
	   {  
	   	outstream << data[i];
	       }
          }
            outstream.close();   
}









