#include <LedControl.h>

// Define os pinos de comunicação com o MAX7219
const int DATA_PIN = 12;
const int CLK_PIN = 11;
const int CS_PIN = 10;

// Cria uma instância do objeto LedControl
LedControl matrizLed = LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

// Função para exibir uma matriz de bytes no display matricial
void exibirMatriz(byte matriz[8])
{
  for (int linha = 0; linha < 8; linha++) {
    matrizLed.setRow(0, linha, matriz[linha]);
  }
  delay(1000);
}

void setup()
{
  // Inicializa o display matricial
  matrizLed.shutdown(0, false);
  matrizLed.setIntensity(0, 8);
  matrizLed.clearDisplay(0);
}

void loop()
{
  // Matrizes de bytes para as letras "Luisa"
  byte letraL[8] = {
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11111111,
    B11111111
  };

  byte letraU[8] = {
    B11000011,
    B11000011,
    B11000011,
    B11000011,
    B11000011,
    B11000011,
    B01111110,
    B01111110
  };

  byte letraI[8] = {
    B01111110,
    B01111110,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B01111110,
    B01111110
  };

  byte letraS[8] = {
    B00111110,
    B01111111,
    B11000001,
    B11000000,
    B01111110,
    B00000111,
    B11111110,
    B01111100
  };

  byte letraA[8] = {
    B00111100,
    B01111110,
    B11000011,
    B11000011,
    B11111111,
    B11000011,
    B11000011,
    B11000011
  };

  // Exibe as letras "Luisa" sequencialmente no display matricial
  exibirMatriz(letraL);
  exibirMatriz(letraU);
  exibirMatriz(letraI);
  exibirMatriz(letraS);
  exibirMatriz(letraA);
}