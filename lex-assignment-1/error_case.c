 #include<stdio.h>
char WT_CHK(float wt2, float min, float max) {
if (wt2 > max || wt2 < min) return ‘F’;
else return ‘T’;
 }

/* This is the driver function. */
 int main() {
 float max=100, min=10;
 /* Checks the range. */
printf(“Wt is in range: %c”, WT_CHK(67, min, max));
}