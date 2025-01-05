#define	TickBase	70

typedef	enum {
  sdm_Off,
  sdm_PC,
  sdm_AdLib,
  sdm_SoundBlaster
  sdm_SoundSource
} SDMode;

static	word  t0CountTable[] = {2,2,2,2,10,10};
