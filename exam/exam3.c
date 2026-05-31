#include <stdio.h>
#include <string.h>

#define MAXDEGREE 20
#define MAXL 200

/*
 Define the following types and functions (function prototypes are given).
 
 Polynomial
 Represents a one-variable polynomial with integer coefficients, e.g.:
 1x^3 + 2x^1 + 3x^0 (more simply, 1x^3 + 2x + 3)

 The polynomial degree (the polynomial's variable's max exponent) must not exceed
 the symbolic constant defined above.

 (The other symbolic constant is defined for convenience and because it is
 used in the main: it denotes the maximum length of a string representing a polynomial 
 No check is necessary about this bound).
*/


/*
initPoly (re-)initializes a given Polynomial, passed through a pointer so that it represents
an elementary polynomial composed of one term (i.e., a monomial), defined by a coefficient and an exponent.
"Overwrites" the passed Polynomial.
If the initialization succeeds, i.e., the exponent doesn't exceed MAXDEGREE, it returns the pointer to the Polynomial.
Otherwise, it returns NULL.
*/
typedef struct{
  int coeff[MAXDEGREE+1];
} Polynomial;

Polynomial * initPoly(Polynomial * p, int coeff, unsigned int exp){
  if (exp>MAXDEGREE){
    return NULL;
  }

  for (int i=0; i<=MAXDEGREE; i++){
    p->coeff[i]=0;
  }

  p->coeff[exp]=coeff;
  return p;
}

/*
printPoly puts in the specified array a string describing a given polynomial,
passed through a pointer (the array holding the string is assumed large enough).
Below are some examples of Polynomial descriptions: the values preceding and following the 'x' symbol
are the variable's coefficient and exponent, respectively; their explicit representation
(including sign) for each non-null term (including constants, i.e., zero-degree terms) simplifies
the implementation; only the null polynomial has a particular representation ("0")

"0"                 (null polynomial)
"+7x0"              (the constant, i.e., zero-degree polynomial, 7)
"+1x1"              (one-degree polynomial)
"-7x1"              (one-degree polynomial)
"-2x3+1x1+1x0"      (three-degree polynomial)
"+2x3-7x1-1x0"      (three-degree polynomial)

Suggestion: the library functions below may be helpful
strcat  (concatenates two strings: the 2nd string passed to the function at the end of the 1st one)
sprintf (works exactly as printf but puts the output on the array passed as an extra 1st argument), e.g.,
the following snippet writes "145" in array s instead of printing 145 on the standard output
int y = 145;
char s[10];
sprintf(s, "%d", y);
*/
void printPoly(const Polynomial * p, char s[]){
  char temp[30];
  int is_zero=1;

  s[0]='\0';

  for (int i=0; i<=MAXDEGREE; i++){
    if (p->coeff[i]!=0){
      sprintf(temp, "%+dx%d", p->coeff[i], i);
      strcat(s, temp);
      is_zero=0;
    }
  }

  if (is_zero==1){
    strcpy(s, "0");
  }
}


/*
coeff returns the coefficient of the polynomial's term with the specified degree
(returns 0 if exp is bigger than MAXDEGREE).
*/
int coeff(const Polynomial * p, unsigned exp){
  if (exp>MAXDEGREE){
    return 0;
  }

  return p->coeff[exp];
}


/*
degree returns the polynomial's degree (the biggest exponent of non-null terms)
*/
unsigned int degree(const Polynomial * p){
  unsigned degree;

  for (int i=0; i<=MAXDEGREE; i++){
    if (p->coeff[i]!=0){
      degree = i;
    }
  }

  return degree;
}


/*
sum makes the sum between polynomials by putting the result in the 1st argument,
which is "overwritten" . 
Returns the pointer to the 1st polynomial.
*/
Polynomial * sum(Polynomial * p1, const Polynomial * p2){
  for (int i=0; i<=MAXDEGREE; i++){
    p1->coeff[i] += p2->coeff[i];
  }
  return p1;
}


/*
prod makes the product between polynomials by putting the result in the 1st argument,
which is "overwritten".
Returns the pointer to the 1st polynomial, NULL, if the sum of polynomials' degrees
exceeds MAXDEGREE (in that case, it does nothing).
*/
Polynomial * prod(Polynomial * p1, const Polynomial * p2){
  if (degree(p1)*degree(p2)>MAXDEGREE){
    return NULL;
  }

  Polynomial result;

  for (int i=0; i<=MAXDEGREE; i++){
    result.coeff[i] = 0;
  }

  for (int i=0; i<=MAXDEGREE; i++){
    for (int j=0; j<=MAXDEGREE; j++){
      if (i+j<=MAXDEGREE){
        result.coeff[i+j] += coeff(p1, i) * coeff(p2, j);
      }
    }
  }

  for (int i=0; i<=MAXDEGREE; i++){
    p1->coeff[i] = result.coeff[i];
  }

  return p1;
} 

/*
main performs some tests of the functions: please comment on the parts not yet implemented
*/
int main() {
  Polynomial p1, p2, p3;
  Polynomial * pt1, * pt2, * pt3; 
  char sp1[MAXL+1], sp2[MAXL+1], sp3[MAXL+1];
  int c;
  unsigned int e;
  
  pt1 = initPoly(&p1, 1, MAXDEGREE + 1);
  if (pt1 != NULL) {
    printf("%s\n", "Error: should return NULL");
  }

  pt1 = initPoly(&p1, -2, 1); //p1 is -2x
  if (pt1 != &p1) {
    printf("%s\n", "Error: the returned pointer should coincide with the passed one");
  }

  printPoly(pt1, sp1);
  printf("p1 is: %s\n", sp1); //for debugging
  if (strcmp(sp1, "-2x1") != 0 ) {
    printf("Error: p1 should be %s instead is %s\n", "-2x1", sp1);
  }
  
  c = coeff(pt1, 1);
  if (c != -2) {
    printf("Error: the coeff of term with esp 1 should be %d instead is %d\n", -2, c);
  }

  c = coeff(pt1, 2);
  if (c != 0) {
    printf("Error: the coeff of term with esp 2 should be %d instead is %d\n", 0, c);
  }

  e = degree(pt1);
  if (e != 1) {
    printf("Error: the degree of of p1 should be %u instead is %u\n",1, e);
  }

  pt2 = initPoly(&p2, 1, 3); //p2 is 1x3
  printPoly(pt2, sp2);
  printf("p2 is: %s\n", sp2); //for debugging
  if (strcmp(sp2, "+1x3") != 0 ) {
    printf("Error: p2 should be %s instead is %s\n", "+1x3", sp2);
  }
  
  
  pt1 = sum(pt1, pt2); // p1 is -2x1+1x3 
  printPoly(pt1, sp1);
  printf("p1 + p2 is: %s\n", sp1); //for debugging
  if (strcmp(sp1, "-2x1+1x3") != 0 ) {
    printf("Error: p1 should be %s instead is %s\n", "-2x1+1x3", sp1);
  }
  
  
  pt2 = prod(pt2, pt1); // p2 is -2x4+1x6
  printPoly(pt2, sp2);
  printf("p2 is: %s\n", sp2); //for debugging
  if (strcmp(sp2, "-2x4+1x6") != 0 ) {
    printf("Error: p2 should be %s instead is %s\n", "-2x4+1x6", sp2);
  }

}

