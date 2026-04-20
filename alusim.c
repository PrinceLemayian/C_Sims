#include <stdio.h>
unsigned int ALU(unsigned int A, unsigned int B, unsigned int opcode) {
  unsigned int result;
  switch (opcode) {
  case 0: // Add
    result = A + B;
    break;
  case 1: // Subtract
    result = A - B;
    break;
  case 2: // AND
    result = A & B;
    break;
  case 3: // OR
    result = A | B;
    break;
  case 4: // XOR
    result = A ^ B;
    break;
    // Implementing NOT and XOR
  case 5: // NOT (operates on A only)
    result = -A;
    break;
  default:
    result = 0;
    break;
  }
  return result;
}

int main() {
  unsigned int A = 8, B = 7;
  unsigned int opcode = 0; // 0 for addition
  unsigned int result = ALU(A, B, opcode);
  printf("Result of operation: %u\n", result);

  // Results for subtraction, AND and OR
  char *ops[] = {"ADD", "SUB", "AND", "OR", "XOR", "NOT"};

  for (unsigned int opcode = 0; opcode <= 5; opcode++) {
    unsigned int result = ALU(A, B, opcode);
    printf("%s: %u\n", ops[opcode], result);
  }
  return 0;
}
