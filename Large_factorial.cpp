// large factorial problem

#include <bits/stdc++.h>

using namespace std;

void multiply(int *a, int &n, int no) {
	int carry = 0;
	for(int i = 0; i < n; i++) {
		int product = a[i]*no + carry;
		a[i] = product % 10;
		carry = product / 10;
	}
	while(carry > 0) {
		a[n] = carry % 10;
		carry = carry / 10;
		n++;
	}
}


void big_factorial(int number) {
	// Assuming that ans contains at max 1000 digits
	int *a = new int[1000];
	int i;
	for(i = 0; i < 1000; i++)
		a[i] = 0;
	a[0] = 1;
	int n = 1; // which denotes the index of the array before which we have stored some digits
	for(i = 2; i <= number; i++) {
		multiply(a, n, i);
	}
	for(i = n-1; i >= 0; i--)
		cout << a[i];
	cout << endl;
}

int main() {

	int t, n;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		big_factorial(n);
	}

	return 0;
}
