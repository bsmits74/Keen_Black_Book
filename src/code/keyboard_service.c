#define	KeyInt		9	// The keyboard ISR number

static void INL_StartKbd(void) {

	IN_ClearKeysDown();

	OldKeyVect = getvect(KeyInt);
	setvect(KeyInt,INL_KeyService);
}

static void interrupt INL_KeyService(void) {
	[...]
}
