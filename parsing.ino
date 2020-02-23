

String dataIn;
String dt[10];
int i;
boolean parsing=false;

void setup() {
  Serial.begin(9600);
  dataIn="";
}


void parsingData(){
int j=0;

Serial.print("data masuk : ");                          //kirim data yang telah diterima sebelumnya
Serial.print(dataIn);
Serial.print("\n");
 

dt[j]="";                                             //inisialisasi variabel, (reset isi variabel)

for(i=1;i<dataIn.length();i++){                      //proses parsing data
if ((dataIn[i] == '#') || (dataIn[i] == ','))       //pengecekan tiap karakter dengan karakter (#) dan (,)
{
j++;                                              //increment variabel j, digunakan untuk merubah index array penampung
dt[j]="";                                        //inisialisasi variabel array dt[j]
}
else{
dt[j] = dt[j] + dataIn[i];                     //proses tampung data saat pengecekan karakter selesai.
  }
}
 
Serial.print("data 1 : ");
Serial.print(dt[0].toInt());
Serial.print("\n");
Serial.print("data 2 : ");
Serial.print(dt[1].toInt());
Serial.print("\n");
Serial.print("data 3 : ");
Serial.print(dt[2].toInt());
Serial.print("\n\n");
}

void loop() {
   if(Serial.available()>0) {
    char inChar = (char)Serial.read();
    dataIn += inChar;
    if (inChar == '\n') {
    parsing = true;
  }
}
 
if(parsing){
    parsingData();
    parsing=false;
    dataIn="";
  } 
}


