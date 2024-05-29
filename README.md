# Projeto 1
Projeto 1
# FECAP - Fundação de Comércio Álvares Penteado

<p align="center">
<a href= "https://www.fecap.br/"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRhZPrRa89Kma0ZZogxm0pi-tCn_TLKeHGVxywp-LXAFGR3B1DPouAJYHgKZGV0XTEf4AE&usqp=CAU" alt="FECAP - Fundação de Comércio Álvares Penteado" border="0"></a>
</p>

# Sistema Integrado para Criação de Pintinhos
## Integrantes: Anie Bissoli (RA:24025800), Felipe de Castro Lima(RA: 24025867), João Vitor Cenedeze (24025874)

## Professor Orientador: Rodnil da Silva
## Descrição
O projeto consiste em criar um sistema integrado utilizando um Arduino ou similar, sensores de
temperatura e umidade, relés para controle de dispositivos, lâmpadas de aquecimento e um display
LCD ou LED. O sistema será capaz de monitorar continuamente a temperatura e umidade ambiente,
controlando as lâmpadas de aquecimento. Um display mostrará informações importantes como
temperatura e umidade. O sistema poderá ser opcionalmente controlado remotamente através de um
aplicativo móvel ou interface web.
<br><br>


## 🛠 Estrutura de pastas

ProjetoAvicultura/

├── src/

codigotrabalho.ino

│   ├── main.ino

│   ├── wifi_credentials.h

│   ├── blynk_credentials.h

│   ├── sensor_functions.h

│   └── led_functions.h

├── lib/

│   ├── DHT/

│   ├── LiquidCrystal_I2C/

│   ├── Blynk/

│   └── ESP8266WiFi/

├── platformio.ini

└── README.md


## 🛠 Instalação
WINDOWS:
É necessário baixar o arduino e executa-ló com o programa utilizado na montagem.

## 💻 Configuração para Desenvolvimento

1. Configuração de Ambiente com Arduino IDE
Passos Gerais (Windows, Linux, macOS)
Baixar e Instalar o Arduino IDE:

Baixe o Arduino IDE e instale para o seu sistema operacional (Windows, Linux, macOS).
Adicionar Suporte ao ESP8266:

Abra o Arduino IDE.
Vá em File > Preferences.
No campo "Additional Board Manager URLs", adicione o seguinte URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json e clique em "OK".
Vá em Tools > Board > Boards Manager, procure por "esp8266" e instale a opção "esp8266 by ESP8266 Community".
Instalar Bibliotecas Necessárias:

Vá em Sketch > Include Library > Manage Libraries.
Procure e instale as seguintes bibliotecas:
Blynk
DHT sensor library (por Adafruit)
LiquidCrystal_I2C (por Frank de Brabander)

2. Configuração de Ambiente com PlatformIO
Passos Gerais (Windows, Linux, macOS)
Instalar Visual Studio Code:

Baixe o Visual Studio Code e instale para o seu sistema operacional.
Instalar PlatformIO:

Abra o Visual Studio Code.
Vá em Extensions (ícone de quadrado no painel lateral) e procure por "PlatformIO IDE".
Instale a extensão "PlatformIO IDE".
Configurar PlatformIO:

Abra o PlatformIO no Visual Studio Code.
Crie um novo projeto e selecione a placa "NodeMCU 1.0 (ESP-12E Module)" ou a correspondente ao seu ESP8266.
Configurar platformio.ini:

No diretório do projeto, edite o arquivo platformio.ini para incluir as dependências:
ini
Copiar código
[env:esp8266]
platform = espressif8266
board = nodemcuv2
framework = arduino
lib_deps =
    blynkkk/Blynk
    adafruit/DHT sensor library
    johnrickman/LiquidCrystal_I2C
    
3. Testes Automatizados com PlatformIO
PlatformIO permite escrever testes unitários que podem ser executados automaticamente. Aqui está um exemplo de como configurar um teste simples para validar a leitura do sensor DHT.

Adicionar Diretório de Testes:

Dentro do diretório do projeto, crie uma pasta chamada test.
Dentro da pasta test, crie uma subpasta chamada test_dht.
Criar Arquivo de Teste:
Dentro da pasta test_dht, crie um arquivo test_main.cpp com o seguinte conteúdo:
cpp
Copiar código
#include <Arduino.h>
#include <unity.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void test_dht_sensor() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    TEST_ASSERT_FALSE(isnan(humidity));
    TEST_ASSERT_FALSE(isnan(temperature));
}
void setup() {
    UNITY_BEGIN();
    dht.begin();
    RUN_TEST(test_dht_sensor);
    UNITY_END();
}
void loop() {
    // Not used in this test
}
Executar Testes:
No PlatformIO, abra o terminal integrado e execute o comando:
sh
Copiar código
pio test

4. Instalar Dependências e Executar Testes em Múltiplas Plataformas
Windows
Instalar Arduino IDE ou Visual Studio Code com PlatformIO seguindo os passos acima.
Executar testes conforme descrito na seção anterior.
Linux
Instalar Arduino IDE:
Use o gerenciador de pacotes da sua distribuição para instalar o Arduino IDE ou baixe diretamente do site oficial.
sh
Copiar código
sudo apt update
sudo apt install arduino
Instalar Visual Studio Code e PlatformIO seguindo os passos acima.
Executar testes conforme descrito na seção anterior.
macOS
Instalar Arduino IDE ou Visual Studio Code com PlatformIO seguindo os passos acima.
Executar testes conforme descrito na seção anterior.

## 🗃 Histórico de lançamentos

0.2.1 - 23/05/2022
CONCLUSÃO: Código concluido
0.2.0 - 20/05/2024
MUDANÇA: Terminamos o código do arduino
0.1.1 - 13/05/2024
CONSERTADO: Erro na biblioteca DHT11
0.1.0 - 29/04/2024
O primeiro lançamento adequado
MUDANÇA: Atualização dos códigos
0.0.1 - 22/04/2024
Trabalho em andamento

## 🎓 Referências

Aqui estão as referências usadas no projeto.

1-https://www.embrapa.br/contando-ciencia/animais-e-criacoes/-/asset_publisher/jzCoSDOAGLc4/content/como-nascem-os-pintinhos-/1355746?inheritRedirect=false

2-https://ligadoseintegrados.canalrural.com.br/aves/esfriou-na-granja-veja-como-proteger-as-aves-quando-a-temperatura-cai/

3-https://opresenterural.com.br/cobb-defende-controle-de-temperatura-do-pintinho-apos-eclosao/#:~:text=%C3%89%20importante%20que%20o%20ambiente
