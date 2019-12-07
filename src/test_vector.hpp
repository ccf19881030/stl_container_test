#ifndef _TEST_VECTOR_H
#define _TEST_VECTOR_H

#include <vector>
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
using std::vector;
using std::exception;
using std::find;

namespace jj02
{
	void test_vector(long& totalCount)
	{
		cout << "\ntest_vector()......... \n";

	    vector<string> c;
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
			// 曾经最高 i=58389486 then std::bad_alloc
			abort();
		    }
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "vector.size()= " << c.size() << endl;
		cout << "vector.front()= " << c.front() << endl;
		cout << "vector.back()= " << c.back() << endl;
		cout << "vector.data()= " << c.data() << endl;
		cout << "vector.capacity()= " << c.capacity() << endl;

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
		
		sort(c.begin(), c.end());
		
	    string* pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareStrings);
		cout << "sort()+bsearch(), milli-seconds: " << (clock() - timeStart) << endl;
		
		if (pItem != NULL)
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;
		}
	}
}
#endif
