#include <stdio.h>
#include <stdlib.h>

int stNacinov = 0;

int urejeno(int* t, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (t[i] > t[i + 1]) {
			return 0;
		}
	}

	return 1;
}

void zamenjaj(int* t, int r, int i, int j) {
	int* temp = (int*) calloc(r, sizeof(int));
	for (int k = 0; k < r; k++) {
		temp[k] = t[i + k];
	}
	
	for (int k = 0; k < r; k++) {
		t[i + k] = t[j + k];
	}

	for (int k = 0; k < r; k++) {
		t[j + k] = temp[k];
	}

	free(temp);
	return;
}

void nacini(int* t, int n, int k, int r) {
	if (urejeno(t, n)) {
		stNacinov++;
	}

	if (k == 0) {
		return;
	}

	for (int prInd = 0; prInd <= n - 2 * r; prInd++) {
		if (prInd + r <= n - r) {
			for (int drInd = prInd + r; drInd <= n - r; drInd++) {
				zamenjaj(t, r, prInd, drInd);
				nacini(t, n, k - 1, r);
				zamenjaj(t, r, prInd, drInd);
			}
		}
	}

	return;
}

int main() {
	int n = 0;
	int k = 0;
	int r = 0;
	scanf("%d%d%d", &n, &k, &r);

	int* t = (int*) calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		int st = 0;
		scanf("%d", &st);
		t[i] = st;
	}

	nacini(t, n, k, r);
	printf("%d\n", stNacinov);

	free(t);
	return 0;
}