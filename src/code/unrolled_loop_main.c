void main (void)
{
	textcolor(7);
	textbackground(0);

	InitGame();

	DemoLoop();					// DemoLoop calls Quit when everything is done
	Quit("Demo loop exited???");
}
