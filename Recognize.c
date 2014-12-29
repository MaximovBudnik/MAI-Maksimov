#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
int mat[1000][1000];
int otvet[100];
int x,y,h,g,k,itv,i,j;

void form();
void recognize();
void verscore();
void otvout();
void present();

int main(int argc, char *argv[]){
	file = fopen(argv[1], "r");
	form();
	recognize();
	verscore();
	otvout();

}

void verscore(){
	int vpr,otv;
	for (vpr=1;vpr<k+1;vpr++){
		for (otv=1;otv<itv+1;otv++){
			if ((mat[((1+g)/2+1)+(1+g)*(vpr-1)][((1+h)/2+1)+(1+h)*(otv-1)]) == 1) otvet[vpr]=otv;
		}
	}
}

void form(){
	char ch[2];
	i = 1;
	y = 1;
	while (!feof(file))
     {
	fgets(ch, 2, file);

		if (ch[0] == '\n')
		{
			y++;
			if (x<i) x=i;
			i=1;
		}
	if (ch[0] == '1' && y>=3)
		{
			mat[y-2][i] = 1;
			i++;
		}
	
	if (ch[0] == '0' && y>=3)
		{
		mat[y-2][i] = 0;
		i++;
		}
	ch[0] = 0;
     }
	y=y-3;
	x=x-1;
     }

void present(int y, int x){
	for (i=1;i<y+1;i++){
		for (j=1;j<x+1;j++){
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
}

void recognize(){
	for (i=1,j=0;j<2;i++){
		if (mat[2][i] == 1) j++;
		if (mat[2][i] == 0) h++;
	}
	for (i=1,j=0;j<2;i++){
		if (mat[i][2] == 1) j++;
		if (mat[i][2] == 0) g++;
	}
	itv=(x-1)/(h+1);
	k=(y-1)/(g+1);
}



void otvout(){
	for (i=1;i<k+1;i++)
		printf("%d\n",otvet[i]);
}


