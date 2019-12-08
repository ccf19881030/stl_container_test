#ifndef _TEST_MULTISET_H
#define _TEST_MULTISET_H

#include <set>
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>   // snprintf()
#include <cstdlib>  // abort()
#include <algorithm>

#include "pub.h"

using std::multiset;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::find;
using std::sort;

namespace jj06
{
	void test_multiset(long& totalCount)
	{
		cout << "\ntest_multiset()......... \n";

	std::multiset<string> c;
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
		cout << "multiset.size()= " << c.size() << endl;
		cout << "multiset.max_size()= " << c.max_size() << endl;

	string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);	// slower than c.find(...)
			cout << "::find(), mill-seconds: " << (clock() - timeStart) << endl;

			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		{
			timeStart = clock();
			auto pItem = c.find(target);		// faster than ::find(...)
			cout << "c.find(), mill-seconds: " << (clock() - timeStart) << endl;

			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}
	}
}
#endif
