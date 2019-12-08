#ifndef _TEST_ARRAY_H
#define _TEST_ARRAT_H

#include <string>
#include <array>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>  // qsort binarysreach, NULL

#include "pub.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::array;

namespace jj01
{
	void test_array()
	{
		cout << "\ntest_array()......... \n";

		array<long, ASIZE> c;

		//srand((unsigned)time(NULL));
		clock_t timeStart = clock();
		for (long i = 0; i < ASIZE; ++i) {
		    c[i] = rand() % 65535;
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "array.size()= " << c.size() << endl;
		cout << "array.front()= " << c.front() << endl;
		cout << "array.back()= " << c.back() << endl;
		cout << "array.data()= " << c.data() << endl;

		long target = get_a_target_long();

		timeStart = clock();
		
		cout << "-------------------before qsort: --------------" << endl;
		
		/*
		for (long i = 0; i < ASIZE; ++i)
		{
		    cout << "The " << i << " element is:" << c[i] << endl;
		}
		*/

		timeStart = clock();

		qsort(c.data(), ASIZE, sizeof(long), compareLongs);
		
		cout << "qsort(), milli-seconds: " << (clock() - timeStart) << endl;

		cout << "---------------------after qsort:------------------ " << endl;

		//timeStart = clock();
		/*
		for (long i = 0; i < ASIZE; ++i)
		{
		    cout << "The " << i << " element is:" << c[i] << endl;
		}
		*/


		cout << "array.size()= " << c.size() << endl;
		cout << "array.front()= " << c.front() << endl;
		cout << "array.back()= " << c.back() << endl;
		cout << "array.data()= " << c.data() << endl;

		timeStart = clock();

		long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
		cout << "bsearch(), milli-seconds: " << (clock() - timeStart) << endl;
		
		if (pItem != NULL)
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;
	}
}
#endif
