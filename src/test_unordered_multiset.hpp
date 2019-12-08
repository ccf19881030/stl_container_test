#ifndef _TEST_UNORDERED_MULTISET_H
#define _TEST_UNORDERED_MULTISET_H

#include <unordered_set>
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>   // snprintf()
#include <cstdlib>  // abort()
#include <algorithm>

#include "pub.h"

using std::unordered_multiset;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::find;
using std::sort;

namespace jj08
{
	void test_unordered_multiset(long& totalCount)
	{
		cout << "\ntest_unordered_multiset()......... \n";

	unordered_multiset<string> c;
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
		cout << "unordered_multiset.size()= " << c.size() << endl;
		cout << "unordered_multiset.max_size()= " << c.max_size() << endl;
		cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << endl;
		cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;
		cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;
		cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << endl;

		for (unsigned long i = 0; i < 20; ++i) {
			cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
		}

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
