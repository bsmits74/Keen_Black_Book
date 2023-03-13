/*
=================================================

						 LOCAL CONSTANTS

=================================================
*/


typedef struct
{
	unsigned	RLEWtag;
	long		headeroffsets[100];
	byte		headersize[100];		// headers are very small
	byte		tileinfo[];
} mapfiletype;
