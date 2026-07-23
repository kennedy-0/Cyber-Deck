#include <Keypad.h>
#include <Keyboard.h>
#define VRX A5
#define VRY A4
const byte Ls = 4;
const byte Cs = 11;
bool ativado = false;
bool ativado1 = false;
// Mapa das teclas (4 linhas x 11 colunas)
char teclas[Ls][Cs] = {
  { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A' },
  { 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' },
  { 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W' },
  { 'X', 'Y', 'Z', '!', '@', '#', '$', '%', '&', '*', '+' }
};

// Pinos das linhas e colunas
byte Plinha[Ls] = { A0, A1, A2, A3 };                       // 4 linhas
byte Pcoluna[Cs] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };  // 11 colunas

Keypad teclado = Keypad(
  makeKeymap(teclas),
  Plinha,
  Pcoluna,
  Ls,
  Cs);

void setup() {
  Keyboard.begin();
}


void loop() {
  char tec = teclado.getKey();

  if (tec) {

    switch (tec) {

      case '1':
        Keyboard.release(KEY_LEFT_CTRL);
        delay(500);
        Keyboard.write(KEY_LEFT_CTRL);
        delay(10);
        break;
        

      case '2': Keyboard.write('.'); break;
      case '3': Keyboard.write(','); break;
      case '4': Keyboard.write('e'); break;
      case '5': Keyboard.write('r'); break;

      case '6': Keyboard.write(' '); break;
      case '7': Keyboard.write('y'); break;
      case '8': Keyboard.write(KEY_RETURN); break;
      case '9': Keyboard.write('i'); break;
      case '0': Keyboard.write('['); break;

      case 'A': Keyboard.write(']'); break;
      case 'B': Keyboard.write('m'); break;
      case 'C': Keyboard.write(KEY_BACKSPACE); break;
      case 'D': Keyboard.write('z'); break;
      case 'E': Keyboard.write('x'); break;

      case 'F': Keyboard.write('c'); break;
      case 'G': Keyboard.write('v'); break;
      case 'H': Keyboard.write('b'); break;
      case 'I': Keyboard.write('n'); break;
      case 'J': Keyboard.write('z'); break;

      case 'K':
        if (ativado) {
          Keyboard.release(KEY_LEFT_SHIFT);
          ativado = false;
        } else {
          Keyboard.press(KEY_LEFT_SHIFT);
          ativado = true;
        }
        break;

      case 'L': Keyboard.write('\''); break;
      case 'M': Keyboard.write('k'); break;
      case 'N': Keyboard.write('a'); break;
      case 'O': Keyboard.write('s'); break;
      case 'P': Keyboard.write('d'); break;

      case 'Q': Keyboard.write('f'); break;
      case 'R': Keyboard.write('g'); break;
      case 'S': Keyboard.write('h'); break;
      case 'T': Keyboard.write('j'); break;
      case 'U': Keyboard.write('k'); break;

      case 'V': Keyboard.write('l'); break;
      case 'W': Keyboard.write(';'); break;
      case 'X': Keyboard.write('i'); break;
      case 'Y': Keyboard.write('q'); break;
      case 'Z': Keyboard.write('w'); break;

      case '!': Keyboard.write('e'); break;
      case '@': Keyboard.write('r'); break;
      case '#': Keyboard.write('t'); break;
      case '$': Keyboard.write('y'); break;
      case '%': Keyboard.write('u'); break;
      case '&': Keyboard.write('i'); break;
      case '*': Keyboard.write('o'); break;
      case '+': Keyboard.write('p'); break;
    }
  }
  delay(1);
  dpad();
}

void dpad() {
  int x = analogRead(VRX);
  int y = analogRead(VRY);


  // Controla apenas as setas
  if (x > 700)
    Keyboard.press(KEY_LEFT_ARROW);
  else
    Keyboard.release(KEY_LEFT_ARROW);

  if (x < 300)
    Keyboard.press(KEY_RIGHT_ARROW);
  else
    Keyboard.release(KEY_RIGHT_ARROW);

  if (y < 300)
    Keyboard.press(KEY_UP_ARROW);
  else
    Keyboard.release(KEY_UP_ARROW);

  if (y > 700)
    Keyboard.press(KEY_DOWN_ARROW);
  else
    Keyboard.release(KEY_DOWN_ARROW);

  delay(100);
}

