/*  
    Created By Tuhin Sengupta. 
    Kalman  Filter is used to smoth out fluctuating values 
    This is a arduino library to implement kalman filter 
*/

float kalVarVolt = 0.25; // filter gain
float kalVarProcess = 0.00001; // accuracy (smaller the number more the accuracy and slower the system response)
float kalPc = 0.0;
float kalG = 0.0;
float kalP = 1.0;
float kalXp = 0.0;
float kalZp = 0.0;
float kalXe = 0.0;

float kalmanFilter(int val) {
  kalPc = kalP + kalVarProcess;
  kalG = kalPc/(kalPc + kalVarVolt);
  kalP = (1-kalG)*kalPc;
  kalXp = kalXe;
  kalZp = kalXp;
  kalXe = kalG*(val-kalZp)+kalXp; 
  return(kalXe);
}


/****************** Example Code ******************

void setup() {  
  Serial.begin(9600);
}

void loop() {
  int var;
  var=analogRead(A0);
  int fil_var = kalmanFilter(var);
  Serial.print("raw: ");
  Serial.print(var);
  Serial.print("   filter: ");
  Serial.println(fil_var);
}

***************************************************/