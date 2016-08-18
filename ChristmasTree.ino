#include <SD.h>  
#include <TMRpcm.h>  

#define SD_ChipSelectPin 4
#define GREEN1_PIN 9  
#define RED1_PIN 8
#define YELLOW1_PIN 7
#define GREEN2_PIN 6
#define RED2_PIN 5
#define SWITCH_SONG_BUTTON 3

int ledMode = 1;
int songSer;
boolean isSwSong = false;

TMRpcm tmrpcm;
 
void setup(){ 
  tmrpcm.speakerPin = 10; //Connecting speaker with library TMRPCM
 
  if (!SD.begin(SD_ChipSelectPin)) {  // checking SD card
    return;   
  }

  //set possibility of changing volume and it's level (5 is the best for mp3-to-wav converters)
  tmrpcm.volume(1);
  tmrpcm.setVolume(5);
  
  //play song at first time
  playMusic();

  pinMode(GREEN1_PIN, OUTPUT);
  pinMode(RED1_PIN, OUTPUT);
  pinMode(YELLOW1_PIN, OUTPUT);
  pinMode(GREEN2_PIN, OUTPUT);
  pinMode(RED2_PIN, OUTPUT);  
  
  pinMode(SWITCH_SONG_BUTTON, INPUT_PULLUP);
}
 
void loop(){ 
  isSwSong = digitalRead(SWITCH_SONG_BUTTON);

  //check is song playing now
  if(!tmrpcm.isPlaying())
    playMusic(); //calling function playMusic() if not

  //Combination of LEDs' work to make it looks like a garland
  //Here different modes switch one-by-one
  if (ledMode == 1) {
    digitalWrite(GREEN1_PIN, HIGH);
    delay(500);
    digitalWrite(RED1_PIN, HIGH);
    delay(500);
    digitalWrite(YELLOW1_PIN, HIGH);
    delay(500);
    digitalWrite(GREEN2_PIN, HIGH);
    delay(500);
    digitalWrite(RED2_PIN, HIGH);
    delay(500);
    digitalWrite(GREEN1_PIN, LOW);
    digitalWrite(RED1_PIN, LOW);
    digitalWrite(YELLOW1_PIN, LOW);
    digitalWrite(GREEN2_PIN, LOW);
    digitalWrite(RED2_PIN, LOW);
    delay(1500);
    ledMode += 1;
  }

  else if (ledMode == 2) {
    digitalWrite(GREEN1_PIN, HIGH);
    delay(500);
    digitalWrite(GREEN1_PIN, LOW);
    digitalWrite(RED1_PIN, HIGH);
    delay(500);
    digitalWrite(RED1_PIN, LOW);
    digitalWrite(YELLOW1_PIN, HIGH);
    delay(500);
    digitalWrite(YELLOW1_PIN, LOW);
    digitalWrite(GREEN2_PIN, HIGH);  
    delay(500);
    digitalWrite(GREEN2_PIN, LOW);
    digitalWrite(RED2_PIN, HIGH);
    delay(500);
    digitalWrite(RED2_PIN, LOW);
    delay(1500);
    ledMode +=1;
  }

  else if (ledMode == 3) {
    digitalWrite(GREEN1_PIN, HIGH);
    delay(500);
    digitalWrite(RED1_PIN, HIGH);
    delay(500);
    digitalWrite(YELLOW1_PIN, HIGH);
    delay(500);
    digitalWrite(GREEN2_PIN, HIGH);
    delay(500);
    digitalWrite(RED2_PIN, HIGH);
    delay(1500);
    digitalWrite(RED2_PIN, LOW);
    delay(500);
    digitalWrite(GREEN2_PIN, LOW);
    delay(500);
    digitalWrite(YELLOW1_PIN, LOW);
    delay(500);
    digitalWrite(RED1_PIN, LOW);
    delay(400);
    digitalWrite(GREEN1_PIN, LOW);
    delay(1500);
    ledMode += 1;
  }

  else if(ledMode == 4) {
    digitalWrite(GREEN1_PIN, HIGH);
    digitalWrite(RED1_PIN, HIGH);
    digitalWrite(YELLOW1_PIN, HIGH);
    digitalWrite(GREEN2_PIN, HIGH);
    digitalWrite(RED2_PIN, HIGH);
    delay(2500);
    ledMode = 1;
  }
}

//play random song (30 songs at all)
void playMusic() {
  //use an "output info" from non-used output 0 as a random seed
  randomSeed(analogRead(0));
  songSer = random(30);
  if(songSer == 1)
    tmrpcm.play("1.wav");
  else if(songSer == 2)
    tmrpcm.play("2.wav");
  else if(songSer == 3)
    tmrpcm.play("3.wav");
  else if(songSer == 4)
    tmrpcm.play("4.wav"); 
  else if(songSer == 5)
    tmrpcm.play("5.wav");
  else if(songSer == 6)
    tmrpcm.play("6.wav");
  else if(songSer == 7)
    tmrpcm.play("7.wav");
  else if(songSer == 8)
    tmrpcm.play("8.wav");
  else if(songSer == 9)
    tmrpcm.play("9.wav");
  else if(songSer == 10)
    tmrpcm.play("10.wav");
  else if(songSer == 11)
    tmrpcm.play("11.wav");
  else if(songSer == 12)
    tmrpcm.play("12.wav");
  else if(songSer == 13)
    tmrpcm.play("13.wav");
  else if(songSer == 14)
    tmrpcm.play("14.wav");
  else if(songSer == 15)
    tmrpcm.play("15.wav");
  else if(songSer == 16)
    tmrpcm.play("16.wav");
  else if(songSer == 17)
    tmrpcm.play("17.wav");
  else if(songSer == 18)
    tmrpcm.play("18.wav"); 
  else if(songSer == 19)
    tmrpcm.play("19.wav");
  else if(songSer == 20)
    tmrpcm.play("20.wav");
  else if(songSer == 21)
    tmrpcm.play("21.wav");
  else if(songSer == 22)
    tmrpcm.play("22.wav");
  else if(songSer == 23)
    tmrpcm.play("23.wav");
  else if(songSer == 24)
    tmrpcm.play("24.wav");
  else if(songSer == 25)
    tmrpcm.play("25.wav");
  else if(songSer == 26)
    tmrpcm.play("26.wav");
  else if(songSer == 27)
    tmrpcm.play("27.wav");
  else if(songSer == 28)
    tmrpcm.play("28.wav");
  else if(songSer == 29)
    tmrpcm.play("29.wav");   
  else if(songSer == 30)
    tmrpcm.play("30.wav");                           
}
