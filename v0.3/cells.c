/*
  ver : 0.3
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
		printf("'h' to left\n'k' to up\n'l' to right\n'j' to down\n'q' to quit\n");
		for (int i=0;i<3;i++){
			putchar('\n');
			for (int j=0;j<3;j++){
				printf("[ %c ]",grd[i][j]);
			}
		}
		printf("\n Enter command : ");
		hareket=move();


		//left
		if (hareket==0){
			if (player.x<0){
				player.x=player.x+1;
				//grd[player.y][player.x+1]=' ';
				grd[player.y][player.x]=player.krk;
			}
			player.x--;
			grd[player.y][player.x+1]=' ';
		}

		//down
		if (hareket==1){
			if (player.y>2){
				player.y=player.y-1;
				//grd[player.y+1][player.x]=' ';
				grd[player.y][player.x]=player.krk;
			}
			player.y++;
			grd[player.y-1][player.x]=' ';
		}

		//up
		if (hareket==2){
			if (player.y<0){
				player.y=player.y+1;
				//grd[player.y+1][player.x]=' ';
				grd[player.y][player.x]=player.krk;
			}
			player.y--;
			grd[player.y+1][player.x]=' ';
		}

		//right
		if (hareket==3){
			if (player.x>2){
				player.x=player.x-1;
				//grd[player.y][player.x-1]=' ';
				grd[player.y][player.x]=player.krk;
			}
			player.x++;
			grd[player.y][player.x-1]=' ';
		}
		
		//quit program
		if (hareket==4){
			printf("\n[*] You leaving program!\n");
			break;
		}
		
		else 
			;
		grd[player.y][player.x]=player.krk;
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
		case 'q':
			yon=4;
			break;
		default :
			yon=5;
	}
	return yon;
}
