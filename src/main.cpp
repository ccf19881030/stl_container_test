#include "test_array.hpp"
#include "test_vector.hpp"
#include "test_list.hpp"
#include "test_forwardlist.hpp"
#include "test_deque.hpp"
#include "test_stack.hpp"
#include "test_queue.hpp"

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
		jj05::test_deque(totalCount);
	break;
#ifndef _WIN32
	case 10:
		jj10::test_slist(totalCount);
		break;
#endif
    case 17:
		jj17::test_stack(totalCount);
		break;
    case 18:
		jj18::test_queue(totalCount);
		break;
    default:
		jj02::test_vector(totalCount);
		break;
    }

    getchar();

    return 0;
}
