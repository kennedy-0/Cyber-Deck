#include <Keypad.h>
#include <Keyboard.h>

const byte Ls = 7;
const byte Cs = 5;

char teclas[Ls][Cs] = {
  { '1', '2', '3', '4', '5' },
  { '6', '7', '8', '9', '0' },
  { 'A', 'B', 'C', 'D', 'E' },
  { 'F', 'G', 'H', 'I', 'J' },
  { 'K', 'L', 'M', 'N', 'O' },
  { 'Z', '!', '$', '%', '@' }
};

byte Plinha[Ls] = { 2, 3, 4, 5, 6, 7 };
byte Pcoluna[Cs] = { 8, 9, 10, 11, 12 };

Keypad teclado = Keypad(makeKeymap(teclas),
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

      case '1': Keyboard.write('a'); break;
      case '2': Keyboard.write('b'); break;
      case '3': Keyboard.write('c'); break;
      case '4': Keyboard.write('d'); break;
      case '5': Keyboard.write('e'); break;

      case '6': Keyboard.write('f'); break;
      case '7': Keyboard.write('g'); break;
      case '8': Keyboard.write('h'); break;
      case '9': Keyboard.write('i'); break;
      case '0': Keyboard.write('j'); break;

      case 'A': Keyboard.write('k'); break;
      case 'B': Keyboard.write('l'); break;
      case 'C': Keyboard.write('m'); break;
      case 'D': Keyboard.write('n'); break;
      case 'E': Keyboard.write('o'); break;

      case 'F': Keyboard.write('p'); break;
      case 'G': Keyboard.write('q'); break;
      case 'H': Keyboard.write('r'); break;
      case 'I': Keyboard.write('s'); break;
      case 'J': Keyboard.write('t'); break;

      case 'K': Keyboard.write('u'); break;
      case 'L': Keyboard.write('v'); break;
      case 'M': Keyboard.write('w'); break;
      case 'N': Keyboard.write('x'); break;
      case 'O': Keyboard.write('y'); break;
      case 'Z': Keyboard.write('z'); break;

      case '!': Keyboard.write('>'); break;
      case '$': Keyboard.write('<'); break;
      case '%': Keyboard.write('/'); break;
      case '@': Keyboard.write('\\'); break;
      case '#': Keyboard.write(':'); break;
      case '&': Keyboard.write(';'); break;
      case '*': Keyboard.write('"'); break;
      case '+': Keyboard.write('('); break;
      case '-': Keyboard.write(')'); break;

      case '!': Keyboard.write(' '); break;            // Espaço
      case '$': Keyboard.write(KEY_RETURN); break;     // Enter
      case '%': Keyboard.write(KEY_BACKSPACE); break;  // Backspace
      case '@': Keyboard.write(KEY_ESC); break;        // Esc
    }
  }

  delay(10);
}