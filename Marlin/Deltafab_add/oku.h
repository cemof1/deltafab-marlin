int baslik=0;
int sayac=0;
int toplam=0;
int baraj=0;
int okuma=0;
int sayac_debug=0;// kafa takılıyken genede kafa algılanmadı mesajı bugını gidermek iıin sayaç eklendi
void baslik_okuma(){
if(baraj==0){// 10 kez okuma yapıp sabitleme kısmı
  for(sayac=0; sayac<10 ; sayac++){
    okuma=analogRead(A3);
    delay(5);
    toplam=okuma+toplam;
    }
  
  }
if(0<(toplam/10) && (toplam/10)<60){baslik=1;} // seramik
else if(65<(toplam/10) && (toplam/10)<125){baslik=2;} // çift nozzle
else if(130<(toplam/10) && (toplam/10)<190){baslik=3;} // lazer
else if(195<(toplam/10) && (toplam/10)<255){baslik=4;}// cnc
/*
 *      .
 *      ..  
 *      ...
 */
 else {baslik=0;}
 baraj=1;
 
}
void kafa_algilama(){
  if(digitalRead(6)==1) {digitalWrite(11, LOW);}// ESP çalıştı
 else{digitalWrite(11, HIGH);}
//for(sayac=0; sayac<10 ; sayac++){
//    if(digitalRead(58)==0)
//    {sayac_debug++;}
//}
//if(sayac_debug==10){
//  kill(PSTR(MSG_KILLED_cup));
if(digitalRead(3)==1 && digitalRead(14)==1 && digitalRead(18)==1) { kill(PSTR(MSG_KILLED_cup));}
//}
}