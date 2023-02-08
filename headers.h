#ifndef HEADERS_H
#define HEADERS_H

class KBMInput{
    private:
        enum action{ UP='w', DOWN ='s', SHOOT = 'e'};

    public:
        void planeAction(enum action){
            if(action == UP){
                pPos++;
            }
            else if(action == DOWN){
                pPos--;
            }
            else if(action == SHOOT){
                Plane::shoot()
            }
        }
};

class Plane{
    private:
        int pProj;
        int pPos;

    
    public:
        int shoot(int plane ){

        }

        int get_pPos(){
            return pPos;
        }

}

#endif