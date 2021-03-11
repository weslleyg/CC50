#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>
#include <crypt.h>

int max_key = 9;
bool crackeado;
char resultado[10];

void cracking(string input, string salt, char *tentativa, int index, int nLetras);

int main(int argc, char *argv[]) {
  //string pass = argv[1];

  if(argc == 1 || argc == 3) {
    printf("Argumento invalido!");
    return 1;
  }
  //SALT: first 2 char in a hashed password
  //Crypt: (key, salt)
  char salt[3] = {argv[1][0], argv[1][1], '\0'};
  // printf("%s", salt);

  for(int nLetras = 1, n = max_key + 2; nLetras < n; nLetras++) {
    char tentativa[nLetras + 1];
    tentativa[nLetras] = '\0';

    cracking(argv[1], salt, tentativa, 0, nLetras);

    if(crackeado) {
      printf("%s", resultado);
      return 0;
    }
  }

  printf("Essa senha não pode ser crackeada!\n");
  return 0;

}

void cracking(string input, string salt, char *tentativa, int index, int nLetras) {
  if(index < nLetras - 1) {
    for(char c = 'a'; c <= 'z'; c++) {
      tentativa[index] = c;

      cracking(input, salt, tentativa, index +1, nLetras);

      if(crackeado) return;
    }

    for(char c = 'A'; c <= 'Z'; c++) {
      tentativa[index] = c;

      cracking(input, salt, tentativa, index +1, nLetras);

      if(crackeado) return;
    }
  } else {
    // printf("%s", tentativa);
    string hash = crypt(tentativa, salt);
    bool resultTentativa = true;

    for(int i = 0; i < 13; i++) {
      //Compara as hashes
      if(hash[i] != input[i]) {
        resultTentativa = false;
        break;
      }
    }

    if(resultTentativa) {
      crackeado = true;
      
      for(int i = 0; i < nLetras; i++) {
        resultado[i] = tentativa[i];
      }
    }
    return;
  }
}