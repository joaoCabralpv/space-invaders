#include <raylib.h>

struct enemy{
    Texture2D* Textures;
    int maxTexture;
    int currentTexture;
};

struct globalEnemyState{   
    double start;
    double move_time_s; // Enemies wait this amount of time between moves (ms)
    double move_last_time; // Last time enemies updated 
};

typedef struct enemy Enemy;
typedef struct globalEnemyState GlobalEnemyState;

bool UpdateCheck(GlobalEnemyState *state);
void UpdateEnemies(Enemy *enemy,int enemyLength ,GlobalEnemyState *state);
