#include <stdlib.h>
#include <stdio.h>
#include "menger.h"
#include <math.h>

/**
 * menger - Function that draws a 2D Menger Sponge
 *
 * @level:  is the level of the Menger Sponge to draw
 *
 * Return: void
 */
void menger(int level)
{
int count = pow(3, level), i, j, x, y;

char s = ' ';
	if (level < 0)
		return;
	if (level == 0)
		printf("#\n");

	else
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				s = '#';
				x = i;
				y = j;
				while (x > 0 || y > 0)
				{
					if ((x % 3 == 1) && y % 3 == 1)
						s = ' ';
					x = x / 3;
					y = y / 3;
				}

			printf("%c", s);
			}

			printf("\n");

		}

}

