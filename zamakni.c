//ne dela za testni primer 7 (samo vodilni presledki in po en oklepaj na vrstico)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	FILE* inp = fopen(argv[1], "r");
	FILE* out = fopen(argv[2], "w");

	int stPresledkov = 0;
	char* niz = (char*) calloc(1001, sizeof(char));
	while (fgets(niz, 1000, inp) != NULL) {
		int prebraniPresledki = 0;
		if (niz[0] == ' ') {
			for (int i = 0; niz[i] == ' '; i++) {
				prebraniPresledki++;
			}
		}

		int len = strlen(niz);
		if (stPresledkov && niz[prebraniPresledki] == '}') {
			stPresledkov -= 4;
		}

		if (stPresledkov) {
			for (int i = 1; i <= stPresledkov; i++) {
				fprintf(out, " ");
			}
		}

		fprintf(out, "%s", niz + prebraniPresledki);

		if (niz[len - 2] == '{') {
			stPresledkov += 4;
		}
	}

	free(niz);
	fclose(inp);
	fclose(out);
	return 0;
}