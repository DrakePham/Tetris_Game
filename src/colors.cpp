#include "colors.h"



const Color darkGrey = {169, 169, 169, 255};
const Color green = {0, 255, 0, 255};
const Color red = {255, 0, 0, 255};
const Color orange = {255, 165, 0, 255};
const Color yellow = {255, 255, 0, 255};
const Color purple = {128, 0, 128, 255};
const Color blue = {0, 0, 255, 255};
const Color cyan = {0, 255, 255, 255};

vector<Color> getCellColors()
{
    return {darkGrey, green, red, orange, yellow, purple, blue, cyan};
}