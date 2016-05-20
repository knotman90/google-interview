#include<iostream>
#include <random>
#include<array>

using namespace std;
#define SIZE_X (8)
#define SIZE_Y (128)

typedef bool wall;

struct cell {
    wall top;
    wall right;
    wall bottom;
    wall left;

    cell(): top(true),bottom(true),right(true),left(true) {};
};



uint random(const double LOW,  double UP) {
    UP+=1;
    return (LOW+(rand()/(double)RAND_MAX)*(UP-LOW));
}

typedef array<cell,SIZE_X> row;
typedef array<row,SIZE_Y> maze;

void printMaze(const maze& maze) {

    for (int i = 0; i < SIZE_X; ++i) {
        for (int j = 0; j < SIZE_Y; ++j)     {
            printf("+");
            if(maze[i][j].top)
                printf("----");
            else
                printf("    ");

        }
        printf("\n");
        for (int j = 0; j < SIZE_Y; ++j) {
            if(maze[i][j].left)
                printf("|    ");
            else
                printf("     ");

        }
        printf("\n");

    }

    printf("\n");
    printf("\n");
    printf("\n");
}

void generate_maze(maze& maze,uint rs, uint re, uint cs,uint ce, int i) {

    int rs2 = (re-rs)/2;
    int cs2 = (ce-cs)/2;
    if(re-rs <=1) {
        maze[rs][cs].bottom = false;
        maze[rs+1][cs].top = false;

        maze[rs][ce].left = false;
        maze[rs+1][cs].right = false;

        maze[re][cs].right = false;
        maze[re][ce].left = false;

        maze[rs][ce].bottom = false;
        maze[re][ce].top = false;


        return;
    }
    generate_maze(maze,rs,      rs+rs2,cs,cs+cs2,i+1);
    generate_maze(maze,rs+rs2+1,re   , cs,cs+cs2,i+1);

    generate_maze(maze,rs,      rs+rs2,cs+cs2+1,ce,i+1);
    generate_maze(maze,rs+rs2+1,re,cs+cs2+1,ce,i+1);

printMaze(maze);
    /*for(int k=i; k>=0 ; k--)
        printf("\t");
    printf("%d,%d,%d,%d\n",rs,re,cs,ce);*/

    int split = random(rs,re);
    maze[split][ce].right = false;
    if(ce+1 < SIZE_X)
        maze[split][ce+1].left = false;

    split = random(rs,re);
    maze[split][cs].left = false;
    if(ce > 0)
        maze[split][ce-1].right = false;

    split = random(cs,ce);
    maze[re][split].bottom = false;
    if(re+1 < SIZE_Y)
        maze[re+1][split].top = false;

    split = random(cs,ce);
    maze[rs][split].top = false;
    if(rs > 0)
        maze[rs-1][split].bottom = false;

    split = random(cs,ce);
    maze[rs+rs2][split].bottom = false;
    maze[rs+rs2+1][split].top = false;

    split = random(rs,re);
    maze[split][cs+cs2].right = false;
    maze[split][cs+cs2+1].left = false;
printf("%d,%d\n",split,cs2);
printMaze(maze);


}



int main() {
    srand(time(0));

    maze maze;
    generate_maze(maze,0,SIZE_X-1,0,SIZE_Y-1,0);
    printMaze(maze);
    return 0;
}
