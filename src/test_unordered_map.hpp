#ifndef _TEST_UNORDERED_MAP_H
#define _TEST_UNORDERED_MAP_H

#include <unordered_map>			
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>   // snprintf()
#include <cstdlib>  // abort()
#include <algorithm>

#include "pub.h"

using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::find;
using std::sort;
using std::pair;

namespace jj16
{
	void test_unordered_map(long& totalCount)
	{
		cout << "\ntest_unordered_map()......... \n";

	unordered_map<long, string> c;
	char buf[10];
	clock_t timeStart = clock();
		for (long i = 0; i < totalCount; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand() % 65535);
				//c.insert(pair<long, string>(i, string(buf)));
				//c.insert(std::make_pair(i, string(buf)));
				//c.insert({ i, string(buf) });
				c[i] = string(buf);
			}
			catch (std::exception& e) {

				cout << "i=" << i << e.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "unordered_map.size()= " << c.size() << endl;
		cout << "unordered_map.max_size()= " << c.max_size() << endl;

	long target = get_a_target_long();
		{
			timeStart = clock();
	auto pItem = c.find(target);
			cout << "c.find(), mill-seconds: " << (clock() - timeStart) << endl;

			if (pItem != c.end())
				cout << "found, " << (*pItem).second << endl;
			else
				cout << "not found! " << endl;
		}
	}
}
#endif
