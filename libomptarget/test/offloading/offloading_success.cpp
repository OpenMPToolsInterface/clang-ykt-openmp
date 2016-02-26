// RUN: %libomptarget-compilexx-run-and-check-powerpc64-ibm-linux-gnu
// RUN: %libomptarget-compilexx-run-and-check-powerpc64le-ibm-linux-gnu
// RUN: %libomptarget-compilexx-run-and-check-x86_64-pc-linux-gnu

#include <stdio.h>
#include <omp.h>

int main(void) {
  int isHost = 0;

#pragma omp target
  { isHost = omp_is_initial_device(); }

  // The compiler doesn't have support to launch the target region on the
  // device.
  // CHECK: Target region executed on the host
  printf("Target region executed on the %s\n", isHost ? "host" : "device");

  return !isHost;
}
