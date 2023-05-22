#include <stdio.h>
#include <stdlib.h>

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

int setTitleToScreenBuffer(char* screenBuf, int width, int height)
{
    clearBuffer(screenBuf, width, height);

    int centerX = width / 2;
    int centerY = height / 2;

    writeStringToBuffer("Rush&dash", screenBuf, width, centerX - 5, centerY - 2);
    writeStringToBuffer("1. Start", screenBuf, width, centerX - 5, centerY);
    writeStringToBuffer("2. Menu", screenBuf, width, centerX - 4, centerY + 2);
    writeStringToBuffer("3. exit", screenBuf, width, centerX - 4, centerY + 4);

	printf("%s\n", screenBuf);
}

int setgamemenuToscreenBuffer(char* screenBuf, int width, int height)
{
    clearBuffer(screenBuf, width, height);

    int centerX = width / 2;
    int centerY = height / 2;

    writeStringToBuffer("1. wasd = move", screenBuf, width, centerX - 9, centerY);
    writeStringToBuffer("2. spacebar = jump", screenBuf, width, centerX - 9, centerY + 2);
    writeStringToBuffer("3. escape dutch!", screenBuf, width, centerX - 9, centerY + 4);

	printf("%s\n", screenBuf);
}

int setgameexitToscreenBuffer(char* screenBuf, int width, int height)
{
    clearBuffer(screenBuf, width, height);

    int centerX = width / 2;
    int centerY = height / 2;

    writeStringToBuffer("game exit?", screenBuf, width, centerX -5, centerY);
    writeStringToBuffer("1. yes", screenBuf, width, centerX - 4, centerY + 2);
    writeStringToBuffer("2. no", screenBuf, width, centerX - 4, centerY + 4);

	printf("%s\n", screenBuf);
}

int main()
{
    char screenBuf[465]; //가로30*세로15+개행문자15
    clearBuffer(screenBuf, 30, 15);

    int playing = 1;
    while (playing)
    {
 
        if (playing == 1)
        {
            system("cls");
            setTitleToScreenBuffer(screenBuf, 30, 15);
            scanf("%d", &playing);
        }
        else if (playing == 2)
        {
            system("cls");
            setgamemenuToscreenBuffer(screenBuf, 30, 15);
            scanf("%d", &playing);
            if (playing == 1)
            {
                // 게임 시작
            }
        }
        else if (playing == 3)
        {
            system("cls");
            setgameexitToscreenBuffer(screenBuf, 30, 15);
            scanf("%d", &playing);
            if (playing == 1)
            {
                playing = 0;
            }
        }
    }

    return 0;
}