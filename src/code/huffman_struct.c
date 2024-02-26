typedef struct
{
  unsigned bit0,bit1;	// 0-255 is a character, 
                      // >255 is a pointer to a node
} huffnode;
