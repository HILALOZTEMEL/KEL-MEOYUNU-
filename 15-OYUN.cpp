#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> 
#include<unistd.h>
/*1] 4,5,6,7,8,9,10 harfli kelime dosyalar� ve bu kelimelerin soru dosyalar�n� olu�turdum.
  2]1.level dosyas�nda 10 tane 4 harfli kelime bulunmaktad�r
  3]1.level_sorulari dosyas�nda 1.level dosyas�ndaki kelimelerin sorular� bulunmaktad�r.
  4]Oyun kuralar�n� ifade eden "void oyun_kurallari();" fonksiyonunu tan�mlad�m.Her soru ba�lang�c�nda �a��r�yorum.
  5]dosyadan rastgele veri okumak ad�na "void random_sayi_(int arrayx[2]);" fonksiyonunu olu�turdum.
  6]"void oyun_kurallari();"fonksiyonuna g�re oyunumu yazmaya baslad�m.
  
  */
void oyun_kurallari();
void random_sayi_(int arrayx[2]);//dosyan�n i�inden rastgele veri okumak i�in
void random_sayi_oyunbiricin(int array[3]);//4 harfli kelimelerden rastgele bir harf okumak i�in
void random_sayi_oyunikinci(int array1[4]);//5 harfli kelimelerden rastgele bir harf okumak i�in
void random_sayi_oyunucuncu(int array2[5]);//6 harfli kelimelerden rastgele bir harf okumak i�in
void random_sayi_oyundort(int array3[6]);//7 harfli kelimelerden rastgele bir harf okumak i�in
void random_sayi_oyunbes(int array4[7]);//8 harfli kelimelerden rastgele bir harf okumak i�in
void random_sayi_oyunalticin(int array5[8]);//9 harfli kelimelerden rastgele bir harf okumak i�in
void random_sayi_oyunyedicin(int array6[9]);//10 harfli kelimelerden rastgele bir harf okumak i�in
int main(){
        oyun_kurallari();
        system("COLOR b");//g�rsel g�r�n�m ad�na,t�m yaz�lar�n mavi olmas� i�in
        printf("\n\n\n*_*_*_*OYUNA BA�LAMAK ���N ENTER a BASINIZ*_*_*_*");
	    getch();
	    system("COLOR f");//g�rsel g�r�n�m ad�na,t�m yaz�lar�n parlak beyaz olmas� i�in
	
		int  k,result,totalPuan=0,say,dongu;
	    char harf_alma[5]={"harf"};
	    
	    float total_s;
	    char cevap[10];
	    int array[3],array1[4],array2[5],array3[6],array4[7],array5[8],array6[9],arrayx[2];
        //s�reyi ba�latt�m.
		clock_t t0 = clock();
	    FILE *oyun_bir,*oyun_bir_soru;
    	//dosyadan okunacak de�erler i�in dizi tan�mlad�m
	    char birinci_level[4];
	    char birinci_level_soru[130];
	    
	    
	    say=0;
	    dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunbiricin(array);
	    //4 harfli kelimelerden iki tanesini nin sorular� ve kelimelri ekrana getirmek i�in i�in for loop 
		for(int a=0;a<2;a++){
		//dosyadan okuma yapt�m
		oyun_bir = fopen("1.level.txt", "r"); 
	    oyun_bir_soru=fopen("1.level_sorulari.txt", "r");
	     //z=10 ��nk� dosyalar�n i�inde 10 ar tane eleman var
	    for(int z=0;z<10;z++){
	    //dosyadan veri z nin artmas�na ba�l� olarak dosyadan s�rayla okur
	    fscanf(oyun_bir,"%s ",&birinci_level);
	    fgets(birinci_level_soru,129,oyun_bir_soru);
		  //"void random_sayi_(int arrayx[2]);" fonksiyonunu dosyadan random veri okumak ad�na yazm��t�m.
		  //�retile random sayi z ye esit ise i�lem yap�lmaya devam eder b�ylece dosyadan veriyi random olarak okumu� oldum
	      if(arrayx[say]==z&&dongu!=2){
		  say++;
		  dongu++;
	    	int sayac=0;
	    	printf("\n\n");
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(birinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
			printf("D�RT HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(birinci_level_soru);
		    printf("         ");
		    int point;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		  if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(birinci_level,cevap);
		  if(result==0)
		  {point+=400;//kelime 4 harfli ise 400 puan al�r.
		  totalPuan+=point;
		  printf("\nTEBR�KLER  %d  puan    ",point);
		  sleep(2);//2 saniye sonra system("cls"); ile ekran� temizler
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else if(result1==0)
		           { 
			    if(sayac!=3){
	           //"array[sayac]" � "void random_sayi_oyunbiricin(int array[3]);" fonksiyonundan ald�m.
			   int c=array[sayac];
                sayac++;
	            point-=100; //yanl�� ise 4 harflik kelimenin al�nan her harfi i�in  -100 puan al�r
	           printf("         ");
				for(int i=0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=birinci_level[c];
			    }printf("%c ",bulunan_harfler[i]);  
			   } printf("    point %d",point);
			     if(sayac==3){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
}
} 
}	   
		    
			//oyun_bir ve oyun_bir_soru dosyas�n� kapatt�m
			fclose(oyun_bir);
			fclose(oyun_bir_soru);
			//1. oyun bitimindeki total s�reyi hesaplattim.
	    clock_t t1 = clock();
	    total_s=(420-((double)(t1 - t0)/CLOCKS_PER_SEC));
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
			
			  
			
				//ikinci oyun
		FILE *oyun_iki,*oyun_iki_soru;
		char ikinci_level[5];
	    char ikinci_level_soru[137];
	    
		       
	    say=0;
	    dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunikinci(array1);
		for(int a=0;a<2;a++){
	    oyun_iki = fopen("2.level.txt", "r"); 
	    oyun_iki_soru=fopen("2.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    
	    fscanf(oyun_iki,"%s ",&ikinci_level);
	    fgets(ikinci_level_soru,137,oyun_iki_soru);

	     //4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  
		  say++;
		  dongu++;
	    	
	    	int sayac=0;
	    	printf("\n\n");
	    	//dosyadan okunacak de�erleri dizi i�ine att�m
	    	
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(ikinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("BE� HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(ikinci_level_soru);
		    printf("         ");
		    int point;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  
		  point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		 if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		   printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(ikinci_level,cevap);
		  if(result==0)
		  {point+=500;
		  totalPuan+=point;
		  printf("\n\n\nTEBR�KLER  %d  puan    ",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		 printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else
		       if(result1==0)
		      { 
	           //yanl�� ise 4 harflik kelimenin her harfi i�in -100 puan al�r
			    if(sayac!=4){
			    
			    int c=array1[sayac];
                sayac++;
                point-=100;
                printf("      ");
				for(int i=0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=ikinci_level[c];
			    }printf("%c ",bulunan_harfler[i]); 
				 
			   }printf("    point %d",point);
			     if(sayac==4){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
}
}
  //oyun iki dosyas�n� kapatt�m
	    fclose(oyun_iki);
		fclose(oyun_iki_soru);
		
		clock_t t2 = clock();
		total_s-=((double)(t2 - t1)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
		
		FILE *oyun_uc,*oyun_uc_soru;
    	//dosyadan okunan de�erleri birer dizi i�inde tuttum
	    char ucuncu_level[6];
	    char ucuncu_level_soru[101];
	    
	    
	    
	    // 4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	    say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunucuncu(array2);
		for(int a=0;a<2;a++){
		//dosyadan okuma yapt�m
	    oyun_uc = fopen("3.level.txt", "r"); 
	    oyun_uc_soru=fopen("3.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    
	    fscanf(oyun_uc,"%s ",&ucuncu_level);
	    fgets(ucuncu_level_soru,100,oyun_uc_soru);
		
	    // 4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  dongu++;
		  say++;
	    	int sayac=0;
	    	printf("\n\n");
	    	//dosyadan okunacak de�erleri dizi i�ine att�m
	    	
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(ucuncu_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("ALTI HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(ucuncu_level_soru);
		    printf("         ");
		   
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		  if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(ucuncu_level,cevap);
		  if(result==0)
		  {point+=600;
		  totalPuan+=point;
		 
		  printf("\n\n\nTEBR�KLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else
		       if(result1==0)
		      { 
		       
			   
			    if(sayac!=5){
	           //yanl�� ise 6 harflik kelimenin her harfi i�in -100 puan al�r
	          
			   int c=array2[sayac];
                sayac++;
                point-=100;
                printf("      ");
				for(int i=0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=ucuncu_level[c];
			    }printf("%c ",bulunan_harfler[i]);  
			   }printf("    point %d",point);
			     if(sayac==5){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	} }}
	    fclose(oyun_uc);
		fclose(oyun_uc_soru);
		
		clock_t t3 = clock();
		total_s-=((double)(t3 - t2)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
		
			FILE *oyun_dort,*oyun_dort_soru;
    	//dosyadan okunan de�erleri birer dizi i�inde tuttum
	    char dorduncu_level[7];
	    char dorduncu_level_soru[106];
	    //dosyadan okuma yapt�m
	    
	    
	     //4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	    say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyundort(array3);
		for(int a=0;a<2;a++){
		oyun_dort = fopen("4.level.txt", "r"); 
	    oyun_dort_soru=fopen("4.level_sorulari.txt", "r");
	     
	    for(int z=0;z<10;z++){
	    
	    //dosyadan okunacak de�erleri dizi i�ine att�m
	    	//dosyadan okunacak de�erleri dizi i�ine att�m
	    fscanf(oyun_dort,"%s ",&dorduncu_level);
	    fgets(dorduncu_level_soru,106,oyun_dort_soru);
	
	     //4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  dongu++;
	      say++;
	    	int sayac=0;
	    	printf("\n\n");
	    
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(dorduncu_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("YED� HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(dorduncu_level_soru);
		    printf("         ");
		    
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		  if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(dorduncu_level,cevap);
		  if(result==0)
		  {point+=700;
		  totalPuan+=point;
		  printf("\n\n\nTEBR�KLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else if(result1==0)
		           { 
			    if(sayac!=6){
	           //yanl�� ise 4 harflik kelimenin her harfi i�in -100 puan al�r
	           
			   int c=array3[sayac];
                sayac++;
	                point-=100;
	                printf("      ");
				for(int i =0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=dorduncu_level[c];
			    }printf("%c ",bulunan_harfler[i]);  
			   }printf("    point %d",point);
			     if(sayac==6){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
}}
	   //oyun_bir ve oyun_bir_soru dosyas�n� kapatt�m
		fclose(oyun_dort);
		fclose(oyun_dort_soru);
		clock_t t4 = clock();
		total_s-=((double)(t4 - t3)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
       
        FILE *oyun_bes,*oyun_bes_soru;
		char besinci_level[8];
	    char besinci_level_soru[61];
	    
		    say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunbes(array4);
		for(int a=0;a<2;a++){
	     oyun_bes = fopen("5.level.txt", "r"); 
	    oyun_bes_soru=fopen("5.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    
	    //dosyadan okunacak de�erleri dizi i�ine att�m
	    	fscanf(oyun_bes,"%s ",&besinci_level);
	        fgets(besinci_level_soru,62,oyun_bes_soru);
	
	     //4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  dongu++;
	      say++;
	    	int sayac=0;
	    	printf("\n\n");
	    	
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(besinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("SEK�Z HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(besinci_level_soru);
		    printf("         ");
		    
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		 if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(besinci_level,cevap);
		  if(result==0)
		  {point+=800;
		  totalPuan+=point;
		  printf("\n\n\nTEBR�KLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else
		       if(result1==0)
		      { 
	           //yanl�� ise 4 harflik kelimenin her harfi i�in -100 puan al�r
			    if(sayac!=7){
			    
			    int c=array4[sayac];
                sayac++;
                point-=100;
                printf("      ");
				for(int i =0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=besinci_level[c];
			    }printf("%c ",bulunan_harfler[i]); 
				 
			   }
			     if(sayac==7){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}}}
  //oyun iki dosyas�n� kapatt�m
	    fclose(oyun_bes);
		fclose(oyun_bes_soru);
		
	    clock_t t5 = clock();
		total_s-=((double)(t5 - t4)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
		//Alt�nc� oyun
	FILE *oyun_alti,*oyun_alti_soru;
    	//dosyadan okunan de�erleri birer dizi i�inde tuttum
	    char altinci_level[9];
	    char altinci_level_soru[130];
	    //dosyadan okuma yapt�m
	    
	    
	     //4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	   	say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunalticin(array5);
		for(int a=0;a<2;a++){
	     oyun_alti = fopen("6.level.txt", "r"); 
	    oyun_alti_soru=fopen("6.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    	//dosyadan okunacak de�erleri dizi i�ine att�m
	    	fscanf(oyun_alti,"%s ",&altinci_level);
	        fgets(altinci_level_soru,129,oyun_alti_soru);
		
	     //4 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
	      say++;dongu++;
	    	int sayac=0;
	    	printf("\n\n");
	    	
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(altinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("DOKUZ HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(altinci_level_soru);
		    printf("         ");
		    //harfalmada=0;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  
		  
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		  //result=0 ise dogrudur
		  if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(altinci_level,cevap);
		  if(result==0)
		  {point+=900;
		  totalPuan+=point;
		  printf("\n\n\nTEBR�KLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else if(result1==0)
		           { 
			    if(sayac!=8){
	           //yanl�� ise 4 harflik kelimenin her harfi i�in -100 puan al�r
	           
			   int c=array5[sayac];
                sayac++;
	                point-=100;
	                printf("      ");
				for(int i =0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=altinci_level[c];
			    }printf("%c ",bulunan_harfler[i]);  
			   }printf("    point %d",point);
			     if(sayac==8){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
}
}
	   //oyun_bir ve oyun_bir_soru dosyas�n� kapatt�m
		fclose(oyun_alti);
		fclose(oyun_alti_soru);
		
		clock_t t6 = clock();
		total_s-=((double)(t6 - t5)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
		
			FILE *oyun_yedi,*oyun_yedi_soru;
    	//dosyadan okunan de�erleri birer dizi i�inde tuttum
	    char yedinci_level[10];
	    char yedinci_level_soru[69];
	   
	    
	     //10 harfli kelimelerden iki tanesini ni sorular� ile sordurma ki�in for loop 
	   	say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunyedicin(array6);
		for(int a=0;a<2;a++){
			 //dosyadan okuma yapt�m
	    oyun_yedi = fopen("7.level.txt", "r"); 
	    oyun_yedi_soru=fopen("7.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    //dosyadan okunacak de�erleri dizi i�ine att�m
	    	fscanf(oyun_yedi,"%s ",&yedinci_level);
	        fgets(yedinci_level_soru,70,oyun_yedi_soru);
	      if(arrayx[say]==z&&dongu!=2){
	      say++;dongu++;
	    	int sayac=0;
	    	printf("\n\n");
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(yedinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("ON HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(yedinci_level_soru);
		    printf("         ");
		     int point;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		  //result=0 ise dogrudur
		  if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(yedinci_level,cevap);
		  if(result==0)
		  {point+=1000;
		  totalPuan+=point;
		  printf("\nTEBR�KLER  %d  puan    ",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else if(result1==0)
		           { 
			    if(sayac!=9){
	           //yanl�� ise 4 harflik kelimenin her harfi i�in -100 puan al�r
	           
			   int c=array6[sayac];
                sayac++;
	                point-=100;
	                printf("      ");
				for(int i =0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=yedinci_level[c];
			    }printf("%c ",bulunan_harfler[i]);  
			   }printf("    point %d",point);
			     if(sayac==9){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
	 }
	 }  //oyun_bir ve oyun_bir_soru dosyas�n� kapatt�m
		fclose(oyun_yedi);
		fclose(oyun_yedi_soru);
		
	clock_t t7 = clock();
		total_s-=((double)(t7 - t6)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
       int fazlasure;
       if(total_s<0){
       	fazlasure=total_s/60;
       	totalPuan+=(fazlasure*100);
	   }
	   
        printf("\n\n*_*_*_*oyun sonu*_*_*_*\n\n TOPLAM OYUN SKORUNUZ = %d",totalPuan);
   
   
   
	  return 0;
	   }
	   void oyun_kurallari(){
	   	setlocale(LC_ALL, "Turkish");
        printf("\n************************************************\n");
        printf("*.*.*.*.*.*KEL�ME OYUNUNA HOSGELD�N�Z*.*.*.*.*.*\n");
        printf("************************************************\n");
        printf("    OYUN KURALLARI\n\n");
        printf("  1]D�rt harfli kelimeler 400 puan\n  2]Be� harfli kelimeler 500 puan\n  3]Alt� harfli kelimeler 600 puan\n  4]Yedi harfli kelimeler 700 puan\n  5]Sekiz harfli kelimeler 800 puan\n  6]Dokuz harfli kelimeler 900 puan\n  7]On harfli kelimeler 1000 puan d�r.\n  8]Harf almak i�in  harf  yaz�n�z\n  9]Al�nan her harf -100 puand�r.\n  10]S�re a��m�nda her dk ba��na -100 puan.\n 11]Pas hakk�n�z� kullanmak i�in p'ye bas�n�z. ");
	    printf("\n\t\t\t\t\t\t\tAD=H�LAL �ZTEMEL OGR_NO=191141016");
		printf(" \n \n   TOPLAM S�REN�Z 420 Saniye (7 dakika)'dir  ");
	    
	   	return ;
	   }
	   
void random_sayi_(int arrayx[2]){
int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<2;count++){
arrayx[count]=rand()%10;
}

while(i<2){
    int r=rand()%10;
    
    for (x = 0; x < i; x++)
    {
        if(arrayx[x]==r){
            break;
        }
    }
    if(x==i){
        arrayx[i++]=r;
    }
    
}
	   	return;	
}
void random_sayi_oyunbiricin(int array[3]){
	   	

int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<3;count++){
array[count]=rand()%4;
}

while(i<3){
    int r=rand()%4;
    
    for (x = 0; x < i; x++)
    {
        if(array[x]==r){
            break;
        }
    }
    if(x==i){
        array[i++]=r;
    }
    
}
	   	return;
	   }
void random_sayi_oyunikinci(int array1[4]){
	int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<4;count++){
array1[count]=rand()%5;
}

while(i<4){
    int r=rand()%5;
    
    for (x = 0; x < i; x++)
    {
        if(array1[x]==r){
            break;
        }
    }
    if(x==i){
        array1[i++]=r;
    }
    
}


	   	return;
	   }
void random_sayi_oyunucuncu(int array2[5]){
	int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<5;count++){
array2[count]=rand()%6;
}

while(i<5){
    int r=rand()%6;
    
    for (x = 0; x < i; x++)
    {
        if(array2[x]==r){
            break;
        }
    }
    if(x==i){
        array2[i++]=r;
    }
    
}

	return;
}
void random_sayi_oyundort(int array3[6]){
int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<6;count++){
array3[count]=rand()%7;
}

while(i<6){
    int r=rand()%7;
    
    for (x = 0; x < i; x++)
    {
        if(array3[x]==r){
            break;
        }
    }
    if(x==i){
        array3[i++]=r;
    }
    
}

	return;
}
void random_sayi_oyunbes(int array4[7]){
	int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<7;count++){
array4[count]=rand()%8;
}

while(i<7){
    int r=rand()%8;
    
    for (x = 0; x < i; x++)
    {
        if(array4[x]==r){
            break;
        }
    }
    if(x==i){
        array4[i++]=r;
    }
    
}

	return;
}
void random_sayi_oyunalticin(int array5[8]){
	int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<8;count++){
array5[count]=rand()%9;
}

while(i<8){
    int r=rand()%9;
    
    for (x = 0; x < i; x++)
    {
        if(array5[x]==r){
            break;
        }
    }
    if(x==i){
        array5[i++]=r;
    }
    
}

	return;
}
void random_sayi_oyunyedicin(int array6[9]){
	int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<9;count++){
array6[count]=rand()%10;
}

while(i<9){
    int r=rand()%10;
    
    for (x = 0; x < i; x++)
    {
        if(array6[x]==r){
            break;
        }
    }
    if(x==i){
        array6[i++]=r;
    }
    
}

	return;
}
