/*
	Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

	You may assume that the intervals were initially sorted according to their start times.

	Example 1:

	Given intervals [1,3], [6,9] insert and merge [2,5] would result in [1,5], [6,9].

	Example 2:

	Given [1,2], [3,5], [6,7], [8,10], [12,16], insert and merge [4,9] would result in [1,2], [3,10], [12,16].

	This is because the new interval [4,9] overlaps with [3,5], [6,7], [8,10];
	Make sure the returned intervals are also sorted.
*/

#include<iostream>
#include<map>
#define pi pair<int, int>
using namespace std;
/*
		[-INF, 0]
	
		[1, 2] 
		[3, 5]
		[6, 7]
		[8, 10]
		[12, 16]

		[17, INF]

		Add [4, 9]
*/
void solve(pi A[], int n, pi newInterval){

	// write code here

	map <int, int> m;
	for (int i = 0; i < n; i++)
		m.insert(make_pair(A[i].first, A[i].second));

	// Add [-INF, first missing value before the intervals]
	m[INT_MIN] = m[m.begin() -> first - 1];
	// Add [first absent value after the intervals]
	m[m.rbegin() -> second + 1] = INT_MAX;

	int left = newInterval.first;
	int right = newInterval.second;

	// reference of intervals
	auto deleteFrom = m.lower_bound(left);
	auto deleteUpto = m.lower_bound(right);

	// left overlapping 
	if (left <= prev(deleteFrom) -> second){

		deleteFrom--;
		left = deleteFrom -> first;
	}

	// right overlapping
	right = (right, prev(deleteUpto) -> second);


	// delete overlapping intervals
	m.erase(deleteFrom, deleteUpto);

	// insert new interval
	m[left] = right;

	for (auto i : m)
		cout << i.first << ' ' << i.second << endl;

}

int main()
{
	pi B = pi(4, 9);
	pi A[] = {pi(1, 2), pi(3, 5), pi(6, 7), pi(8, 10), pi(12, 16)};
	int n = sizeof (A) / (2*sizeof (int)) ;

	solve(A, n, B);
}
