#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int qtd_sanduiches = 0;
int num_pessoas = 0;

//https://github.com/alura-cursos/maratonaprogramacao/blob/aula4-exc/PAO07.cpp
int busca_tam(int de, int ate, int tam_sanduiches[]) {
    if (de == ate) return de;
    
	int meio = (de + ate + 1)/2;
    if (num_lanches(meio, tam_sanduiches) >= num_pessoas) return busca_tam(meio, ate, tam_sanduiches);
    else return busca_tam(de, meio - 1, tam_sanduiches);
}

int num_lanches (int tam_fatia, int tam_sanduiches[]) {
	int fatias = 0;
	
	int i = 0;
	for (i = 0; i < qtd_sanduiches; i++) {
		fatias += (tam_sanduiches[i] / tam_fatia);
	}
	
	return fatias;
}

int main () {
	
	FILE *fp;
	fp = freopen("input3.txt", "r", stdin);
	
	if (fp != NULL) {
		char buf[10009];
		
		fgets(buf, 10009, fp);
		num_pessoas = strtol(buf, NULL, 10);
		
		fgets(buf, 10009, fp);
		qtd_sanduiches = strtol(buf, NULL, 10);
		
		int tamanhos_sanduiches[qtd_sanduiches];
		
		//printf("pessoas:%d | sanduiches:%d\ntamanhos:", num_pessoas, qtd_sanduiches);
		
		int i = 0;
		char *pEnd;
		fgets(buf, 10009, fp);
		for (i = 0; i < qtd_sanduiches; i++) {
			tamanhos_sanduiches[i] = strtol(buf, &pEnd, 10);
			memcpy(buf, &pEnd[1], strlen(pEnd));
			//printf("%d ", tamanhos_sanduiches[i]);
		}
		//printf("\n");
		
		printf("%d\n", busca_tam(1, 10000, tamanhos_sanduiches));
	}
	
	return (0);
}
