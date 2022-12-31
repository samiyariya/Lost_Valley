#include "header.h"

int x_pos;
int y_pos;
int up;
int down;
int ground;
int y_velocity;
void man_sprite()
{
    for(int i=0;i<6;i++){
        gSpriteClips[ i ].x =  115*i;
        gSpriteClips[ i ].y =  0;
        gSpriteClips[ i ].w =  115;
        gSpriteClips[ i ].h =  170;
    }   
}
void jump(int y_pos_start)
{
    if(ground && up && !down)
    {
        y_velocity = 20;
        ground =0;
    }
    if(up)
    {
        y_velocity--;
        y_pos -= y_velocity;
    }
    if(down)
    {
        y_velocity++;
        y_pos +=y_velocity;
    }
    if(!ground && y_velocity<=0)
    {
        down = 1;
        up =0;
    }
    if(y_pos >= y_pos_start)
    {
        y_pos=y_pos_start;
        up=0;
        down=0;
        ground = 1;
        y_velocity=0;
    }
}
