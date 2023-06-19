#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);
	int* pojavitve = (int*) calloc(1000000000 + 1, sizeof(int));

	for (int i = 0; i < n; i++) {
		int stevilo = 0;
		scanf("%d", &stevilo);
		pojavitve[stevilo]++;
	}

	long long stevec = 0;
	for (int i = 1; i <= k / 2; i++) {
		long a = pojavitve[i];
		long b = pojavitve[k - i];
		if (i == k - i) {
			stevec += (a - 1) * a / 2;
			continue;
		}
		stevec += a * b;
	}
	/*int* tabela = (int*) calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		int stevilo = 0;
		scanf("%d", &stevilo);
		tabela[i] = stevilo;
	}

	int stevec = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int vsota = tabela[i] + tabela[j];
			if (vsota == k) {
				stevec++;
			} else if (vsota > k) {
				break;
			}
		}
	}*/

	free(pojavitve);
	printf("%lld\n", stevec);
	return 0;
}