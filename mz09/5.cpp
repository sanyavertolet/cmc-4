#include <iostream>
#include <fstream>
#include <string>

#include "boost/date_time/gregorian/gregorian.hpp"

int main()
{
    std::string s;
    unsigned long long sum = 0;
    if(std::getline(std::cin,s)) {
        boost::gregorian::date d0 (boost::gregorian::from_simple_string(s));
        while(std::getline(std::cin,s)) {
            boost::gregorian::date d1 (boost::gregorian::from_simple_string(s));
            if(d1 >= d0) {
                sum += (d1-d0).days();
            } else {
                sum += (d0-d1).days();
            }
            d0 = d1;
        }
    }
    std::cout <<sum <<std::endl;

    return 0;
}


