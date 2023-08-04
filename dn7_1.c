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

//optimizirano (avgust 2023):
/*int visinaDrevesa(int** drevo, int indeks) {
	if (drevo[indeks][0] == 0 && drevo[indeks][1] == 0) {
		if (indeks == 0) {
			return 1;
		}
	}

	int visinaL = 1;
	if (drevo[indeks][0] != 0) {
		visinaL += visinaDrevesa(drevo, drevo[indeks][0] + indeks);
	}

	int visinaD = 1;
	if (drevo[indeks][1] != 0) {
		visinaD += visinaDrevesa(drevo, drevo[indeks][1] + indeks);
	}
	
	if (visinaL > visinaD) {
		return visinaL;
	} else {
		return visinaD;
	}
}*/

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

	//bi bilo dobro še sprostiti tabelo:
	/*for (int i = 0; i < n; i++) {
		free(drevo[i]);
	}

	free(drevo);*/
	return 0;
}
