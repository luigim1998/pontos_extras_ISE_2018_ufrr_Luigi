/*Codigo da maquina de cafe*/

#include <at89x52.h>
#define ENTRADA P3_0
#define BOTAOCAFE P3_1
#define BOTAOCHA P3_2
#define VALVULACAFE P2_0
#define VALVULACHA P2_1

void delay_ms(unsigned int time_ms){
	unsigned int i, j;
	for(i = 0; i<time_ms; i++){
		for(j = 0; j<1275; j++);
	}
}

void ligar_valvula(){
	delay_ms(10000);
}

void main(){
	P2 = 0;
	P3 = 0;
	while(1){
		if(ENTRADA == 1){ //espera ate que a moeda seja inserida, ou seja, a ENTRADA fica 1
			while(BOTAOCHA == BOTAOCAFE); // esperasse que somente um dos botoes sejam apertados, entao um os estados dos dois ficam diferentes
			if(BOTAOCHA == 1){ //se o botao do cha for apertado ele liga a valvula por um tempo e depois desliga junto com o botao
				VALVULACHA = 1;
				ligar_valvula();
				BOTAOCHA = 0;
				VALVULACHA = 0;
			} else { //se o botao do cafe for apertado ele liga a valvula por um tempo e depois desliga junto com o botao
				VALVULACAFE = 1;
				ligar_valvula();
				BOTAOCAFE = 0;
				VALVULACAFE = 0;
			}
			ENTRADA = 0; //ele zera a entrada para esperar uma nova moeda
		}
	}
}