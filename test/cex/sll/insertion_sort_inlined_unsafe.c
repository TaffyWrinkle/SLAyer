/* Copyright (c) Microsoft Corporation.  All rights reserved. */

#include "sll.h"

void main() {
  PSLL_ENTRY x = NULL, y, c, h, elem, prev;
  x = SLL_create(17);

  c = x;
  x = NULL;
  while (c != NULL) {
    y = c;
    c = c->Flink;
    y->Flink = NULL;
    elem = x;
    prev = NULL;
    while (elem != NULL) {
      if (elem->Data >= y->Data) {
	y->Flink = elem;
	if (prev == NULL) { x = y; goto retn; }
	prev->Flink = y;
	goto retn;
      }
      elem = elem->Flink;
      prev = elem;
    }
    y->Flink = elem;
    if (prev == NULL) { x = y; goto retn; }
    prev->Flink = y;
  retn: ;
  }

  SLL_destroy(c);
  SLL_destroy(x);
}
