/*
 * Author: Mengming Guo
 *
 * Date: July 5, 2016
 *
 *
 * Description: this is implementation file for class DVD
 *
 */
#include "DVD.h"

using namespace std;

DVD::DVD()
{   
	// Initialized DVD
	title = "NA";
	year = 0;
	running_time = 0;
	movie_type = "NA";
	rating = "NA";
}

DVD::DVD(string ti, int yr, int times, string type, string rat)
{
	title = ti;
	year = yr;
	running_time = times;
	movie_type = type;
	rating = rat;
}


 string DVD::get_title() const
 {
 	return title;
 }

int DVD::get_year() const
{
	return year;
}

int DVD::get_running_time()const
{
	return running_time;
}

string DVD::get_movie_type()const
{
   return movie_type;
}

string DVD::get_rating()const
{
	return rating;
}

void DVD::set_title(string str)
{
	title = str;
}

void DVD::set_year(int num)
{
    year = num;
}

void DVD::set_running_time(int num)
{
	if(num > 0)
	{
		running_time = num;
   }
}

void DVD::set_movie_type(string str)
{
	movie_type = str;
}

void DVD::set_rating(string str)
{
	rating = str;
}


istream& operator >>(istream& in, DVD& t)
{
    in >> t.title >> t.year >>t.running_time >> t.movie_type >> t.rating;
    return in;
}

ostream& operator <<(ostream& out, DVD& t)
{
	out <<  t.title << " " << t.year << " " <<  t.running_time << " "
	    <<  t.movie_type << " " << t.rating << endl;
	  return out;  
}