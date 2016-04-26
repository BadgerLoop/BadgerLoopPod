
  float time_elapsed_seconds;
  int num_strips = 0;
  int inches_normal = 1200;
  int inches_warning = 2;
  double inches_per_second = 0; //velocity
  boolean reflective = false;
  int count = 1;
  boolean test_in_progress = true;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
     
  unsigned long starting = 0;
  unsigned long ending = 0;
  unsigned long temp = 0;
  test_in_progress = true;
  
  while(test_in_progress) {
    
    
    
    //Sensor is reading reflective material
    if(digitalRead(8) && reflective) {
      if(count % 2 == 0) {
        ending = millis();
        temp = starting;
        test_in_progress = false;
      }
      starting = ending;
      num_strips++;
      count++;
      reflective = false;
      
      
    }

    //Sensor is not reading reflective material
    if(!digitalRead(8) && test_in_progress) {
      reflective = true;
      
    }
  }

  //END WHILE
  
  time_elapsed_seconds = ((float)(ending - temp) / 1000.000);
  

  //Start until 1000 feet remaining && end of 500ft remaining until the end
  if(num_strips < 43 || num_strips > 69) {
    inches_per_second = (inches_normal * (1/time_elapsed_seconds));
  }
  
  //1000 feet remaining until next 100ft marker
  if(num_strips > 43 && num_strips < 64) {
    //Serial.print("1000 feet remaining");
    inches_per_second = (inches_warning *(1/time_elapsed_seconds));
  }

  //100ft markers until 500ft marker
  if(num_strips > 64 && num_strips < 68) {
    inches_per_second = (inches_normal * (1/time_elapsed_seconds));
  }

  //500ft marker until next 100ft marker
  if(num_strips > 68 && num_strips < 69) {
    //Serial.print("500 feet remaining");
    inches_per_second = (inches_warning * (1/time_elapsed_seconds));
  }

  

  Serial.print("Start: ");
  Serial.println(starting);
  Serial.print("End: ");
  Serial.println(ending);
  Serial.print("Time elapsed: ");
  Serial.println(time_elapsed_seconds);
  Serial.print("Strip Count: ");
  Serial.println(num_strips);
  Serial.print("Inches per second: ");
  Serial.println(inches_per_second);
  Serial.println();
  Serial.println();
 

}