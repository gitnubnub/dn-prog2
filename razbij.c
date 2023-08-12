/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int k = atoi(argv[2]);
	char* ime = argv[1];
	FILE* inp = fopen(argv[1], "rb");

	unsigned char prebran;
	int stevec = 0;
	int stevecDat = 0;

	char imeOutputa[k];
	sprintf(imeOutputa, "%s.%d", ime, stevecDat);
	FILE* out = fopen(imeOutputa, "wb");
	while (fread(&prebran, sizeof(unsigned char), 1, inp)) {
		fwrite(&prebran, sizeof(unsigned char), 1, out);
		stevec++;

		if (stevec == k) {
			stevecDat++;
			fclose(out);
			sprintf(imeOutputa, "%s.%d", ime, stevecDat);
			FILE* out = fopen(imeOutputa, "wb");
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}*/

//lepša rešitev:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	FILE* datoteka = fopen(argv[1], "rb");
	int k = atoi(argv[2]);
	char* ime = argv[1];
	int imeLen = strlen(ime);

	unsigned char* prebrano = (unsigned char*) calloc(k, sizeof(unsigned char));
	int velikost = fread(prebrano, sizeof(unsigned char), k, datoteka);
	
	for (int i = 0; velikost; i++) {
		char* novoIme = (char*) calloc(imeLen + 9, sizeof(char));
		sprintf(novoIme, "%s.%d", ime, i);

		FILE* razbita = fopen(novoIme, "wb");
		fwrite(prebrano, sizeof(unsigned char), velikost, razbita);
		
		fclose(razbita);
		free(novoIme);
		velikost = fread(prebrano, sizeof(unsigned char), k, datoteka);
	}

	free(prebrano);
	fclose(datoteka);
	return 0;
}
