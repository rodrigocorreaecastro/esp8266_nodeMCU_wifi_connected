#include <ESP8266WiFi.h>

//Login e senha do wi-fi principal
char* ssid = "wifi_name"; //coloque aqui o nome da rede principal que se deseja conectar
char* pass = "yourpassword"; //coloque aqui a senha da rede principal que se deseja conectar

char* ssid_aux = "wifi_name_5G"; //coloque aqui o nome da rede principal que se deseja conectar
char* pass_aux = "yourpassword"; //coloque aqui a senha da rede principal que se deseja conectar

//Define contador igual a zero
int count = 0;

int pin = 2;

void setup()
{
  Serial.begin(115200);
  Serial.println("Estabelecendo conexao...");
  connect();

  //Caso o Wi-Fi seja desconectado:
  if(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("A conexao não foi estabelecida, por favor apertar botao reset ou aguardar...\n");
    return;
  }
}

void loop() {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second

  //Conexão ao endereço IP específico
  WiFiClient client;
  const int httpPort = 80;

  //Caso o Wi-Fi seja desconectado:
  if(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("Falha na conexao, por favor aguarde estabilizacao da rede");
    if (ssid=="rodrigo_5G") //coloque aqui o nome da rede auxiliar que se deseja conectar
    {
      ssid = ssid_aux; //coloque aqui o nome da rede auxiliar que se deseja conectar
      pass = pass_aux; //coloque aqui a senha da rede auxiliar que se deseja conectar
      Serial.println("Estabelecendo conexao na rede auxiliar");
      connect();

      //Tenta estabelecer nova conexão a rede principal
      if(WiFi.status()!=WL_CONNECTED)
      return;
    }
    else
    {
      ssid = ssid; //coloque aqui o nome da rede principal que se deseja conectar
      pass = pass; //coloque aqui a senha da rede principal que se deseja conectar
      Serial.println("Estabelecendo conexao na rede principal");
      connect();

      //Tenta estabelecer nova conexão a rede auxiliar
      if(WiFi.status()!=WL_CONNECTED)
      return;
    }
  }
}

void connect()
{
  //Quando conectado contador volta a zero
  count = 0;
  WiFi.begin(ssid, pass);

  //Enquanto Wi-Fi não estiver conectado e o limite do tempo de conexão não exceder
  while (WiFi.status()!= WL_CONNECTED && count<= 130)
  {
    delay(100);
    Serial.print(".");
    count = count + 1;
  }
  if ((WiFi.status() == WL_CONNECTED))
  {
    Serial.println("");
    Serial.print("Conectado em: ");
    Serial.println(ssid);
    Serial.print("Endereco IP: ");
    Serial.println(WiFi.localIP());

    if (ssid=="rodrigo") //coloque aqui o nome da rede principal que se deseja conectar
    {
      Serial.println("Rede principal conectada");
      delay (100);
    }
    if (ssid=="rodrigo_5G") //coloque aqui o nome da rede auxiliar que se deseja conectar
    {
      Serial.println("Rede auxiliar conectada");
      delay(100);
    }
  }
}