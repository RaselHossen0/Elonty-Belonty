#include "init.h"
#include "audio.h"
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
		
		#if defined(SDL_TTF_MAJOR_VERSION)
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

//The application time based timer
class LTimer
{
    public:
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};

//Starts up SDL and creates window
bool init1();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
// SDL_Window* gWindow = NULL;

// //The window renderer
// SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font* gFont = NULL;

//Scene textures
LTexture gTimeTextTexture;
LTexture gPausePromptTexture;
LTexture gStartPromptTexture;

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( rend, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

#if defined(SDL_TTF_MAJOR_VERSION)
bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( rend, textSurface );
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
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	
	//Return success
	return mTexture != NULL;
}
#endif

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( rend, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

LTimer::LTimer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void LTimer::start()
{
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void LTimer::stop()
{
    //Stop the timer
    mStarted = false;

    //Unpause the timer
    mPaused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}

void LTimer::pause()
{
    //If the timer is running and isn't already paused
    if( mStarted && !mPaused )
    {
        //Pause the timer
        mPaused = true;

        //Calculate the paused ticks
        mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
    }
}

void LTimer::unpause()
{
    //If the timer is running and paused
    if( mStarted && mPaused )
    {
        //Unpause the timer
        mPaused = false;

        //Reset the starting ticks
        mStartTicks = SDL_GetTicks() - mPausedTicks;

        //Reset the paused ticks
        mPausedTicks = 0;
    }
}

Uint32 LTimer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool LTimer::isStarted()
{
	//Timer is running and paused or unpaused
    return mStarted;
}

bool LTimer::isPaused()
{
	//Timer is running and paused
    return mPaused && mStarted;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont( "lazy.ttf", 28 );
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Set text color as black
		SDL_Color textColor = { 0, 0, 0, 255 };
		
		//Load stop prompt texture
		if( !gStartPromptTexture.loadFromRenderedText( "Press S to Start or Stop the Timer", textColor ) )
		{
			printf( "Unable to render start/stop prompt texture!\n" );
			success = false;
		}
		
		//Load pause prompt texture
		if( !gPausePromptTexture.loadFromRenderedText( "Press P to Pause or Unpause the Timer", textColor ) )
		{
			printf( "Unable to render pause/unpause prompt texture!\n" );
			success = false;
		}
	}

	return success;
}

void close()
{
	//Free loaded images
	gTimeTextTexture.free();
	gStartPromptTexture.free();
	gPausePromptTexture.free();

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Destroy window	
	SDL_DestroyRenderer( rend );
	SDL_DestroyWindow( win );
	
	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(int agr, char *args[])
{

    init();

    surface = IMG_Load("res/dip.jpg");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex0)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    // Mix_PlayChannel(-1,menu,1);
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex0, NULL, NULL);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 3);

    audio();

    surface = IMG_Load("res/start.jpg");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *tex3 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    if (!tex3)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    TTF_Font *font = TTF_OpenFont("res/font/Oswald-Bold.ttf", 40);
    surface = TTF_RenderText_Solid(font, "Elonti-Belonti", {0, 0, 0});

    SDL_Texture *fontTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_Rect textRect = {40, 40, 500, 50};
    SDL_FreeSurface(surface);

    SDL_Rect start_rect;
    start_rect.w = 300;
    start_rect.h = 150;
    start_rect.x = (WINDOW_WIDTH - start_rect.w) / 2;
    start_rect.y = (WINDOW_HEIGHT - start_rect.h) / 2;

    surface = IMG_Load("res/newman.png");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect playerRect;     // rect for a single frame of the sprite sheet
    SDL_Rect playerPosition; // rect for the whole sprite sheet
    playerPosition.x = 350;
    playerPosition.y = 550;
    playerPosition.w = 150;
    playerPosition.h = 150; // ei rec(square) er moddher kothao texture (runman) load hobe

    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    SDL_QueryTexture(tex, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth / 9;
    frameHeight = textureHeight;
    // printf("%d %d",frameHeight,frameWidth);
    playerRect.x = playerRect.y = 0;
    playerRect.w = frameWidth;
    playerRect.h = frameHeight;
    SDL_Rect boy2;     // rect for a single frame of the sprite sheet
    SDL_Rect boy2_pos; // rect for the whole sprite sheet
    boy2_pos.x = 750;
    boy2_pos.y = 550;
    boy2_pos.w = 150;
    boy2_pos.h = 150; // ei rec(square) er moddher kothao texture (runman) load hobe

    boy2.x = 400;
    boy2.y = 50;
    boy2.w = frameWidth;
    boy2.h = frameHeight;
    // SDL_SetRenderDrawColor(rend,0xFF,0,0,0xFF);

    surface = IMG_Load("res/gameover.jpeg");
    if (!surface)
    {
        printf("Green rectangle Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        printf("Green Rectangle Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect gameover_rect;
    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 250;

    surface = IMG_Load("res/bg.png");
    SDL_Texture *bg_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/putull.png");
    SDL_Texture *Putul_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_Rect playrRect;     // rect for a single frame of the sprite sheet
    SDL_Rect playrPosition; // rect for the whole sprite sheet
    playrPosition.x = 568;
    playrPosition.y = 30;
    playrPosition.w = 75;
    playrPosition.h = 75; // ei rec(square) er moddher kothao texture (runman) load hobe

    surface = IMG_Load("res/2883482.png");
    SDL_Texture *next_level = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect next;
    // SDL_QueryTexture(next_level,NULL,NULL,&next.w,&next.h);
    next.w = 180;
    next.h = 180;
    next.x = 490;
    next.y = 450;
    surface = IMG_Load("res/sprite-02.png");
    SDL_Texture *l2boy = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    int tx1W, tx1H, f1W, f1H;
    SDL_Rect src_l2b, dest_l2b;
    SDL_QueryTexture(l2boy, NULL, NULL, &tx1W, &tx1H);
    f1W = tx1W / 3;
    f1H = tx1H;
   // printf("%d %d", f1W, f1H);
    src_l2b.w = f1W;
    src_l2b.h = f1H;
    src_l2b.x = src_l2b.y = 0;
    dest_l2b.w = 450;
    dest_l2b.h = 450;
    dest_l2b.x = 500;
    dest_l2b.y = 100;
    int framWidth, framHeight;
    int texturWidth, texturHeight;
    SDL_QueryTexture(Putul_Tex, NULL, NULL, &texturWidth, &texturHeight);

    framWidth = texturWidth / 4;
    framHeight = texturHeight / 3;
    playrRect.x = playrRect.y = 0;
    playrRect.w = framWidth;
    playrRect.h = framHeight;
    struct rect r1(texturWidth / 4, texturHeight / 3);

    playrRect.x = playrRect.y = 0;
    playrRect.w = r1.frmWid;
    playrRect.h = r1.frmHit;

    surface = IMG_Load("res/fire.png");
    SDL_Texture *fire_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_Rect plarRect;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition; // rect for the whole sprite sheet
    plarPosition.x = 390;
    plarPosition.y = 100;
    plarPosition.w = 130;
    plarPosition.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth, txturHeight;
    SDL_QueryTexture(fire_Tex, NULL, NULL, &txturWidth, &txturHeight);

    struct rect r3(txturWidth / 10, txturHeight);
    plarRect.x = plarRect.y = 0;
    plarRect.w = r3.frmWid;
    plarRect.h = r3.frmHit;

    SDL_Rect plarRect1;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition1; // rect for the whole sprite sheet
    plarPosition1.x = 195;
    plarPosition1.y = 100;
    plarPosition1.w = 130;
    plarPosition1.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth1, txturHeight1;
    SDL_QueryTexture(fire_Tex, NULL, NULL, &txturWidth1, &txturHeight1);

    struct rect r2(txturWidth1 / 10, txturHeight1);
    plarRect1.x = plarRect1.y = 0;
    plarRect1.w = r2.frmWid;
    plarRect1.h = r2.frmHit;

    SDL_Rect plarRect2;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition2; // rect for the whole sprite sheet
    plarPosition2.x = 20;
    plarPosition2.y = 100;
    plarPosition2.w = 130;
    plarPosition2.h = 130;

    int txturWidth2, txturHeight2;
    SDL_QueryTexture(fire_Tex, NULL, NULL, &txturWidth2, &txturHeight2);

    struct rect r5(txturWidth2 / 10, txturHeight2);
    plarRect2.x = plarRect2.y = 0;
    plarRect2.w = r5.frmWid;
    plarRect2.h = r5.frmHit;

    surface = IMG_Load("res/fire2.png");
    SDL_Texture *fire2_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_Rect plarRect22;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition22; // rect for the whole sprite sheet
    plarPosition22.x = 690;
    plarPosition22.y = 100;
    plarPosition22.w = 130;
    plarPosition22.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth22, txturHeight22;
    SDL_QueryTexture(fire2_Tex, NULL, NULL, &txturWidth22, &txturHeight22);

    struct rect r6(txturWidth2 / 10, txturHeight2);
    plarRect22.x = plarRect22.y = 0;
    plarRect22.w = r6.frmWid;
    plarRect22.h = r6.frmHit;

    SDL_Rect plarRect3;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition3; // rect for the whole sprite sheet
    plarPosition3.x = 890;
    plarPosition3.y = 100;
    plarPosition3.w = 130;
    plarPosition3.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth3, txturHeight3;
    SDL_QueryTexture(fire2_Tex, NULL, NULL, &txturWidth3, &txturHeight3);

    struct rect r7(txturWidth1 / 10, txturHeight1);
    plarRect3.x = plarRect3.y = 0;
    plarRect3.w = r7.frmWid;
    plarRect3.h = r7.frmHit;

    SDL_Rect plarRect4;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition4; // rect for the whole sprite sheet
    plarPosition4.x = 1090;
    plarPosition4.y = 100;
    plarPosition4.w = 130;
    plarPosition4.h = 130;

    int txturWidth4, txturHeight4;
    SDL_QueryTexture(fire2_Tex, NULL, NULL, &txturWidth4, &txturHeight4);

    struct rect r8(txturWidth4 / 10, txturHeight4);
    plarRect4.x = plarRect4.y = 0;
    plarRect4.w = r8.frmWid;
    plarRect4.h = r8.frmHit;

    surface = IMG_Load("res/replay.png");
    if (!surface)
    {
        printf("replay Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!replay_tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Rect replay_rect;
    replay_rect.w = 200;
    replay_rect.h = 100;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2;

    surface = IMG_Load("res/cloud.png");
    SDL_Texture *cloud = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_Rect cloud_rect;
    SDL_QueryTexture(cloud, NULL, NULL, &cloud_rect.w, &cloud_rect.h);
    cloud_rect.w /= 8;
    cloud_rect.h /= 8;
    cloud_rect.x = 0;
    cloud_rect.y = 0;


surface=IMG_Load("res/fireA.png");
    SDL_Texture *fir=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect src_fir,dest_fir;
    int tfW,tfH,fw,fh;
    SDL_QueryTexture(fir,NULL,NULL,&tfW,&tfH);
    fw=tfW/8;
    fh=tfH/4;
    src_fir.w=fw;
    src_fir.h=fh;
    src_fir.x=0;
    src_fir.y=0;
    dest_fir.w=playerPosition.w*2;
    dest_fir.h=playerPosition.h*2;
    dest_fir.x=dest_fir.y=0;

    surface = IMG_Load("res/playAgain.png");
    SDL_Texture *againTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    bool isRunning = true;
    float y_pos = 550.0;
    float y_pos1 = 450.0;
    int gameover = 0;
    int start = 1;
    int main_game = 0;  int goob=0;
    int next_lvl = 0;
    int frameTime = 0, FPS = 60;
    int scroll = 0;
  //  int loob=0;
  int var=1;
    SDL_Event ev,e;
    SDL_Color textColor = { 0, 0, 0, 255 };

			//The application timer
			LTimer timer;

			//In memory text stream
			std::stringstream timeText;
    while (isRunning)
    {
         int goob=0,loob=0;

        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                switch (ev.key.keysym.scancode)
                {

                case SDL_SCANCODE_UP:
                {
                    y_pos = y_pos - (500 / 60);
                    if (y_pos > 0)
                        playerPosition.y = (int)y_pos;
                    else
                    {
                        y_pos = 0;
                        playerPosition.y = 0;
                    }
                    goob=1;
                    playerRect.x += frameWidth;
                    if (playerRect.x >= textureWidth - frameWidth)
                        playerRect.x = 0;
                    break;
                }

                case SDL_SCANCODE_DOWN:
                {
                    goob=1;
                    y_pos = y_pos + (500 / 60);
                    if (y_pos < 550)
                        playerPosition.y = (int)y_pos;
                    else
                    {
                        y_pos = 550;
                        playerPosition.y = 550;
                    }

                    playerRect.x -= frameWidth;
                    if (playerRect.x <= 0)
                    {
                        playerRect.x = 0;
                        playerRect.x = textureWidth - frameWidth;
                    }
                }
                if( e.key.keysym.sym == SDLK_s )
						{
							if( timer.isStarted() )
							{
								timer.stop();
							}
							else
							{
								timer.start();
							}
						}
						//Pause/unpause
						else if( e.key.keysym.sym == SDLK_p )
						{
							if( timer.isPaused() )
							{
								timer.unpause();
							}
							else
							{
								timer.pause();
							}
						}
                }
            }
        }

        if (main_game)
        {
            double initTime=0;
            double startTime = SDL_GetTicks() / 1000.0;
        
            if (startTime  >= 2*var&&startTime<=10*var)
            {
                Mix_PlayChannel(-1,rand1,0);
            }
              else if (startTime  >= 10.1*var&&startTime<=12.0*var)
            {
                if(goob)
                loob=1;
            }
            
            
          else  if (startTime  >= 12.0*var&&startTime<=18.0*var)
            {
                Mix_PlayChannel(-1,rand2,0);
            }
            else  if (startTime  >= 18*var&&startTime<=21*var)
            {
                if(goob)
                loob=1;
            }
            
            else  if (startTime  >= 21.0*var&&startTime<=25*var)
            {
                
                Mix_PlayChannel(-1,rand3,0);
            }     
            else  if (startTime  >= 25*var&&startTime<=28*var)
            {
                if(goob)
                loob=1;
            }
            
            else  if (startTime  >= 28*var&&startTime<=34*var)
            {
                
                Mix_PlayChannel(-1,rand3,0);
            } 
            cloud_rect.x += 1;
            if (cloud_rect.x >= WINDOW_WIDTH)
                cloud_rect.x = 0;

                src_fir.x+=fw;
                if(src_fir.x+fw>=tfW){
                    src_fir.x=0;
            frameTime++;
            if (FPS / frameTime == 1) // will be repeated 7 times a second
            {
                frameTime = 0; // repeat
                
                }
                playrRect.x += r1.frmWid;
                if (playrRect.x >= texturWidth - r1.frmWid)
                {
                    playrRect.x = 0;
                    playrRect.y += r1.frmHit;
                }
                if (playrRect.y >= texturHeight - r1.frmHit)
                    playrRect.y = 0;

                plarRect.x += r3.frmWid;
                if (plarRect.x >= txturWidth - r3.frmWid)
                    plarRect.x = 0;
                plarRect1.x += r2.frmWid;
                if (plarRect1.x >= txturWidth1 - r2.frmWid)
                    plarRect1.x = 0;

                plarRect2.x += r5.frmWid;
                if (plarRect2.x >= txturWidth2 - r5.frmWid)
                    plarRect2.x = 0;

                plarRect3.x += r7.frmWid;
                if (plarRect3.x >= txturWidth3 - r7.frmWid)
                    plarRect3.x = 0;
                plarRect4.x += r8.frmWid;
                if (plarRect4.x >= txturWidth4 - r8.frmWid)
                    plarRect4.x = 0;

                plarRect22.x += r6.frmWid;
                if (plarRect22.x >= txturWidth22 - r6.frmWid)
                    plarRect22.x = 0;
            }
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, tex0, NULL, NULL);
            SDL_RenderCopy(rend, bg_Tex, NULL, NULL);
            SDL_RenderCopy(rend, cloud, NULL, &cloud_rect);
            SDL_RenderCopy(rend, Putul_Tex, &playrRect, &playrPosition);
            SDL_RenderCopy(rend, fire_Tex, &plarRect, &plarPosition);
            SDL_RenderCopy(rend, fire_Tex, &plarRect1, &plarPosition1);
            SDL_RenderCopy(rend, fire_Tex, &plarRect2, &plarPosition2);
            SDL_RenderCopy(rend, fire2_Tex, &plarRect22, &plarPosition22);
            SDL_RenderCopy(rend, fire2_Tex, &plarRect3, &plarPosition3);
            SDL_RenderCopy(rend, fire2_Tex, &plarRect4, &plarPosition4);
            SDL_RenderCopy(rend, tex, &playerRect, &playerPosition);

            if(loob)
            {
                dest_fir.y=playerPosition.y;
                dest_fir.x=350;
                SDL_RenderCopy(rend,fir,&src_fir,&playerPosition);
              //  SDL_RenderCopy(rend, tex, &playerRect, &playerPosition);
                //SDL_RenderPresent(rend);
                gameover=4;
                
            }
            SDL_RenderPresent(rend);
            SDL_RenderClear(rend);

            if (playerPosition.y <= 100)
            {
                gameover = 1;
                var++;
                main_game = 0;
                 
              
            }
           
            start = 0;
        }
        else if (start)
        {
            // Mix_PlayChannel( -1, replay, 0 );
            // Mix_PlayChannel(-1,menu,0);
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, fontTex, NULL, &textRect);
            SDL_RenderCopy(rend, tex3, NULL, &start_rect);
            SDL_RenderPresent(rend);

            int mousx, mousy;
            int button = SDL_GetMouseState(&mousx, &mousy);
            // printf("%d %d\n", mousx, mousy);

            if (button & SDL_BUTTON(1))
            {
                if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
                {
                    Mix_PlayChannel(-1, mouse, 4);
                    // SDL_Delay(2000);
                    main_game = 1;
                }
            }
        }
        else if (gameover == 1)
        {
            Mix_PlayChannel(-1, replay1, 0);
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
            SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);
            SDL_RenderCopy(rend, next_level, NULL, &next);
            SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);
            // printf("%d %d",mousex,mousey);

            if (buttons & SDL_BUTTON(1))
            {
                if (mousex >= replay_rect.x && mousex <= (replay_rect.x + replay_rect.w) && mousey >= replay_rect.y && mousey <= (replay_rect.y + replay_rect.h))
                {
                    Mix_PlayChannel(-1, mouse, 0);
                    y_pos = 550.0;
                    playerPosition.x = 400;
                    playerPosition.y = 550;
                    playerRect.x = playerRect.y = 0;
                    main_game = 1;
                }

                if (mousex >= next.x && mousex <= (next.x + next.w) && mousey >= next.y && mousey <= (next.y + next.h))
                {

                    next_lvl = 1;
                    main_game = 0;
                    gameover = 0;
                }
            }
        }
         else if(gameover==4)
         {
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend,againTex,NULL,NULL);
             SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);
           

            if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousex >= WINDOW_WIDTH/2.5 && mousex <= WINDOW_WIDTH/1.5 && mousey >= WINDOW_HEIGHT/2.5&& mousey <= WINDOW_HEIGHT/1.5)
                {
                    gameover = 0;
                    y_pos=550.0;
                    //count = 0;
                   playerPosition.x=400;
                   playerPosition.y=550;
                   playerRect.x=playerRect.y=0;
                    
                   
                }
            }
        }
        else if (next_lvl == 1)
        {
            timeText.str( "" );
				timeText << "Seconds since start time " << ( timer.getTicks() / 1000.f ) ; 

				//Render text
				if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor ) )
				{
					printf( "Unable to render time texture!\n" );
				}

				//Clear screen
				SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
				//SDL_RenderClear( rend);

				//Render textures
				gStartPromptTexture.render( ( WINDOW_WIDTH - gStartPromptTexture.getWidth() ) / 2, 0 );
				gPausePromptTexture.render( ( WINDOW_WIDTH - gPausePromptTexture.getWidth() ) / 2, gStartPromptTexture.getHeight() );
				gTimeTextTexture.render( ( WINDOW_WIDTH - gTimeTextTexture.getWidth() ) / 2, ( WINDOW_HEIGHT - gTimeTextTexture.getHeight() ) / 2 );
            cloud_rect.x += 1;
            if (cloud_rect.x >= WINDOW_WIDTH)
                cloud_rect.x = 0;
            frameTime++;
            if (FPS / frameTime == 1)
            {
                frameTime = 0;
                src_l2b.x += f1W;
                if (src_l2b.x+f1W >= tx1W)
                    src_l2b.x = 0;
            }
         //   SDL_RenderClear(rend);
            SDL_SetRenderDrawColor(rend,0,255, 0x00, 0x00);
            SDL_RenderCopy(rend, cloud, NULL, &cloud_rect);
            SDL_RenderCopy(rend, l2boy, &src_l2b, &dest_l2b);
            SDL_RenderPresent(rend);
        }
    }
  close();
    return 0;
}