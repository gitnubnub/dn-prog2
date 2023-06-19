#include <stdio.h>

int pred0(int znak) {
	if (znak == ' ' || znak == '\n') {
		return 1;
	} else {
		return 0;
	}
}

int pred1(int znak) {
	while (znak != ' ' && znak != '\n') {
		if (!(znak >= '0' && znak <= '9')) {
			return 0;
		}
		znak = getchar();
	}
	if (znak == '\n') {
		return 2;
	}
	return 1;
}

int predznak(int znak) {
	if (znak == '0') {
		znak = getchar();
		if (pred0(znak)) {
			return 1;
		} else {
			return 0;
		}
	} else if (znak >= '1' && znak <= '9') {
		znak = getchar();
		int klic = pred1(znak);
		if (klic == 1) {
			return 1;
		} else if (klic == 2) {
			return 2;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

int main() {
	int znak = 0;
	while (znak != '\n') {
		znak = getchar();
		if (znak == '0') {
			znak = getchar();
			if (pred0(znak)) {
				putchar('1');
				continue;
			} else {
				putchar('0');
				while (znak != ' ' && znak != '\n') {
					znak = getchar();
				}
				continue;
			}
		} else if (znak >= '1' && znak <= '9') {
			znak = getchar();
			int klic = pred1(znak);
			if (klic) {
				putchar('1');
				if (klic == 2) {
					break;
				}
				continue;
			} else {
				putchar('0');
				while (znak != ' ' && znak != '\n') {
					znak = getchar();
				}
				continue;
			}
		} else if (znak == '+' || znak == '-') {
			znak = getchar();
			int klic = predznak(znak);
			if (klic) {
				putchar('1');
				if (klic == 2) {
					break;
				}
				continue;
			} else {
				putchar('0');
				while (znak != ' ' && znak != '\n') {
					znak = getchar();
				}
				continue;
			}
		} else {
			putchar('0');
			while (znak != ' ' && znak != '\n') {
				znak = getchar();
			}
		}
	}

	putchar('\n');
	return 0;
}