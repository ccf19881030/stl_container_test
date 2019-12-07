#ifndef _TEST_LIST_H
#define _TEST_LIST_H

#include <list>
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
using std::list;
using std::exception;
using std::find;

namespace jj03
{
	void test_list(long& totalCount)
	{
		cout << "\ntest_list()......... \n";

	    list<string> c;
	    char buf[10];
		//srand((unsigned)time(NULL));
	    clock_t timeStart = clock();
		for (long i = 0; i < totalCount; ++i) 
		{
		    try {
			snprintf(buf, 10, "%d", rand() % 65535);
			c.push_back(string(buf));
		    } catch(std::exception& e) {

			cout << "i=" << i << e.what() << endl;
			abort();
		    }
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "list.size()= " << c.size() << endl;
		cout << "list.max_size()= " << c.max_size() << endl;
		cout << "list.front()= " << c.front() << endl;
		cout << "list.back()= " << c.back() << endl;

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
