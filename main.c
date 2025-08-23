#include <stdlib.h>
#include <stdio.h>
#include <direct.h>
#include <string.h>


char SonicCD_dir[1024];
char Sonic1_dir[1024];
char Sonic2_dir[1024];
char Sonic_Mania_dir[1024];




char run_Sonic_CD(char cwd[1024]){

    snprintf(SonicCD_dir, sizeof(SonicCD_dir), "%s\\RSDKv3\\Sonic CD", cwd);

    _chdir(SonicCD_dir);
    system("RSDKv3.exe");

}


char run_Sonic_1(char cwd[1024]){

    snprintf(Sonic1_dir, sizeof(Sonic1_dir), "%s\\RSDKv4\\Sonic 1", cwd);

    _chdir(Sonic1_dir);
    system("RSDKv4.exe");

}


char run_Sonic_2(char cwd[1024]){

    snprintf(Sonic2_dir, sizeof(Sonic2_dir), "%s\\RSDKv4\\Sonic 2", cwd);

    _chdir(Sonic2_dir);
    system("RSDKv4.exe");

}

char run_Sonic_Mania(char cwd[1024]){

    snprintf(Sonic_Mania_dir, sizeof(Sonic_Mania_dir), "%s\\RSDKv5\\Sonic Mania", cwd);

    _chdir(Sonic_Mania_dir);
    system("RSDKv5U.exe");

}


int main() {
    char cwd[1024];
    _getcwd(cwd, sizeof(cwd));

    int chosse_game;
    printf("Chosse a game to play:\n 1 - Sonic CD\n 2 - Sonic 1\n 3 - Sonic 2\n 4 - Sonic Mania\n");
    scanf("%d", &chosse_game);


    if (chosse_game == 1){
        run_Sonic_CD(cwd);

    }
    if (chosse_game == 2){
        run_Sonic_1(cwd);

    }
    if (chosse_game == 3){
        run_Sonic_2(cwd);

    }
    if (chosse_game == 4){
        run_Sonic_Mania(cwd);

    }
    

}
