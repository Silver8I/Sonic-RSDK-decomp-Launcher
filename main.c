#include <stdlib.h>
#include <stdio.h>
#include <direct.h>
#include <string.h>


#define RSDKv3_URL "https://github.com/RSDKModding/RSDKv3-Decompilation/releases/download/1.3.2/win_x64.zip"
#define RSDKv4_URL "https://github.com/RSDKModding/RSDKv4-Decompilation/releases/download/1.3.2/win_x64.zip"
#define RSDKv5_URL "https://github.com/RSDKModding/Sonic-Mania-Decompilation/releases/download/v1.1.0/mania-windows-x64.zip"




char SonicCD_dir[1024];
char Sonic1_dir[1024];
char Sonic2_dir[1024];
char Sonic_Mania_dir[1024];
char chosse_game;
char cwd[1024];

int download_game( char *url, char *zip_file, char *extract_dir, char *version_dir) {
    char mkdir[1024];
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "curl -O -L %s", url);
    snprintf(mkdir, sizeof(mkdir), "mkdir \"%s\"", version_dir);
    system(mkdir);
    _chdir(version_dir);
    system(cmd);



    snprintf(cmd, sizeof(cmd), "powershell Expand-Archive -Path %s -DestinationPath %s", zip_file, extract_dir);
    system(cmd);
}

void setup_Generlal(int game){
    
}



void setup_Sonic_CD(){
    download_game(RSDKv3_URL, "win_x64.zip", "Sonic_CD", "RSDKv3");
}

void setup_Sonic_1(){
    download_game(RSDKv4_URL, "win_x64.zip", "Sonic_1", "RSDKv4");
}

void setup_Sonic_2(){
    download_game(RSDKv4_URL, "win_x64.zip", "Sonic_2", "RSDKv4");
}

void setup_Sonic_Mania(){
    download_game(RSDKv5_URL, "mania-windows.zip", "Sonic_Mania", "RSDKv5");
}



void get_path_Sonic_CD(){
        snprintf(SonicCD_dir, sizeof(SonicCD_dir), "%s\\RSDKv3\\Sonic_CD", cwd);
}

void get_path_Sonic_1(){
        snprintf(Sonic1_dir, sizeof(Sonic1_dir), "%s\\RSDKv4\\Sonic_1", cwd);
}

void get_path_Sonic_2(){
        snprintf(Sonic2_dir, sizeof(Sonic2_dir), "%s\\RSDKv4\\Sonic_2", cwd);
}

void get_path_Sonic_Mania(){
        snprintf(Sonic_Mania_dir, sizeof(Sonic_Mania_dir), "%s\\RSDKv5\\Sonic_Mania", cwd);
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
    else if (chosse_game == '2'){
        run_Sonic_1(cwd);
        continue;
    }
    else if (chosse_game == '3'){
        run_Sonic_2(cwd);
        continue;
    }   
    else if (chosse_game == '4'){
        run_Sonic_Mania(cwd);
        continue;
    }
    else if (chosse_game == '0'){
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
