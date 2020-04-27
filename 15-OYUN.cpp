#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> 
#include<unistd.h>
/*1] 4,5,6,7,8,9,10 harfli kelime dosyalarý ve bu kelimelerin soru dosyalarýný oluþturdum.
  2]1.level dosyasýnda 10 tane 4 harfli kelime bulunmaktadýr
  3]1.level_sorulari dosyasýnda 1.level dosyasýndaki kelimelerin sorularý bulunmaktadýr.
  4]Oyun kuralarýný ifade eden "void oyun_kurallari();" fonksiyonunu tanýmladým.Her soru baþlangýcýnda çaðýrýyorum.
  5]dosyadan rastgele veri okumak adýna "void random_sayi_(int arrayx[2]);" fonksiyonunu oluþturdum.
  6]"void oyun_kurallari();"fonksiyonuna göre oyunumu yazmaya basladým.
  
  */
void oyun_kurallari();
void random_sayi_(int arrayx[2]);//dosyanýn içinden rastgele veri okumak için
void random_sayi_oyunbiricin(int array[3]);//4 harfli kelimelerden rastgele bir harf okumak için
void random_sayi_oyunikinci(int array1[4]);//5 harfli kelimelerden rastgele bir harf okumak için
void random_sayi_oyunucuncu(int array2[5]);//6 harfli kelimelerden rastgele bir harf okumak için
void random_sayi_oyundort(int array3[6]);//7 harfli kelimelerden rastgele bir harf okumak için
void random_sayi_oyunbes(int array4[7]);//8 harfli kelimelerden rastgele bir harf okumak için
void random_sayi_oyunalticin(int array5[8]);//9 harfli kelimelerden rastgele bir harf okumak için
void random_sayi_oyunyedicin(int array6[9]);//10 harfli kelimelerden rastgele bir harf okumak için
int main(){
        oyun_kurallari();
        system("COLOR b");//görsel görünüm adýna,tüm yazýlarýn mavi olmasý için
        printf("\n\n\n*_*_*_*OYUNA BAÞLAMAK ÝÇÝN ENTER a BASINIZ*_*_*_*");
	    getch();
	    system("COLOR f");//görsel görünüm adýna,tüm yazýlarýn parlak beyaz olmasý için
	
		int  k,result,totalPuan=0,say,dongu;
	    char harf_alma[5]={"harf"};
	    
	    float total_s;
	    char cevap[10];
	    int array[3],array1[4],array2[5],array3[6],array4[7],array5[8],array6[9],arrayx[2];
        //süreyi baþlattým.
		clock_t t0 = clock();
	    FILE *oyun_bir,*oyun_bir_soru;
    	//dosyadan okunacak deðerler için dizi tanýmladým
	    char birinci_level[4];
	    char birinci_level_soru[130];
	    
	    
	    say=0;
	    dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunbiricin(array);
	    //4 harfli kelimelerden iki tanesini nin sorularý ve kelimelri ekrana getirmek için için for loop 
		for(int a=0;a<2;a++){
		//dosyadan okuma yaptým
		oyun_bir = fopen("1.level.txt", "r"); 
	    oyun_bir_soru=fopen("1.level_sorulari.txt", "r");
	     //z=10 çünkü dosyalarýn içinde 10 ar tane eleman var
	    for(int z=0;z<10;z++){
	    //dosyadan veri z nin artmasýna baðlý olarak dosyadan sýrayla okur
	    fscanf(oyun_bir,"%s ",&birinci_level);
	    fgets(birinci_level_soru,129,oyun_bir_soru);
		  //"void random_sayi_(int arrayx[2]);" fonksiyonunu dosyadan random veri okumak adýna yazmýþtým.
		  //üretile random sayi z ye esit ise iþlem yapýlmaya devam eder böylece dosyadan veriyi random olarak okumuþ oldum
	      if(arrayx[say]==z&&dongu!=2){
		  say++;
		  dongu++;
	    	int sayac=0;
	    	printf("\n\n");
	        //ilk kelimenin uzunluðunu buldum
		    k=strlen(birinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
			printf("DÖRT HARFLÝ %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(birinci_level_soru);
		    printf("         ");
		    int point;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini görünmeyecek sekilde yazdýrdým
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  point=0;
		  do{//cevap doðru oalna kadar dönecek döngü
		  printf("\n\ncevabý giriniz= ");
		  gets(cevap);
		  //verilen cevabý doðrumu diye karsýlaþtýrma yaptým
		  if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  
		  result=strcmp(birinci_level,cevap);
		  if(result==0)
		  {point+=400;//kelime 4 harfli ise 400 puan alýr.
		  totalPuan+=point;
		  printf("\nTEBRÝKLER  %d  puan    ",point);
		  sleep(2);//2 saniye sonra system("cls"); ile ekraný temizler
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanlýþ ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLIÞ CEVAP YENÝDEN DENEYÝNÝZ");
              }else if(result1==0)
		           { 
			    if(sayac!=3){
	           //"array[sayac]" ý "void random_sayi_oyunbiricin(int array[3]);" fonksiyonundan aldým.
			   int c=array[sayac];
                sayac++;
	            point-=100; //yanlýþ ise 4 harflik kelimenin alýnan her harfi için  -100 puan alýr
	           printf("         ");
				for(int i=0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=birinci_level[c];
			    }printf("%c ",bulunan_harfler[i]);  
			   } printf("    point %d",point);
			     if(sayac==3){
                printf("\nHARF ALMA HAKKINIZ BÝTMÝSTÝR!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
}
} 
}	   
		    
			//oyun_bir ve oyun_bir_soru dosyasýný kapattým
			fclose(oyun_bir);
			fclose(oyun_bir_soru);
			//1. oyun bitimindeki total süreyi hesaplattim.
	    clock_t t1 = clock();
	    total_s=(420-((double)(t1 - t0)/CLOCKS_PER_SEC));
       printf("\n--------->Kalan Süre = %.0Lf saniye",total_s);
			
			  
			
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

	     //4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  
		  say++;
		  dongu++;
	    	
	    	int sayac=0;
	    	printf("\n\n");
	    	//dosyadan okunacak deðerleri dizi içine attým
	    	
	        //ilk kelimenin uzunluðunu buldum
		    k=strlen(ikinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("BEÞ HARFLÝ %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(ikinci_level_soru);
		    printf("         ");
		    int point;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini görünmeyecek sekilde yazdýrdým
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  
		  point=0;
		  do{//cevap doðru oalna kadar dönecek döngü
		  
		  printf("\n\ncevabý giriniz= ");
		  gets(cevap);
		  //verilen cevabý doðrumu diye karsýlaþtýrma yaptým
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
		  printf("\n\n\nTEBRÝKLER  %d  puan    ",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		 printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanlýþ ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLIÞ CEVAP YENÝDEN DENEYÝNÝZ");
              }else
		       if(result1==0)
		      { 
	           //yanlýþ ise 4 harflik kelimenin her harfi için -100 puan alýr
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
                printf("\nHARF ALMA HAKKINIZ BÝTMÝSTÝR!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
}
}
  //oyun iki dosyasýný kapattým
	    fclose(oyun_iki);
		fclose(oyun_iki_soru);
		
		clock_t t2 = clock();
		total_s-=((double)(t2 - t1)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan Süre = %.0Lf saniye",total_s);
		
		FILE *oyun_uc,*oyun_uc_soru;
    	//dosyadan okunan deðerleri birer dizi içinde tuttum
	    char ucuncu_level[6];
	    char ucuncu_level_soru[101];
	    
	    
	    
	    // 4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	    say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunucuncu(array2);
		for(int a=0;a<2;a++){
		//dosyadan okuma yaptým
	    oyun_uc = fopen("3.level.txt", "r"); 
	    oyun_uc_soru=fopen("3.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    
	    fscanf(oyun_uc,"%s ",&ucuncu_level);
	    fgets(ucuncu_level_soru,100,oyun_uc_soru);
		
	    // 4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  dongu++;
		  say++;
	    	int sayac=0;
	    	printf("\n\n");
	    	//dosyadan okunacak deðerleri dizi içine attým
	    	
	        //ilk kelimenin uzunluðunu buldum
		    k=strlen(ucuncu_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("ALTI HARFLÝ %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(ucuncu_level_soru);
		    printf("         ");
		   
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini görünmeyecek sekilde yazdýrdým
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap doðru oalna kadar dönecek döngü
		  
		  printf("\n\ncevabý giriniz= ");
		  gets(cevap);
		  //verilen cevabý doðrumu diye karsýlaþtýrma yaptým
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
		 
		  printf("\n\n\nTEBRÝKLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanlýþ ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLIÞ CEVAP YENÝDEN DENEYÝNÝZ");
              }else
		       if(result1==0)
		      { 
		       
			   
			    if(sayac!=5){
	           //yanlýþ ise 6 harflik kelimenin her harfi için -100 puan alýr
	          
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
                printf("\nHARF ALMA HAKKINIZ BÝTMÝSTÝR!");	
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
       printf("\n--------->Kalan Süre = %.0Lf saniye",total_s);
		
			FILE *oyun_dort,*oyun_dort_soru;
    	//dosyadan okunan deðerleri birer dizi içinde tuttum
	    char dorduncu_level[7];
	    char dorduncu_level_soru[106];
	    //dosyadan okuma yaptým
	    
	    
	     //4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	    say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyundort(array3);
		for(int a=0;a<2;a++){
		oyun_dort = fopen("4.level.txt", "r"); 
	    oyun_dort_soru=fopen("4.level_sorulari.txt", "r");
	     
	    for(int z=0;z<10;z++){
	    
	    //dosyadan okunacak deðerleri dizi içine attým
	    	//dosyadan okunacak deðerleri dizi içine attým
	    fscanf(oyun_dort,"%s ",&dorduncu_level);
	    fgets(dorduncu_level_soru,106,oyun_dort_soru);
	
	     //4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  dongu++;
	      say++;
	    	int sayac=0;
	    	printf("\n\n");
	    
	        //ilk kelimenin uzunluðunu buldum
		    k=strlen(dorduncu_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("YEDÝ HARFLÝ %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(dorduncu_level_soru);
		    printf("         ");
		    
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini görünmeyecek sekilde yazdýrdým
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap doðru oalna kadar dönecek döngü
		  printf("\n\ncevabý giriniz= ");
		  gets(cevap);
		  //verilen cevabý doðrumu diye karsýlaþtýrma yaptým
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
		  printf("\n\n\nTEBRÝKLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanlýþ ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLIÞ CEVAP YENÝDEN DENEYÝNÝZ");
              }else if(result1==0)
		           { 
			    if(sayac!=6){
	           //yanlýþ ise 4 harflik kelimenin her harfi için -100 puan alýr
	           
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
                printf("\nHARF ALMA HAKKINIZ BÝTMÝSTÝR!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
}}
	   //oyun_bir ve oyun_bir_soru dosyasýný kapattým
		fclose(oyun_dort);
		fclose(oyun_dort_soru);
		clock_t t4 = clock();
		total_s-=((double)(t4 - t3)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan Süre = %.0Lf saniye",total_s);
       
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
	    
	    //dosyadan okunacak deðerleri dizi içine attým
	    	fscanf(oyun_bes,"%s ",&besinci_level);
	        fgets(besinci_level_soru,62,oyun_bes_soru);
	
	     //4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
		  dongu++;
	      say++;
	    	int sayac=0;
	    	printf("\n\n");
	    	
	        //ilk kelimenin uzunluðunu buldum
		    k=strlen(besinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("SEKÝZ HARFLÝ %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(besinci_level_soru);
		    printf("         ");
		    
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini görünmeyecek sekilde yazdýrdým
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap doðru oalna kadar dönecek döngü
		  
		  printf("\n\ncevabý giriniz= ");
		  gets(cevap);
		  //verilen cevabý doðrumu diye karsýlaþtýrma yaptým
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
		  printf("\n\n\nTEBRÝKLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanlýþ ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLIÞ CEVAP YENÝDEN DENEYÝNÝZ");
              }else
		       if(result1==0)
		      { 
	           //yanlýþ ise 4 harflik kelimenin her harfi için -100 puan alýr
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
                printf("\nHARF ALMA HAKKINIZ BÝTMÝSTÝR!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}}}
  //oyun iki dosyasýný kapattým
	    fclose(oyun_bes);
		fclose(oyun_bes_soru);
		
	    clock_t t5 = clock();
		total_s-=((double)(t5 - t4)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan Süre = %.0Lf saniye",total_s);
		//Altýncý oyun
	FILE *oyun_alti,*oyun_alti_soru;
    	//dosyadan okunan deðerleri birer dizi içinde tuttum
	    char altinci_level[9];
	    char altinci_level_soru[130];
	    //dosyadan okuma yaptým
	    
	    
	     //4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	   	say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunalticin(array5);
		for(int a=0;a<2;a++){
	     oyun_alti = fopen("6.level.txt", "r"); 
	    oyun_alti_soru=fopen("6.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    	//dosyadan okunacak deðerleri dizi içine attým
	    	fscanf(oyun_alti,"%s ",&altinci_level);
	        fgets(altinci_level_soru,129,oyun_alti_soru);
		
	     //4 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop  
	      
	      if(arrayx[say]==z&&dongu!=2){
	      say++;dongu++;
	    	int sayac=0;
	    	printf("\n\n");
	    	
	        //ilk kelimenin uzunluðunu buldum
		    k=strlen(altinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("DOKUZ HARFLÝ %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(altinci_level_soru);
		    printf("         ");
		    //harfalmada=0;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini görünmeyecek sekilde yazdýrdým
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  int point=0;
		  do{//cevap doðru oalna kadar dönecek döngü
		  
		  
		  printf("\n\ncevabý giriniz= ");
		  gets(cevap);
		  //verilen cevabý doðrumu diye karsýlaþtýrma yaptým
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
		  printf("\n\n\nTEBRÝKLER  %d  puan",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanlýþ ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLIÞ CEVAP YENÝDEN DENEYÝNÝZ");
              }else if(result1==0)
		           { 
			    if(sayac!=8){
	           //yanlýþ ise 4 harflik kelimenin her harfi için -100 puan alýr
	           
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
                printf("\nHARF ALMA HAKKINIZ BÝTMÝSTÝR!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
}
}
	   //oyun_bir ve oyun_bir_soru dosyasýný kapattým
		fclose(oyun_alti);
		fclose(oyun_alti_soru);
		
		clock_t t6 = clock();
		total_s-=((double)(t6 - t5)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan Süre = %.0Lf saniye",total_s);
		
			FILE *oyun_yedi,*oyun_yedi_soru;
    	//dosyadan okunan deðerleri birer dizi içinde tuttum
	    char yedinci_level[10];
	    char yedinci_level_soru[69];
	   
	    
	     //10 harfli kelimelerden iki tanesini ni sorularý ile sordurma kiçin for loop 
	   	say=0;dongu=0;
	    random_sayi_(arrayx);
	    random_sayi_oyunyedicin(array6);
		for(int a=0;a<2;a++){
			 //dosyadan okuma yaptým
	    oyun_yedi = fopen("7.level.txt", "r"); 
	    oyun_yedi_soru=fopen("7.level_sorulari.txt", "r");
	    for(int z=0;z<10;z++){
	    //dosyadan okunacak deðerleri dizi içine attým
	    	fscanf(oyun_yedi,"%s ",&yedinci_level);
	        fgets(yedinci_level_soru,70,oyun_yedi_soru);
	      if(arrayx[say]==z&&dongu!=2){
	      say++;dongu++;
	    	int sayac=0;
	    	printf("\n\n");
	        //ilk kelimenin uzunluðunu buldum
		    k=strlen(yedinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
		    printf("ON HARFLÝ %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(yedinci_level_soru);
		    printf("         ");
		     int point;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini görünmeyecek sekilde yazdýrdým
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  
		  point=0;
		  do{//cevap doðru oalna kadar dönecek döngü
		  printf("\n\ncevabý giriniz= ");
		  gets(cevap);
		  //verilen cevabý doðrumu diye karsýlaþtýrma yaptým
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
		  printf("\nTEBRÝKLER  %d  puan    ",point);
		  sleep(2);
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanlýþ ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLIÞ CEVAP YENÝDEN DENEYÝNÝZ");
              }else if(result1==0)
		           { 
			    if(sayac!=9){
	           //yanlýþ ise 4 harflik kelimenin her harfi için -100 puan alýr
	           
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
                printf("\nHARF ALMA HAKKINIZ BÝTMÝSTÝR!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
	
		
	}
	 }
	 }  //oyun_bir ve oyun_bir_soru dosyasýný kapattým
		fclose(oyun_yedi);
		fclose(oyun_yedi_soru);
		
	clock_t t7 = clock();
		total_s-=((double)(t7 - t6)/CLOCKS_PER_SEC);
       printf("\n--------->Kalan Süre = %.0Lf saniye",total_s);
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
        printf("*.*.*.*.*.*KELÝME OYUNUNA HOSGELDÝNÝZ*.*.*.*.*.*\n");
        printf("************************************************\n");
        printf("    OYUN KURALLARI\n\n");
        printf("  1]Dört harfli kelimeler 400 puan\n  2]Beþ harfli kelimeler 500 puan\n  3]Altý harfli kelimeler 600 puan\n  4]Yedi harfli kelimeler 700 puan\n  5]Sekiz harfli kelimeler 800 puan\n  6]Dokuz harfli kelimeler 900 puan\n  7]On harfli kelimeler 1000 puan dýr.\n  8]Harf almak için  harf  yazýnýz\n  9]Alýnan her harf -100 puandýr.\n  10]Süre aþýmýnda her dk baþýna -100 puan.\n 11]Pas hakkýnýzý kullanmak için p'ye basýnýz. ");
	    printf("\n\t\t\t\t\t\t\tAD=HÝLAL ÖZTEMEL OGR_NO=191141016");
		printf(" \n \n   TOPLAM SÜRENÝZ 420 Saniye (7 dakika)'dir  ");
	    
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
