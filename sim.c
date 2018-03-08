#include <stdio.h>
#include "sim.h"

// retorna quantos bits sao necessarios para representar (modulo do numero)
int modulo(int assoc, int num_blocks){
	int div = num_blocks / assoc;
	int mod = 0;
	while(div>1){
		div /= 2;
		mod++;
	}	
	return mod;
}

// retorna indice do endereco
int indiceEnd(int endereco, int modulo){
	int cont=1;
	int mod = modulo;
	for(int i=0; i < mod; i++)	
		cont = cont * 2;
	cont=cont-1;
	return endereco & cont;
}

//retorna o rotulo do endereco
int rotuloEnd(int endereco, int modulo){
	return endereco>>modulo;
}

struct resultado exec(int endereco, struct cache entrada){
	struct resultado result;
	//entrada.associatividade = 1; //mapeamento direto
	//entrada.numBytes = 32; //numero de bytes por bloco 
	//entrada.numBlocos = 16; //numero de bloco por conjunto

	endereco /= 4; //converte endereco para decimal
	int mod = modulo(entrada.associatividade, entrada.numBlocos);
	int qtWordPorBloco = entrada.numBytes/4;
	result.indice = indiceEnd(endereco/qtWordPorBloco, mod);
	result.rotulo = rotuloEnd(endereco/qtWordPorBloco, mod);
	
	return result;
}
