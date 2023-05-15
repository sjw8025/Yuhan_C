#include <stdio.h>
#include <stdlib.h>

int game_main_screen() {
	char main_screen[20][50];
	char name[10] = "jump&rush";
	char go_game[10] = "[1.Start]";
	char how_game[9] = "[2.Help]";
	char Ex[9] = "[3.Exit]";
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 50; x++) {
			if (y == 0 || y == 19)
				main_screen[y][x] = '-';
			else if (x == 0 || x == 48)
				main_screen[y][x] = '!';
			else
				main_screen[y][x] = ' ';
		}
		main_screen[y][49] = '\n';
	}
	for (int a = 0; a <= 8; a++)
		main_screen[7][a + 20] = name[a];
	for (int a = 0; a <= 8; a++)
		main_screen[11][a + 20] = go_game[a];
	for (int a = 0; a <= 7; a++)
		main_screen[12][a + 20] = how_game[a];
	for (int a = 0; a <= 7; a++)
		main_screen[13][a + 20] = Ex[a];

	main_screen[19][49] = '\0';
	printf("%s\n", main_screen);
	return 0;
}
int game_help_screen() {
	char main_screen[20][50];
	char first[27] = "Press WASD to move forward";
	char second[27] = "and backward to both side.";
	char third[28] = "Press the space bar to jump";
	char last[36] = "Return to Main Screen?(1.yes/2. no)";
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 50; x++) {
			if (y == 0 || y== 19)
				main_screen[y][x] = '-';
			else if (x == 0 || x == 48)
				main_screen[y][x] = '!';
			else
				main_screen[y][x] = ' ';
		}
		main_screen[y][49] = '\n';
	}
	for (int a = 0; a <= 25; a++)
		main_screen[8][a + 10] = first[a];
	for (int a = 0; a <= 25; a++)
		main_screen[9][a + 10] = second[a];
	for (int a = 0; a <= 26; a++)
		main_screen[10][a + 10] = third[a];
	for (int a = 0; a <= 34; a++)
		main_screen[15][a + 7] = last[a];
	main_screen[19][49] = '\0';
	printf("%s\n", main_screen);
	return 0;
}
int game_exit_screen() {
	char main_screen[20][50];
	char ex[19] = "Are You Sure Exit?";
	char choose[15] = "(1. Yes/2. No)";
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 50; x++) {
			if (y == 0 || y == 19)
				main_screen[y][x] = '-';
			else if (x == 0 || x == 48)
				main_screen[y][x] = '!';
			else
				main_screen[y][x] = ' ';
		}
		main_screen[y][49] = '\n';
	}
	for (int a = 0; a < 18; a++) {
		main_screen[9][a + 15] = ex[a];
	}
	for (int a = 0; a < 14; a++) {
		main_screen[10][a + 17] = choose[a];
	}
	main_screen[19][49] = '\0';
	printf("%s\n", main_screen);
	return 0;
}

int main()
{

	int playing = 1;
	while (playing)
	{

		if (playing == 1)
		{
			system("cls");
			game_main_screen();
			printf("input>");
			scanf("%d", &playing);
		}
		else if (playing == 2)
		{
			system("cls");
			game_help_screen();
			printf("input>");
			scanf("%d", &playing);
			if (playing == 1)
			{
				system("cls");
				playing = 1;
			}
			else if (playing == 2)
			{
				system("cls");
				playing = 2;
			}
			else
			{
				system("cls");
				playing = 2;
			}
		}
		else if (playing == 3)
		{
			system("cls");
			game_exit_screen();
			printf("input>");
			scanf("%d", &playing);
			if (playing == 1)
			{
				system("cls");
				playing = 0;
			}
			else if (playing == 2)
			{
				system("cls");
				playing = 1;
			}
			else 
			{
				system("cls");
				playing = 3;
			}
		}

	}


}