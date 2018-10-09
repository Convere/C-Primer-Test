/*#include<iostream>
using namespace std;

int chengf(int k) {
	int sum = 0;
	for (int i = 0; i<k; i++) {
		sum *= 10;
	}
	return sum;
}
bool Weishu(int x) {
	double j = x / 10.0;
	int z = x;
	int n = 0, y = 0, a = 0;
	while (j >= 0.1) {
		n++;
		j = x / 10.0;
	}
	for (int l = 0; l<n; l++) {
		a = z % 10;
		z = z / 10;
		if (z >= 1)
			y += a*chengf(n - l - 1);
		else
			y += z;
	}
	return x == y;
}
int main() {
	for (int m = 11; m<13; m++) {
		if (Weishu(m) && Weishu(m*m) && Weishu(m*m*m)) {
			cout << "m=" << m;
			cout << "  m*m=" << m*m;
			cout << "  m*m*m=" << m*m*m << endl;
		}
	}
	return 0;
}*/