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

void DrawEnemy(Enemy *enemy) {
        DrawTexture(enemy->Textures[enemy->currentTexture],enemy->posX,enemy->posY,WHITE);
}


void UpdateEnemies(Enemy *enemies,int enemyLength ,GlobalEnemyState *state) {
    bool update = UpdateCheck(state);
        for (int i=0;i<=enemyLength;i++) {
            if (update) {
                //printf("1");
                enemies[i].currentTexture++;
                enemies[i].currentTexture%=enemies[i].maxTexture;
            }
            //DrawEnemy(&enemies[i]);
        }
    }
