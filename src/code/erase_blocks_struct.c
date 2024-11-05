typedef struct
{
    int			screenx,screeny;
    int			width,height;
} eraseblocktype;

//sprite removal list for Page 0 and Page 1
eraseblocktype	eraselist[2][MAXSPRITES],*eraselistptr[2];
