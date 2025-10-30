#include <stdio.h>
#include <math.h>
double sqrt(double n) {
    if (n == 0) {
        return 0.0;
    }

    double guess = n / 2.0;
    double temp_guess = 0.0;
    double Epiclon = 1e-6;
    while (1) {
        temp_guess = (guess + (n / guess)) / 2.0;
        if (temp_guess == guess || fabs(temp_guess-guess) < Epiclon ) {
            break;
        }
        guess = temp_guess;
    }

    return guess;
}

int main() {
    double number;
    printf("Enter the number of which you want to find square root: ");
    scanf("%lf",&number);

    if (number >= 0.0) {
        double result = sqrt(number);
        printf("The square root of %g is %g\n", number, result);
    } else {
        printf("Invalid input: Cannot calculate the square root of a negative number.\n");
    }
    
    return 0;
}