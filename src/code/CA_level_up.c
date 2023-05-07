void CA_UpLevel (void)
{
	int i;

	if (ca_levelnum==7)
		Quit ("CA_UpLevel: Up past level 7!");

	ca_levelbit<<=1;
	ca_levelnum++;
}
