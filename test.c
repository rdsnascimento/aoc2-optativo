#include "simplegrade.h"
#include "sim.h"

/* Função auxiliar para imprimir*/
void print(struct resultado res){
	printf("Linha da cache (decimal): %d\n", res.indice);
	printf("Tag (decimal): %d\n\n", res.rotulo);
}

void test(){
	int endereco = 524;
	struct cache entrada1 = {1, 32, 16}; //mapeamento direto, numero de bytes por bloco, numero de bloco por conjunto
	struct resultado res = exec(endereco, entrada1);
	DESCRIBE("Cache com 16 linhas de 32 bytes");
	IF("Questao 1 da Prova - Endereço 524");
	THEN("Espero que a linha seja 0 e a tag 1");
	isEqual(res.indice, 0, 1);
	isEqual(res.rotulo, 1, 1);
	print(res);
	
	endereco = 64;
	struct cache entrada2 = {1, 32, 16}; //mapeamento direto, numero de bytes por bloco, numero de bloco por conjunto
	res = exec(endereco, entrada2);
	IF("Endereço 64");
	THEN("Espero que a linha seja 2 e a tag 0");
	isEqual(res.indice, 2, 1);
	isEqual(res.rotulo, 0, 1);
	print(res);
	
	endereco = 2052;
	struct cache entrada3 = {1, 32, 16}; //mapeamento direto, numero de bytes por bloco, numero de bloco por conjunto
	res = exec(endereco, entrada3);
	IF("Endereço 2052");
	THEN("Espero que a linha seja 0 e a tag 4");
	isEqual(res.indice, 0, 1);
	isEqual(res.rotulo, 4, 1);
	print(res);
}

int main(int argc __attribute__ ((unused)), char ** argv __attribute__ ((unused))){
	DESCRIBE("Simulador");
	test();

	GRADEME();

	if (grade==maxgrade)
		return 0;
	else return grade;

}
