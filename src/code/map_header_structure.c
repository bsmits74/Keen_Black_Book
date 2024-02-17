typedef struct
{
	unsigned	RLEWtag;              // RLE flag
	long		headeroffsets[100];     
	byte		headersize[100];        // headers are very small
	byte		tileinfo[];
} mapfiletype;
