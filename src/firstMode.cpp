#include "header.h"

int scrollingOffset;
int frame;
int score;
int alive;
int i,j,k;

void firstMode()
{
    jump(400);

    //Scroll background
    scrollingOffset=scrollingOffset-6;
    if( scrollingOffset < -SCREEN_WIDTH)
    {
        scrollingOffset = 0;
    }

    coins(477,272,false);
    obstacle();

    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    //Render background
    render(BG1,SCREEN_WIDTH,SCREEN_HEIGHT,scrollingOffset,0,NULL);
    render(BG1,SCREEN_WIDTH,SCREEN_HEIGHT,scrollingOffset+SCREEN_WIDTH,0,NULL);

    //render obstacle
    render(Obstacle1,120,90,obs_x1,745,NULL); //710
    render(Obstacle2,140,80,obs_x2,750,NULL);
    render(Obstacle3,100,90,obs_x3,750,NULL);

    //Render Current Clip
    SDL_Rect* currentclip=&gSpriteClips[frame/6];
    render(Man,mWidth,mHeight,x_pos,y_pos+260,currentclip);  //240

    //Render coin          240
    render(Coin,40,55,coin.x,coin.y+280,NULL);
                    
    //update score
    render(gScoretexture,mWidth-150,mHeight,0,0,NULL);
    int_to_string(score);
    scoreImage=scoreprint(scorestring);
    render(scoreImage,70,60,mWidth-150,0,NULL);

    //update life
    for(i=0,j=0;i<alive;i++,j=j+70)
    {
        render(life,55,38,0+j,mHeight,NULL);
    }
                   
    //update screen
    SDL_RenderPresent( gRenderer );

                    
    ++frame;
    if( frame / 6 >= 6 )
    frame = 0;
}
