#include "test_array.hpp"
#include "test_vector.hpp"
#include "test_list.hpp"
#include "test_forwardlist.hpp"
#include "test_deque.hpp"
#include "test_stack.hpp"
#include "test_queue.hpp"
#include "test_multiset.hpp"
#include "test_multimap.hpp"
#include "test_unordered_multiset.hpp"
#include "test_unordered_multimap.hpp"
#include "test_set.hpp"
#include "test_map.hpp"
#include "test_unordered_set.hpp"
#include "test_unordered_map.hpp"

#include "test_slist.hpp"

int main(int argc, char* argv[])
{
int select;
    
    cout << "select: ";
    cin >> select;
long totalCount;
    cout << "how many elements:";
    cin >> totalCount;
    
    srand((unsigned)time(NULL));
    
    switch(select)
    {
    case 1:
		jj01::test_array();
		break;
    case 2:
		jj02::test_vector(totalCount);
		break;
    case 3:
		jj03::test_list(totalCount);
		break;
    case 4:
		jj04::test_forward_list(totalCount);
		break;
    case 5:
		jj05::test_deque(totalCount);
		break;
	case 6:
		jj06::test_multiset(totalCount);
		break;
	case 7:
		jj07::test_multimap(totalCount);
		break;
	case 8:
		jj08::test_unordered_multiset(totalCount);
		break;
	case 9:
		jj09::test_unordered_multimap(totalCount);
		break;
#ifndef _WIN32
	case 10:
		jj10::test_slist(totalCount);
		break;
#endif
	case 13:
		jj13::test_set(totalCount);
		break;
	case 14:
		jj14::test_map(totalCount);
		break;
	case 15:
		jj15::test_unordered_set(totalCount);
		break;
	case 16:
		jj16::test_unordered_map(totalCount);
		break;
    case 17:
		jj17::test_stack(totalCount);
		break;
    case 18:
		jj18::test_queue(totalCount);
		break;
    default:
		break;
    }

    getchar();

    return 0;
}
