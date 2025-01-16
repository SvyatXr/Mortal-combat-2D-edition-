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

//!GetAsyncKeyState(VK_ESCAPE)
int main()
{
txCreateWindow (1370, 710);
txTextCursor (false);




string PAGE = "menu";




Button btn1 = {10, 80, 220, 150, "������", true};
Button btn2 = {10, 530, 220, 150, "�����", true};
Button btn3 = {10, 380, 220, 150, "� ����", true};
Button btn4 = {10, 230, 220, 150, "���������", true};

   while(!btn2.click())
    {
     txClear();
     txBegin();

    if(PAGE == "menu")
    {

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
         PAGE="���������";
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        txSetFillColor (TX_BLACK);
        txSelectFont ("Arial", 40);
        txSetColor(TX_YELLOW);
        txTextOut(20, 30, "Mortal combat 2D edition");

    }


     if(PAGE == "���������")
     {
      txSetFillColor(TX_BLACK);
      txSelectFont ("Arial", 35);
      txTextOut(600, 20, "���������");
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
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_LIGHTGREEN);
     }

     if(PAGE == "������")
     {
      txSetFillColor(TX_BLACK);
      txSelectFont ("Arial", 35);
      txTextOut(600, 20, "��������...");
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_YELLOW);
     }



     txEnd();
     txSleep(10);


    }
txDisableAutoPause();
return 0;
}

