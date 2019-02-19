#include<stdio.h>
/* Checks the weight range. */
char check_range(float wt2, float min, float max) {
if (wt2 > max || wt2 < min) return ‘F’;
else return ‘T’;
}
/* This is the driver function. */
int main() {
/* Max and min weight of the consignment in kg. */
float max=100, min=10;
/* Checks the range. */
printf(“Wt is in range: %c”, check_range(67, min, max));
}