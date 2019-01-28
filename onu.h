int baslik=0;
int sayac=0;
int toplam=0;
int baraj=0;
int okuma=0;
int sayac_debug=0;// kafa takılıyken genede kafa algılanmadı mesajı bugını gidermek için sayaç eklendi
void baslik_okuma(){
  if(digitalRead(58)!=1){
    sayac_debug++;// sayaç her kafayı algılamadığında birer arttıracak
    }
    if(sayac_debug>50){
  kill(PSTR(MSG_KILLED_cup));//eğer 50 kezden daha fazla sayaç kafayı algılamazsa o zaman öldürecek.
    }
if(baraj==0){// 10 kez okuma yapıp sabitleme kısmı
  for(sayac=0; sayac<10 ; sayac++){
    okuma=analogRead(A3);
    delay(5);
    toplam=okuma+toplam;
    }
  
  }
if(0<(toplam/10) && (toplam/10)<60){baslik=1;}
else if(65<(toplam/10) && (toplam/10)<125){baslik=2;}
else if(130<(toplam/10) && (toplam/10)<190){baslik=3;}
else if(195<(toplam/10) && (toplam/10)<255){baslik=4;}
/*
 *      .
 *      ..  
 *      ...
 */
 else {baslik=0;}
 baraj=1;
if (baslik==3){
  if(digitalRead(6)==0)
  {//lazerde durdurma
    const uint16_t p = parser.ushortval('P');
    if (p < FAN_COUNT) fanSpeeds[p] = 0;
    delay(200);
    card.pauseSDPrint();
    print_job_timer.pause();
    PSTR("M117 Close the door");
    }
  }
}
