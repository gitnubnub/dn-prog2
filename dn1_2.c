#include <stdio.h>

int main() {
	int znak = getchar();
	int prvaEnica = 0;
	int stevec = 0;
	int stevec0 = 0;
	int stevec1 = 0;
	while (znak != '\n') {
		if (znak == '1') {
			prvaEnica = 1;
			stevec1++;
		} else if (prvaEnica) {
			stevec0++;
		}
		znak = getchar();
	}
	if (stevec1 >= stevec0) {
		stevec = stevec1 + stevec0;
		if (stevec0 == 0 && stevec1 == 1) {
			putchar('0');
			putchar('\n');
			return 0;
		}
	} else {
		stevec = stevec1 + stevec0 -1;
	}
	
	int delitelj = 100;
	int prviIzpis = 1;
	while (delitelj > 0) {
		if (stevec >= delitelj) {
			int stevka = stevec / delitelj;
			putchar(stevka + '0');
			prviIzpis = 0;
			stevec %= delitelj;
		} else if (!prviIzpis) {
			putchar('0');
		}
		delitelj /= 10;
	}

	putchar('\n');
	return 0;
}