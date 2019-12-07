#ifndef _TEST_STACK_H
#define _TEST_STACK_H

#include <stack>
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
using std::stack;
using std::exception;
using std::find;
using std::sort;

namespace jj17
{
	void test_stack(long& totalCount)
	{
		cout << "\ntest_stack()......... \n";

	    stack<string> c;
	    char buf[10];
		//srand((unsigned)time(NULL));
	    clock_t timeStart = clock();
		for (long i = 0; i < totalCount; ++i) 
		{
		    try {
			snprintf(buf, 10, "%d", rand() % 65535);
			c.push(string(buf));
		    } catch(std::exception& e) {

			cout << "i=" << i << e.what() << endl;
			abort();
		    }
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "stack.size()= " << c.size() << endl;
		cout << "stack.top()= " << c.top() << endl;
		c.pop();
		cout << "stack.size()= " << c.size() << endl;
		cout << "stack.top()= " << c.top() << endl;
	}
}
#endif
