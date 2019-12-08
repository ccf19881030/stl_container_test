#ifndef _PUB_H_
#define _PUB_H_

#ifdef _MSC_VER
#define snprintf _snprintf  
#endif

#include <string>
#include <cstdio>
#include <iostream>

using std::string;
using std::cin;
using std::cout;

const long ASIZE = 1000000;

long get_a_target_long()
{
    long target = 0;
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
	
    return target;
}

string get_a_target_string()
{
    long target = 0;
    char buf[10];

    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    //sprintf(buf, "%d", target);
    
    return string(buf);
}
int compareLongs(const void* a, const void* b)
{
    return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b)
{
    if (*(string*)a > *(string*)b)
	    return 1;
    else if(*(string*)a < *(string*)b)
	    return -1;
    else
	    return 0;
}
#endif
