// 将SDL函数和数据类型包含进来
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string.h>

typedef enum bool
{
    true,
    false
} bool;

// 窗口属性
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; // 位/像素



// 每当使用指针时，你都得记着将它们初始化
// SDL_Surface *hello = NULL; // 即将加载并显示的图片
SDL_Surface *image = NULL;
// SDL_Surface *background = NULL;
SDL_Surface *screen = NULL; // 屏幕上的可见窗口

//将要用到的事件结构体
SDL_Event event;

SDL_Surface *load_image(char * filename)
{
    //加载的图像
    SDL_Surface *loadedImage = NULL;

    //优化后的图像
    SDL_Surface *optimizedImage = NULL;

    //使用SDL_image加载图像
    loadedImage = IMG_Load(filename);
    //loadedImage = SDL_LoadBMP(filename);

    //如果图像加载成功
    if(loadedImage != NULL)
    {
        //创建一个优化后的图像
        optimizedImage = SDL_DisplayFormat(loadedImage);

        //释放原先加载的图像
        SDL_FreeSurface(loadedImage);
    }

    //返回优化后的图像
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    // 将图像应用到窗口上
    SDL_BlitSurface(source, NULL, destination, &offset);
}

bool init()
{
    //初始化SDL的所有子系统
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //设置窗口
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //如果设置出错
    if( screen == NULL )
    {
        return false;
    }

    //设置窗口标题
    SDL_WM_SetCaption( "Event test", NULL );

    //如果所有初始化操作都成功
    return true;
}

bool load_files()
{
    //加载图像
    image = load_image( "hello.bmp" );

    //如果加载出错
    if( image == NULL )
    {
        return false;
    }

    //如果所有图片加载正常
    return true;
}

void clean_up()
{
    //释放图像
    SDL_FreeSurface( image );

    //退出SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //确保程序一直等待quit
    bool quit = false;

    // 初始化
    if(init() == false)
        return 1;

    // 加载文件
    if( load_files() == false)
        return 1;



    apply_surface( 0, 0, image, screen );

    // 更新窗口
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }


    //当用户还不想退出时
    while( quit == false )
    {
        //当有事件发生时，我们需要处理它们
        while( SDL_PollEvent( &event))
        {
            //如果用户点击了窗口右上角的关闭按钮
            if( event.type == SDL_QUIT )
            {
                //退出程序
                quit = true;
            }
            else if(event.type == SDL_MOUSEBUTTONUP)
            {
                //退出程序
                quit = true;
            }
        }
    }

    clean_up();



    // 退出SDL
    // SDL_Quit();

    return 0;
}
