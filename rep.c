//5. testni primer ne dela (segmentation fault)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	FILE* datoteka = fopen(argv[1], "r");
	int n = atoi(argv[2]);

	char** izpis = (char**) calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		izpis[i] = (char*) calloc(11, sizeof(char));
	}

	int vrstica = 0;
	int daljse = 0;
	while (fgets(izpis[vrstica], 11, datoteka) != NULL) {
		vrstica++;

		if (vrstica == n) {
			vrstica = 0;
			daljse = 1;
		}
	}

	if (daljse) {
		for (int i = vrstica; i < n; i++) {
		printf("%s", izpis[i]);
	}
	}

	for (int i = 0; i < vrstica; i++) {
		printf("%s", izpis[i]);
	}

	for (int i = 0; i <= n; i++) {
		free(izpis[i]);
	}
	free(izpis);

	fclose(datoteka);
	return 0;
}