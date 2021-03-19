#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// mapa template
int map0[20][20] = { 
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,2,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,2,1,
1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,
1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,
1,0,1,0,0,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,
1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,
1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,
1,0,0,1,0,0,0,1,0,0,0,1,0,0,2,1,0,1,0,1,
1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,
1,0,0,0,0,1,0,0,0,1,2,0,0,0,0,0,0,0,0,1,
1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,1,0,1,1,1,
1,2,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,2,1,
1,0,0,0,1,0,1,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,
1,0,0,0,1,0,1,0,0,1,0,1,0,1,2,1,0,0,0,1,
1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,1,0,1,
1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
// mapa instancia
int map1[20][20] = { 
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

//Nr de movimentos
int mov = 0;

//Score
int score = 0;

//posicao jogador
int y = 1, x = 18;

//desenho mapa
void drawMap(int m[20][20]){	
	int i,j,k = 0;
	printf("SCORE : %i\n---------------------------------------\n",score);
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(k == 20){
				k=0;
				printf("\n");
			}   //definir icones do jogador, pontos e parede
			if(x == j && y == i){
				printf("O ");
			}else if(m[j][i] == 1){
				printf("# ");
			}else if(m[j][i] == 0){
				printf("  ");
			}else if(m[j][i] == 2){
				printf("@ ");
			}else{
				printf("X ");
			}
			k++;
		}
	}
	printf("\n\n\n");
}
// variaveis matriz
int rtmap(int i, int j, int n){
	int k;
	if(n == 0){
		k = map0[i][j];
	}else if(n == 1){
		k = map1[i][j];
	}
	return k;
}
// cor do mapa e titulo
int main(){
	system("title Maze");
	system("color f5");
	system("cls");
	char key;
	
	// mapa clone 
	int map[20][20];
	int i,j;
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			map[i][j] = rtmap(i, j, 0);
		}
	}	
	
	drawMap(map);
	printf("Aperte ESC para sair!\n");
//definir teclas de movimento	
	while(true){
		key = getch();
		mov++;
		if(y < 0){
			y = 0;
		}else if(y > 19){
			y = 19;
		}
			
		if(x < 0){
			x = 0;
		}else if(x > 19){
			x = 19;
		}
			
		if(key == 119){
			// cima W
			if(y >= 1 && map[x][y - 1] != 1){
				y--;
			}
			if(map[x][y] == 2){
				map[x][y] = 0;
				score++;				
			}
		}else if(key == 115){
			// baixo S
			if(y <= 18 && map[x][y + 1] != 1){
				y++;
			}
			if(map[x][y] == 2){
				map[x][y] = 0;
				score++;
			}
		}else if(key == 97){
			// esquerda A
			if(x >= 1 && map[x - 1][y] != 1){
				x--;
			}
			if(map[x][y] == 2){
				map[x][y] = 0;
				score++;
			}
		}else if(key == 100){
			// direita D
			if(x <= 18 && map[x + 1][y] != 1){
				x++;
			}
			if(map[x][y] == 2){
				map[x][y] = 0;
				score++;
			}
		}else if(key == 27){
			system("cls");
			break;
		}
		//painel de exibiçao final
		if(score == 10){
			system("cls");
			printf("Parabens! Venceu o labirinto!\n");
			printf("Voce teve %i movimentos!\n", mov);
			printf("Aperte qualquer tecla pra continuar!");
			system("pause>nul");
		}
		
		system("cls");
		drawMap(map);
		printf("Aperte ESC para sair!");
	}
	printf("Aperte qualquer tecla para sair!");
	system("pause>nul");
	return 0;
}

