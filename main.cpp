#include <allegro.h>
#include "inicia.h"

BITMAP  *buffer;
BITMAP  *p1;
BITMAP  *p2;
BITMAP  *p3;
BITMAP  *p4;
BITMAP  *p5;
BITMAP  *c1;
BITMAP  *c2;
BITMAP  *c3;
BITMAP  *c4;
BITMAP  *c5;
BITMAP  *e1;
BITMAP  *e2;
BITMAP  *e3;
BITMAP  *e4;
BITMAP  *e5;
BITMAP  *q1;
BITMAP  *q2;
BITMAP  *q3;
BITMAP  *q4;
BITMAP  *q5;
BITMAP  *correcto;
BITMAP  *incorrecto;
BITMAP  *inicio;
int x = 0;
int y = 0;




int random(int max)
{
    int n;
    srand(time(NULL));
    n = rand();
    return n%max;
}

void respuesta(int correcta)
{
    int val;
    while(keypressed())
    readkey();
    val = readkey();

    if( (val >> 8) == correcta)
       blit(correcto,screen,0,0,x,y,640,480);
    else
       blit(incorrecto,screen,0,0,x,y,640,480);
}


void pregunta_aleatoria(BITMAP *preg1,BITMAP *preg2,BITMAP *preg3,BITMAP *preg4,BITMAP *preg5)
{
    int ran = (random(5)+1);
    if(ran == 1)
    {
        rest(0);
         blit(preg1,screen,0,0,x,y,640,480);
         respuesta(KEY_C);
    }
    if(ran == 2)
    {
        rest(0);
         blit(preg2,screen,0,0,x,y,640,480);
         respuesta(KEY_A);
    }
    if(ran == 3)
    {
        rest(0);
         blit(preg3,screen,0,0,x,y,640,480);
         respuesta(KEY_B);
    }
    if(ran == 4)
    {
        rest(0);
         blit(preg4,screen,0,0,x,y,640,480);
         respuesta(KEY_B);
    }
    if(ran == 5)
    {
        rest(0);
         blit(preg5,screen,0,0,x,y,640,480);
         respuesta(KEY_A);
    }
}
void aleatorio()
{
if(key[KEY_ENTER])
 {
    int r = (random(4)+1);
    if(r == 1)
        {
         pregunta_aleatoria(c1,c2, c3,c4, c5);
        }
    if(r == 2)
        {
         pregunta_aleatoria(p1,p2,p3,p4, p5);
        }
    if(r == 3)
    {
         pregunta_aleatoria(q1,q2, q3,q4, q5);
        }
    if(r == 4)
    {
         pregunta_aleatoria(e1,e2, e3,e4, e5);
        }
 }
}

void jugar()
{
    blit(inicio,screen, 0,0,x,y,640,480);
    while(!key[KEY_ESC])
    {
    aleatorio();
    }

}


int main()
{

inicia_allegro(640, 480);
buffer = create_bitmap(640,480);
clear_to_color(buffer,0xFFFFFF);
p1 = load_bitmap("images/pack1/p1.bmp",NULL);
p2 = load_bitmap("images/pack1/p2.bmp",NULL);
p3 = load_bitmap("images/pack1/p3.bmp",NULL);
p4 = load_bitmap("images/pack1/p4.bmp",NULL);
p5 = load_bitmap("images/pack1/p5.bmp",NULL);
c1 = load_bitmap("images/pack2/c1.bmp",NULL);
c2 = load_bitmap("images/pack2/c2.bmp",NULL);
c3 = load_bitmap("images/pack2/c3.bmp",NULL);
c4 = load_bitmap("images/pack2/c4.bmp",NULL);
c5 = load_bitmap("images/pack2/c5.bmp",NULL);
e1 = load_bitmap("images/pack3/e1.bmp",NULL);
e2 = load_bitmap("images/pack3/e2.bmp",NULL);
e3 = load_bitmap("images/pack3/e3.bmp",NULL);
e4 = load_bitmap("images/pack3/e4.bmp",NULL);
e5 = load_bitmap("images/pack3/e5.bmp",NULL);
q1 = load_bitmap("images/pack4/q1.bmp",NULL);
q2 = load_bitmap("images/pack4/q2.bmp",NULL);
q3 = load_bitmap("images/pack4/q3.bmp",NULL);
q4 = load_bitmap("images/pack4/q4.bmp",NULL);
q5 = load_bitmap("images/pack4/q5.bmp",NULL);
        correcto = load_bitmap("images/correcto.bmp",NULL);
        inicio = load_bitmap("images/inicio.bmp",NULL);
        incorrecto = load_bitmap("images/incorrecto.bmp",NULL);
        blit(buffer,screen, 0,0,0,0,1200,600);
jugar();

destroy_bitmap(buffer);
destroy_bitmap(p1);
destroy_bitmap(p2);
destroy_bitmap(p3);
destroy_bitmap(p4);
destroy_bitmap(p5);
destroy_bitmap(c1);
destroy_bitmap(c2);
destroy_bitmap(c3);
destroy_bitmap(c4);
destroy_bitmap(c5);
destroy_bitmap(e1);
destroy_bitmap(e2);
destroy_bitmap(e3);
destroy_bitmap(e4);
destroy_bitmap(e5);
destroy_bitmap(q1);
destroy_bitmap(q2);
destroy_bitmap(q3);
destroy_bitmap(q4);
destroy_bitmap(q5);
destroy_bitmap(correcto);
destroy_bitmap(incorrecto);
destroy_bitmap(inicio);

return 0;
}
END_OF_MAIN();

