#include <raylib.h>

struct enemy{
    Texture2D* Textures;
    int lenTextures;
    int currentTexture;
    int posX;
    int posY;
};

struct globalEnemyState{   
    double start;
    double move_time_s; // Enemies wait this amount of time between moves (ms)
    double move_last_time; // Last time enemies updated 
    int enemyWidth;
    int enemyHight;
    int direction; // 1->down -1-left
    bool goDown;
};

typedef struct enemy Enemy;
typedef struct globalEnemyState GlobalEnemyState;

bool UpdateCheck(GlobalEnemyState *state);
void UpdateEnemies(Enemy *enemy, int enemyLength, GlobalEnemyState *state);
void ChangeFrame(Enemy *enemy);
void DrawEnemy(Enemy *enemy);
