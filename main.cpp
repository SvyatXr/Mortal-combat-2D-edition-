#include "TXLib.h"

struct Button
{

    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool visible;

   void draw()
   {
     txSetColor (TX_WHITE, 3);
     txSetFillColor (TX_RED);
     Win32::RoundRect(txDC(), x, y, x+w, y+h, 30, 30);
     txSelectFont("Areal", 35);
     txDrawText(x, y, x+w, y+h, text);
    }

  bool click()
  {
   return (txMouseX()>x && txMouseX()<x+w && txMouseY()>y && txMouseY()<y+h && txMouseButtons() == 1 && visible);
}


};

struct Mario
{
    int x;
    int y;
    int w;
    int h;
    HDC stop;
    HDC run;
    HDC jump;
    HDC hit;
    HDC image;
    int n_cadr;
    int healthy;


   void draw()
   {
        txTransparentBlt(txDC(), x, y, w, h, image, n_cadr*100, 0, TX_WHITE);
   }
};

void drawProgressBar(int x)
{
    txSetColor(TX_BLUE);
    txSetFillColor(TX_BLUE);
    txCircle(x, 300, 50);
}



//!GetAsyncKeyState(VK_ESCAPE)
int main()
{
txCreateWindow (1370, 710);
txTextCursor (false);

string PAGE = "menu";

HDC image_mario = txLoadImage("Images\\�����.bmp");
HDC image_AJY = txLoadImage("Images\\��� ����.bmp");
int xProgressBar = 100;

Button btn1 = {10, 80, 220, 150, "������", true};
Button btn2 = {10, 530, 220, 150, "�����", true};
Button btn3 = {10, 380, 220, 150, "�� ����", true};
Button btn4 = {10, 230, 220, 150, "�������", true};

int n_cadr = 0;

Mario mario = { 100, 500, 100, 108,
                txLoadImage("Images/left_stop.bmp"),
                txLoadImage("Images/left_run.bmp"),
                txLoadImage("Images/left_jump.bmp"),
                txLoadImage("Images/left_hit.bmp"),
                txLoadImage("Images/left_stop.bmp"), 0, 400};


Mario mario1 = { 1170, 500, 100, 108,
                txLoadImage("Images/right_stop.bmp"),
                txLoadImage("Images/right_run.bmp"),
                txLoadImage("Images/right_jump.bmp"),
                txLoadImage("Images/right_hit.bmp"),
                txLoadImage("Images/right_stop.bmp"), 0, 400};


int r = 0;




   while(!btn2.click())
    {
     txClear();
     txBegin();
 //����

    if(PAGE == "menu")
    {
        txPlaySound (NULL);
        xProgressBar=100;
        mario.healthy=400;
        mario1.healthy=400;
        txSetFillColor(TX_ORANGE);
        txRectangle (340, 0, 820, 710);
        txSetColor(TX_LIGHTBLUE);
        txLine (360, 0, 360, 710);
        txLine (380, 0, 380, 710);
        txLine (400, 0, 400, 710);
        txLine (420, 0, 420, 710);
        txLine (440, 0, 440, 710);
        txLine (460, 0, 460, 710);
        txLine (480, 0, 480, 710);
        txLine (500, 0, 500, 710);
        txLine (520, 0, 520, 710);
        txLine (540, 0, 540, 710);
        txLine (560, 0, 560, 710);
        txLine (580, 0, 580, 710);
        txLine (600, 0, 600, 710);
        txLine (620, 0, 620, 710);
        txLine (640, 0, 640, 710);
        txLine (660, 0, 660, 710);
        txLine (680, 0, 680, 710);
        txLine (700, 0, 700, 710);
        txLine (720, 0, 720, 710);
        txLine (740, 0, 740, 710);
        txLine (760, 0, 760, 710);
        txLine (780, 0, 780, 710);
        txLine (800, 0, 800, 710);


        txTransparentBlt(txDC(), 820, 110, 550, 600, image_mario, 0, 0);

        btn1.draw();
        btn2.draw();
        btn3.draw();
        btn4.draw();


        btn1.visible = true;
        btn2.visible = true;
        btn3.visible = true;
        btn4.visible = true;

        if(btn1.click())
        {
         PAGE="������";
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }

        if(btn3.click())
        {
         PAGE="�� ����";
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        if(btn4.click())
        {
         PAGE="�������";
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        txSetFillColor (TX_BLACK);
        txSelectFont ("Arial", 40);
        txSetColor(TX_WHITE);
        txTextOut(15, 30, "Mortal combat 2D edition");

    }


     if(PAGE == "�������")
     {
      txSetFillColor(TX_BLACK);
      txSelectFont ("Arial", 33);
      txDrawText   (100, 0, 1270, 100, "�������");

      txTextOut(25, 100, "1.������ ��� �����.");
      txTextOut(25, 135, "2.�� ����� ���� �� ������ ���������� �������� ������ ��������.");
      txTextOut(25, 170, "3.������ ��� ��������.");
      txTextOut(25, 205, "���� ������������� ����� ����, ��� ���� ����� ��������� �������.");

      txDrawText   (100, 250, 1270, 700, "���������� ��� ������ �����: \n"
                                         "A-����� \n"
                                         "D-������ \n"
                                         "S-����� \n"
                                         "W-���� \n"
                                         "���������� ��� ������� �����: \n"
                                         "������� �����-����� \n"
                                         "������� ������-������ \n"
                                         "������� ����-����� \n"
                                         "������� �����-���� \n");

      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_LIGHTBLUE);

     }

     if(PAGE == "�� ����")
     {
      txSetColor(TX_WHITE);
      txSelectFont ("Arial", 40);
      txTextOut(5, 50, "�����");
      txTextOut(5, 100, "��� ����� ��������� ��-�� ��������� ��� ������� � �������� ������������ ����� �� �������!");
      txSelectFont ("Arial", 50);
      txTextOut(600, 20, "O ����");
      txSelectFont ("Arial", 35);
      txTextOut(5, 150, "��������� ������ ����: <?|?|?|?|?|?|?|?|?|?|?|?|?|?|?|?|?|?|?|?|?>");
      txSelectFont ("Arial", 35);
      txTextOut(5, 200, "������ ���� �� �������� ���������, � ���� ����� ���������");
      txSelectFont ("Arial", 35);
      txTextOut(5, 250, "������� � ������");
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_LIGHTGREEN);
     }

     if(PAGE == "������")
     {
          if(GetAsyncKeyState(VK_ESCAPE))
          {
            PAGE="menu";
          }

          txSetFillColor (TX_LIGHTGRAY);
          txClear();
          txSetFillColor(TX_BLACK);
          txSelectFont ("Arial", 35);
          txTextOut(600, 20, "��������...");

          txSetFillColor (TX_LIGHTGRAY);

          while(xProgressBar<1270)
          {
              drawProgressBar(xProgressBar);
              xProgressBar+=5;
              txSleep(10);
          }

     //����


            txBitBlt(txDC(), 0, 0, 1370, 710, image_AJY);

            //mario.draw();
            mario.image = mario.stop;
            //mario1.draw();
            mario1.image = mario1.stop;

            txSetColor (TX_WHITE, 5);
            txSetFillColor(TX_BLACK);
            txRectangle (50, 50, 450, 75);
            txSetColor (TX_WHITE, 0);
            txSetFillColor(TX_ORANGE);
            txRectangle (50, 50, 50+mario.healthy, 75);


            txSetColor (TX_WHITE, 5);
            txSetFillColor(TX_BLACK);
            txRectangle (870, 50, 870+400, 75);
            txSetColor (TX_WHITE, 0);
            txSetFillColor(TX_ORANGE);
            txRectangle (870, 50, 870+mario1.healthy, 75);



            if(GetAsyncKeyState('1'))
            {
                txPlaySound (NULL);
                txPlaySound ("fite.wav");
            }
            if(GetAsyncKeyState('2'))
            {
                txPlaySound (NULL);
                txPlaySound ("fite2.wav");
            }
            if(GetAsyncKeyState('3'))
            {
                txPlaySound (NULL);
                txPlaySound ("fite3.wav");
            }


            if (GetAsyncKeyState('D'))
            {
                mario.x += 20;
                mario.image = mario.run;
                txSleep(15);
                mario.n_cadr+=1;
                if(mario.n_cadr>1) mario.n_cadr=0;

            }

            if (GetAsyncKeyState('A'))
            {
             mario.x -= 20;

            }

            if (GetAsyncKeyState('S'))
            {
              mario.image = mario.jump;
              mario.y -= 40;

            }

            if (GetAsyncKeyState('W'))
            {
                 mario.image = mario.hit;
                 txSleep(50);
                 mario.n_cadr+=1;
                 if(mario.n_cadr>1) mario.n_cadr=0;
            }

            if(mario.image == mario.hit && mario.x+mario.w>mario1.x && mario.x<mario1.x && mario.y<mario1.y+mario1.h && mario.y+mario.h>mario1.y)
            {
                mario1.healthy -= 10;
            }




            mario.y += 10;

            if(mario.y > 602)
            {
             mario.y = 602;
            }

            if(mario.y < 0)
            {
             mario.y = 0;
            }

            if (mario.x  > 1370-mario.w)
             {
              mario.x = 1370-mario.w;
             }
            if (mario.x < 0)
             {
              mario.x = 0;
             }





            if (GetAsyncKeyState(VK_RIGHT))
            {
                mario1.x += 20;
            }

            if (GetAsyncKeyState(VK_LEFT))
            {
                mario1.x -= 20;
                mario1.image = mario1.run;
                txSleep(15);
                mario1.n_cadr+=1;
                if(mario1.n_cadr>1) mario1.n_cadr=0;

            }

            if (GetAsyncKeyState(VK_DOWN))
            {
              mario1.image = mario1.jump;
              mario1.y -= 40;
            }

            if (GetAsyncKeyState(VK_UP))
            {
             mario1.image = mario1.hit;
             txSleep(50);
             mario1.n_cadr+=1;
             if(mario1.n_cadr>1) mario1.n_cadr=0;
            }
              if(mario1.image == mario1.hit && mario1.x<mario.x+mario.w && mario1.x>mario.x && mario1.y<mario.y+mario.h && mario1.y+mario1.h>mario.y)
            {
                mario.healthy -= 10;
            }

            mario1.y += 10;

            if(mario1.y > 602)
            {
             mario1.y = 602;
            }

            if(mario1.y < 0)
            {
             mario1.y = 0;
            }

            if (mario1.x  > 1370-mario1.w)
             {
              mario1.x = 1370-mario1.w;
             }
            if (mario1.x < 0)
             {
              mario1.x = 0;
             }

             if(mario.healthy<10 || mario1.healthy<10)
             {
               PAGE = "�����";
             }




            if (GetAsyncKeyState('Q'))
            {
                 txCircle(mario.x+mario.w/2, mario.y+mario.h/2, 125);
                 txSleep(20);

                if(mario.x+mario.w/2+125>mario1.x && mario.x+mario.w/2<mario1.x && mario.y<mario1.y+mario1.h && mario.y+ mario.h>mario1.y)
                {
                     mario1.healthy -= 5;
                }
            }
            if (GetAsyncKeyState(VK_SHIFT))
            {
                 txCircle(mario1.x+mario1.w/2, mario1.y+mario1.h/2, 125);
                 txSleep(20);
            }




            mario.draw();
            mario1.draw();
      }

      if(PAGE == "�����")
      {
          if(GetAsyncKeyState(VK_ESCAPE))
          {
            PAGE="menu";
          }

           txSetFillColor (TX_LIGHTGREEN);
           txClear();
           txBegin();
           txSetFillColor(TX_BLACK);
           txSelectFont ("Arial", 35);
           if(mario.healthy<10)
             {
                txTextOut(540, 300, "Mario1 ������� Mario!");
             }
             else if(mario1.healthy<10)
             {
                txTextOut(540, 300, "Mario ������� Mario1!");
             }
           txTextOut(540, 350, "��� ������ ������� Esc");



      }
     txEnd();
     txSleep(10);


    }
txDisableAutoPause();
return 0;
}

