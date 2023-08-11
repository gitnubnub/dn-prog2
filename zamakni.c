#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[2], "w");

	int z = 0;
	int trenutni = fgetc(input);

	while (trenutni != EOF) {
		while (trenutni == ' ') {
			trenutni = fgetc(input);
		}

		if (trenutni == '}' && z >= 4) {
			z -= 4;
		}
		int zadnji = trenutni;
		
		for (int i = 1; i <= z; i++) {
			fputc(' ', output);
		}

		while (trenutni != '\n') {
			fputc(trenutni, output);
			zadnji = trenutni;
			trenutni = fgetc(input);
		}

		if (zadnji == '{') {
			z += 4;
		}

		fputc(trenutni, output);
		trenutni = fgetc(input);
	}

	fclose(input);
	fclose(output);
	return 0;
}
