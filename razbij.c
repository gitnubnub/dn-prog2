#include <stdio.h>
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
}