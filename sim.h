#ifndef _SIM_H_
#define _SIM_H_

struct resultado{
	int indice;
	int rotulo;
};

struct cache{
	int associatividade; //mapeamento direto
	int numBytes; //numero de bytes por bloco 
	int numBlocos; //numero de bloco por conjunto
};

struct resultado exec(int endereco, struct cache entrada);

#endif // _SIM_H_
