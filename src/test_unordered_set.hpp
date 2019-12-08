#ifndef _TEST_UNORDERED_SET_H
#define _TEST_UNORDERED_SET_H

#include <unordered_set>
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>   // snprintf()
#include <cstdlib>  // abort()
#include <algorithm>

#include "pub.h"

using std::unordered_set;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::find;
using std::sort;

namespace jj15
{
	void test_unordered_set(long& totalCount)
	{
		cout << "\ntest_unordered_set()......... \n";

	unordered_set<string> c;
	char buf[10];
	clock_t timeStart = clock();
		for (long i = 0; i < totalCount; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand() % 65535);
				c.insert(string(buf));
			}
			catch (std::exception& e) {

				cout << "i=" << i << e.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "unordered_set.size()= " << c.size() << endl;
		cout << "unordered_set.max_size()= " << c.max_size() << endl;

	string target = get_a_target_string();
		{
			timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);	// 比c.find(...)慢很多
			cout << "::find(), mill-seconds: " << (clock() - timeStart) << endl;

			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		{
			timeStart = clock();
	auto pItem = c.find(target);		// 比::find(...)快很多
			cout << "c.find(), mill-seconds: " << (clock() - timeStart) << endl;

			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}
	}
}
#endif
