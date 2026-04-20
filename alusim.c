#include <stdio.h>
unsigned int ALU(unsigned int A, unsigned int B, unsigned int opcode) {
  unsigned int result;
  // The switch stt acts like a multiplexer (routes the inputs to the correct
  // operation based on the control signal)
  switch (opcode) {
  case 0: // Add
    result = A + B;
    break;
  case 1: // Subtract (Done using two's complement in real hardware: flips bits
          // of B, adds 1, adds it to A)
    result = A - B;
    break;
  case 2: // AND (Compares each bit position across A and B: Output is 1 only if
          // both bits are 1)
    result = A & B;
    break;
  case 3: // OR (Compares each bit position: output is 1 if either bit is 1)
    result = A | B;
    break;
    // Implementing NOT and XOR
  case 4: // XOR (Output is 1 only if the bits are different)
    result = A ^ B;
    break;
  case 5: // NOT (operates on A only: flips every single bit)
    result = ~A;
    break;
  default:
    result = 0;
    break;
  }
  return result;
}

int main() {
  unsigned int A = 8, B = 7;

  // Results for subtraction, AND and OR
  char *ops[] = {"ADD", "SUB", "AND", "OR", "XOR", "NOT"};

  for (unsigned int opcode = 0; opcode <= 5; opcode++) {
    unsigned int result = ALU(A, B, opcode);
    printf("%s: %u\n", ops[opcode], result);
  }
  return 0;
}
