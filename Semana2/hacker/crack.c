#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>
#include <crypt.h>

int max_key = 4;
bool crackeado;
char resultado[6];

void cracking(string input, string salt, char *tentativa, int index, int letra);

int main(int argc, char *argv[]) {
  //string pass = argv[1];

  if(argc == 1 || argc == 3) {
    return 1;
  }
  //SALT: first 2 char in a hashed password
  //Crypt: (key, salt)
  char salt[3] = {argv[1][0], argv[1][1], '\0'};
  printf("%s", salt);

  for(int letra = 1, n = max_key + 2; letra < n; letra++) {
    char tentativa[letra + 1];
    tentativa[letra] = '\0';

    cracking(argv[1], salt, tentativa, 0, letra);

    if(crackeado) {
      printf("%s", resultado);
      return 0;
    }
  }

  printf("Essa senha não pode ser crackeada!\n");
  return 0;

}

void cracking(string input, string salt, char *tentativa, int index, int letra) {
  if(index < letra - 1) {
    for(char c = 'a'; c <= 'z'; c++) {
      tentativa[index] = c;

      cracking(input, salt, tentativa, index +1, letra);

      if(crackeado) return;
    }

    for(char c = 'A'; c <= 'Z'; c++) {
      tentativa[index] = c;

      cracking(input, salt, tentativa, index +1, letra);

      if(crackeado) return;
    }
  } else {
    string hash = crypt(tentativa, salt);
    bool resultTentativa = true;

    for(int i = 0; i < 13; i++) {
      if(hash[i] != input[i]) {
        resultTentativa = false;
        break;
      }
    }

    if(resultTentativa) {
      crackeado = true;
      
      for(int i = 0; i < letra; i++) {
        resultado[i] = tentativa[i];
      }
    }
    return;
  }
}