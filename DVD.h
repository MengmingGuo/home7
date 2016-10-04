/*
 * Author: Mengming Guo
 *
 * Date: July 5, 2016
 *
 *
 * Description: this is header file for class DVD
 *
 */
#ifndef DVD_H
#define DVD_H
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class DVD
 
 {

       public:
          
         // Default constructor
       	 DVD(); // Postcondition: the DVD has been initialized
       	 DVD(string ti, int yr, int times, string type, string rat);
         // Postcondition: the DVD will be initialized

           // Member Functions

          // Precondition: None
       	  // Postcondition: return title
          string get_title() const;
          // Precondition: None
          // Postcondition: return year
          int get_year() const;
          // Precondition: None
          // Postcondition: return running time
          int get_running_time() const;
          // Precondition: None
          // Postcondition: return movie type
          string get_movie_type() const;
          // Precondition: None
          // Postcondition: return rating
          string get_rating() const;
          
          //Precondition: None
          // Postcondition: title will be str
          void set_title(string str);
          //Precondition: None
          // Postcondition: year will be num
          void set_year(int num);
          //Precondition: None
          // Postcondition: running time will be num
          void set_running_time(int num);
          //Precondition: None
          // Postcondition: movie type will be str
          void set_movie_type(string str);
          //Precondition: None
          // Postcondition: rating will be str
          void set_rating(string str);

        
          // Friend functions
          // Over load >> and <<
          friend istream& operator >>(istream& in, DVD& t);
          friend ostream& operator <<(ostream& out, DVD& t);

  
    private:   	
   	     string title;
   	     int year;
   	     int running_time;
   	     string movie_type;
   	     string rating;

};
#endif 