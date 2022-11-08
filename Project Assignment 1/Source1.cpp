#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long num[100005];
long long n;
long long ans = 0;
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &num[i]);
	}
	sort(num, num + n);
	if (n % 2 == 0) {
		for (int i = n - 1; i >= 1;) {
			ans += num[i] - num[i - 1];
			i -= 2;
		}
	}
	else {
		for (int i = n - 1; i > 0;) {
			ans += num[i] - num[i - 1];
			i -= 2;
		}
		ans += num[0];
	}

	printf("%lld", ans);
	return 0;
}
