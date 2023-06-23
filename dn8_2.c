#include <stdio.h>
#include <stdlib.h>

int zmagaCrni = 1;

void izpisiTabelo(int* moves) {
	printf("%d", moves[0]);
	for (int i = 1; moves[i] != 0; i++) {
		if (i % 2) {
			printf(" -> [%d]", moves[i]);
		} else {
			printf(" -> %d", moves[i]);
		}
	}
	printf("\n");
	return;
}

void poteze(int n, int k, int* moves, int poteza) {
	if (n <= k) {
		if (poteza % 2) {
			return;
		} else {
			moves[poteza] = n;
			izpisiTabelo(moves);
			zmagaCrni = 0;
			return;
		}
	}

	if (poteza % 2) {
		for (int i = 1; i <= k; i++) {
			moves[poteza] = i;
			poteze(n - i, k, moves, poteza + 1);
		}
	} else {
		if (n % (k + 1)) {
			moves[poteza] = (n % (k + 1));
			poteze(n - moves[poteza], k, moves, poteza + 1);
		} else {
			return;
		}
	}

	return;
}

int main() {
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);

	int* moves = (int*) calloc(n + 1, sizeof(int));

	if (k == 1 && n % 2 == 0) {
		printf("CRNI\n");
		return 0;
	}

	if (n <= k) {
		printf("%d\n", n);
		return 0;
	}

	poteze(n, k, moves, 0);
	if (zmagaCrni) {
		printf("CRNI\n");
	}

	free(moves);
	return 0;
}