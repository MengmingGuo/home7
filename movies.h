/*
 * Author: Mengming Guo
 *
 * Date: July 5, 2016
 *
 *
 * Description: this is header file for class movies
 *
 */
#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "DVD.h"

using namespace std;
class movies {
        
     public:
     	// CAPACITY is the maximum number of items a movies can hold
         static const size_t CAPACITY = 300;	
        
        // Default constructor
        // Postcondition: initialized the used is equal 0
        movies();

     
         // Member Functions

          // Precondition: None
       	  // Postcondition: use will be num
        void set_used(int num);

        // Precondition: used is less than capacity
       	 // Postcondition: object t1 will be added in object movies
        void insert(DVD& t1);
        // Precondition: None
       	  // Postcondition: display all datas
        void display_all();
        // Precondition: None
       	  // Postcondition: display certain rating
        void display_certain_rating(string str);
        // Precondition: None
       	  // Postcondition: search and display title is same with str
        void search_title(string str);
        // Precondition: None
       	  // Postcondition: remove movie whose title is same with str
        void remove(string str);
        // Precondition: None
       	  // Postcondition: movies will be sorted by title
        void sort_by_title();
        // Precondition: None
       	  // Postcondition: movies will be sorted by year
        void sort_by_year();
        // Precondition: None
       	  // Postcondition: movies will be saved
       void save();
      

     private:
    	
    	DVD data[CAPACITY];
    	size_t used;


};
#endif 
