#include <stdlib.h>
#include <stdio.h>
#include <direct.h>
#include <string.h>


char SonicCD_dir[1024];
char Sonic1_dir[1024];
char Sonic2_dir[1024];
char Sonic_Mania_dir[1024];
char chosse_game;
char cwd[1024];





void get_path_Sonic_CD(){
        snprintf(SonicCD_dir, sizeof(SonicCD_dir), "%s\\RSDKv3\\Sonic CD", cwd);
}


void get_path_Sonic_1(){
        snprintf(Sonic1_dir, sizeof(Sonic1_dir), "%s\\RSDKv4\\Sonic 1", cwd);
}

void get_path_Sonic_2(){
        snprintf(Sonic2_dir, sizeof(Sonic2_dir), "%s\\RSDKv4\\Sonic 3", cwd);
}

void get_path_Sonic_Mania(){
        snprintf(Sonic_Mania_dir, sizeof(Sonic_Mania_dir), "%s\\RSDKv5\\Sonic Mania", cwd);
}


void run_Sonic_CD(){

    get_path_Sonic_CD();
    _chdir(SonicCD_dir);
    system("RSDKv3.exe");

}


void run_Sonic_1(){
    get_path_Sonic_1();
    _chdir(Sonic1_dir);
    system("RSDKv4.exe");

}


void run_Sonic_2(){
    get_path_Sonic_2();
    _chdir(Sonic2_dir);
    system("RSDKv4.exe");

}

void run_Sonic_Mania(){
    get_path_Sonic_Mania();
    _chdir(Sonic_Mania_dir);
    system("RSDKv5U.exe");

}

int launch(){
    do{
    
    printf("Chosse a game to play:\n 1 - Sonic CD\n 2 - Sonic 1\n 3 - Sonic 2\n 4 - Sonic Mania\n 0 - Exit\n");
    scanf("%c", &chosse_game);
    while (getchar() != '\n');
    if (chosse_game == '1'){
        run_Sonic_CD(cwd);
        continue;
    }
    if (chosse_game == '2'){
        run_Sonic_1(cwd);
        continue;
    }
    if (chosse_game == '3'){
        run_Sonic_2(cwd);
        continue;
    }   
    if (chosse_game == '4'){
        run_Sonic_Mania(cwd);
        continue;
    }
    if (chosse_game == '0'){
        break;
    }
    else{
        printf("Invalid input\n");

    }
    }
while(1);
}


int main() {
    _getcwd(cwd, sizeof(cwd));
    launch();
    




}
