#include <stdio.h>

int do9(int znak) {
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

int do7(int znak) {
	while (znak != ' ' && znak != '\n') {
		if (!(znak >= '0' && znak <= '7')) {
			return 0;
		}
		znak = getchar();
	}

	if (znak == '\n') {
		return 2;
	}
	return 1;
}

int niclaB(int znak) {
	int prvi = 1;
	while (znak != ' ' && znak != '\n') {
		if (!(znak == '0' || znak == '1')) {
			return 0;
		}
		znak = getchar();
		prvi = 0;
	}

	if (znak == ' ' && prvi) {
		return -1;
	}

	if (znak == '\n') {
		if (prvi) {
			return -2;
		} else {
			return 2;
		}
	}

	return 1;
}

int niclaX(int znak) {
	int prvi = 1;
	while (znak != ' ' && znak != '\n') {
		if (!(znak >= '0' && znak <= 'F')) {
			return 0;
		}
		znak = getchar();
		prvi = 0;
	}

	if (znak == ' ' && prvi) {
		return -1;
	}

	if (znak == '\n') {
		if (prvi) {
			return -2;
		} else {
			return 2;
		}
	}

	return 1;
}

int nicla(int znak) {
	if (znak == 'x') {
		znak = getchar();
		int klic = niclaX(znak);
		return klic;

	} else if (znak == 'b') {
		znak = getchar();
		int klic = niclaB(znak);
		return klic;

	} else if (znak >= '0' && znak <= '7') {
		znak = getchar();
		int klic = do7(znak);
		return klic;

	} else if (znak == ' ' || znak == '\n') {
		return 1;
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
			int klic = nicla(znak);
			if (klic == 1 || klic == 2) {
				putchar('1');
				if (klic == 2) {
					break;
				}
				continue;
			} else {
				putchar('0');
				if (!klic) {
					while (znak != ' ' && znak != '\n') {
						znak = getchar();
					}
				} else if (klic == -2) {
					break;
				}
				continue;
			}
		} else if (znak >= '1' && znak <= '9') {
			znak = getchar();
			int klic = do9(znak);
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
			continue;
		}
	}

	putchar('\n');
	return 0;
}