/* ease.c
 * Robert Allen
 * CPSC 275
 * 10/2020
 */

#include <stdio.h>
#define INGOLD 0.618
#define CHARACTERMAX 25
#define WORDMAX 1000

void sort(float A[], char B[][CHARACTERMAX], int n);
int compare(float x, float y);
float findRatioDiff(char word[]);

void main() {
	char words[WORDMAX][CHARACTERMAX];
	int i, j, k;
	int row, col = 0;
	char readThis;
	while ((readThis = getchar()) != EOF) {
		if (readThis != '\n') {
			words[row][col] = readThis;
			col++;
		}
		else {
			col = 0;
			row++;
		}
	}
	float percent[row + 1];
	for (k = 0; k < row + 1; k++) {
		percent[k] = findRatioDiff(words[k]);
	}
	sort(percent, words, row + 1);
	printf("Ranking from easiest to hardest: \n");
	int m;
	for (i = 0; i <= row; i++) {
		for (j = 0; j <= CHARACTERMAX; j++) {
			if (words[i][j] == '\0') {
				break;
			}
			printf("%c", words[i][j]);
		}
		printf("\n");
	}
}

				
float findRatioDiff(char word[]) {
	int i;
	float numLetters = 0.0;
	float vowels = 0.0;
	for (i = 0; i < CHARACTERMAX; i++) {
		if (word[i] == '\0') {
			break;
		}
		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
			vowels++;
		}
		numLetters++;
	}
	numLetters--;
	float ratio = (numLetters - vowels) / numLetters;
	float diff = INGOLD - ratio;
	if (diff < 0) {
		diff = diff * -1;
	}
	return diff;
}
		
int compare(float x, float y) {
	if ((x - y) > 0) {
		return 1;
	}
	return 0;
}

void sort(float A[], char B[][CHARACTERMAX], int n) {
	float key;
	char holder[CHARACTERMAX];
	int i, j, k, l, m;
	for (j = 1; j < n; j++) {
		key = A[j];
		for (i = 0; i < CHARACTERMAX; i++) {
			holder[i] = B[j][i];
		}
		k = j-1;
		while ((k >= 0) && (compare(A[k], key) == 1)) {
			A[k + 1] = A[k];
			for (l = 0; l < CHARACTERMAX; l++) {
				B[k + 1][l] = B[k][l];
			}
			k = k - 1;
		}
		A[k + 1] = key;
		for (m = 0; m < CHARACTERMAX; m++) {
			B[k + 1][m] = holder[m];
		}
	}
}
