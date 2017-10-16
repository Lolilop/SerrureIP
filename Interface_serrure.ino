#include <stdint.h>
#include <TFTv2.h>
#include <SPI.h>
#include <SeeedTouchScreen.h>
#include <Password.h>

TouchScreen ts = TouchScreen(XP, YP, XM, YM);

Password passwordC = Password( "1234" ); // Civils
Password password1A = Password( "1111" );     // Admin

int Continue = 0; //apres pression
int Bienvenu_Continue = 0;
int Ajout_Etoils =0;
int Loop_Admin = 0;
int Exist = 0;
int Code_Faux = 0;
int Go_Verification = 0;
int i = 0;



void setup() {

  Serial.begin(9600); //Verifie

  TFT_BL_ON;
  Tft.TFTinit();

}

void loop() {

MenuPrincipale(); // Affichage Menu acceuille


  passwordC.reset();  //reset MDP
  password1A.reset();


  clavier(); // Affichage Clavier

  while ( i <= 3)
  {

    clavier(); // Affichage Clavier
    toucheClavier(); //Tactile clavier

    if (Go_Verification >= 4 ) //Condition nombre de touches >= à 4 regarder si MDP est bon
    {
      
      Verification(); 
  }


      
}
        i = 0;
     
      Go_Verification = 0;
       Bienvenu_Continue = 0;
Continue = 0; //apres pression
Ajout_Etoils = 0;
Loop_Admin = 0;
Exist = 0;
Code_Faux = 0;

}


void MenuPrincipale()
{

while(  Bienvenu_Continue <= 0)
{
    Tft.drawString("BIENVENU", 30, 10, 4, WHITE);
   Tft.drawString("Appuiyer", 70, 135, 2, WHITE);
    Tft.drawString("pour", 90, 165, 2, WHITE);
    Tft.drawString("continuer", 65, 195, 2, WHITE);
    


    toucheAcceuille(); // Attente d'une pression sur l'ecran pour aficher la suite 


    if ( Continue >= 1)
    {
    Tft.TFTinit();
      Tft.drawString("saisissez", 35, 100, 3, WHITE);
      Tft.drawString("Votre Code", 28, 150, 3, WHITE);
      Tft.drawString("PIN", 85, 200, 3, WHITE);
      delay(1000);
      Bienvenu_Continue++;
      






    }
}

    Tft.TFTinit();
    
  
}

void toucheAcceuille() // Zone max prescion
{
 Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);



  if (p.z > __PRESURE and i <= 4)
  {

    if (p.x >=  0 && p.x <= 1000 && p.y >= 0 && p.y <= 1000 )
    {


      Continue++;



    }
  }
}




void clavier()
{

  Tft.drawString("_ _ _ _", 78, 5 , 2, WHITE); // Pour nombre de touche toucher

  Tft.drawNumber(1, 30, 50, 4,  WHITE);
  Tft.drawNumber(2, 100, 50, 4, WHITE); // 1er ligne
  Tft.drawNumber(3, 170, 50, 4, WHITE);

  Tft.drawNumber(4, 30, 115, 4,  WHITE);
  Tft.drawNumber(5, 100, 115, 4 , WHITE); // 2eme lignes
  Tft.drawNumber(6, 170, 115, 4, WHITE);


  Tft.drawNumber(7, 30, 180, 4,  WHITE);
  Tft.drawNumber(8, 100, 180, 4, WHITE); //3eme lignes
  Tft.drawNumber(9, 170, 180, 4, WHITE);

  Tft.drawString("*", 30, 245, 4, WHITE);
  Tft.drawNumber(0, 100, 245, 4,  WHITE);  // 4eme lignes
  Tft.drawString("#", 170, 245, 4, WHITE);




}

void toucheClavier()  //  ZONE pression touche clavier
{

  Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);



  if (p.z > __PRESURE and i <= 4)
  {

    if (p.x >=  0 && p.x <= 60 && p.y >= 30 && p.y <= 70 )
    {


      passwordC.append('1');    // Ajoute x nombre au mpd passwordC && passwordA
      password1A.append('1');

      delay(500);
   



    }

    if (p.x >= 70 && p.x <= 130 && p.y >= 30 && p.y <= 70 )
    {

      password1A.append('2');
      passwordC.append('2');
    
      delay(500);
     
      

    }

    if (p.x >= 140 && p.x <= 200 && p.y >= 30 && p.y <= 70)
    {

     password1A.append('3');
      passwordC.append('3');
   
      delay(500);
     
      


    }

    if (p.x >= 0 && p.x <= 60 && p.y >= 100 && p.y <= 130 )
    {

password1A.append('4');
      passwordC.append('4');
     
      delay(500);
     
      
    }

    if (p.x >= 70 && p.x <= 130 && p.y >= 100 && p.y <= 130 )
    {


      passwordC.append('5');
      password1A.append('5');
      delay(500);
     ;
       

    }

    if (p.x >= 140 && p.x <= 200 && p.y >= 100 && p.y <= 130 )
    {


      passwordC.append('6');
      password1A.append('6');
      delay(500);
     
    }

    if (p.x >= 0 && p.x <= 60 && p.y >= 160 && p.y <= 200 )
    {


      passwordC.append('7');
      password1A.append('7');
      delay(500);
      ;


    }

    if (p.x >= 70 && p.x <= 130 &&  p.y >= 160 && p.y <= 200 )
    {


      passwordC.append('8');
      password1A.append('8');
      delay(500);
     

    }

    if (p.x >= 140 && p.x <= 200 &&  p.y >= 160 && p.y <= 200 )
    {


      passwordC.append('9');
      password1A.append('9');
      delay(500);
      




    }

    if (p.x >= 0 && p.x <= 60 && p.y >= 230 && p.y <= 260 )
    {


      passwordC.append('*');
      password1A.append('*');
      delay(500);
   



    }

    if (p.x >= 70 && p.x <= 130 &&  p.y >= 230 && p.y <= 260 )
    {


      passwordC.append('0');
      password1A.append('0');
         
      delay(500);
    
      

    }


    if (p.x >= 140 && p.x <= 200 &&  p.y >= 230 && p.y <= 260 )
    {


      passwordC.append('#');
      password1A.append('#');
      delay(500);
      

    }
   Ajout_Etoils++;
      i++;
      Go_Verification++;
      Etoiles(); // Appelle representation etoile
      delay(500);

  }
}


void Etoiles() // Ajoute des etoiles
{
  if ( Ajout_Etoils == 1) // SI n est egale à ...
  {
    Tft.drawString("*", 78, 4, 2, WHITE);


  }

  if (Ajout_Etoils == 2)
  {
    Tft.drawString("*", 78, 4, 2, WHITE);
    Tft.drawString("*", 102, 4, 2, WHITE);

  }

  if (Ajout_Etoils == 3)
  {
    Tft.drawString("*", 78, 4, 2, WHITE);
    Tft.drawString("*", 102, 4, 2, WHITE);
    Tft.drawString("*", 126, 4, 2, WHITE);

  }

  if (Ajout_Etoils == 4)
  {
    Tft.drawString("*", 78, 4, 2, WHITE);
    Tft.drawString("*", 102, 4, 2, WHITE);
    Tft.drawString("*", 126, 4, 2, WHITE);
    Tft.drawString("*", 149, 4, 2, WHITE);
    

  }


}






void Verification() //Verifie si les MDP sont bon
{


  
  if (passwordC.evaluate()) { //si civil est bon 

    Tft.TFTinit();
    Tft.drawString("CODE BON", 20, 150, 4, WHITE);
    delay(500);
    Tft.TFTinit();

    //CODE OUVERTURE PORTE

    Tft.drawString("OUVERTURE ", 10, 150, 4, WHITE);
    Tft.drawString("PORTE", 50, 200, 4, WHITE);
    Code_Faux =-1;

    delay(5000);
   
    Tft.TFTinit();
    
   
   

 }

   if (password1A.evaluate()){
 Tft.TFTinit();  
while( Loop_Admin <= 1)
{
 Menu_Admin();
 Code_Faux = -1;
 

 
}
}
  
if(Code_Faux == 0)

{
  Tft.TFTinit();
  Tft.drawString("CODE ", 70, 100, 4, WHITE);
  Tft.drawString("FAUX ", 70, 140, 4, WHITE);
  Tft.TFTinit();
}

}


void Menu_Admin() {

  
 
  Tft.drawRectangle(0, 30, 300,65,WHITE);
  Tft.drawRectangle(0, 130, 300,65,WHITE);
  Tft.drawRectangle(0, 230, 300,65,WHITE);

  Tft.drawString("CHANGER",45,30,3,WHITE);
  Tft.drawString("CODE",60,65,3,WHITE);
  Tft.drawString("OUVERTURE",10,150,4,WHITE);
  Tft.drawString("RETOUR",45,250,4,WHITE);

  toucheCHOIX();
 
 
}

void toucheCHOIX()
{

  Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);




if (p.z > __PRESURE and i <= 4)
  {
    if (p.x >=  0 && p.x <= 300  && p.y >= 0 && p.y <= 80 )
    {
       
  Tft.TFTinit();
 



    }
     if (p.x >=  0 && p.x <= 300  && p.y >= 90 && p.y <= 180  )
    {

Tft.TFTinit();
     Tft.drawString("OUVERTURE ", 10, 150, 4, WHITE);
  Tft.drawString("PORTE", 50, 200, 4, WHITE);
  delay(5000);

  Tft.TFTinit();



   
  

  
  
    }
     if (p.x >=  0 && p.x <= 300  && p.y >= 190 && p.y <= 300  )
    {
Tft.TFTinit();
 
Tft.fillRectangle(30, 170, 65,60,WHITE);
  Tft.fillRectangle(145, 170, 65,60,WHITE);


   while(Exist <= 1)

   
{
 Tft.drawString("ETEZ-VOUS ", 10, 10, 4, WHITE);
  Tft.drawString("SUR", 70, 50, 4, WHITE);

  Tft.drawString("OUI ", 35, 185, 3, BLACK);
  Tft.drawString("NON ", 150, 185, 3, BLACK);
  toucheOUINON();
  
  
  
}
  Exist=0;
  Loop_Admin++;
  Tft.TFTinit();
 
   


    }
  }
}

void toucheOUINON() // Zone max prescion
{

  Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);



  if (p.z > __PRESURE and i <= 4)
  {

    if (p.x >=  0 && p.x <= 70 && p.y >= 150 && p.y <= 200 )
    {


      Exist++;
      Loop_Admin++;



    }

    if(p.x >=  115 && p.x <= 185 && p.y >= 150 && p.y <= 200) 
    {
      Exist++;
      
    }
  }
}


