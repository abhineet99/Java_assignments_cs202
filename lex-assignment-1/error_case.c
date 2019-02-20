 #include<stdio.h>
char WT_CHK(float wt2, float min, float max) {
if (wt2 > max || wt2 < min) return ‘F’;
else return ‘T’;
 }

/* This is the driver function. */
 int main() {
 /* Checks the range. */
 float max=100, min_3=10;
 /* Checks the range. */
 
char WT_check();
printf(“Wt is in range: %c”, WT_CHK(67, min, max));
}