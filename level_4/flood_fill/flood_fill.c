#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
    int x;
    int y;
}               t_point;

void fill(char **tab, t_point size, int x, int y, char target)
{
    // Check bounds
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return;
    // Stop if the cell is not the target character
    if (tab[y][x] != target)
        return;

    // Replace the character
    tab[y][x] = 'F';

    // Recurse in four directions
    fill(tab, size, x + 1, y, target);
    fill(tab, size, x - 1, y, target);
    fill(tab, size, x, y + 1, target);
    fill(tab, size, x, y - 1, target);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x];
    if (target != 'F') // Avoid infinite loop if starting cell is already 'F'
        fill(tab, size, begin.x, begin.y, target);
}

// Helper function to duplicate the test zone into a writable char**
char **make_area(char **zone, t_point size)
{
    char **area = malloc(sizeof(char *) * (size.y + 1));
    for (int i = 0; i < size.y; i++)
    {
        area[i] = malloc(sizeof(char) * (size.x + 1));
        for (int j = 0; j < size.x; j++)
            area[i][j] = zone[i][j];
        area[i][size.x] = '\0';
    }
    area[size.y] = NULL;
    return area;
}

// Helper function to print the 2D array
void print_tab(char **area, t_point size)
{
    for (int i = 0; i < size.y; i++)
    {
        for (int j = 0; j < size.x; j++)
            printf("%c", area[i][j]);
        printf("\n");
    }
}

int main(void)
{
    t_point size = {8, 6};
    t_point begin = {2, 2};

    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
        "11111111"
    };

    char **area = make_area(zone, size);

    printf("Before flood fill:\n");
    print_tab(area, size);

    flood_fill(area, size, begin);

    printf("\nAfter flood fill:\n");
    print_tab(area, size);

    return 0;
}
