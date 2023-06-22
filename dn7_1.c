#include <stdio.h>
#include <stdlib.h>

int visinaDrevesa(int** drevo, int i, int visina) {
	int visinaLeva = visina;
	int visinaDesna = visina;

	if (drevo[i][0] == 0 && drevo[i][1] == 0) {
		return 1;
	}
	
	if (drevo[i][0] != 0) {
		visinaLeva += visinaDrevesa(drevo, drevo[i][0] + i, visinaLeva);
	}
	
	if (drevo[i][1] != 0) {
		visinaDesna += visinaDrevesa(drevo, drevo[i][1] + i, visinaDesna);
	}

	if (visinaLeva > visinaDesna) {
		return visinaLeva + 1;
	} else {
		return visinaDesna + 1;
	}
}

int main() {
	int n = 0;
	scanf("%d", &n);

	int** tabela = (int**) calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		tabela[i] = (int*) calloc(2, sizeof(int));
		for (int j = 0; j < 2; j++) {
			int stevilo = 0;
			scanf("%d", &stevilo);
			tabela[i][j] = stevilo;
		}
	}

	int visina = visinaDrevesa(tabela, 0, 0) - 1;
	printf("%d\n", visina);
	return 0;
}