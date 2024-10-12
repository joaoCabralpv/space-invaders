#include <raylib.h>
#include <stdio.h>
#include "enemy.h"
#include "utils.h"


bool UpdateCheck(GlobalEnemyState *state) {
    //printf("Update");
    double timePassed = GetTime()-state->move_last_time;
    if (timePassed>=state->move_time_s)
        {
            state->move_last_time = GetTime();
            return true;
        }
        return false;
}

void UpdateEnemies(Enemy *enemy,int enemyLength ,GlobalEnemyState *state) {
    //DrawTexture(enemy[0].Textures[enemy[0].currentTexture],200, 200,WHITE);
    if (UpdateCheck(state)){
        //printf("1");
        //printf("len:%d",len);
        for (int i=0;i<=enemyLength;i++) {
            enemy[i].currentTexture++;
            enemy[i].currentTexture%=enemy[i].maxTexture;
            //printf("%d\n");
            //if(enemy[i].currentTexture>enemy[i].maxTexture)
               // enemy[i].currentTexture=0;
        }
    }
}