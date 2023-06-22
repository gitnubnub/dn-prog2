#include <stdio.h>
#include <stdlib.h>

void izpis(int n, char** input, char* p, int j, int i1, int i2) {
	if (j == n) {
		for (int i = 0; i < n; i++) {
			printf("%c", p[i]);
		}
		printf("\n");
		return;
	}
	
	if (i1 >= n || i2 >= 42 || input[i1][i2] == '\n') {
		return;
	}
	
	p[j] = input[i1][i2];
	izpis(n, input, p, j + 1, i1 + 1, 0);
	p[j] = 0;
	izpis(n, input, p, j, i1, i2 + 1);
	return;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();

	char** input = (char**) calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		input[i] = (char*) calloc(42, sizeof(char));
		for (int j = 0; j <= 42; j++) {
			int znak = getchar();

			if (znak == '\n') {
				input[i][j] = znak;
				break;
			} else {
				input[i][j] = znak;
			}
		}
	}

	char* p = (char*) calloc(n, sizeof(char));
	izpis(n, input, p, 0, 0, 0);

	for (int i = 0; i < n; i++) {
        free(input[i]);
    }
    free(input);
    free(p);
	return 0;
}