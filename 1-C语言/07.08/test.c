#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
    struct Point *pos;
};

// int main()
// {
//     struct Point *p[3] = (struct Point*)malloc(3 * sizeof(struct Point));
//     if (p == NULL)
//     {
//         return 0;
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         p[i]->x = i;
//         p[i]->y = i;
//     }
//     p[0]->pos = p[1];
//     p[1]->pos = p[2];
//     p[2]->pos = NULL;
//     printf("%d,%d\n", p[0]->pos->x, p[0]->pos->y);
//     printf("%d,%d\n", p[0]->pos->pos->x, p[0]->pos->pos->y);
//     free(p);
    
//     return 0;
// }

int main()
{
    struct Point *p = (struct Point*)malloc(3 * sizeof(struct Point));
    if (p == NULL)
    {
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        (p+i)->x = i;
        (p+i)->y = i;
    }
    p->pos = (p+1);
    (p+1)->pos = (p+2);
    (p+2)->pos = NULL;
    printf("%d,%d\n", p->pos->x, p->pos->y);
    printf("%d,%d\n", p->pos->pos->x, p->pos->pos->y);
    free(p);
    p=NULL;
    return 0;
}

// int main()
// {
//     struct Point p[3];
//     for (int i = 0; i < 3; i++)
//     {
//         p[i].x = i;
//         p[i].y = i;
//     }
//     p[0].pos = &p[1];
//     p[1].pos = &p[2];
//     p[2].pos = NULL;
//     printf("%d,%d\n", p[0].pos->x, p[0].pos->y);
//     printf("%d,%d\n", p[0].pos->pos->x, p[0].pos->pos->y);
//     return 0;
// }
// int main()
// {
//     struct Point p1, p2, p3;
//     p1.x = 1;
//     p1.y = 1;
//     p1.pos = &p2;
//     p2.x = 2;
//     p2.y = 2;
//     p2.pos = &p3;
//     p3.x = 3;
//     p3.y = 3;
//     p3.pos = NULL;
//     printf("%d,%d\n", p1.pos->x, p1.pos->y);
//     printf("%d,%d\n", p1.pos->pos->x, p1.pos->pos->y);
//     return 0;
// }

// struct Student
// {
//     char *id;
//     char *name;
//     char *sex;
//     double socre;
// };
// int main(int argc, char const *argv[])
// {
//     struct Student *s = (struct Student *)malloc(sizeof(struct Student));
//     if (s == NULL)
//     {
//         return 0;
//     }
//     s->id = "202006020130";
//     s->name = "zhangshan";
//     s->sex = "man";
//     s->socre = 80;
//     printf("%s %s %s %g\n", s->id, s->name, s->sex, s->socre);
//     free(s);
//     s = NULL;
//     return 0;
// }
