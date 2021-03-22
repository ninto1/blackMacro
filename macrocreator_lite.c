#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#define WINVER 0x0500
#include <windows.h>
char filespec[] = "macro.txt";
char keys[10][6] = {"w", "a", "s", "d", "1", "2", "3", "sneak", "space", "lclick"};
int keycodes[10] = {0x57, 0x41, 0x53, 0x44, 0x31, 0x32, 0x26, 0x10, 0x20, 0x01};
int commands[] = {0};
int randD = 0;
int loop = 0;

int randomizeDelay(int delay)
{

    return (randD - rand() % randD * 2) + delay;
}
int readcommands()
{
    FILE *fPointer;
    char str[MAXCHAR];
    int counter = 0;
    fPointer = fopen(filespec, "r");
    if (fPointer == NULL)
    {
        printf("Could not open file");
    }
    randD = atoi(fgets(str, MAXCHAR, fPointer));
    loop = atoi(fgets(str, MAXCHAR, fPointer));
    int count2 = 0;
    while (fgets(str, MAXCHAR, fPointer) != NULL && count2 < 10)
    {
        count2++;
        // printf("%s", str);                DEBUG
        /*Commands:
        1 = w down
        2 = a d
        3 = s d
        4 = d d
        5 = 1 d
        6 = 2 d
        7 = 3 d
        8 = sneak d
        9 = space d
        10 = w up
        11 = a u
        12 = s u
        13 = d u
        14 = 1 u
        15 = 2 u
        16 = 3 u
        17 = sneak u
        18 = space u
        19 = click d
        20 = click u
        (time)+21 = delay
        */
        if (strcmp(str, "w d\n") == 0)
            commands[counter] = 1;
        else if (strcmp(str, "a d\n") == 0)
            commands[counter] = 2;
        else if (strcmp(str, "s d\n") == 0)
            commands[counter] = 3;
        else if (strcmp(str, "d d\n") == 0)
            commands[counter] = 4;
        else if (strcmp(str, "1 d\n") == 0)
            commands[counter] = 5;
        else if (strcmp(str, "2 d\n") == 0)
            commands[counter] = 6;
        else if (strcmp(str, "3 d\n") == 0)
            commands[counter] = 7;
        else if (strcmp(str, "sneak d\n") == 0)
            commands[counter] = 8;
        else if (strcmp(str, "space d\n") == 0)
            commands[counter] = 9;
        else if (strcmp(str, "w u\n") == 0)
            commands[counter] = 10;
        else if (strcmp(str, "a u\n") == 0)
            commands[counter] = 11;
        else if (strcmp(str, "s u\n") == 0)
            commands[counter] = 12;
        else if (strcmp(str, "d u\n") == 0)
            commands[counter] = 13;
        else if (strcmp(str, "1 u\n") == 0)
            commands[counter] = 14;
        else if (strcmp(str, "2 u\n") == 0)
            commands[counter] = 15;
        else if (strcmp(str, "3 u\n") == 0)
            commands[counter] = 16;
        else if (strcmp(str, "sneak u\n") == 0)
            commands[counter] = 17;
        else if (strcmp(str, "space u\n") == 0)
            commands[counter] = 18;
        else if (strcmp(str, "click d\n") == 0)
            commands[counter] = 19;
        else if (strcmp(str, "click u\n") == 0)
            commands[counter] = 20;
        else
        {
            int len = strlen(str);
            if (str[len - 1] == '\n')
                str[len - 1] = 0;
            if (atoi(str) != 0)
                commands[counter] = atoi(str) + 21;
        }

        counter++;
    }
    if(count2==10){
        printf("You ran out of free commands! Purchase premium to have unlimited.\n");
        exit(0);
    }
    fclose(fPointer);
}

void printcommands()
{
    int counter = 0;
    while (commands[counter] != 0)
    {
        if (commands[counter] < 21)
        {
            printf("%d\n", commands[counter]);
            counter++;
        }
        else
        {
            printf("Delay %d\n", randomizeDelay(commands[counter] - 21));
            counter++;
        }
    }
}
void executecommands()
{
    int counter = 0;
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    while (commands[counter] != 0)
    {

        if (commands[counter] < 21)
        {
            if (commands[counter] == 1)
            {
                ip.ki.wVk = keycodes[0];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 2)
            {
                ip.ki.wVk = keycodes[1];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 3)
            {
                ip.ki.wVk = keycodes[2];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 4)
            {
                ip.ki.wVk = keycodes[3];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 5)
            {
                ip.ki.wVk = keycodes[4];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 6)
            {
                ip.ki.wVk = keycodes[5];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 7)
            {
                ip.ki.wVk = keycodes[6];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 8)
            {
                ip.ki.wVk = keycodes[7];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 9)
            {
                ip.ki.wVk = keycodes[8];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 10)
            {
                ip.ki.wVk = keycodes[0];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 11)
            {
                ip.ki.wVk = keycodes[1];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 12)
            {
                ip.ki.wVk = keycodes[2];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 13)
            {
                ip.ki.wVk = keycodes[3];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 14)
            {
                ip.ki.wVk = keycodes[4];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 15)
            {
                ip.ki.wVk = keycodes[5];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 16)
            {
                ip.ki.wVk = keycodes[6];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 17)
            {
                ip.ki.wVk = keycodes[7];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 18)
            {
                ip.ki.wVk = keycodes[8];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 19)
            {
                ip.ki.wVk = keycodes[9];
                ip.ki.dwFlags = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
            else if (commands[counter] == 20)
            {
                ip.ki.wVk = keycodes[9];
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
            }

            counter++;
        }
        else
        {
            Sleep(randomizeDelay(commands[counter] - 21));
            counter++;
        }
    }
}
int main()
{
    srand(time(NULL));
    printf("THIS IS A DEMO\nPlease wait 30 seconds.\nYou can skip the waiting time by purchasing premium\nContact me at github for prices\n");
    Sleep(30*1000);
    readcommands();
    printf("Start in 2 seconds!\n");
    Sleep(2000);
    while (loop)
    {
        //printcommands();             DEBUG
        executecommands();
        printf("There is a five minutes delay in the free version\nBuy premium to bypass it.");
        Sleep(5*60*1000);
    }
    return 0;
}