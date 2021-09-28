#include <bits/stdc++.h>

using namespace std;

long long GetAnswer(long long a, long long b) {
	return a * b + a - b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// sort the sequence in non-decreasing order
		sort(a.begin(), a.end());
		/* 
			mx1 -> when the sequence consists of both positive and negative numbers
					-> used when there two or more negative numbers
					-> applying the formula would produce a positive value
					-> least negative numbers (first two elements)
					
		  mx2 -> when the sequence consists of all positive numbers
					-> the two largest elements would produce the maximum value
					
			mx3 -> when the sequence consists of negative numbers and 0 as its maximum
					-> a[n - 1] = 0, a[0] = least negative number
					-> applying the formula will turn it into a positive number (maximum value)
		*/
		long long mx1 = GetAnswer(a[1], a[0]);
		long long mx2 = GetAnswer(a[n - 1], a[n - 2]);
		long long mx3 = GetAnswer(a[n - 1], a[0]);
		cout << max({mx1, mx2, mx3}) << '\n';
	}
	return 0;
}
