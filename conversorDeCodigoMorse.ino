
char* letras[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "-.", "....", "..", ".---", "-.-", ".-..", "--",      // A - M
                 "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};  // N - Z
                 
char* numeros[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};     // 0 - 9

int tempoPonto = 200;
int pinoConexao = 13;

void sequenciaLed(char* sequencia){
  int i = 0;
  while(sequencia[i] != '\0'){
    piscarLed(sequencia[i]);
    i++;
  }
  delay(tempoPonto * 3); //intervalo de tempo entre letras.
}

void piscarLed(char simbolo){
  digitalWrite(pinoConexao, HIGH);
  if(simbolo == '.'){
    delay(tempoPonto);
  } else{
      delay(tempoPonto * 3);
  }
  digitalWrite(pinoConexao, LOW);
  delay(tempoPonto); //intervalo de tempo entre piscadas
}


void setup(){
   pinMode(pinoConexao, OUTPUT);
   Serial.begin(9600);
}

void loop(){
  char escrita;
  
  if(Serial.available() > 0){
    escrita = Serial.read();
    if(escrita >= 'a' && escrita <= 'z'){
      sequenciaLed(letras[escrita - 'a']);
    }
    
    else if(escrita >= 'A' && escrita <= 'z'){
      sequenciaLed(letras[escrita - 'A']);
    }
    
    else if(escrita >= '0' && escrita <= '9'){
      sequenciaLed(numeros[escrita - '0']);
    }
    
    else if(escrita == ' '){
      delay(tempoPonto * 4); //intervalo de tempo entre palavras.
    }
  }
}

