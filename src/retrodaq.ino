
  float time_elapsed_seconds;
  int num_strips = 0;
  int inches_normal = 1200;     // distance between early and end strips
  int inches_warning = 2;       // distance between middle strips
  double inches_per_second = 0; //velocity
  double caculated_inches_per_second = 880; // variable used for distance estimations
  boolean reflective = false;
  boolean test_in_progress = true;
  double expected_inches_traveled = 0;
  double distance_error = 0;
  double velocity_error = 0;
  
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
  Serial.println("estimated distance(in) from last strip: ")
  
  while(test_in_progress) {
    
    //Sensor is reading reflective material
    if(digitalRead(8) && reflective) {
      if((num_strips + 1) % 2 == 0) { // branch is taken on second strip only
        ending = millis();
        temp = starting;
        test_in_progress = false;
      }
      starting = ending;
      num_strips++;
      reflective = false;
    }

    //Sensor is not reading reflective material
    if(!digitalRead(8) && test_in_progress) {
      reflective = true;
      expected_inches_traveled = calculated_inches_per_second * (millis() - starting) / 1000;
      // prints the inches traveled since last reflective tape
      Serial.print(expected_inches_traveled);
      Serial.print(", ");
    }
  }

  //END WHILE
  
  time_elapsed_seconds = ((float)(ending - temp) / 1000.000);
  
  //Start until 1000 feet remaining && end of 500ft remaining until the end
  if(num_strips < 43 || num_strips > 69) {
    expected_inches_traveled = time_elapsed_seconds * caculated_inches_per_second;
    distance_error = inches_normal - expected_inches_traveled;
    inches_per_second = (inches_normal * (1/time_elapsed_seconds));
  }
  
  //1000 feet remaining until next 100ft marker
  if(num_strips > 43 && num_strips < 64) {
    //Serial.print("1000 feet remaining");
    expected_inches_traveled = time_elapsed_seconds * calculated_inches_per_second;
    distance_error = inches_warning - expected_inches_traveled;
    inches_per_second = (inches_warning *(1/time_elapsed_seconds));
  }

  //100ft markers until 500ft marker
  if(num_strips > 64 && num_strips < 68) {
    expected_inches_traveled = time_elapsed_seconds * calculated_inches_per_second;
    distance_error = inches_normal - expected_inches_traveled;
    inches_per_second = (inches_normal * (1/time_elapsed_seconds));
  }

  //500ft marker until next 100ft marker
  if(num_strips > 68 && num_strips < 69) {
    //Serial.print("500 feet remaining");
    expected_inches_traveled = time_elapsed_seconds * calculated_inches_per_second;
    distance_error = inches_warning - expected_inches_traveled;
    inches_per_second = (inches_warning * (1/time_elapsed_seconds));
  }
  
  velocity_error = distance_error * (1/time_elapsed_seconds);
  // accounts for error
  calculated_inches_per_second = calculated_inches_per_second + velocity_error;

  
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
