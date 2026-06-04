#include <stdio.h>

#define MAX_DEGREE 20

typedef struct {
    int coeff[MAX_DEGREE + 1];
} Polynomial;

/*
============================================================
QUESTION 10. POLYNOMIAL STRUCTURE
Points: 4

Define a Polynomial type that represents a polynomial with integer
coefficients and degree at most MAX_DEGREE.

For example:
2x^3 - 7x + 1

can be represented by storing coefficients by exponent:
coeff[3] = 2
coeff[1] = -7
coeff[0] = 1

Requirements:
- Use the Polynomial structure declared at the top of this file.
- Create Polynomial *init_poly(Polynomial *p, int coeff, unsigned exp).
  It initializes p as one monomial. Return NULL if exp > MAX_DEGREE.
- Create int coeff_at(const Polynomial *p, unsigned exp).
- Create unsigned degree(const Polynomial *p).
- Create Polynomial *sum(Polynomial *p1, const Polynomial *p2).
- Create Polynomial *prod(Polynomial *p1, const Polynomial *p2).
  If the product degree exceeds MAX_DEGREE, return NULL and do not modify p1.
- Create void print_poly(const Polynomial *p).

Printing rules:
- Print the null polynomial as 0.
- Print each non-zero term as signed coefficient followed by x and exponent.
- Print terms from lowest exponent to highest exponent.

Example:
Polynomial p1 = -2x1
Polynomial p2 = +1x3

After sum:
-2x1+1x3

After product:
-2x4+1x6
============================================================
*/

Polynomial *init_poly(Polynomial *p, int coeff, unsigned exp) {
    if (exp>MAX_DEGREE){
        return NULL;
    }

    for (int i=0; i<MAX_DEGREE+1; i++){
        p->coeff[i]=0;
    }

    p->coeff[exp]=coeff;
    return p;
}

int coeff_at(const Polynomial *p, unsigned exp) {
    if (exp>MAX_DEGREE){
        return 0;
    }
    return p->coeff[exp];
}

unsigned degree(const Polynomial *p) {
    unsigned degree=0;
    for (int exp=0; exp<MAX_DEGREE+1; exp++){
        if ((p->coeff[exp]!=0) && (exp>degree)){
            degree=exp;
        }
    }
    return degree;
}

Polynomial *sum(Polynomial *p1, const Polynomial *p2) {
    for (int i=0; i<MAX_DEGREE+1; i++){
        p1->coeff[i] = p1->coeff[i] + p2->coeff[i];
    }
    return p1;
}

Polynomial *prod(Polynomial *p1, const Polynomial *p2) {
    if (degree(p1)+degree(p2)>MAX_DEGREE){
        return NULL;
    }
    
    Polynomial result;

    for (int i=0; i<MAX_DEGREE+1; i++){
        result.coeff[i]=0;
    }

    for (int i=0; i<MAX_DEGREE+1; i++){
        for (int j=0; j<MAX_DEGREE+1; j++){
            if (i + j <= MAX_DEGREE){
                result.coeff[i+j] += coeff_at(p1, i)*coeff_at(p2, j);
            }
        }
    }

    for (int i=0; i<MAX_DEGREE+1; i++){
        p1->coeff[i]=result.coeff[i];
    }

    return p1;
}

void print_poly(const Polynomial *p) {
    int is_null=1;

    for (int i=0; i<MAX_DEGREE+1; i++){
        if (p->coeff[i]!=0){
            if (p->coeff[i]>0){
                printf("+%dx%d", p->coeff[i], i);
            }
            else{
                printf("%dx%d", p->coeff[i], i);
            }
            is_null=0;
        }
    }

    if (is_null){
        printf("0");
    }
}

int main(void) {
    Polynomial p1;
    Polynomial *pt1;
    pt1 = init_poly(&p1, -2, 1);
    
    print_poly(pt1);
    printf("\n");

    Polynomial p2;
    Polynomial *pt2;
    pt2 = init_poly(&p2, 1, 3);

    print_poly(pt2);
    printf("\n");

    sum(&p1, &p2);
    print_poly(pt1);
    printf("\n");

    prod(&p1, &p2);
    print_poly(pt1);
    // printf("%d %u", coeff_at(&p1, 1), degree(&p2));

    return 0;
}
