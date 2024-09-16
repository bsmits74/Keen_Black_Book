typedef	struct spriteliststruct
{
    int			screenx,screeny;
    int			width,height;
    [...]
} spritelisttype;

typedef struct
{
    int			screenx,screeny;
    int			width,height;
} eraseblocktype;


//
// post an erase block to both pages by copying 
// screenx,screeny,width,height
// both pages may not need to be erased if the sprite 
// just changed last frame (updatecount = 2)
//
if (sprite->updatecount<2)
{
    if (!sprite->updatecount)
        memcpy (eraselistptr[otherpage]++,sprite,
            sizeof(eraseblocktype));
    memcpy (eraselistptr[screenpage]++,sprite,
        sizeof(eraseblocktype));
}
