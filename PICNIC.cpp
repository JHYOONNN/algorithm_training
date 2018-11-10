#include<stdio.h>


int main() {
	int all, H, W;
	char P[100][100];

	scanf("%d", &all);
	scanf("%d %d", &H, &W);
	
	for (int i = 0; i < all; i++) {
		for (int j = 0; j < H; j++) {
				scanf("%s", P[j]);
		}
	}
}