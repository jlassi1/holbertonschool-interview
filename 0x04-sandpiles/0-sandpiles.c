#include "sandpiles.h"
/**
 *verification-verification of stabilisation
*
*@a: grid to check it
*
*Return: true or false
*/
bool verification(int a[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (a[i][j] > 3)
{
return (false);
}
}
}
return (true);
}
/**
 *print-print the grid
*@a: the grid to print
*
*
*Return: void
*/
void print(int a[3][3])
{
printf("=\n");
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
printf("%d", a[i][j]);
if (j < 2)
{
printf(" ");
}
}
printf("\n");
}
}
/**
 *stable- stable the sum of two grid
*
*@a: grid1 to change
*@tmp: grid2 to compaire with it
*
*Return:void
*/
void stable(int a[3][3], int tmp[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
tmp[i][j] = a[i][j];
}
}
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{

if (tmp[i][j] >= 4)
{
a[i][j] = a[i][j] - 4;
if (i >= 1)
{
a[i - 1][j] += 1;
}
if (i <= 1)
{
a[i + 1][j] += 1;
}
if (j >= 1)
{
a[i][j - 1] += 1;
}
if (j <= 1)
{
a[i][j + 1] += 1;
}
}
}
}
}
/**
*sandpiles_sum-computes the sum of two sandpiles
*
*@grid1: the grid1
*@grid2: the grid2
*
*Return: void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int tmp[3][3];

for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}
while (!verification(grid1))
{
print(grid1);
stable(grid1, tmp);
}
}
