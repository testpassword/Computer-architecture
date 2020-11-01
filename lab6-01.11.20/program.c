#include <reg51.h>

#define cDiv (0x10000-10000) / 256;
#define cMod (0x10000-10000) % 256;

void signalHandler() interrupt 0 {
	unsigned int x = (TL1 + (TH1 << 8)) * 2;
	TL1 = 0;
	TH1 = 0;
}

void timeHandler() interrupt 1 {
	TL0 = cMod;
	TH0 = cDiv;
	P3 ^= 0x7F;
}

int main() {
	TR0 = 1; //разрешение счёта
	IT0 = 1; // тип прерывания H/L фронт на входе порта P3
	TMOD = 0x91; //режим 16-бит счётчика TM1, Gate
	TR1 = 1; //разрешение счёта таймера 1
	ET0 = 1; //маска прерывания для таймера 0
	//чтобы разрешить прерывания, устанавливаем бит маски EX0 и бит разрешения прерываний EA раными 1
	EX0 = 1;
	EA = 1;
	while(1); //ожидание прерываний
	return 0;
}