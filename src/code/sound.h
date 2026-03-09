void    SD_Startup(void);
void    SD_Shutdown(void);

void    SD_Default(boolean gotit,SDMode sd,SMMode sm);
void    SD_PlaySound(word sound);
void    SD_StopSound(void);
void    SD_WaitSoundDone(void);

boolean SD_SetSoundMode(SDMode mode);

