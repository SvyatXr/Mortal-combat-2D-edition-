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
    HDC image;

   void draw()
   {
        txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_WHITE);
       Mario mario = { 100, 250, 100, 80, txLoadImage("M�����_2.bmp"), txLoadImage("M�����_2.bmp")};
   }
   while (!GetAsyncKeyState(VK_ESCAPE))
   {
    txClear();
    txBegin();

    mario.draw();

    if (GetAsyncKeyState(VK_RIGHT))
    {
     mario.x += 5;
    }

    if (GetAsyncKeyState(VK_SPACE))
    {
      mario.image = mario.image_jump;
      mario.y -= 20;
    }

    mario.y += 5;

    if(mario.y > 400)
    {
     mario.y = 400;
    }

    txEnd();
    txSleep(30);
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
Button btn3 = {10, 380, 220, 150, "� ����", true};
Button btn4 = {10, 230, 220, 150, "�������", true};

   while(!btn2.click())
    {
     txBegin();
     txClear();
 //����

    if(PAGE == "menu")
    {
        xProgressBar=100;
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
         PAGE="� ����";
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
      txSelectFont ("Arial", 35);
      txTextOut(600, 20, "�������");
      txTextOut(5, 100, "1.������ ��� �����.");
      txTextOut(5, 150, "2.�� ����� ���� �� ������ ���������� ��� ������ �� ��������� ��������.");
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_LIGHTBLUE);

     }

     if(PAGE == "� ����")
     {
      txSetFillColor(TX_BLACK);
      txSelectFont ("Arial", 35);
      txTextOut(600, 20, "O ����");
      txTextOut(5, 50, "��������� ������ ����: ̸����� ��������");
      txTextOut(5, 100, "������ ���� �� �������� ���������, � ���� ���� ���������");
      txTextOut(5, 150, "������� � ������");
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_LIGHTGREEN);
     }

     if(PAGE == "������")
     {

          txSetFillColor (TX_LIGHTGRAY);
          txClear();
          txSetFillColor(TX_BLACK);
          txSelectFont ("Arial", 35);
          txTextOut(600, 20, "��������...");

          if(GetAsyncKeyState(VK_ESCAPE))
          {
            PAGE="menu";
          }

          txSetFillColor (TX_LIGHTGRAY);

          while(xProgressBar<1170)
          {
              drawProgressBar(xProgressBar);
              xProgressBar+=5;
              txSleep(10);
          }

     //����

        txBitBlt(txDC(), 0, 0, 1370, 710, image_AJY);

        //Color (TX_LIGHTGRAY);

     }



     txEnd();
     txSleep(10);


    }
txDisableAutoPause();
return 0;
}

