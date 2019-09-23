#include "data.h"

Data criar_data(int dia, int mes, int ano) //OK
{
	Data data;
	data.dia = dia;
	data.mes = mes;
	data.ano = ano;
	return data;
}

int eh_nula(Data data)
{
	return data.dia == 0 && data.mes == 0 && data.ano == 0;
}

int eh_menor_que(Data data1, Data data2)
{
	if (data1.ano < data2.ano) {
		return 1;
	} else if (data1.ano > data2.ano) {
		return 0;
	} else if (data1.mes < data2.mes) {
		return 1;
	} else if (data1.mes > data2.mes) {
		return 0;	
	} else if (data1.dia < data2.dia) {
		return 1;	
	} else {
		return 0;
	}
}
