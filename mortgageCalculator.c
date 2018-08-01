#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
	Loan payment = Amount / Discount
	n = number of payments per year, 12
	i = (annual rate/100)/12
	Discount = {[(1 + i)**n] - 1}/[ i(1 + i)**n]
*/

struct UI{
	double amount;
	int n;
	double rate;
};

//protoypes
struct UI *user_input();
double loan(struct UI* input);

int main()
{
	struct UI* input = user_input();
	double payment = loan(input);
	printf("Your monthly payment is: %.2lf\n", payment);
	printf("Your total payoff is: %.2lf\n", payment * 24);	

	if(input != NULL)
		free(input);

	return 0;
}

struct UI* user_input()
{
	struct UI* input = malloc(sizeof(struct UI));

	if(input == NULL)
	{
		fprintf(stderr, "Malloc Failed!");
		return NULL;
	}

	printf("How much do you want to borrow? ");
	scanf("%lf", &input->amount);
	printf("How long is this loan for? ");
	scanf("%d", &input->n);
	printf("What is the interest rate? ");
	scanf("%lf", &input->rate);

	return input;
}

double loan(struct UI *input)
{
	int years = input->n * 12;
	double interest = (input->rate/100.0) / 12.0;

	double top = pow((1 + interest), years) - 1;

	double bottom = (interest*(pow((1+interest), years)));
	
	double discount = top/bottom;
	//printf("discount is %lf\n", discount);
	
	double payment = input->amount / discount;
	//printf("payment = %.2lf\n", payment);

	return payment;
}

