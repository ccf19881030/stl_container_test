#ifndef _TEST_SLIST_H
#define _TEST_SLIST_H

#ifndef _WIN32
#include <ext/slist>

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

namespace jj10
{
	void test_slist(long& totalCount)
	{
		cout << "\ntest_slist()......... \n";

	    __gnu_cxx::slist<string> c;
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
		cout << "slist.size()= " << c.size() << endl;
		cout << "slist.front()= " << c.front() << endl;

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

#endif
