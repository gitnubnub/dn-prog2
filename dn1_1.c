#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;

	int znak = getchar();
	int negativen = 0;
	while (znak != ' ') {
		if (znak == '-') {
			negativen = 1;
			znak = getchar();
			continue;
		}

		a *= 10;
		a += (znak - '0');
		znak = getchar();
	}
	if (negativen) {
		a = -a;
	}

	znak = getchar();
	negativen = 0;
	while (znak != '\n') {
		if (znak == '-') {
			negativen = 1;
			znak = getchar();
			continue;
		}

		b *= 10;
		b += (znak - '0');
		znak = getchar();
	}
	if (negativen) {
		b = -b;
	}

	int vsota = a + b;
	if (vsota == 0) {
		putchar('0');
		putchar('\n');
		return 0;
	}

	if (vsota < 0) {
		putchar('-');
		vsota += (-2 * vsota);
	}

	int delitelj = 1000000000;
	int prviIzpis = 1;
	while (delitelj > 0) {
		if (vsota >= delitelj) {
			int stevka = vsota / delitelj;
			putchar(stevka + '0');
			prviIzpis = 0;
			vsota %= delitelj;
		} else if (!prviIzpis) {
			putchar('0');
		}
		delitelj /= 10;
	}
	
	putchar('\n');
	return 0;
}