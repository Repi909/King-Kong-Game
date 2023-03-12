#include "headers.h"

Projectile::Projectile() {
    projectileNum = 1;
    projectileFrq = 5000;
    mProjectile = ")";
}

//Get method for projectile frequency
int Projectile::getProjectileFrq(){
    return projectileFrq;
}

//Get method for number of projectiles
int Projectile::getProjectileNum(){
    return projectileNum;
}

//Set method for number of projectiles
void Projectile::setProjectileNum(int pNum){
    projectileNum = pNum;
}

void Projectile::setProjectileFrq(int pFrq){
    projectileFrq = pFrq;
}

int Projectile::randProjRow(){
    int projRow = rand() % 22 + 8;
    return projRow;
}

//Method to find position of projectile within array. If projectiles are next to each other, moveProjectile will delete from array.
void Projectile::projCollision(){

}

std::vector<int> Projectile::getPlaneProjectilePositions(COORD projectileTopLeft, int projectileRegion[], std::string projectile) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(console, &consoleInfo);
    COORD foundPos = {-1, -1};
    for (short int i = projectileTopLeft.X; i < projectileTopLeft.X + projectileRegion[0]; i++) {
        for (short int j = projectileTopLeft.Y; j < projectileTopLeft.Y + projectileRegion[1]; j++) {
            COORD projPos = {i, j};
            SetConsoleCursorPosition(console, projPos);
            CHAR_INFO projChar;
            SMALL_RECT readRegion = {projPos.X, projPos.Y, projPos.X, projPos.Y};
            if (ReadConsoleOutput(console, &projChar, {1, 1}, {0, 0}, &readRegion) && projChar.Char.AsciiChar == '-') {
                foundPos = projPos;
                break;
            }
        }
        if (foundPos.X != -1 && foundPos.Y != -1) {
            break;
        }
    }
    return {foundPos.X, foundPos.Y};
}