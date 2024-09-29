#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polyclinic.h"

int main()
{
    patient p1{"Artur", "Grishin", "Artemovich", 2002, 0, "Barnaul sity...", "88005553535", "1111"};
    add_patient(p1);
}