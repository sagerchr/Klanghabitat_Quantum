String strIN;
const int bSize = 13; 
byte Buffer[bSize];
float Millis = 0;
float Millislast = 0;
void setup() {
   Serial.begin(57600);   
   pinMode(0, INPUT);  
   Millislast= millis(); 
   pinMode(0, INPUT_PULLUP); 
}

void loop() 
{
            
        if (Serial.available() > 0) 
        {
                Serial.readBytesUntil(0xFF, Buffer, bSize); 

                
                for(int i=0;i<bSize-1;i++)
                {
                Serial.print('|');  
                Serial.print(Buffer[i], HEX);
                Buffer[i]=0;
                }
                
                Millis= millis() - Millislast; 
                Serial.print("|--Dauer:");
                Serial.println(Millis);        
        }    

}
    


