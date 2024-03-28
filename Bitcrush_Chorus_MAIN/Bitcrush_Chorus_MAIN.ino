#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=69,100
AudioEffectBitcrusher    bitcrusher1;    //xy=242,95
AudioFilterBiquad        biquad2;        //xy=374,95
AudioEffectChorus        chorus1;        //xy=487,244
AudioFilterBiquad        biquad3;        //xy=556,154
AudioMixer4              mixer1;         //xy=739,116
AudioOutputI2S           i2s1;           //xy=970,228
AudioConnection          patchCord1(i2s2, 0, bitcrusher1, 0);
AudioConnection          patchCord2(bitcrusher1, biquad2);
AudioConnection          patchCord3(biquad2, chorus1);
AudioConnection          patchCord4(biquad2, 0, mixer1, 0);
AudioConnection          patchCord5(chorus1, biquad3);
AudioConnection          patchCord6(biquad3, 0, mixer1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=322,507
// GUItool: end automatically generated code


void setup() {
  // put your setup code here, to run once:
  delay(100);
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(1600);
  Serial.begin(38400);
  analogReadResolution(12);
  
  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.5);
  sgtl5000_1.unmuteLineout();

  //Bitcrush set up
  bitcrusher1.bits(16);
  bitcrusher1.sampleRate(4500)


}

void loop() {
  // put your main code here, to run repeatedly:

}


//Read analog read and returns a .00 to 1 value
void knobPercent(pin){

  int readValue;
  float percent;

  readValue = analogRead(pin);
  percent = readValue / 4095;

  return percent;   
}










