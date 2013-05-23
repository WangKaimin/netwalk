// ��SDL�������������Ͱ�������
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string.h>

typedef enum bool
{
    true,
    false
} bool;

// ��������
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; // λ/����



// ÿ��ʹ��ָ��ʱ���㶼�ü��Ž����ǳ�ʼ��
// SDL_Surface *hello = NULL; // �������ز���ʾ��ͼƬ
SDL_Surface *image = NULL;
// SDL_Surface *background = NULL;
SDL_Surface *screen = NULL; // ��Ļ�ϵĿɼ�����

//��Ҫ�õ����¼��ṹ��
SDL_Event event;

SDL_Surface *load_image(char * filename)
{
    //���ص�ͼ��
    SDL_Surface *loadedImage = NULL;

    //�Ż����ͼ��
    SDL_Surface *optimizedImage = NULL;

    //ʹ��SDL_image����ͼ��
    loadedImage = IMG_Load(filename);
    //loadedImage = SDL_LoadBMP(filename);

    //���ͼ����سɹ�
    if(loadedImage != NULL)
    {
        //����һ���Ż����ͼ��
        optimizedImage = SDL_DisplayFormat(loadedImage);

        //�ͷ�ԭ�ȼ��ص�ͼ��
        SDL_FreeSurface(loadedImage);
    }

    //�����Ż����ͼ��
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    // ��ͼ��Ӧ�õ�������
    SDL_BlitSurface(source, NULL, destination, &offset);
}

bool init()
{
    //��ʼ��SDL��������ϵͳ
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //���ô���
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //������ó���
    if( screen == NULL )
    {
        return false;
    }

    //���ô��ڱ���
    SDL_WM_SetCaption( "Event test", NULL );

    //������г�ʼ���������ɹ�
    return true;
}

bool load_files()
{
    //����ͼ��
    image = load_image( "hello.bmp" );

    //������س���
    if( image == NULL )
    {
        return false;
    }

    //�������ͼƬ��������
    return true;
}

void clean_up()
{
    //�ͷ�ͼ��
    SDL_FreeSurface( image );

    //�˳�SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //ȷ������һֱ�ȴ�quit
    bool quit = false;

    // ��ʼ��
    if(init() == false)
        return 1;

    // �����ļ�
    if( load_files() == false)
        return 1;



    apply_surface( 0, 0, image, screen );

    // ���´���
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }


    //���û��������˳�ʱ
    while( quit == false )
    {
        //�����¼�����ʱ��������Ҫ��������
        while( SDL_PollEvent( &event))
        {
            //����û�����˴������ϽǵĹرհ�ť
            if( event.type == SDL_QUIT )
            {
                //�˳�����
                quit = true;
            }
            else if(event.type == SDL_MOUSEBUTTONUP)
            {
                //�˳�����
                quit = true;
            }
        }
    }

    clean_up();



    // �˳�SDL
    // SDL_Quit();

    return 0;
}
