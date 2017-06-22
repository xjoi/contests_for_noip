#include <cstdio>
using namespace std;

#define M 700000

int n, k, i, j, m, p, a[510];
double b[710000];

double calc(int x, int y, double a) {
	return (y - x) * a + x;
}

int main() {
	scanf("%d%d", &n, &k);
	m = M / k;
	for (i = 1; i <= n; i++) {
		double ans = 0;
		for (j = 0; j <= k; j++)	scanf("%d", &a[j]);
		for (j = 0; j < k; j++) {
			for (p = 0; p < m; p++) {
				double s = calc(a[j], a[j + 1], 1.0 / m * (p + 0.5));
				if (s > b[j * m + p])	ans += s - b[j * m + p], b[j * m + p] = s;
			}
		}
		printf("%.10lf\n", ans / m);
	}
}
