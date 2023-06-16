/*
ќбчислити та вивести значенн€ функц≥й.

«наченн€ m обираЇтьс€ ≥з множини [-5, 5] ≥з кроком 0,5; a = 3; 
значенн€ b обираЇтьс€ ≥з множини [-3, 3] ≥з кроком 1; 
c Ц ≥з множини [0, 50] ≥з кроком 10.
«наченн€ зм≥нних (x) задаЇ користувач з клав≥атури.
*/

#include <iostream>
#include <cstdlib> // needed for rand() function
#include <ctime>
#include <cmath>

using namespace std;

/* CONSTANTS */
const int a = 3;

// Generates random number in specified range.
// Third parameter is a step. Default value is 1.
float generateNumberInRange(int start, int end, float step = 1.0)
{
	int numberOfSteps;
	srand(time(0)); // seed for rand() function

	// checking if the start value is bigger than the end.
	// if true, swapping their values.
	if (start > end)
	{
		swap(start, end);
	}

	// calculating the number of steps:
	numberOfSteps = (end - start) / step + 1;

	// calculating and returning number in specified range:
	return start + rand() % numberOfSteps * step;
	
}

double tFunction(float x, float b, float c)
{
	double result;
	if (b > 0)
	{
		result = a * sin(x - 3);
	}
	else if (b < 0 && c < 20)
	{
		if ((pow(b, 2) + c - 4) == 0)
		{
			cout << "Error: division by 0 is happening in 't' function.\n";
			cin.get();

			exit(0); // exiting from program
		}
		// checking log() argument. It can't be equal 0, otherwise - returning error
		else if (pow(c + b, 2))
		{
			result = log(pow(c + b, 2)) / (pow(b, 2) + c - 4);
		}
		else
		{
			cout << "Error: log() argument is equal to 0.\n";
			cin.get();

			exit(0); // exiting from program
		}
	}
	else
	{
		cout << "'t' function doesn't have any solutions\n";
		cin.get();

		exit(0); // exiting from program
	}

	return result;
}

double rFunction(float x, double t, float b, float m)
{
	double result;
	if (m < 0)
	{
		// checking for -nan(ind) value
		if (isnan(pow(b, -t * x)))
		{
			cout << "Error: taking the square root of a negative number.\n"
				 << "Occured in 'r' function.\n";
			cin.get();

			exit(0); // exiting from program
		}
		else
		{
			result = 2.35 * pow(t, 2) + pow(b, -t * x) - pow(a, 2);
		}
	}
	else if (m == 0)
	{
		cout << "Error: division by 0 is happening in 'tg(b/2m)' in 'r' function.\n";
		cin.get();

		exit(0); // exiting from program
	}
	else
	{
		result = b * tan(b / (2 * m));
	}

	return result;
}

int main()
{
	float b, c, m, x;
	double t;
	
	// generating numbers (b, c, m)
	b = generateNumberInRange(-3, 3);
	c = generateNumberInRange(0, 50, 10);
	m = generateNumberInRange(-5, 5, 0.5);

	cout << "a: " << a << '\n';
	cout << "m: " << m << '\n';
	cout << "b: " << b << '\n';
	cout << "c: " << c << '\n';
	
	// getting input from user
	cout << "Enter x: ";
	cin >> x;

	/* "t" FUNCTION */
	t = tFunction(x, b, c);

	// output of 't' function
	cout << "t : " << t << '\n';

	/* "r" FUNCTION */

	// output of 'r' function
	cout << "r : " << rFunction(x, t, b, m) << '\n';
}
