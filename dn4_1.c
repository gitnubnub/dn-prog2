/*#include <stdio.h>
#include <stdlib.h>

int primerjavaTabel(int* tabela1, int* tabela2, int k, int n) {
	/*if (k <= n / 2) {
		for (int i = 0; i <= k; i++) {
			if (tabela1[i] != tabela2[n - 1 - k + i]) {
				return 0;
			}
		}
	} else {*/
		/*for (int i = k; i < n; i++) {
			if (tabela1[i] != tabela2[0 + i - k]) {
				return 0;
			}
		}
	//}

	return 1;
}

int main() {
	int n = 0;
	scanf("%d", &n);

	int* tabela1 = (int*) calloc(n, sizeof(int));
	int* tabela2 = (int*) calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		int stevilo = 0;
		scanf("%d", &stevilo);
		tabela1[i] = stevilo;
	}

	for (int i = 0; i < n; i++) {
		int stevilo = 0;
		scanf("%d", &stevilo);
		tabela2[i] = stevilo;
	}

	for (int k = 0; k < n; k++) {
		int soEnake = primerjavaTabel(tabela1, tabela2, k, n);
		if (soEnake) {
			printf("%d\n", k);
			free(tabela1);
			free(tabela2);
			return 0;
		}
	}
}*/

//boljša rešitev (avgust 2023):

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);

	int* tabela1 = (int*) calloc(n, sizeof(int));
	int* tabela2 = (int*) calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		int clen = 0;
		scanf("%d", &clen);
		tabela1[i] = clen;
	}

	for (int i = 0; i < n; i++) {
		int clen = 0;
		scanf("%d", &clen);
		tabela2[i] = clen;
	}

	for (int k = 0; k < n; k++) {
		int nasli = 1;
		for (int i = k; i < n; i++) {
			if (tabela1[i] != tabela2[i - k]) {
				nasli = 0;
				break;
			}
		}

		if (nasli) {
			printf("%d\n", k);
			return 0;
		}
	}

	free(tabela1);
	free(tabela2);
	return 0;
}
