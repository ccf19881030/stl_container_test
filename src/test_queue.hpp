#ifndef _TEST_QUEUE_H
#define _TEST_QUEUE_H

#include <queue>
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
using std::queue;
using std::exception;
using std::find;
using std::sort;

namespace jj18
{
	void test_queue(long& totalCount)
	{
		cout << "\ntest_stack()......... \n";

	    queue<string> c;
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
		cout << "queue.size()= " << c.size() << endl;
		cout << "queue.front()= " << c.front() << endl;
		cout << "queue.back()= " << c.back() << endl;
		c.pop();
		cout << "queue.size()= " << c.size() << endl;
		cout << "queue.front()= " << c.front() << endl;
		cout << "queue.back()= " << c.back() << endl;
	}
}
#endif
