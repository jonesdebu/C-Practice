#include <stdio.h> //includes printf

float celsius2F(float celsius)
{
	return celsius * 9 / 5 + 32;
}

float celsius2K(float celsius)
{
	return celsius + 273.15f;
}

int main()
{
	float celsius = 0;

	while (celsius < 100)
	{
		celsius = celsius + 10;

		printf("%.2f C = %.2f F = %.2f K \n", 
			celsius, 
			celsius2F(celsius), 
			celsius2K(celsius));
	}	
}