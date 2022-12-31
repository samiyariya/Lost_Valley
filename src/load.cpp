#include "header.h"

SDL_Texture* BG1=NULL;
SDL_Texture* Coin=NULL;
SDL_Texture* Man=NULL;
SDL_Texture* Obstacle1=NULL;
SDL_Texture* Obstacle2=NULL;
SDL_Texture* Obstacle3=NULL;
SDL_Texture* gameOver=NULL;
SDL_Texture* name=NULL;       
SDL_Texture* menu=NULL;
SDL_Texture* menu1=NULL;
SDL_Texture* mTexture=NULL;
SDL_Texture* newgame=NULL;
SDL_Texture* help=NULL;
SDL_Texture* highscore=NULL;
SDL_Texture* gEnd=NULL;
SDL_Texture* Continue=NULL;
SDL_Texture* city=NULL;
SDL_Texture* forest=NULL;
SDL_Texture* scoreTexture=NULL;
SDL_Texture* gScoretexture=NULL;
SDL_Texture* scoreImage=NULL;
SDL_Texture* menu2=NULL;
SDL_Texture* EnterName=NULL;
SDL_Texture* life=NULL;
SDL_Texture* tutorial=NULL;
SDL_Texture* sl=NULL;
SDL_Texture* nameTexture=NULL;
SDL_Texture* ScoreName=NULL;
SDL_Texture* HighScore=NULL;

SDL_Texture* BG2=NULL;
SDL_Texture* Star=NULL;
SDL_Texture* spirit = NULL;
SDL_Texture* enemy_zombie = NULL;
SDL_Texture* knife_texture = NULL;
SDL_Texture* enemy_ghost = NULL;

Mix_Music* menusound=NULL;
Mix_Music* citysound=NULL;
Mix_Music* forestsound=NULL;
Mix_Chunk* spiritsound=NULL;
Mix_Chunk* zombiesound=NULL;
Mix_Chunk* coinsound=NULL;
Mix_Chunk* diesound=NULL;
Mix_Chunk* collidesound=NULL;
Mix_Chunk* weaponsound=NULL;
Mix_Chunk* mouseclick;

SDL_Rect spirit_spriteclips[12];
SDL_Rect zombie_spriteclips[30];
SDL_Rect ghost_spriteclips[30];

TTF_Font* gFont = NULL;

SDL_Rect gSpriteClips[ 6 ];
int mWidth;
int mHeight;

bool loadMedia()
{
    bool success = true;
    BG1=loadtexture("Images/bg.png");
    if( BG1==NULL)
    {
        printf( "Failed to load background texture!\n" );
        success = false;
    }
    Man=loadtexture("Images/boy.png");
    if (Man==NULL)
    {
        printf( "Failed to load runningman texture!\n" );
        success = false;
    }
    else
    {
        man_sprite();

    }
    Coin=loadtexture("Images/coin.png");
    if (Coin==NULL)
    {
        printf( "Failed to load runningman texture!\n" );
        success = false;
    }
    Obstacle1=loadtexture("Images/obstacle1.png");
    if (Obstacle1==NULL)
    {
        printf( "Failed to load obstacle texture!\n" );
        success = false;
    }
    Obstacle2=loadtexture("Images/obstacle2.png");
    if (Obstacle2==NULL)
    {
        printf( "Failed to load obstacle texture!\n" );
        success = false;
    }
    Obstacle3=loadtexture("Images/obstacle3.png");
    if (Obstacle3==NULL)
    {
        printf( "Failed to load obstacle texture!\n" );
        success = false;
    }
    gameOver=loadtexture("Images/gameover.png");
    if (gameOver==NULL)
    {
        printf( "Failed to load gameover texture!\n" );
        success = false;
    }
    tutorial=loadtexture("Images/help.png");
    if (tutorial==NULL)
    {
        printf( "Failed to load help texture!\n" );
        success = false;
    }
    life=loadtexture("Images/life.png");
    if(life==NULL)
    {
        printf( "Failed to load gameover texture!\n" );
        success = false;
    }
    BG2=loadtexture("Images/bg2.png");
    if( BG2==NULL)
    {
        printf( "Failed to load background texture!\n" );
        success = false;
    }

    spirit = loadtexture("Images/animal.png");
    if(spirit == NULL)
    {
        printf("FAILED TO LOAD SPIRIT %s\n",SDL_GetError());
        success = false;
    }
    else
    {
        spirit_sprite();
    }

    enemy_zombie = loadtexture("Images/zombie.png");
    if(enemy_zombie == NULL)
    {
        printf("FAILED TO LOAD MONKEY %s\n",SDL_GetError());
        success = false;
    }
    else
    {
        zombie_sprite();

    }

    knife_texture = loadtexture("Images/weapon.png");
    if(knife_texture == NULL)
    {
        printf("FAILED TO LOAD NINJA STAR %s/n",SDL_GetError());
        success = false;
    }

    enemy_ghost = loadtexture("Images/ghost.png");
    if(enemy_ghost == NULL)
    {
        printf("FAILED TO LOAD GHOST IMAGES %s/n",SDL_GetError());
        success = false;
    }
    else
    {
        ghost_sprite();
    }

    menu=loadtexture("Images/menu.png");
    if(menu==NULL)
    {
        printf( "Failed to load menu texture!\n" );
        success = false;
    }

    menu1=loadtexture("Images/menu1.png");
    if(menu1==NULL)
    {
        printf( "Failed to load menu texture!\n" );
        success = false;
    }
    menu2=loadtexture("Images/mode.png");
    if(menu1==NULL)
    {
        printf( "Failed to load menu texture!\n" );
        success = false;
    }
    name=loadtexture("Images/name.png"); 
    if(name==NULL)
    {
        printf( "Failed to load name texture!\n" );
        success = false;
    }
    HighScore=loadtexture("Images/highscore.png");
     if(HighScore==NULL)
    {
        printf( "Failed to load menu texture!\n" );
        success = false;
    }


    gFont = TTF_OpenFont( "abcd.otf", 50);
	if( gFont == NULL )
	{
		printf( "Failed to load ttf font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
    
    SDL_Color textColor = { 0xFF, 0xC0, 0x00 };   

    ScoreName=loadFromRenderedText("SCORE",textColor);
    if(ScoreName==NULL)
    {
        printf( "Failed to load text texture!\n" );
		success = false;
    }
    gScoretexture=loadFromRenderedText("SCORE : ",textColor);
     if(gScoretexture==NULL)
    {
        printf( "Failed to load menu texture!\n" );
        success = false;
    }
   
    menusound= Mix_LoadMUS("sound/menusound.mp3");
    if(menusound==NULL)
    {
         printf( "Failed to load menusound %s\n",Mix_GetError() );
		success = false;
    }
    citysound= Mix_LoadMUS("sound/citysound.mp3");
    if(citysound==NULL)
    {
         printf( "Failed to load citysound %s\n",Mix_GetError() );
		success = false;
    }
    forestsound= Mix_LoadMUS("sound/forestsound.mp3");
    if(forestsound==NULL)
    {
         printf( "Failed to load forestsound %s\n",Mix_GetError() );
		success = false;
    }
    coinsound= Mix_LoadWAV("sound/coinsound.mp3");
    if(coinsound==NULL)
    {
         printf( "Failed to load coinsound %s\n",Mix_GetError() );
		success = false;
    }
    collidesound= Mix_LoadWAV("sound/collidesound.mp3");
    if(collidesound==NULL)
    {
         printf( "Failed to load collidesound %s\n",Mix_GetError() );
		success = false;
    }
    diesound= Mix_LoadWAV("sound/diesound.mp3");
    if(diesound==NULL)
    {
         printf( "Failed to load diesound %s\n",Mix_GetError());
		success = false;
    }
    spiritsound= Mix_LoadWAV("sound/spiritsound.mp3");
    if(spiritsound==NULL)
    {
         printf( "Failed to load spiritsound %s\n",Mix_GetError() );
		success = false;
    }
    weaponsound= Mix_LoadWAV("sound/weaponsound.mp3");
    if(weaponsound==NULL)
    {
         printf( "Failed to load weaponsound %s\n",Mix_GetError() );
		success = false;
    }
    zombiesound= Mix_LoadWAV("sound/zombiesound.mp3");
    if(zombiesound==NULL)
    {
         printf( "Failed to load zombiesound %s\n",Mix_GetError() );
		success = false;
    }
     mouseclick= Mix_LoadWAV("sound/mouseclick.mp3");
    if(mouseclick==NULL)
    {
         printf( "Failed to mouseclick %s\n",Mix_GetError() );
		success = false;
    }
   
    return success;
}

SDL_Texture* loadtexture(std::string path)
{
    void free();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    else
    {
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

        else
        {
            SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0xFF, 0xFF ) );
        }
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}

SDL_Texture* loadFromRenderedText( std::string textureText, SDL_Color textColor )
{

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
        else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	
	//Return success
	return mTexture;
}



