#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>  
#include <windows.h>

#define WIDTH 30
#define HEIGHT 15

void loadingAnimation() {
    int i;
    for (i = 0; i < 2; i++) {
        printf("Loading");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        system("cls");
    }
}

int GameclearBuffer(char* screenBuf, int width, int height)
{
    int i = 0;
    int j = 0;
    while (j < height)
    {
        while (i < width + 1)
        {
            if (i == width)
                screenBuf[i + (j * (width + 1))] = '\n';
            else
            {
                if (i == 0 ||i == (width - 1) || j == 0 || j == (height - 1))
                    screenBuf[i + (j * (width + 1))] = '*';
                else if(i == 1 || i == (width-2))
                    screenBuf[i + (j * (width + 1))] = '|';
                else
                    screenBuf[i + (j * (width + 1))] = ' ';
            }
            i = i + 1;
        }
        i = 0;
        j = j + 1;
    }
    screenBuf[height * (width + 1) - 1] = '\0';
}

int writeStringToBuffer(const char* string, char* screenBuf, int width, int x, int y)
{
    int i = 0;  // 문자열 인덱스

    while (string[i] != '\0')
    {
        // 현재 위치 계산
        int position = x + (y * (width + 1));

        // 개행 문자('\n') 처리
        if (string[i] == '\n')
        {
            x = 0;    // x 좌표 초기화
            y = y + 1;  // y 좌표 증가
        }
        else	
        {
            // 현재 위치에 문자 쓰기
            screenBuf[position] = string[i];
            x = x + 1;  // x 좌표 증가
        }

        i = i + 1;  // 다음 문자로 이동
    }

}
#define MAX_OBSTACLES 5

// 장애물 구조체 정의
typedef struct {
    int x;      // x 좌표
    int y;      // y 좌표
    int speed;  // 속도
} Obstacle;

int startGame(char* screenBuf, int width, int height)
{
    // 장애물 배열 선언
    Obstacle obstacles[MAX_OBSTACLES];

    GameclearBuffer(screenBuf, width, height);

    int centerX = width / 2;
    int centerY = height / 2;

    // 캐릭터 초기 위치
    int characterX = centerX;
    int characterY = centerY + 6;

    // 장애물 초기화
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].x = rand() % (width - 2) + 1;
        obstacles[i].y = 0;
        obstacles[i].speed = 1;
    }

    while (1) {
        // 화면을 그립니다.
        system("cls");
        GameclearBuffer(screenBuf, width, height);

        // 장애물을 화면에 그립니다.
        for (int i = 0; i < MAX_OBSTACLES; i++) {
            screenBuf[obstacles[i].x + obstacles[i].y * (width + 1)] = 'C';
        }

        // 캐릭터를 화면에 그립니다.
        screenBuf[characterX + characterY * (width + 1)] = 'S';

        printf("%s\n", screenBuf);

        // 장애물 위치 업데이트
        for (int i = 0; i < MAX_OBSTACLES; i++) {
            obstacles[i].y += obstacles[i].speed;

            // 장애물이 화면을 벗어나면 재생성
            if (obstacles[i].y >= height) {
                obstacles[i].x = rand() % (width - 2) + 1;
                obstacles[i].y = 0;
            }

            // 충돌 감지
            if (obstacles[i].x == characterX && obstacles[i].y == characterY) {
                printf("Game Over!\n");
                return 0;
            }
        }

        // 일정한 시간 딜레이
        Sleep(50);  // Windows에서는 Sleep 함수 사용

        // 키 입력 처리
        if (_kbhit()) {
            char key = _getch();  // 키 입력을 받습니다.

            // 이동 방향 결정
            int dx = 0, dy = 0;
            switch (key) {
                case 'a':  // 왼쪽으로 이동
                    dx = -1;
                    break;
                case 'd':  // 오른쪽으로 이동
                    dx = 1;
                    break;
                return 0;
            }

            // 캐릭터 위치 업데이트
            int newCharacterX = characterX + dx;
            int newCharacterY = characterY + dy;

            // 캐릭터가 화면을 벗어나지 않는지 체크
            if (newCharacterX >= 0 && newCharacterX < width && newCharacterY >= 0 && newCharacterY < height) {
                characterX = newCharacterX;
                characterY = newCharacterY;
            }
        }
    }
}

int clearBuffer(char* screenBuf, int width, int height)
{
    int i = 0;
    int j = 0;
    while (j < height)
    {
        while (i < width + 1)
        {
            if (i == width)
                screenBuf[i + (j * (width + 1))] = '\n';
            else
            {
                if (i == 0 ||i == (width - 1) || j == 0 || j == (height - 1))
                    screenBuf[i + (j * (width + 1))] = '#';
                else
                    screenBuf[i + (j * (width + 1))] = ' ';
            }
            i = i + 1;
        }
        i = 0;
        j = j + 1;
    }
    screenBuf[height * (width + 1) - 1] = '\0';
}

int setTitleToScreenBuffer(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf, width, height);

    int centerX = width / 2;
    int centerY = height / 2;

    writeStringToBuffer("Avoid Meteor", screenBuf, width, centerX - 6, centerY - 2);
    writeStringToBuffer("1. Start", screenBuf, width, 11 , centerY);
    writeStringToBuffer("2. Menu", screenBuf, width, centerX - 4, centerY + 2);
    writeStringToBuffer("3. exit", screenBuf, width, centerX - 4, centerY + 4);

	printf("%s\n", screenBuf);
}

int setgamemenuToscreenBuffer(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf, width, height);

    int centerX = width / 2;
    int centerY = height / 2;

    writeStringToBuffer("escape dutch!", screenBuf, width, centerX - 9, centerY - 2);
    writeStringToBuffer("a,d = left,right", screenBuf, width, centerX - 9, centerY );
    writeStringToBuffer("press 1 go to menu", screenBuf, width, centerX - 9, centerY + 2 );

	printf("%s\n", screenBuf);
}

int setgameexitToscreenBuffer(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf, width, height);

    int centerX = width / 2;
    int centerY = height / 2;

    writeStringToBuffer("game exit?", screenBuf, width, centerX -5, centerY -2);
    writeStringToBuffer("1. yes", screenBuf, width, centerX - 4, centerY + 1);
    writeStringToBuffer("2. no", screenBuf, width, centerX - 4, centerY + 3);

	printf("%s\n", screenBuf);
}

int main()
{
    char screenBuf[465]; //가로30*세로15+개행문자15
    clearBuffer(screenBuf, 30, 15);
    srand(time(NULL));  // 난수 시드 초기화

    char GamescreenBuf[(WIDTH + 1) * HEIGHT];  // 화면 버퍼 크기 조정

    int playing = 0;
    setTitleToScreenBuffer(screenBuf, 30, 15);
    scanf("%d", &playing);

    while (playing)
    {
 
        if (playing == 1)
        {
            system("cls");
            loadingAnimation();
            startGame(screenBuf, WIDTH, HEIGHT);
            printf("To Main_Title press 1\n",screenBuf);
            scanf("%d", &playing);
            if (playing == 1)
            {
                setTitleToScreenBuffer(screenBuf, 30, 15);
                scanf("%d", &playing);
            }
        }
        else if (playing == 2)
        {
            setgamemenuToscreenBuffer(screenBuf, 30, 15);
            scanf("%d", &playing);
            if (playing == 1)
            {
                setTitleToScreenBuffer(screenBuf, 30, 15);
                scanf("%d", &playing);
            }
        }
        else if (playing == 3)
        {
            setgameexitToscreenBuffer(screenBuf, 30, 15);
            scanf("%d", &playing);
            if (playing == 1)
            {
                playing = 0;
            }
            else
            {
                setTitleToScreenBuffer(screenBuf, 30, 15);
                scanf("%d", &playing);
            }
        }
    }

    return 0;
}
