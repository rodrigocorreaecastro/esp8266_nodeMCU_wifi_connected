# Programando a reconexão automática do ESP8266 NodeMCU

Este código exemplifica a possibilidade de realizar leitura e escrita de dados sem se preocupar com falhas de conexão na rede Wi-Fi ou quedas de energia, ou seja, o módulo ESP8266 NodeMCU se conecta a rede Wi-Fi principal, sendo possível acompanhá-las através do serial monitor, porém se a conexão Wi-Fi principal falhar no momento da comunicação o módulo buscará a rede Wi-Fi auxiliar que deverá ser configurada conforme programa e quando a conexão for restabelecida as strings de dados continuaram a trafegar normalmente.
