#ifndef _TEST_FORWARDLIST_H
#define _TEST_FORWARDLIST_H

#include <forward_list>
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>   // snprintf()
#include <cstdlib>  // abort()
#include <algorithm>

#include "pub.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::forward_list;
using std::exception;
using std::find;

namespace jj04
{
	void test_forward_list(long& totalCount)
	{
		cout << "\ntest_forward_list()......... \n";

	    forward_list<string> c;
	    char buf[10];
		//srand((unsigned)time(NULL));
	    clock_t timeStart = clock();
		for (long i = 0; i < totalCount; ++i) 
		{
		    try {
			snprintf(buf, 10, "%d", rand() % 65535);
			c.push_front(string(buf));
		    } catch(std::exception& e) {

			cout << "i=" << i << e.what() << endl;
			abort();
		    }
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		//cout << "forward_list.size()= " << c.size() << endl;	// no such member function
		cout << "forward_list.max_size()= " << c.max_size() << endl;
		cout << "forward_list.front()= " << c.front() << endl;
		//cout << "forward_list.back()= " << c.back() << endl;	// no such member function

	    string target = get_a_target_string();
		{
		timeStart = clock();
	    auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(), mill-seconds: " << (clock()-timeStart) << endl;

		if (pItem != c.end())
		    cout << "found, " << *pItem << endl;
		else
		    cout << "not found! " << endl;
		}	

		{
		timeStart = clock();
		
		c.sort();
		
		cout << "c.sort(), milli-seconds: " << (clock() - timeStart) << endl;
		}
	}
}
#endif
