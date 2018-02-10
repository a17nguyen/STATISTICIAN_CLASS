/* file: statistician.cpp
 * This file provides statistician properties by providing the length, sum, mean, minimum, and maximum of a sequence of numbers.
 *
 * Andrew Nguyen
 * COEN 79 Friday Lab
 */

#include <cassert>
#include <iostream>
#include "statistician.h"

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2{
   		void statistician::next(double r){
			count++;
			total = total + r;

			if(count==1){
				smallest=r;
      				largest=r;
      			}
	
			else if(r  < smallest)
           			smallest=r;
     			else if(r > largest)
          			largest=r;
		}
   		void statistician::reset( ){
			count=0;
			total=0;
			smallest=0;
			largest=0;
		}

	//PUBLIC CONSTANT member functions
		int statistician::length( ) const{
			return count;
       		}
   		double statistician::sum( ) const{
			return total;
       		}
		double statistician::mean( ) const{
			assert(count != 0);
      			return total/count;
       		}
		double statistician::minimum( ) const{
			assert(count != 0);
      			return smallest;
		}
		double statistician::maximum( ) const{
			assert(count != 0);
      			return largest;
       		}

    	//NON-MEMBER functions
		statistician operator +(const statistician& s1, const statistician& s2){
			statistician temp;
			temp.count= s1.count+s2.count;
			temp.total=s1.total + s2.total;
			if(s1.smallest<s2.smallest)
      				temp.smallest=s1.smallest;
			else
     				temp.smallest=s2.smallest;
			if(s1.largest>s2.smallest)
      				temp.largest=s1.largest;
			else
     				temp.largest=s2.largest;
			return temp;
       			}
		statistician operator *(double scale, const statistician& s){
			statistician temp;
			temp.count = (s.count) * scale;
			temp.total = (s.total) * scale;
			temp.smallest = s.smallest * scale;
			temp.largest = s.largest * scale;
			return temp;
		}
		bool operator ==(const statistician& s1, const statistician& s2){
			if(s1.length() == 0 && s2.length() ==0)
				return true;
			else if(s1.length()>0)
    				if(s1.length()==s2.length())
         				if(s1.sum()==s2.sum())
              					if(s1.mean()==s2.mean())
                   					if(s1.minimum()==s2.minimum())
                         					if(s1.maximum()==s2.maximum())
              								return true;
			return false;      
          	}
		
}
