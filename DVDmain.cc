/*
 * Author: Mengming Guo
 *
 * Date: July 5, 2016
 *
 *
 * Description: the main file for the program, sort, add, remove, search movies
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "DVD.h"
#include "movies.h"

using namespace std;

//Postcondition: print menu
void print_menu();

//Postocondition: Load movies from input file
void load(ifstream& instream, DVD& t1, movies& Data, int& count);


int main()
{
   
    int choice;
    int count = 0;
    ifstream instream;
    ofstream outstream;
    DVD t1; 
    movies Data;
    string title_name;
    string rating_enter;
    string str;

  
    cout << endl;
    cout << " Are you ready ? Let's go! " << endl;

       instream.open("moviesdata.txt");
    	if(!instream.fail())  // check the input file can open or not
    	   load(instream, t1, Data, count); // load movies
    	instream.close();
    do
    {   
 
    	print_menu();  // print menu
    	cout << endl;
    	cout << " Your choice is: ";
    	cin >> choice;
    	cout << endl;
    	switch(choice)
    	{
          
           
           case 1:  
                    cout << " Enter your insert DVD: ";
                    cin >> t1;
                    Data.insert(t1);  // add movie
                    break;
           
           case 2: 
                   cout << " Enter your remove movie's name: ";
                   cin >> title_name;
                   Data.remove(title_name);  // remove movie
                   break;
           
           case 3: 
                   cout << " Enter your rating: ";
                   cin >> rating_enter;
                   Data.display_certain_rating(rating_enter);  // print certain rating movies
                   break;
          
           case 4: 
                   Data.sort_by_title(); // sorted by title
                   break;
           
           case 5: 
                   Data.sort_by_year();  // sorted by year
                   break;
           
           case 6: 
                    Data.display_all(); // print all movies
                    break;

           case 7: 
                    cout << " Enter your search title" << endl;
                    cin >> str;
                    Data.search_title(str);  // search movies
                    break;
                      
           case 0: 
                    cout << " Quit " << endl;
                    break;           
                                                         
           default: cout << " " << choice << " is invalid, enter again. " << endl;
    	}
       
      
        Data.save();
                           // save to file
    }while( (choice != 0));

 return 0;
}

void print_menu()
{
	cout << endl;
	cout << " Your work will automatiocally saved." << endl;
	cout << " The followig choices are available: " << endl;
	cout << " 1  Insert an additional movie. " << endl;
	cout << " 2  Remove a movie, enter title what your want to remove " << endl;
	cout << " 3  Display certain rating movies, enter your rating. " <<endl;
	cout << " 4  Sort movies by title. " << endl;
	cout << " 5  Sort movies by year." << endl;
	cout << " 6  Display all movies. "<< endl;
	cout << " 7  Search by title." << endl;
	cout << " Enter 0 to quit, your work will be saved to the file." << endl;
}


void load(ifstream& instream, DVD& t1, movies& Data, int& count)
{
	
	string ti; 
    int yr; 
    int times; 
    string type; 
    string rat;

	Data.set_used(0); // set used is 0

	instream >> ti;
	
  while(!instream.eof())
	{  
		t1.set_title(ti); // set title is ti
		
		instream >> yr;
		t1.set_year(yr);  // set year is yr
		

		instream >> times;
		t1.set_running_time(times); // set running time is times
		

		instream >> type;
		t1.set_movie_type(type); // set movie type is type
		
		instream >> rat;
		t1.set_rating(rat);  // set rating is rat
		

        Data.insert(t1);  // insert t1 into movies
        count ++;
        instream >> ti;
	}

	instream.close();
}










