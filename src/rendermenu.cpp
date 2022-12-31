#include "header.h"

//int scrollingOffset;

void render (SDL_Texture* mTexture, int Width,int Height,int x, int y,SDL_Rect* clip)
{
    SDL_Rect renderQuad = { x, y,Width,Height};
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad);
}

void start_menu()
{   
    //Scroll background
    scrollingOffset=scrollingOffset-1.5;
    if( scrollingOffset < -SCREEN_WIDTH)
    {
        scrollingOffset = 0;
    }

    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );  
                      
    render(menu,SCREEN_WIDTH,SCREEN_HEIGHT,0,0,NULL);
    SDL_RenderPresent(gRenderer);

}

void middle_menu()  
{
    render(menu1,SCREEN_WIDTH,SCREEN_HEIGHT,0,0,NULL);
    render(Continue,mWidth,mHeight,10,(SCREEN_HEIGHT/2)-100,NULL);
    SDL_RenderPresent(gRenderer);
}

void mode_menu()
{
    render(menu2,SCREEN_WIDTH,SCREEN_HEIGHT,0,0,NULL);
    render(city,mWidth,mHeight+50,(SCREEN_WIDTH/2)-100,(SCREEN_HEIGHT/2)-150,NULL);
    render(forest,mWidth,mHeight+50,(SCREEN_WIDTH/2)-100,(SCREEN_HEIGHT/2),NULL);
    SDL_RenderPresent(gRenderer);

}

void instruction()
{
    render(tutorial,SCREEN_WIDTH,SCREEN_HEIGHT,0,0,NULL);
    SDL_RenderPresent(gRenderer);
}