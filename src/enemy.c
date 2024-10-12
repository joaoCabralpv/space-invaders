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

void ChangeFrame(Enemy *enemy){
    enemy->currentTexture++;
    enemy->currentTexture %= enemy->lenTextures; // Changes current texture to 0 if it is equal to lenTextures
}

void UpdateEnemyPos(Enemy* enemies,int enemiesLenght,GlobalEnemyState *state){
        if (state->goDown) {
            state->goDown = false;
            for(int i=0;i<=enemiesLenght;i++) {
                enemies[i].posY+=state->enemyHight;
            }
        } else {
         for(int i=0;i<=enemiesLenght;i++) {
            enemies[i].posX+=(state->enemyWidth*state->direction);
            int maxRight = (((GetScreenWidth()/state->enemyWidth)-1))*state->enemyWidth;
            printf("%d\n",maxRight);
            int maxLeft = state->enemyWidth;
            if (enemies[i].posX <= maxLeft || enemies[i].posX >= maxRight) {
                state->direction *= -1;
                state->goDown = true;
            }
         }
    }
}

void UpdateEnemies(Enemy *enemies,int enemiesLength ,GlobalEnemyState *state) {
    bool update = UpdateCheck(state);
    if (update) { 
        UpdateEnemyPos(enemies,enemiesLength,state);
    }
        for (int i=0;i<=enemiesLength;i++) {
            if (update) {
                ChangeFrame(&enemies[i]);
            }
            DrawEnemy(&enemies[i]);
        }
}


