#ifndef __BINARYSEARCH_HPP__
#define __BINARYSEARCH_HPP__
//#include <vector>
//using namespace std;
#define NOT_FOUND -1
template<typename Comparable>
class BinarySearch{
public:
	BinarySearch(){}

	int binarySearch(const vector<Comparable> &A, const Comparable x) {
		int low = 0, high = A.size() - 1;
		while (low<=high)
		{
			int mid = (low + high) / 2;
			if (A[mid] < x) {
				low = mid + 1;
			}
			else if (A[mid] > x) {
				high = mid - 1;
			}
			else {
				//Cuando low=high=mid
				//y A[mid] == x
				return mid;
			}
		}
}

	int binarySearchMejor(const vector<Comparable> &A, const Comparable x) {
		int low = 0;
		int high = A.size() - 1;
		int mid;
		while (low<high) {
			mid = (low + high) / 2;
			if (A[mid] < x) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
		return (low == high) && A[low] == x ? low : NOT_FOUND;
	}

};

#endif // !__BINARYSEARCH_HPP__

