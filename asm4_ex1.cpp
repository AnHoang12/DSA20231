#include <iostream>
using namespace std;

int sum1(int n){
    if (n == 0 ) return 0;
    else return (n-1 + sum1(n-1));
}

int sum2(int n){
    int sum = 0;
    for (int i = 0; i<n;i++){
        sum = sum +i;
    }
    return sum;
}

int C1(int k, int n) {
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	return C1(k - 1, n - 1) + C1(k, n - 1);
} 

int fact(int n) {
	long long s = 1;
	for (int i = 1; i <= n; i++)
		s *= i;
	return s;
}
int C2(int k, int n) {
	return  fact(n) / (fact(k)*fact(n - k));
}

int GCD1(int a, int b){
    if (b == 0) {
        return a;
    }
    return GCD1(b, a % b);
}

int GCD2(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    cout << "Tong:" << sum2(3);
    cout << "\nTo hop:" << C2(2,3);
    cout << "\nUCLN:" << GCD2(15,20) << endl;
    return 0;
}