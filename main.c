#include <stdio.h>

char matrix[3][3] = {};

// i = rows, j = columns;

int checkGameState() {
  for (int i = 0; i < 3; i++) {
    if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != '.') {
      return 1;
    }   
  }

  for (int j = 0; j < 3; j++) {
    if (matrix[0][j] == matrix[1][j] && matrix[1][j] == matrix[2][j] && matrix[0][j] != '.') {
      return 1;
    }  
  }

  if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != '.') {
    return 1; 
  }

  if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2] && matrix[2][0] != '.') {
    return 1; 
  }
  
  return 0;
}

int initMatrix() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = '.';
    }
  }
  
  return 1;
}

void printBoard() { 
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", matrix[i][j]);
    }
    printf("\n");
  }
  
  printf("\n");
}

int checkMove(int row, int column) {
  if (matrix[row][column] != '.') {
    return 1;
  }

  return 0;
}

void play(int num, char symbol) {
  switch (num) {
    case 1:
      checkMove(0, 0);
      matrix[0][0] = symbol;
      break;
    case 2:
      matrix[0][1] = symbol;
      break;
    case 3:
      matrix[0][2] = symbol;
      break;
    case 4:
      matrix[1][0] = symbol;
      break;
    case 5:
      matrix[1][1] = symbol;
      break;
    case 6:
      matrix[1][2] = symbol;
      break;
    case 7:
      matrix[2][0] = symbol;
      break;
    case 8:
      matrix[2][1] = symbol;
      break;
    case 9:
      matrix[2][2] = symbol;
      break;
  }
}

int main() {
  int number;
  
  if (initMatrix()) {
    printBoard();
  }

  printf("Type a number: ");
  scanf("%d", &number);
  play(number, 'X');
  printBoard();
  
  while (number >= 1 && number <= 9) {
    printf("O's Turn: ");
    scanf("%d", &number);
    play(number, 'O');
    printBoard();
    
    if (checkGameState()) {
      printf("You won!");
      break;
    }
    
    printf("X's Turn: ");
    scanf("%d", &number);
    play(number, 'X');
    printBoard();
    
    if (checkGameState()) {
      printf("You won!");
      break;
    }
  }
  
  return 0;
}
