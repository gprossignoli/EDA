#include <math.h>
#include <iostream>
#include "bintree_eda.h"

int recursion(bintree<int> const& tree, int & nPadres, int & BuenosPadres, int altura, bool & esEquilibrado) {
	if (tree.empty()) {
		return altura - 1;
	}

	else {
		if(!tree.left().empty() && !tree.right().empty())
			++nPadres;
		const int factorEquilibrio = abs(recursion(tree.left(), nPadres, BuenosPadres, altura + 1, esEquilibrado) - recursion(tree.right(), nPadres, BuenosPadres, altura + 1, esEquilibrado));
		if (factorEquilibrio == 0 || factorEquilibrio == 1)
			esEquilibrado = true;
		else
			esEquilibrado = false;
	}
	if (esEquilibrado && !tree.left().empty() && !tree.right().empty())
		++BuenosPadres;

	return altura;
}

int hacerCosasDePadres(bintree<int> const& tree) {
	if (tree.empty())
		return 100;
	int nPadres = 0;
	int BuenosPadres = 0;
	bool esEquilibrado = false;
	recursion(tree, nPadres, BuenosPadres, 0, esEquilibrado);
	int porcentajeBuenosPadres = (BuenosPadres * 100) / nPadres;
	return porcentajeBuenosPadres;
}

int main() {
	bintree<int> aux;
	aux = leerArbol(-1);
	
	int sol = hacerCosasDePadres(aux);

	return 0;
}