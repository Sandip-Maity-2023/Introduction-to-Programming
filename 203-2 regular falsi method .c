//
// Created by 12san on 10-09-2024.
//
#include<stdio.h>
#include<math.h>

// Function definition
float f(float x){
    return (x*x*x - 2*x - 5);
}

int main(){
    float a, b, err, fa, fb, fc, c, c0;
    int itr = 0;

    // Input for a, b, and error tolerance
    printf("Enter the value of a, b & error tolerance:\n");
    scanf("%f %f %f", &a, &b, &err);

    // Check if f(a) and f(b) have opposite signs
    if(f(a) * f(b) > 0){
        printf("Invalid values: a and b should have opposite signs.\n");
        return 0;
    }

    c0 = a;

    // Regular Falsi Method
    do {
        fa = f(a);
        fb = f(b);
        c = a - fa * (b - a) / (fb - fa);  // New approximation
        fc = f(c);

        if(fabs(c - c0) < err){  // Convergence check
            printf("\nThe root is approximately %f\n", c);
            return 0;
        }

        if(fc == 0){
            printf("\n%f is exactly the root\n", c);
            return 0;
        }

        // Update intervals based on the sign of fc
        if(fa * fc < 0){
            b = c;
        } else {
            a = c;
        }

        c0 = c;  // Store the last value of c
        itr++;

    } while(fabs(c - c0) >= err);

    printf("\nThe root is approximately %f after %d iterations.\n", c, itr);

    return 0;
}