/*
  ver : 0.1
  author : serdar
*/

#include<stdio.h>

int move(void);

char grd[3][3]={
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '}
	};

int main(){
	int hareket;

	struct Player
	{
		char krk;
		int x;
		int y;
	} player = {'#', 0, 0};
	grd[player.y][player.x]=player.krk;

	while(1){
		grd[player.y][player.x]=player.krk;
		hareket=move();
		if (hareket==3){
			if (player.x>2){
				grd[player.y][2]=' ';
				player.x=0;
			}
			player.x++;
			grd[player.y][player.x-1]=' ';
		}
		else 
			;
		for (int i=0;i<3;i++){
			putchar('\n');
			for (int j=0;j<3;j++){
				printf("[ %c ]",grd[i][j]);
			}
		}
		putchar('\n');
	}
	return 0;
}

int move(){
	int yon;
	char c=getchar();
	switch(c){
		case 'h':
			yon=0; /*left*/
			break;
		case 'j':
			yon=1; /*down*/
			break;
		case 'k':
			yon=2; /*up*/
			break;
		case 'l':
			yon=3; /*right*/
			break;
		default :
			yon=5;
	}
	return yon;
