#include "Arduino.h"
#include "smartpinns.h"

int* outarr = nullptr;
int* inarr = nullptr;
int* inarr_pl = nullptr;
int s;
int sp;
int outarr_size = 0;
int inarr_size = 0;
int inarr_pl_size = 0;

void out(int* start, int* stopp) {
  s = *start;
  sp = *stopp;
  if (*start >= 3 && *stopp <= 13) {
    outarr_size = (*stopp - *start) + 1;
    outarr = new int[outarr_size];
    for (int i = 0; i < outarr_size; i++) {
      outarr[i] = *start + i;  // Pin-Nummern zuweisen
      pinMode(outarr[i], OUTPUT);
      Serial.println(outarr[i]);
    }
  } else {
    Serial.println("Ungültige Pin-Bereichsangabe");
  }
}

void in(int start, int stop) {
  if (start >= 1 && stop <= 13) {
    inarr_size = (stop - start) + 1;
    inarr = new int[inarr_size];
    for (int i = 0; i < inarr_size; i++) {
      inarr[i] = start + i;  // Pin-Nummern zuweisen
      pinMode(inarr[i], INPUT);
    }
  }
}

void in_pl(int start, int stop) {
  if (start >= 1 && stop <= 13) {
    inarr_pl_size = (stop - start) + 1;
    inarr_pl = new int[inarr_pl_size];
    for (int i = 0; i < inarr_pl_size; i++) {
      inarr_pl[i] = start + i;  // Pin-Nummern zuweisen
      pinMode(inarr_pl[i], INPUT_PULLUP);
    }
  }
}

int readPin(int index) {
  if (inarr != nullptr && index >= 0 && index < inarr_size) {
    return digitalRead(inarr[index]);
  } else {
    Serial.println("Fehler beim Zugriff auf den Pin");
    delete[] inarr;
    return -1;
  }
}

int readPin_pl(int index) {
  if (inarr_pl != nullptr && index >= 0 && index < inarr_pl_size) {
    return digitalRead(inarr_pl[index]);
  } else {
    Serial.println("Fehler beim Zugriff auf den Pin");
    delete[] inarr_pl;
    return -1;
  }
}

int getPin(int index) {
  Serial.println("sp ist gleich: " + String(sp) + String(index));
  if (outarr != nullptr && index >= 0 && index <= sp) {
    return outarr[index - (s)];
  } else if (outarr == nullptr) {
    Serial.println("Array ist NULL");
  } else if (index <= 0 || index > 13 || index == NULL) {
    Serial.println("index ist NULL");
  } else {
    Serial.println("Fehler beim Zugriff auf den Pin");
    delete[] outarr;
    return -1;
  }
}